//
// Created by Jakub Kordel on 30.03.19.
//

#ifndef SAPER_SPOT_H
#define SAPER_SPOT_H


class Spot {
public:
    enum Type{ BOMB, VALUE };
    enum Visibility{ HIDDEN, VISIBLE, FLAG, QUESTION };

private:
    Type type;
    Visibility visibility;

    Spot * neighbour[8]; // clockwise order starting from up-left corner
    //  0 1 2  //
    //  7 T 3  // T - this one spot
    //  6 5 4  //

    int bombs;

public:
    Spot();
    void setType( Type =  VALUE );
    void setVisibility( Visibility = HIDDEN );
    void setNeighbors( Spot * ul, Spot * u, Spot * ur, Spot * r, Spot * dr, Spot * d, Spot * dl, Spot * l ); //clockwise order, ul - up/left corner
    Type getType();
    Visibility getVisibility();
    int bombsAround();
};


#endif //SAPER_SPOT_H
