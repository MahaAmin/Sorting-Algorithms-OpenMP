#include<stdio.h>
#include<time.h>
#include<omp.h>
#include "../helpers/helpers.h"

int SIZE = 10;
clock_t t;
double cpu_time_used; 

void omp_quick_sort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main(){

    // generate random array with length and max value of SIZE
    int arr[SIZE];
    generate_rand_arr(arr, SIZE, SIZE);

    // view the unsorted array
    print_arr(arr, SIZE);

    // mesaure consumed time
    t = clock();
    // sort array 
    omp_quick_sort(arr, 0, SIZE-1);
    t = clock() - t;
    
    // view sorted array
    print_arr(arr, SIZE);

    cpu_time_used = ((double)t)/CLOCKS_PER_SEC;
    printf("Parallel quick sort time = %f seconds.\n", cpu_time_used);
}


void omp_quick_sort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);

    // Parallel change
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            omp_quick_sort(arr, low, pi-1);
        }

        #pragma omp section
        {
            omp_quick_sort(arr, pi+1, high);
        }
    }
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[high]; // pivot element
    int i = low -1;

    for(int j = low; j<= high-1; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}