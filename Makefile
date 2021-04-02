default: CBenchmark CBenchmark_Ser

CBenchmark: CBenchmark.c timer.h
	gcc -g -O2 --std=c99 -fopenmp -Wall -o CBenchmark CBenchmark.c

CBenchmark_Ser: CBenchmark_Ser.c timer.h
	gcc -g -O2 --std=c99 -Wall -o CBenchmark_Ser CBenchmark_Ser.c

clean:
	rm -f CBenchmark CBenchmark_Ser

