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

    int C[n];
    
    
    //Populate the two arrays with numbers between 0 and 100

    for(int i = 0; i < n; i++) {

        C[i] = (rand() % (100 - 0 + 1)) + 0;;
    }

    //Performs a cross multiplication between the two arrays using OpenMP and records the run time
    START_TIMER(RandMult);
#   pragma omp parallel for   
    for(int x = 0; x < n; x++){
        for(int i = 0; i < 100; i++) {
            for(int j = 0; j < 100; j++)
                C[x] = C[x] * i * j;
        }
    }

    STOP_TIMER(RandMult);
    printf("Time taken: %8.14fs seconds\n", GET_TIMER(RandMult));
    
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
