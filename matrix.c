#include <stdio.h>
#include <stdlib.h>

// 0 means is identity matrix
int
IsIdentity(int **A, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			if ((i != j) && (A[i][j]) != 0)
				return -1;
			if ((i == j) && (A[i][j] != 1))
				return -1;
		}

	return 0;
}

int 
IsScalar(int **A, int size)
{
	int tmp = A[0][0];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			if ((i != j) && (A[i][j]) != 0)
				return -1;
			if ((i == j) && (A[i][j] != A[0][0]))
				return -1;
		}

	return 0;
}

int 
IsDiagonal(int **A, int size)
{
	//int tmp = A[0][0];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			if ((i != j) && (A[i][j]) != 0)
				return -1;
		}

	return 0;
}
 
int 
IsUpperTriangular(int **A, int size)
{
	//int tmp = A[0][0];
	for (int i = 0; i < size; i++)
		for (int j = (i+1); j < size; j++) {
			if (A[i][j] != 0)
				return -1;
		}

	return 0;
}

int 
IsLowerTriangular(int **A, int size)
{
	//int tmp = A[0][0];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < i; j++) {
			if (A[i][j] != 0)
				return -1;
		}

	return 0;
}

int 
IsSymmetric(int **A, int size)
{
	//int tmp = A[0][0];
	int **B = NULL;
	B = (int**)malloc(sizeof(int*)*size);
	for (int i = 0; i < size; i++)
		B[i] = (int*)malloc(sizeof(int)*size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			B[i][j] = A[j][i];
		}

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			if (B[i][j] != A[j][i])
				return -1;
		}
	return 0;
}

int 
IsSkewSymmetric(int **A, int size)
{
	//int tmp = A[0][0];
	int **B = NULL;
	B = (int**)malloc(sizeof(int*)*size);
	for (int i = 0; i < size; i++)
		B[i] = (int*)malloc(sizeof(int)*size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			B[i][j] = -A[j][i];
		}

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			if (B[i][j] != A[j][i])
				return -1;
		}
	return 0;
}
int main()
{
	return 0;
}
