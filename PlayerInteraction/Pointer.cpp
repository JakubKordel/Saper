//
// Created by Jakub Kordel on 14.04.19.
//

#include "Pointer.h"

Pointer::Pointer( int widthX, int heightY  ) : width(widthX), height(heightY) {
    x = 0;
    y = 0;
}

void Pointer::left(){
    if ( x > 0 ) --x;
    else x = width - 1;
}

void Pointer::right(){
    if ( x < width - 1) ++x;
    else x = 0;
}

void Pointer::up(){
    if ( y < height - 1 ) ++y;
    else y = 0;
}

void Pointer::down(){
    if ( y > 0 ) --y;
    else y = height - 1;
}

int Pointer::getX(){
    return x;
}

int Pointer::getY(){
    return y;
}
