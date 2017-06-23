/* Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/ */

#include "bignum.h"

typedef BigDecNum<1020> bignum;

void arctan(bignum& n, unsigned inverse_x);
void calc_pi(bignum& n);

