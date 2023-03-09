#include "CWRDEntity.h"

#include <cassert>
#include <vector>




namespace NWRD {
    struct CModelPoint::SImpl {
        public:
            explicit SImpl(
                const CObject&
                a_object );

            M_IMPL_MAKE_STRUCT(
                SImpl, TImpl )


        public:

            // Объект
            CObject m_object;
    };
}




NWRD::CModelPoint::SImpl::SImpl(
    const CObject& a_object )
    : m_object( a_object ) {
}




NWRD::CObject
NWRD::CModelPoint::f_GetObject(
    const int ) const {
    return
        m_impl->m_object;
}



CPoint
NWRD::CModelPoint::f_GetPoint(
    const int ) const {

    return
        m_impl->m_objects;
}



NGE::CTexture
NWRD::CModelPoint::f_GetTexture(
    const int ) const {
    return
        m_impl->m_object;
}



size_t NWRD::CModelPoint::f_GetObjectsCount()
    const {
    return 1;
}



bool NWRD::CModelPoint::f_Move(
    const CPoint& a_point ) {
    m_impl
        ->m_object.f_SetPoint( a_point );


    return true;
}



void NWRD::CModelPoint::f_Test() {
    auto entity = CModelPoint();
    std::cout << "entity: "
        << entity << std::endl;

    assert( entity.f_IsEmpty()
         == true );

    assert( entity.f_GetObject()
        .f_IsNull() == true );

    assert( entity.f_GetPoint()
        .f_IsNull() == true );

    assert( entity.f_GetTexture()
        .f_IsUndefined() == true );

    assert( entity.f_GetObjectsCount()
        == 0 );


    // Добавление объектов
    assert( entity.f_Move( CPoint( 1, 1 ) ) == false );

    CObject object_empty;
    entity.f_AddObject( object_empty );

    assert( entity.f_GetObjectsCount()
        == 1 );

    assert( entity.f_IsEmpty()
         == false );

    assert( entity.f_Move( CPoint( 1, 1 ) ) == true );
}



NWRD::CModelPoint::CModelPoint()
    : m_impl(
        SImpl::f_Create() ) {
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CModelPoint& a_entity ) {
    a_out << "ID: "
        << a_entity.f_GetID() << ": "
        << a_entity.f_GetObject();

    return a_out;
}
