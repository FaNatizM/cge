#ifndef CCGEDECORATION_H
#define CCGEDECORATION_H


#include <memory>
#include <iostream>

#include "HCGEMacroses.h"
#include "CCGEEntity.h"




namespace NWRD {
    class CDecoration : public CEntity {
        M_IMPL_UNIQUE_V_DECL(
            CDecoration )


        public:
            static bool f_Test();

        protected:
            explicit CDecoration();


        private:
            M_IMPL_UNIQUE_STRUCT(
                SImpl, TImpl )
    };
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CDecoration&
        a_decoration );




#endif
