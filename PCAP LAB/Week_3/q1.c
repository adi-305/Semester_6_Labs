#include "mpi.h"
#include <stdio.h>

int factorial(int a){
	if(a==1 || a==0) return 1;
	return a*factorial(a-1);
}

int main(int argc,char *argv[]){
	int rank,size,A[10],c,i,B[10],n,sum = 0;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Status status;

	if(rank == 0){
		n = size;
		fprintf(stdout, "Enter %d values\n",n );
		fflush(stdout);
		for(i =0;i<n;i++) scanf("%d",&A[i]);
		fflush(stdout);
	}
	MPI_Scatter(A,1,MPI_INT,&c,1,MPI_INT,0,MPI_COMM_WORLD);
	fprintf(stdout, "Number %d recieved in process %d\n",c,rank);
	c = factorial(c);

	MPI_Gather(&c,1,MPI_INT,B,1,MPI_INT,0,MPI_COMM_WORLD);
	if(rank == 0){
		fprintf(stdout,"All the numbers gathered in the root\n");
		fflush(stdout);
		for(i =0 ;i<n;i++){
			sum+=B[i];
		}
		fprintf(stdout, "The sum of the factorials is %d\n",sum);
		fflush(stdout);
	}
	MPI_Finalize();
	return 0;
}