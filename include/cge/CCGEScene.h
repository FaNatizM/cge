#ifndef CCGECENE_H
#define CCGECENE_H


#include <memory>
#include <functional>

#include "HCGEMacroses.h"
#include "CCGEPoint.h"
#include "CCGETexture.h"




namespace NCGE {
    class CScene {
        public:
            using TNode
                = std::pair<
                    const CPoint
                    , CTexture >;

            using TOperation
                = std::function<
                    void(
                        TNode& ) >;

        public:
            explicit CScene(
                const int a_width
                , const int a_height );

            static TOperation
            f_GetVisualOperation();

            int f_GetWidth() const;

            int f_GetHeight() const;

            void f_Draw() const;

            CTexture f_GetTexture(
                const CPoint& a_point )
                const;

            bool f_SetTexture(
                const CPoint& a_point
                , const CTexture&
                    a_texture );

            void f_Loop(
                const TOperation&
                    a_operation );

            void f_LoopConst(
                const TOperation&
                    a_operation ) const;


        private:
            M_IMPL_SHARED_STRUCT(
                SImpl, TImpl )
    };
}




#endif
