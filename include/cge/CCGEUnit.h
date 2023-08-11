#ifndef CCGEUNIT_H
#define CCGEUNIT_H


#include <memory>
#include <iostream>

#include "HCGEMacroses.h"
#include "CCGEEntity.h"




namespace NWRD {
    class CUnit : public CEntity {
        M_IMPL_UNIQUE_V_DECL( CUnit )


        public:
            static bool f_Test();

        protected:
            explicit CUnit();


        private:
            M_IMPL_UNIQUE_STRUCT(
                SImpl, TImpl )
    };
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CUnit& a_unit );




#endif
