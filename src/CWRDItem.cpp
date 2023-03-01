#include "CWRDItem.h"

#include <cassert>
#include <vector>




namespace NWRD {
    struct CItem::SImpl {
        public:
            explicit SImpl();

            template< typename... Types >
            static TImpl f_Create(
                Types&& ... a_params ) {
                auto impl
                    = std::make_unique<
                        SImpl >(
                            std::forward<
                                Types >( a_params ) ... );

            return impl;
        }


        public:

            // Тип предмета
            // Название предмета
    };
}




NWRD::CItem::SImpl::SImpl() {
}




namespace NWRD {
    M_IMPL_UNIQUE( CItem, SImpl )
}




bool NWRD::CItem::f_Test() {
    CItem item;
    std::cout << item << std::endl;

    return true;
}



NWRD::CItem::CItem()
    : m_impl(
        SImpl::f_Create() ) {
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CItem& a_entity ) {
    return a_out;
}
