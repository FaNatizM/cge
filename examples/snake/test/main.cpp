#include <iostream>

#include <cassert>

#include "CTest.h"




int main() {
    const auto test_passed
        = NSnake::f_Test();
    assert( test_passed == true );


    return 0;
}

