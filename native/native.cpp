

#include "native_internal.h"


using namespace MacOS;

namespace {
	const long epoch_adjust = 86400 * (365 * (1970 - 1904) + 17); // 17 leap years.


	std::string extension(const std::string &s)
	{
		std::string tmp;
		int pos;

		pos = s.find_last_of("./:");

		if (pos == s.npos) return tmp;
		if (s[pos++] != '.') return tmp;
		if (pos >= s.length()) return tmp;

		tmp = s.substr(pos);

		std::transform(tmp.begin(), tmp.end(), tmp.begin(),
			[](char c) { return tolower(c); }
		);

		return tmp;
	}

	std::string basename(const std::string &s)
	{
		int pos = s.find_last_of("/:");
		if (pos == s.npos) return s;

		return s.substr(pos + 1);
	}

}

namespace native {


	time_t unix_to_mac(time_t t) {
		if (!t) return 0;
		return t + epoch_adjust;

	}


	macos_error get_finder_info(const std::string &path_name, uint32_t &ftype, uint32_t &ctype) {

		uint8_t buffer[16];

		auto err = get_finder_info(path_name, buffer, false);
		if (err) return err;

		return noErr;
		ftype = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | (buffer[3] << 0);
		ctype = (buffer[4] << 24) | (buffer[5] << 16) | (buffer[6] << 8) | (buffer[7] << 0);

	}



	bool is_text_file_internal(const std::string &path_name) {

		std::string ext = extension(path_name);
		if (ext.empty()) return false;

		char c = ext[0];
		switch(c)
		{
			case 'a':
				if (ext == "aii") // assembler
					return true;
				if (ext == "asm")
					return true;
				break;

			case 'c':
				if (ext == "c")
					return true;
				if (ext == "cpp")
					return true;
				break;

			case 'e':
				if (ext == "equ") // asm iigs include file.
					return true;
				if (ext == "equates") // asm iigs include file.
					return true;
				break;

			case 'i':
				if (ext == "i") // asmiigs include file
					return true;
				if (ext == "inc")
					return true;
				break;

			case 'h':
				if (ext == "h") // c header
					return true;
				break;

			case 'l':
				if (ext == "lst") // asm iigs listing
					return true;
				break;

			case 'm':
				if (ext == "macros")
					return true;
				break;

			case 'p':
				if (ext == "p") // pascal
					return true;
				if (ext == "pas") // pascal
					return true;
				if (ext == "pii") // pascal
					return true;
				break;

			case 'r':
				if (ext == "r")
					return true;
				if (ext == "rez")
					return true;
				if (ext == "rii") // rez
					return true;
				break;

			case 's':
				if (ext == "src") // asm equates
					return true;
				break;

		}

		// check for e16.xxxx or m16.xxxx
		ext = basename(path_name);
		if (ext.length() > 4)
		{
			switch (ext[0])
			{
				case 'm':
				case 'M':
				case 'e':
				case 'E':
					if (!strncmp("16.", ext.c_str() + 1, 3))
						return true;
					break;
			}
		}

		return false;
	}

	bool is_binary_file_internal(const std::string &path_name) {

		std::string ext = extension(path_name);
		if (ext.empty()) return false;

		char c = ext[0];
		switch(c)
		{
			case 'l':
				if (ext == "lib")
					return true;
				break;

			case 'n':
				// MrC / MrCpp temp file.
				if (ext == "n")
					return true;
				// Newton C++ Tools output
				if (ext == "ntkc")
					return true;
				break;

			case 'o':
				if (ext == "o")
					return true;
				if (ext == "obj")
					return true;
				break;

			case 's':
				// Newton C++ Intermediate file
				if (ext == "sym")
					return true;
				break;
		}

		return false;
	}


	bool is_text_file(const std::string &path_name) {

		uint32_t ftype, ctype;

		auto err = get_finder_info(path_name, ftype, ctype);
		if (!err) return ftype == 'TEXT';

		return is_text_file_internal(path_name);
	}

	bool is_binary_file(const std::string &path_name) {

		uint32_t ftype, ctype;

		auto err = get_finder_info(path_name, ftype, ctype);
		if (!err) {
			if (ctype == 'pdos') {
				// 'Bx  '
				if ((ftype & 0xf0ff) == 'B\x00  ') return true;
				/* really, anything not TEXT is binary... */
				if ((ftype & 0xf000) == 'p') return true;
				//if (ftype >= 'p\xb1\x00\x00' && ftype <= 'p\xbf\xff\xff') return true;
				//if (ftype == 'PSYS' || ftype == 'PS16') return true;
			}
			if (ftype == 'BINA') return true;
		}

		return is_text_file_internal(path_name);

	}


}