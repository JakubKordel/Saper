#include <iostream>
#include <unistd.h>
#include "Game.h"
#include "./PlayerInteraction/Pointer.h"
#include "./PlayerInteraction/Settings.h"
#include <ctime>

char getch();



int main() {
	char a;
	Pointer width(66, 0 ) , height( 41, 0 ), risk ( 201, 0 ), gameType ( 3, 0 ), setValue ( 0, 4 );
	Settings settings( width, height, risk, gameType, setValue );
	setValue.down();
	srand( time( NULL ) );
	while ( a != 'q' ) {
		clearScreen();
		std::cout << "----------------------------------" << std::endl ;
		std::cout << "              SAPER" << std::endl;
		std::cout << "----------------------------------" << std::endl << std::endl ;
		std::cout << "Sterowanie w grze awsd" << std::endl ;
		std::cout << "USTAWIENIA" << std::endl << std::endl;
		std::cout << "Szerokosc:" << std::endl;
		if ( setValue.getY() == 3 )
			std::cout << " < ";
		else std::cout << "   ";
		std::cout << settings.width ;
		if ( setValue.getY() == 3 )
			std::cout << " > ";
		std::cout << std::endl << "Wysokosc:" << std::endl;
		if ( setValue.getY() == 2 )
			std::cout << " < ";
		else  std::cout << "   ";
		std::cout << settings.height;
		if ( setValue.getY() == 2 )
			std::cout << " > ";
		std::cout << std::endl << "Ryzyko:" << std::endl;
		if ( setValue.getY() == 1 )
			std::cout << " < ";
		else std::cout << "   ";
		std::cout << settings.risk ;
		if ( setValue.getY() == 1 )
			std::cout << " > ";
		std::cout << std::endl << "Typ gry:" << std::endl;
		if ( setValue.getY() == 0 )
			std::cout << " < ";
		else std::cout << "   ";
		if ( settings.gameType == Settings::NORMAL )
			std::cout << "Normalna" ;
		else if ( settings.gameType == Settings::AI )
			std::cout << "Rozgrywka komputera"; 
		else if ( settings.gameType == Settings::AITEST )
			std::cout << "Test komputera"; 
		if ( setValue.getY() == 0 )
			std::cout << " > ";
		std::cout << std::endl << std::endl ;
		std::cout << "g - uruchamia rozgrywke" << std::endl;
		std::cout << "q - aby opuscic gre " << std::endl;
		a = getch(); 
		settings.set( a );		
		if ( a == 'g' && settings.gameType == Settings::NORMAL )
			Game( settings.width, settings.height, settings.risk );
		else if ( a == 'g' && settings.gameType == Settings::AI )
			AIGame( settings.width, settings.height, settings.risk );
		else if ( a == 'g' && settings.gameType == Settings::AITEST )
			AIGameTest( settings.width, settings.height, settings.risk );
		 
        }
   	return 0;
}




