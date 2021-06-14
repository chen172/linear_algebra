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

// using Gauss Elimination 
// first convert given square matrix to upper triangular matrix

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
	int B[N][N] = {{1,0,2,-1},{3,0,0,5},{2,1,4,-3},{1,0,5,0}};
	//int B[N][N] = {{1,3,2,1},{0,0,1,0},{2,0,4,5},{-1,5,-3,0}};
	//int B[N][N] = {{6,1,1},{4,-2,5},{2,8,7}};
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			A[i][j] = B[i][j];
			//printf("%d %d, %d\n", i,j,A[i][j]);
		}
	
	
	int sum = 0;
	
	sum = det(A, N);
	printf("det is %d\n", sum);
	free(A);
	return 0;
}
