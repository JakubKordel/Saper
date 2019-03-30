//
// Created by Jakub Kordel on 30.03.19.
//

#include "Spot.h"

Spot::Spot(){
    setType();
    setVisibility();
    setNeighbors( nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
}

void Spot::setType( Type t ){
    type = t;
}

void Spot::setVisibility( Visibility vis ){
    visibility = vis;
}

void Spot::setNeighbors( Spot * ul, Spot * u, Spot * ur, Spot * r, Spot * dr, Spot * d, Spot * dl, Spot * l ){
    neighbour[0] = ul;
    neighbour[1] = u;
    neighbour[2] = ur;
    neighbour[3] = r;
    neighbour[4] = dr;
    neighbour[5] = d;
    neighbour[6] = dl;
    neighbour[7] = l;
    int counter = 0;
    for ( int i = 0; i < 8 ; ++i ){
        if ( neighbour[i] != nullptr ) {
            if (neighbour[i]->getType() == BOMB)
                ++counter;
        }
    }
    bombs = counter;
}

Spot::Type Spot::getType(){
    return type;
}

Spot::Visibility Spot::getVisibility(){
    return visibility;
}

int Spot::bombsAround(){
    return bombs;
}