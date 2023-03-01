#ifndef CWRDENTITY_H
#define CWRDENTITY_H


#include <memory>
#include <iostream>

#include "HMacroses.h"
#include "CWRDObject.h"
#include "CWRDEntityID.h"




namespace NWRD {
    M_POINTER_TYPE( CEntity, TEntity )



    class CEntity {
        M_IMPL_UNIQUE_V_DECL( CEntity )


        public:
            CEntityID f_GetID() const;

            CObject
            f_GetObject(
                const int a_index = 0 )
                const;

            NGE::CTexture
            f_GetTexture(
                const int a_index = 0 )
                const;

            CPoint f_GetPoint(
                const int a_index = 0 )
                const;

        protected:
            explicit CEntity();


        private:
            M_IMPL_UNIQUE_STRUCT(
                SImpl, TImpl )
    };
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::TEntity& a_entity );




#endif
