import time
import random
import sys
from multiprocessing import Pool



def wrapper(args):
    return rand_mult(*args)


def rand_mult(A, B, C, i):
    
    for j in range(len(B)):
        C[i] = A[i] * B[j]
        
    
    


if __name__ == "__main__":
    
    
    if len(sys.argv) < 2:
        print("Invalid format: python3 rand_thread <Thread number> <Number of args>")
        sys.exit(1)
    
    numP = int(sys.argv[1])
    numA = int(sys.argv[2])

#    A = [random.randint(0,100) for i in range(numA)]
#    B = [random.randint(0,100) for i in range(numA)]
    A = [i for i in range(numA)]
    B = [i for i in range(numA)]
    C = [0 for i in range(numA)]



#    result = [A,B,C]
#    for i in range(len(A)):
#        for j in range(len(B)):
#            result.append((A[i],B[j]))
    
    starttime = time.time()
    pool = Pool(processes = numP)
    
    
    for i in range(numA):
        pool.apply_async(rand_mult, args = (A,B,C,i))
    
    pool.close()
    pool.join()
    endtime = time.time()
    

    print(f"Time taken {endtime-starttime} seconds")