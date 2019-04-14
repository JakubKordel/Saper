//
// Created by Jakub Kordel on 14.04.19.
//

#ifndef SAPER_MAP_H
#define SAPER_MAP_H

#include <iostream>
#include "../Engine/Engine.h"

class Map {

    Engine & engine;
    int width;
    int height;


public:
    Map ( Engine & Engine );
    void draw( int px, int py ); // px, py wspolrzedne pointera gracza
};

#endif //SAPER_MAP_H
