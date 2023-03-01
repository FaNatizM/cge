#ifndef CWRDITEM_H
#define CWRDITEM_H


#include <memory>
#include <iostream>

#include "HMacroses.h"
#include "CWRDEntity.h"




namespace NWRD {
    class CItem : public CEntity {
        M_IMPL_UNIQUE_V_DECL( CItem )


        public:
            explicit CItem();

            static bool f_Test();


        private:
            M_IMPL_UNIQUE_STRUCT(
                SImpl, TImpl )
    };
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CItem& a_item );




#endif
