#include <iostream>
#include "Tests/Tests.h"
#include "Engine/Engine.h"
#include "PlayerInteraction/Map.h"
/*
#include <unistd.h>
#include <termios.h>
*/
/*char getch() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror ("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror ("tcsetattr ~ICANON");
    return (buf);
}


void ClrScr(){
    printf("\033[2J"); // Czyści ekran
    printf("\033[0;0f"); // Ustawia kursor w lewym, górnym rogu
}*/

int main() {
	START_TESTS();
    Engine engine( 14, 10, 20 );
    Map map( engine );
    engine.unhide( 0, 9 );
    map.draw( 0, 0 );
   /* char a;
    a = getch();
    if ( a == 'a' ) {
        ClrScr();
        map.draw(0, 1);
    }*/
    return 0;
}
