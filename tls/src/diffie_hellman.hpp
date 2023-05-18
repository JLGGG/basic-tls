#pragma once

#include "mpz_utility.hpp"

struct DiffieHellman {
    mpz_class setPeerPublicKey(mpz_class public_key) {
        k = powm(public_key, private_key, prime);
        return k;
    }
    
    // I used the already known prime number from RFC 7919
    mpz_class prime {"0xFFFFFFFFFFFFFFFFADF85458A2BB4A9AAFDC5620273D3CF1D8B9C583\
    CE2D3695A9E13641146433FBCC939DCE249B3EF97D2FE363630C75D8F681B202AEC4617AD3DF\
    1ED5D5FD65612433F51F5F066ED0856365553DED1AF3B557135E7F57C935984F0C70E0E68B77\
    E2A689DAF3EFE8721DF158A136ADE73530ACCA4F483A797ABC0AB182B324FB61D108A94BB2C8\
    E3FBB96ADAB760D7F4681D4F42A3DE394DF4AE56EDE76372BB190B07A7C8EE0A6D709E02FCE1\
    CDF7E2ECC03404CD28342F619172FE9CE98583FF8E4F1232EEF28183C3FE3B1B4C6FAD733BB5\
    FCBC2EC22005C58EF1837D1683B2C6F34A26C1B2EFFA886B423861285C97FFFFFFFFFFFFFFFF"};

    mpz_class k, g = 2, private_key = randomPrime(255), y = powm(g, private_key, prime);
};