OBJECTS =
CFLAGS = -std=c17 -g -Wall
LDLIBS = 
CC=gcc
UNITY=../../../../unity

all: build/test

init:
	mkdir -p build

build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/linked_list.o: linked_list.c linked_list.h
	$(CC) $(CFLAGS) $(LDLIBS) -c linked_list.c -o build/linked_list.o

build/test.o: linked_list_test.c
	$(CC) $(CFLAGS) $(LDLIBS) -I $(UNITY) -c linked_list_test.c -o build/test.o

build/test: init build/unity.o build/linked_list.o build/test.o
	$(CC) $(CFLAGS) $(LDLIBS) build/unity.o build/linked_list.o build/test.o -o build/test
	build/test


clean:
	rm -rf build/


