//
// Created by Jakub Kordel on 30.03.19.
//

#include "FieldTests.h"

bool fieldConstructorTest(){
    return fieldGetSpotTest();
}

bool fieldInitializeTest(){
    return fieldGetSpotTest();
}

bool fieldGetSpotTest(){
    bool flag = true;
    Field field ( 15, 8 );
    if ( field.getRowsNum() != 8 || field.getCollumnsNum() != 15 )
        flag = false;
    if ( field.getSpot( 14, 7 ).getType() != Spot::VALUE || field.getSpot( 5, 2).getVisibility() != Spot::HIDDEN )
        flag = false;
    return flag;
}
