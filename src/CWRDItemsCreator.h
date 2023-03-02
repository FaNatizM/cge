#ifndef CWRDITEMSCREATOR_H
#define CWRDITEMSCREATOR_H


#include <memory>
#include <iostream>

#include "HMacroses.h"
#include "CWRDItem.h"




namespace NWRD {
    class CItemsCreator {
        public:
            explicit CItemsCreator(
                const TItemType a_type
                ,const NGE::CTexture& a_texure
            );

            CItem f_Create() const;

            static bool f_Test();


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
