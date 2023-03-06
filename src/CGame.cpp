#include "CGame.h"

#include <iostream>
#include <cassert>

#include "CWRDItemsCreator.h"




struct CGame::SImpl {
    public:
        explicit SImpl()
            : m_location( NWRD::CLocation( 20, 20 ) )
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

            // Захватываем предмет обзорщиком
            m_viewer.f_CatchEntity( m_item );

            // Двигаем предмет
            auto point = CPoint( 0, 0 );
            assert( m_location.f_MoveItem(
                m_item.f_GetID()
                , point )
                    == true );


            // Создаём неподвижный предмет
            const auto food_creator
                = NWRD::CItemsCreator(
                    NWRD::TItemType::EUndefined
                    , NGE::CTexture( 'o' ) );

            auto food = food_creator.f_Create();

            // Добавление предмета на локацию
            assert( m_location.f_AddItem( food )
                == food.f_GetID() );

            // Двигаем предмет
            point = CPoint( 5, 8 );
            assert( m_location.f_MoveItem(
                food.f_GetID()
                , point )
                    == true );


            // Создаём ничто
            m_location.f_SetPlace(
                CPoint( 4, 4 )
                , NWRD::CPlace::f_MakeNowhere() );

            m_location.f_SetPlace(
                CPoint( 3, 4 )
                , NWRD::CPlace::f_MakeNowhere() );

            m_location.f_SetPlace(
                CPoint( 5, 4 )
                , NWRD::CPlace::f_MakeNowhere() );

            m_location.f_SetPlace(
                CPoint( 4, 3 )
                , NWRD::CPlace::f_MakeNowhere() );

            m_location.f_SetPlace(
                CPoint( 4, 5 )
                , NWRD::CPlace::f_MakeNowhere() );
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

    // Если предмет подходит близко к краю
    // просмотрщика, то сдвигаем просмотрщик
    const auto result = m_impl->m_location.f_MoveItem(
        m_impl->m_item.f_GetID()
        , CPoint(
            point.f_GetX()
            , point.f_GetY() - 1 ) );

    m_impl->m_viewer.f_MoveWithEntity();

    return result;
}



bool CGame::f_MoveLeft() {
    const auto point
        = m_impl->m_item.f_GetPoint();

    const auto result = m_impl->m_location.f_MoveItem(
        m_impl->m_item.f_GetID()
        , CPoint(
            point.f_GetX() - 1
            , point.f_GetY() ) );

    m_impl->m_viewer.f_MoveWithEntity();

    return result;
}



bool CGame::f_MoveRight() {
    const auto point
        = m_impl->m_item.f_GetPoint();

    const auto result = m_impl->m_location.f_MoveItem(
        m_impl->m_item.f_GetID()
        , CPoint(
            point.f_GetX() + 1
            , point.f_GetY() ) );

    m_impl->m_viewer.f_MoveWithEntity();

    return result;
}



bool CGame::f_MoveDown() {
    const auto point
        = m_impl->m_item.f_GetPoint();

    const auto result = m_impl->m_location.f_MoveItem(
        m_impl->m_item.f_GetID()
        , CPoint(
            point.f_GetX()
            , point.f_GetY() + 1 ) );

    m_impl->m_viewer.f_MoveWithEntity();

    return result;
}
