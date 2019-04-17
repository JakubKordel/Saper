//a
// Created by Jakub Kordel on 14.04.19.
//

#include "Map.h"


Map::Map ( Engine & Engine, Pointer & Pointer ) : engine(Engine), pointer( Pointer ){
    width = engine.width();
    height = engine.height();
}

void Map::draw(){
    std::cout << "Flags: " << engine.flagsNum() << std::endl << std::endl;
    std::cout << "klawisz l - odkrywa pole, klawisz p - zmienia pomiedzy X (flaga) -> ? -> O (zakryte) " << std::endl << std::endl ;
    for ( int i = 0; i < height ; ++i ){
        for ( int j = 0; j < width ; ++j ){
            if ( height - 1 - i == pointer.getY() ) {
                if ( pointer.getX() == j || pointer.getX() + 1 == j ) std::cout << '|';
                else std::cout << ' ';
            } else std::cout << ' ';
            if ( engine.visibility( j, height - 1 - i ) == Spot::VISIBLE ){
                if ( engine.type(j, height - 1 - i) == Spot::VALUE ){
		    if ( engine.value(j, height - 1 - i) == 0 )
		    	std::cout << ' ';			
                    else std::cout << engine.value(j, height - 1 - i);
		}
                else
                    std::cout << 'B';
            }
            else {
                if ( engine.visibility(j, height - 1 - i) == Spot::HIDDEN )
                    std::cout << 'O';
                else if ( engine.visibility(j, height - 1 - i) == Spot::FLAG )
                    std::cout << 'X';
                else
                    std::cout << '?';
            }
            if ( pointer.getX() == width - 1 && height - 1 - i == pointer.getY() && j == width - 1 )
                std::cout << '|';
        }
        std::cout << std::endl;
    }
}

void clearScreen(){
    printf("\033[2J");
    printf("\033[0;0f");
}
