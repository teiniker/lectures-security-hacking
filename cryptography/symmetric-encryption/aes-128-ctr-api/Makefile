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

build/aes-api.o: aes-api.c
	$(CC) $(CFLAGS) $(INCLUDES) -c aes-api.c -o build/aes-api.o

build/aes-api: build/hex.o build/aes-api.o 
	$(CC) $(CFLAGS) build/aes-api.o build/hex.o -o build/aes-api $(LIBS)

run: build/aes-api 
	build/aes-api

clean:
	rm -rf build/
