#ifndef CCGEGAME_H
#define CCGEGAME_H


#include <memory>

#include <cge/export.h>
#include <cge/HCGEMacroses.h>




namespace NCGE {
    CGE_EXPORT class CGame {
        public:
            explicit CGame();

            void f_ViewAndDraw() const;

            bool f_MoveUp();
            bool f_MoveLeft();
            bool f_MoveRight();
            bool f_MoveDown();


        private:
            M_IMPL_SHARED_STRUCT(
                SImpl, TImpl )
    };
}




#endif
