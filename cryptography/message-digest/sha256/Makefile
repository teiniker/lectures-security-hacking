CC=gcc
CFLAGS=-std=c17 -g -Wall
INCLUDES=-I/usr/include/openssl/
LIBS=-L/usr/lib/x86_64-linux-gnu/ -lcrypto

all: init run

init:
	mkdir -p build

build/sha-256.o: sha-256.c
	$(CC) $(CFLAGS) $(INCLUDES) -c sha-256.c -o build/sha-256.o

build/sha-256: init build/sha-256.o 
	$(CC) $(CFLAGS) build/sha-256.o -o build/sha-256 $(LIBS)

run: build/sha-256 
	build/sha-256

clean:
	rm -rf build/
