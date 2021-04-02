# PythonThreading


Repository for the PythonThreading research project for CS 470 at James Madison University

## Usage

To begin, start of with running the provided make file

```bash
make
gcc -g -O2 --std=c99 -fopenmp -Wall -o CBenchmark CBenchmark.c
gcc -g -O2 --std=c99 -Wall -o CBenchmark_Ser CBenchmark_Ser.c
```

It should have compiled the CBenchmark.c and CBenchmark_Ser.c files and created an executable for each
