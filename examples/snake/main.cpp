#include <iostream>

#include <cassert>

#include <cge/CCGEEngine.h>
#include "CRules.h"




using namespace NCGE;




int main() {
    const auto test_passed
        = NSnake::f_Test();
    assert( test_passed == true );


    /*
    CGame game;
    CEngine test( game );
    test.f_Exec();
    */


    return 0;
}

