//
// Created by Jakub Kordel on 14.04.19.
//

#ifndef SAPER_MAP_H
#define SAPER_MAP_H

#include <iostream>
#include "../Engine/Engine.h"
#include "Pointer.h"

class Map {

    Engine & engine;
    Pointer & pointer;
    int width;
    int height;

public:
    Map ( Engine & Engine, Pointer & Pointer );
    void draw(); // px, py wspolrzedne pointera gracza
};

#endif //SAPER_MAP_H
