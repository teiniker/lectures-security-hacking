CC=gcc
CFLAGS=-std=c17 -g -Wall
INCLUDES=-I/usr/include/openssl/
LIBS=-L/usr/lib/x86_64-linux-gnu/ -lcrypto -lm

all: init run

init:
	mkdir -p build

build/hex.o: hex.c
	$(CC) $(CFLAGS) $(INCLUDES) -c hex.c -o build/hex.o

build/hex: init build/hex.o 
	$(CC) $(CFLAGS) build/hex.o -o build/hex $(LIBS)

run: build/hex 
	build/hex

clean:
	rm -rf build/
