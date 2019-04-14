//a
// Created by Jakub Kordel on 14.04.19.
//

#include "Map.h"

Map::Map ( Engine & Engine ) : engine(Engine) {
    width = engine.width();
    height = engine.height();
}

void Map::draw( int px, int py){
    for ( int i = 0; i < height ; ++i ){
        for ( int j = 0; j < width ; ++j ){
            if ( height - 1 - i == py ) {
                if ( px == j || px + 1 == j ) std::cout << '|';
                else std::cout << ' ';
            } else std::cout << ' ';
            if ( engine.visibility( j, height - 1 - i ) == Spot::VISIBLE ){
                if ( engine.type(j, height - 1 - i) == Spot::VALUE )
                    std::cout << engine.value(j, height - 1 - i);
                else
                    std::cout << 'B';
            }
            else {
                if ( engine.visibility(j, height - 1 - i) == Spot::HIDDEN )
                    std::cout << 'H';
                else if ( engine.visibility(j, height - 1 - i) == Spot::FLAG )
                    std::cout << 'F';
                else
                    std::cout << '?';
            }
            if ( px == width - 1 && height - 1 - i == py && j == width - 1 )
                std::cout << '|';
        }
        std::cout << std::endl;
    }
}