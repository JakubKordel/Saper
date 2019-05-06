CFLAGS=-Wall -pedantic -std=c++11

compile: main.o Game.o ./Tests/Tests.o ./Tests/ListTests.o ./Engine/Engine.o ./Tests/EngineTests.o ./Engine/Spot.o ./Engine/Field.o ./Tests/FieldTests.o ./PlayerInteraction/Map.o ./Tests/SpotTests.o ./PlayerInteraction/Pointer.o ./PlayerInteraction/Input.o ./PlayerInteraction/Settings.o ./AIPlayer/AIPlayer.o
	g++ $(CFLAGS) main.o Game.o ./Tests/Tests.o ./Tests/ListTests.o ./Engine/Engine.o ./Tests/EngineTests.o ./Engine/Spot.o ./Engine/Field.o ./Tests/FieldTests.o ./PlayerInteraction/Map.o ./Tests/SpotTests.o ./PlayerInteraction/Pointer.o ./PlayerInteraction/Input.o ./PlayerInteraction/Settings.o ./AIPlayer/AIPlayer.o -o Saper

main.o: main.cpp ./PlayerInteraction/Pointer.h ./PlayerInteraction/Settings.h
	g++ -c $(CFLAGS) main.cpp ./PlayerInteraction/Pointer.h ./PlayerInteraction/Settings.h

Game.o: Game.cpp
	g++ -c $(CFLAGS) Game.cpp 

Tests.o: ./Tests/Tests.cpp ./Tests/Tests.h
	g++ -c $(CFLAGS) ./Tests/Tests.cpp ./Tests/Tests.h

ListTests.o: ./Tests/ListTests.cpp ./Tests/ListTests.h
	g++ -c $(CFLAGS) ./Tests/ListTests.cpp ./Tests/ListTests.h

Engine.o: ./Engine/Engine.cpp ./Engine/Engine.h
	g++ -c $(CFLAGS) ./Engine/Engine.cpp ./Engine/Engine.h

EngineTests.o: ./Tests/EngineTests.cpp ./Tests/EngineTests.h
	g++ -c $(CFLAGS) ./Tests/EngineTests.cpp ./Tests/EngineTests.h

Spot.o: ./Engine/Spot.cpp ./Engine/Spot.h
	g++ -c $(CFLAGS) ./Engine/Spot.cpp ./Engine/Spot.h

Field.o: ./Engine/Field.cpp ./Engine/Field.h
	g++ -c $(CFLAGS) ./Engine/Field.cpp ./Engine/Field.h

FieldTests.o: ./Tests/FieldTests.cpp ./Tests/FieldTests.h
	g++ -c $(CFLAGS) ./Tests/FieldTests.cpp ./Tests/FieldTests.h

Map.o: ./PlayerInteraction/Map.cpp ./PlayerInteraction/Map.h
	g++ -c $(CFLAGS) ./PlayerInteraction/Map.cpp ./PlayerInteraction/Map.h

SpotTests.o: ./Tests/SpotTests.cpp ./Tests/SpotTests.h
	g++ -c $(CFLAGS) ./Tests/SpotTests.cpp ./Tests/SpotTests.h

Pointer.o: ./PlayerInteraction/Pointer.cpp ./PlayerInteraction/Pointer.h
	g++ -c $(CFLAGS) ./PlayerInteraction/Pointer.cpp ./PlayerInteraction/Pointer.h

Input.o: ./PlayerInteraction/Input.cpp ./PlayerInteraction/Input.h
	g++ -c $(CFLAGS) ./PlayerInteraction/Input.cpp ./PlayerInteraction/Input.h

Settings.o: ./PlayerInteraction/Settings.cpp ./PlayerInteraction/Settings.h
	g++ -c $(CFLAGS) ./PlayerInteraction/Settings.cpp ./PlayerInteraction/Settings.h

AIPlayer.o: ./AIPlayer/AIPlayer.cpp ./AIPlayer/AIPlayer.h
	g++ -c $(CFLAGS) ./AIPlayer/AIPlayer.cpp ./AIPlayer/AIPlayer.h

clean:
	rm -rf *.o compile

