#include "CTest.h"

#include <cassert>

#include "CRules.h"




namespace {
    bool f_TestMoveToWall();
    bool f_TestMoveCircle();
    bool f_TestEatingSelf();
}




bool NSnake::f_Test() {
    std::cout << "f_Test()" << std::endl;

    assert( f_TestMoveToWall() == true );
    assert( f_TestMoveCircle() == true );
    assert( f_TestEatingSelf() == true );


    return true;
}




namespace {
    using namespace NSnake;




    bool f_TestMoveToWall() {
        CGame game( SSize( 3, 3 ) );
        const auto snake = game
            .f_MoveSnake(
                EDirection::E_Top );
        const auto snake_head
            = snake.f_GetHead();
        const auto snake_body
            = snake.f_GetBody();

        assert( snake.f_GetLength()
            == 3 );
        assert( snake_body.front()
            == SPoint( 2, 0 ) );
        assert( snake_body.back()
            == SPoint( 1, 0 ) );
        assert( snake_head
            == SPoint( 2, -1 ) );

        assert( game.f_CheckState()
            == EGameState::E_Losed );

        return true;
    }



    bool f_TestMoveCircle() {
        CGame game( SSize( 3, 3 ) );

        auto snake = game
            .f_MoveSnake(
                EDirection::E_Bottom );
        assert( game.f_CheckState()
            == EGameState::E_IsBeing );
        std::cout << snake << std::endl;

        snake = game.f_MoveSnake(
            EDirection::E_Bottom );
        assert( game.f_CheckState()
            == EGameState::E_IsBeing );
        std::cout << snake << std::endl;

        game.f_MoveSnake(
            EDirection::E_Left );
        assert( game.f_CheckState()
            == EGameState::E_IsBeing );
        std::cout << snake << std::endl;

        game.f_MoveSnake(
            EDirection::E_Left );
        assert( game.f_CheckState()
            == EGameState::E_IsBeing );
        std::cout << snake << std::endl;

        game.f_MoveSnake(
            EDirection::E_Top );
        assert( game.f_CheckState()
            == EGameState::E_IsBeing );
        std::cout << snake << std::endl;

        game.f_MoveSnake(
            EDirection::E_Top );
        assert( game.f_CheckState()
            == EGameState::E_IsBeing );
        std::cout << snake << std::endl;

        game.f_MoveSnake(
            EDirection::E_Right );
        assert( game.f_CheckState()
            == EGameState::E_IsBeing );
        std::cout << snake << std::endl;

        snake = game.f_MoveSnake(
            EDirection::E_Right );
        assert( game.f_CheckState()
            == EGameState::E_IsBeing );

        std::cout << snake << std::endl;
        const auto snake_head
            = snake.f_GetHead();
        assert( snake_head.m_x == 2
            && snake_head.m_y == 0 );


        return true;
    }



    bool f_TestEatingSelf() {
        CGame game( SSize( 3, 3 ) );


        game.f_MakeFood(
            SPoint( 2, 1 ) );
        auto snake = game
            .f_MoveSnake(
                EDirection::E_Bottom );
        const auto snake_head
            = snake.f_GetHead();
        const auto snake_body
            = snake.f_GetBody();
        std::cout << snake << std::endl;

        assert( snake.f_GetLength()
            == 4 );
        assert( snake_body.front()
            == SPoint( 2, 0 ) );
        assert( snake_body.back()
            == SPoint( 0, 0 ) );
        assert( snake_head
            == SPoint( 2, 1 ) );

        assert( game.f_CheckState()
            == EGameState::E_IsBeing );


        game.f_MakeFood(
            SPoint( 1, 1 ) );
        snake = game
            .f_MoveSnake(
                EDirection::E_Left );
        snake = game
            .f_MoveSnake(
                EDirection::E_Top );
        std::cout << snake << std::endl;
        assert( game.f_CheckState()
            == EGameState::E_Losed );


        return true;
    }
}
