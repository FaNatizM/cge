#ifndef CGETEXTURE_H
#define CGETEXTURE_H


#include <iostream>
#include <memory>

#include "HMacroses.h"




namespace NGE {
    using TTexture = char;




    class CTexture {
        public:
            static constexpr TTexture
            C_UNDEFINED = '?';

            static constexpr TTexture
            C_NOWHERE = ' ';

            static constexpr TTexture
            C_GROUND = '.';

            static constexpr TTexture
            C_FOG = '~';


        public:
            explicit CTexture(
                const TTexture a_texture
                    = C_UNDEFINED );

            bool operator==(
                const CTexture& a_other )
                const;

            bool f_IsUndefined() const;

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
