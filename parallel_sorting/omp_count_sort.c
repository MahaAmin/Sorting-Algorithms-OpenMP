#include <stdio.h>
#include <omp.h>
#include "../helpers/helpers.h"

# define NUM_THREADS 5
int SIZE = 10;

void omp_count_sort(int unsorted_arr[], int sorted_arr[], int size);

int main(){

    // generate random unsorted array
    int unsorted_arr[SIZE];
    generate_rand_arr(unsorted_arr, SIZE, SIZE);
    print_arr(unsorted_arr, SIZE);
    
    // initialize output array with 0
    int sorted_arr[SIZE];
    for(int i=0; i<SIZE; i++)
        sorted_arr[i] = 0;

    // parallel count sort
    omp_count_sort(unsorted_arr, sorted_arr, SIZE);
    print_arr(sorted_arr, SIZE);
}


void omp_count_sort(int unsorted_arr[], int sorted_arr[], int size){
    int i, j, count;
    omp_set_num_threads(NUM_THREADS);
    double start_time = omp_get_wtime();
    #pragma omp parallel for private(i, j, count)
    for (i = 0; i < size; i++) {
        count = 0;
        for (j = 0; j < size; j++) {
            if (unsorted_arr[i] > unsorted_arr[j])
                count++;
        }
        while (sorted_arr[count] != 0)
            count++;
        sorted_arr[count] = unsorted_arr[i];
    }
    double end_time = omp_get_wtime();
    double time_used = end_time - start_time;
    printf("Parallel time: %f s\n", time_used);
}
