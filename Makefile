CC=gcc -ansi -lrt

.PHONY: benchmark demo

benchmark:
	${CC} -o benchmark benchmark.c sgsort.c

demo:
	${CC} -o demo demo.c sgsort.c
