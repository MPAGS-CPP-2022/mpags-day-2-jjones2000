#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// Our project headers.
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "Cipher.hpp"

int main(int argc, char* argv[])
{
    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};

    // Options that might be set by the command-line arguments
    bool helpRequested{false};
    bool versionRequested{false};
    std::string inputFile{""};
    std::string outputFile{""};

    // Variables for cipher.
    bool encrypt{true};
    int key = 0;

    // Check that there are arguments.
    if (!processCommandLine(cmdLineArgs, helpRequested, versionRequested, inputFile, outputFile, encrypt, key))
    {
         return 1;
    }

    // Handle help, if requested
    if (helpRequested) {
        // Line splitting for readability
        std::cout
            << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << "  -k INT	   Number of places to shift letters by\n\n"
	    << "  -d		   Changes application to decrypt mode\n"
	    << std::endl;
        // Help requires no further action, so return from main
        // with 0 used to indicate success
        return 0;
    }

    // Handle version, if requested
    // Like help, requires no further action,
    // so return from main with zero to indicate success
    if (versionRequested) {
        std::cout << "0.1.0" << std::endl;
        return 0;
    }

    // Initialise variables
    char inputChar{'x'};
    std::string inputText;

    // Read in user input from stdin/file
    // Warn that input file option not yet implemented
    if (!inputFile.empty()) {
        std::ifstream in_file {inputFile};
	if (in_file.good())
	{
	 in_file >> inputChar;
	while (in_file >> inputChar){
	    inputText += transformChar(inputChar);
	}
	in_file.close();
	}
    }
    else {
    // loop over each character from user input
    while (std::cin >> inputChar) {
        // Transliterate digits to English words and add them to the text.
	inputText += transformChar(inputChar);

    }
    }
    std::string outputText {""};
    outputText = runCaesarCipher(inputText, key, encrypt);
    // Warn that output file option not yet implemented
    if (!outputFile.empty()) {
	std::ofstream out_file {outputFile};
	if (out_file.good()){
		out_file << outputText;
	}
    }else{

    std::cout << inputText << std::endl;
    }

    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
}
