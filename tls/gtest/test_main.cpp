#include "mpz_utility.hpp"
#include <gtest/gtest.h>

TEST(HelloTest, mpz) {
  uint8_t arr[8];
  mpz_class a {"0x1234567890abcdef"};
  mpz2bnd(a, arr, arr + 8);
  mpz_class b = bnd2mpz(arr, arr + 8);
  EXPECT_EQ(a, b);
}