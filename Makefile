CC=gcc
CFLAGS=-Wall -pedantic

release: saper
	./saper

saper: all main.o
	$(CC) -o saper main.o Tests/Tests.o Tests/ListTests.o Engine/Engine.o Tests/EngineTests.o Engine/Spot.o Tests/SpotTests.o Engine/Field.o Tests/FieldTests.o PlayerInteraction/Map.o
all:
	+$(MAKE) -C Engine
	+$(MAKE) -C PlayerInteraction
	+$(MAKE) -C Tests

main.o: main.cpp
	$(CC) -c $(CFLAGS) main.cpp

clean:
	rm -rf *.o saper 
	 

