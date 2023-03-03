#ifndef CWRDPLACE_H
#define CWRDPLACE_H


#include <memory>
#include <iostream>

#include "HMacroses.h"
#include "CGETexture.h"
#include "CWRDObject.h"




namespace NWRD {
    M_POINTER_TYPE( CPlace, TPlace )



    // Место на локации
    // в котором может быть сущность
    class CPlace {
        M_IMPL_UNIQUE_V_DECL( CPlace )


        public:
            static TPlace f_MakeNowhere();

            static TPlace f_MakeGround();

            NGE::CTexture
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
            explicit CPlace(
                const NGE::CTexture&
                a_texture
                , const bool a_space );

            void f_SetEmpty(
                const bool a_value );


        private:
            M_IMPL_UNIQUE_STRUCT(
                SImpl, TImpl )
    };
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::TPlace& a_place );




#endif
