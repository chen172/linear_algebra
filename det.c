#include <stdio.h>
#include <stdlib.h>

// find determinant of square matrix 
// normal approach

int det(int **A, int size)
{
	int i;
	int sum = 0;
	int **tmp;
	
	if (size == 2)
		sum = A[0][0]*A[1][1] - A[0][1]*A[1][0];
	else {
	for (i = 0; i < size; i++) {
		
		tmp = (int**)malloc(sizeof(int*)*(size-1));
		for (int m = 0; m < (size-1); m++)
			tmp[m] = (int*)malloc(sizeof(int)*(size-1));
		for(int j = 0; j < (size-1); j++)
			for(int k = 0; k < (size-1); k++) {
				if (k < i)
					tmp[j][k] = A[j+1][k];
				else
					tmp[j][k] = A[j+1][k+1];
			}
		
		if ((i%2) == 1)
			sum += A[0][i]*det(tmp, (size-1))*(-1);
		else
			sum += A[0][i]*det(tmp, (size-1));
		free(tmp);
	}
	}
	return sum;
}

// properties 3
int predet(int **A, int size)
{
	float tmp = 0;
	int m = 0;
	
	for (int i = 0; i < size; i++)
		for(int j = (i+1); j < size; j++) {
			m = 0;
			
			if (A[0][i] == 0)
				tmp = 0;
			else
				tmp = (float)A[m][j]/(float)A[m][i];
			
			while ((m<size) && ((A[m][i]*tmp) == (float)A[m][j])) {
				
				m++;
			}
			
			if (m == size)
				return 0;
		}
	
	return -1;
}
			
			

//The determinant can be characterized by the following three key properties.

//1.det(I) = 1, where I is an identity matrix
//2.
//3.
/* The determinant is alternating: whenever two
columns of a matrix are identical, its determinant is 0. */




// using Gauss Elimination 
// first convert given square matrix to upper triangular matrix
float
g_det(int **A, int size)
{
	float **B = NULL;
	float factor = 0;
	float sum = 1;
	int m = 0;
	float tmp;

	
	B = (float**)malloc(sizeof(float*)*size);
	for (int i = 0; i < size; i++)
		B[i] = malloc(sizeof(float)*size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			B[i][j] = (float)A[i][j];

	for (m = 0; m < (size-1); m++) {
	for (int i = (size-1); i > m; i--) {
		#if 0
		for (int ii = 0; ii < size; ii++) {
		for (int jj = 0; jj < size; jj++)
			printf("%f	", B[ii][jj]);
		printf("\n");
		}
		printf("\n");
		#endif
		if (B[m][m] == 0) {
			for(int n = 0; n < size; n++) {
				tmp = B[m+1][n];
				B[m+1][n] = B[m][n];
				B[m][n] = tmp;
			}
			sum = sum*(-1);
		}
			
		factor = (float)B[i][m]/(float)B[m][m];
		//printf("factor is %f, %d, %d\n", factor, i, m);
		
		
		for (int j = 0; j < size; j++)
			B[i][j] = (float)B[i][j]-(float)B[m][j]*factor;
	}
	}
	//for (int j = 0; j < size; j++)
	//	B[0][j] = (float)A[0][j];

	for (int i = 0; i < size; i++)
		sum *= B[i][i];

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			printf("%f	", B[i][j]);
		printf("\n");
	}

	free(B);
	return sum;
}
#define N 4
int main()
{
	#if 1
	//int A[N][N] = {2,2,2,2};
	int **A = NULL;
	
	A = (int**)malloc(sizeof(int*)*N);
	for (int i = 0; i < N; i++)
		A[i] = (int*)malloc(sizeof(int)*N);
	#endif
	//int B[N][N] = {{1,0,2,-1},{3,0,0,5},{2,1,4,-3},{1,0,5,0}};
	//int B[N][N] = {{1,3,2,1},{0,0,1,0},{2,0,4,5},{-1,5,-3,0}};
	//int B[N][N] = {{6,1,1},{4,-2,5},{2,8,7}};

	// test for properties 3
	int B[N][N] = {{1,1,2,10},{3,0,0,5},{2,2,4,-2},{1,4,8,0}};
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			A[i][j] = B[i][j];
			//printf("%d %d, %d\n", i,j,A[i][j]);
		}
	
	
	int sum = 0;
	float sum1 = 0;
	
	// properties 3
	if (predet(A, N) == 0) {
		printf("two columns of a matrix are identical\n");
		sum = 0;
	}
	else {
		sum = det(A, N);
		sum1 = g_det(A, N);
	}
	printf("det is %d, gauss elimination is %f\n", sum, sum1);
	// properties 1
	if (sum == 1)
		printf("this is an identity matrix\n");
	free(A);
	return 0;
}
