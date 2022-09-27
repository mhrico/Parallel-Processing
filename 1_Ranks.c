#include<stdio.h>
#include<mpi.h>

int main(int argc, char** argv)
{
    MPI_Init(&argc, &argv);

    int myRank, worldSize;

    MPI_Comm_size(MPI_COMM_WORLD, &worldSize);
    MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

    printf("Process rank: %d; Total processes: %d\n", myRank, worldSize);

    MPI_Finalize();
}
