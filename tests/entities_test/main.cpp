#include <cassert>

#include "../../src/CWRDEntity.h"




bool f_TestObject() {
    auto point = CPoint( 0, 1 );
    auto texture = NGE::CTexture( 'x' );
    auto object
        = NWRD::CObject( point, texture );
    std::cout << "object: " << object
        << std::endl;

    assert( object.f_IsNull()
        == false );

    assert( point
        == object.f_GetPoint() );

    assert( texture
        == object.f_GetTexture() );


    auto object_empty = NWRD::CObject();
    assert( object_empty.f_IsNull()
        == true );


    return true;
}



bool f_TestID() {
    NWRD::CEntityID::f_Test();

    NWRD::CEntityID id;
    std::cout << "id: "
        << id << std::endl;


    return true;
}



int main( void ) {
    f_TestObject();
    f_TestID();
}
