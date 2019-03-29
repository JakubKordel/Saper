//
// Created by Jakub Kordel on 29.03.19.
//

#include "ListTests.h"
#include "iostream"

bool listConstructorTest ( ){
    bool flag = true;
    List <int> list ;
    if ( list.numberOfElements() != 0 ){
        flag = false;
        std::cout << "List/List.cpp:" << std::endl << "NumberOfElements is not 0 after creating object" << std::endl;
    }
    if ( &list[0] ){
        flag = false;
        std::cout << "Head is not NULL after creating object" << std::endl ;
    }
    return flag;
}

bool listAddElementTest(){
    bool flag = true;
    List <int> list;
    list.addElement( -1 );
    list.addElement( 2 );
    list.addElement( -3 );
    list.addElement( 4 );
    if ( list[0] != 4 || list[1] != -3 || list[2] != 2 || list[3] != -1  ){
        flag = false;
        std::cout << "List/List.cpp:" << "Objects were added wrong" << std::endl ;
    }
    if ( list.numberOfElements() != 4 ) {
        flag = false;
        std::cout << "List/List.cpp:" << "Number of elements is not correct" << std::endl ;
    }
    return flag;
}

bool listDeleteElementTest(){
    bool flag = true;
    List <int> list;
    list.addElement( -1 );
    list.addElement( 2 );
    list.addElement( -3 );
    list.deleteElement(2);
    list.deleteElement(0);
    if ( list[0] != 2  ){
        flag = false;
        std::cout << "List/List.cpp:" << "Objects were deleted wrong" << std::endl ;
    }
    if ( list.numberOfElements() != 1 ) {
        flag = false;
        std::cout << "List/List.cpp:" << "Number of elements is not correct" << std::endl ;
    }
    return flag;
}

bool listOperatorPlusTest(){
    bool flag = true;
    List <int> list1;
    List <int> list2;
    list1.addElement( 1 );
    list1.addElement( 2 );
    list2.addElement( 3 );
    list2.addElement( 4 );
    list2.addElement( 5 );
    list2.addElement( 6 );
    list1 = list1+list2;
    if ( list1[0] != 3 || list1[1] != 4 || list1[2] != 5 || list1[3] != 6 || list1[4] != 1 || list1[5] != 2  ){
        flag = false;
        std::cout << "List/List.cpp:" << "Operator + doesnt work correct" << std::endl ;
    }
    if ( list1.numberOfElements() != 6 ) {
        flag = false;
        std::cout << "List/List.cpp:" << "Number of elements after operator + is not correct" << std::endl ;
    }
    return flag;
}




