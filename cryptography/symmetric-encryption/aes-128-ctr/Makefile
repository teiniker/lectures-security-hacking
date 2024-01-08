CC=gcc
UTILS=../../utils
CFLAGS=-std=c17 -g -Wall
INCLUDES=-I/usr/include/openssl/ -I$(UTILS)/
LIBS=-L/usr/lib/x86_64-linux-gnu/ -lcrypto

all: init run

init:
	mkdir -p build

build/hex.o: $(UTILS)/encoding/hex.h $(UTILS)/encoding/hex.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(UTILS)/encoding/hex.c -o build/hex.o

build/aes.o: aes.c
	$(CC) $(CFLAGS) $(INCLUDES) -c aes.c -o build/aes.o

build/aes: build/hex.o build/aes.o 
	$(CC) $(CFLAGS) build/aes.o build/hex.o -o build/aes $(LIBS)

run: build/aes 
	build/aes

clean:
	rm -rf build/
