#include<stdio.h>
#include "../helpers/helpers.h"

int SIZE = 10;

void selection_sort(int arr[], int size);

int main(){
    // generate random array with length and max value of SIZE
    int arr[SIZE];
    generate_rand_arr(arr, SIZE, SIZE);

    // view the unsorted array
    print_arr(arr, SIZE);

    // sort and view sorted array
    selection_sort(arr, SIZE);
    print_arr(arr, SIZE);
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
