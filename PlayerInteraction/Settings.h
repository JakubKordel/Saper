//
// Created by Jakub Kordel on 18.04.19.
//

#ifndef SAPER_SETTINGS_H
#define SAPER_SETTINGS_H

#include "Pointer.h"


class Settings {
public:
	enum GameType { NORMAL, AI } ;

private:

	Pointer & pWidth;
	Pointer & pHeight;
	Pointer & pRisk;
	Pointer & pGameType;
	Pointer & pSetValue;

public:
	Settings ( Pointer & Width, Pointer & Height, Pointer & Risk, Pointer & GameType, Pointer & SetValue );
	int width;
	int height;
	double risk;
	GameType gameType;
	void set( char a ); 
};


#endif //SAPER_SETTINGS_H
