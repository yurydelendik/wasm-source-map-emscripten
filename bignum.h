/* Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/ */

#include <cstdlib>
#include <cstring>

// Some simple implementation of big number operations
template <size_t n>
class BigDecNum {
  public:
    static const size_t size = n;
    const unsigned base = 10;
    unsigned char digits[n];

    BigDecNum() { zero(); }
    void zero() { memset(digits, 0, n); }
    BigDecNum& operator*=(unsigned x) {
        unsigned c = 0;
        for (size_t i = n; i --> 0;) {
            c += digits[i] * x;
            digits[i] = c % base;
            c /= base;
        }
        return *this;
    }
    BigDecNum& operator/=(unsigned x) {
        unsigned c = 0;
        for (size_t i = 0; i < n; i++) {
            c = c * base + digits[i];
            digits[i] = c / x;
            c %= x;
        }
        return *this;
    }
    BigDecNum& operator+=(const BigDecNum& other) {
        unsigned c = 0;
        for (size_t i = n; i --> 0;) {
            c += digits[i] + other.digits[i];
            digits[i] = c % base;
            c /= base;
        }
        return *this;
    }
    BigDecNum& operator-=(const BigDecNum& other) {
        unsigned c = 0;
        for (size_t i = n; i -->0;) {
            c += other.digits[i];
            if (c > digits[i]) {
              digits[i] = base + digits[i] - c;
              c = 1;
            } else {
              digits[i] -= c;
              c = 0;
            }
        }
        return *this;
    }
    BigDecNum& operator=(const BigDecNum& other) {
        memmove(digits, other.digits, n);
        return *this;
    }
};

