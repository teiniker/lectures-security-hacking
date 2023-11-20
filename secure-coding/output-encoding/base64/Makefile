CC=gcc
CFLAGS=-std=c17 -g -Wall
INCLUDES=-I/usr/include/openssl/
LIBS=-L/usr/lib/x86_64-linux-gnu/ -lcrypto -lm

all: init run

init:
	mkdir -p build

build/base64.o: base64.c
	$(CC) $(CFLAGS) $(INCLUDES) -c base64.c -o build/base64.o

build/base64: init build/base64.o 
	$(CC) $(CFLAGS) build/base64.o -o build/base64 $(LIBS)

run: build/base64 
	build/base64

clean:
	rm -rf build/
