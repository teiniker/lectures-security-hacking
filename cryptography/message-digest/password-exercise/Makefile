CC=gcc
CFLAGS=-std=c17 -g -Wall
INCLUDES=-I/usr/include/openssl/
LIBS=-L/usr/lib/x86_64-linux-gnu/ -lcrypto

all: init run

init:
	mkdir -p build

build/password.o: password.c
	$(CC) $(CFLAGS) $(INCLUDES) -c password.c -o build/password.o

build/password: init build/password.o 
	$(CC) $(CFLAGS) build/password.o -o build/password $(LIBS)

run: build/password
	build/password

clean:
	rm -rf build/
