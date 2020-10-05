#include <stdio.h>

unsigned int factorial(unsigned int n);
double pow(double base, int exponent);
double fmod(double n, double modulo);
double cos(double angle);

void test(double expected, double result);

#define PI 3.14159
#define EPSILON 0.00001

int main(void){
    test(factorial(0), 1);
    test(factorial(1), 1);
    test(factorial(5), 120);
    puts("");

    test(pow(2,2), 4);
    test(pow(0.5,2), 0.25);
    test(pow(2,-2), 0.25);
    test(pow(0,2), 0);
    test(pow(2,0), 1);
    puts("");

    test(fmod(10,3.33), 0.003);
    test(fmod(10,PI), 0.18);
    test(fmod(10,-PI), -0.18);
    puts("");

    test(cos(0), 1);
    test(cos(PI), -1);
    test(cos(PI / 2.0), 0);
    test(cos(3*PI/2.0), 0);
    test(cos(7*PI), -1);
    test(cos(PI/6.0), 0.866);
    test(cos(PI/3.0), 0.5);
    test(cos(651), -0.771);

    return 0;
}

unsigned int factorial(unsigned int n){
    unsigned int result = 1;
    for(; n > 1; n--){
        result *= n;
    }
    return result;
}

double pow(double base, int exponent){
    if(exponent < 0){
        exponent = -exponent;
        base = 1 / base;
    }

    double result = 1;
    for(int i = 0; i < exponent; i++){
        result *= base;
    }

    return result;
}

double fmod(double n, double modulo){
    return n / modulo - (int)(n / modulo);
}

double cos(double angle){
    angle = fmod(angle, 2 * PI) * 2 * PI;

    int iteration = 0;
    double result = 0, previousResult = 0;
    do {
        previousResult = result;
        result += pow(-1, iteration) * pow(angle, 2 * iteration) / factorial(2 * iteration);
        iteration++;
    } while(result - previousResult < EPSILON && result - previousResult > -EPSILON);
    
    return result;
}

void test(double expected, double result){
    printf("%.4f\t\t%.4f\t\t%s\n", expected, result, expected == result ? "OK" : "FAIL");
}