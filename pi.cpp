/* Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/ */

#include "calc.h"

// Function to get string representation of first n digits
// of the Pi. The function will be exposed to JavaScript.
extern "C" size_t get_pi(char* buf, size_t n) {
    bignum pi;
    calc_pi(pi);
    if (n < 3) return 0;
    buf[0] = '0' + pi.digits[0];
    buf[1] = '.';
    size_t size = n < pi.size ? n : pi.size;
    for (size_t i = 2; i < size; i++) {
      buf[i] = '0' + pi.digits[i - 1];
    }
    return size;
}
