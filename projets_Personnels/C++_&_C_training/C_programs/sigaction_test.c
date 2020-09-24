//http://www-inf.telecom-sudparis.eu/COURS/CSC4103/Public/EnLigne/Cours/C9/1.2.html

#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <signal.h> 
#include <sys/types.h> 


struct sigaction s;


/* Function to call upon signal reception */ 
void signal_handler(int signo) { 
  printf("Received: signal %d\n", signo); 
} 
void signal_handler3(int signo){
    printf("AGAIN");
        s.sa_handler = SIG_DFL;
        sigaction(SIGFPE, &s, NULL);

}
void signal_handler2(int signo) { 
    static int i = 0;
    if (i == 0){
        i++;
        printf("Received signal 1\n"); 
    }
    else {
        s.sa_handler = signal_handler3;
    }
} 
 
int main(int argc, char**argv) { 
  if(argc != 2) { 
    fprintf(stderr, "usage: %s signo\n", argv[0]); 
    return EXIT_FAILURE; 
  } 
 
    int a = 12;
    int b = 0;
    int c;
    
    int signo = atoi(argv[1]); 
    
    s.sa_handler = signal_handler2;
    s.sa_flags = 0;
    int retval = sigaction(signo, &s, NULL); 
    if(retval<0) { 
        perror("sigaction failed"); 
        abort(); 
    }

    c = a/b;
    c = a/b;
    c = a/b;
  /* Initialize the sigaction structure */ 
  /*
  int signo = atoi(argv[1]); 
  struct sigaction s; 
  s.sa_handler = signal_handler; 
 /*
  /* Install the signal handler */ /*
  printf("Installing signal handler for signal %d\n", signo); 
  int retval = sigaction(signo, &s, NULL); 
  if(retval<0) { 
    perror("sigaction failed"); 
    abort(); 
  } 
 /*
  /* Wait to receive signals */ /*
  while(1) { 
    printf("[%d] Sleeping...\n", getpid()); 
    sleep(1); 
  } 
 */
  return EXIT_SUCCESS; 
}