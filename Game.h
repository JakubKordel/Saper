#include <iostream>
#include "Engine/Engine.h"
#include "PlayerInteraction/Map.h"
#include "PlayerInteraction/Input.h"
#include "PlayerInteraction/Pointer.h"
#include "AIPlayer/AIPlayer.h"
#include <unistd.h>

void Game ( const int & width, const int & height, const double & risk );
void AIGame( const int & width, const int & height, const double & risk );

void clearBuf();
void clearScreen();
void refresh( Map & map);
