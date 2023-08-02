#include "CCGEUnit.h"

#include <cassert>
#include <vector>




namespace NWRD {
    struct CUnit::SImpl {
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




NWRD::CUnit::SImpl::SImpl() {
}




namespace NWRD {
    M_IMPL_UNIQUE( CUnit, SImpl )
}




bool NWRD::CUnit::f_Test() {
    CUnit unit;
    std::cout << unit << std::endl;

    return true;
}



NWRD::CUnit::CUnit()
    : m_impl(
        SImpl::f_Create() ) {
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CUnit& a_unit ) {
    return a_out;
}
