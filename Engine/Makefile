CC=gcc
CFLAGS=-Wall -pedantic

compile: Engine.o Spot.o Field.o 

Engine.o: Engine.cpp Engine.h
	$(CC) -c $(CFLAGS) Engine.cpp

Spot.o: Spot.cpp Spot.h
	$(CC) -c $(CFLAGS) Spot.cpp

Field.o: Field.cpp Field.h
	$(CC) -c $(CFLAGS) Field.cpp

clean:
	rm -rf *.o compile
