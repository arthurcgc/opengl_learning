#include "matriz.h"


double* vetcria (int n)
{
	double *vec = (double*)malloc(sizeof(double)*n);
	return vec;
}

void vetlibera (double* v)
{
	free(v);
}

void printvec(double *vec,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("v[%d] = %f\n", i,vec[i]);
	}
}

void printmat(int m, int n, double **mat)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("mat[%d][%d] = %f\t",i,j,mat[i][j]);
			if(j==n-1)
			{
				printf("\n");
			}
		}
	}

}

double escalar (int n, double* v, double* w)
{
	int i;
	double sum, temp = 0;
	for (i=0;i<n;i++)
	{
		temp = v[i]*w[i];
		sum += temp;
	}
	return sum;
}

double norma2 (int n, double* v)
{
	int i;
	double sum = 0;

	for(i=0;i<n;i++)
	{
		sum += v[i]*v[i];
	}

	return sqrt(sum);
}

double** matcria (int m, int n)
{
	int i;
	double **mat = (double **)malloc(m * sizeof(double*));
    	for (i=0; i<m; i++)
         	mat[i] = vetcria(n);
	return mat;
}

void matlibera (int m, double** A)
{
	int i;
	for(i=0;i<m;i++)
	{
		vetlibera(A[i]);
	}
}

void transposta (int m, int n, double** A, double** T)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			T[i][j] = A[j][i];
	}
}

void multmv (int m, int n, double** A, double* v, double* w)
{
	return;
}

void multmm (int m, int n, int q, double** A, double** B, double** C)
{
	int i,j,k;
	double sum = 0;

	for(i=0;i<m;i++) // no meu caso m = n ou seja m = 3 linhas!
	{
		sum = 0;
		for(j=0;j<q;j++)
		{
			for(k=0;k<n;k++) // k < ncolunas
			{
				sum += A[i][k] * B[k][j];
			}
			C[i][j] = sum;
			sum = 0;
		}
	}

}
