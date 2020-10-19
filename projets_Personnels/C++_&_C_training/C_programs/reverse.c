#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

double V(int);
double U(int);

void reverse(char *s1){
    if (s1 == NULL || *s1 == 0) return; //NULL string or empty string
    //char * fin = s1 + strlen(s1) -1;
    char * debut = s1;
    char * fin = s1;
    while (*fin != '\0'){
        fin++;
    }
    fin--;

    char t;
    while (debut < fin){
        t = *debut;
        *debut = *fin;
        *fin = t;
        debut++;
        fin--;
    }

}


void reverse2(char *s)
{
  char *end,temp;
  end = s;
  while(*end != '\0'){
    end++;
  }
  end--;  //end points to last letter now
  for(;s<end;s++,end--){
    temp = *end;
    *end = *s;
    *s = temp; 
  }
}

/*
char * reverse3(char * str){
  char * s1 = malloc (sizeof(char) * strlen(str));
  s1[strlen(str)] = '\0';
  char * fin = str;

  while(*fin != '\0'){
    fin++;
  }
  fin--;
  for (int i = strlen(str)-1; i > 0; i--){
    s1[i] = *fin;
    fin--;
  } 
  return s1;
}
*/

void bubbleSort(int * arr, int size){
  for (int i = 0; i < size-1; i++){
    if (arr[i] > arr[i+1]){
      int temp = arr[i];
      arr[i] = arr[i+1];
      arr[i+1] = temp;
      i = -1;
      }
  }
}



int main(void){

  
    char s1[] = "Hello";
    const char * s2 = "coups"; //read only
    char * s3 = "Hi"; //read only too
    char * s4 = malloc (sizeof(char) * 4);
    s4[0] = 'A';s4[1] = 'B';s4[2] = 'C';s4[3] = '\0';

    printf("s1 : %s ", s1);
    reverse(s1);
    printf("new char : %s\n", s1);

    
    //-----------------------
    //printf("%s\n", s2);
    //printf("%s\n", s3);
    //printf("%s\n", s4);
    //-----------NOT WORKING-------------
    //s4 = reverse3(s4);
    //printf("%s\n", s4);

    /*BUBBLE SORT*/
    /*
    int arr[] = {4,5,1,2,8,7};
    for (int i = 0; i < 6; i++){
      printf("%d ", arr[i]);
    }
    printf("\n");
    bubbleSort(arr, 6);
    for (int i = 0; i < 6; i++){
      printf("%d ", arr[i]);
    }
    printf("\n");
*/

    //printf("%d", fibo(19));
    //return 0;
}
