//! Unit Tests for MPAGSCipher Ciphers
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "CipherMode.hpp"
#include "Cipher.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

bool testCipher( const Cipher& cipher, const CipherMode cipherMode, const std::string& inputText, const std::string& outputText)
{
return cipher.applyCipher (inputText, cipherMode)  == outputText;
}


TEST_CASE("Caesar Cipher encryption", "[caesar]") {
  CaesarCipher cc{10};
  REQUIRE( testCipher( cc, CipherMode::Encrypt, "HELLOWORLD", "ROVVYGYBVN"));
}


TEST_CASE("Playfair Cipher encryption", "[playfair]") {
  PlayfairCipher cc{"hello"};
  REQUIRE( testCipher( cc, CipherMode::Encrypt,"BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING", "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA"));
}


TEST_CASE("Vigenere Cipher encryption", "[vigenere]") {
  VigenereCipher vc{"key"};
  REQUIRE( testCipher( vc, CipherMode::Encrypt, "HELLOWORLD",  "RIJVSUYVJN"));
}


TEST_CASE("Caesar Cipher decryption", "[caesar]") {
  CaesarCipher cc{10};
  REQUIRE( testCipher( cc, CipherMode::Decrypt, "ROVVYGYBVN", "HELLOWORLD"));
}


TEST_CASE("Playfair Cipher decryption", "[playfair]") {
  PlayfairCipher cc{"hello"};
  REQUIRE( testCipher( cc, CipherMode::Decrypt, "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA","BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ"));
}


TEST_CASE("Vigenere Cipher decryption", "[vigenere]") {
  VigenereCipher vc{"key"};
  REQUIRE( testCipher( vc, CipherMode::Decrypt, "RIJVSUYVJN" ,"HELLOWORLD"));
}


