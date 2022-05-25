/********************
This Program for Pi calculation depicts the usage of
MPI_Wtime, MPI_Bcast and MPI_Reduce
This exercise presents a simple program to determine the value of pi. The algorithm suggested here is chosen for its simplicity. The method evaluates the integral of 4/(1+x*x) between 0 and 1. The method is simple: the integral is approximated by a sum of n intervals; the approximation to the integral in each interval is (1/n)*4/(1+x*x). The master process (rank 0) asks the user for the number of intervals; the master should then broadcast this number to all of the other processes. Each process then adds up every n'th interval (x = rank/n, rank/n+size/n,...). Finally, the sums computed by each process are added together using a reduction.
*********************/

#include "mpi.h"
#include <math.h>
#include <stdio.h>

#define MAX_NAME 80 /* length of characters for naming a process */
#define MASTER 0    /* rank of the master */

int main(int argc, char *argv[])
{
    int rank,   /* rank variable to identify the process */
        nprocs, /* number of processes */
        i,
        len; /* variable for storing name of processes */

    int n = 1000;                               /* the number of bins */
    double PI25DT = 3.141592653589793238462643; /* 25-digit-PI*/
    double mypi,                                /* value from each process */
        pi,                                     /* value of PI in total*/
        step,                                   /* the step */
        sum,                                    /* sum of area under the curve */
        x;

    char name[MAX_NAME]; /* char array for storing the name of each process */

    double start_time,    /* starting time */
        end_time,         /* ending time */
        computation_time; /* time for computing value of PI */

    /*Initialize MPI execution environment */
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    MPI_Get_processor_name(name, &len);

    start_time = MPI_Wtime();

    /* Broadcast the number of bins to all processes */
    /* This broadcasts an integer which is n, from the master to all processes
     * and
     */

    MPI_Bcast(&n, 1, MPI_INT, MASTER, MPI_COMM_WORLD);

    /* Calculating for each process */
    step = 1.0 / (double)n;
    sum = 0.0;
    for (i = rank + 1; i <= n; i += nprocs)
    {
        x = step * ((double)i - .5);
        sum += (4.0 / (1.0 + x * x));
    }

    mypi = step * sum;

    printf("This is my sum: %.16f from rank: %d name: %s\n", mypi, rank, name);

    /* Now we can reduce all those sums to one value which is Pi */
    MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("Pi is approximately %.16f, Error is %.16f\n", pi, fabs(pi - PI25DT));
        end_time = MPI_Wtime();
        computation_time = end_time - start_time;
        printf("Time of calculating PI is: %f\n", computation_time);
    }
    /* Terminate MPI execution environment */
    MPI_Finalize();
}