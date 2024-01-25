CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt
UNITY=../../../unity/

all: init run  

init:
	mkdir -p build

unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/user.o: user.cpp user.h
	$(CC) $(CFLAGS) -c user.cpp -o build/user.o

build/test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp -o build/test.o

build/test: build/test.o build/user.o 
	$(CC) build/test.o build/user.o -o build/test $(LIBS)

run: build/test
	build/test

clean:
	rm -rf build/
