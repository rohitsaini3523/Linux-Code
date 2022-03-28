#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(void)
{
    printf("\nHello world using Single ProcessorCore");
    #pragma omp parallel
    {
        printf("\nHello World using Multicore with Thread id: %d",omp_get_thread_num());
    }
    printf("\n");
    return 0;
}