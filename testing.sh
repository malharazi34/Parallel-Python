#!/bin/bash
#
#SBATCH --job-name=py-compare
#SBATCH --output=py-compare.txt
#SBATCH --ntasks=1

make

for n in 5000 10000 20000 25000 40000 50000 75000 85000 100000 150000 200000; do

    echo -n "n=$n C Serial: "
    ./CBenchmark_Ser $n

    for t in 1 2 4 8 16; do
        echo -n "n=$n t=$t C W/ Processes: "
        OMP_NUM_THREADS="$t" ./CBenchmark $n
    done

    echo "-----------------------------------------------------------"

    echo -n "n=$n Python Serial: "
    python3 PyBenchmark_Ser.py $n

    for t in 1 2 4 8 16; do
        echo -n "n=$n t=$t Python W/ Processes: "
        python3 PyBenchmark.py $t $n
    done

    echo "-----------------------------------------------------------"
    echo -n "n=$n Pypy Serial: "
    ./pypy3.6-v7.3.3-linux64/bin/pypy3 PyBenchmark_Ser.py $n

    for t in 1 2 4 8 16; do
        echo -n "n=$n t=$t Pypy W/ Processes: "
        ./pypy3.6-v7.3.3-linux64/bin/pypy3 PyBenchmark.py $t $n
    done

    echo "-----------------------------------------------------------"
    echo -n "n=$n Cython Serial"
    python Cython-0.28.1/Cy_ser_test.py $n

    for t in 1 2 4 8 16; do
        echo -n "n=$n t=$t Cython W/ Processes: "
        python Cython-0.28.1/Cy_multi_test.py $t $n
    done
    
    
    echo "-----------------------------------------------------------"
    echo -n "n=$n Python Serial:"
    python3 PyBenchmark_Ser.py $n

    for t in 1 2 4 8 16; do
        echo -n "n=$n t=$t Python W/ Threads: "
        python3 Py_thread.py $t $n
    done

    echo ""
done

