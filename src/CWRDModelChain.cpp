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

            int f_Contains( const CObject& a_object ) {
                int counter = 0;
                for ( auto object : m_objects ) {
                    if ( object == a_object ) {
                        return counter;
                    }

                    counter++;
                }

                return -1;
            }

            CObject f_GetObject(
                const int a_index ) const;



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



NWRD::CObject
NWRD::CModelChain::SImpl::f_GetObject(
    const int a_index ) const {
    if ( a_index < 0 ) {
        return CObject::f_MakeNull();
    }

    if ( m_objects.size()
        <= a_index ) {
        return CObject::f_MakeNull();
    }

    return m_objects[ a_index ];
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
    const int a_index ) const {
    return m_impl->f_GetObject( a_index );
}



CPoint
NWRD::CModelChain::f_GetPoint(
    const int a_index ) const {
    return m_impl->f_GetObject( a_index )
            .f_GetPoint();
}



TPoints
NWRD::CModelChain::f_GetPoints() const {
    auto points = TPoints();
    for ( auto object : m_impl->m_objects ) {
        points.push_back( object.f_GetPoint() );
    }

    return points;
}



NGE::CTexture
NWRD::CModelChain::f_GetTexture(
    const int a_index ) const {
    return m_impl->f_GetObject( a_index )
        .f_GetTexture();
}



bool
NWRD::CModelChain::f_ContainsObject(
    const CObject& a_object ) const {
    return 0 <= m_impl->f_Contains( a_object );
}



size_t
NWRD::CModelChain::f_GetObjectsCount()
    const {
    return m_impl->m_objects.size();
}



bool NWRD::CModelChain::f_Loop(
    const TOperation& a_operation ) {

    for ( auto object : m_impl->m_objects ) {
        if ( a_operation( object ) == false ) {
            return false;
        }
    }

    return true;
}



TPoints NWRD::CModelChain::f_CheckMove(
    const CPoint& a_point
    , TPoints& a_points_free ) const {

    // Проверяем на смежную ли точку происходит перемещение
    // Если да, то объекты тела по цепочке
    // Например смещение в (1,2)
    //  012    012
    // 0x..   0...
    // 1xx.   1xxx
    // 2...   2...

    // Иначе, перемещаем тело как есть на новое место
    // Например смещение в (2,2)
    //  012    012
    // 0x..   0...
    // 1xx.   1.x.
    // 2...   2.xx


    // Смещение в никуда
    auto points = TPoints();
    a_points_free.clear();
    if ( a_point.f_IsNull() == true ) {
        for ( auto object : m_impl->m_objects ) {
            a_points_free.push_back(
                object.f_GetPoint() );
        }

        for ( auto object : m_impl->m_objects ) {
            points.push_back( CPoint() );
        }

        return points;
    }


    // Смещение куда-то
    const auto is_adjacent
        = f_IsAdjacent(
            m_impl->m_objects[ 0 ].f_GetPoint()
            , a_point );

    if ( is_adjacent == true ) {

        // Смещение в смежную точку
        a_points_free.push_back(
            m_impl->m_objects[ 2 ].f_GetPoint() );


        points.push_back(
            a_point );
        points.push_back(
            m_impl->m_objects[ 0 ].f_GetPoint() );
        points.push_back(
            m_impl->m_objects[ 1 ].f_GetPoint() );

        return points;
    }


    // Смещение в новую позицию
    // Вычисляем дельты
    const auto point_head
        = m_impl->m_objects[ 0 ].f_GetPoint();
    auto delta_x
        = std::abs( a_point.f_GetX()
            - point_head.f_GetX() );

    auto delta_y
        = std::abs( a_point.f_GetY()
            - point_head.f_GetY() );

    // Вычисляем коэффициенты
    if ( a_point.f_GetX() < point_head.f_GetX() ) {
        delta_x = delta_x * -1;
    }

    if ( a_point.f_GetY() < point_head.f_GetY() ) {
        delta_y = delta_y * -1;
    }

    // Вычисляем новые позиции
    for ( auto object : m_impl->m_objects ) {
        auto point
            = object.f_GetPoint();

        points.push_back(
            CPoint(
                point.f_GetX() + delta_x
                , point.f_GetY() + delta_y ) );
    }


    // Вычисляем освободившиеся точки
    for ( auto object : m_impl->m_objects ) {
        auto point_old = object.f_GetPoint();
        auto taken = false;
        for ( auto point_new : points ) {
            taken = point_old
                == point_new;
        }

        if ( taken == false ) {
            a_points_free.push_back(
                    point_old );
        }
    }


    return points;
}



bool NWRD::CModelChain::f_Move(
    const TPoints& a_points ) {

    if ( a_points.size()
        != m_impl->m_objects.size() ) {
        return false;
    }


    auto counter = 0;
    for ( auto& object : m_impl->m_objects ) {
        object.f_SetPoint( a_points[ counter ] );
        counter++;
    }


    return true;
}



std::ostream&
NWRD::CModelChain::f_Visual(
    std::ostream& a_out )
    const {
    a_out << "[ ";
    for ( auto object : m_impl->m_objects ) {
        a_out << "object: " << object << "; ";
    }

    a_out << " ]";

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
