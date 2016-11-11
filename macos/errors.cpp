
#include <cstddef> // null
#include <cstdint>
#include <cerrno>
#include <string>

#include "errors.h"

const char *ErrorName(int16_t error)
{
	switch(error)
	{
	case -32768: return "Temporarily disable card but run primary init.";
	case -32767: return "Bad component instance";
	case -32766: return "Bad component selector";
	case -32640: return "Reserve range -32640 to -32768 for Apple temp disables.";
	case -32615: return "Bitmap font passed to routine that does outlines only";
	case -32100: return "Can't mount system startup volume";
	case -32086: return "Circular reference in hierarchical menu";
	case -32085: return "Unable to load menu bar defproc";
	case -32041: return "The file named \"Finder\" can't be found on the disk";
	case -32030: return "\"Please insert the disk\"";
	case -32029: return "File server error";
	case -32028: return "Stack overflow: the stack has expanded into the heap";
	case -32027: return "File map destroyed";
	case -32026: return "Segment Loader error: a GetResource call to read a 'CODE' resource failed";
	case -32025: return "Can't allocate requested memory block in heap";
	case -32024: return "Can't load package";
	case -32023: return "Can't load package";
	case -32022: return "Can't load package";
	case -32021: return "Can't load package";
	case -32020: return "Can't load package";
	case -32019: return "Can't load package";
	case -32018: return "Can't load package";
	case -32017: return "Can't load package";
	case -32016: return "Floating point error";
	case -32015: return "Segment Loader error: a GetResource call failed";
	case -32014: return "I/O system error";
	case -32013: return "Spurious interrupt";
	case -32012: return "Unimplemented core routine: Unimplemented trap number encountered";
	case -32011: return "Miscellaneous exception";
	case -32010: return "Line 1111 exception: Unimplemented instruction";
	case -32009: return "Line 1010 exception: the 1010 trap dispatcher has failed";
	case -32008: return "Trace exception";
	case -32007: return "Privilege violation";
	case -32006: return "Trap V exception";
	case -32005: return "Check exception: value out of range";
	case -32004: return "Zero divide";
	case -32003: return "Illegal instruction";
	case -32002: return "Address error: word or long-word reference to an odd address";
	case -32001: return "Bus error: invalid memory reference";
	case -31009: return "Inconsistent dump format";
	case -31008: return "Invalid file type";
	case -31007: return "Illegal use of I/O control block";
	case -31006: return "Attempt to use I/O control block which is currently in use";
	case -31005: return "Too many includes";
	case -31004: return "I/O system error (illegal use of buffer)";
	case -31003: return "Not enough heap space to allocate I/O control block";
	case -31002: return "Not enough heap space to allocate I/O buffer";
	case -31001: return "Not a text file";
	case -20002: return "The recordIndex parameter is not valid";
	case -20001: return "The record data is bigger than buffer size (1024 bytes)";
	case -20000: return "There is no such insert mode";
	case -13005: return "Power Manager did not finish handshake during receive";
	case -13004: return "Power Manager did not start handshake during receive";
	case -13003: return "Power Manager did not finish handshake during send";
	case -13002: return "Power Manager did not start handshake during send";
	case -13001: return "Timed out waiting for reply";
	case -13000: return "Power Manager never ready to start handshake";
	case -11005: return "The picture data was invalid ";
	case -11004: return "The number of colors requested was illegal ";
	case -11003: return "Custom pick method not in resource chain";
	case -11002: return "Invalid verb combination specified";
	case -11001: return "Invalid PictInfo ID";
	case -11000: return "Version number not zero";
	case -10016: return "Apple Event Local Only";
	case -10015: return "Apple Event Can't Undo";
	case -10014: return "Apple Event Not A Single Object";
	case -10013: return "Apple Event No User Selection";
	case -10012: return "Apple Event No Such Transaction";
	case -10011: return "Apple Event In Transaction";
	case -10010: return "Apple Event Can't Handle Class";
	case -10009: return "Apple Event Can't Supply Type";
	case -10008: return "Apple Event Not An Element";
	case -10007: return "Apple Event Index Too Large";
	case -10006: return "Apple Event Write Denied";
	case -10005: return "Apple Event Read Denied";
	case -10004: return "Apple Event Privilege Error";
	case -10003: return "Apple Event Not Modifiable";
	case -10002: return "Apple Event Bad Key Form";
	case -10001: return "Apple Event Type Error";
	case -10000: return "Apple Event Failed";
	case -9999: return "Can't move attached controller";
	case -9998: return "Controller has fixed height";
	case -9997: return "Can't set width of attached controller";
	case -9996: return "Controller bounds not exact";
	case -9995: return "Editing not allowed ";
	case -9994: return "Bad controller height";
	case -9408: return "Device can't meet request";
	case -9407: return "Sequence grab info not available";
	case -9406: return "Bad SG channel";
	case -9405: return "Couldn't get required component";
	case -9404: return "Not enough disk space to grab";
	case -9403: return "Not enough memory to grab";
	case -9402: return "Can't do that in current mode";
	case -9401: return "Grab time complete";
	case -9400: return "No device for channel";
	case -8976: return "Codec Nothing to Blit error";
	case -8975: return "Codec Can't Queue error";
	case -8974: return "Codec Can't When error";
	case -8973: return "Codec open error";
	case -8972: return "Codec Condition error";
	case -8971: return "Codec extension not found error";
	case -8970: return "Codec data version error";
	case -8969: return "Codec bad data error";
	case -8968: return "Codec off screen error";
	case -8967: return "Codec abort error";
	case -8966: return "Codec spool error";
	case -8965: return "Codec image buffer error";
	case -8964: return "Codec screen buffer error";
	case -8963: return "Codec size error";
	case -8962: return "Codec unimplemented error";
	case -8961: return "No codec error";
	case -8960: return "Codec error";
	case -8159: return "Printer not initialized";
	case -8151: return "Incompatible printer initialization";
	case -8150: return "No printer chosen";
	case -8133: return "Postscript error";
	case -6230: return "Attempt to add an already installed display";
	case -6229: return "Could not find item";
	case -6228: return "Video Driver does not support display manager";
	case -6227: return "Required software not initialized (eg window manager or display mgr)";
	case -6226: return "Missing critical pieces of System Software";
	case -6225: return "Mirroring is off; should be turned on";
	case -6224: return "Can't Block because mirroring is on (first call DMUnMirror() )";
	case -6223: return "DMBlockMirroring() has been called";
	case -6222: return "More than two displays attempted";
	case -6221: return "Mirroring is on; should be turned off";
	case -6220: return "Display Manager unexpected error";
	case -5553: return "Gestalt function pointer wasn't in sysheap";
	case -5552: return "Tried to add an entry that already existed";
	case -5551: return "Undefined selector was passed to Gestalt";
	case -5550: return "Value returned if Gestalt doesn't know the answer";
	case -5502: return "The version requested is greater than the current SysEnvirons trap can provide";
	case -5501: return "Non-positive selector was passed to SysEnvirons trap";
	case -5500: return "SysEnvirons call not present as a trap";
	case -5044: return "the folder being shared is inside or being moved to the trash folder";
	case -5043: return "the folder being shared is inside or being moved to a shared folder";
	case -5042: return "the password being used is too old: this requires the user to change the password before log-in can continue";
	case -5041: return "the password being set is too short: there is a minimum length that must be met or exceeded";
	case -5040: return "someone tried to change their password to the same password on a mandatory password change";
	case -5039: return "afpBadIDErr";
	case -5038: return "afpSameObjectErr";
	case -5037: return "afpCatalogChanged";
	case -5036: return "afpDiffVolErr";
	case -5035: return "afpIDExists";
	case -5034: return "afpIDNotFound";
	case -5033: return "the folder being shared contains a shared folder";
	case -5032: return "Object is MODIFY/READ/DELETE/WRITE inhibited";
	case -5031: return "Volume is Read-Only";
	case -5030: return "Icon size specified different from existing icon size";
	case -5029: return "Unknown directory specified";
	case -5028: return "AFPRename cannot rename volume";
	case -5027: return "Server is shutting down";
	case -5026: return "Maximum open file count reached";
	case -5025: return "File/Directory specified where Directory/File expected";
	case -5024: return "Unsupported AFP call was made";
	case -5023: return "No AFPLogin call has successfully been made for this session";
	case -5022: return "Session closed";
	case -5021: return "Some or all of range already locked by same user";
	case -5020: return "Tried to unlock range that was not locked by user";
	case -5019: return "A specified parameter was out of allowable range";
	case -5018: return "Specified file or directory does not exist";
	case -5017: return "Specified destination file or directory already exists";
	case -5016: return "Server not responding";
	case -5015: return "Maximum lock limit reached";
	case -5014: return "Unexpected error encountered during execution";
	case -5013: return "Some or all of requested range is locked by another user";
	case -5012: return "Unknown UserName/UserID or missing comment/APPL entry";
	case -5011: return "Cannot create directory on specified volume";
	case -5010: return "Cannot delete an open file";
	case -5009: return "Read beyond logical end-of-file";
	case -5008: return "Insufficient free space on volume for operation";
	case -5007: return "Cannot delete non-empty directory";
	case -5006: return "Specified open/deny modes conflict with current open modes";
	case -5005: return "Move destination is offspring of source, or root was specified";
	case -5004: return "Bitmap contained bits undefined for call";
	case -5003: return "Unknown AFP version number specified";
	case -5002: return "Unknown user authentication method specified";
	case -5001: return "Further information required to complete AFPLogin call";
	case -5000: return "Insufficient access privileges for operation";
	case -4101: return "Printer not found or closed";
	case -4100: return "Connection to printer closed";
	case -4099: return "Printing failure: write request too big";
	case -4098: return "Printing failure: request already active";
	case -4097: return "Printing failure: bad connection reference number";
	case -4096: return "Printing failure: no free connect control blocks available";
	case -3109: return "Asynchronous call aborted because socket was closed before call was completed";
	case -3108: return "ABRecord not found";
	case -3107: return "Bad response from ATPRequest";
	case -3106: return "ATP response message too large";
	case -3105: return "Socket or protocol type invalid or not found in table";
	case -3104: return "NBP can't find tuple in buffer";
	case -3103: return "DDP bad checksum";
	case -3102: return "MPP driver not installed";
	case -3101: return "ALAP frame too large for buffer / DDP datagram too large for buffer";
	case -3032: return "noPrefAppErr";
	case -3031: return "Bad translation spec";
	case -3030: return "No translation path";
	case -3026: return "Could not parse source file";
	case -3025: return "Invalid translation path";
	case -3003: return "Component doesn't register";
	case -3002: return "Component not captured";
	case -3001: return "Valid instances exist";
	case -3000: return "Invalid component ID";
	case -2824: return "Invalid fragment usage";
	case -2823: return "Fragment targeted for an unacceptable architecture";
	case -2822: return "No application found in cfrg (for Process Manager)";
	case -2821: return "Fragment user initialization routine did not return noErr";
	case -2820: return "Fragment container corrupted (known format) ";
	case -2819: return "Fragment internal inconsistency ";
	case -2818: return "Error in initialization of CFM";
	case -2817: return "Error connecting to library (error occurred in sub prepare) ";
	case -2816: return "Boot library has initialization routine";
	case -2815: return "Fragment circularity detected in mandatory initialization order";
	case -2814: return "Import library was too new and therefore incompatible";
	case -2813: return "Import library was too old and therefore incompatible";
	case -2812: return "Fragment order error during user initialization function invocation";
	case -2811: return "Fragment no more context id's";
	case -2810: return "Fragment out of memory in user's address space for loadable section";
	case -2809: return "Fragment out of memory for internal bookkeeping";
	case -2807: return "Loaded fragment had \"hard\" unresolved imports";
	case -2806: return "Fragment container format unknown";
	case -2805: return "Fragment registered name already in use";
	case -2804: return "Fragment library name not found in registry";
	case -2803: return "Fragment section not found";
	case -2802: return "Fragment symbol not found in connection";
	case -2801: return "Fragment connectionID not valid";
	case -2800: return "Fragment contextID not valid";
	case -2780: return "AppleScript inconsistent names";
	case -2763: return "AppleScript no result returned";
	case -2762: return "AppleScript parameter not for event";
	case -2761: return "AppleScript illegal formal parameter";
	case -2760: return "AppleScript terminology nesting too deep";
	case -2721: return "AppleScript can't compare more than 32k";
	case -2720: return "AppleScript can't consider and ignore";
	case -2526: return "Mixed mode internal error";
	case -2519: return "TSM unknown error";
	case -2518: return "TSM Unsupported interface type";
	case -2517: return "TSM script has no input method or is using old IM";
	case -2516: return "TSM returned by GetDefaultInputMethod";
	case -2515: return "TSM text service already opened for the document";
	case -2514: return "TSM text service is not open";
	case -2513: return "TSM the text service has no menu";
	case -2512: return "Not TSM aware because we are using input window";
	case -2511: return "TSM there are open documents";
	case -2510: return "TSM no text service found";
	case -2509: return "TSM can't open the component";
	case -2508: return "TSM no open text service";
	case -2507: return "TSM document is not active";
	case -2506: return "TSM document is still active";
	case -2505: return "Invalid TSM documentation ID ";
	case -2504: return "TSM application not registered";
	case -2503: return "TSM application already registered";
	case -2502: return "TSM not an application";
	case -2501: return "TSM input method not found";
	case -2500: return "Unsupported script language error";
	case -2062: return "Movie text not found";
	case -2059: return "Samples already in media";
	case -2058: return "Auxiliary export data unavailable";
	case -2057: return "Unsupported auxiliary import data";
	case -2053: return "Feature unsupported";
	case -2052: return "Couldn't use an existing sample";
	case -2051: return "No defaultdata reference";
	case -2050: return "Bad data reference index";
	case -2049: return "Invalid data reference container";
	case -2048: return "No movie found";
	case -2047: return "No data reference";
	case -2046: return "End of data reached";
	case -2045: return "data already closed";
	case -2044: return "Data already open for write";
	case -2043: return "Data not open for write";
	case -2042: return "Data not open for read";
	case -2041: return "Invalid sample description";
	case -2040: return "Invalid chunk cache";
	case -2039: return "Invalid sample description index";
	case -2038: return "Invalid chunk number";
	case -2037: return "Invalid sample number";
	case -2036: return "Invalid rectangle";
	case -2035: return "Can't enable track";
	case -2034: return "Internal QuickTime error";
	case -2033: return "Bad edit index";
	case -2032: return "Time not in media";
	case -2031: return "Time not in track";
	case -2030: return "Track not in movie";
	case -2029: return "Track ID not found";
	case -2028: return "Bad track index";
	case -2027: return "Max size to grow too small";
	case -2026: return "User data item not found";
	case -2025: return "Stale edit state";
	case -2024: return "Non-matching edit state";
	case -2023: return "Invalid edit state";
	case -2022: return "Can't create single fork file";
	case -2021: return "WF file not found";
	case -2020: return "Movie toolbox uninitialized";
	case -2019: return "Progress proc aborted";
	case -2018: return "Media types don't match";
	case -2017: return "Bad edit list";
	case -2016: return "Can't put public movie atom";
	case -2015: return "Invalid Time";
	case -2014: return "Invalid duration";
	case -2013: return "Invalid handler";
	case -2012: return "Invalid data reference";
	case -2011: return "Invalid sample table";
	case -2010: return "Invalid movie";
	case -2009: return "Invalid track";
	case -2008: return "Invalid media";
	case -2007: return "No data handler";
	case -2006: return "No media handler";
	case -2005: return "Bad component type";
	case -2004: return "Can't open handler";
	case -2003: return "Can't find handler";
	case -2002: return "Bad public movie atom";
	case -2001: return "Bad image description";
	case -2000: return "Could not resolve data reference";
	case -1857: return "Drag was not accepted by receiver";
	case -1856: return "Handler not found (Drag Manager)";
	case -1855: return "Handler already exists (Drag Manager) ";
	case -1854: return "Error while trying to get flavor data (Drag Manager)";
	case -1853: return "Flavor type already exists (Drag Manager)";
	case -1852: return "Unknown flavor type (Drag Manager)";
	case -1851: return "Unknown drag item reference";
	case -1850: return "Unknown drag reference";
	case -1813: return "Apple Event end of body";
	case -1812: return "Apple Event end of document";
	case -1811: return "Apple Event top of body";
	case -1810: return "Apple Event top of document";
	case -1801: return "Apple Event offset outside of view";
	case -1800: return "Apple Event offset invalid";
	case -1730: return "Empty list container";
	case -1729: return "Negative count";
	case -1728: return "No such object";
	case -1727: return "Not an object specifier";
	case -1726: return "Bad test key";
	case -1725: return "No such logical operator";
	case -1723: return "Accessor not found";
	case -1721: return "Wrong number of arguments";
	case -1720: return "Impossible range";
	case -1719: return "Index is out of range in a put operation";
	case -1718: return "The contents of the reply you are accessing have not arrived yet";
	case -1717: return "No handler in the dispatch tables fits the parameters";
	case -1716: return "The target address type is not known";
	case -1715: return "A required parameter was not accessed";
	case -1714: return "There is no special function with this keyword";
	case -1713: return "No user interaction allowed";
	case -1712: return "AppleEvent timed out";
	case -1711: return "In AESend, User canceled out of wait loop for reply or receipt";
	case -1710: return "Mode wasn't NoReply, WaitReply, or QueueReply; or Interaction level is unknown";
	case -1709: return "AEResetTimer was passed an invalid reply parameter";
	case -1708: return "The AppleEvent was not handled by any handler";
	case -1707: return "The event is not in AppleEvent format";
	case -1706: return "Need newer version of AppleEvent Manager";
	case -1705: return "Specified list item does not exist";
	case -1704: return "Not a valid AppleEvent descriptor";
	case -1703: return "Data with a keyword was expected but not found";
	case -1702: return "Data in an AppleEvent could not be read";
	case -1701: return "Descriptor was not found";
	case -1700: return "Data could not be coerced to the requested data type";
	case -1308: return "When _Mount allows only remounts and doesn't get a remount.";
	case -1307: return "File id is dangling or doesn't match with the file number";
	case -1306: return "Can't exchange a file with itself";
	case -1305: return "Desktop database files are corrupted";
	case -1304: return "The catalog has been modified";
	case -1303: return "Files on different volumes";
	case -1302: return "Directory specified";
	case -1301: return "File id already exists";
	case -1300: return "No file thread exists.";
	case -1280: return "Bad connection refNum";
	case -1279: return "Control call was aborted";
	case -1278: return "Bad connection state for this operation";
	case -1277: return "Open connection request failed";
	case -1276: return "Attention message too long";
	case -1275: return "Read terminated by forward reset";
	case -1274: return "DSP Read/Write Queue Too small";
	case -1273: return "Open connection request was denied";
	case -1105: return "Request aborted";
	case -1104: return "Too many outstanding ATP calls";
	case -1103: return "ATPAddRsp issued before ATPSndRsp";
	case -1102: return "ATP control block not found";
	case -1101: return "ATP no release received";
	case -1100: return "ATP bad sequence number";
	case -1099: return "ATP bad responding socket";
	case -1098: return "ATP too many responding sockets";
	case -1097: return "ATP too many concurrent requests";
	case -1096: return "ATPSndRequest failed: retry count exceeded";
	case -1075: return "No acknowledge on server attention request";
	case -1074: return "Too many server clients";
	case -1073: return "Command block too big";
	case -1072: return "Session closed";
	case -1071: return "Server cannot open another session";
	case -1070: return "ASP parameter error";
	case -1069: return "No servers at that address";
	case -1068: return "No more sessions on server";
	case -1067: return "Buffer too small";
	case -1066: return "Server cannot support this ASP version";
	case -1029: return "NBP names information socket error";
	case -1028: return "NBP name not found";
	case -1027: return "NBP duplicate name already exists";
	case -1026: return "NBP name confirmed for different socket";
	case -1025: return "NBP name not confirmed";
	case -1024: return "NBP buffer overflow";
	case -1011: return "Mixed mode failure";
	case -1010: return "Bad shared library";
	case -1000: return "No mask found";
	case -932: return "Destination port requires authentication";
	case -931: return "Location name is invalid ";
	case -930: return "Illegal service type, or not supported ";
	case -928: return "Invalid user reference number ";
	case -927: return "User's password is wrong";
	case -926: return "PPCStart failed because destination did not have inform pending ";
	case -925: return "Error has occurred in the network";
	case -924: return "Unable to create a new userRefNum";
	case -923: return "The default userRefNum does not yet exist ";
	case -922: return "User hasn't specified an owner's name in Sharing Setup Control Panel ";
	case -919: return "PPCPortRec malformed";
	case -917: return "The session was closed ";
	case -916: return "The port was closed";
	case -915: return "Unable to contact application ";
	case -914: return "A system resource is missing";
	case -913: return "User hasn't named his Macintosh in the Sharing Setup Control Panel";
	case -912: return "Destination rejected the session request";
	case -911: return "User name unknown on destination machine ";
	case -910: return "A port is already open with this name";
	case -909: return "Bad parameter or invalid state for operation";
	case -908: return "Invalid session reference number ";
	case -907: return "Out of session tables";
	case -906: return "Port does not exist at destination";
	case -905: return "Network activity is currently disabled ";
	case -904: return "The system is unable to allocate memory, critical error";
	case -903: return "Unable to open port or bad portRefNum";
	case -902: return "Invalid or inappropriate locationKindSelector in location name";
	case -900: return "PPCToolBox not initialized ";
	case -863: return "User using Close View won't let you remove balloons";
	case -862: return "No balloon showing";
	case -861: return "Invalid method passed in the method parameter";
	case -860: return "Help Manager - could not load package";
	case -859: return "Help message record contained a bad type";
	case -858: return "Help manager resource was the wrong version";
	case -857: return "No balloon content to fill in";
	case -856: return "Help Manager - bad selector";
	case -855: return "Help menu not set up";
	case -854: return "Menu & item is same as previous menu, item";
	case -853: return "Because of constant cursor movement, the help balloon was not displayed";
	case -852: return "Help Manager - out of memory";
	case -851: return "Help Manager - resource not found";
	case -850: return "Show Balloons mode was off, call to routine ignored";
	case -813: return "Attempt to call other routine before InitDBPack";
	case -812: return "Wrong version ";
	case -811: return "No application handler for specified data type";
	case -810: return "Invalid parameter block specified";
	case -809: return "The database extension does not support async calls";
	case -808: return "Couldn't open or find the specified database extension.";
	case -807: return "Invalid session number";
	case -806: return "Session ID is invalid";
	case -805: return "Query currently executing";
	case -804: return "Function timed out";
	case -803: return "Next data item not of requested data type";
	case -802: return "Error executing function";
	case -801: return "Data available or successfully retrieved";
	case -800: return "The data item was NULL";
	case -625: return "Unable to defer additional functions";
	case -624: return "Called with interrupts masked";
	case -623: return "Specified range of memory is not locked";
	case -622: return "Cannot make specified range contiguous";
	case -621: return "Specified range of memory is not held";
	case -620: return "Insufficient physical memory";
	case -619: return "Bad thread protocol";
	case -618: return "Thread not found";
	case -617: return "Thread Manager--Too many reqs";
	case -610: return "Cannot interact directly with user";
	case -609: return "Connection is invalid";
	case -608: return "No outstanding high-level event";
	case -607: return "Buffer is too small";
	case -606: return "Application is background only";
	case -605: return "Application SIZE not big enough for launch ";
	case -604: return "Hardware configuration is not correct for call ";
	case -603: return "Application made module calls in improper order ";
	case -602: return "Memory mode is 32-bit, but application is not 32-bit clean ";
	case -601: return "Not enough room to launch application with special requirements";
	case -600: return "No eligible process with specified process serial number ";
	case -502: return "Bad selector for _HWPriv";
	case -501: return "Scrap item too big for text edit record";
	case -500: return "Region is too big";
	case -492: return "User debugger break - execute commands on stack";
	case -491: return "User debugger break - display string on stack";
	case -490: return "User debugger break";
	case -489: return "Unimplemented routine was called (SCSI)";
	case -479: return "Linked command never executed (SCSI)";
	case -478: return "Device did not go through a status phase (SCSI)";
	case -477: return "Non-zero (not \"Good\") status returned (SCSI)";
	case -476: return "The bus was reset, so your request was aborted (SCSI)";
	case -475: return "scsiReqTO exceeded (SCSI)";
	case -474: return "scsiSelTO exceeded (selection failed) (SCSI)";
	case -473: return "(SCSI)us error during transfer (SCSI)";
	case -472: return "Write flag conflicts with data transfer phase (SCSI)";
	case -471: return "Attempted to transfer too many bytes (SCSI)";
	case -470: return "Invalid field(s) in the parameter block (SCSI)";
	case -463: return "Not the first registered publisher for that container";
	case -462: return "Container already opened by this section";
	case -461: return "Alias was not resolved";
	case -460: return "A Publisher is already registered for that container";
	case -454: return "Bad edition container spec or invalid edition container";
	case -453: return "Edition file is corrupt";
	case -452: return "Not a registered section type";
	case -451: return "Not a valid section type";
	case -450: return "Edition manager not initialized or could not load package.";
	case -417: return "There is no such a key attribute";
	case -416: return "Maximum key length is too long or equal to zero";
	case -415: return "Record cannot be found";
	case -414: return "Record already exists";
	case -413: return "Can't allocate disk space";
	case -410: return "The file is not a dictionary";
	case -400: return "GCR format on high density media error";
	case -360: return "Invalid slot number";
	case -351: return "Record not found in the SRT";
	case -350: return "SRT overflow";
	case -349: return "No opens were successful in the loop";
	case -348: return "Offset was too big";
	case -347: return "NumByteLanes was determined to be zero";
	case -346: return "Bad sPointer was passed to a SDM call";
	case -345: return "Error occurred during _sGetDriver";
	case -344: return "No more sResources";
	case -343: return "Error occurred during _sDisDrvrName";
	case -342: return "Error occurred during _sGetDrvrName";
	case -341: return "Status of slot is bad";
	case -340: return "Error occurred during _BlockMove";
	case -339: return "Error occurred during _NewPtr";
	case -338: return "Selector out of bounds";
	case -337: return "Slot out of bounds or does not exist";
	case -336: return "The physical block size of an sBlock was zero";
	case -335: return "The sPointer is nil; no list is specified";
	case -334: return "The CPU field of the code to be executed by sExec was wrong";
	case -333: return "The revision code to be executed by sExec was wrong";
	case -332: return "A reserved field was not zero";
	case -331: return "The id's in the given sList are not in ascending order";
	case -330: return "Reference id not found in the given list";
	case -320: return "Bus error timeout";
	case -319: return "Board ID was wrong: Init the PRAM record";
	case -318: return "SDM jump table could not be created";
	case -317: return "Error occurred while trying to initialize the slot resource table";
	case -316: return "The InitStatus_V field was negative after primary init";
	case -315: return "No board id";
	case -314: return "Error occurred during _sGetPRAMRec";
	case -313: return "No board sResource";
	case -312: return "Error occurred during _DisposePointer";
	case -311: return "The F-Header block could not be disposed";
	case -310: return "The F-Header block could not be read";
	case -309: return "A valid ByteLane field was not found";
	case -308: return "An unexpected bus error occurred";
	case -307: return "A reserved field of the declaration ROM was used";
	case -306: return "The SDM was unable to allocate memory for the sInfo array";
	case -305: return "The longword test failed";
	case -304: return "There is no directory";
	case -303: return "The revision of the declaration ROM is wrong";
	case -302: return "The format of the declaration ROM is wrong";
	case -301: return "CRC check failed";
	case -300: return "No card in slot";
	case -299: return "Wrong queue type";
	case -293: return "Cards could not be initialized";
	case -292: return "Slot Resource Table could not be initialized";
	case -291: return "Slot Resource Table could not be initialized";
	case -290: return "SDM could not be initialized";
	case -261: return "Command not supported for port type";
	case -260: return "Duplicate client ID";
	case -259: return "Name supplied is longer than 31 characters";
	case -258: return "MIDIWritePacket couldn't write to all connected ports";
	case -257: return "No connection exists between specified ports";
	case -256: return "Pending virtual connection removed";
	case -255: return "Pending virtual connection resolved";
	case -254: return "Pending virtual connection created";
	case -253: return "Too many connections made";
	case -252: return "Too many ports already installed in the system";
	case -251: return "No port with that ID found";
	case -250: return "No client with that ID found ";
	case -247: return "Bad input text";
	case -246: return "Bad dictionary format";
	case -245: return "Incompatible voice";
	case -244: return "Voice not found";
	case -243: return "Buffer too small";
	case -242: return "Synthesizer not ready";
	case -241: return "Synthesizer open failed";
	case -240: return "No synthesizer found";
	case -232: return "Unknown quality";
	case -231: return "Unknown type of information";
	case -230: return "Input device hardware failure";
	case -229: return "Invalid input device reference number";
	case -228: return "Input device could not be opened";
	case -227: return "Input device already in use";
	case -226: return "Invalid sample size";
	case -225: return "Invalid sample rate";
	case -224: return "Hard disk drive too slow to record to disk";
	case -223: return "Invalid compression type";
	case -222: return "No buffer specified";
	case -221: return "Invalid Sound Input device";
	case -220: return "No Sound Input hardware";
	case -213: return "A parameter is incorrect";
	case -212: return "Not enough CPU cycles left to add another task";
	case -211: return "Channel not currently used";
	case -210: return "Can not operate in the memory allowed ";
	case -209: return "The Channel is being used already ";
	case -208: return "Corrupt/bad format or not of type AIFF";
	case -207: return "Could not allocate enough memory";
	case -206: return "Bad sound resource format";
	case -205: return "Bad sound channel specified";
	case -204: return "Sound resource error";
	case -203: return "Sound channel full";
	case -201: return "All available channels are already open for the synthesizer";
	case -200: return "No sound hardware";
	case -199: return "Resource map read error";
	case -198: return "Resource attribute error";
	case -197: return "RmveReference failed";
	case -196: return "RmveResource failed";
	case -195: return "AddReference failed";
	case -194: return "AddResource failed";
	case -193: return "Resource file not found";
	case -192: return "Resource not found";
	case -190: return "Offset or count out of bounds";
	case -189: return "Writing past end of file";
	case -188: return "Resource already in memory";
	case -186: return "Resource bent - Can't decompress a compressed resource";
	case -185: return "Extended resource has a bad format.";
	case -158: return "Invalid parameter";
	case -157: return "Invalid pixel depth";
	case -156: return "Invalid resolution for MakeITable";
	case -155: return "Invalid type of graphics device";
	case -154: return "ColorTable entry protection violation";
	case -153: return "Range error in colorTable request";
	case -152: return "Failed to allocate memory for structure";
	case -151: return "Failed to allocate memory for temporary structures";
	case -150: return "Color2Index failed to find an index";
	case -149: return "QuickDraw could not complete the operation (insufficient stack)";
	case -148: return "Pixel map record is deeper than 1 bit per pixel";
	case -147: return "Region accumulation failed. Resulting region may be corrupt";
	case -145: return "Not enough memory for picture";
	case -132: return "File id already exists";
	case -131: return "Directory specified";
	case -130: return "No file thread exists";
	case -128: return "User canceled the query";
	case -127: return "Could not find HMenu's parent in MenuKey";
	case -126: return "System error code for MBDF not found";
	case -125: return "Insufficient memory to update a pixmap";
	case -124: return "Server volume has been disconnected";
	case -123: return "Attempt to do a hierarchical operation on a non hierarchical volume";
	case -122: return "Attempt to move into offspring (file system)";
	case -121: return "Too many working directories open";
	case -120: return "Directory not found";
	case -117: return "Block is locked";
	case -116: return "Size check failed";
	case -115: return "Block check failed";
	case -114: return "Pointer check failed";
	case -113: return "Address in zone check failed";
	case -112: return "Attempt to purge a locked or non-purgeable block";
	case -111: return "Attempt to operate on a free block";
	case -110: return "Address was odd, or out of range";
	case -109: return "NIL master pointer";
	case -108: return "Not enough room in heap zone";
	case -102: return "No object of that type in scrap";
	case -100: return "Desk scrap isn't initialized";
	case -99: return "Error in ROZ";
	case -98: return "Driver open error; port not configured for this connection";
	case -97: return "Driver open error; port already in use";
	case -95: return "Excessive collisions on AppleTalk write";
	case -94: return "AppleTalk error in attaching/detaching protocol";
	case -93: return "No AppleTalk bridge found";
	case -92: return "AppleTalk data length too big";
	case -91: return "AppleTalk socket error: socket already active; not a known socket; socket table full; all dynamic socket numbers in use / Multicast address error ddpSktErr";
	case -90: return "SCC break received";
	case -89: return "SCC receiver error";
	case -88: return "Parameter RAM uninitialized";
	case -87: return "Parameter RAM written did not verify";
	case -86: return "Time written did not verify";
	case -85: return "Unable to read clock";
	case -84: return "Track failed to verify / I/O error";
	case -83: return "Cannot synchronize";
	case -82: return "Can't find sector 0 after track format";
	case -81: return "Can't find sector";
	case -80: return "Drive error (track number wrong in address mark)";
	case -79: return "Can't correctly adjust disk speed";
	case -78: return "Tried to read side 2 of a disk in a single-sided drive";
	case -77: return "Can't initialize disk controller chip";
	case -76: return "Can't find track 0";
	case -75: return "Drive error";
	case -74: return "Write underrun occurred";
	case -73: return "Bad data mark bit slip nibbles";
	case -72: return "Bad data mark checksum";
	case -71: return "Can't find a data mark";
	case -70: return "Bad address mark (bit slip nibbles)";
	case -69: return "Bad address mark (checksum didn't check)";
	case -68: return "Read verify failed";
	case -67: return "Can't find an address mark";
	case -66: return "Disk is probably blank / Font substitution occurred";
	case -65: return "No disk in drive / Font not declared";
	case -64: return "Drive isn't connected / Font declaration error / I/O error";
	case -61: return "Read/write permission doesn't allow writing";
	case -60: return "Bad master directory block; must reinitialize volume";
	case -59: return "Problem during rename";
	case -58: return "External file system; file-system identifier is non zero, or path reference number is greater than 1024";
	case -57: return "Not a Macintosh disk; volume lacks Macintosh-format directory";
	case -56: return "No such drive; specified drive number doesn't match any number in the drive queue";
	case -55: return "Specified volume is already mounted and on-line";
	case -54: return "Attempt to open locked file for writing";
	case -53: return "Volume not on-line";
	case -52: return "Error getting file position";
	case -51: return "Path reference number specifies nonexistent access path";
	case -50: return "Error in parameter list / Not an existing volume, and no default volume / Bad positioning information / Bad drive number";
	case -49: return "The read/write permission of only one access path to a file can allow writing";
	case -48: return "File with specified name and version number already exists";
	case -47: return "File is busy; one or more files are open";
	case -46: return "Volume is locked by a software flag";
	case -45: return "File is locked";
	case -44: return "Volume is locked by a hardware setting";
	case -43: return "File not found";
	case -42: return "Too many files open";
	case -41: return "Memory full (open) or file won't fit (load)";
	case -40: return "Attempt to position before start of file";
	case -39: return "Logical end-of-file reached during read operation";
	case -38: return "File not open";
	case -37: return "Bad file name or volume name (perhaps zero-length)";
	case -36: return "I/O error";
	case -35: return "Specified volume doesn't exist";
	case -34: return "All allocation blocks on the volume are full";
	case -33: return "File directory full";
	case -30: return "DCE extension error";
	case -29: return "Unit table has no more entries";
	case -28: return "Driver isn't open";
	case -27: return "I/O request aborted by KillIO / I/O abort error";
	case -26: return "Couldn't find driver in resource file";
	case -25: return "Attempt to remove an open driver";
	case -24: return "Close error";
	case -23: return "Requested read/write permission doesn't match driver's open permission / Attempt to open RAM Serial Driver failed";
	case -22: return "Driver reference number specifies NIL handle in unit table";
	case -21: return "Driver reference number doesn't match unit table";
	case -20: return "Driver can't respond to Write call";
	case -19: return "Driver can't respond to Read call";
	case -18: return "Driver can't respond to Status call";
	case -17: return "Driver can't respond to Control call / Unimplemented control instruction";
	case -13: return "Extensions disabled";
	case -12: return "Process ID not in valid range or unavailable";
	case -11: return "Disassembler installed";
	case -10: return "MacsBug installed";
	case -9: return "Miscellaneous system error";
	case -8: return "No debugger installed to handle debugger command";
	case -5: return "Invalid Power Manager queue element";
	case -4: return "Unimplemented core routine";
	case -3: return "Core routine number out of range";
	case -2: return "Invalid queue element";
	case -1: return "Saving spool file / Entry not in queue";
	case 0: return "No error";
	case 1: return "Event type not designated in system event mask / bus error / uninitialized slot interrupt dispatch table";
	case 2: return "No such file";
	case 3: return "No such resource / Arbitration failed during SCSIGet; bus busy / uninitialized slot priority table";
	case 4: return "Interrupted system call";
	case 5: return "I/O error";
	case 6: return "No such device";
	case 7: return "Insufficient space for return argument / SCSI Manager busy with another operation";
	case 8: return "Attempted operation was out of sequence (e.g., SCSISelect before SCSIGet)";
	case 9: return "File not open or bad file number";
	case 10: return "SCSIComplete failed; bus not in status phase";
	case 11: return "Miscellaneous hardware exception error";
	case 12: return "Not enough memory / Slot resource table uninitialized / Unimplemented Core routine";
	case 13: return "Permission denied / Slot PRAM uninitialized / Uninstalled interrupt error";
	case 14: return "Bad address / I/O Core Error";
	case 15: return "Block device required / Segment loader error";
	case 16: return "Mount device busy / Floating Point error / Serial driver error";
	case 17: return "File exists";
	case 18: return "Cross-device link";
	case 19: return "No such device";
	case 20: return "Not a directory";
	case 21: return "Is a directory";
	case 22: return "Invalid or unsupported parameter";
	case 23: return "File table overflow";
	case 24: return "Too many open files";
	case 25: return "Not an interactive device / Out of memory";
	case 26: return "Text file busy / Can't launch file";
	case 27: return "File too large / File system map has been trashed";
	case 28: return "No space left on device / Stack has moved into application heap";
	case 29: return "Illegal seek";
	case 30: return "Read-only file system";
	case 31: return "Too many links";
	case 32: return "Serial hardware overrun";
	case 33: return "Math argument out or range for domain of function";
	case 34: return "Math result not representable";
	case 35: return "Record doesn't fit in node ";
	case 36: return "Time out waiting for sync after holdoff";
	case 37: return "Time out waiting for HSHK high";
	case 38: return "Checksum error on response packet";
	case 40: return "Welcome to Macintosh greeting";
	case 41: return "Can't load the Finder error";
	case 42: return "Shutdown error / Unable to mount boot volume (sad Mac only)";
	case 43: return "Can't find System file to open (sad Mac only)";
	case 48: return "First byte in response packet was wrong";
	case 49: return "Sequence number in response packet was wrong";
	case 50: return "Drive number in response packet was wrong";
	case 51: return "Unserviceable slot interrupt";
	case 52: return "Detected bad catalog structure";
	case 53: return "Thread belongs to a directory not a file";
	case 54: return "File thread doesn't exist";
	case 64: return "Serial driver error";
	case 81: return "Bad opcode given to SANE Pack4";
	case 83: return "SetTrapAddress saw the \"come-from\" header";
	case 84: return "A menu was purged";
	case 85: return "MBDF resource not found";
	case 86: return "Hierarchical menus cannot be recursive";
	case 87: return "Could not load WDEF";
	case 88: return "Could not load CDEF";
	case 89: return "Could not load MDEF";
	case 90: return "An FPU instruction was executed and the machine doesn't have one";
	case 98: return "Can't patch for particular Model Mac";
	case 99: return "Can't load patch resource";
	case 101: return "Memory parity error";
	case 102: return "System is too old for this ROM";
	case 103: return "Booting in 32-bit on a 24-bit system";
	case 104: return "Need to write new boot blocks";
	case 105: return "Must have at least 1.5MB of RAM to boot 7.0";
	case 106: return "BufPtr moved too far during boot";
	case 128: return "Application or user requested abort";
	case 255: return "All command words less than this are errors";
	case 20000: return "User choice between ShutDown and Restart";
	case 20001: return "User choice between switching off and Restart";
	case 20002: return "Allow the user to ExitToShell, return if Cancel";
	case 32767: return "General system error (catch-all used in DSAT)";	

	default: return NULL;
	}
}

