//
// Created by Jakub Kordel on 17.04.19.
//

#include "AIPlayer.h"

AIPlayer::AIPlayer( Engine & Engine ) : engine( Engine ) {}

void AIPlayer::move() {
    if ( !findFree() ) {
        if ( !findBomb() )
            shoot();
    }
}

bool AIPlayer::findFree(){
    bool f = false;
    for ( int i = 0; i < engine.height() ; ++i ){
        for ( int j = 0; j < engine.width() ; ++j ){
            if ( engine.visibility( j, i ) == Spot::VISIBLE && countFlags( j, i ) == engine.value( j, i ) && countHidden( j, i ) ){
                unhide( j, i );
                f = true;
                break;
            }
        }
        if ( f ) break;
    }
    return f;
}

bool AIPlayer::findBomb(){
    bool f = false;
    for ( int i = 0; i < engine.height() ; ++i ){
        for ( int j = 0; j < engine.width() ; ++j ){
            if ( engine.visibility( j, i ) == Spot::VISIBLE && countHidden( j, i ) &&  engine.value( j, i ) == ( countHidden( j, i ) + countFlags( j, i ) ) ) {
                    setFlag( j, i );
                    f = true;
                    break;
                }
            }
            if ( f ) break;
    }
    return f;
}



void AIPlayer::shoot(){
    srand( time( NULL ) );
    int places = 0;
    for ( int i = 0; i < engine.height() ; ++i ){
        for ( int j = 0; j < engine.width() ; ++j ){
            if ( engine.visibility( j, i ) == Spot::HIDDEN ) ++places;
        }
    }
    int randomNum = rand()%(places) + 1;
    for ( int i = 0; i < engine.height() ; ++i ){
        for ( int j = 0; j < engine.width() ; ++j ){
            if ( engine.visibility( j, i ) == Spot::HIDDEN ) {
                if ( --randomNum == 0 ) {
                    engine.unhide( j, i );
                    break;
                }
            }
        }
        if ( randomNum == 0 ) break;
    }
}

void AIPlayer::unhide( const int & x, const int & y ){
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
    if ( x > 0 ) left = true;
    if ( x + 1 < engine.width() ) right = true;
    if ( y > 0 ) down = true;
    if ( y + 1 < engine.height() ) up = true;
    if ( up && left && engine.visibility( x - 1, y + 1) == Spot::HIDDEN  ) engine.unhide( x - 1, y + 1 );
    else if ( up && engine.visibility( x , y + 1 ) == Spot::HIDDEN ) engine.unhide( x , y + 1 );
    else if ( up && right && engine.visibility( x + 1, y + 1 ) == Spot::HIDDEN ) engine.unhide( x + 1, y + 1 );
    else if ( right && engine.visibility( x + 1, y  ) == Spot::HIDDEN ) engine.unhide( x + 1, y );
    else if ( down && right  && engine.visibility( x + 1, y - 1 ) == Spot::HIDDEN ) engine.unhide( x + 1, y - 1 );
    else if ( down && engine.visibility( x , y - 1 ) == Spot::HIDDEN ) engine.unhide( x , y - 1 );
    else if ( down && left && engine.visibility( x - 1, y - 1 ) == Spot::HIDDEN ) engine.unhide( x - 1, y - 1 );
    else if ( left && engine.visibility( x - 1, y ) == Spot::HIDDEN ) engine.unhide( x - 1, y );
}

void AIPlayer::setFlag( const int & x, const int & y ){
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
    if ( x > 0 ) left = true;
    if ( x + 1 < engine.width() ) right = true;
    if ( y > 0 ) down = true;
    if ( y + 1 < engine.height() ) up = true;
    if ( up && left && engine.visibility( x - 1, y + 1) == Spot::HIDDEN  ) engine.switchSymbol( x - 1, y + 1 );
    else if ( up && engine.visibility( x , y + 1 ) == Spot::HIDDEN ) engine.switchSymbol( x , y + 1 );
    else if ( up && right && engine.visibility( x + 1, y + 1 ) == Spot::HIDDEN ) engine.switchSymbol( x + 1, y + 1 );
    else if ( right && engine.visibility( x + 1, y  ) == Spot::HIDDEN ) engine.switchSymbol( x + 1, y );
    else if ( down && right  && engine.visibility( x + 1, y - 1 ) == Spot::HIDDEN ) engine.switchSymbol( x + 1, y - 1 );
    else if ( down && engine.visibility( x , y - 1 ) == Spot::HIDDEN ) engine.switchSymbol( x , y - 1 );
    else if ( down && left && engine.visibility( x - 1, y - 1 ) == Spot::HIDDEN ) engine.switchSymbol( x - 1, y - 1 );
    else if ( left && engine.visibility( x - 1, y ) == Spot::HIDDEN ) engine.switchSymbol( x - 1, y );
}

int AIPlayer::countFlags( const int & x, const int & y ){
    int counter = 0;
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
    if ( x > 0 ) left = true;
    if ( x + 1 < engine.width() ) right = true;
    if ( y > 0 ) down = true;
    if ( y + 1 < engine.height() ) up = true;
    if ( up && left && engine.visibility( x - 1, y + 1) == Spot::FLAG  ) ++counter;
    if ( up && engine.visibility( x , y + 1 ) == Spot::FLAG  ) ++counter;
    if ( up && right && engine.visibility( x + 1, y + 1 ) == Spot::FLAG ) ++counter;
    if ( right && engine.visibility( x + 1, y  ) == Spot::FLAG ) ++counter;
    if ( down && right  && engine.visibility( x + 1, y - 1 ) == Spot::FLAG ) ++counter;
    if ( down && engine.visibility( x , y - 1 ) == Spot::FLAG  ) ++counter;
    if ( down && left && engine.visibility( x - 1, y - 1 ) == Spot::FLAG ) ++counter;
    if ( left && engine.visibility( x - 1, y ) == Spot::FLAG ) ++counter;
    return counter;
}

int AIPlayer::countHidden( const int & x, const int & y ){
    int counter = 0;
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
    if ( x > 0 ) left = true;
    if ( x + 1 < engine.width() ) right = true;
    if ( y > 0 ) down = true;
    if ( y + 1 < engine.height() ) up = true;
    if ( up && left && engine.visibility( x - 1, y + 1) == Spot::HIDDEN  ) ++counter;
    if ( up && engine.visibility( x , y + 1 ) == Spot::HIDDEN  ) ++counter;
    if ( up && right && engine.visibility( x + 1, y + 1 ) == Spot::HIDDEN ) ++counter;
    if ( right && engine.visibility( x + 1, y  ) == Spot::HIDDEN ) ++counter;
    if ( down && right  && engine.visibility( x + 1, y - 1 ) == Spot::HIDDEN  ) ++counter;
    if ( down && engine.visibility( x , y - 1 ) == Spot::HIDDEN  ) ++counter;
    if ( down && left && engine.visibility( x - 1, y - 1 ) == Spot::HIDDEN ) ++counter;
    if ( left && engine.visibility( x - 1, y ) == Spot::HIDDEN ) ++counter;
    return counter;
}
