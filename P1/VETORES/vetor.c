#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]){
	srand(time(NULL));
	int* A;
	int* B;
	int* C;
	int n;
	if(argc > 1){
		n = atoi(argv[1]);
	}
	else{
		n = 5;
	}
	A =(int *) malloc(n * sizeof (int));
	B =(int *) malloc(n * sizeof (int));
	C =(int *) malloc(n * sizeof (int));
	for(int i=0; i < n; i++){ 
		A[i]= rand()%10; 
		B[i]= rand()%10;
		printf("%d %d",A[i], B[i]);
	}
multiplica_vetores(A, B, C, n);
return 0;
}
int multiplica_vetores(int* A, int* B, int* C, int n){
	for(int i=0; i < n; i++){ 
		C[i] = A[i] * B[i];
		printf("%d ",A[i] * B[i]);

	}
return 0;
}

