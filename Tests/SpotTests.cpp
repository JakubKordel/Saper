//
// Created by Jakub Kordel on 30.03.19.
//

#include "SpotTests.h"

bool SpotConstructorTest(){
    bool flag = true;
    Spot spot;
    if ( spot.getType() != Spot::VALUE || spot.getVisibility() != Spot::HIDDEN || spot.bombsAround() )
        flag = false;
    return flag;
}

bool SpotSetTypeTest(){
    bool flag = true;
    Spot spot1;
    Spot spot2;
    spot1.setType( Spot::BOMB );
    spot2.setType( Spot::BOMB );
    spot1.setType( Spot::VALUE );
    if ( spot1.getType() != Spot::VALUE || spot2.getType() != Spot::BOMB )
        flag = false;
    return flag;
}

bool SpotSetVisibilityTest(){
    bool flag = true;
    Spot spot1;
    Spot spot2;
    Spot spot3;
    Spot spot4;
    spot1.setVisibility( Spot::VISIBLE );
    spot2.setVisibility( Spot::HIDDEN );
    spot3.setVisibility( Spot::QUESTION );
    spot4.setVisibility( Spot::FLAG );
    if ( spot1.getVisibility() != Spot::VISIBLE || spot2.getVisibility() != Spot::HIDDEN || spot3.getVisibility() != Spot::QUESTION || spot4.getVisibility() != Spot::FLAG )
        flag = false;
    return flag;
}

bool SpotSetNeighborsTest(){
    bool flag = true;
    Spot middle;
    Spot spot[8];
    for ( int i = 4; i < 8 ; ++i ){
        spot[i].setType( Spot::BOMB );
    }
    spot[1].setType( Spot::BOMB) ;
    middle.setNeighbors( &spot[0], &spot[1], &spot[2], &spot[3], &spot[4], &spot[5], &spot[6], &spot[7] );
    if ( middle.bombsAround() != 5 )
        flag = false;
    return flag;
}

bool SpotGetTypeTest(){
    bool flag = true;
    Spot spot1;
    Spot spot2;
    spot1.setType( Spot::BOMB );
    spot2.setType( Spot::VALUE );
    Spot::Type type1 = spot1.getType();
    Spot::Type type2 = spot2.getType();
    if ( type1 != Spot::BOMB || type2 != Spot::VALUE)
        flag = false;
    return flag;
}

bool SpotGetVisibilityTest(){
    bool flag = true;
    Spot spot1;
    Spot spot2;
    Spot spot3;
    Spot spot4;
    spot1.setVisibility( Spot::VISIBLE );
    spot2.setVisibility( Spot::QUESTION );
    spot3.setVisibility( Spot::FLAG );
    spot4.setVisibility( Spot::HIDDEN );
    Spot::Visibility type1 = spot1.getVisibility();
    Spot::Visibility type2 = spot2.getVisibility();
    Spot::Visibility type3 = spot3.getVisibility();
    Spot::Visibility type4 = spot4.getVisibility();
    if ( type1 != Spot::VISIBLE || type2 != Spot::QUESTION || type3 != Spot::FLAG || type4 != Spot::HIDDEN )
        flag = false;
    return flag;

}

bool SpotBombsAroundTest(){
    bool flag = true;
    Spot middle;
    Spot spot[8];
    for ( int i = 2; i < 6 ; ++i ){
        spot[i].setType( Spot::BOMB );
    }
    middle.setNeighbors( &spot[0], &spot[1], &spot[2], &spot[3], &spot[4], &spot[5], &spot[6], &spot[7] );
    if ( middle.bombsAround() != 4 )
        flag = false;
    return flag;
}