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

#if 0
// more simple
int 
IsSymmetric(int **A, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			if (A[i][j] != A[j][i])
				return -1;
		}
	return 0;
}
#endif

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


// convert two dimention array to one dimention array

// rows
int* 
SymmetricToArray(int **A, int  size)
{
	int *B = NULL;
	B = (int*)malloc(sizeof(int)*size*(size+1)/2);
	
	for (int i = 0; i < size; i++)
		for (int j = 0; j <= i; j++) {
			B[i*(i+1)/2+j] = A[i][j];
		}
	return B;
}

#if 0
// columns
int* 
SymmetricToArray(int **A, int  size)
{
	int *B = NULL;
	B = (int*)malloc(sizeof(int)*size*(size+1)/2);
	
	for (int j = 0; j < size; j++)
		for (int i = 0; i <= j; i++) {
			B[j*(j+1)/2+i] = A[i][j];
		}
	return B;
}
#endif

int* 
LowerTriangularToArray(int **A, int size)
{
	int *B = NULL;
	B = (int*)malloc(sizeof(int)*size*(size+1)/2);
	
	for (int i = 0; i < size; i++)
		for (int j = 0; j <= i; j++) {
			B[i*(i+1)/2+j] = A[i][j];
		}
	return B;
}

int* 
UpperTriangularToArray(int **A, int size)
{
	int *B = NULL;
	B = (int*)malloc(sizeof(int)*size*(size+1)/2);
	
	for (int j = 0; j < size; j++)
		for (int i = 0; i <= j; i++) {
			B[j*(j+1)/2+i] = A[i][j];
		}
	return B;
}

int* 
DiagonalToArray(int **A, int size)
{
	int *B = NULL;
	B = (int*)malloc(sizeof(int)*size);
	
	for (int i = 0; i < size; i++)
			B[i] = A[i][i];
		
	return B;
}

int**
matrix_add(int **A, int **B, int rows, int cols)
{
	int **C = NULL;
	C = (int**)malloc(sizeof(int*)*rows);
	for (int i = 0; i < rows; i++)
		C[i] = (int*)malloc(sizeof(int)*cols);


	for (int i = 0; i <  rows; i++)
		for (int j = 0; j < cols; j++) 
			C[i][j] = A[i][j] + B[i][j];
			

	return C;
}

int**
matrix_sub(int **A, int **B, int rows, int cols)
{
	int **C = NULL;
	C = (int**)malloc(sizeof(int*)*rows);
	for (int i = 0; i < rows; i++)
		C[i] = (int*)malloc(sizeof(int)*cols);


	for (int i = 0; i <  rows; i++)
		for (int j = 0; j < cols; j++) 
			C[i][j] = A[i][j] - B[i][j];
			

	return C;
}


int**
matrix_scal_mul(int **A, int rows, int cols, int scal)
{
	int **C = NULL;
	C = (int**)malloc(sizeof(int*)*rows);
	for (int i = 0; i < rows; i++)
		C[i] = (int*)malloc(sizeof(int)*cols);


	for (int i = 0; i <  rows; i++)
		for (int j = 0; j < cols; j++) 
			C[i][j] = scal*A[i][j];
			

	return C;
}

// A is mxn, B is nxp
// C is mxp
int**
matrix_mul(int **A, int **B, int m, int n, int p)
{
	int **C = NULL;
	int sum = 0; 
	C = (int**)malloc(sizeof(int*)*m);
	for (int i = 0; i < m; i++)
		C[i] = (int*)malloc(sizeof(int)*p);


	for (int i = 0; i <  m; i++)
		for (int j = 0; j < p; j++) {
			for (int ii = 0; ii < n; ii++)
				sum += A[i][ii]*B[ii][j];
			C[i][j] = sum;
		}
			

	return C;
}

