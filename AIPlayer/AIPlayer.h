//
// Created by Jakub Kordel on 17.04.19.
//

#ifndef SAPER_AIPLAYER_H
#define SAPER_AIPLAYER_H

#include "../Engine/Engine.h"
#include <cstdlib>
#include <ctime>

class AIPlayer {

    Engine & engine;
    bool findFree();
    bool findBomb();
    void unhide( const int & x, const int & y );// Odkrywa jedno zakryte pole wokol punktu x,y
    void setFlag( const int & x, const int & y );// Ustawia flage na jednym z zakrytych pol wokol x, y
    void shoot();
    int countNotHidden( const int & x, const int & y );
    int countFlags( const int & x, const int & y );
    int countHidden( const int & x, const int & y );

public:
    AIPlayer( Engine & Engine );
    void move();
};


#endif //SAPER_AIPLAYER_H
