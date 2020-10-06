#include <stdio.h>

double factorial(unsigned int n);
long double fpow(double base, int exponent);
double fmod(double n, double modulo);
long double fsin(double angle);

void test();

#define PI 3.14159
#define ITERATION_COUNT 10

int main(void)
{
    test();
    return 0;
}

double factorial(unsigned int n)
{
    double result = 1;
    for (; n > 1; n--)
    {
        result *= n;
    }
    return result;
}

long double fpow(double base, int exponent)
{
    if (exponent < 0)
    {
        exponent = -exponent;
        base = 1 / base;
    }

    long double result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }

    return result;
}

double fmod(double n, double modulo)
{
    return n / modulo - (int)(n / modulo);
}

long double fsin(double angle)
{
    angle = fmod(angle, 2 * PI) * 2 * PI;

    int iteration = 0;
    long double result = 0;
    do
    {
        result += fpow(-1, iteration) * fpow(angle, 2 * iteration + 1) / factorial(2 * iteration + 1);
        iteration++;
    } while (iteration < ITERATION_COUNT);
    return result;
}

void test()
{
    // Factorial
    printf("\n\n-- Tests de la fonction 'factorial(int n)' --\n");
    printf("Entrees\tValeur attendue\tValeur obtenue\tTest reussi\n");

    int factorialTestCount = 3;
    int factorialInputs[] = {0, 1, 5};
    int factorialResults[] = {1, 1, 120};

    for (int i = 0; i < factorialTestCount; i++)
    {
        int actualResult = factorial(factorialInputs[i]);
        char *successState = factorialResults[i] == actualResult ? "OUI" : "NON";
        printf("%d\t%d\t\t%d\t\t%s\n", factorialInputs[i], factorialResults[i], actualResult, successState);
    }

    printf("\n");

    // Power
    printf("\n\n-- Tests de la fonction 'pow(double base, int exponent)' --\n");
    printf("Entrees\t\tValeur attendue\tValeur obtenue\tTest reussi\n");

    int powTestCount = 5;
    double powBaseInputs[] = {2, 0.5, 2, 0, 2};
    int powExponentInputs[] = {2, 2, -2, 2, 0};
    double powResults[] = {4, 0.25, 0.25, 0, 1};

    for (int i = 0; i < powTestCount; i++)
    {
        double actualResult = fpow(powBaseInputs[i], powExponentInputs[i]);
        char *successState = powResults[i] == actualResult ? "OUI" : "NON";
        printf("%.3f, %d\t%.3f\t\t%.3f\t\t%s\n", powBaseInputs[i], powExponentInputs[i], powResults[i], actualResult, successState);
    }

    printf("\n");

    // decimal modulus
    printf("\n\n-- Tests de la fonction 'fmod(double n, double modulo)' --\n");
    printf("Entrees\t\tValeur attendue\t\tValeur obtenue\tTest reussi\n");

    int fmodTestCount = 3;
    double nInputs[] = {10, 10, 10};
    double moduloInputs[] = {3.33, PI, -PI};
    double fmodResults[] = {0.003, 0.1831, -0.1831};

    for (int i = 0; i < fmodTestCount; i++)
    {
        double actualResult = fmod(nInputs[i], moduloInputs[i]);
        char *successState = actualResult - fmodResults[i] < 0.0001 ? "OUI" : "NON";
        printf("%.4f, %.4f\t\t%.4f\t\t%.4f\t\t%s\n", nInputs[i], moduloInputs[i], fmodResults[i], actualResult, successState);
    }

    printf("\n");

    // sin
    printf("\n\n-- Tests de la fonction 'sin(double angle)' --\n");
    printf("Entrees\t\tValeur attendue\tValeur obtenue\tTest reussi\n");

    int sinTestCount = 8;
    double sinInputs[] = {0.0, PI, PI / 2.0, 3 * PI / 2.0, 7 * PI / 2.0, PI / 6.0, PI / 3.0, 651.0};
    double sinResults[] = {0, 0, 1, -1, -1, 0.5, 0.866, -0.6367};

    for (int i = 0; i < sinTestCount; i++)
    {
        double actualResult = fsin(sinInputs[i]);
        char *successState = (sinResults[i] - actualResult < 0.0001) ? "OUI" : "NON";
        printf("%.4f\t\t%.4f\t\t%.4f\t\t%s\n", sinInputs[i], sinResults[i], actualResult, successState);
    }
}