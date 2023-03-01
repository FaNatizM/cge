#include "CWRDEntity.h"




namespace NWRD {
    struct CEntity::SImpl {
        public:
            explicit SImpl(
                const NGE::CTexture&
                a_texture );

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

            // Объект сущности
            CObject m_object;
    };
}




NWRD::CEntity::SImpl::SImpl(
    const NGE::CTexture& a_texture )
    : m_texture( a_texture ) {
}




namespace NWRD {
    M_IMPL_UNIQUE( CEntity, SImpl )
}



NGE::CTexture
NWRD::CEntity::f_GetTexture() const {
    return m_impl->m_texture;
}



NWRD::CEntity::CEntity(
    const NGE::CTexture& a_texture
    , const bool a_space )
    : m_impl(
        SImpl::f_Create(
            a_texture, a_space ) ) {
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::TEntity& a_entity ) {
    std::cout << a_entity.f_GetObject();
    return a_out;
}
