#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <getopt.h>
#include "src/integral.h"

extern unsigned int iterations;

void print_help()
{
    printf("Usage: ./integral [options]\n");
    printf("Options:\n");
    printf("  --help, -h            Show this help message\n");
    printf("  --root, -r            Print the roots of the equations\n");
    printf("  --iterations, -i      Print the number of iterations needed\n");
    printf("  --test-root, -R arg   Test the root function with parameters F1:F2:A:B:E:R\n");
    printf("  --test-integral, -I arg Test the integral function with parameters F:A:B:E:R\n");
}

int main(int argc, char *argv[])
{
    double rng1, rng2, rng3, a, b;
    double eps1 = 0.00001;
    rng1 = root(_f1, _f2, _f1d, _f2d, 0.0, 2.0, eps1);
    rng2 = root(_f1, _f3, _f1d, _f3d, -2.0, 0.0, eps1);
    rng3 = root(_f2, _f3, _f2d, _f3d, 0.0, 1.0, eps1);
    double res = integral(_f1, rng2, rng1, eps1) - integral(_f3, rng2, rng3, eps1) - integral(_f2, rng3, rng1, eps1);
    int opt;
    int option_index = 0;
    static struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"root", no_argument, 0, 'r'},
        {"iterations", no_argument, 0, 'i'},
        {"test-root", required_argument, 0, 'R'},
        {"test-integral", required_argument, 0, 'I'},
        {0, 0, 0, 0}};
    while ((opt = getopt_long(argc, argv, "hriR:I:", long_options, &option_index)) != -1)
    {
        switch (opt)
        {
        case 'h':
            print_help();
            return 0;
        case 'r':
            rng1 = root(_f1, _f2, _f1d, _f2d, 0.0, 2.0, eps1);
            rng2 = root(_f1, _f3, _f1d, _f3d, -2.0, 0.0, eps1);
            rng3 = root(_f2, _f3, _f2d, _f3d, 0.0, 1.0, eps1);
            printf("%f %f %f\n", rng1, rng2, rng3); // Значения корней
            return 0;
        case 'i':
            printf("%u\n", iterations);
            return 0;
        case 'R':
        {
            unsigned int F1, F2;
            double correct_root;
            sscanf(optarg, "%d:%d:%lf:%lf:%lf:%lf", &F1, &F2, &a, &b, &eps1, &correct_root);
            double result = root(get_func(F1), get_func(F2), get_funcd(F1), get_funcd(F2), a, b, eps1);
            double abs_error = fabs(result - correct_root);
            double rel_error = fabs(abs_error / correct_root);
            printf("%f %f %f\n", result, abs_error, rel_error);
            return 0;
        }
        case 'I':
        {
            int F;
            double eps2, correct_integral;
            sscanf(optarg, "%d:%lf:%lf:%lf:%lf", &F, &a, &b, &eps2, &correct_integral);
            double result = integral(get_func(F), a, b, eps2);
            double abs_error = fabs(result - correct_integral);
            double rel_error = fabs(abs_error / correct_integral);
            printf("%f %f %f\n", result, abs_error, rel_error);
            return 0;
        }
        default:
            printf("Wrong command");
            print_help();
            return 0;
        }
    }
    printf("%f\n", res);

    return 0;
}