int**
matrix_trans(int **A, int rows, int cols)
{
	int **C = NULL;
	C = (int**)malloc(sizeof(int*)*cols);
	for (int i = 0; i < cols; i++)
		C[i] = (int*)malloc(sizeof(int)*rows);


	for (int i = 0; i < cols; i++)
		for (int j = 0; j < rows; j++) 
			C[i][j] = A[j][i];
			

	return C;
}

// next is about the sparse matrix
// max non-zero element
#define SMAX 16
typedef int Datatype;
typedef struct {
int i, j;
Datatype v;
} Node;

typedef struct {
int m, n, t;
Node data[SMAX];
} Spmatrix;

void
Insert(Spmatrix *M, int i, int j, Datatype v)
{
	for(int m = 0; m < SMAX; m++)
		if (M->data[m].v == 0) {
			//printf("%d	%d\n", i, j);
			M->data[m].i = i;
			M->data[m].j = j;
			M->data[m].v = v;
			break;
		}
}

#define ROWS 4
#define COLUMNS 5

void 
InitSpmatrix(int A[ROWS][COLUMNS], Spmatrix *M)
{
	M->m = ROWS;
	M->n = COLUMNS;
	int t = 0;
	
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLUMNS; j++)
			if (A[i][j] != 0)
				t += 1;
	M->t = t;

	for (int i = 0; i < SMAX; i++) {
		M->data[i].i = -1;
		M->data[i].j = -1;
		M->data[i].v = 0;
	}
	

	

	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLUMNS; j++)
			if (A[i][j] != 0) {
				//printf("%d	%d\n", i, j);
				Insert(M, i, j, A[i][j]);
			}
	//for(int m = 0; m < SMAX; m++)
		//printf("%d	%d	%d\n", M->data[m].i, M->data[m].j, M->data[m].v);
	
}

void 
PrintSpmatrix(Spmatrix M)
{
	for(int m = 0; m < SMAX; m++)
		if (M.data[m].v != 0) {
			printf("%d	%d	%d\n", M.data[m].i, M.data[m].j, M.data[m].v);
		}
}

void 
PrintSpmatrix1(Spmatrix *M)
{
	#if 0
	for(int m = 0; m < SMAX; m++)
		if (M->data[m].v != 0) {
			printf("%d	%d	%d\n", M->data[m].i, M->data[m].j, M->data[m].v);
		}
	#endif

	// fast
	for(int m = 0; m < M->t; m++)
		printf("%d	%d	%d\n", M->data[m].i, M->data[m].j, M->data[m].v);
		
}

Spmatrix*
TransMat(Spmatrix *M)
{
	Spmatrix *N;
	N = (Spmatrix*)malloc(sizeof(Spmatrix));
	N->m = M->m;
	N->n = M->n;
	N->t = M->t;
	for (int m = 0; m <  SMAX; m++) {
		N->data[m].i = M->data[m].j;
		N->data[m].j = M->data[m].i;
		N->data[m].v = M->data[m].v;
	}
	return N;
}

Spmatrix*
TransMat1(Spmatrix *M)
{
	Spmatrix *N;
	N = (Spmatrix*)malloc(sizeof(Spmatrix));
	N->m = M->m;
	N->n = M->n;
	N->t = M->t;
	int num = 0;

	for (int i = 0; i < M->n; i++)
		for (int j = 0; j < M->t; j++)
			if (M->data[j].j == i) {
				N->data[num].i = M->data[j].j;
				N->data[num].j = M->data[j].i;
				N->data[num].v = M->data[j].v;
				num++;
			}
	
	return N;
}
		
int main()
{
	
	Spmatrix *M;
	M = (Spmatrix*)malloc(sizeof(Spmatrix));
	int A[ROWS][COLUMNS] = {{0, 5, 0, 0, 8}, {1, 0, 3, 0, 0}, {0, -2, 0, 0, 0}, {6, 0, 0, 0, 0}};
	InitSpmatrix(A, M);
	
	PrintSpmatrix1(M);
	printf("\n");
	PrintSpmatrix1(TransMat(M));
	printf("\n");
	PrintSpmatrix1(TransMat1(M));
	return 0;
}
