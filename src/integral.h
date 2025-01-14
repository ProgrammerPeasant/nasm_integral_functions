#ifndef INTEGRAL_H
#define INTEGRAL_H

typedef double afunc(double);

// Function prototypes for external functions that need to be defined elsewhere
extern double _f1(double x);
extern double _f2(double x);
extern double _f3(double x);

extern double _f1d(double x);
extern double _f2d(double x);
extern double _f3d(double x);

// Function to get the function pointer based on the function ID
afunc *get_func(unsigned func_id);
afunc *get_funcd(unsigned func_id);

// Function to find the root of the equation f(x) = g(x) using Newton's method
double root(afunc *f, afunc *g, afunc *df, afunc *dg, double a, double b, double eps1);

// Function to calculate the integral of a function f from a to b using the trapezoidal rule
double trapezoidal_rule(afunc f, double a, double b, int n);

// Function to calculate the integral of a function f from a to b with a specified accuracy using the Runge rule
double integral(afunc f, double a, double b, double eps2);

#endif // INTEGRAL_H