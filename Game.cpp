#include "Game.h"

void resultInfo ( Engine & engine ){
	std::cout << std::endl;
	if ( engine.stateVal() == Engine::WIN ){
		std::cout << std::endl << "Gratulacje! Wygrales! " ;
	} else 
		std::cout << std::endl << "BUM!" ;  
	std::cout << std::endl << "Enter"; 
	getchar();
	clearBuf();
}

void Game( const int & width, const int & height, const double & risk ){
	Engine engine( width, height, risk );
    	Pointer pointer( width, height );
    	Map map( engine, pointer );
    	Input input( engine, pointer );
    	while ( engine.stateVal() != Engine::WIN && engine.stateVal() != Engine::LOSE ){
		refresh( map );
		input.action();
    	}
	refresh( map );
	resultInfo ( engine );
}

void AIGame( const int & width, const int & height, const double & risk ){
	Engine engine( width, height, risk );
    	Pointer pointer( -1, -1 );
    	Map map( engine, pointer );
    	AIPlayer player ( engine );
    	while ( engine.stateVal() != Engine::WIN && engine.stateVal() != Engine::LOSE ){
		refresh( map );
        	player.move();
                usleep(500000);
    	}
	refresh( map );
	resultInfo( engine );
}

void refresh( Map & map ){
	clearScreen();
        map.draw();
}

void clearBuf ()
{
    char c;
    do
        c=getchar();
    while
    (c!='\n' && c!=EOF);
}
