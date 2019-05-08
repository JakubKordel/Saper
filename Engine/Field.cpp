//
// Created by Jakub Kordel on 30.03.19.
//

#include "Field.h"

void Field::initialize(){
    Spot spot;
    List<Spot> row;
    for ( int j = 0 ; j < collumnsNum ; ++j ) {
	row.addElement( spot );
    }

    for ( int i = 0 ; i < rowsNum ; ++i ) {
        rows.addElement( row );
    }
}

Field::Field( const int & collumns, const int & rows ){
    collumnsNum = collumns;
    rowsNum = rows;
    initialize();
}

Spot & Field::getSpot( const int & x, const int & y ){
    return rows[y][x];
}

int Field::getCollumnsNum(){
    return collumnsNum;
}

int Field::getRowsNum(){
    return rowsNum;
}
