﻿#ifndef CGETEXTURE_H
#define CGETEXTURE_H


#include <iostream>
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

            TTexture f_Get() const;

            void f_Draw() const;


        private:
            M_IMPL_SHARED_STRUCT(
                SImpl, TImpl )
    };
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NGE::CTexture& a_texture );




#endif
