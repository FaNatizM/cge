#ifndef CCGEUI_H
#define CCGEUI_H


#include "CCGEUICommand.h"




// Класс для приёма команд пользователя
namespace NCGE {
    namespace NUI {
        M_POINTER_TYPE(
            CCommandFactory
            , TCommandFactory )
        class CCommandFactory {
            protected:
                explicit
                    CCommandFactory();

            public:
                virtual
                    ~CCommandFactory();

                // Метод обработки
                // пользовательского
                // ввода
                // Анализирует, что ввёл
                // пользователь и на
                // основе этого
                // создаёт объект-команду
                // Если пользователь ввёл
                // символы, которые
                // программа не ожидает,
                // то метод вернёт
                // пустую команду
                virtual
                    ::NCGE::NUI::TCommand
                    f_ProcessInput() = 0;
        };
    }
}




#endif
