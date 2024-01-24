#include "mpi.h"
#include <stdio.h>


int main(int argc,char *argv[]){
	int i,rank,size;
	float A[100],C[100],B[100],n,sum = 0,m,t;
	float average;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Status status;

	if(rank == 0){
		n = size;
		fprintf(stdout,"Enter the integer M");
		fflush(stdout);
		scanf("%f",&m);
		fprintf(stdout, "Enter %f values\n",n*m );
		fflush(stdout);
		for(i =0;i<n*m;i++) scanf("%f",&A[i]);
		fflush(stdout);
	}
	MPI_Bcast(&m,1,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Scatter(A,m,MPI_INT,C,m,MPI_INT,0,MPI_COMM_WORLD);
	//fprintf(stdout, "Number %d recieved in process %d\n",c,rank);
	//c = factorial(c);
	for(i = 0;i<m;i++) sum+=C[i];
	average =  sum/m;
	MPI_Gather(&average,1,MPI_INT,B,1,MPI_INT,0,MPI_COMM_WORLD);
	if(rank == 0){
		fprintf(stdout,"All the numbers gathered in the root\n");
		fflush(stdout);
		float sum = 0;
		fprintf(stdout,"All the numbers :\n");
		fflush(stdout);
		for(i =0 ;i<m*n;i++){
			fprintf(stdout, "%f\t",A[i]);
		}
		fprintf(stdout,"\n");
		fflush(stdout);
		for (int i = 0; i < n; ++i)
		{
			sum+=B[i];
		}
		fprintf(stdout, "The total average is %f\n",sum/n);
		fflush(stdout);
	}
	MPI_Finalize();
	return 0;
}