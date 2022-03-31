#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<omp.h>

 	
int main(void)
{
	long int max;
	printf("Enter Max size: ");
	scanf("%ld",&max);
	int *a = (int*)malloc(max*sizeof(int));
	for(int i =0;i<max;i++)
	{
		a[i] = i;
	}
	int *b = (int*)malloc(max*sizeof(int));
	for(int i =0;i<max;i++)
	{
		b[i] = i;
	}
double start = omp_get_wtime();
int *ans = (int*)malloc(max*sizeof(int));
	for(int i =0;i<max;i++)
	{
		ans[i] = a[i]+b[i];
	}
double stop = omp_get_wtime();
for(int i =0;i<max;i++)
	{
		//printf("%d ",ans_p[i]);
	}	
	printf("Serial Time: %f\n",stop-start);
double start_p = omp_get_wtime();
int *ans_p = (int*)malloc(max*sizeof(int));
int i;	
#pragma omp parallel for private(i)
	for(i =0;i<max;i++)
	{
		ans_p[i] = a[i]+b[i];
	}
double stop_p = omp_get_wtime();
for(i =0;i<max;i++)
	{
		//printf("%d ",ans_p[i]);
	}	
printf("\nParallel Time: %f",stop_p-start_p);
	free(a);
	free(b);
	free(ans);
	free(ans_p);
        return 0;
}
