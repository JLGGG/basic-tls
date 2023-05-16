#pragma once
#include <gmpxx.h>
#include <random>

#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>

mpz_class nextPrime(mpz_class n) {
    mpz_class r;
    mpz_nextprime(r.get_mpz_t(), n.get_mpz_t());
    return r;
}

// return base^exp % mod
mpz_class powm(mpz_class base, mpz_class exp, mpz_class mod) {
    mpz_class r;
    if (mod == 0) throw std::invalid_argument("mod cannot be 0");
    mpz_powm(r.get_mpz_t(), base.get_mpz_t(), exp.get_mpz_t(), mod.get_mpz_t());
    return r;
}

// convert mpz to big endian
// 0x100 = 256 (1 0000 0000)
// It write n as a big endian type in the consecutive memory [begin, end)
template<typename It> 
void mpz2bnd(mpz_class n, It begin, It end) {
    for (It i = end; i != begin; n /= 0x100) {
        *--i = mpz_class {n % 0x100}.get_ui();
    }
}

// convert big endian to mpz
// It read the memory structure of the big-endian and returns mpz
template<typename It>
mpz_class bnd2mpz(It begin, It end) {
    std::stringstream ss; ss << "0x";
    for (It i = begin; i != end; i++) {
        ss << std::hex << std::setfill('0') << std::setw(2) << +*i;
    }
    return mpz_class {ss.str()};
}

// It returns the prime number of the byte size
mpz_class randomPrime(unsigned int byte) {
    unsigned char buf[byte];
    // It makes a random number from 0 to 255 a balanced probability
    std::uniform_int_distribution<> dist(0, 0xff);
    std::random_device rd;

    for (unsigned int i = 0; i < byte; i++) {
        buf[i] = dist(rd);
    }

    auto z = nextPrime(bnd2mpz(buf, buf + byte));

    for (unsigned int i = 0; i < byte; i++) {
        buf[i] = 0xff;
    }
    // If the generated number is bigger than the maximum value of the byte size
    if (z > bnd2mpz(buf, buf + byte)) return randomPrime(byte);
    else return z;
}

// It returns the container 'c's contents as a hex string
template<typename C>
std::string hexPrint(const char* prefix, const C& c) {
    std::stringstream ss;
    ss << prefix << " : 0x";
    for (unsigned char i : c) {
        ss << std::hex << std::setfill('0') << std::setw(2) << +i;
    }
    return ss.str();
}