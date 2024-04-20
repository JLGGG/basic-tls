#include "diffie_hellman.hpp"
#include <gtest/gtest.h>

class TestTls : public ::testing::Test {
protected:
  void SetUp() override {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  void TearDown() override {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }
};

TEST_F(TestTls, mpz) {
  uint8_t arr[8];
  mpz_class a {"0x1234567890abcdef"};
  mpz2bnd(a, arr, arr + 8);
  mpz_class b = bnd2mpz(arr, arr + 8);
  EXPECT_EQ(a, b);
}

TEST_F(TestTls, DiffieHellman) {
  DiffieHellman alice, bob;
  mpz_class alice_public_key = alice.y;
  mpz_class bob_public_key = bob.y;
  mpz_class alice_shared_secret = alice.setPeerPublicKey(bob_public_key);
  mpz_class bob_shared_secret = bob.setPeerPublicKey(alice_public_key);
  EXPECT_EQ(alice_shared_secret, bob_shared_secret);
}

TEST_F(TestTls, ECDHE) {

}