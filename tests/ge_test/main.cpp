#include <cassert>
#include <iostream>
#include <vector>

#include "../../src/CPoint.h"
#include "../../src/CGETexture.h"
#include "../../src/CGEScene.h"




bool f_TestPoint() {
    auto point_empty = CPoint();
    std::cout << "point: "
        << point_empty << std::endl;
    assert( point_empty.f_IsNull()
        == true );

    auto point_empty_1 = CPoint( 0 );
    std::cout << "point: "
        << point_empty_1 << std::endl;
    assert( point_empty_1.f_IsNull()
        == true );


    auto point = CPoint( 1, 0 );
    std::cout << "point: "
        << point << std::endl;

    assert( point.f_IsNull() == false );

    auto point_1 = point;
    std::cout << "point_1: "
        << point_1 << std::endl;
    assert( point_1.f_IsNull() == false );
    assert( point_1 == point );

    return true;
}



bool f_TestTexture() {
    NGE::CTexture texture_1( 'x' );
    auto texture_2 = NGE::CTexture( 'y' );
    auto texture = texture_1;


    std::vector< NGE::CTexture > textures
        = { texture_1
            , texture_2
            , texture };


    for ( auto texture : textures ) {
        texture.f_Draw();
    }


    return true;
}



void f_TestScene() {
    auto scene = NGE::CScene( 3, 3 );
    scene.f_Draw();

    std::cout << "empty point test\n";
    const auto point = CPoint();
    const auto x = NGE::CTexture( 'x' );
    assert( scene.f_SetTexture(
        point, x )
            == false );


    const auto point_incorrect
        = CPoint( 0, scene.f_GetWidth() );

    std::cout << "\nincorrect point test\n";
    const auto found_incorrect
        = scene.f_SetTexture(
            point_incorrect, x );
    assert( found_incorrect == false );


    std::cout << "\nset texture test\n";
    const auto point_01 = CPoint( 0, 1 );
    const auto found
        = scene.f_SetTexture(
            point_01, x );
    assert( found == true );

    std::cout << "\nget texture test\n";
    assert( x
        == scene.f_GetTexture(
            point_01 ) );

    scene.f_SetTexture(
        CPoint( 2, 2 )
        , NGE::CTexture( 'y' ) );
    scene.f_SetTexture(
        CPoint( 1, 2 )
        , NGE::CTexture( '1' ) );

    scene.f_Draw();
}



int main( int argc, char* argv[] ) {
    std::cout << argv[ 0 ]
        << std::endl << std::endl;

    f_TestPoint();
    f_TestTexture();
    f_TestScene();
}
