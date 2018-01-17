#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

#define MAX_THREADS 10
sem_t cheio, vazio, lock_prod, lock_cons;
int i,f;
int buffer;

void *produtor (void *arg) {
  sem_wait(vazio);
  sem_wait(lock_prod);
  f = (f + 1)% MAX_THREADS;
  buffer[f] = rand();
  sem_post(lock_prod);
  sem_post(cheio);
}
void *consumidor (void *arg) {
  sem_wait(cheio);
  sem_wait(lock_cons);
  i = (i + 1)% MAX_THREADS;
  printf(buffer[i]);
  //buffer[i] = rand();
  sem_post(lock_cons);
  sem_post(vazio);
}
int main(int argc, char **argv) {
  int i;
  pthread_t threads[MAX_THREADS];
  sem_init (&cheio, 0, 1);
  sem_init (&vazio, 0, MAX_THREADS);
  sem_init (&lock_prod, 0, 1);
  sem_init (&lock_cons, 0, 1);

  for(i=0; i<MAX_THREADS; i++)
    pthread_create(&threads[i], NULL, thread, NULL);

  for(i=0; i<MAX_THREADS; i++)
    pthread_join(threads[i], NULL);

  sem_destroy(&cheio);
  sem_destroy(&vazio);
  sem_destroy(&lock_prod);
  sem_destroy(&lock_cons);

  //printf("Valor do contador global = %d\n", contador_global);

  return 0;
}
