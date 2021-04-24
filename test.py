import time
import cython_example
 
 
def main():
    start = time.time()
    result = cython_example.main()
    duration = time.time() - start
    print(result, duration)
 
 
if __name__ == '__main__':
    main()