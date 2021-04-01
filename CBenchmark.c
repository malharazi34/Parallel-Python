#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include "timer.h"

#define n 2048

double A[n][n];
double B[n][n];
double C[n][n];

int main() {

    //populate the matrices with random values between 0.0 and 1.0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            A[i][j] = (double) rand() / (double) RAND_MAX;
            B[i][j] = (double) rand() / (double) RAND_MAX;
            C[i][j] = 0;
        }
    }
    //matrix multiplication
    START_TIMER(MatrixMult);
    int i, j, k;

#   pragma omp parallel for default(none) shared(A,B,C) private(i,j,k)
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    STOP_TIMER(MatrixMult);
    printf("Elapsed time in seconds: %f \n", GET_TIMER(MatrixMult));
    return 0;
}