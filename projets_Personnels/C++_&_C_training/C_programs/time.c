#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
    time_t my_time;
    my_time = time(NULL);

    if (my_time == (time_t) -1){
        return 0;
    }
    printf("%ld & %s\n", my_time, ctime(&my_time));
    printf("First \r last\n");
    return 0;
}