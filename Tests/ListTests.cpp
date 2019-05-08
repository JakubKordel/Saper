//
// Created by Jakub Kordel on 29.03.19.
//

#include "ListTests.h"
#include <iostream>

bool listConstructorTest ( ){
    bool flag = true;
    List <int> list ;
    if ( list.numberOfElements() != 0 ){
        flag = false;
    }
    if ( &list[0] ){
        flag = false;
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
    }
    if ( list.numberOfElements() != 4 ) {
        flag = false;
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
    }
    if ( list.numberOfElements() != 1 ) {
        flag = false;
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
    if ( list1[0] != 3 || list1[1] != 4 || list1[2] != 5 || list1[3] != 6 || list1[4] != 2 || list1[5] != 1  ){
       flag = false;
    }
    if ( list1.numberOfElements() != 6 ) {
        flag = false;
    }
    return flag;
}

bool listOperatorAtribbutionTest(){
    bool flag = true;
    List <int> list1;
    List <int> list2;
    list1.addElement( 1 );
    list1.addElement( 2 );
    list2.addElement( 3 );
    list2.addElement( 4 );
    list2.addElement( 5 );
    list2.addElement( 6 );
    list1 = list2;
    if ( list1[0] != 6 || list1[1] != 5 || list1[2] != 4 || list1[3] != 3 ){
        flag = false;
    }

    if ( list1.numberOfElements() != 4 ) {
        flag = false;
    }

    if ( list2[0] != 6 || list2[1] != 5 || list2[2] != 4 || list2[3] != 3 ){
        flag = false;
    }

    if ( list2.numberOfElements() != 4 ) {
        flag = false;
    }
    return flag;
}

bool listClearListTest(){
    bool flag = true;
    List <int> list1;
    List <int> list2;
    list1.addElement( 1 );
    list1.addElement( 2 );
    list2.addElement( 3 );
    list2.addElement( 4 );
    list2.addElement( 5 );
    list2.addElement( 6 );
    list1.clearList();
    list2.clearList();
    if ( list1.numberOfElements() != 0 ) {
        flag = false;
    }
    if ( list2.numberOfElements() != 0 ) {
        flag = false;
    }
    return flag;
}




