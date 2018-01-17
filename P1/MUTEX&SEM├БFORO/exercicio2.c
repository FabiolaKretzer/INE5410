#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

#define MAX_THREADS 10

int contador_global = 0;
sem_t sem;

void *thread (void *arg) {
  int i;

  for(i=0; i<100; i++) {
    sem_wait(&sem);
    contador_global++;
    sem_post (&sem);
  }
  return NULL;
}

int main(int argc, char **argv) {
  int i;
  pthread_t threads[MAX_THREADS];
  sem_init (&sem, 0, 1);

  for(i=0; i<MAX_THREADS; i++)
    pthread_create(&threads[i], NULL, thread, NULL);

  for(i=0; i<MAX_THREADS; i++)
    pthread_join(threads[i], NULL);

  sem_destroy(&sem);

  printf("Valor do contador global = %d\n", contador_global);

  return 0;
}
