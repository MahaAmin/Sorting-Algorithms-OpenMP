# Serial to Parallel Sorting Algorithms Using OpenMP

This project implements sorting algorithms into 2 modes: normal serial mode, and parallel mode using openMP using C language.

---

## Sorting Algorithms

|Sorting Algorithm|
|-----------------|
|Count Sort|
|Merge Sort|
|Quick Sort|
|Selection Sort|

---

## How-To Run:

**For serial algorithms:**

1- Compile serial algorithm:

```
$ gcc serial_sorting/<serial_ALGO_sort>.c helpers/helpers.c -o <serial_ALGO_sort>.out
```

2- Run serial algorithm:

```
$ ./<serial_ALGO_sort>.out
```

**For parallel algorithms:**

1- Compile parallel algorithm:

```
$ gcc -fopenmp parallel_sorting/<omp_ALGO_sort>.c helpers/helpers.c -o <omp_ALGO_sort>.out
```

2- Run parallel algorithm:

```
$ ./<omp_ALGO_sort>.out
```

----