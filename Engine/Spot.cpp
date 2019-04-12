//
// Created by Jakub Kordel on 30.03.19.
//

#include "Spot.h"

Spot::Spot(){
    setType();
    setVisibility();
    setBombsAround();
}

void Spot::setType( Type t ){
    type = t;
}

void Spot::setVisibility( Visibility vis ){
    visibility = vis;
}

void Spot::setBombsAround( int num ){
    bombs = num;
}

Spot::Type Spot::getType(){
    return type;
}

Spot::Visibility Spot::getVisibility(){
    return visibility;
}

int Spot::getBombsAround(){
    return bombs;
}