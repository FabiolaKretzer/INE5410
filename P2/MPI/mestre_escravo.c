#include <stdio.h>
#include <mpi.h>

#define N 100

int main(int argc, char** argv){
  int size, rank;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  if (rank == 0){
    char palavra = '@';
    int filho;
    MPI_Status status;
    for (int i = 1; i < size; i++) {
      MPI_Send(&palavra, 1, MPI_CHAR, i, 0, MPI_COMM_WORLD);
    }
    for (int i = 1; i < size; i++) {
      MPI_Recv(&filho, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      printf("O processo %d imprime filho %d!!!\n", rank, filho);
    }
  } else {

    char palavraFilho;
    MPI_Status status;
    MPI_Recv(&palavraFilho,	1, MPI_CHAR, 0, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("O processo %d recebe palavvra %c!!!\n", rank, palavraFilho );
    MPI_Send(&rank, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
  }
  MPI_Finalize();
  return 0;
}
