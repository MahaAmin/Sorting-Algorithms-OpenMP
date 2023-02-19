#include<stdio.h>
#include<time.h>
#include "../helpers/helpers.h"

int SIZE = 10;

void selection_sort(int arr[], int size);
clock_t t;
double cpu_time_used; 

int main(){
    // generate random array with length and max value of SIZE
    int arr[SIZE];
    generate_rand_arr(arr, SIZE, SIZE);

    // view the unsorted array
    print_arr(arr, SIZE);

    // mesaure consumed time
    t = clock();
    // sort and view sorted array
    selection_sort(arr, SIZE);
    t = clock() - t;

    print_arr(arr, SIZE);
    cpu_time_used = ((double)t)/CLOCKS_PER_SEC;
    printf("Serial selection sort time = %f seconds.\n", cpu_time_used);
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
