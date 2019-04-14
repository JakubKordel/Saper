#include <iostream>
#include "Tests/Tests.h"
#include "Engine/Engine.h"
#include "PlayerInteraction/Map.h"
#include "PlayerInteraction/Input.h"
#include "PlayerInteraction/Pointer.h"

int main() {
    Engine engine( 6, 6, 20 );
    Pointer pointer( 6, 6 );
    Map map( engine, pointer );
    Input input( engine, pointer );
    while ( engine.stateVal() != Engine::WIN && engine.stateVal() != Engine::LOSE ){
	map.clearScreen();
        map.draw();
        input.action();
    }
	map.clearScreen();
        map.draw();	

    return 0;
}
