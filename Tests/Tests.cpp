//
// Created by Jakub Kordel on 29.03.19.
//

#include "Tests.h"

void TEST( bool testingFun, const std::string funName );

void START_TESTS(){
    std::cout << "TESTING PROGRAM" << std::endl << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
    TEST( listConstructorTest(), "List<Type>::List()");
    TEST( listAddElementTest(), "void List<Type>::addElement(const Type &obj)");
    TEST( listDeleteElementTest(), "void deleteElement(std::size_t index)");
    TEST( listOperatorPlusTest(), "bool listOperatorPlusTest();");
}

void TEST( bool testingFun, const std::string funName ){
    std::string result;
    if ( testingFun )
        result = "SUCCEED";
    else
        result = "FAILED";
    std::cout << "IN FUNCTION:" << std::right << std::setw(50) << funName << std::right << std::setw(30) << result << std::endl;
}


