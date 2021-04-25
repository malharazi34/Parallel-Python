import time
import random
import sys
from multiprocessing import Pool


def rand_mult(int x):
    
    cdef int b
    b = x
    for i in range(0, 100):
        for j in range(0, 100):
            b = b * i * j
    return b
    
    


if __name__ == "__main__":
    main()
    
def main():    
    if len(sys.argv) < 2:
        print("Invalid format: python3 rand_thread <Thread number> <Number of args>")
        sys.exit(1)
    
    cdef int numP, numA
   

    numP = int(sys.argv[1])
    numA = int(sys.argv[2])
    
    
    C = [random.randint(0,100) for i in range(numA)]

    
    starttime = time.time()
    pool = Pool(processes = numP)
    
    
    C = pool.map(rand_mult, C)

    
    pool.close()
    pool.join()
    endtime = time.time()
    

    print(f"Time taken {endtime-starttime} seconds")
