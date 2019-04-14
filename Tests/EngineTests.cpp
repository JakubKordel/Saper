//
// Created by Jakub Kordel on 30.03.19.
//

#include "EngineTests.h"

bool engineConstructorTest(){
    bool flag = true;
    Engine game( 12, 10, 50 );
    if ( game.bombsNum() != 60 || game.flagsNum() != 60 ) flag = false;
    if ( game.stateVal() != Engine::BEFORE ) flag = false;
    return flag;
}

bool engineSetUpMapTest(){
    bool flag = true;
    Engine game( 12, 10, 50 );
    game.unhide( 6, 5 );
    if ( game.stateVal() != Engine::STARTED ) flag = false;
    int counter = 0;
    for ( int i = 0; i<10 ; ++i ){
        for ( int j = 0; j < 12 ; ++j ) {
            if (game.type(j, i) == Spot::BOMB)
                ++counter;
        }
    }
    if ( counter != 60 ) flag = false;
    return flag;
}

bool engineBombsNumTest() {
    bool flag = true;
    Engine game( 12, 10, 50 );
    if ( game.bombsNum() != 60 ) flag = false;
    return flag;
}

bool engineFlagsNumTest() {
    bool flag = true;
    Engine game( 12, 10, 50 );
    game.switchSymbol( 6,6 );
    if ( game.flagsNum() != 59 ) flag = false;
    return flag;
}

bool engineStateValTest() {
    bool flag = true;
    Engine game( 12, 10, 50 );
    if ( game.stateVal() != Engine::BEFORE ) flag = false;
    game.unhide( 6, 5 );
    if ( game.stateVal() != Engine::STARTED ) flag = false;
    return flag;
}

bool engineUnhideTest() {
    Engine game( 12, 10, 50 );
    game.unhide( 6, 5 );
    return  game.visibility( 6, 5 ) == Spot::VISIBLE ;
}

bool engineSwitchSymbolTest() {
    bool flag = true;
    Engine game( 12, 10, 50 );
    game.switchSymbol( 7, 8 );
    if ( game.visibility( 7, 8 ) != Spot::FLAG ) flag = false;
    game.switchSymbol( 7, 8 );
    if ( game.visibility( 7, 8 ) != Spot::QUESTION ) flag = false;
    return flag;
}

bool engineVisibilityTest( ) {
    Engine game( 12, 10, 50 );
    game.switchSymbol( 7, 8 );
    return game.visibility( 7, 8 ) == Spot::FLAG;
}

bool engineTypeTest ( ) {

    bool flag = true;
    Engine game( 12, 10, 50 );
    game.unhide( 6, 5 );
    if ( game.type( 6, 5 ) != Spot::VALUE ) flag = false;
    return flag;
}
