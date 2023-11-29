CC=gcc
CFLAGS=-std=c17 -g -Wall
INCLUDES=-I/usr/include/openssl/
LIBS=-L/usr/lib/x86_64-linux-gnu/ -lcrypto -lm

all: init run

init:
	mkdir -p build

build/base64.o: base64.c base64.h
	$(CC) $(CFLAGS) $(INCLUDES) -c base64.c -o build/base64.o

build/main.o: main.c
	$(CC) $(CFLAGS) $(INCLUDES) -c main.c -o build/main.o

build/main: init build/base64.o build/main.o
	$(CC) $(CFLAGS) build/base64.o build/main.o -o build/main $(LIBS)

run: build/main 
	build/main

clean:
	rm -rf build/
