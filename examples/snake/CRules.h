#ifndef CRULES_H
#define CRULES_H


#include <list>




namespace NSnake {
    struct SPoint {
        explicit SPoint(
            const int a_x = 0
            , const int a_y = 0 );

        bool operator == ( const SPoint& a_other ) const;
        bool operator != ( const SPoint& a_other ) const;
        bool operator< ( const SPoint& a_other ) const;


        int m_x = 0;
        int m_y = 0;
    };

    using TPoints = std::list< SPoint >;



    struct SSize {
        explicit SSize(
            const int a_width = 0
            , const int a_height = 0 )
            : m_width( a_width )
            , m_height( a_height ) {
        }


        int m_width;
        int m_height;
    };



    enum class EDirection {
        E_Left
        , E_Top
        , E_Right
        , E_Bottom
    };



    enum class ESnakeState {
        E_Alive
        , E_Died
    };
    class CSnake {
        public:
            explicit CSnake();

            ESnakeState f_GetState() const;
            EDirection f_GetCourse() const;
            const SPoint& f_GetHead() const;
            const TPoints& f_GetBody() const;
            int f_GetLength() const;

            void f_Move(
                const EDirection a_course );
            void f_Eat(
                const EDirection a_course );


        private:
            ESnakeState m_state;
            EDirection m_course;
            SPoint m_head;
            TPoints m_body;
            int m_length;
    };



    struct SFood {
        explicit SFood( const SPoint& a_position
            = SPoint() )
            : m_position( a_position ) {
        }


        SPoint m_position;
    };



    struct SLocation {
        explicit SLocation( const SSize& a_size )
            : m_size( a_size ) {
        }


        SSize m_size;
    };




    enum class EGameState {
        E_IsBeing
        , E_Losed
        , E_Won
    };
    class CGame {
        public:
            explicit CGame(
                const SSize& a_size );
            const CSnake& f_MoveSnake(
                const EDirection a_course );
            EGameState f_CheckState() const;


        private:
            CSnake m_snake;
            SLocation m_location;
            SFood m_food;
    };




    bool f_Test();
}




#endif
