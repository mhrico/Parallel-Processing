#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(int argc, char **argv){
    int a, b;
    a = atoi(argv[1]);
    b = atoi(argv[2]);

    MPI_Init(&argc, &argv);
    int rank, world_size;

    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(rank==0) printf("a + b = %d\n", a + b);
    else if(rank==1) printf("a - b = %d\n", a - b);
    else if(rank==2) printf("a * b = %d\n", a * b);
    else if(rank==3) printf("a / b = %d\n", a / b);

    MPI_Finalize();
}
