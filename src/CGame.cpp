#include "CGame.h"

#include <iostream>
#include <cassert>

#include "CWRDItemsCreator.h"




struct CGame::SImpl {
    public:
        explicit SImpl()
            : m_location( NWRD::CLocation( 10, 10 ) )
            , m_viewer( NWRD::CViewer( NGE::CScene( 10, 10 ), m_location ) )
            , m_item() {

            // Создание предмета, который будем двигать
            const auto item_creator
                = NWRD::CItemsCreator(
                    NWRD::TItemType::EUndefined
                    , NGE::CTexture( 'x' ) );

            m_item = item_creator.f_Create();

            // Добавление предмета на локацию
            assert( m_location.f_AddItem( m_item )
                == m_item.f_GetID() );

            // Двигаем предмет
            auto point = CPoint( 0, 0 );
            assert( m_location.f_MoveItem(
                m_item.f_GetID()
                , point )
                    == true );
        };

        M_IMPL_MAKE_STRUCT( SImpl, TImpl )


    public:

        // Локация
        NWRD::CLocation m_location;

        // Обзорщик карты
        NWRD::CViewer m_viewer;

        // То, что двигаем по карте
        NWRD::CItem m_item;
};




CGame::CGame()
    : m_impl(
        SImpl::f_Create() ) {
}



void CGame::f_ViewAndDraw() const {
    m_impl->m_viewer.f_ViewAndDraw();
}



bool CGame::f_MoveUp() {
    const auto point
        = m_impl->m_item.f_GetPoint();
    return m_impl->m_location.f_MoveItem(
        m_impl->m_item.f_GetID()
        , CPoint(
            point.f_GetX()
            , point.f_GetY() - 1 ) );
}



bool CGame::f_MoveLeft() {
    const auto point
        = m_impl->m_item.f_GetPoint();
    return m_impl->m_location.f_MoveItem(
        m_impl->m_item.f_GetID()
        , CPoint(
            point.f_GetX() - 1
            , point.f_GetY() ) );
}



bool CGame::f_MoveRight() {
    const auto point
        = m_impl->m_item.f_GetPoint();
    return m_impl->m_location.f_MoveItem(
        m_impl->m_item.f_GetID()
        , CPoint(
            point.f_GetX() + 1
            , point.f_GetY() ) );
}



bool CGame::f_MoveDown() {
    const auto point
        = m_impl->m_item.f_GetPoint();
    return m_impl->m_location.f_MoveItem(
        m_impl->m_item.f_GetID()
        , CPoint(
            point.f_GetX()
            , point.f_GetY() + 1 ) );
}
