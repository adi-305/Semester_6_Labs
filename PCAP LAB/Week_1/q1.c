#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int pow(int a,int b){
	int ans = 1;
	for(int i = 0;i<b;i++){
		ans*=a;
	}
	return ans;
}


int main(int argc,char *argv[]){
	int rank,size;
	int x =  atoi(argv[1]);
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	int ans = pow(x,rank);
	printf("My rank is %d and the power calculated is: %d\n",rank,ans);
	MPI_Finalize();
	return 0;
}