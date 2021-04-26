import time
import random
import sys
from concurrent.futures import ThreadPoolExecutor





def rand_mult(x):
    
   
    beg = int(numA/numT) * x
    
    if(x == numT-1):
        end = int((numA/numT)) + (numA%numT) + beg
    else:
        end = int(numA/numT) + beg
    
    for num in range(beg,end):
        for i in range(0, 100):
            for j in range(0, 100):
                C[num] = C[num] * i * j
                
    
    
    


    
if len(sys.argv) < 1:
    print("Invalid format: python3 rand_thread <Thread number> <Number of args>")
    sys.exit(1)
    
numT = int(sys.argv[1])
numA = int(sys.argv[2])


C = [random.randint(0,100) for i in range(numA)]
    
thread_list = []
    
starttime = time.time()

with ThreadPoolExecutor(max_workers=numT) as executor:
    for i in range(numT):
        executor.submit(rand_mult, i)

endtime = time.time()
    

print(f"Time taken {endtime-starttime} seconds")