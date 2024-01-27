#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

void my_error_handler(MPI_Comm *comm, int *err, ...) {
    char error_string[MPI_MAX_ERROR_STRING];
    int length_of_error_string, error_class;

    MPI_Error_class(*err, &error_class);
    MPI_Error_string(*err, error_string, &length_of_error_string);
    printf("MPI Error: %s\n", error_string);
    MPI_Abort(MPI_COMM_WORLD, *err);
}

int main(int argc, char *argv[]) {
    int rank, size,fact = 1,factsum,i;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Errhandler errhandler;
    MPI_Comm_create_errhandler(my_error_handler, &errhandler);
    MPI_Comm_set_errhandler(MPI_COMM_WORLD, errhandler);
    
    // for(int i = rank;i <rank+1;i+=0.01){
    //     sum+=func(i);
    // }
    MPI_Bcast(&fact,1,MPI_INT,4,MPI_COMM_WORLD);
    for(i = 1;i < rank + 1;i++){
        fact*=i;
    }
    MPI_Scan(&fact,&factsum,1,MPI_INT,MPI_SUM,MPI_COMM_WORLD);
    if (rank == size-1) {
            printf("Factorial is %d\n", factsum);
    } 
    MPI_Finalize();
    return 0;
}
