CC=gcc
CFLAGS=-std=c17 -g -Wall
INCLUDES=-I/usr/include/openssl/
LIBS=-L/usr/lib/x86_64-linux-gnu/ -lcrypto

all: init run

init:
	mkdir -p build

build/hmac.o: hmac.c
	$(CC) $(CFLAGS) $(INCLUDES) -c hmac.c -o build/hmac.o

build/hmac: init build/hmac.o 
	$(CC) $(CFLAGS) build/hmac.o -o build/hmac $(LIBS)

run: build/hmac 
	build/hmac

clean:
	rm -rf build/
