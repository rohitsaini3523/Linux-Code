#include<stdio.h>
#include<mpi.h>

int main(int argc , char **argv)
{
    int rank;
    int size;
    MPI_Init(&argc, &argv); //Intitialize
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if(rank == 0)
        printf("That's all For Now!\n");
    else
        printf("Hello World! from rank: %d out of %d\n", rank, size);
    MPI_Finalize(); //Exit Mode
}