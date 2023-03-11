#include "CWRDModelChain.h"

#include <cassert>
#include <vector>




namespace NWRD {
    using TObjects
        = std::vector< CObject >;




    struct CModelChain::SImpl {
        public:
            explicit SImpl(
                const CObject& a_head
                , const CObject& a_body
                , const CObject& a_tail
                );

            M_IMPL_MAKE_STRUCT(
                SImpl, TImpl )


        public:

            // Объекты
            TObjects m_objects;
    };
}




NWRD::CModelChain::SImpl::SImpl(
    const CObject& a_head
    , const CObject& a_body
    , const CObject& a_tail )
    : m_objects() {

    // Проверка смежности позиций
    // объектов
    m_objects.push_back( a_head );
    m_objects.push_back( a_body );
    m_objects.push_back( a_tail );
}



NWRD::CModelChain::CModelChain(
    const CObject& a_head
    , const CObject& a_body
    , const CObject& a_tail )
    : CModel()
    , m_impl(
        SImpl::f_Create(
            a_head
            , a_body
            , a_tail ) ) {
}



NWRD::CObject
NWRD::CModelChain::f_GetObject(
    const int ) const {
    return
        m_impl->m_objects[ 0 ];
}



CPoint
NWRD::CModelChain::f_GetPoint(
    const int ) const {

    return
        m_impl->m_objects[ 0 ]
            .f_GetPoint();
}



NGE::CTexture
NWRD::CModelChain::f_GetTexture(
    const int ) const {
    return
        m_impl->m_objects[ 0 ]
            .f_GetTexture();
}



size_t
NWRD::CModelChain::f_GetObjectsCount()
    const {
    return m_impl->m_objects.size();
}



bool NWRD::CModelChain::f_Loop(
    const TOperation& a_operation ) {

    // a_operation( m_impl->m_object );
    return true;
}



TPoints NWRD::CModelPoint::f_CheckMove(
    const CPoint& a_point )
    const {

    // Вычисляем новое положение каждого
    // объкта цепочки

    auto points = TPoints();

    points.push_back(
        m_impl->m_objects[ 0 ].f_GetPoint() );
    points.push_back(
        m_impl->m_objects[ 1 ].f_GetPoint() );
    points.push_back(
        m_impl->m_objects[ 2 ].f_GetPoint() );

    return points;
}



bool NWRD::CModelChain::f_Move(
    const TPoints& a_points ) {
    m_impl
        ->m_objects[ 0 ]
            .f_SetPoint( a_points[ 0 ] );

    return true;
}



std::ostream&
NWRD::CModelChain::f_Visual(
    std::ostream& a_out )
    const {
    a_out << "object: "
        << m_impl->m_objects[ 0 ];
    return a_out;
}



void NWRD::CModelChain::f_Test() {
    /*
    auto model = CModelChain();
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
        model.f_Move( CPoint( 1, 1 ) )
        == true );
    */
}
