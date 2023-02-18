#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "../helpers/helpers.h"

int SIZE = 100;

void count_sort(int arr[], int size);

int main(){
    // initialize random seed to generate unique values each run.
    srand(time(NULL));

    // generate random array with length and max value of SIZE
    int arr[SIZE];
    generate_rand_arr(arr, SIZE, SIZE);

    // view the unsorted array
    print_arr(arr, SIZE);

    // sort and view sorted array
    count_sort(arr, SIZE);
    print_arr(arr, SIZE);
}

void count_sort(int arr[], int size){
    int output[SIZE];

    // Get the largest element of the array
    int max = get_max(arr, size);

    // Initialize count array with all zeros.
    int count[1000];
    for(int i = 0; i <= max; ++i)
        count[i] = 0;

    // Store the count of each element
    for(int i=0; i<size; i++)
        count[arr[i]]++;

    // Store the cummulative count of each array
    for (int i = 1; i <= max; i++) 
        count[i] += count[i - 1];

    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements into original array
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
  
}

