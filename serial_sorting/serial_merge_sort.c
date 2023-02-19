#include<stdio.h>
#include<time.h>
#include "../helpers/helpers.h"

int SIZE = 10;
clock_t t;
double cpu_time_used; 

void serial_merge_sort(int arr[], int low, int high);   
void merge(int arr[], int low, int middle, int high);

int main(){
    // generate random array with length and max value of SIZE
    int arr[SIZE];
    generate_rand_arr(arr, SIZE, SIZE);

    // view the unsorted array
    print_arr(arr, SIZE);

    // mesaure consumed time
    t = clock();
    // sort array 
    serial_merge_sort(arr, 0, SIZE-1);
    t = clock() - t;
    
    // view sorted array
    print_arr(arr, SIZE);

    cpu_time_used = ((double)t)/CLOCKS_PER_SEC;
    printf("Serial merge sort time = %f seconds.\n", cpu_time_used);
}


void serial_merge_sort(int arr[], int low, int high){
    if(low < high){
        int middle = low + (high - low) / 2;

        serial_merge_sort(arr, low, middle);
        serial_merge_sort(arr, middle + 1, high);

        merge(arr, low, middle, high);
    }
}

void merge(int arr[], int low, int middle, int high){
    int i, j, k;
    int n1 = middle - low + 1;
    int n2 = high - middle;

    // create temp arrays
    int left[n1], right[n2];

    // copy data to temp arrays left[] and right[]
    for(i=0; i<n1; i++)
        left[i] = arr[low+i];
    for(j=0; j<n2; j++)
        right[j] = arr[middle+1+j];

    // merge temp arrays back to arr[]
    i=0; j=0; k=low;
    while(i<n1 && j<n2){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = left[i];
        i++; k++;
    }

    while(j<n2){
        arr[k] = right[j];
        j++; k++;
    }
}

