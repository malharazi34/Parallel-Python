//Function Headers
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <omp.h>
#include "timer.h"

/*
 * Function: rand_mult
 * ---------------------------
 * Populates two arrays with random numbers, then performs a cross multiplication in parallel between the two arrys
 *      and stores them in a third array. 
 * 
 *  n: size of the arrays, which will then run through a for loop n*n times
 */

void rand_multiplication(int n) {

    int A[n], B[n], C[n];
    memset(C, 0, n);
    
    //Populate the two arrays with numbers between 0 and 100
    for(int i = 0; i < n; i++) {

        A[i] = (rand() % (100 - 0 + 1)) + 0;
    }

    for(int i = 0; i < n; i++) {

        B[i] = (rand() % (100 - 0 + 1)) + 0;;
    }

    //Performs a cross multiplication between the two arrays using OpenMP and records the run time
    START_TIMER(RandMult);
#   pragma omp parallel for collapse(2)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            C[i] = A[i] * B[j];
    }

    STOP_TIMER(RandMult);
    printf("Work took %8.4fs seconds\n", GET_TIMER(RandMult));
    
}

int main(int argc, char *argv[]) {

    int numA;

    //Error checking to make sure the number of arguments in the command line are correct
    if (argc != 2) {
        fprintf(stderr, "Invalid format: srun OMP_NUM_THREADS=<NUM_PROCESSES> ./CBenchmark <Number of Arguments> \n");
        return EXIT_FAILURE;
    }

    
    numA = atoi(argv[1]);
    rand_multiplication(numA);

    return 0;
}
