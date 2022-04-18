//	Name: Rohit Saini	Panel: F2
//	ERP: 1032200897    	Rollno : 20



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>

int main(void)
{
	int MAX;
	printf("\nEnter Size of Matrix: ");
	scanf("%d", &MAX);
	int count = 1;
	int i, j, k;
	int a[MAX][MAX];
	int b[MAX][MAX];
	int c[MAX][MAX];
	int c_p[MAX][MAX];

	for (i = 0; i < MAX; i++)
		for (j = 0; j < MAX; j++)
		{
			a[i][j] = count;
			b[i][j] = count;
			c[i][j] = 0;
			c_p[i][j] = 0;
			count++;
		}

	/* printf("\nMatrix A:");
	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	} */
	/* printf("\nMatrix B:");
	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			printf("%d ",b[i][j]);
		} 
		printf("\n");
	} */
	double start = omp_get_wtime();
	printf("\nSerial Multiplication of Matrix: \n");
	for (i = 0; i < MAX; i++)
		for (j = 0; j < MAX; j++)
			for (k = 0; k < MAX; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
	double stop = omp_get_wtime();
	/* for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			printf("%d ", c[i][j]);
			printf(" ");
		}
		printf("\n");
	} */
	printf("\nSerial Time: %f\n", stop - start);
	sleep(2);
	double start_p = omp_get_wtime();
#pragma omp parallel for private(i, j, k)
	for (i = 0; i < MAX; i++)
		for (j = 0; j < MAX; j++)
			for (k = 0; k < MAX; k++)
			{
				c_p[i][j] += a[i][k] * b[k][j];
			}
	double stop_p = omp_get_wtime();
	printf("\nParallel Multiplication of Matrix: \n");
	/* for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			printf("%d ", c_p[i][j]);
			printf(" ");
		}
		printf("\n");
	} */
	printf("\nParallel Time : %f\n", stop_p - start_p);
	return 0;
}
