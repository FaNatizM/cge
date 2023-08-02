#include "CCGEPoint.h"

#include "HCGEMacroses.h"




struct CPoint::SImpl {
    public:

        // explicit SImpl()
        //     : m_x( -1 )
        //     , m_y( -1 ) {
        // }

        explicit SImpl(
            const TCoord a_x
            , const TCoord a_y )
            : m_x( a_x )
            , m_y( a_y ) {
        }

        template< typename... Types >
        static TImpl f_Create(
            Types&& ... a_params ) {
            auto impl
                = std::make_unique<
                    SImpl >(
                        std::forward<
                            Types >( a_params ) ... );

            return impl;
        }


    public:
        TCoord m_x;
        TCoord m_y;
};




CPoint::CPoint(
    const TCoord a_x
    , const TCoord a_y )
    : m_impl( SImpl::f_Create(
        a_x, a_y ) ) {
}



M_IMPL_UNIQUE( CPoint, SImpl )



bool CPoint::operator==(
    const CPoint& a_other ) const {

    if ( f_GetX() != a_other.f_GetX() ) {
        return false;
    }

    if ( f_GetY() != a_other.f_GetY() ) {
        return false;
    }

    return true;
}



bool CPoint::operator<(
    const CPoint& a_other ) const {

    // std::cout << *this << " < "
    //    << a_other << std::endl;

    if ( f_GetY() < a_other.f_GetY() ) {
        return true;
    }

    if ( a_other.f_GetY() < f_GetY() ) {
        return false;
    }


    if ( f_GetX() < a_other.f_GetX() ) {
        return true;
    }

    return false;
}



bool CPoint::f_IsNull() const {
    if ( m_impl->m_x < 0 ) {
        return true;
    }

    if ( m_impl->m_y < 0 ) {
        return true;
    }

    return false;
}



TCoord CPoint::f_GetX() const {
    return m_impl->m_x;
}



TCoord CPoint::f_GetY() const {
    return m_impl->m_y;
}




bool f_IsAdjacent(
    const CPoint& a_left
    , const CPoint& a_right ) {
    auto delta_x
        = std::abs( a_left.f_GetX()
        - a_right.f_GetX() );

    auto delta_y
        = std::abs( a_left.f_GetY()
        - a_right.f_GetY() );

    return 1 == delta_x + delta_y;
}



std::ostream& operator<<(
    std::ostream& a_out
    , const CPoint& a_point ) {
    a_out << "(" << a_point.f_GetX()
        << ", " << a_point.f_GetY()
        << ")";

    return a_out;
}



std::ostream& operator<<(
    std::ostream& a_out
    , const TPoints& a_points ) {
    for ( auto point : a_points ) {
        a_out << point << " ";
    }
}
