#include <stdio.h>

#define SIZE 3

void multiplyMatrices(int mat1[], int mat2[], int matOut[]);
void printMat(int mat[]);

int main(void){
    
    int matOut[SIZE * SIZE] = {0,0,0,0,0,0,0,0,0};
    int mat1[SIZE * SIZE] = {1,2,3,4,5,6,7,8,9};
    int mat2[SIZE * SIZE] = {-1,0,0,0,-1,0,0,0,-1};
    multiplyMatrices(mat1, mat2, matOut);
    printMat(matOut);

    return 0;
}

void multiplyMatrices(int mat1[], int mat2[], int matOut[]){
    for(int i = 0; i < SIZE * SIZE; i++){
        for(int n = 0; n < SIZE; n++){
            matOut[i] += mat1[n + (int)(i / SIZE) * SIZE] * mat2[SIZE * n + i % SIZE];
        }
    }
}

void printMat(int mat[]){
    printf("[");
    for(int i = 0; i < SIZE * SIZE; i++){
        printf("%d", mat[i]);
        if(i < SIZE * SIZE - 1){
            printf(",");
        }
    }
    printf("]");
}