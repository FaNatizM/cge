#include "CWRDItem.h"

#include <cassert>
#include <vector>




namespace NWRD {
    struct CItem::SImpl {
        public:
            explicit SImpl(
                const TItemType a_type );

            M_IMPL_MAKE_STRUCT(
                SImpl, TImpl )


        public:

            // Тип предмета
            TItemType m_type;

            // Название предмета
    };
}




NWRD::CItem::SImpl::SImpl(
    const TItemType a_type )
    : m_type( a_type ) {
}




NWRD::CItem::CItem(
    const TItemType a_type
    , const CModel& a_model )
    : CEntity( a_model )
    , m_impl(
        SImpl::f_Create( a_type ) ) {
}



NWRD::TItemType
NWRD::CItem::f_GetType() const {
    return m_impl->m_type;
}



bool NWRD::CItem::f_IsUndefined() const {
    return f_GetType()
        == TItemType::EUndefined;
}



bool NWRD::CItem::f_Test() {
    CItem item;
    std::cout << item << std::endl;

    assert( item.f_IsUndefined()
        == true );

    return true;
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CItem& a_item ) {

    return a_item.f_Visual( a_out );
}



std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::TItem& a_item ) {

    return a_item->f_Visual( a_out );
}
