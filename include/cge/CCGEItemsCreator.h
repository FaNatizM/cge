#ifndef CCGEITEMSCREATOR_H
#define CCGEITEMSCREATOR_H


#include <iostream>

#include "CCGEItem.h"




namespace NWRD {
    class CItemsCreator {
        public:
            explicit CItemsCreator(
                const TItemType a_type
                , const TModel&
                    a_model );

            TItem f_Create() const;

            std::ostream& f_Visual(
                std::ostream& a_out )
                const;

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
