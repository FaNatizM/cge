#ifndef CNWRDVIEWER_H
#define CNWRDVIEWER_H


#include <memory>

#include "HMacroses.h"
#include "CGEScene.h"
#include "CWRDLocation.h"




namespace NWRD {
    class CViewer {
        public:
            explicit CViewer(
                const NGE::CScene&
                    a_scene
                , const CLocation&
                    a_location );

            void f_View() const;

            void f_ViewAndDraw() const;

            bool f_SetPoint(
                const CPoint& a_point );

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
