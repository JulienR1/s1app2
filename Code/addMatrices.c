#include <stdio.h>

#define HEIGHT 2
#define WIDTH 3

void addMatrice(int mat1[], int mat2[], int matOut[]);
void printMat(int mat[]);

void test();

int main(void)
{
	test();
	return 0;
}

void addMatrice(int mat1[], int mat2[], int matOut[])
{
	for (int i = 0; i < HEIGHT * WIDTH; i++)
	{
		matOut[i] = mat1[i] + mat2[i];
	}
}

void printMat(int mat[])
{
	printf("[");
	for (int i = 0; i < WIDTH * HEIGHT; i++)
	{
		printf("%d", mat[i]);
		if (i < WIDTH * HEIGHT - 1)
		{
			printf(",");
		}
	}
	printf("]");
}

void test()
{
	printf("\n\n-- Tests de la fonction 'addMatrices(int mat1[], int mat2[], int matOut[])' --\n");
	printf("Entrees\t\t\t\tValeur attendue\tValeur obtenue\tTest reussi\n");

	const int addMatTestCount = 4;
	int mat1Inputs[][HEIGHT * WIDTH] = {
		{1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 0},
		{-1, -1, -1, -1, -1, -1}};
	int mat2Inputs[][HEIGHT * WIDTH] = {
		{1, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1}};
	int matOutResult[][HEIGHT * WIDTH] = {
		{2, 2, 2, 2, 2, 2},
		{1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 0}};

	for (int i = 0; i < addMatTestCount; i++)
	{
		int actualResult[WIDTH * HEIGHT];
		addMatrice(mat1Inputs[i], mat2Inputs[i], actualResult);
		char *successState = "OUI";
		for (int j = 0; j < WIDTH * HEIGHT; j++)
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