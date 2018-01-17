#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

#define MAX_THREADS 100

void *func_thread() {
	printf("Nova thread criada,TD = %lu \n", pthread_self());
	pthread_exit(NULL);	
	return 0;
}

int main(int argc, char **argv) {
	pthread_t thread[MAX_THREADS];
	for(int i = 0; i < MAX_THREADS; i++)
		pthread_create(&thread[i],	NULL, func_thread, NULL);

	for(int i = 0; i < MAX_THREADS; i++)
		pthread_join(thread[i], NULL);	
	pthread_exit(NULL);
	return 0;
}