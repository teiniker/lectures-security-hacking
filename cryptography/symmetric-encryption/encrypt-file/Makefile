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

build/encrypt-file.o: encrypt-file.c
	$(CC) $(CFLAGS) $(INCLUDES) -c encrypt-file.c -o build/encrypt-file.o

build/encrypt-file: build/hex.o build/encrypt-file.o 
	$(CC) $(CFLAGS) build/encrypt-file.o build/hex.o -o build/encrypt-file $(LIBS)

run: build/encrypt-file 
	build/encrypt-file

clean:
	rm -rf build/
