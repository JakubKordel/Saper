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
    int bombs;

public:
    Spot();
    void setType( const Type & = VALUE );
    void setVisibility( const Visibility & = HIDDEN );
    void setBombsAround( const int & num = 0 );
    Type getType();
    Visibility getVisibility();
    int getBombsAround();
};


#endif //SAPER_SPOT_H
