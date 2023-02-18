#include "CUI.h"

#include <memory>

#include "private/HKeyboard.hpp"




namespace NUI {
    class CCore;
    using TCore = std::shared_ptr< CCore >;



    class CCore {
        public:
            explicit CCore()
                : m_input( 0 ) {
            }

            TCommand f_ProcessInput( const CMap& a_map );


        private:

            // Пользовательский ввод
            int m_input;
    };




    static TCore f_Get() {
        static auto core = TCore( new CCore() );
        return core;
    }
}




NUI::TCommand NUI::CCore::f_ProcessInput( const CMap& a_map ) {

    // обработка действий пользователя
    // set_keypress();
    m_input = getch() + getch();


    if ( static_cast< KEYS >( m_input ) != KEYS::KEY_CONTROL ) {

        // Если клавиша не та, то генерируем команду выход
        // reset_keypress();
        return CCommand::f_CreateExit( a_map );
    }


    TCommand command;
    switch ( static_cast< KEYS >( getchar() ) ) {
        case KEYS::KEY_DOWN:
            command = CCommand::f_Create( a_map, EMoveSide::E_Bottom );
            break;

        case KEYS::KEY_UP:
            command = CCommand::f_Create( a_map, EMoveSide::E_Top );
            break;

        case KEYS::KEY_RIGHT:
            command = CCommand::f_Create( a_map, EMoveSide::E_Right );
            break;

        case KEYS::KEY_LEFT:
            command = CCommand::f_Create( a_map, EMoveSide::E_Left );
            break;

        default:

            // Пустая команда
            command = CCommand::f_Create( a_map );
            break;
    }

    //
    // reset_keypress();
    return command;
}



NUI::TCommand NUI::CUI::f_ProcessInput( const CMap& a_map ) {
    auto core = f_Get();
    return core->f_ProcessInput( a_map );
}
