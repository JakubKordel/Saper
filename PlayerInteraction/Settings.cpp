//
// Created by Jakub Kordel on 18.04.19.
//

#include "Settings.h"

Settings::Settings ( Pointer & Width, Pointer & Height, Pointer & Risk, Pointer & GameType, Pointer & SetValue ) : pWidth( Width ), pHeight(Height), pRisk(Risk), pGameType(GameType), pSetValue(SetValue) {
	width = 5;
	height = 5;
	risk = 10;
	gameType = NORMAL ;
}

void Settings::set( char a ){
	if ( pSetValue.getY() == 3 ){
		if ( a == 'a' )
			pWidth.left();
		else if ( a == 'd')
			pWidth.right();
		width = 5 + pWidth.getX();	
	}
	else if ( pSetValue.getY() == 2 ){
		if ( a == 'a' )
			pHeight.left();
		else if ( a == 'd')
			pHeight.right();
		height = 5 + pHeight.getX();
	}

	else if ( pSetValue.getY() == 1 ){
		if ( a == 'a' )
			pRisk.left();
		else if ( a == 'd')
			pRisk.right();
		risk = 10 + ( double ) (pRisk.getX())/5;
	}

	else if ( pSetValue.getY() == 0 && ( a == 'a' || a == 'd' ) ){
		pGameType.right();
		if ( pGameType.getX() == 0 )
			gameType = NORMAL;
		else if ( pGameType.getX() == 1 )
			gameType = AI;
	}

	if ( a == 's' )
		pSetValue.down();
	else if ( a == 'w' )
		pSetValue.up();
}
