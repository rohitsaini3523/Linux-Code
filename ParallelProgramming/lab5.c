#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv)
{

    MPI_Init(&argc, &argv); // Initialization of MPI Parallelism
    int myrank, sum, min, max;
    int arr[] = {1, 2, 3, 4};
    int x;
    int i = 0;
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank); // communication between the cores

    MPI_Scatter(arr, 1, MPI_INT, &x, 1, MPI_INT, 0, MPI_COMM_WORLD); // MPI Scatter function for scattering the data to ranks
    for (i = 0; i < 4; i++)
    {
        if (myrank == i)
        {
            printf("Value on scattered %d core is %d\n", myrank, x);
        }
    }
    MPI_Reduce(&x, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD); // MPI Reduction function for sum
    if (myrank == 0)
    {
        printf("Sum=%d on the core=%d\n", sum, myrank);
    }
    MPI_Finalize(); // Termination of the MPI Parallelism
    return 0;
}