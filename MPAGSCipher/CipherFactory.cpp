#include "CipherFactory.hpp"
#include <iostream>
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"


std::unique_ptr<Cipher> cipherFactory( const CipherType type, const std::string& key)
{

	switch (type) {

		case CipherType::Caesar :
		{
	        	size_t caesarKey {0};
			if ( ! key.empty() ) {

	 			 for ( const auto& elem : key ) {
	    				if ( ! std::isdigit(elem) ) {
	      					std::cerr << "[error] cipher key must be an unsigned long integer for Caesar cipher,\n"
						<< "        the supplied key (" << key << ") could not be successfully converted" << std::endl;
	      					return std::unique_ptr<Cipher>();
	    				}
	 			 }
	 			 caesarKey = std::stoul(key);
			}


			return std::make_unique<CaesarCipher>( caesarKey );
		}
		case CipherType::Playfair :
		{
			return std::make_unique<PlayfairCipher>( key );
		}
		case CipherType::Vigenere :
		{
			return std::make_unique<VigenereCipher>( key );
		}
	}

return 0;

}			
