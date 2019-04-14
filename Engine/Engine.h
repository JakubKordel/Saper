//
// Created by Jakub Kordel on 30.03.19.
//

#ifndef SAPER_ENGINE_H
#define SAPER_ENGINE_H

#include "Field.h"
#include <cstdlib>
#include <ctime>

class Engine {
public:
    enum State { BEFORE, STARTED, WIN, LOSE }; // BEFORE - stan przed pierwszym wywolaniem unhide

private:
    Field * field;
    State state;
    int bombs;
    int flags;
    int widthX;
    int heightY;
    int hiddenValues;
    void setUpMap( int n, int x, int y ); // x, y wspolrzedne pierwszego punktu wybranegp przez uzytkownika
    void setUpBombs( int n, int x, int y ); // n - liczba pol wokol pierwszego punktu wybranego przez uzytkownika
    void setUpValues();
    int countBombsAround( int x, int y );

public:
    Engine( int width, int height, double risk ); // risk - wartosc 0-100, procent bomb na mapie
    // mala mapa ( mniejsza od 5x5 ) lub wysoka wartosc risk (wieksza od 70) moga spowodowac niewlasciwe zachowanie programu

    ~Engine();

    //Dla funkcji wczytujacych poczynanie gracza
    void unhide( int x, int y); //odkrywa pole wybrane przez gracza
    void switchSymbol( int x, int y ); // zakryte -> flaga -> znak ?

    // Dla funkcji wyswietlajacych mape
    Spot::Visibility visibility(int x, int y ); // zwraca wartosc pola: 0 - zakryte, 1 - odkryte, 2 - flaga, 3 - znak zapytania 
    Spot::Type type(int x, int y ); // zwraca: 0 - Bomba, 1 - pole bez bomby, z wartoscia
    int value( int x, int y );  //zwraca liczbe bomb dookola pola, 0-8
    int width();
    int height();
    //Informacje dla Gracza o stanie gry
    int bombsNum(); // ilosc bomb na mapie;
    int flagsNum(); // ilosc nieoflagowanych bomb
    State stateVal();
};


#endif //SAPER_ENGINE_H
