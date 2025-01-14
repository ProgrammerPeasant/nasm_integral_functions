// here are some tests and stuff around
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <getopt.h>
#include "../src/integral.h"

extern double _f4(double x);
extern double _f5(double x);
extern double _f6(double x);

extern double _f4d(double x);
extern double _f5d(double x);
extern double _f6d(double x);

int main(void)
{
    double rng1, rng2, rng3, a, b;
    double eps1 = 0.00001;
    rng1 = root(_f5, _f6, _f5d, _f6d, -1.0, 0.0, eps1);
    // double res = integral(_f4, -2.0, rng1, eps1) - integral(_f5, -2.0, rng1, eps1) - integral(_f6, -1.0, rng1, eps1);
    printf("testing...");
}