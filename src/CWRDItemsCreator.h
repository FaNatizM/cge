#ifndef CWRDITEMSCREATOR_H
#define CWRDITEMSCREATOR_H


#include <memory>
#include <iostream>

#include "HMacroses.h"
#include "CWRDItem.h"




namespace NWRD {
    class CItemsCreator {
        public:
            static CItem f_MakeFood();

            static bool f_Test();

        private:
            explicit CItemsCreator();

            static CItemsCreator
                f_Get();


        private:
            M_IMPL_SHARED_STRUCT(
                SImpl, TImpl )
    };
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CItemsCreator&
        a_creator );




#endif
