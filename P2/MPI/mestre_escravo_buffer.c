#include <stdio.h>
#include <mpi.h>

#define N 100

int main(int argc, char** argv){
  int size, rank;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  if (rank == 0){
    int buffer[N];
    for (int i = 0; i < N; i++){
      buffer[i] = i;
    }
    int filho;
    MPI_Status status;
    int i;
    for (i = 1; i < size; i++) {
      MPI_Send(&buffer[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
    }

    for (; i < N; i++) {
      MPI_Recv(&filho, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
      printf("O processo %d imprime filho %d!!!\n", rank, filho);
      MPI_Send(&buffer[i], 1, MPI_INT, status.MPI_SOURCE, 0, MPI_COMM_WORLD);
    }

    //finalização
    int fim = -1;
    for (i = 1; i < size; i++) {
      MPI_Send(&fim, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
    }

  } else {
    int elemento;
    MPI_Status status;
    while(1) {
      MPI_Recv(&elemento,	1, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

      //criterio de parada
      if(elemento == -1)
        break;

      int mult = elemento*rank;
      printf("O processo %d multiplica %d!!!\n", rank, mult );
      MPI_Send(&mult, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
  }
  MPI_Finalize();
  return 0;
}
