#ifndef CCGEENTITYID_H
#define CCGEENTITYID_H


#include <memory>
#include <iostream>

#include "HCGEMacroses.h"




namespace NWRD {
    class CEntityID {
        public:
            explicit CEntityID();

            std::ostream& f_Visual(
                std::ostream& a_out
                ) const;

            bool operator<(
                const CEntityID&
                    a_other )
                const;

            bool operator==(
                const CEntityID&
                    a_other )
                const;

            static bool f_Test();


        private:
            M_IMPL_SHARED_STRUCT(
                SImpl, TImpl )
    };
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CEntityID& a_id );




#endif
