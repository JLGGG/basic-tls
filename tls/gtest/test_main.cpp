#include "diffie_hellman.hpp"
#include <gtest/gtest.h>

TEST(TlsTest, mpz) {
  uint8_t arr[8];
  mpz_class a {"0x1234567890abcdef"};
  mpz2bnd(a, arr, arr + 8);
  mpz_class b = bnd2mpz(arr, arr + 8);
  EXPECT_EQ(a, b);
}

TEST(TlsTest, DiffieHellman) {
  DiffieHellman alice, bob;
  mpz_class alice_public_key = alice.y;
  mpz_class bob_public_key = bob.y;
  mpz_class alice_shared_secret = alice.setPeerPublicKey(bob_public_key);
  mpz_class bob_shared_secret = bob.setPeerPublicKey(alice_public_key);
  EXPECT_EQ(alice_shared_secret, bob_shared_secret);
}