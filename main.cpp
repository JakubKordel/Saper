#include <iostream>
#include "Tests/Tests.h"
#include "Engine/Engine.h"
#include "PlayerInteraction/Map.h"
#include "PlayerInteraction/Input.h"
#include "PlayerInteraction/Pointer.h"
#include "AIPlayer/AIPlayer.h"
#include <unistd.h>

char getch();
void clearScreen();
void clearBuf();

int main() {
	char a;
	int y = 0;
	int width;
	int height;
	int risk;
	while ( a != 'q' ) {
		clearScreen();
		std::cout << "----------------------------------" << std::endl ;
		std::cout << "              SAPER" << std::endl;
		std::cout << "----------------------------------" << std::endl << std::endl ;
		std::cout << "Sterowanie w grze awsd" << std::endl ;
		std::cout << "Wybierz poziom trudnosci:" << std::endl << std::endl;
		if ( y == 0 ) std::cout << " -> ";
		std::cout << "Latwy" << std::endl;
		if ( y == 1 ) std::cout << " -> ";
		std::cout << "Sredni" << std::endl;
		if ( y == 2 ) std::cout << " -> ";
		std::cout << "Trudny" << std::endl << std::endl;
		std::cout << "g - graj" << std::endl;
		std::cout << "q - oposc gre" << std::endl;
		a = getch();
		if ( a == 's' ) {
			if ( y < 2 ) ++y; }
		else if ( a == 'w' ) { 
			if ( y > 0 ) --y; }
		else if ( a == 'g' ){
			if ( y == 0 ){
				width = 7;
				height = 7;
				risk = 16;
			}
			else if ( y == 1 ){
				width = 14;
				height = 10;
				risk = 18;
			}	
			else if ( y == 2 ){
				width = 20;
				height = 15;
				risk = 20;
			}				
			Engine engine( width, height, risk );
    			Pointer pointer( width, height );
    			Map map( engine, pointer );
    			//Input input( engine, pointer );
    			AIPlayer player ( engine );
    			while ( engine.stateVal() != Engine::WIN && engine.stateVal() != Engine::LOSE ){
				    clearScreen();
        			map.draw();
				//input.action();
        			player.move();
                    		usleep(200000);
    			}
			clearScreen();
        		map.draw();
			std::cout << std::endl;
			if ( engine.stateVal() == Engine::WIN ){
				std::cout << std::endl << "Gratulacje! Wygrales! " ;
			} else 
				std::cout << std::endl << "BUM!" ;  
			std::cout << std::endl << "Enter"; 
			getchar();
			clearBuf();
		} 
        }
   	return 0;
}

void clearBuf ()
{
    char c;
    do
        c=getchar();
    while
    (c!='\n' && c!=EOF);
}
