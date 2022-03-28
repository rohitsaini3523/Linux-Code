#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main (){

    int sum=0;
    #pragma omp parallel
        for (int i = 0; i < 8; i++)
        {
            int tid = omp_get_thread_num();
            printf("\nPrinting value of i = %d by thread id: %d", i,tid);
            sum++;
        }      
        printf("\nValue if sum is %d\n", sum);

    return 1;
}