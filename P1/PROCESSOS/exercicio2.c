#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argv, char** argc){
	pid_t pid = getpid();
	for(int i = 0; i < 4; i++){
		if(pid != 0){
			pid = fork();
			if(pid != 0){
				printf("Processo pai %d criou %d!!!\n",getpid(),pid);
			}
		}
	}
	if(pid == 0){
			printf("Processo filho %d!!!\n",getpid());
	}
	while(1){

	}
	return 0;
}