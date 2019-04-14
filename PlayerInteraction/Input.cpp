//
// Created by Jakub Kordel on 14.04.19.
//

#include <iostream>
#include "Input.h"
#include <unistd.h>
#include <termios.h>

char getch() {
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

Input::Input ( Engine & Engine, Pointer & Pointer ) : engine ( Engine ), pointer( Pointer)  {}

void Input::action (){
    char input;
    input = getch();
    if ( input == 'a' ) pointer.left();
    if ( input == 'd' ) pointer.right();
    if ( input == 's' ) pointer.down();
    if ( input == 'w' ) pointer.up();
    if ( input == 'l' ) engine.unhide( pointer.getX(), pointer.getY());
    if ( input == 'p' ) engine.switchSymbol( pointer.getX(), pointer.getY());
}