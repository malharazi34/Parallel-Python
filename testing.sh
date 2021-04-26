#!/bin/bash
#
#SBATCH --job-name=py-compare
#SBATCH --output=py-compare.txt
#SBATCH --ntasks=1

make

for n in 5000 10000 20000 25000 40000 50000 75000 85000 100000 150000 200000; do

    echo -n "n=$n c serial "
    ./CBenchmark_Ser $n

    for t in 1 2 4 8 16; do
        echo -n "n=$n t=$t c "
        OMP_NUM_THREADS="$t" ./CBenchmark $n
    done

    echo "-----------------------------------------------------------"

    echo -n "n=$n py serial "
    python3 PyBenchmark_Ser.py $n

    for t in 1 2 4 8 16; do
        echo -n "n=$n t=$t py "
        python3 PyBenchmark.py $t $n
    done

    echo "-----------------------------------------------------------"
    echo -n "n=$n pypy serial "
    ./pypy3.6-v7.3.3-linux64/bin/pypy3 PyBenchmark_Ser.py $n

    for t in 1 2 4 8 16; do
        echo -n "n=$n t=$t pypy "
        ./pypy3.6-v7.3.3-linux64/bin/pypy3 PyBenchmark.py $t $n
    done

    echo "-----------------------------------------------------------"
    echo -n "n=$n cython serial"
    python Cython-0.28.1/Cy_ser_test.py $n

    for t in 1 2 4 8 16; do
        echo -n "n=$n t=$t cython "
        python Cython-0.28.1/Cy_multi_test.py $t $n
    done

    echo ""
done

