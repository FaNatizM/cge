#include "CCGEUICommand.h"

#include <iostream>




using namespace NCGE;
namespace NUI {
    class CCommandNothing : public CCommand {
        public:
            explicit CCommandNothing( const CGame& a_game )
                : CCommand( a_game ) {
            }

            bool f_Execute() override {
                return false;
            }
    };



    class CCommandExit : public CCommand {
        public:
            explicit CCommandExit( const CGame& a_game )
                : CCommand( a_game ) {
            }

            bool f_Execute() override {
                return false;
            }
    };



    class CCommandMove : public CCommand {
        public:
            explicit CCommandMove(
                const CGame& a_game
                , const EMoveSide& a_side )
                : CCommand( a_game )
                , m_move_side( a_side ) {
            }

            bool f_Execute() override;

        private:
            EMoveSide m_move_side;
    };
}



// Двигаем объект на карте
bool NUI::CCommandMove::f_Execute() {

    switch ( m_move_side ) {
        case EMoveSide::E_Bottom:
            f_GetGame().f_MoveDown();
            break;

        case EMoveSide::E_Top:
            f_GetGame().f_MoveUp();
            break;

        case EMoveSide::E_Right:
            f_GetGame().f_MoveRight();
            break;

        case EMoveSide::E_Left:
            f_GetGame().f_MoveLeft();
            break;

        default:

            std::cout << "error: undefined move side!" << std::endl;
            return false;
    }


    return true;
}




NUI::CCommand::CCommand( const CGame& a_game )
    : m_game( a_game ) {
}



CGame& NUI::CCommand::f_GetGame() {
    return m_game;
}



NUI::TCommand NUI::CCommand::f_Create( const CGame& a_game ) {
    return TCommand( new CCommandNothing( a_game ) );
}


NUI::TCommand NUI::CCommand::f_CreateExit( const CGame& a_game ) {
    return TCommand( new CCommandExit( a_game ) );
}



NUI::TCommand NUI::CCommand::f_Create(
    const CGame& a_game
    , const EMoveSide a_side ) {
    return TCommand( new CCommandMove( a_game, a_side ) );
}
