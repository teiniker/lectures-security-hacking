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

build/hmac-fingerprint.o: hmac-fingerprint.c
	$(CC) $(CFLAGS) $(INCLUDES) -c hmac-fingerprint.c -o build/hmac-fingerprint.o

build/hmac-fingerprint: build/hex.o build/hmac-fingerprint.o 
	$(CC) $(CFLAGS) build/hmac-fingerprint.o build/hex.o -o build/hmac-fingerprint $(LIBS)

run: build/hmac-fingerprint 
	build/hmac-fingerprint

clean:
	rm -rf build/
