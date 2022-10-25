#include "Cipher.hpp"
#include <string> // String
#include <vector> // Vector
#include <algorithm> // Find, distance

std::string runCaesarCipher( const std::string& inputText,
	const size_t key, const bool encrypt)
{
	// Create the alphabet container and output string.
	std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //"abcdefghijklmnopqrstuvwxys";
	std::string outputString = "";
	// Loop over input text.
	for (size_t i = 0; i < inputText.size(); i++)
	{
	char currentChar = inputText.at(i);
	auto it = std::find(alphabet.begin(), alphabet.end(), currentChar);
	size_t charIndex = std::distance(alphabet.begin(), it);
	if (encrypt){
	charIndex = (charIndex + key)%26;
	}else{
	charIndex = (charIndex - key)%26;
	}
	outputString += alphabet.at(charIndex);
	}
	// For each character find the corresponding position in the alphabet.

	// Apply the shift (+ve (-ve) for encrypt (decrypt)).
	// to the position, handling correctly potential wrap-around.

	// Determine the new character and add it to the output string.

	// Finally (after the loop), return the output string.
	return outputString;
}
