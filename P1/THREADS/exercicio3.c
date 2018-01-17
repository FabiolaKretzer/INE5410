#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

#define MAX_THREADS 128
int contador_global = 0;

void *func_thread() {
	for (int i = 0; i < 100; i++)
		contador_global++;
	pthread_exit(NULL);
}

int main(int argc, char **argv) {
	pthread_t thread[MAX_THREADS];
	for(int i = 0; i < MAX_THREADS; i++){
		pthread_create(&thread[i],	NULL, func_thread, NULL);		
	}
	for(int i = 0; i < MAX_THREADS; i++){
		pthread_join(thread[i], NULL);
	}
	printf("Contador global = %d \n", contador_global);
	return 0;
}