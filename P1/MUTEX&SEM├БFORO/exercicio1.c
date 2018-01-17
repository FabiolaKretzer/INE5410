#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_THREADS 10

int contador_global = 0;
pthread_mutex_t mutex;

void *thread (void *arg) {
  int i;

  for(i=0; i<100; i++) {
    pthread_mutex_lock(&mutex);
    //int tmp = contador_global;
    //tmp++;
    //if (i==0)
      //sleep(0.1);
    //contador_global = tmp;
    contador_global++;
    pthread_mutex_unlock(&mutex);
    }
  return NULL;
}

int main(int argc, char **argv) {
  int i;
  pthread_t threads[MAX_THREADS];
  pthread_mutex_init(&mutex,NULL);

  for(i=0; i<MAX_THREADS; i++)
    pthread_create(&threads[i], NULL, thread, NULL);

  for(i=0; i<MAX_THREADS; i++)
    pthread_join(threads[i], NULL);

  pthread_mutex_destroy(&mutex);

  printf("Valor do contador global = %d\n", contador_global);

  return 0;
}
