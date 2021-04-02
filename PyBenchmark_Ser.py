# Import require modules

import time
import random
import sys


#
# Function: rand_mult
# ---------------------------
# Performs the inside loop of the C cross multiplication nested loop with a processing pool to
#   divide the data among processes
# 
#  A: array of n random numbers
#  B: array of n random numbers
#  C: Holds the current loops multiplication results
#  n: number of arguments to loop over n*n times
def rand_mult(A, B, C, n):
    
    for i in range(n):
        for j in range(n):
            C[i] = A[i] * B[j]

    
    
    
    


if __name__ == "__main__":

    #Error handling of command line arguments
    if len(sys.argv) < 2:
        print("Invalid format: python3 rand_thread <Number of args>")
        sys.exit(1)

    
    numA = int(sys.argv[1])

    #Populate the arrays with n random numbers between 0 and 100
    A = [random.randint(0,100) for i in range(numA)]
    B = [random.randint(0,100) for i in range(numA)]
    C = [0 for i in range(numA)]

    
    start = time.time()
    rand_mult(A, B, C, numA)
    end - time.time()
    print(f"Time taken {end-start} seconds")
