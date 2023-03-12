#ifndef CWRDOBJECT_H
#define CWRDOBJECT_H


#include <memory>
#include <iostream>

#include "HMacroses.h"
#include "CPoint.h"
#include "CGETexture.h"




namespace NWRD {
    class CObject {
        M_IMPL_SHARED_V_DECL( CObject )


        public:
            static CObject f_MakeNull();

            explicit CObject();

            explicit CObject(
                const CPoint& a_point
                , const NGE::CTexture&
                a_texture );

            bool operator==(
                const CObject& a_other )
                const;

            bool f_IsNull() const;

            CPoint f_GetPoint() const;

            void f_SetPoint( const CPoint& a_point );

            NGE::CTexture
            f_GetTexture() const;


        private:
            M_IMPL_SHARED_STRUCT(
                SImpl, TImpl )
    };
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CObject& a_object );




#endif
