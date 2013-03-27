#include "os_internal.h"
#include "os.h"
#include "toolbox.h"

#include <stdexcept>
#include <cerrno>

#include <unistd.h>
#include <fcntl.h>
#include <sys/xattr.h>



namespace OS { namespace Internal {


	uint16_t errno_to_oserr(int xerrno)
	{
		using namespace ToolBox::Errors;
		
		switch (xerrno)
		{
			case 0: return 0;
			case EBADF: return rfNumErr;
			case EIO: return ioErr;
			case EACCES: return permErr;
			case ENOENT: return fnfErr;
			case ENOTDIR: return dirNFErr;
			case EISDIR: return notAFileErr;
			case ENOTSUP: return extFSErr;
			case EROFS: return wPrErr;

			case EEXIST: return dupFNErr;

			case EBUSY: return fBsyErr;

			case EDQUOT: return dskFulErr;
			case ENOSPC: return dskFulErr;


			default:
				return ioErr;
		}

	}


	/*
     
     tech note PT515
     ProDOS -> Macintosh conversion
     
     ProDOS             Macintosh
     Filetype    Auxtype    Creator    Filetype
     $00          $0000     'pdos'     'BINA'
     $B0 (SRC)    (any)     'pdos'     'TEXT'
     $04 (TXT)    $0000     'pdos'     'TEXT'
     $FF (SYS)    (any)     'pdos'     'PSYS'
     $B3 (S16)    (any)     'pdos'     'PS16'
     $uv          $wxyz     'pdos'     'p' $uv $wx $yz
     
     Programmer's Reference for System 6.0:
     
     ProDOS Macintosh 
     File Type Auxiliary Type Creator Type File Type 
     $00        $0000           “pdos”  “BINA” 
     $04 (TXT)  $0000           “pdos”  “TEXT” 
     $FF (SYS)  (any)           “pdos”  “PSYS” 
     $B3 (S16)  $DByz           “pdos”  “p” $B3 $DB $yz 
     $B3 (S16)  (any)           “pdos”  “PS16” 
     $D7        $0000           “pdos”  “MIDI” 
     $D8        $0000           “pdos”  “AIFF” 
     $D8        $0001           “pdos”  “AIFC” 
     $E0        $0005           “dCpy”  “dImg” 
     $FF (SYS)  (any)           “pdos”  “PSYS” 
     $uv        $wxyz           “pdos”  “p” $uv $wx $yz 
     
	
	  mpw standard:
     $uv        (any)          "pdos"  printf("%02x  ",$uv)

     */

	uint16_t GetFinderInfo(const std::string &pathName, void *info, bool extended)
	{
		// todo -- move to separate function? used in multiple places.
		uint8_t buffer[32];
		std::memset(buffer, 0, sizeof(buffer));
		int rv;

		rv = ::getxattr(pathName.c_str(), XATTR_FINDERINFO_NAME, buffer, 32, 0, 0);

		if (rv < 0)
		{
			switch (errno)
			{
				case ENOENT:
				case EACCES:
					return errno_to_oserr(errno);
			}
		}

		// override for source files.
		// TODO -- only override if missing?
		if (IsTextFile(pathName))
		{
			std::memcpy(buffer, "TEXTMPS ", 8);
		}	


		// convert pdos types...
		if (::memcmp(buffer + 4, "pdos", 4) == 0)
		{
			// mpw expects 'xx  ' where
			// xx are the ascii-encode hex value of the file type.
			// the hfs fst uses 'p' ftype8 auxtype16
			if (buffer[0] == 'p')
			{
				static char Hex[] = "0123456789ABCDEF";

				uint8_t ftype = buffer[1];
				buffer[0] = Hex[ftype >> 4];
				buffer[1] = Hex[ftype & 0x0f];
				buffer[2] = ' ';
				buffer[3] = ' ';
			}
		}

		if (extended)
			std::memcpy(info, buffer, 32);
		else
			std::memcpy(info, buffer, 16);
		return 0;
	}

	unsigned tox(unsigned x)
	{
		if (x >= '0' && x <= '9') return x - '0';
		if (x >= 'a' && x <= 'f') return x - 'a' + 10;
		if (x >= 'A' && x <= 'F') return x - 'A' + 10;
		return 0;
	}

