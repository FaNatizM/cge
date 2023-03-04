#ifndef CGAME_H
#define CGAME_H


#include "CWRDViewer.h"




class CGame {
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





#endif
