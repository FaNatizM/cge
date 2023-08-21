#include <cge/CCGEItem.h>

#include <cassert>
#include <vector>

#include <cge/eng/CCGEEventManagerItem.h>




using namespace NWRD;
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

            CEventManagerItem
                m_event_manager;
    };
}




NWRD::CItem::SImpl::SImpl(
    const TItemType a_type )
    : m_type( a_type )
    , m_event_manager() {
}




NWRD::CItem::CItem(
    const TItemType a_type
    , const TModel& a_model )
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



void CItem::f_AddEventEmitter(
    const CEventItem::EType a_event_type
    , const std::string& a_emitter_name
    , const TEventEmitter& a_emitter ) {
    m_impl->m_event_manager
        .f_AddEventEmitter(
            a_event_type
            , a_emitter_name
            , a_emitter );
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
