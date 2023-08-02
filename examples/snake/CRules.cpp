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




CSnake::CSnake()
    : m_state( ESnakeState::E_Alive )
    , m_course( EDirection::E_Right )
    , m_head( 2, 0 )
    , m_body()
    , m_length( C_SNAKE_LENGHT_MIN ) {
    m_body.push_back( SPoint( 0, 0 ) );
    m_body.push_back( SPoint( 1, 0 ) );
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

    f_MoveSnakeHead( m_course, m_head );
}



void CSnake::f_Eat(
    const EDirection a_course ) {
    m_course = a_course;

    m_body.push_front( m_head );

    f_MoveSnakeHead( m_course, m_head );

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
    , m_food() {
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
        || 0 < snake_head.m_x
        || 0 < snake_head.m_y ) {
        return EGameState::E_Losed;
    }

    if ( m_snake.f_GetLength() ==
        m_location.m_size.m_width
            * m_location.m_size.m_height ) {
        return EGameState::E_Won;
    }

    return EGameState::E_IsBeing;
}




bool NSnake::f_Test() {
    CGame game( SSize( 3, 3 ) );
    game.f_MoveSnake( EDirection::E_Top );
    assert( game.f_CheckState() == EGameState::E_Losed );


    return true;
}
