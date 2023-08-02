#include "CRules.h"

#include <cassert>




using namespace NSnake;
namespace {
    constexpr auto C_SNAKE_LENGHT_MIN = 3;
    constexpr auto C_LOCATION_SIZE_MIN = 3;
}




SPoint::SPoint(
    const int a_x
    , const int a_y )
    : m_x( a_x )
    , m_y( a_y ) {
}



bool SPoint::operator == (
    const SPoint& a_other ) const {

    if ( m_y != a_other.m_y ) {
        return false;
    }

    if ( m_x != a_other.m_x ) {
        return false;
    }

    return true;
}



bool SPoint::operator != (
    const SPoint& a_other ) const {
    return ! ( *this == a_other );
}



bool SPoint::operator< (
    const SPoint& a_other ) const {

    if ( m_y < a_other.m_y ) {
        return true;
    }

    if ( a_other.m_y < m_y ) {
        return false;
    }


    if ( m_x < a_other.m_x ) {
        return true;
    }

    return false;
}



std::ostream& operator << (
    std::ostream& a_out
    , const SPoint& a_point ) {
    a_out << "( " << a_point.m_x
        << ", " << a_point.m_y << std::endl;
}




CSnake::CSnake()
    : m_state( ESnakeState::E_Alive )
    , m_course( EDirection::E_Right )
    , m_head( 2, 0 )
    , m_body()
    , m_length( C_SNAKE_LENGHT_MIN ) {
    m_body.push_front( SPoint( 0, 0 ) );
    m_body.push_front( SPoint( 1, 0 ) );
}



ESnakeState CSnake::f_GetState() const {
    return m_state;
}



EDirection CSnake::f_GetCourse() const {
    return m_course;
}



const SPoint& CSnake::f_GetHead() const {
    return m_head;
}



const TPoints& CSnake::f_GetBody() const {
    return m_body;
}



int CSnake::f_GetLength() const {
    return m_length;
}



namespace {
    SPoint& f_MoveSnakeHead(
        const EDirection a_course
        , SPoint& a_head );
}

void CSnake::f_Move(
    const EDirection a_course ) {
    m_course = a_course;

    m_body.push_front( m_head );
    m_body.pop_back();

    m_head = f_MoveSnakeHead( m_course, m_head );
}



void CSnake::f_Eat(
    const EDirection a_course ) {
    m_course = a_course;

    m_body.push_front( m_head );

    m_head = f_MoveSnakeHead( m_course, m_head );

    m_length++;
}



namespace {
    SPoint& f_MoveSnakeHead(
        const EDirection a_course
        , SPoint& a_head ) {
        if ( a_course == EDirection::E_Left ) {
            a_head = SPoint( a_head.m_x - 1, a_head.m_y );
        }

        if ( a_course == EDirection::E_Top ) {
            a_head = SPoint( a_head.m_x, a_head.m_y - 1 );
        }

        if ( a_course == EDirection::E_Right ) {
            a_head = SPoint( a_head.m_x + 1, a_head.m_y );
        }

        if ( a_course == EDirection::E_Bottom ) {
            a_head = SPoint( a_head.m_x, a_head.m_y + 1 );
        }

        return a_head;
    }
}



std::ostream& operator << (
    std::ostream& a_out
    , const CSnake& a_snake ) {
    const auto snake_head = a_snake.f_GetHead();
    a_out << "head: " << snake_head << std::endl;

    a_out << "body:" << std::endl;
    const auto body = a_snake.f_GetBody();
    for ( auto point : body ) {
        a_out << point << std::endl;
    }

    a_out << "length: " << a_snake.f_GetLength()
        << std::endl;
}




namespace {
    SSize f_FixLocationSize( const SSize& a_size ) {
        auto size = a_size;
        if ( size.m_width < C_LOCATION_SIZE_MIN ) {
            size.m_width = C_LOCATION_SIZE_MIN;
        }

        if ( size.m_height < C_LOCATION_SIZE_MIN ) {
            size.m_height = C_LOCATION_SIZE_MIN;
        }


        return size;
    }
}

CGame::CGame( const SSize& a_size )
    : m_snake()
    , m_location( SLocation( a_size ) )
    , m_food( SPoint( -1, -1 ) ) {
}



const CSnake& CGame::f_MoveSnake(
    const EDirection a_course ) {

    auto snake_head = m_snake.f_GetHead();
    snake_head = f_MoveSnakeHead(
        a_course
        , snake_head );
    if ( snake_head == m_food.m_position ) {
        m_snake.f_Eat( a_course );
    } else {
        m_snake.f_Move( a_course );
    }

    return m_snake;
}



EGameState CGame::f_CheckState() const {
    const auto snake_head = m_snake.f_GetHead();
    if ( m_location.m_size.m_width <= snake_head.m_x
        || m_location.m_size.m_height <= snake_head.m_y
        || snake_head.m_x < 0
        || snake_head.m_y < 0 ) {
        return EGameState::E_Losed;
    }


    // Проверка поедания самой себя?


    if ( m_snake.f_GetLength() ==
        m_location.m_size.m_width
            * m_location.m_size.m_height ) {
        return EGameState::E_Won;
    }

    return EGameState::E_IsBeing;
}




bool NSnake::f_Test() {
    {
        CGame game( SSize( 3, 3 ) );
        const auto snake = game.f_MoveSnake(
            EDirection::E_Top );
        const auto snake_head
            = snake.f_GetHead();
        const auto snake_body
            = snake.f_GetBody();

        assert( snake.f_GetLength() == 3 );
        assert( snake_body.front().m_x == 2
            && snake_body.front().m_y == 0 );
        assert( snake_body.back().m_x == 1
            && snake_body.back().m_y == 0 );
        assert( snake_head.m_x == 2
            && snake_head.m_y == -1 );

        assert( game.f_CheckState()
            == EGameState::E_Losed );
    }


    {
        CGame game( SSize( 3, 3 ) );
        const auto snake = game.f_MoveSnake(
            EDirection::E_Bottom );
        assert( game.f_CheckState()
            == EGameState::E_IsBeing );

        game.f_MoveSnake(
            EDirection::E_Bottom );
        assert( game.f_CheckState()
            == EGameState::E_IsBeing );

        game.f_MoveSnake(
            EDirection::E_Left );
        assert( game.f_CheckState()
            == EGameState::E_IsBeing );

        game.f_MoveSnake(
            EDirection::E_Left );
        assert( game.f_CheckState()
            == EGameState::E_IsBeing );

        game.f_MoveSnake(
            EDirection::E_Top );
        assert( game.f_CheckState()
            == EGameState::E_IsBeing );

        game.f_MoveSnake(
            EDirection::E_Top );
        assert( game.f_CheckState()
            == EGameState::E_IsBeing );

        game.f_MoveSnake(
            EDirection::E_Right );
        assert( game.f_CheckState()
            == EGameState::E_IsBeing );

        game.f_MoveSnake(
            EDirection::E_Right );
        assert( game.f_CheckState()
            == EGameState::E_IsBeing );

        std::cout << snake.f_GetHead().m_x << std::endl;
        std::cout << snake.f_GetHead().m_y << std::endl;
        const auto snake_head
            = snake.f_GetHead();
        assert( snake_head.m_x == 2
            && snake_head.m_y == 0 );
    }

    return true;
}
