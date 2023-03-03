#include "CWRDLocation.h"

#include <iostream>
#include <map>
#include <cassert>
#include <algorithm>




namespace NWRD {
    using TNodes = std::map<
        CPoint, TPlace >;

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
            TNodes m_places;
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
        = []( const TNode& a_node )
            -> void {
        std::cout << a_node.first
            << ": "
            << a_node.second
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
        ->f_GetTexture();
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
        ->f_IsEmpty();
}



bool NWRD::CLocation::f_SetPlace(
    const CPoint& a_point
    , const TPlace& a_place ) {
    const auto node
        = m_impl->m_places.find(
            a_point );
    if ( a_place == nullptr ) {
        return false;
    }

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


    auto item
        = item_node->second;

    // Проверки возможности движения
    if ( f_ExistPlace( a_point )
        == false ) {
        return false;
    }

    // Задаём позицию предмету
    if ( item.f_Move( a_point )
        == false ) {
        return false;
    }

    // Занимаем место
    return m_impl->m_places[ a_point ]
        ->f_Take(
            item.f_GetObject() );
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
