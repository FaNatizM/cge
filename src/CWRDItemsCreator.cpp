#include "CWRDItemsCreator.h"

#include <cassert>




namespace NWRD {
    struct CItemsCreator::SImpl {
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
    };
}




NWRD::CItemsCreator::SImpl::SImpl() {
}



NWRD::CItem
NWRD::CItemsCreator::f_MakeFood() {
    CItem food;
    return food;
}



bool NWRD::CItemsCreator::f_Test() {
    const auto creator
        = CItemsCreator::f_Get();

    std::cout << creator << std::endl;


    const auto food
        = NWRD::CItemsCreator
            ::f_MakeFood();

    return true;
}



NWRD::CItemsCreator::CItemsCreator()
    : m_impl(
        SImpl::f_Create() ) {
}



NWRD::CItemsCreator
NWRD::CItemsCreator::f_Get() {
    static CItemsCreator creator;
    return creator;
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CItemsCreator&
        a_creator ) {
    return a_out;
}
