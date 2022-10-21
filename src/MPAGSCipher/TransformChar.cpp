#include <iostream>
#include <cctype>
#include <string>

#include "TransformChar.hpp"

std::string transformChar(const char in_char)
{// Transform digits to english translisterations.
        // Uppercase alphabetic characters
    std::string inputText{""};

if (std::isalpha(in_char)) {
    inputText = std::toupper(in_char);
    return inputText;
}



switch (in_char) {
            case '0':
                return "ZERO";
                break;
            case '1':
                return "ONE";
                break;
            case '2':
                return "TWO";
                break;
            case '3':
                return "THREE";
                break;
            case '4':
                return "FOUR";
                break;
            case '5':
                return "FIVE";
                break;
            case '6':
                return "SIX";
                break;
            case '7':
                return "SEVEN";
                break;
            case '8':
                return "EIGHT";
                break;
            case '9':
                return "NINE";
                break;
        }

	return inputText;
}


