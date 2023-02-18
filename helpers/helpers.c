#include<stdio.h>
#include<stdlib.h>

void generate_rand_arr(int arr[], int size, int max){
    for(int i=0; i<size; i++)
        arr[i] = rand()%max;
}

void print_arr(int arr[], int size){
    printf("[");
    for(int i=0; i<size; i++)
        printf("%d, ", arr[i]);
    printf("]\n");
}

void swap(int *xp, int *yp){
    int tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}