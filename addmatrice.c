#include <stdio.h>

#define matrixHeight 2
#define matrixWidht  3


int addmatrice(int intmat1,int mat2,int matout);


int main(void) 
{


int mat1 [matrixHeight*matrixWidht];
int mat2 [matrixHeight*matrixWidht];
int matOut [matrixHeight*matrixWidht];


	for(int i = 0; i < matrixHeight*matrixWidht; i++)
	{
		 matOut[i] = mat1[i] + mat2[i];
	}
	return 0;
	
}

