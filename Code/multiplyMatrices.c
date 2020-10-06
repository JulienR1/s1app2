#include <stdio.h>

#define SIZE 3

void multiplyMatrices(int mat1[], int mat2[], int matOut[]);
void printMat(int mat[]);

void test();

int main(void)
{
    test();
    return 0;
}

void multiplyMatrices(int mat1[], int mat2[], int matOut[])
{
    for (int i = 0; i < SIZE * SIZE; i++)
    {
        for (int n = 0; n < SIZE; n++)
        {
            matOut[i] += mat1[n + (int)(i / SIZE) * SIZE] * mat2[SIZE * n + i % SIZE];
        }
    }
}

void printMat(int mat[])
{
    printf("[");
    for (int i = 0; i < SIZE * SIZE; i++)
    {
        printf("%d", mat[i]);
        if (i < SIZE * SIZE - 1)
        {
            printf(",");
        }
    }
    printf("]");
}

void test()
{
    printf("\n\n-- Tests de la fonction 'multiplyMatrices(int mat1[], int mat2[], int matOut[])' --\n");
    printf("Entrees\t\t\t\t\t\tValeur attendue\t\tValeur obtenue\t\tTest reussi\n");

    const int multiplyMatTestCount = 4;
    int mat1Inputs[][SIZE * SIZE] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 5, 6, 7, 8, 9}};
    int mat2Inputs[][SIZE * SIZE] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 1, 0, 0, 0, 1},
        {0, 0, 1, 0, 1, 0, 1, 0, 0},
        {-1, 0, 0, 0, -1, 0, 0, 0, -1}};
    int matOutResult[][SIZE * SIZE] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {3, 2, 1, 6, 5, 4, 9, 8, 7},
        {-1, -2, -3, -4, -5, -6, -7, -8, -9}};

    for (int i = 0; i < multiplyMatTestCount; i++)
    {
        int actualResult[SIZE * SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        multiplyMatrices(mat1Inputs[i], mat2Inputs[i], actualResult);
        char *successState = "OUI";
        for (int j = 0; j < SIZE * SIZE; j++)
        {
            if (matOutResult[i][j] != actualResult[j])
            {
                successState = "NON";
            }
        }
        printMat(mat1Inputs[i]);
        printf(", ");
        printMat(mat2Inputs[i]);
        printf("\t");
        printMat(matOutResult[i]);
        printf("\t");
        printMat(actualResult);
        printf("\t%s\n", successState);
    }
}