#include<stdio.h>
#include<mpi.h>


int main(int argc, char** argv)
{
    MPI_Init(&argc, &argv);

    int myRank, worldSize;

    MPI_Comm_size(MPI_COMM_WORLD, &worldSize);
    MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

    if(myRank % 2 == 0) printf("Hello (Process %d out of %d)\n", myRank, worldSize);
    else printf("World (Process %d out of %d)\n", myRank, worldSize);

    MPI_Finalize();
}
