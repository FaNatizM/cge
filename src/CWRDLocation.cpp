#include "CWRDLocation.h"

#include <iostream>
#include <map>
#include <cassert>
#include <algorithm>




namespace NWRD {
    using TPlaces = std::map<
        CPoint, CPlace >;

    using TItems = std::map<
        CEntityID, CItem >;




    struct CLocation::SImpl {
        public:
            explicit SImpl(
                const int a_width
                , const int a_height )
                : m_width( a_width )
                , m_height( a_height )
                , m_places()
                , m_items() {

                if ( m_width <= 0 ) {
                    m_width = 1;
                }

                if ( m_height <= 0 ) {
                    m_height = 1;
                }

                f_InitNodes();
            }

            M_IMPL_MAKE_STRUCT(
                SImpl, TImpl )

            void f_InitNodes();


        public:
            int m_width;
            int m_height;
            TPlaces m_places;
            TItems m_items;
    };
}




void NWRD::CLocation::SImpl::f_InitNodes() {
    auto size
        = m_width * m_height;
    for ( int row = 0
        ; row < m_height
        ; row++ ) {
        for ( int column = 0
            ; column < m_width
            ; column++ ) {

            const auto point
                = CPoint( column, row );
            const auto place
                = CPlace::f_MakeGround();
            m_places[ point ]
                = place;
        }
    }

    assert( m_places.size() == size );
}




NWRD::CLocation::CLocation(
    const int a_width
    , const int a_height )
    : m_impl(
        SImpl::f_Create(
            a_width
            , a_height ) ) {
}



NWRD::TOperation
NWRD::CLocation::f_GetVisualOperation() {
    static TOperation f_VisualNode
        = []( const TPlace& a_place )
            -> void {
        std::cout << a_place.first
            << ": "
            << a_place.second
            << std::endl;
    };

    return f_VisualNode;
}



int NWRD::CLocation::f_GetWidth() const {
    return m_impl->m_width;
}



int NWRD::CLocation::f_GetHeight()
    const {
    return m_impl->m_height;
}



bool NWRD::CLocation::f_ExistPlace(
    const CPoint& a_point
    ) const {
    auto node
        = m_impl->m_places.find(
            a_point );

    if ( node
        == m_impl->m_places.end() ) {
        return false;
    }


    return true;
}



NGE::CTexture
NWRD::CLocation::f_GetTexture(
    const CPoint& a_point )
    const {

    auto node
        = m_impl->m_places.find(
            a_point );

    if ( node
        == m_impl->m_places.end() ) {
        return NGE::CTexture();
    }


    return m_impl->m_places[ a_point ]
        .f_GetTexture();
}



bool NWRD::CLocation::f_IsEmpty(
    const CPoint& a_point ) const {

    std::cout << a_point << std::endl;

    const auto node
        = m_impl->m_places.find(
            a_point );

    if ( node
        == m_impl->m_places.end() ) {
        return false;
    }


    return m_impl->m_places[ a_point ]
        .f_IsEmpty();
}



bool NWRD::CLocation::f_SetPlace(
    const CPoint& a_point
    , const CPlace& a_place ) {
    const auto node
        = m_impl->m_places.find(
            a_point );

    if ( node
        == m_impl->m_places.end() ) {
        return false;
    }


    m_impl->m_places[ a_point ]
        = a_place;

    return true;
}



void NWRD::CLocation::f_Loop(
    const TOperation a_operation )
    const {
    std::for_each(
        m_impl->m_places.begin()
        , m_impl->m_places.end()
        , a_operation );
}



void NWRD::CLocation::f_Loop(
    const TOperation a_operation
    , const CPoint& a_begin
    , const CPoint& a_end )
    const {
    auto begin
        = m_impl
            ->m_places.find( a_begin );
    if ( begin
        == m_impl->m_places.end() ) {
        begin = m_impl->m_places.begin();
    }

    auto end
        = m_impl
            ->m_places.find( a_end );
    if ( end
        != m_impl->m_places.end() ) {

        // Переводим на следующий
        // за нужным элементом, т.к.
        // последний элемент цикл
        // не проходит
        end++;
    }

    std::for_each(
        begin
        , end
        , a_operation );
}



NWRD::CEntityID NWRD::CLocation::f_AddItem(
    const CItem& a_item ) {

    const auto id = a_item.f_GetID();
    m_impl->m_items[ id ] = a_item;

    return id;
}



NWRD::CItem NWRD::CLocation::f_GetItem(
    const NWRD::CEntityID& a_id ) const {
    auto item_node
        = m_impl->m_items.find(
            a_id );

    if ( item_node
        == m_impl->m_items.end() ) {
        return CItem();
    }


    return item_node->second;
}



bool NWRD::CLocation::f_MoveItem(
    const CEntityID& a_id
    , const CPoint& a_point ) {
    auto item_node
        = m_impl->m_items.find(
            a_id );

    if ( item_node
        == m_impl->m_items.end() ) {
        return false;
    }


    // Предмет существует
    // Проверки возможности движения
    // нет ли границы карты
    auto x = a_point.f_GetX();
    auto y = a_point.f_GetY();
    if ( x < 0 ) {
        x = 0;
    }

    if ( m_impl->m_width <= x ) {
        x = m_impl->m_width - 1;
    }

    if ( y < 0 ) {
        y = 0;
    }

    if ( m_impl->m_height <= y ) {
        y = m_impl->m_height - 1;
    }

    const auto point = CPoint( x, y );


    // Занятие нового места
    // Проверяем не занято ли оно
    auto& place =
        m_impl->m_places[ point ];

    if ( place.f_IsSpace() == false ) {

        // Место недоступно для объектов
        return false;
    }

    if ( place.f_IsEmpty() == false ) {

        // Место занято
        return false;
    }


    // Запоминаем предыдущую позицию предмета
    auto item
        = item_node->second;

        const auto item_point_perv
            = item.f_GetPoint();

    // Задаём позицию предмету
    if ( item.f_Move( point )
        == false ) {

        // Не удалось сместить объект
        return false;
    }


    // Занимаем место
    const auto taken
        = m_impl->m_places[ point ]
            .f_Take(
                item.f_GetObject() );


    // Освобождаем предыдущее место
    // если оно существует
    if ( taken == true ) {
        if ( f_ExistPlace( item_point_perv )
            == true ) {
            m_impl->m_places[
                item_point_perv ]
                    .f_Free();
        }
    }


    return taken;
}



void NWRD::CLocation::f_LoopItems(
    const TItemOperation a_operation )
    const {
    std::for_each(
        m_impl->m_items.begin()
        , m_impl->m_items.end()
        , a_operation );
}



std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CLocation&
        a_location ) {
    a_location.f_Loop(
        NWRD::CLocation
            ::f_GetVisualOperation() );


    return a_out;
}
