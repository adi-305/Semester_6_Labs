#include "mpi.h"
#include <stdio.h>

int isVowel(char c){
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return 1;
	return 0;
}

int main(int argc,char *argv[]){
	int i,rank,size,m,n;
	char A[100],C[100];
	int B[100];
	float average;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Status status;

	if(rank == 0){
		n = size;
		fprintf(stdout,"Enter how many characters to send to each process");
		fflush(stdout);
		scanf("%d",&m);
		fprintf(stdout,"This means you have to enter a string of %d characters\n",m*n);
		fprintf(stdout, "Enter %d values\n",n*m );
		fflush(stdout);
		for(i =0;i<(n*m);i++) scanf(" %c",&A[i]);
		fflush(stdout);
	}
	MPI_Bcast(&m,1,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Scatter(A,m,MPI_CHAR,C,m,MPI_CHAR,0,MPI_COMM_WORLD);
	//fprintf(stdout, "Number %d recieved in process %d\n",c,rank);
	//c = factorial(c);
	int num = 0;
	for(i = 0;i<m;i++){
		if(isVowel(C[i])) num++;
	}
	MPI_Gather(&num,1,MPI_INT,B,1,MPI_INT,0,MPI_COMM_WORLD);
	if(rank == 0){
		fprintf(stdout,"All the numbers gathered in the root\n");
		fflush(stdout);
		int sum = 0;
		A[m*n] ='\0';
		fprintf(stdout,"The string : %s\n",A);
		fflush(stdout);
		fprintf(stdout,"\n");
		fflush(stdout);
		for (int i = 0; i < n; ++i)
		{
			sum+=B[i];
		}
		fprintf(stdout, "The total number of vowels is %d\n",sum);
		fflush(stdout);
	}
	MPI_Finalize();
	return 0;
}