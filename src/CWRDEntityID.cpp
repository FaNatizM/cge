#include "CWRDEntityID.h"

#include <cassert>




namespace NWRD {
    struct CEntityID::SImpl {
        public:
            explicit SImpl(
                const int64_t a_id );

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
            int64_t m_id;
    };
}




NWRD::CEntityID::SImpl::SImpl(
    const int64_t a_id )
    : m_id( a_id ) {
}




namespace NWRDCEntityID {
    constexpr int64_t C_ID_UNDEFINED
        = -1;

    static int64_t f_GenerateID() {
        static int64_t id
            = NWRDCEntityID::
                C_ID_UNDEFINED;
        id++;

        return id;
    }
}




NWRD::CEntityID::CEntityID()
    : m_impl(
        SImpl::f_Create(
            NWRDCEntityID::f_GenerateID(
                ) ) ) {
}



std::ostream&
NWRD::CEntityID::f_Visual(
    std::ostream& a_out ) const {
    std::cout << m_impl->m_id;
    return a_out;
}



bool NWRD::CEntityID::operator<(
    const CEntityID& a_other )
    const {
    if ( m_impl->m_id
        < a_other.m_impl->m_id ) {
        return true;
    }

    return false;
}



bool NWRD::CEntityID::operator==(
    const CEntityID& a_other )
    const {
    if ( m_impl->m_id
        == a_other.m_impl->m_id ) {
        return true;
    }

    return false;
}



bool NWRD::CEntityID::f_Test() {
    CEntityID id_0;
    assert( id_0.m_impl->m_id == 0 );

    CEntityID id_1;
    assert( id_1.m_impl->m_id == 1 );


    assert( ( id_0 == id_1 )
        == false );
    assert( id_0 < id_1 );


    auto id_0_copy = id_0;
    assert( id_0_copy == id_0 );
    assert( ( id_0_copy < id_0 )
        == false );


    return true;
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CEntityID& a_id ) {
    a_id.f_Visual( a_out );


    return a_out;
}
