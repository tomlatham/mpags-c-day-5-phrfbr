
// Standard library includes
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

// Out project headers
#include "Alphabet.hpp"
#include "VigenereCipher.hpp"

VigenereCipher::VigenereCipher ( const std::string& key )
{
// Set the given key
setKey(key);
}


void VigenereCipher::setKey(const std::string& key ){

	// Store the key

	key_ = key;

	// Make sure the key is uppercase

	std::transform( std::begin(key_), std::end(key_), std::begin(key_), ::toupper );

	// Remove non-alpha characters

	key_.erase( std::remove_if( std::begin(key_), std::end(key_), [](char c){ return !std::isalpha(c); } ), std::end(key_) );

	// loop over the key

	for ( const auto& keyChar : key_ ) {

		// Check if letter has been found already
		if (charLookup_.find(keyChar) != charLookup_.end()) {
			continue;
		}	

		// Find the letter position in the alphabet

		unsigned int index = Alphabet::alphabet.find(keyChar);

		// Create a CaesarCipher using this position as a key

		CaesarCipher cipher {index};

		// Insert a std::pair of the letter and CaesarCipherinto the lookup

		charLookup_.insert( std::make_pair(keyChar,cipher) ); 

	}

	std::cout << "Congrats you're not an idiot" << std::endl;
	}



	std::string VigenereCipher::applyCipher( const std::string& inputText, const CipherMode cipherMode ) const{

	// For each letter in input:

std::string outputText{""};

	const int inputSize = inputText.length();

	for (int i = 0; i < inputSize; ++i){

		// Find the corresponding letter in the key, 		
		// repeating/truncating as required

		char keyLetter = { key_[i % key_.length()] };

		// Find the Caesar cipher from the lookup

		auto iter = charLookup_.find(keyLetter);
		auto& caesar = (*iter).second; 

		// Caesar Cipher (De)Encryption

		std::string inputString {inputText[i]};
		std::string cipherLett = caesar.applyCipher( inputString, cipherMode );

		// Add to the output text

		outputText += cipherLett;


	}

return outputText;

}
