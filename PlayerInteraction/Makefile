CC=gcc
CFLAGS=-Wall -pedantic

compile: Map.o

Map.o: Map.cpp Map.h
	$(CC) -c $(CFLAGS) Map.cpp

clean:
	rm -rf *.o compile
