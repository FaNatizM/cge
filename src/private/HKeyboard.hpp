// Инструменты для работы с пользовательским вводом
#ifndef HKEYBOARD_H
#define HKEYBOARD_H


#include <iostream>
#include <termios.h>




char getch( void ) {

    /* get original settings */
    struct termios settings_new, settings_old;
    tcgetattr( 0, &settings_old );
    settings_new = settings_old;

    /* set new settings and flush out terminal */
    settings_new.c_lflag &= ~ICANON;
    tcsetattr( 0, TCSAFLUSH, &settings_new );

    /* get char and reset terminal */
    char ch = getchar();
    tcsetattr( 0, TCSAFLUSH, &settings_old );

    return ch;
}




// перечисление констант ascii кодов некоторых клавиш
enum class KEYS {
    KEY_CONTROL = 118,
    KEY_UP = 65,
    KEY_DOWN = 66,
    KEY_RIGHT = 67,
    KEY_LEFT = 68
};




#endif
