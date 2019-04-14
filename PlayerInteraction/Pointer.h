//
// Created by Jakub Kordel on 14.04.19.
//

#ifndef SAPER_POINTER_H
#define SAPER_POINTER_H


class Pointer {
public:
    const int width;
    const int height;
private:
    int x;
    int y;
public:
    Pointer( int widthX, int heightY );
    void left();
    void right();
    void up();
    void down();
    int getX();
    int getY();
};


#endif //SAPER_POINTER_H
