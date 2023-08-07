#ifndef CCGEPLACE_H
#define CCGEPLACE_H


#include <memory>
#include <iostream>

#include <cge/HCGEMacroses.h>
#include <cge/CCGETexture.h>
#include <cge/CCGEObject.h>




namespace NWRD {

    // Уникальное место на локации
    // в котором может быть объект
    // Объект может быть общим на несколько
    // мест. Например, "нулевой" объект
    // обший на все пустые места
    class CPlace {
        M_IMPL_UNIQUE_V_DECL( CPlace )


        public:
            static CPlace f_MakeNowhere();

            static CPlace f_MakeGround();

            explicit CPlace(
                const NCGE::CTexture&
                a_texture = NCGE::CTexture(
                    NCGE::CTexture::C_NOWHERE )
                , const bool a_space = false );

            NCGE::CTexture
            f_GetTexture() const;

            bool f_IsSpace() const;

            bool f_IsEmpty() const;

            // Метод занятия места
            bool f_Take(
                const CObject&
                a_object );

            // Метод освобождения места
            CObject f_Free();

            CObject f_GetObject() const;


        protected:
            void f_SetEmpty(
                const bool a_value );


        private:
            M_IMPL_UNIQUE_STRUCT(
                SImpl, TImpl )
    };
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CPlace& a_place );




#endif
