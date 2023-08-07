#include <iostream>
#include <chrono>

#include <cge/CCGEEngine.h>




using namespace NCGE;




struct NCGE::CEngine::SImpl {
    public:
        explicit SImpl(
            const NUI::TCommandFactory&
                a_ui
            , const TDrawer& a_drawer )
            : m_ui( a_ui )
            , m_drawer( a_drawer ) {
        }

        M_IMPL_MAKE_STRUCT(
            SImpl, TImpl )

        void f_Draw();


    public:
        NUI::TCommandFactory m_ui;
        TDrawer m_drawer;
};



void CEngine::SImpl::f_Draw() {
    system( "clear" );

    // Рисуем происходящее
    m_drawer();
}




CEngine::CEngine(
    const NUI::TCommandFactory& a_ui
    , const TDrawer& a_drawer )
    : m_impl(
        SImpl::f_Create(
            a_ui, a_drawer ) ) {

    m_impl->f_Draw();
}




namespace {
    using TTime
        = std::chrono::milliseconds;
    TTime f_GetCurrentTime() {
        using namespace std::chrono;

        auto time_since_epoch
            = system_clock::now()
                .time_since_epoch();
        milliseconds ms
            = duration_cast<
                milliseconds >(
                    time_since_epoch );


        return ms;
    }



    static TTime g_ms_last
        = f_GetCurrentTime();
}




void CEngine::f_Exec() {

    while ( true ) {

        auto ms = f_GetCurrentTime();
        const auto once_25_ms = 40;
        const auto once_60_ms = 90;
        TTime step{ once_25_ms };

        if ( step
            <= ( ms - g_ms_last ) ) {

            // Отрисовка экрана с частотой раз в 25 секунд
            m_impl->f_Draw();

            g_ms_last = ms;
        }


        // Обрабатываем пользовательский ввод
        auto command
            = m_impl->m_ui
                ->f_ProcessInput();

        // Выполняем пользовательскую команду
        if ( command->f_Execute()
            == false ) {

            // Если команда Выход или не смогла выполниться, то
            //  прерываем выполнение движка
            break;
        }
    }
}
