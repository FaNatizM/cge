#include <cassert>

#include "../../src/CWRDDecoration.h"
#include "../../src/CWRDItemsCreator.h"
#include "../../src/CWRDUnit.h"




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

    object.f_SetPoint( CPoint( 1, 1 ) );
    assert(
        object.f_GetPoint().f_GetX() == 1 );


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



bool f_TestItemsCreator() {
    NWRD::CItemsCreator::f_Test();
    return true;
}



int main( void ) {
    f_TestObject();
    f_TestID();
    NWRD::CEntity::f_Test();
    NWRD::CItem::f_Test();
    NWRD::CDecoration::f_Test();
    NWRD::CUnit::f_Test();
    f_TestItemsCreator();
}
