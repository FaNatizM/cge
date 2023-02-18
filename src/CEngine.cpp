#include <iostream>
#include <chrono>

#include "CEngine.h"
#include "CUI.h"




class CEnginePrivate {
    public:
        CEnginePrivate( const CMap& a_map )
            : m_map( a_map ) {
        }

    void f_Draw();


    public:
        CMap m_map;
};




CEngine::CEngine( const CMap& a_map )
    : m_impl( TEnginePrivate( new CEnginePrivate( a_map ) ) ) {

    m_impl->f_Draw();
}



void CEnginePrivate::f_Draw() {
    system( "clear" );

    CMapObject object = m_map.f_GetObject();
    for ( int i = 0; i < m_map.f_GetWidth(); i++ ) {
        for ( int j = 0; j < m_map.f_GetHeight(); j++ ) {
            if ( ( i == object.f_GetYPos() )
                && (j == object.f_GetXPos() ) ) {
                std::cout << " " << object.f_GetSymbol() << " ";
            } else {
                    std::cout << " " << m_map.f_GetSymbol() << " ";
            }
        }

        std::cout << std::endl;
    }
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
        TTime step{ 40 };

        if ( step <= ( ms - g_ms_last ) ) {

            // Отрисовка экрана с частотой раз в 25 секунд
            m_impl->f_Draw();

            g_ms_last = ms;
        }


        // Обрабатываем пользовательский ввод
        auto command = NUI::CUI::f_ProcessInput( m_impl->m_map );

        // Выполняем пользовательскую команду
        if ( command->f_Execute() == false ) {

            // Если команда Выход или не смогла выполниться, то
            //  прерываем выполнение движка
            break;
        }
    }
}
