#include <gmp.h>
#include <gmpxx.h>

#include <fmt/core.h>

int main() {
    mpz_class a("11111");
    mpz_class b("99999");
    mpz_class c;

    c = a + b;
    fmt::print("sum: {}\n", c.get_str());

    return 0;
}
