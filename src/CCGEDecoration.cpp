#include <cge/CCGEDecoration.h>

#include <cassert>
#include <vector>




namespace NWRD {
    struct CDecoration::SImpl {
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

            // Тип декорации
            // Название декорации
    };
}




NWRD::CDecoration::SImpl::SImpl() {
}




namespace NWRD {
    M_IMPL_UNIQUE( CDecoration, SImpl )
}




bool NWRD::CDecoration::f_Test() {
    CDecoration decoration;
    std::cout << decoration << std::endl;

    return true;
}



NWRD::CDecoration::CDecoration()
    : m_impl(
        SImpl::f_Create() ) {
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CDecoration&
        a_decoration ) {
    return a_out;
}
