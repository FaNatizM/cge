#ifndef CENGINE_H
#define CENGINE_H

#include <memory>

#include "CCGEGame.h"




// Движок
// Реализует цикл обработки пользовательского ввода и отрисовки экрана
class CEngine {
    public:
        explicit CEngine(
            const CGame& a_game );

        // Цикл выполнения
        void f_Exec();


    private:
        M_IMPL_SHARED_STRUCT(
            SImpl, TImpl )
};




#endif
