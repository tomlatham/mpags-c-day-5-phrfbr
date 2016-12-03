//! Unit Tests for MPAGSCipher Ciphers
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "CipherMode.hpp"
#include "CipherType.hpp"
#include "Cipher.hpp"
#include "CipherFactory.hpp"

bool testCipher( const Cipher& cipher, const CipherMode cipherMode, const std::string& inputText, const std::string& outputText)
{
  return cipher.applyCipher (inputText, cipherMode)  == outputText;
}

TEST_CASE("Cipher encryption/decryption", "[ciphers]") {
  std::vector<std::unique_ptr<Cipher>> ciphers;
  ciphers.push_back( cipherFactory(CipherType::Caesar,"10") );
  ciphers.push_back( cipherFactory(CipherType::Playfair,"hello") );
  ciphers.push_back( cipherFactory(CipherType::Vigenere,"key") );

  std::vector<std::string> plainText;
  plainText.push_back("HELLOWORLD");
  plainText.push_back("BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ");
  plainText.push_back("HELLOWORLD");

  std::vector<std::string> cipherText;
  cipherText.push_back("ROVVYGYBVN");
  cipherText.push_back("FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA");
  cipherText.push_back("RIJVSUYVJN");

  for ( size_t i{0}; i < ciphers.size(); ++i ) {
    REQUIRE( ciphers[i] );
    REQUIRE( testCipher( *ciphers[i], CipherMode::Encrypt, plainText[i], cipherText[i]) );
    REQUIRE( testCipher( *ciphers[i], CipherMode::Decrypt, cipherText[i], plainText[i]) );
  }
}


