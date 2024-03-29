#ifndef CNWRDVIEWER_H
#define CNWRDVIEWER_H


#include <memory>

#include "HCGEMacroses.h"
#include "CCGEScene.h"
#include "CCGELocation.h"




namespace NWRD {
    class CViewer {
        public:
            explicit CViewer(
                const NCGE::CScene&
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

            // Захват сущности в обзорщик
            // Если сущность подходит
            // близко к краю обзорщика,
            // то обзорщик сдвигается
            void f_CatchEntity( const TEntity& a_entity );

            void f_MoveWithEntity();


        private:
            M_IMPL_SHARED_STRUCT(
                SImpl, TImpl )
    };
}




#endif
