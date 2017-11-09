#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sighandler(int signo){
  if (signo == SIGINT) {
    printf("Help! I've been interrupted :(\n");
    exit(1);
  }
  if (signo == SIGUSR1) {
    printf("Parent process id: %d\n", getppid());
  }
}

int main() {
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);

  while(1) {
    printf("My PID is: %d\n", getpid());
    sleep(1);
  }

  return 0;
}
