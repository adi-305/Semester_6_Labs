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
    int rank, size,arr[3][3],element,count=0,answer;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Errhandler errhandler;
    MPI_Comm_create_errhandler(my_error_handler, &errhandler);
    MPI_Comm_set_errhandler(MPI_COMM_WORLD, errhandler);
    if(rank == 0){
        for(int i = 0;i<3;i++){
            printf("For row %d\n",i+1);
            for(int j= 0;j<3;j++){
                printf("Enter element %d\n",j+1 );
                scanf("%d",&arr[i][j]);
            }
        }
        printf("Enter the element you want to find:\n");
        scanf("%d",&element);
    }
    MPI_Bcast(&element,1,MPI_INT,0,MPI_COMM_WORLD);
    MPI_Bcast(&arr,9,MPI_INT,0,MPI_COMM_WORLD);
    for(int i =0;i<3;i++){
        if(arr[rank][i]==element) count++;
    }
    MPI_Reduce(&count,&answer,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
    if (rank == 0) {
            printf("The matrix was \n");
            for(int i = 0;i<3;i++){
                for(int j= 0;j<3;j++){
                    printf("%d\t",arr[i][j]);
                }
                printf("\n");
            }
            printf("The number of times the element was found is %d\n", answer);
    } 
    MPI_Finalize();
    return 0;
}
