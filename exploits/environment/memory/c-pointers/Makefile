OBJECTS = 
CFLAGS = -std=c17 -g -Wall
LDLIBS = 
CC=gcc


all: build/pointers build/type_sizes

init:
	mkdir -p build

build/pointers: init pointers.c
	$(CC) $(CFLAGS) $(LDLIBS) -o build/pointers pointers.c 
	build/pointers

build/type_sizes: init type_sizes.c
	$(CC) $(CFLAGS) $(LDLIBS) -o build/type_sizes type_sizes.c

clean:
	rm -rf build/

