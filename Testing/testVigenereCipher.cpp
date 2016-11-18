//! Unit Tests for MPAGSCipher CaesarCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "VigenereCipher.hpp"

TEST_CASE("Vigenere Cipher encryption", "[vigenere]") {
  VigenereCipher vc{"key"};
  REQUIRE( vc.applyCipher("HELLOWORLD", CipherMode::Encrypt) == "RIJVSUYVJN");
}

TEST_CASE("Vigenere Cipher decryption", "[vigenere]") {
  VigenereCipher vc{"key"};
  REQUIRE( vc.applyCipher("RIJVSUYVJN", CipherMode::Decrypt) == "HELLOWORLD");
}
