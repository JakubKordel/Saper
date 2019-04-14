CC=gcc
CFLAGS=-Wall -pedantic -std=c++11

compile:
	g++ $(CFLAGS) main.cpp Tests/Tests.cpp Tests/ListTests.cpp Engine/Engine.cpp Tests/EngineTests.cpp Engine/Spot.cpp Engine/Field.cpp Tests/FieldTests.cpp PlayerInteraction/Map.cpp Tests/SpotTests.cpp PlayerInteraction/Pointer.cpp PlayerInteraction/Input.cpp -o Saper





