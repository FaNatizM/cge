#include "CWRDItemsCreator.h"

#include <cassert>




namespace NWRD {
    struct CItemsCreator::SImpl {
        public:
            explicit SImpl(
                const TItemType a_type
                , const NGE::CTexture& a_texture );

            M_IMPL_MAKE_STRUCT(
                SImpl, TImpl )


        public:
            TItemType m_type;
            NGE::CTexture m_texture;
    };
}




NWRD::CItemsCreator::SImpl::SImpl(
    const TItemType a_type
    , const NGE::CTexture& a_texture )
    : m_type( a_type )
    , m_texture( a_texture ) {
}




NWRD::CItemsCreator::CItemsCreator(
    const TItemType a_type
    , const NGE::CTexture& a_texture )
    : m_impl(
        SImpl::f_Create(
            a_type, a_texture ) ) {
}



NWRD::CItem
NWRD::CItemsCreator::f_Create() const {
    CItem item(
        m_impl->m_type
        , m_impl->m_texture );

    return item;
}



bool NWRD::CItemsCreator::f_Test() {
    const auto creator
        = CItemsCreator(
            TItemType::EUndefined
            , NGE::CTexture( '1' ) );

    std::cout << creator << std::endl;

    const auto item
        = creator.f_Create();

    assert( item.f_IsUndefined()
        == true );

    return true;
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CItemsCreator&
        a_creator ) {
    return a_out;
}
