#include <stdlib.h>
#include <stdio.h>

int main(){
	int **arr;
	arr = malloc(sizeof (int *) *5*6);
	for (int i = 0; i < 5; i++){
		arr[i] = malloc(sizeof(int) * 6);
	}
	for (int i = 0; i < 5; i++){
		for (int j = 0 ; j < 6; j++){
			arr[i][j] = i;
		}
	}
	for (int i = 0; i < 5; i++){
		for (int j = 0 ; j < 6; j++){
			printf("%d ", arr[i][j]);
		}
	}

	printf("\n");
	int const SIZE = 15;
	arr[2] = realloc(arr[2], SIZE);
	for (int i = 0; i < 10; i++){
		arr[2][i] = 9;
	}
	for (int i = 0; i < SIZE; i++){
			printf("%d ", arr[2][i]);
	}


	int t1[3] = { 1, 2, 3 };
	int *p1 = &t1[0];
	int t2[4][3] = {{1,2,3}, {4,5,6}, {7,8,9}, {10,11,12}};
	int **p2 = &p1;
	int *t3[3] = { &t1[1], &t2[0][0], &t2[1][2] };
	int (*p3)[3] = &t2[3];
	return 0;
}
//typedef string char *;