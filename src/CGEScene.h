#ifndef CGECENE_H
#define CGECENE_H


#include <memory>

#include "HMacroses.h"
#include "CPoint.h"
#include "CGETexture.h"




namespace NGE {
    class CScene {
        public:
            explicit CScene(
                const int a_width
                , const int a_height );

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


        private:
            M_IMPL_STRUCT( SImpl, TImpl )
    };
}




#endif
