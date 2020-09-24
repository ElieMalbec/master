#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void my_handler(int sig){
	//printf("Bonjour");
	if (sig == SIGUSR1){
		printf("BONJOUR\n");
	}
	else if (sig == SIGUSR2){
		printf("BONSOIR\n");
	}
	else {
		printf("Other signal\n");
	}
}

int main(void){
	if (signal(SIGUSR1, my_handler) == SIG_ERR){
		printf("Error\n");
	}
	if (signal(SIGUSR2, my_handler) == SIG_ERR){
		printf("Error\n");
	}
	if (signal(SIGFPE, my_handler) == SIG_ERR){
		printf("Error\n");
	}
	//(void) signal(SIGUSR1, my_handler);
	while (1){
		kill(SIGINT, getpid());
		//(void) signal(SIGUSR2, my_func2);
		sleep(1);
	}
	//printf("j attends");
	//sleep(10); //\n vide le buffer
	//printf(" 10 sec\n");
	return 0;
}
