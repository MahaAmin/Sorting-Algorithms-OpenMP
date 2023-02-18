#include<stdio.h>
#include<omp.h>
#include "../helpers/helpers.h"


int SIZE = 100000;
struct Compare
{
    int val;
    int index;
};

void omp_selection_sort(int arr[], int size);

#pragma omp declare reduction(minimum : struct Compare : omp_out = omp_in.val < omp_out.val ? omp_in : omp_out) initializer(omp_priv=omp_orig)

int main(){
    int arr[SIZE];
    generate_rand_arr(arr, SIZE, SIZE);
    //print_arr(arr, SIZE);
    omp_selection_sort(arr, SIZE);
    //print_arr(arr, SIZE);
}


void omp_selection_sort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        struct Compare min;
        min.val = arr[i];
        min.index = i; 
        #pragma omp parallel for reduction(minimum:min)
        for(int j=i+1; j<size; j++){
            if(arr[j]<min.val){
                min.val = arr[j];
                min.index = j;
            }
        }

        // swap
        if(min.index != i){
            int tmp = arr[i];
            arr[i] = min.val;
            arr[min.index] = tmp;
        }
    }
}