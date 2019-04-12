//
// Created by jakub on 30.03.19.
//

#ifndef SAPER_FIELD_H
#define SAPER_FIELD_H

#include "../List/List.h"
#include "Spot.h"

class Field {
    List<List<Spot>> rows;
    int collumnsNum;
    int rowsNum;

    void initialize();

public:
    Field( const int collumns = 10, const int rows = 10);
    Spot & getSpot( int x, int y );
    int getCollumnsNum();
    int getRowsNum();
};


#endif //SAPER_FIELD_H
