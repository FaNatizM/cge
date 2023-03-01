#include <cassert>

#include "../../src/CWRDEntityID.h"




bool f_TestID() {
    NWRD::CEntityID::f_Test();

    NWRD::CEntityID id;
    std::cout << "id: "
        << id << std::endl;


    return true;
}



int main( void ) {
    f_TestID();
}
