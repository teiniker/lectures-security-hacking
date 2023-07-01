CC=gcc
CFLAGS=-std=c17 -g -Wall
INCLUDES=-I/usr/include/openssl/
LIBS=-L/usr/lib/x86_64-linux-gnu/ -lcrypto

all: init run

init:
	mkdir -p build

build/random.o: random.c
	$(CC) $(CFLAGS) $(INCLUDES) -c random.c -o build/random.o

build/random: init build/random.o 
	$(CC) $(CFLAGS) build/random.o -o build/random $(LIBS)

run: build/random 
	build/random

clean:
	rm -rf build/
