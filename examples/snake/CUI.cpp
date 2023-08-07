#include "CUI.h"

#include <cge/HCGEKeyboard.hpp>




namespace NSnake {
    struct CCommandFactory::SImpl {
        public:
            explicit SImpl(
                const CGame& a_game )
                : m_game( a_game )
                , m_input( 0 ) {
            }

            M_MAKE_SHARED( SImpl, TImpl )


        public:
            CGame m_game;

            // Пользовательский ввод
            int m_input;
    };
}

using namespace NSnake;




CCommandFactory::CCommandFactory(
    const CGame& a_game )
    : NCGE::NUI::CCommandFactory()
    , m_impl(
        SImpl::f_Create( a_game ) ) {
}




using namespace NCGE::NUI;
namespace {

    // Перечислитель для команды
    // движения в определённую сторону
    enum class EMoveSide {
        E_Left = 0
        , E_Right
        , E_Top
        , E_Bottom
    };




    class CCommandMove
        : public CCommand {
        public:
            explicit CCommandMove(
                const CGame& a_game
                , const EMoveSide
                    a_side )
                : CCommand()
                , m_game( a_game )
                , m_move_side( a_side ) {
            }

            M_MAKE_SHARED(
                CCommandMove
                , TCommand )

            bool f_Execute() override;


        private:
            CGame m_game;
            EMoveSide m_move_side;
    };
}




// Двигаем объект на карте
bool CCommandMove::f_Execute() {

    switch ( m_move_side ) {
        case EMoveSide::E_Bottom:
            m_game.f_MoveDown();
            break;

        case EMoveSide::E_Top:
            m_game.f_MoveUp();
            break;

        case EMoveSide::E_Right:
            m_game.f_MoveRight();
            break;

        case EMoveSide::E_Left:
            m_game.f_MoveLeft();
            break;

        default:

            std::cout
                << "error:"
                "undefined move side!"
                << std::endl;
            return false;
    }


    return true;
}




NCGE::NUI::TCommand
NSnake::CCommandFactory::f_ProcessInput() {
    using namespace NCGE::NUI;


    // обработка действий пользователя
    m_impl->m_input = getch() + getch();


    if ( static_cast< KEYS >(
            m_impl->m_input )
        != KEYS::KEY_CONTROL ) {

        // Если клавиша не та,
        // то генерируем команду выход
        // reset_keypress();
        return CCommand::f_MakeExit();
    }


    const auto input
        = static_cast< KEYS >(
            getchar() );
    TCommand command;
    if ( input == KEYS::KEY_DOWN ) {
        return
            CCommandMove::f_Create(
                m_impl->m_game
                , EMoveSide::E_Bottom );
    }

    if ( input == KEYS::KEY_UP ) {
        return
            CCommandMove::f_Create(
                m_impl->m_game
                , EMoveSide::E_Top );
    }

    if ( input == KEYS::KEY_RIGHT ) {
        return
            CCommandMove::f_Create(
                m_impl->m_game
                , EMoveSide::E_Right );
    }

    if ( input == KEYS::KEY_LEFT ) {
        return
            CCommandMove::f_Create(
                m_impl->m_game
                , EMoveSide::E_Left );
    }


    // Пустая команда
    return CCommand::f_Make();
}
