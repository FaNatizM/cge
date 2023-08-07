#ifndef CGAME_H
#define CGAME_H


#include <memory>

#include <cge/export.h>
#include <cge/CCGEEngine.h>
#include <cge/HCGEMacroses.h>




namespace NSnake {
    class CGame {
        public:
            explicit CGame();

            NCGE::TDrawer f_GetDrawer()
                const;

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
