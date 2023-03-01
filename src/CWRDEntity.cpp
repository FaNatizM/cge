#include "CWRDEntity.h"

#include <vector>




namespace NWRD {
    using TObjects
        = std::vector< CObject >;



    struct CEntity::SImpl {
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

        inline bool f_ExistObject(
            const int a_index ) {
            if ( a_index < 0 ) {
                return false;
            }

            if ( m_objects.size()
                <= a_index ) {
                return false;
            }

            return true;
        }


        public:
            CEntityID m_id;

            // Объекты сущности
            TObjects m_objects;
    };
}




NWRD::CEntity::SImpl::SImpl()
    : m_id()
    , m_objects() {
}




namespace NWRD {
    M_IMPL_UNIQUE( CEntity, SImpl )
}



NWRD::CEntityID
NWRD::CEntity::f_GetID() const {
    return
        m_impl->m_id;
}



NWRD::CObject
NWRD::CEntity::f_GetObject(
    const int a_index ) const {
    if ( m_impl->f_ExistObject( a_index )
        == false ) {
        return CObject();
    }


    return
        m_impl->m_objects[ a_index ];
}



NGE::CTexture
NWRD::CEntity::f_GetTexture(
    const int a_index ) const {
    if ( m_impl->f_ExistObject( a_index )
        == false ) {
        return NGE::CTexture();
    }


    return
        m_impl->m_objects[ a_index ]
            .f_GetTexture();
}



CPoint
NWRD::CEntity::f_GetPoint(
    const int a_index ) const {
    if ( m_impl->f_ExistObject( a_index )
        == false ) {
        return CPoint();
    }


    return
        m_impl->m_objects[ a_index ]
            .f_GetPoint();
}



NWRD::CEntity::CEntity()
    : m_impl(
        SImpl::f_Create() ) {
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::TEntity& a_entity ) {
    std::cout << a_entity->f_GetObject();
    return a_out;
}
