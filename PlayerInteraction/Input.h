//
// Created by Jakub Kordel on 14.04.19.
//

#ifndef SAPER_INPUT_H
#define SAPER_INPUT_H

#include "../Engine/Engine.h"
#include "Pointer.h"

class Input {
    Engine & engine;
    Pointer & pointer;
public:

    Input ( Engine & Engine, Pointer & Pointer ) ;
    void action ();

};


#endif //SAPER_INPUT_H
