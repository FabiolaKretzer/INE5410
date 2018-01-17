#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char **argv) {
    int i, j;
    pid_t pid, pid2;

    for(i = 0; i < 2; i++) {
     	pid = fork();
      if (pid == 0) { // filho (1o nivel)
          for(j = 0; j < 2; j++) {
              pid2 = fork();
              if (pid2 == 0) break; // filho (2o nivel)
          }
          printf("Processo %d filho de %d.\n", getpid(), getppid());
          break;
      }
    }

    // aguarda o termino de TODOS os filhos
    // o retorno de wait() indica o PID do filho que terminou ou -1 caso o processo não tenha filhos
    while ((pid = wait(NULL)) > 0)
      printf("Processo pai %d: filho %d terminou!\n", getpid(), pid);

    return 0;
}
