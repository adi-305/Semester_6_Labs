#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc,char *argv[]){
	int rank,size;
	int number;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Status status;
	if(rank == 0){
		printf("Enter the Number that you want to send : ");
		scanf("%d",&number);
		for(int i =1 ;i<size;i++){
			MPI_Send(&number,1,MPI_INT,i,1,MPI_COMM_WORLD);
		}
		fflush(stdout);
	}
	else{
		MPI_Recv(&number,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
		printf("In Process : %d. Number recieved : %d\n",rank,number);
		fflush(stdout);
	}
	MPI_Finalize();
	return 0;
}
