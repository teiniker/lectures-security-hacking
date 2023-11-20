
OBJECTS = 
CFLAGS = -std=c17 -g -Wall
LDLIBS = 
CC=gcc
UNITY=../../../../unity

all: build/test

init:
	mkdir -p build

build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/stack.o: stack.c
	$(CC) $(CFLAGS) $(LDLIBS) -I $(UNITY) -c stack.c -o build/stack.o

build/stack_test.o: stack_test.c
	$(CC) $(CFLAGS) $(LDLIBS) -I $(UNITY) -c stack_test.c -o build/stack_test.o

build/test: init build/unity.o build/stack.o build/stack_test.o
	$(CC) $(CFLAGS) $(LDLIBS) build/unity.o build/stack.o build/stack_test.o -o build/test
	build/test

clean:
	rm -rf build/

