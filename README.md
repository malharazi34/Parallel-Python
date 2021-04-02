# PythonThreading


Repository for the PythonThreading research project for CS 470 at James Madison University

## Description

In our project, we attempt to compare the difference in runtime of parallel and serial compuations between C and multiple Python implementations. The programs create two arrays of size n containing random numbers, then performs a cross multiplication between the two, and stores them in an array. Ultimately, the program will iterate n\*n times over the arrays, and prints the run time of the function.

## Compilation of C source files

To begin, start of with running the provided make file

```bash
make
gcc -g -O2 --std=c99 -fopenmp -Wall -o CBenchmark CBenchmark.c
gcc -g -O2 --std=c99 -Wall -o CBenchmark_Ser CBenchmark_Ser.c
```

It should have compiled the CBenchmark.c and CBenchmark_Ser.c files and created an executable for each

## Running the C files

Once you have the two executables in your directory, the files are ready to be ran

To run the serial C executable:

```bash
./CBenchmark_Ser <Number of Arugments>
```

to run the parallel C executable:

```bash
OMP_NUM_THREADS=<NUMBER_OF_PROCESSES> ./CBenchmark <Number of Arugments>
```

## Running Python3 with the Python files

To run the serial Python program:

```bash
srun python3 PyBenchmark_Ser.py <Number of Arugments>
```

To run the Multiprocess Python program:

```bash
srun python3 PyBenchmark.py <Number of Processes> <Number of Arugments>
```

## Running PyPy3 with the Python files

To run pypy3, we have provided the absoulte path for it to work on the cluster

Serial pypy example: 

```bash
srun pypy3.6-v7.3.3-linux64/bin/pypy3 PyBenchmark_Ser.py <Number of Arugments>
```

Parallel pypy example:

```bash
srun pypy3.6-v7.3.3-linux64/bin/pypy3 PyBenchmark.py <Number of Processes> <Number of Arugments>
```

