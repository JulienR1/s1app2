#include <stdio.h>

#define HEIGHT 2
#define WIDTH  3

void addMatrice(int mat1[], int mat2[], int matOut[]);
void printMat(int mat[]);

int main(void) 
{
	int mat1[HEIGHT * WIDTH] = {1,1,1,1,1,1};
	int mat2[HEIGHT * WIDTH] = {-1,-1,-1,-1,-1,-1};
	int matOut[HEIGHT * WIDTH];

	addMatrice(mat1, mat2, matOut);
	printMat(matOut);

	return 0;
}

void addMatrice(int mat1[], int mat2[], int matOut[]){
	for(int i = 0; i < HEIGHT * WIDTH; i++)
	{
		 matOut[i] = mat1[i] + mat2[i];
	}
}

void printMat(int mat[]){
    printf("[");
    for(int i = 0; i < WIDTH * HEIGHT; i++){
        printf("%d", mat[i]);
        if(i < WIDTH * HEIGHT - 1){
            printf(",");
        }
    }
    printf("]");
}