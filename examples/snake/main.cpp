#include <iostream>

#include <cassert>

#include <cge/CCGEEngine.h>
#include "CRules.h"




using namespace NCGE;




int main() {
    assert( NSnake::f_Test() == true );


    CGame game;
    CEngine test( game );
    test.f_Exec();


    return 0;
}

