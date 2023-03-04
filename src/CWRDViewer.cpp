#include "CWRDViewer.h"

#include <iostream>
#include <map>
#include <cassert>




namespace NWRD {
    struct CViewer::SImpl {
        public:
            explicit SImpl(
                const NGE::CScene&
                    a_scene
                , const CLocation&
                    a_location )
                : m_left_top(
                    CPoint( 0, 0 ) )
                , m_right_bottom(
                    CPoint() )
                , m_scene( a_scene )
                , m_location(
                    a_location ) {
                m_right_bottom
                    = f_ComputeRightBottom(
                        m_left_top );
            }

            M_IMPL_MAKE_STRUCT( SImpl, TImpl )

            CPoint
            f_ComputeRightBottom(
                const CPoint&
                a_left_top ) const;


        public:

            // Текущая позиция
            // обзорщика карты
            CPoint m_left_top;
            CPoint m_right_bottom;

            // Текущая сцена
            NGE::CScene m_scene;

            CLocation m_location;
    };
}




CPoint
NWRD::CViewer::SImpl::f_ComputeRightBottom(
    const CPoint& a_left_top ) const {
    const auto width
        = m_scene.f_GetWidth();
    const auto height
        = m_scene.f_GetHeight();
    const auto x = a_left_top.f_GetX();
    const auto y = a_left_top.f_GetY();

    return
        CPoint(
            x + width - 1
            , y + height - 1 );
}




NWRD::CViewer::CViewer(
    const NGE::CScene& a_scene
    , const CLocation& a_location )
    : m_impl(
        SImpl::f_Create(
            a_scene
            , a_location ) ) {
}



void NWRD::CViewer::f_View() const {

    // Позиционируем обзорщик
    // Обходим локацию,
    // чтобы задать сцену
    TOperation f_SetSceneNode
        = [ = ]( const TPlace& a_place )
            -> void {

        // Вычисляем координаты узла
        // обзорщика
        const auto point
            = CPoint(
                a_place.first.f_GetX()
                - m_impl->m_left_top
                    .f_GetX()
                , a_place.first.f_GetY()
                - m_impl->m_left_top
                    .f_GetY() );

        // Фильтр лишних точек
        if ( m_impl->m_scene.f_GetWidth()
            <= point.f_GetX() ) {
            return;
        }

        if ( point.f_GetX() < 0 ) {
            return;
        }

        if ( m_impl->m_scene.f_GetHeight()
            <= point.f_GetY() ) {
            return;
        }

        if ( point.f_GetY() < 0 ) {
            return;
        }


        // Задаём узел сцены
        m_impl->m_scene.f_SetTexture(
            point
            , a_place.second
                .f_GetTexture() );
    };


    const auto scene_width
        = m_impl->m_scene.f_GetWidth();
    const auto scene_height
        = m_impl->m_scene.f_GetHeight();
    const auto location_width
        = m_impl->m_location
            .f_GetWidth();
    const auto location_height
        = m_impl->m_location
            .f_GetHeight();

    if ( scene_width <= location_width
        && ( scene_height
            <= location_height ) ) {

        // Когда обзорщик меньше карты
        const auto begin
            = m_impl->m_left_top;
        const auto end
            = m_impl->m_right_bottom;


        // Задаём узлы сцены по
        // локации
        m_impl->m_location.f_Loop(
            f_SetSceneNode
            , begin
            , end );

        return;
    }


    // Обзорщик частично больше
    // Формируем сцену из локации
    m_impl->m_location.f_Loop(
        f_SetSceneNode );


    // Заполняем оставшуюся часть сцены
    // ничем
    const NGE::CScene::TOperation
    f_SetNowhere
        = [ = ](
            NGE::CScene::TNode&
            a_node ) {

        const auto nowhere
            = CPlace::f_MakeNowhere();

        const auto point
            = a_node.first;

        const auto location_width
            = m_impl->m_location
                .f_GetWidth();
        if ( location_width
            <= point.f_GetX() ) {
            a_node.second
                = nowhere
                    .f_GetTexture();
            return;
        }

        const auto location_height
            = m_impl->m_location
                .f_GetHeight();
        if ( location_height
            <= point.f_GetY() ) {
            a_node.second
                = nowhere
                    .f_GetTexture();
            return;
        }
    };


    m_impl->m_scene.f_Loop(
        f_SetNowhere );
}



void NWRD::CViewer::f_ViewAndDraw() const {
    f_View();
    m_impl->m_scene.f_Draw();
}



bool NWRD::CViewer::f_SetPoint(
    const CPoint& a_point ) {

    const auto exist
        = m_impl->m_location
            .f_ExistPlace(
                a_point );

    // Точки, куда хотим сдвинуть
    // обзорщика не существует
    if ( exist == false ) {
        return false;
    }


    if ( a_point.f_IsNull() ) {

        // Обзорщик вышел
        // за пределы карты
        return false;
    }


    const auto right_bottom
        = m_impl->f_ComputeRightBottom(
            a_point );

    const auto location_width
        = m_impl->m_location
            .f_GetWidth();

    if ( location_width
        <= right_bottom.f_GetX() ) {

        // Обзоршик вышел
        // за пределы карты
        return false;
    }

    const auto location_height
        = m_impl->m_location
            .f_GetHeight();

    if ( location_height
        <= right_bottom.f_GetY() ) {

        // Обзоршик вышел
        // за пределы карты
        return false;
    }


    // Сдвинуть есть куда
    // Меняем позицию обзорщика
    m_impl->m_left_top
        = a_point;

    m_impl->m_right_bottom
        = right_bottom;


    return true;
}



bool NWRD::CViewer::f_MoveUp() {
    const auto point
        = m_impl->m_left_top;
    return f_SetPoint(
        CPoint(
            point.f_GetX()
            , point.f_GetY() - 1 ) );
}



bool NWRD::CViewer::f_MoveLeft() {
    const auto point
        = m_impl->m_left_top;
    return f_SetPoint(
        CPoint(
            point.f_GetX() - 1
            , point.f_GetY() ) );
}



bool NWRD::CViewer::f_MoveRight() {
    const auto point
        = m_impl->m_left_top;
    return f_SetPoint(
        CPoint(
            point.f_GetX() + 1
            , point.f_GetY() ) );
}



bool NWRD::CViewer::f_MoveDown() {
    const auto point
        = m_impl->m_left_top;
    return f_SetPoint(
        CPoint(
            point.f_GetX()
            , point.f_GetY() + 1 ) );
}