	uint16_t SetFinderInfo(const std::string &pathName, void *info, bool extended)
	{
		uint8_t buffer[32];
		std::memset(buffer, 0, sizeof(buffer));
		int rv;

		if (!extended)
		{
			rv = ::getxattr(pathName.c_str(), XATTR_FINDERINFO_NAME, buffer, 32, 0, 0);

			if (rv < 0)
			{
				switch (errno)
				{
					case ENOENT:
					case EACCES:
						return errno_to_oserr(errno);
				}
			}
		}

		if (extended)
			std::memmove(buffer, info, 16);
		else
			std::memmove(buffer, info, 32);

		// convert pdos types.
		if (::memcmp(buffer + 2, "  pdos", 6) == 0)
		{
			unsigned a = buffer[0];
			unsigned b = buffer[1];

			if (isxdigit(a) && isxdigit(b))
			{
				buffer[0] = 'p';
				buffer[1] = (tox(a) << 4) | tox(b);
				buffer[2] = 0;
				buffer[3] = 0;
			}
		}

		rv = ::setxattr(pathName.c_str(), XATTR_FINDERINFO_NAME, buffer, 32, 0, 0);
		if (rv < 0) return errno_to_oserr(errno);

		return 0;
	}


	int32_t mac_seek(uint16_t refNum, uint16_t mode, int32_t offset)
	{
		off_t rv;
		switch (mode & 0x03)
		{
		case OS::fsAtMark:
			mode = SEEK_CUR;
			offset = 0;
			break;
		case OS::fsFromStart:
			mode = SEEK_SET;
			break;
		case OS::fsFromLEOF:
			mode = SEEK_END;
			break;
		case OS::fsFromMark:
			mode = SEEK_CUR;
			break;
		}

		rv = ::lseek(refNum, offset, mode);
		if (rv < 0) return errno_to_oserr(errno);
		return rv;
	}

	//std::deque<FDEntry> FDTable;

	std::deque<FDEntry> FDEntry::FDTable;
	FDEntry& FDEntry::allocate(int fd)
	{
		std::string noname;

		return allocate(fd, noname);
	}

	FDEntry& FDEntry::allocate(int fd, std::string &&filename)
	{
		if (fd < 0) throw std::out_of_range("Invalid FD");

		if (FDTable.size() <= fd)
			FDTable.resize(fd + 1);

		auto &e = FDTable[fd];
		e.refcount = 1;
		e.text = false;
		e.resource = false;
		e.filename = std::move(filename);
		return e;
	}

	FDEntry& FDEntry::allocate(int fd, const std::string &filename)
	{
		if (fd < 0) throw std::out_of_range("Invalid FD");

		if (FDTable.size() <= fd)
			FDTable.resize(fd + 1);

		auto &e = FDTable[fd];
		e.refcount = 1;
		e.text = false;
		e.resource = false;
		e.filename = filename;
		return e;
	}


	int FDEntry::close(int fd, bool force)
	{
		if (fd < 0 || fd >= FDTable.size())
		{
			errno = EBADF;
			return -1;
		}
		auto &e = FDTable[fd];
		if (!e.refcount)
		{
			errno = EBADF;
			return -1;
		}

		if (--e.refcount == 0 || force)
		{
			e.refcount = 0;
			return ::close(fd);
		}
		return 0;
	}


	ssize_t FDEntry::read(int fd, void *buffer, size_t count)
	{
		if (fd < 0 || fd >= FDTable.size())
		{
			errno = EBADF;
			return -1;
		}

		auto const &e = FDTable[fd];
		if (!e.refcount)
		{
			errno = EBADF;
			return -1;
		}

		// hmm... keep a current seek position?

		ssize_t size;
		if (e.text)
		{
			std::unique_ptr<uint8_t[]> trbuffer(new uint8_t[count]);

			size = ::read(fd, trbuffer.get(), count);

			if (size > 0)
			{
				std::transform(trbuffer.get(), trbuffer.get() + size, (uint8_t *)buffer, 
					[](uint8_t c) { return c == '\n' ? '\r' : c; }
				);
			}
		}
		else
		{
			size = ::read(fd, buffer, count);
		}
		return size;
	}

	ssize_t FDEntry::write(int fd, const void *buffer, size_t count)
	{
		if (fd < 0 || fd >= FDTable.size())
		{
			errno = EBADF;
			return -1;
		}

		auto const &e = FDTable[fd];
		if (!e.refcount)
		{
			errno = EBADF;
			return -1;
		}

		// hmm... keep a current seek position?

		ssize_t size;
		if (e.text)
		{
			std::unique_ptr<uint8_t[]> trbuffer(new uint8_t[count]);

			if (count > 0)
			{
				std::transform((const uint8_t *)buffer, (const uint8_t *)buffer + count, trbuffer.get(), 
					[](uint8_t c) { return c == '\r' ? '\n' : c; }
				);
			}

			size = ::write(fd, trbuffer.get(), count);
		}
		else
		{
			size = ::write(fd, buffer, count);
		}
		return size;
	}


} }