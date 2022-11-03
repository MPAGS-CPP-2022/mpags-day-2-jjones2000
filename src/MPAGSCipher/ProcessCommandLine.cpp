#include <cctype>
#include <vector>
#include <string>
#include <iostream>

#include "ProcessCommandLine.hpp"

bool processCommandLine(
	const std::vector<std::string> args,
	bool& helpRequested,
	bool& versionRequested,
	std::string& inputFileName,
	std::string& outputFileName,
	bool& encrypt,
	int& key )
{// Processes command line arguments.
const std::size_t nCmdLineArgs{args.size()};
   // Process command line arguments - ignore zeroth element, as we know this
    // to be the program name and don't need to worry about it
    for (std::size_t i{1}; i < nCmdLineArgs; ++i) {
        if (args[i] == "-h" || args[i] == "--help") {
            helpRequested = true;
        } else if (args[i] == "--version") {
            versionRequested = true;
        } else if (args[i] == "-i") {
            // Handle input file option
            // Next element is filename unless "-i" is the last argument
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -i requires a filename argument"
                          << std::endl;
                // exit main with non-zero return to indicate failure
                return 1;
            } else {
                // Got filename, so assign value and advance past it
                inputFileName = args[i + 1];
                ++i;
            }
        } else if (args[i] == "-o") {
            // Handle output file option
	    // Next element is filename unless "-o" is the last argument
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -o requires a filename argument"
                          << std::endl;
                // exit main with non-zero return to indicate failure
                return 1;
            } else {
                // Got filename, so assign value and advance past it
                outputFileName = args[i + 1];
                ++i;
            }
        } else if (args[i] == "-d" || args[i] == "--decrypt") {
	// Decrypts if given this option
		encrypt = false;
                ++i;
	} else if (args[i] == "-k" || args[i] == "--key") {
	// Handle value of key
	if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -k requires a value"
                          << std::endl;
                // exit main with non-zero return to indicate failure
                return 1;
            } else {
                // Got filename, so assign value and advance past it
                key = std::stoul(args[i + 1]);
		if (key < 0 || key > 25){
			std::cerr << "[error] key must be between 0 and 25" << std::endl;
			return 1;
		}
                ++i;
            }

	}
	 else {
            // Have an unknown flag to output error message and return non-zero
            // exit status to indicate failure
            std::cerr << "[error] unknown argument '" << args[i]
                      << "'\n";
            return 1;
        }
    }
return 1;
}
