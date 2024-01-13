#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc,char *argv[]){
	int rank,size,a;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	int number[size];
	int rec_number;
	MPI_Status status;
	if(rank == 0){
		for(int i = 0;i<size;i++){
			printf("Enter the number %d ",i+1);
			scanf("%d",&number[i]);
		}

		int buffer_size = size * sizeof(int) + MPI_BSEND_OVERHEAD;
		void *buffer = malloc(buffer_size);
		MPI_Buffer_attach(&buffer,buffer_size);
		for(int i =1 ;i<size;i++){
			MPI_Bsend(&number[i],1,MPI_INT,i,1,MPI_COMM_WORLD);
		}
		MPI_Buffer_detach(buffer,&buffer_size);
		printf("In process %d. Number recieved : %d Square: %d\n",rank,number[0],number[0]*number[0]);
		fflush(stdout);
	}
	else{
		MPI_Recv(&rec_number,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
		if(rank % 2 == 0){
			printf("In process %d. Number recieved : %d Square: %d\n",rank,rec_number,rec_number*rec_number);
		}
		else{
			printf("In process %d. Number recieved : %d Cube: %d\n",rank,rec_number,rec_number*rec_number*rec_number);
		}
		fflush(stdout);
	}
	MPI_Finalize();
	return 0;
}
