// ##### TO-DO ##### //
// 1- [DONE] Generate random unsorted array.
// 2- [DONE] Print array function.
// 3- [DONE] Implement "Selection Sort" function.
// 4- [DONE] Implement swap() function.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int SIZE = 100000;
void generate_rand_arr(int arr[], int size, int max);
void print_arr(int arr[], int size);
void selection_sort(int arr[], int size);
void swap(int *x, int *y);

int main(){

    // initialize random seed to generate unique values each run.
    srand(time(NULL));
    int arr[SIZE];
    generate_rand_arr(arr, SIZE, SIZE);
    //print_arr(arr, SIZE);
    selection_sort(arr, SIZE);
    //print_arr(arr, SIZE);
}


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

void selection_sort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        int min_index = i;
        for(int j=i+1; j<size; j++)
            if(arr[j]<arr[min_index])
                min_index=j;
            if(min_index != i)
                swap(&arr[i], &arr[min_index]);
    }
}

void swap(int *xp, int *yp){
    int tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}