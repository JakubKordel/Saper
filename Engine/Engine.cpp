//
// Created by Jakub Kordel on 30.03.19.
//

#include "Engine.h"

Engine::Engine( int width, int high, double risk ){
    highY = high;
    widthX = width;
    field = new Field( width, high );
    bombs = ( int )(risk/100 * width * high);
    hiddenValues = widthX * highY - bombs;
    flags = bombs;
    state = BEFORE;
}

Engine::~Engine(){
    delete field;
}

void Engine::setUpMap( int n ){
    setUpBombs( n );
    setUpValues();
}

void Engine::setUpBombs( int n ){
    srand( time( NULL ) );
    int places = widthX*highY - ( 1 + n ); //pozostale miejsca na bomby( bez punktu startowego i punktow wokol niego
    int notPlacedBombs = bombs;
    int randomNum;
    bool isPlaced;
    while ( notPlacedBombs-- ){
        randomNum = rand()%places;
        --places;
        isPlaced = false;
        for ( int i = 0; i< highY; ++i ){
            for ( int j = 0; j < widthX ; ++j ) {
                Spot & spot = field ->getSpot( j, i );
                if ( spot.getType() != Spot::BOMB && spot.getVisibility() != Spot::VISIBLE ){
                    if ( randomNum )
                        --randomNum;
                    else {
                        spot.setType(Spot::BOMB);
                        isPlaced = true;
                        break;
                    }
                }
            }
            if ( isPlaced )
                break;
        }
    }
}

void Engine::setUpValues(){
    for ( int i = 0; i< highY; ++i ) {
        for (int j = 0; j < widthX; ++j) {
            Spot & spot = field ->getSpot( j, i );
            spot.setBombsAround( countBombsAround( j, i ) );
        }
    }
}

int Engine::countBombsAround( int x, int y ){
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
    if ( x > 0 ) left = true;
    if ( x + 1 < widthX ) right = true;
    if ( y > 0 ) down = true;
    if ( y + 1 < highY ) up = true;
    int counter = 0;
    if ( up && left )
        if ( type( x - 1, y + 1) == Spot::BOMB ) ++counter;
    if ( up )
        if ( type( x    , y + 1) == Spot::BOMB ) ++counter;
    if ( up && right )
        if ( type( x + 1, y + 1) == Spot::BOMB ) ++counter;
    if ( right )
        if ( type( x + 1, y    ) == Spot::BOMB ) ++counter;
    if ( down && right )
        if ( type( x + 1, y - 1) == Spot::BOMB ) ++counter;
    if ( down )
        if ( type( x    , y - 1) == Spot::BOMB ) ++counter;
    if ( down && left )
        if ( type( x - 1, y - 1) == Spot::BOMB ) ++counter;
    if ( left )
        if ( type( x - 1, y    ) == Spot::BOMB ) ++counter;
    return counter;
}

int Engine::bombsNum(){
    return bombs;
}

int Engine::flagsNum(){
    return flags;
}

Engine::State Engine::stateVal(){
    return state;
}

void Engine::unhide( int x, int y){
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
    if ( x > 0 ) left = true;
    if ( x + 1 < widthX ) right = true;
    if ( y > 0 ) down = true;
    if ( y + 1 < highY ) up = true;
    int n = 8;

    Spot & spot = field->getSpot( x, y );
    spot.setVisibility( Spot::VISIBLE );
    if ( state == BEFORE ){
        int sum = (int)up + (int)down + (int)left + (int)right;
        if ( sum == 3 ) n = 5;
        if ( sum == 2 ) n = 3;
        --hiddenValues;
        state = STARTED;
        if ( up && left ) field->getSpot( x - 1, y + 1 ).setVisibility( Spot::VISIBLE );
        if ( up ) field->getSpot( x, y + 1).setVisibility( Spot::VISIBLE );
        if ( up && right ) field->getSpot( x + 1, y + 1).setVisibility( Spot::VISIBLE );
        if ( right ) field->getSpot( x + 1, y ).setVisibility( Spot::VISIBLE );
        if ( down && right ) field->getSpot( x + 1, y - 1 ).setVisibility( Spot::VISIBLE );
        if ( down ) field->getSpot( x, y - 1).setVisibility( Spot::VISIBLE );
        if ( down && left ) field->getSpot( x - 1, y - 1 ).setVisibility( Spot::VISIBLE );
        if ( left ) field->getSpot( x - 1, y ).setVisibility( Spot::VISIBLE );
        setUpMap( n );
        if ( up && left ) unhide( x - 1, y + 1 );
        if ( up ) unhide( x, y + 1);
        if ( up && right ) unhide( x + 1, y + 1);
        if ( right ) unhide( x + 1, y );
        if ( down && right ) unhide( x + 1, y - 1 );
        if ( down ) unhide( x, y - 1);
        if ( down && left ) unhide( x - 1, y - 1 );
        if ( left ) unhide( x - 1, y );

    } else {
        if ( spot.getType() == Spot::BOMB )
            state = LOSE;
        else {
            --hiddenValues;
            if ( hiddenValues == 0 ) state = WIN;
            else if ( value( x, y ) == 0 ) {
                if ( up && left )
                    if ( type( x - 1, y + 1) == Spot::VALUE && visibility( x - 1, y + 1 ) != Spot::VISIBLE) unhide( x - 1, y + 1 );
                if ( up )
                    if ( type( x    , y + 1) == Spot::VALUE && visibility( x    , y + 1 ) != Spot::VISIBLE) unhide( x    , y + 1 );
                if ( up && right )
                    if ( type( x + 1, y + 1) == Spot::VALUE && visibility( x + 1, y + 1 ) != Spot::VISIBLE) unhide( x + 1, y + 1 );
                if ( right )
                    if ( type( x + 1, y    ) == Spot::VALUE && visibility( x + 1, y     ) != Spot::VISIBLE) unhide( x + 1, y     );
                if ( down && right )
                    if ( type( x + 1, y - 1) == Spot::VALUE && visibility( x + 1, y - 1 ) != Spot::VISIBLE) unhide( x + 1, y - 1 );
                if ( down )
                    if ( type( x    , y - 1) == Spot::VALUE && visibility( x    , y - 1 ) != Spot::VISIBLE) unhide( x    , y - 1 );
                if ( down && left )
                    if ( type( x - 1, y - 1) == Spot::VALUE && visibility( x - 1, y - 1 ) != Spot::VISIBLE) unhide( x - 1, y - 1 );
                if ( left )
                    if ( type( x - 1, y    ) == Spot::VALUE && visibility( x - 1, y     ) != Spot::VISIBLE) unhide( x - 1, y     );
            }
        }
    }
}

void Engine::switchSymbol( int x, int y ) {
    Spot & spot = field->getSpot( x, y );
    Spot::Visibility current = spot.getVisibility();
    if ( current != Spot::VISIBLE ){
        switch ( current ) {
            case Spot::HIDDEN:
                spot.setVisibility( Spot::FLAG );
                --flags;
                break;
            case Spot::FLAG:
                spot.setVisibility( Spot::QUESTION );
                ++flags;
                break;
            case Spot::QUESTION:
                spot.setVisibility( Spot::HIDDEN );
                break;
        }
    }
}

Spot::Visibility Engine::visibility( int x, int y ) {
   return field ->getSpot( x, y ).getVisibility();
}

Spot::Type Engine::type(int x, int y ) {
    return field ->getSpot( x, y ).getType();
}

int Engine::value( int x, int y ){
    return field ->getSpot( x, y ).getBombsAround();
}