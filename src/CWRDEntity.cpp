#include "CWRDEntity.h"

#include <cassert>
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



bool NWRD::CEntity::f_IsEmpty() const {
    if ( f_GetObjectsCount()
        == 0 ) {
        return true;
    }


    return false;
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



void NWRD::CEntity::f_AddObject(
    const CObject& a_object ) {
    m_impl->m_objects.push_back(
        a_object );
}



size_t NWRD::CEntity::f_GetObjectsCount()
    const {
    return m_impl->m_objects.size();
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



bool NWRD::CEntity::f_Move(
    const CPoint& a_point ) {
    if ( f_IsEmpty() == true ) {
        return false;
    }


    auto object
        = m_impl->m_objects[ 0 ];
    object.f_SetPoint( a_point );


    return true;
}



void NWRD::CEntity::f_Test() {
    auto entity = CEntity();
    std::cout << "entity: "
        << entity << std::endl;

    assert( entity.f_IsEmpty()
         == true );

    assert( entity.f_GetObject()
        .f_IsNull() == true );

    assert( entity.f_GetPoint()
        .f_IsNull() == true );

    assert( entity.f_GetTexture()
        .f_IsUndefined() == true );

    assert( entity.f_GetObjectsCount()
        == 0 );


    // Добавление объектов
    assert( entity.f_Move( CPoint( 1, 1 ) ) == false );

    CObject object_empty;
    entity.f_AddObject( object_empty );

    assert( entity.f_GetObjectsCount()
        == 1 );

    assert( entity.f_IsEmpty()
         == false );

    assert( entity.f_Move( CPoint( 1, 1 ) ) == true );
}



NWRD::CEntity::CEntity()
    : m_impl(
        SImpl::f_Create() ) {
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::TEntity& a_entity ) {
    a_out << *a_entity;
    return a_out;
}



std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CEntity& a_entity ) {
    a_out << "ID: "
        << a_entity.f_GetID() << ": "
        << a_entity.f_GetObject();

    return a_out;
}
