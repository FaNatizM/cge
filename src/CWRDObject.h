#ifndef CWRDOBJECT_H
#define CWRDOBJECT_H


#include <memory>
#include <iostream>

#include "HMacroses.h"
#include "CPoint.h"
#include "CGETexture.h"




namespace NWRD {
    class CObject {
        M_IMPL_UNIQUE_V_DECL( CObject )


        public:
            explicit CObject();

            explicit CObject(
                const CPoint& a_point
                , const NGE::CTexture&
                a_texture );

            bool f_IsNull() const;

            CPoint f_GetPoint() const;

            NGE::CTexture
            f_GetTexture() const;


        private:
            M_IMPL_UNIQUE_STRUCT(
                SImpl, TImpl )
    };
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CObject& a_object );




#endif
