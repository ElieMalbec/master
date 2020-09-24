#include <unistd.h>

int main(void){

	fork();
	fork();
	fork();
	fork();
	fork();
	fork();
	sleep(300);
	return 0;
}
