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

build/hmac-api.o: hmac-api.c
	$(CC) $(CFLAGS) $(INCLUDES) -c hmac-api.c -o build/hmac-api.o

build/hmac-api: build/hex.o build/hmac-api.o 
	$(CC) $(CFLAGS) build/hmac-api.o build/hex.o -o build/hmac-api $(LIBS)

run: build/hmac-api 
	build/hmac-api

clean:
	rm -rf build/
