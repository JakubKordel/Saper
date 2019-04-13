//
// Created by Jakub Kordel on 29.03.19.
//

#include "Tests.h"

void TEST( bool testingFun, std::string funName );

void START_TESTS(){
    std::cout << "TESTING PROGRAM" << std::endl << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;

    //List
    TEST( listConstructorTest(), "List<Type>::List()");
    TEST( listAddElementTest(), "void List<Type>::addElement(const Type &obj)");
    TEST( listDeleteElementTest(), "void deleteElement(std::size_t index)");
    TEST( listOperatorPlusTest(), "bool listOperatorPlusTest()");

    //Spot
    TEST( spotConstructorTest(), "Spot::Spot()" );
    TEST( spotSetTypeTest(), "Spot::setType()");
    TEST( spotSetVisibilityTest(), "Spot::setVisibility()" );
    TEST( spotGetTypeTest(), "Spot::getType()");
    TEST( spotGetVisibilityTest(), "Spot::getVisibility()" );
    TEST( spotGetBombsAroundTest(), "Spot::getBombsAround()" );

    //Field
    TEST( fieldConstructorTest(), "Field::Field()" );
    TEST( fieldInitializeTest(), "Field::initialize()");
    TEST( fieldGetSpotTest(), "Field::getSpot()");

    //Engine
    TEST( engineConstructorTest(), "Engine::Engine( int width, int high, double risk )");
    TEST( engineSetUpMapTest(), "void Engine::setUpMap( int startX, int startY )");
    TEST( engineBombsNumTest(), "int Engine::bombsNum()");
    TEST( engineFlagsNumTest(), "int Engine::flagsNum()");
    TEST( engineStateValTest(), "State Engine::stateVal()");
    TEST( engineUnhideTest(), "void Engine::unhide( int x, int y);");
    TEST( engineSwitchSymbolTest(), "void Engine::switchSymbol( int x, int y );");
    TEST( engineVisibilityTest(), "Spot::Visibility Engine::visibility(int x, int y);");
    TEST( engineTypeTest(), "Spot::Type Engine::type(int x, int y );");
}

void TEST( bool testingFun, const std::string funName ){
    std::string result;
    if ( testingFun )
        result = "SUCCEED";
    else
        result = "FAILED";
    std::cout << "IN FUNCTION:" << std::right << std::setw(50) << funName << std::right << std::setw(30) << result << std::endl;
}


