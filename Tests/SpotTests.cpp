//
// Created by Jakub Kordel on 30.03.19.
//

#include "SpotTests.h"

bool spotConstructorTest(){
    bool flag = true;
    Spot spot;
    if ( spot.getType() != Spot::VALUE || spot.getVisibility() != Spot::HIDDEN || spot.getBombsAround() )
        flag = false;
    return flag;
}

bool spotSetTypeTest(){
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

bool spotSetVisibilityTest(){
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

bool spotGetTypeTest(){
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

bool spotGetVisibilityTest(){
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

bool spotGetBombsAroundTest(){
    bool flag = true;
    Spot spot;
    if ( spot.getBombsAround() != 0 )
        flag = false;
    return flag;
}