#include "CWRDModelPoint.h"

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



NWRD::CModelPoint::CModelPoint(
    const CObject& a_object )
    : CModel()
    , m_impl(
        SImpl::f_Create( a_object ) ) {
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
        m_impl->m_object.f_GetPoint();
}



TPoints
NWRD::CModelPoint::f_GetPoints() const {
    return { m_impl->m_object.f_GetPoint() };
}



NGE::CTexture
NWRD::CModelPoint::f_GetTexture(
    const int ) const {
    return
        m_impl->m_object.f_GetTexture();
}



bool
NWRD::CModelPoint::f_ContainsObject(
    const CObject& a_object ) const {
    return m_impl->m_object == a_object;
}



size_t
NWRD::CModelPoint::f_GetObjectsCount()
    const {
    return 1;
}



bool NWRD::CModelPoint::f_Loop(
    const TOperation& a_operation ) {
    return a_operation( m_impl->m_object );
}



TPoints NWRD::CModelPoint::f_CheckMove(
    const CPoint& a_point
    , TPoints& a_points_free ) const {

    a_points_free.clear();
    a_points_free.push_back(
        m_impl->m_object.f_GetPoint() );

    return TPoints( 1, a_point );
}



bool NWRD::CModelPoint::f_Move(
    const TPoints& a_points ) {
    m_impl
        ->m_object.f_SetPoint( a_points[ 0 ] );

    return true;
}



std::ostream&
NWRD::CModelPoint::f_Visual(
    std::ostream& a_out )
    const {
    a_out << "object: "
        << m_impl->m_object;
    return a_out;
}



void NWRD::CModelPoint::f_Test() {
    auto model = CModelPoint();
    std::cout << "model: "
        << model << std::endl;

    assert( model.f_GetObject()
        .f_IsNull() == true );

    assert( model.f_GetPoint()
        .f_IsNull() == true );

    assert( model.f_GetTexture()
        .f_IsUndefined() == true );

    assert( model.f_GetObjectsCount()
        == 1 );


    // Добавление объектов
    assert(
        model.f_Move( { CPoint( 1, 1 ) } )
        == true );

}
