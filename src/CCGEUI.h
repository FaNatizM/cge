#ifndef CCGEUI_H
#define CCGEUI_H


#include "CCGEUICommand.h"




// Класс для приёма команд пользователя
namespace NUI {
    class CUI {
        public:

            // Метод обработки пользовательского ввода
            // Анализирует, что ввёл пользователь и на основе этого
            // создаёт объект-команду
            // Если пользователь ввёл символы, которые
            // программа не ожидает, то метод вернёт пустую команду
            static TCommand f_ProcessInput( const CGame& a_game );

        private:
            explicit CUI() {}
    };
}




#endif
