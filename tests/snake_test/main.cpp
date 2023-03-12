// Тест классов реализации змейки
//
#include <cassert>
#include <iostream>

#include "../../src/CWRDModelPoint.h"
#include "../../src/CWRDModelChain.h"
#include "../../src/CWRDViewer.h"
#include "../../src/CWRDItemsCreator.h"




bool f_TestItemsMoves() {
    std::cout
        << "\n\nf_TestItemsMoves()\n";


    auto scene
        = NGE::CScene( 3, 3 );
    auto location
        = NWRD::CLocation( 4, 4 );
    auto viewer
        = NWRD::CViewer(
            scene
            , location );

    const auto head = NWRD::CObject(
        CPoint( 0, 0 ), NGE::CTexture( 'x' ) );
    const auto body = NWRD::CObject(
        CPoint( 1, 0 ), head.f_GetTexture() );
    const auto tail = NWRD::CObject(
        CPoint( 2, 0 ), head.f_GetTexture() );
    const auto model
        = NWRD::CModelChain::f_Create(
            head, body, tail
        );
    auto snake_creator
        = NWRD::CItemsCreator(
            NWRD::TItemType::EUndefined
            , model
    );

    auto snake = snake_creator.f_Create();
    auto snake_id
        = location.f_AddItem( snake );

    std::cout << "snake: "
        << snake << std::endl;


    viewer.f_View();
    scene.f_Draw();


    // Проверка смещений
    auto f_Move
        = [ = ](
            NWRD::CLocation& a_location
            , const CPoint& a_point ) {
        assert( a_location.f_MoveItem(
            snake_id
            , a_point )
                == true );

        std::cout << "snake: "
            << snake << std::endl;

        assert(
            ( snake->f_GetPoint() == a_point )
                == true );


        viewer.f_View();
        scene.f_Draw();
    };


    f_Move( location, CPoint( 0, 2 ) );
    assert(
        ( snake->f_GetPoint( 1 ) == CPoint( 1, 2 ) )
            == true );
    assert(
        ( snake->f_GetPoint( 2 ) == CPoint( 2, 2 ) )
            == true );


    f_Move( location, CPoint( 0, 1 ) );
    assert(
        ( snake->f_GetPoint( 1 ) == CPoint( 0, 2 ) )
            == true );
    assert(
        ( snake->f_GetPoint( 2 ) == CPoint( 1, 2 ) )
            == true );


    f_Move( location, CPoint( 0, 0 ) );
    assert(
        ( snake->f_GetPoint( 1 ) == CPoint( 0, 1 ) )
            == true );
    assert(
        ( snake->f_GetPoint( 2 ) == CPoint( 0, 2 ) )
            == true );


    f_Move( location, CPoint( 1, 0 ) );
    assert(
        ( snake->f_GetPoint( 1 ) == CPoint( 0, 0 ) )
            == true );
    assert(
        ( snake->f_GetPoint( 2 ) == CPoint( 0, 1 ) )
            == true );


    f_Move( location, CPoint( 2, 1 ) );
    assert(
        ( snake->f_GetPoint( 1 ) == CPoint( 1, 1 ) )
            == true );
    assert(
        ( snake->f_GetPoint( 2 ) == CPoint( 1, 2 ) )
            == true );


    return true;
}



int main( void ) {
    f_TestItemsMoves();
}
