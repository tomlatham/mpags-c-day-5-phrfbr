#ifndef MPAGSCIPHER_CIPHERFACTORY_HPP
#define MPAGSCIPHER_CIPHERFACTORY_HPP


#include <memory> 
#include "Cipher.hpp"
#include "CipherType.hpp"
#include <string>




std::unique_ptr<Cipher> cipherFactory( const CipherType type, const std::string& key);














#endif
