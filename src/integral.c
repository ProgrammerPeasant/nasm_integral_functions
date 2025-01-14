#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef double afunc(double);
extern double _f1(double x);
extern double _f2(double x);
extern double _f3(double x);

extern double _f1d(double x);
extern double _f2d(double x);
extern double _f3d(double x);

static afunc *get_func(unsigned func_id)
{
    switch (func_id)
    {
    case 1:
        return _f1;
    case 2:
        return _f2;
    case 3:
        return _f3;
    default:
        return NULL;
    }
}
static afunc *get_funcd(unsigned func_id)
{
    switch (func_id)
    {
    case 1:
        return _f1d;
    case 2:
        return _f2d;
    case 3:
        return _f3d;
    default:
        return NULL;
    }
}

double root(afunc *f, afunc *g, afunc *df, afunc *dg, double a, double b, double eps1)
{
    double x0, x1, fx, gx, dfx, dgx;

    // Начальное приближение
    x0 = (a + b) / 2;

    do
    {
        fx = f(x0);
        gx = g(x0);
        dfx = df(x0);
        dgx = dg(x0);

        // Проверка деления на ноль
        if (fabs(dfx - dgx) < eps1)
        {
            printf("Error.\n");
            return NAN;
        }

        // Итерационная формула метода Ньютона
        x1 = x0 - (fx - gx) / (dfx - dgx);

        // Проверка на выход за пределы отрезка [a, b]
        if (x1 < a || x1 > b)
        {
            printf("Значение вышло за пределы отрезка.\n");
            return NAN; // Возвращаем NAN, чтобы указать на ошибку
        }

        // Проверка условия окончания итераций
        if (fabs(x1 - x0) < eps1)
        {
            return x1; // Возвращаем найденный корень
        }

        x0 = x1; // Обновляем приближение
    } while (fabs(f(x0) - g(x0)) > eps1);

    return x0;
}

double trapezoidal_rule(afunc f, double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; i++)
    {
        sum += f(a + i * h);
    }
    return sum * h;
}
unsigned int iterations = 0;
// Функция для вычисления интеграла с использованием правила Рунге
double integral(afunc f, double a, double b, double eps2)
{
    int n = 1; // Начальное число разбиений
    double I1, I2;
    I1 = trapezoidal_rule(f, a, b, n);
    iterations++; // Первоначальное приближение
    do
    {
        n *= 2;
        I2 = trapezoidal_rule(f, a, b, n); // Удвоение числа разбиений
        iterations++;
        // Проверка условия Рунге
        if (fabs(I2 - I1) / 3.0 < eps2)
        {
            return I2;
        }
        I1 = I2;
    } while (1);
}

int main(void) {}