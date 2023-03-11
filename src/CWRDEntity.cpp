#include "CWRDEntity.h"

#include <cassert>
#include <vector>




namespace NWRD {
    struct CEntity::SImpl {
        public:
            explicit SImpl(
                const TModel& a_model );

            M_IMPL_MAKE_STRUCT(
                SImpl, TImpl )

            bool f_ExistObject(
                const int a_index )
                const;


        public:
            CEntityID m_id;

            // Объекты сущности
            TModel m_model;
    };
}




NWRD::CEntity::SImpl::SImpl(
    const TModel& a_model )
    : m_id()
    , m_model( a_model ) {
}



bool NWRD::CEntity::SImpl::f_ExistObject(
    const int a_index ) const {
    if ( a_index < 0 ) {
        return false;
    }

    if ( m_model->f_GetObjectsCount()
        <= a_index ) {
        return false;
    }

    return true;
}




NWRD::CEntity
NWRD::CEntity::f_MakeNull() {
    static auto null
        = CEntity();

    return null;
}



bool NWRD::CEntity::f_IsEmpty() const {
    if ( f_GetObjectsCount()
        < 1 ) {
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


    return m_impl->m_model->f_GetObject(
        a_index );
}



void NWRD::CEntity::f_AddObject(
    const CObject& a_object ) {
}



size_t NWRD::CEntity::f_GetObjectsCount()
    const {
    return m_impl->m_model
        ->f_GetObjectsCount();
}



NGE::CTexture
NWRD::CEntity::f_GetTexture(
    const int a_index ) const {
    if ( m_impl->f_ExistObject( a_index )
        == false ) {
        return NGE::CTexture();
    }


    return
        m_impl->m_model
            ->f_GetTexture( a_index );
}



CPoint
NWRD::CEntity::f_GetPoint(
    const int a_index ) const {
    if ( m_impl->f_ExistObject( a_index )
        == false ) {
        return CPoint();
    }


    return
        m_impl->m_model
            ->f_GetPoint( a_index );
}



bool NWRD::CEntity::f_LoopModel(
    const CModel::TOperation&
    a_operation ) {
    return m_impl->m_model->f_Loop( a_operation );
}



TPoints NWRD::CEntity::f_CheckMove(
    const CPoint& a_point )
    const {
    return m_impl->m_model->f_CheckMove( a_point );
}



bool NWRD::CEntity::f_Move(
    const TPoints& a_points ) {
    if ( f_IsEmpty() == true ) {
        return false;
    }


    return m_impl->m_model
        ->f_Move( a_points );
}



std::ostream& NWRD::CEntity::f_Visual(
    std::ostream& a_out )
    const {
    a_out << "ID: "
        << f_GetID()
        << "; model: "
        << m_impl->m_model
        << "; size: "
        << f_GetObjectsCount();

    return a_out;
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
    assert(
        entity.f_Move( { CPoint( 1, 1 ) } )
            == false );

    CObject object_empty;
    entity.f_AddObject( object_empty );

    assert( entity.f_GetObjectsCount()
        == 0 );

    assert( entity.f_IsEmpty()
         == true );

    assert(
        entity.f_Move( { CPoint( 1, 1 ) } )
            == false );
}



NWRD::CEntity::CEntity(
    const TModel& a_model )
    : m_impl(
        SImpl::f_Create( a_model ) ) {
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::TEntity& a_entity ) {
    return a_entity->f_Visual( a_out );
}



std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CEntity& a_entity ) {
    return a_entity.f_Visual( a_out );
}
