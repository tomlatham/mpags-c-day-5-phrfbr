#ifndef MPAGSCIPHER_CIPHER_HPP
#define MPAGSCIPHER_CIPHER_HPP

#include "CipherMode.hpp"

class Cipher {
	
	public:

/**
* \class Cipher.hpp 
*
*
* \brief Definitions needed when defining a virtual destructor 

**/


		Cipher() = default;  
		Cipher(const Cipher& rhs) = default;   ///< Copy constructor
		Cipher(Cipher&& rhs) = default;   ///< Move constructor
		Cipher& operator=(const Cipher& rhs) = default;   ///< Copy assignment operator
		Cipher& operator=(Cipher&& rhs) = default;   ///< Move assignment operator 
		virtual ~Cipher() = default; ///< Virtual destructor needed

/// Define one pure vitual member functions

		virtual std::string applyCipher( const std::string& input, const CipherMode cipherMode ) const=0;

};

#endif // MPAGSCIPHER_CIPHER_HPP
