CC=gcc
CFLAGS=-std=c17 -g -Wall
INCLUDES=
LIBS=

all: init run

init:
	mkdir -p build

build/base16.o: base16.c base16.h
	$(CC) $(CFLAGS) $(INCLUDES) -c base16.c -o build/base16.o

build/main.o: main.c
	$(CC) $(CFLAGS) $(INCLUDES) -c main.c -o build/main.o

build/main: init build/base16.o build/main.o
	$(CC) $(CFLAGS) build/base16.o build/main.o -o build/main $(LIBS)

run: build/main 
	build/main

clean:
	rm -rf build/
