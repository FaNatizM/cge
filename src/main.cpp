#include <iostream>

#include "CEngine.h"




int main() {

    // ������� ������
    // getchar();


    CMapObject object;
    CMap map( '.', 20, 20, object );
    CEngine test( map );
    test.f_Exec();


    return 0;
}

