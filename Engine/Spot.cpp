//
// Created by Jakub Kordel on 30.03.19.
//

#include "Spot.h"

Spot::Spot(){
    setType();
    setVisibility();
    setBombsAround();
}

void Spot::setType( const Type & t ){
    type = t;
}

void Spot::setVisibility( const Visibility & vis ){
    visibility = vis;
}

void Spot::setBombsAround( const int & num ){
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
