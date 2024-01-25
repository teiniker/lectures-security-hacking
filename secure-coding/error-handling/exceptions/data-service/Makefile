CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt
UNITY=../../../unity/

all: init run 

init:
	mkdir -p build

unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o
	
build/FileService.o: FileService.cpp FileService.h
	$(CC) $(CFLAGS) -c FileService.cpp -o build/FileService.o

build/DataService.o: DataService.cpp DataService.h
	$(CC) $(CFLAGS) -c DataService.cpp -o build/DataService.o

build/FileServiceTest.o: FileServiceTest.cpp
	$(CC) $(CFLAGS) -c FileServiceTest.cpp -o build/FileServiceTest.o

build/FileServiceTest: build/FileServiceTest.o build/FileService.o build/DataService.o 
	$(CC) build/FileServiceTest.o build/FileService.o build/DataService.o -o build/FileServiceTest $(LIBS)
	
run: build/FileServiceTest	
	build/FileServiceTest

clean:
	rm -rf build/
