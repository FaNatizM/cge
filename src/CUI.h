#ifndef CUI_H
#define CUI_H


#include "CUICommand.h"




// Класс для приёма команд пользователя
namespace NUI {
    class CUI {
        public:

            // Метод обработки пользовательского ввода
            // Анализирует, что ввёл пользователь и на основе этого
            // создаёт объект-команду
            // Если пользователь ввёл символы, которые
            // программа не ожидает, то метод вернёт пустую команду
            static TCommand f_ProcessInput( const CMap& a_map );

        private:
            explicit CUI() {}
    };
}




#endif
