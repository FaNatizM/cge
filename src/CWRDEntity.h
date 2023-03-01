#ifndef CWRDENTITY_H
#define CWRDENTITY_H


#include <memory>
#include <iostream>

#include "HMacroses.h"
#include "CGETexture.h"




namespace NWRD {
    M_POINTER_TYPE( CEntity, TEntity )



    class CEntity {
        M_IMPL_UNIQUE_V_DECL( CEntity )


        public:
            CObject
            f_GetObject() const;

            CPoint f_GetPoint() const;

        protected:
            explicit CEntity(
                const NGE::CTexture&
                a_texture );


        private:
            M_IMPL_UNIQUE_STRUCT(
                SImpl, TImpl )
    };
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::TEntity& a_entity );




#endif
