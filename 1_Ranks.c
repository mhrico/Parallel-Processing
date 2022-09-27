#include<stdio.h>
#include<mpi.h>

// MPI likes working with references. So instead of directly accessing variables, put & infront of them

int main(int argc, char** argv)
{
    MPI_Init(&argc, &argv); // Call this if you want to do MPI stuff

    int myRank, worldSize; // Gonna store process rank in myRank, and total processes in worldSize

    MPI_Comm_size(MPI_COMM_WORLD, &worldSize); // This gets total processes and stores it in worldSize. Here COMM_WORLD is the default communicator
    MPI_Comm_rank(MPI_COMM_WORLD, &myRank); // Gets rank and puts it in myRank. You want to use both of this functions in your programs.

    printf("Process rank: %d; Total processes: %d\n", myRank, worldSize);

    MPI_Finalize(); // Call this when you are doing doing MPI stuff or bad things will happen to ur OS
}
