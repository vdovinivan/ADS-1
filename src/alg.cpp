// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    int a, k, i;
    k = 0;
    a = value;
    for (i = 1; i <= a; i++) {
        if (a % i == 0) k = k + 1;
    }
    if (k != 2)
        return false;
    else
        return true;
}

uint64_t nPrime(uint64_t n) {
    int count = 0;
    int current = 0;
    for (int i = 2; i < 10000000; i++) {
        if (checkPrime(i) == true) {
            count++;
            if (count == n) {
                current = i;
                break;
            }
        }
    }
    return current;
}

uint64_t nextPrime(uint64_t value) {
    while (1) {
        int c = 0;
        value++;
        if (!checkPrime(value)) {
            c++;
        }
        if (c == 0) {
            return value;
            break;
        }
    }
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 5;
    for (int i = 2; i < hbound; i++) {
        if (i % 2 == 0) {
            continue;
        }
        if (i % 3 == 0) {
            continue;
        }
        if (checkPrime(i)) {
            sum = sum + i;
        }
    }
    return sum;
}