namespace MacOS {

	namespace {
		class __system_category : public std::error_category
		{
		public:
			virtual const char* name() const noexcept;
			virtual std::string message(int ev) const;
    		virtual std::error_condition default_error_condition(int ev) const noexcept;

		private:
			static int remap(macos_error e);

		};


		const char *__system_category::name() const noexcept
		{
			return "macos error";
		}

		std::string __system_category::message(int ev) const
		{

			const char *cp = ErrorName(ev);
			if (cp) return std::string(cp);

			std::string tmp("Unknown error: ");
			tmp += std::to_string(ev);
			return tmp;
		}

    	std::error_condition __system_category::default_error_condition(int ev) const noexcept
    	{

    		int x = remap(static_cast<macos_error>(ev));
    		if (x >= 0) return std::error_condition(x, std::generic_category());

    		return std::error_condition(ev, macos_system_category());
    	}

		int __system_category::remap(macos_error e)
		{
			// todo
			switch(e)
			{
			case rfNumErr: return EBADF;
			case ioErr: return EIO;
			case permErr: return EACCES;
			case fnfErr: return ENOENT;
			case dirNFErr: return ENOTDIR;
			case notAFileErr: return EISDIR;
			case extFSErr: return ENOTSUP;
			case wPrErr: return EROFS;
			case dupFNErr: return EEXIST;
			case fBsyErr: return EBUSY;
			case dskFulErr: return ENOSPC;
			case paramErr: return EINVAL;
			case posErr: return EINVAL;
			case memFullErr: return ENOMEM;
			case mFulErr: return ENOMEM;
			case tmfoErr: return ENFILE;

			default: return -1;
			}

		}

	}

