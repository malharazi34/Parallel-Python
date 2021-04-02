//Function Headers
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include "timer.h"


/*
 * Function: rand_mult
 * ---------------------------
 * Populates two arrays with random numbers, the performs cross multiplication between the two arrys
 *      and stores them in a third array. 
 * 
 *  n: size of the arrays, which will then run through a for loop n*n times
 */
void rand_multiplication(int n) {

    struct timeval start, end;
    int A[n], B[n], C[n], i;
    memset(C, 0, n);

    //Populate the two arrays with numbers between 0 and 100
    for(int i = 0; i < n; i++) {

        A[i] = i;
    }

    for(int i = 0; i < n; i++) {

        B[i] = i;
    }

    //Performs a cross multiplication between the two arrays and stores them in array C while recording the runtime
    START_TIMER(RandMult);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            C[i] = A[i] * B[j];
    }

   STOP_TIMER(RandMult);

    printf("Work took %8.4fs seconds\n", GET_TIMER(MatrixMult));
    
}

int main(int argc, char *argv[]) {

    int numT, numA;

    //Error checking to make sure the number of arguments in the command line are correct
    if (argc != 2) {
        fprintf(stderr, "Invalid format: srun ./CBenchmark_Ser <Number of Arguments> \n");
        return EXIT_FAILURE;
    }

    
    numA = atoi(argv[1]);
    rand_multiplication(numA);

    return 0;
}
