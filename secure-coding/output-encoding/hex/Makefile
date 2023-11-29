CC=gcc
CFLAGS=-std=c17 -g -Wall
INCLUDES=
LIBS=

all: init run

init:
	mkdir -p build

build/hex.o: hex.c hex.h
	$(CC) $(CFLAGS) $(INCLUDES) -c hex.c -o build/hex.o

build/main.o: main.c
	$(CC) $(CFLAGS) $(INCLUDES) -c main.c -o build/main.o

build/main: init build/hex.o build/main.o
	$(CC) $(CFLAGS) build/hex.o build/main.o -o build/main $(LIBS)

run: build/main 
	build/main

clean:
	rm -rf build/