	const std::error_category& macos_system_category()
	{
		static __system_category s;
		return s;		
	}



    macos_error macos_error_from_errno()
    {
    	return macos_error_from_errno(errno);
    }


    macos_error macos_error_from_errno(const std::error_code &ec) {
    	if (!ec) return noErr;

    	// generic_category is a posix errno.
    	// system_category is the native error (eg posix errno or windows error)
    	// but will default_error_condition() to a generic_category, if possible.

    	if (ec.category() == std::generic_category())
    		return macos_error_from_errno(ec.value());

    	if (ec.category() == macos_system_category()) return (macos_error)ec.value();

		std::error_condition econd = ec.default_error_condition();
		if (econd.category() == std::generic_category())
			return macos_error_from_errno(econd.value());

    	return ioErr; 
    }


    macos_error macos_error_from_errno(int error)
    {
		switch(error)
		{
			case 0: return noErr;
			case EBADF: return rfNumErr;
			case EIO: return ioErr;
			case EACCES: return permErr;
			case EPERM: return permErr;
			case ENOENT: return fnfErr;
			case ENOTDIR: return dirNFErr;
			case EISDIR: return notAFileErr;
			case ENOTSUP: return extFSErr;
			case EROFS: return wPrErr;
			case EINVAL: return paramErr;

			case EEXIST: return dupFNErr;

			case EBUSY: return fBsyErr;
			case ENOTEMPTY: return fBsyErr;

#ifdef EDQUOT
			case EDQUOT: return dskFulErr;
#endif
			case ENOSPC: return dskFulErr;
			case ENOMEM: return mFulErr;
			case ENFILE: return tmfoErr;


			default:
				return ioErr;
		}

    }

}
