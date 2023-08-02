#ifndef CCGEENGINE_H
#define CCGEENGINE_H

#include <memory>

#include <cge/export.h>

#include <cge/CCGEGame.h>




// Движок
// Реализует цикл обработки пользовательского ввода и отрисовки экрана
namespace NCGE {
    CGE_EXPORT class CEngine {
        public:
            explicit CEngine(
                const CGame& a_game );

            // Цикл выполнения
            void f_Exec();


        private:
            M_IMPL_SHARED_STRUCT(
                SImpl, TImpl )
    };
}




#endif
