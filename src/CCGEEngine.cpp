#include <iostream>
#include <chrono>

#include <cge/CCGEEngine.h>
#include "CCGEUI.h"




using namespace NCGE;




struct NCGE::CEngine::SImpl {
    public:
        explicit SImpl( const CGame& a_game )
            : m_game( a_game ) {
        }

        M_IMPL_MAKE_STRUCT( SImpl, TImpl )

    void f_Draw();


    public:
        CGame m_game;
};



void CEngine::SImpl::f_Draw() {
    system( "clear" );

    // Рисуем происходящее
    m_game.f_ViewAndDraw();
}




CEngine::CEngine( const CGame& a_game )
    : m_impl( SImpl::f_Create( a_game ) ) {

    m_impl->f_Draw();
}



// Test
using TTime = std::chrono::milliseconds;
TTime f_GetCurrentTime() {
    using namespace std::chrono;

    milliseconds ms = duration_cast< milliseconds >(
        system_clock::now().time_since_epoch()
    );


    return ms;
}




static TTime g_ms_last = f_GetCurrentTime();




void CEngine::f_Exec() {

    while ( true ) {

        auto ms = f_GetCurrentTime();
        const auto once_25_ms = 40;
        const auto once_60_ms = 90;
        TTime step{ 40 };

        if ( step <= ( ms - g_ms_last ) ) {

            // Отрисовка экрана с частотой раз в 25 секунд
            m_impl->f_Draw();

            g_ms_last = ms;
        }


        // Обрабатываем пользовательский ввод
        auto command = NUI::CUI::f_ProcessInput( m_impl->m_game );

        // Выполняем пользовательскую команду
        if ( command->f_Execute() == false ) {

            // Если команда Выход или не смогла выполниться, то
            //  прерываем выполнение движка
            break;
        }
    }
}
