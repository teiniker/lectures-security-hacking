CFLAGS=-std=c17 -g -Wall  
CC=gcc
UNITY=../../../../unity

all: init build/test

init:
	mkdir -p build

build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/factorial.o: factorial.h factorial.c
	$(CC) $(CFLAGS) -c factorial.c -o build/factorial.o

build/factorial_test.o: factorial_test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c factorial_test.c -o build/factorial_test.o

build/test: init build/unity.o build/factorial.o build/factorial_test.o
	$(CC) $(CFLAGS) build/unity.o build/factorial.o build/factorial_test.o -o build/test
	build/test

clean:
	rm -rf build/
