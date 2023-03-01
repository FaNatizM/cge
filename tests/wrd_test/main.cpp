#include <cassert>
#include <iostream>

#include "../../src/CWRDViewer.h"




bool f_TestPlace() {
    auto nowhere
        = NWRD::CPlace::f_MakeNowhere();

    auto nowhere_1
        = NWRD::CPlace::f_MakeNowhere();
    assert( nowhere.use_count() == 3 );

    std::cout << nowhere_1 << std::endl;


    auto ground
        = NWRD::CPlace::f_MakeGround();
    assert( ground.use_count() == 2 );

    std::cout << ground << std::endl;


    return true;
}



bool f_TestLocation() {
    auto location
        = NWRD::CLocation( 3, 3 );
    std::cout << location << std::endl;


    auto nowhere
        = NWRD::CPlace::f_MakeNowhere();
    location.f_SetPlace(
        CPoint( 1, 1 ), nowhere );
    std::cout << location << std::endl;

    assert( nowhere->f_IsEmpty()
        == location.f_IsEmpty(
            CPoint( 1, 1 ) ) );


    assert( location.f_ExistPlace(
        CPoint() ) == false );

    assert( location.f_ExistPlace(
        CPoint( 0, 0 ) ) == true );


    return true;
}



bool f_TestViewerSmall() {
    std::cout
        << "\n\nf_TestViewerSmall()\n";
    auto scene
        = NGE::CScene( 3, 3 );
    auto location
        = NWRD::CLocation( 4, 4 );
    auto viewer
        = NWRD::CViewer(
            scene
            , location );

    auto nowhere
        = NWRD::CPlace::f_MakeNowhere();
    location.f_SetPlace(
        CPoint( 1, 2 ), nowhere );

    viewer.f_View();
    scene.f_Draw();

    assert( viewer.f_SetPoint(
        CPoint( 1, 1 ) )
            == true );
    viewer.f_View();
    scene.f_Draw();


    assert( viewer.f_SetPoint(
        CPoint( -1, 1 ) )
            == false );

    assert( viewer.f_SetPoint(
        CPoint( 10, 1 ) )
            == false );

    assert( viewer.f_MoveUp()
        == true );

    assert( viewer.f_MoveLeft()
        == true );

    assert( viewer.f_MoveRight()
        == true );

    assert( viewer.f_MoveDown()
        == true );

    assert( viewer.f_MoveDown()
        == false );


    return true;
}



bool f_TestViewerBig() {
    std::cout
        << "\n\nf_TestViewerBig()\n";


    auto scene
        = NGE::CScene( 4, 4 );
    auto location
        = NWRD::CLocation( 3, 4 );
    auto viewer
        = NWRD::CViewer(
            scene
            , location );

    auto nowhere
        = NWRD::CPlace::f_MakeNowhere();
    location.f_SetPlace(
        CPoint( 0, 0 ), nowhere );

    viewer.f_View();
    scene.f_Draw();

    assert( viewer.f_SetPoint(
        CPoint( 1, 1 ) )
            == false );
    viewer.f_View();
    scene.f_Draw();


    return true;
}



int main( void ) {
    f_TestPlace();
    f_TestLocation();
    f_TestViewerSmall();
    f_TestViewerBig();
}
