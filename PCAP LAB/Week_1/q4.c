#include "mpi.h"
#include <stdio.h>
#include <string.h> 


char* toggle(int n,char *s){
	char c = s[n];
	int a = c;
	char* ans;
	strcpy(ans,s);
	if(a > 96) ans[n] = c-32;
	else ans[n] = c+32;
	return ans;
}

int main(int argc,char *argv[]){
	int rank,size;
	int len = strlen(argv[1]);
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	if(rank > len){
		printf("Process rank(%d) is greater than the length of the string\n",rank);
	}
	else{
		char *ans  = toggle(rank,argv[1]);
		printf("%s\n",ans);
	}
	MPI_Finalize();
	return 0;
}