import time
import random
import sys


def rand_mult(int x):
    
    cdef int b
    b  = x
    for i in range(0, 100):
        for j in range(0, 100):
            b = b * i * j
    return b
    
    


if __name__ == "__main__":
    main()
    
def main():
    if len(sys.argv) < 1:
        print("Invalid format: python3 rand_thread <Number of args>")
        sys.exit(1)
    
    cdef int numA

 
    numA = int(sys.argv[1])


    C = [random.randint(0,100) for i in range(numA)]

    starttime = time.time()
    for i in range(len(C)):
        C[i] = rand_mult(C[i])


    
    
    endtime = time.time()
    

    print(f"Time taken {endtime-starttime} seconds")
