#include <unistd.h>
#include <stdio.h>


int main(void){
	printf("JE SUIS là\n");

	pid_t c = fork();

	if (c == 0){
		printf("Je suis dans le fils\n");
	}
	else if (c > 0){
		printf("Je suis dans le pere\n");
	}
	else {
		printf("Je suis error\n");
	
	}
	return 0;
}
