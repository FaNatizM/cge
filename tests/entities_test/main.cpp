#include <cassert>

#include "../../src/CWRDDecoration.h"
#include "../../src/CWRDItemsCreator.h"
#include "../../src/CWRDUnit.h"
#include "../../src/CWRDModelPoint.h"




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
        object.f_GetPoint().f_GetX()
            == 1 );


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



bool f_TestItemsMoving() {
    const auto object = NWRD::CObject(
        CPoint()
        , NGE::CTexture( '1') );
    const auto model = NWRD::CModelPoint(
        object );
    std::cout << "model = "
        << model << std::endl;


    const auto item
        = NWRD::CItem::f_Create(
            NWRD::TItemType::EUndefined
            , model );

    std::cout << "item = "
        << item << std::endl;

    assert( item->f_IsEmpty() == false );

    assert(
        item->f_Move( CPoint( 1, 1 ) )
            == true );

    return true;
}



int main( void ) {
    f_TestObject();
    f_TestID();
    NWRD::CModel::f_Test();
    NWRD::CModelPoint::f_Test();
    NWRD::CEntity::f_Test();
    NWRD::CItem::f_Test();
    NWRD::CDecoration::f_Test();
    NWRD::CUnit::f_Test();
    f_TestItemsCreator();
    f_TestItemsMoving();
}
