#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toggle(int n,char *s){
	for(int i =0 ;i<n;i++){
		if(s[i] > 96) s[i] -= 32;
		else s[i] += 32;
	}
}

int main(int argc,char *argv[]){
	int rank,size;
	char x[100];
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Status status;
	if(rank == 0){
		printf("Enter the string that you want to send : ");
		scanf("%s",x);
		MPI_Ssend(x,strlen(x)+1,MPI_CHAR,1,1,MPI_COMM_WORLD);
		fflush(stdout);
		MPI_Recv(x,30,MPI_CHAR,1,1,MPI_COMM_WORLD,&status);
		printf("%s",x);
	}
	else{
		MPI_Recv(x,30,MPI_CHAR,0,1,MPI_COMM_WORLD,&status);
		size = strlen(x);
		toggle(size,x);
		MPI_Ssend(x,strlen(x)+1,MPI_CHAR,0,1,MPI_COMM_WORLD);
		fflush(stdout);
	}
	MPI_Finalize();
	return 0;
}