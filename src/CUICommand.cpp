#include "CUICommand.h"

#include <iostream>




namespace NUI {
    class CCommandNothing : public CCommand {
        public:
            explicit CCommandNothing( const CMap& a_map )
                : CCommand( a_map ) {
            }

            bool f_Execute() override {
                return false;
            }
    };



    class CCommandExit : public CCommand {
        public:
            explicit CCommandExit( const CMap& a_map )
                : CCommand( a_map ) {
            }

            bool f_Execute() override {
                return false;
            }
    };



    class CCommandMove : public CCommand {
        public:
            explicit CCommandMove(
                const CMap& a_map
                , const EMoveSide& a_side )
                : CCommand( a_map )
                , m_move_side( a_side ) {
            }

            bool f_Execute() override;

        private:
            EMoveSide m_move_side;
    };
}



// Двигаем объект на карте
bool NUI::CCommandMove::f_Execute() {

    const auto map = f_GetMap();
    auto object = map.f_GetObject();

    switch ( m_move_side ) {
        case EMoveSide::E_Bottom:
            if ( object.f_GetYPos() < map.f_GetHeight() - 1 ) {
                object.f_SetYPos( object.f_GetYPos() + 1 );
            }

            break;

        case EMoveSide::E_Top:
            if ( object.f_GetYPos() > 0 ) {
                object.f_SetYPos( object.f_GetYPos() - 1);
            }

            break;

        case EMoveSide::E_Right:
            if ( object.f_GetXPos() < ( map.f_GetWidth() - 1 ) ) {
                object.f_SetXPos( object.f_GetXPos() + 1 );
            }

            break;

        case EMoveSide::E_Left:
            if ( object.f_GetXPos() > 0 ) {
                object.f_SetXPos( object.f_GetXPos() - 1 );
            }

            break;

        default:

            std::cout << "error: undefined move side!" << std::endl;
            return false;
    }


    return true;
}




NUI::CCommand::CCommand( const CMap& a_map )
    : m_map( a_map ) {
}



CMap& NUI::CCommand::f_GetMap() {
    return m_map;
}



NUI::TCommand NUI::CCommand::f_Create( const CMap& a_map ) {
    return TCommand( new CCommandNothing( a_map ) );
}


NUI::TCommand NUI::CCommand::f_CreateExit( const CMap& a_map ) {
    return TCommand( new CCommandExit( a_map ) );
}



NUI::TCommand NUI::CCommand::f_Create(
    const CMap& a_map
    , const EMoveSide a_side ) {
    return TCommand( new CCommandMove( a_map, a_side ) );
}
