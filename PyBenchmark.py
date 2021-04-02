# Import require modules
import time
import random
import sys
from multiprocessing import Pool



#
# Function: rand_mult
# ---------------------------
# Performs the inside loop of the C cross multiplication nested loop with a processing pool to
#   divide the data among processes
# 
#  A: array of n random numbers
#  B: array of n random numbers
#  C: Holds the current loops multiplication results
def rand_mult(A, B, C, i):
    
    for j in range(len(B)):
        C[i] = A[i] * B[j]
        
    
    


if __name__ == "__main__":
    
    # Error Checking to make sure the correct number of arguments were given
    if len(sys.argv) < 2:
        print("Invalid format: python3 PyBenchmark <Thread number> <Number of args>")
        sys.exit(1)
    
    #Initialize the arguments for later use
    numP = int(sys.argv[1])
    numA = int(sys.argv[2])

    #Populate arrays with random numbers
    A = [random.randint(0,100) for i in range(numA)]
    B = [random.randint(0,100) for i in range(numA)]
    C = [0 for i in range(numA)]


    
    start = time.time()
    # Create a pool of processes based on the input given
    pool = Pool(processes = numP)
    
    #Divide the data in the first for loop among the processes
    for i in range(numA):
        pool.apply_async(rand_mult, args = (A,B,C,i))
    
    #Cleanup the processes
    pool.close()
    pool.join()
    end = time.time()
    

    print(f"Time taken {end-start} seconds")
