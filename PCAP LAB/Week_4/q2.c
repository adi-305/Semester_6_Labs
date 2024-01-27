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

float func(float a){
    return 4/(1 + (a*a));
}

int main(int argc, char *argv[]) {
    int rank, size;
    float answer,sum;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Errhandler errhandler;
    MPI_Comm_create_errhandler(my_error_handler, &errhandler);
    MPI_Comm_set_errhandler(MPI_COMM_WORLD, errhandler);
    
    for(float i = rank;i <rank+1;i+=0.0001){
        sum+=func(i);
    }
    sum/=10000;
    MPI_Reduce(&sum,&answer,1,MPI_FLOAT,MPI_SUM,0,MPI_COMM_WORLD);
    if (rank == 0) {
            printf("Value of pi is %f\n", answer);
    } 
    MPI_Finalize();
    return 0;
}
