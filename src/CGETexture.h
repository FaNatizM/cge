#ifndef CGETEXTURE_H
#define CGETEXTURE_H


#include <memory>

#include "HMacroses.h"




namespace NGE {
    using TTexture = char;




    class CTexture {
        public:
            explicit CTexture(
                const TTexture a_texture
                    = ' ' );

            bool operator==(
                const CTexture& a_other )
                const;

            void f_Draw() const;


        private:
            M_IMPL_STRUCT( SImpl, TImpl )
    };
}




#endif
