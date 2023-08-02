#include "CCGEPlace.h"




namespace NWRD {
    struct CPlace::SImpl {
        public:
            explicit SImpl(
                const NGE::CTexture&
                a_texture
                , const bool a_space );

            M_IMPL_MAKE_STRUCT(
                SImpl, TImpl )


        public:

            // Текстура
            NGE::CTexture m_texture;

            // Признак возможности
            // помещения объекта
            bool m_space;

            // Признак отсутствия объекта
            bool m_empty;

            // Признак сокрытия
            // объекта
            bool m_hiding;

            // Сущность, которая занимает
            // место
            CObject m_object;
    };
}




NWRD::CPlace::SImpl::SImpl(
    const NGE::CTexture& a_texture
    , const bool a_space )
    : m_texture( a_texture )
    , m_space( a_space )
    , m_empty( true )
    , m_object( CObject::f_MakeNull() ) {
}




namespace NWRD {
    M_IMPL_UNIQUE( CPlace, SImpl )
}




namespace NWRD {
    class CPlaceNowhere : public CPlace {
        public:
            explicit CPlaceNowhere()
                : CPlace(
                    NGE::CTexture(
                        NGE::CTexture
                        ::C_NOWHERE )
                    , false ) {
            }
    };



    class CPlaceGround : public CPlace {
        public:
            explicit CPlaceGround()
                : CPlace(
                    NGE::CTexture(
                        NGE::CTexture
                        ::C_GROUND )
                    , true ) {
            }
    };
}




NWRD::CPlace
NWRD::CPlace::f_MakeNowhere() {
    const auto nowhere = CPlaceNowhere();

    return nowhere;
}



NWRD::CPlace
NWRD::CPlace::f_MakeGround() {
    const auto ground = CPlaceGround();

    return ground;
}



NWRD::CPlace::CPlace(
    const NGE::CTexture& a_texture
    , const bool a_space )
    : m_impl(
        SImpl::f_Create(
            a_texture, a_space ) ) {
}



NGE::CTexture
NWRD::CPlace::f_GetTexture() const {

    // Убеждаемся, что в месте нет
    // нет объекта, или, что место
    // может скрывать объекты
    if ( f_IsEmpty() == false ) {

        // Берём текстуру от предмета
        //  у локации
        return m_impl->m_object
            .f_GetTexture();
    }


    return m_impl->m_texture;
}



bool NWRD::CPlace::f_IsSpace() const {
    return m_impl->m_space;
}



bool NWRD::CPlace::f_IsEmpty() const {
    return m_impl->m_object
        .f_IsNull() == true;
}



void NWRD::CPlace::f_SetEmpty(
    const bool a_value ) {
    m_impl->m_empty = a_value;
}



bool NWRD::CPlace::f_Take(
    const CObject& a_object ) {
    if ( m_impl->m_space == false ) {
        return false;
    }

    f_SetEmpty( false );
    m_impl->m_object = a_object;

    return true;
}



NWRD::CObject NWRD::CPlace::f_Free() {
    if ( f_IsEmpty() == true ) {
        return m_impl->m_object;
    }

    const auto object
        = m_impl->m_object;
    m_impl->m_object
        = CObject::f_MakeNull();

    f_SetEmpty( true );

    return object;
}



NWRD::CObject
NWRD::CPlace::f_GetObject() const {
    return m_impl->m_object;
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CPlace& a_place ) {
    const std::string space
        = a_place.f_IsSpace() == true
            ? "space"
            : "no space";

    const std::string empty
        = a_place.f_IsEmpty() == true
            ? "is empty"
            : "isn't empty";

    a_out << "\""
        << a_place.f_GetTexture()
        << "\": "
        << space
        << ": " << empty
        << " ("
        << a_place.f_GetObject() << ")";


    return a_out;
}
