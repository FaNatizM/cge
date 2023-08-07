#include <cge/CCGEItemsCreator.h>

#include <cassert>




namespace NWRD {
    struct CItemsCreator::SImpl {
        public:
            explicit SImpl(
                const TItemType a_type
                , const TModel&
                    a_model );

            M_IMPL_MAKE_STRUCT(
                SImpl, TImpl )


        public:
            TItemType m_type;
            TModel m_model;
    };
}




NWRD::CItemsCreator::SImpl::SImpl(
    const TItemType a_type
    , const TModel& a_model )
    : m_type( a_type )
    , m_model( a_model ) {
}




NWRD::CItemsCreator::CItemsCreator(
    const TItemType a_type
    , const TModel& a_model )
    : m_impl(
        SImpl::f_Create(
            a_type, a_model ) ) {
}



NWRD::TItem
NWRD::CItemsCreator::f_Create() const {
    const auto item = CItem::f_Create(
        m_impl->m_type
        , m_impl->m_model );


    return item;
}



std::ostream&
NWRD::CItemsCreator::f_Visual(
    std::ostream& a_out )
    const {

    a_out << "item type: "
        << static_cast< int >(
            m_impl->m_type );
    a_out << "; model: "
        << m_impl->m_model;

    return a_out;
}



bool NWRD::CItemsCreator::f_Test() {
    const auto creator
        = CItemsCreator(
            TItemType::EUndefined
            , CModel::f_Create() );

    std::cout << creator << std::endl;

    const auto item
        = creator.f_Create();

    assert( item->f_IsUndefined()
        == true );

    assert( item->f_IsEmpty()
        == true );

    return true;
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CItemsCreator&
        a_creator ) {

    return a_creator.f_Visual( a_out );
}
