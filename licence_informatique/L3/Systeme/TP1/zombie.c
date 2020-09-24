#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char ** argv){
	if (fork() == (pid_t) 0){
		printf("fin du fils de %d\n", getpid());
		sleep(30);
		exit(0);
	}
	sleep(30);
	printf("le pere se reveille et stoppe %d\n", getpid());
	return 0;
}
