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
		MPI_Send(&number,1,MPI_INT,1,1,MPI_COMM_WORLD);
		MPI_Recv(&number,1,MPI_INT,size-1,1,MPI_COMM_WORLD,&status);
		printf("In process %d recieved from process %d. Number : %d\n",0,size-1,number);
		fflush(stdout);
	}
	else{
		for(int i =1 ;i<size;i++){
			if(i == size-1){
				MPI_Recv(&number,1,MPI_INT,i-1,1,MPI_COMM_WORLD,&status);
				printf("In process %d recieved from process %d. Number : %d\n",i,i-1,number);
				number += 1;
				MPI_Send(&number,1,MPI_INT,0,1,MPI_COMM_WORLD);
				fflush(stdout);
			}
			if(i == rank){
				MPI_Recv(&number,1,MPI_INT,i-1,1,MPI_COMM_WORLD,&status);
				printf("In process %d recieved from process %d. Number : %d\n",i,i-1,number);
				number += 1;
				MPI_Send(&number,1,MPI_INT,i+1,1,MPI_COMM_WORLD);
				fflush(stdout);
			}
		}
	}
	MPI_Finalize();
	return 0;
}
