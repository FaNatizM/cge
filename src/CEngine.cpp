#include <iostream>
#include <termios.h>
#include <chrono>

#include "CEngine.h"




struct termios stored_settings;




//функция для перевода консоли в неканонический режим
void set_keypress(void) {
    struct termios new_settings;

    tcgetattr(0, &stored_settings);

    new_settings = stored_settings;

    new_settings.c_lflag &= (~ICANON & ~ECHO);
    new_settings.c_cc[VTIME] = 0;
    new_settings.c_cc[VMIN] = 1;

    tcsetattr(0, TCSANOW, &new_settings);
    return;
}



//функция для перевода консоли в канонический режим
void reset_keypress(void) {
    tcsetattr(0, TCSANOW, &stored_settings);
    return;
}




//перечисление констант ascii кодов некоторых клавиш
enum class KEYS {
    KEY_CONTROL = 118,
    KEY_UP = 65,
    KEY_DOWN = 66,
    KEY_RIGHT = 67,
    KEY_LEFT = 68
};




CEngine::CEngine( const CMap& a_map )
    : m_map( a_map )
    , ascii() {

    f_Draw();
}



// Test
// Декомпозиция в классы CUI, CCommand, CCommandMove
bool CEngine::inputAscii( CMapObject& m_map, int width, int height ) {

    // обработка действий пользователя
    set_keypress();
    this->ascii = getchar() + getchar();

    if ( static_cast< KEYS >( this->ascii ) != KEYS::KEY_CONTROL ) {

        // Если клавиша не та, то выходим
        reset_keypress();
        return false;
    }


    switch ( static_cast< KEYS >( getchar() ) ) {
        case KEYS::KEY_DOWN:
            if ( m_map.f_GetYPos() < height - 1 ) {
                m_map.f_SetYPos(m_map.f_GetYPos() + 1);
            }
            break;

        case KEYS::KEY_UP:
            if (m_map.f_GetYPos() > 0)
                m_map.f_SetYPos(m_map.f_GetYPos() - 1);
            break;

        case KEYS::KEY_RIGHT:
            if (m_map.f_GetXPos() < width - 1)
                m_map.f_SetXPos(m_map.f_GetXPos() + 1);
            break;

        case KEYS::KEY_LEFT:
            if (m_map.f_GetXPos() > 0)
                m_map.f_SetXPos(m_map.f_GetXPos() - 1);
            break;

        default:
            break;
    }

    //
    reset_keypress();
    return true;
}



void CEngine::f_Draw() {
    system( "clear" );

    // Отрисовка карты с объектом на ней
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

    while( true ) {

        auto ms = f_GetCurrentTime();
        TTime step{ 40 };

        if ( step <= ( ms - g_ms_last ) ) {

            // Перерисовка экрана происходит 25 раз в секунду
            f_Draw();

            g_ms_last = ms;
        }


        // Обработка пользовательского ввода
        auto object = m_map.f_GetObject();
        if ( this->inputAscii( object, m_map.f_GetWidth(), m_map.f_GetHeight() ) == false ) {
            break;
        }
    }
}
