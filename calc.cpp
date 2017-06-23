/* Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/ */

#include "calc.h"

// Compute the arctangents using the power series:
//   arctan(x) = x - x^3/3 + x^5/5 - x^7/7 + ...
void arctan(bignum& n, unsigned inverse_x)
{
    bignum i, t;
    i.digits[0] = 1;
    i /= inverse_x;
    n = i; 
    unsigned inverse_x2 = inverse_x * inverse_x;
    unsigned j = 3;
    bool neg = true;
    size_t k = 0;
    for (;;) {
       while (k < bignum::size && !i.digits[k]) k++;
       if (k >= bignum::size) break;
       i /= inverse_x2;
       t = i;
       t /= j;
       j += 2;
       if (neg)
           n -= t;
       else
           n += t;
       neg = !neg;
    }
}

// Calulate Pi using Machin's formula:
//    Pi = 16 * arctan(1/5) - 4 * arctan(1/239)
void calc_pi(bignum& n)
{
  bignum a1;
  arctan(a1, 5);
  a1 *= 16;
  bignum a2;
  arctan(a2, 239);
  a2 *= 4;
  a1 -= a2;
  n = a1;
}
