
OBJECTS = 
CFLAGS = -std=c17 -g -Wall  
LDLIBS = 
CC=gcc

all: init build/heap 

init:
	mkdir -p build

build/heap: heap.c
	$(CC) $(CFLAGS) $(LDLIBS) -o build/heap heap.c 

clean:
	rm -rf build/ 

