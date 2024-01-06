#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
	int rank;
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	switch(rank){
		case 0:
			printf("%d + %d = %d\n",a,b,a+b);
			break;
		case 1:
			printf("%d - %d = %d\n",a,b,a-b);
			break;
		case 2:
			printf("%d / %d = %d\n",a,b,a/b);
			break;
		case 3:
			printf("%d * %d = %d\n",a,b,a*b);
			break;
		default:
			printf("Rank is out of range\n");
	}
	MPI_Finalize();
	return 0;
}
