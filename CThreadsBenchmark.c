//Function Headers
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>
#include "timer.h"


struct Process_Args
{
    int num_processes;
    int thread_number;
    int n;
    int* C[];
};

void thread_workload(void *args)
{
    struct Process_Args *local_args = (struct Process_Args *)args;

    int start = (local_args->n/local_args->num_processes) * local_args->thread_number;
    int end = start + (local_args->n/local_args->num_processes);
    int result = 0;


    
    for(int x = start; x < end; x++){
        for(int i = 0; i < 100; i++) {
            for(int j = 0; j < 100; j++)
            {
                result = result * i * j;
            }
        }
    }
    printf("Thread: %d Start: %d  End: %d N: %d\n", local_args->thread_number, start, end, local_args->n);
}
/*
 * Function: rand_mult
 * ---------------------------
 * Populates two arrays with random numbers, then performs a cross multiplication in parallel between the two arrys
 *      and stores them in a third array. 
 * 
 *  n: size of the arrays, which will then run through a for loop n*n times
 */

void rand_multiplication(int n, int num_threads) {

    int C[n];
    

    for(int i = 0; i < n; i++) {

        C[i] = (rand() % (100 - 0 + 1)) + 0;;
    }

    //Performs a cross multiplication between the two arrays using Pthreads and records the run time
    START_TIMER(RandMult); 
    //Spawn threads
    pthread_t* workers = calloc(num_threads, sizeof(pthread_t));
    struct Process_Args thread_args[num_threads];
    for (int i = 0; i < num_threads; i++)
    {
        thread_args[i].num_processes = num_threads;
        thread_args[i].thread_number = i;
        thread_args[i].n = n;
        pthread_create(&(workers[i]), NULL, (void*) (*thread_workload), (void *)&thread_args[i]);
    }

    //Wait for threads to terminate
    for (int i = 0; i < num_threads; i++)
    {
        printf("num_threads in join: %d\n", num_threads);
        pthread_join(workers[i], NULL);
    }

    STOP_TIMER(RandMult);
    free(workers);
    printf("Time taken: %8.14fs seconds\n", GET_TIMER(RandMult));
    
}

int main(int argc, char *argv[]) {

    int numA;

    //Error checking to make sure the number of arguments in the command line are correct
    if (argc != 3) {
        fprintf(stderr, "Invalid format: srun ./CBenchmark_Ser <Number of Arguments> <Number of Threads\n");
        return EXIT_FAILURE;
    }

    
    numA = atoi(argv[1]);
    int num_threads = atoi(argv[2]);
    rand_multiplication(numA, num_threads);

    return 0;
}
