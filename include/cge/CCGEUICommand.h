#ifndef CCGEUICOMMAND_H
#define CCGEUICOMMAND_H


#include <memory>

#include <cge/HCGEMacroses.h>




namespace NCGE {
    namespace NUI {
        M_POINTER_TYPE(
            CCommand, TCommand )

        // Абстрактная команда
        class CCommand {
            protected:
                explicit CCommand();

            public:
                virtual ~CCommand();

                // Создание команды
                // бездействия
                static TCommand
                    f_Make();

                // Создание команды выход
                static TCommand
                    f_MakeExit();

                // Если команду
                // не удалось
                // обработать,
                // то игра будет
                // завершена
                virtual bool
                    f_Execute() = 0;
        };
    }
}




#endif
