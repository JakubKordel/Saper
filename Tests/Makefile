CC=gcc
CFLAGS=-Wall -pedantic

compile: Tests.o ListTests.o EngineTests.o SpotTests.o FieldTests.o 

Tests.o: Tests.h Tests.cpp
	$(CC) -c $(CFLAGS) Tests.cpp

ListTests.o: ListTests.cpp ListTests.h
	$(CC) -c $(CFLAGS) ListTests.cpp

EngineTests.o: EngineTests.h EngineTests.cpp
	$(CC) -c $(CFLAGS) EngineTests.cpp

SpotTests.o: SpotTests.h SpotTests.cpp
	$(CC) -c $(CFLAGS) SpotTests.cpp

FieldTests.o: FieldTests.h FieldTests.cpp
	$(CC) -c $(CFLAGS) FieldTests.cpp

clean:
	rm -rf *.o compile
