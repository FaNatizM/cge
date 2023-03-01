#include "CWRDPlace.h"




namespace NWRD {
    struct CPlace::SImpl {
        public:
            explicit SImpl(
                const NGE::CTexture&
                a_texture
                , const bool a_space );

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
    };
}




NWRD::CPlace::SImpl::SImpl(
    const NGE::CTexture& a_texture
    , const bool a_space )
    : m_texture( a_texture )
    , m_space( a_space )
    , m_empty( true ) {
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
                        '~' )
                    , false ) {
            }
    };



    class CPlaceGround : public CPlace {
        public:
            explicit CPlaceGround()
                : CPlace(
                    NGE::CTexture(
                        '.' )
                    , true ) {
            }
    };
}




NWRD::TPlace
NWRD::CPlace::f_MakeNowhere() {
    static auto nowhere =
        std::make_shared<
            CPlaceNowhere >();

    return nowhere;
}



NWRD::TPlace
NWRD::CPlace::f_MakeGround() {
    static auto ground =
        std::make_shared<
            CPlaceGround >();

    return ground;
}



NGE::CTexture
NWRD::CPlace::f_GetTexture() const {
    return m_impl->m_texture;
}



bool NWRD::CPlace::f_IsSpace() const {
    return m_impl->m_space;
}



bool NWRD::CPlace::f_IsEmpty() const {
    return m_impl->m_empty;
}



NWRD::CPlace::CPlace(
    const NGE::CTexture& a_texture
    , const bool a_space )
    : m_impl(
        SImpl::f_Create(
            a_texture, a_space ) ) {
}



void NWRD::CPlace::f_SetEmpty(
    const bool a_value ) {
    m_impl->m_empty = a_value;
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::TPlace& a_place ) {
    const std::string space
        = a_place->f_IsSpace() == true
            ? "space"
            : "no space";

    const std::string empty
        = a_place->f_IsEmpty() == true
            ? "is empty"
            : "isn't empty";

    a_out << "\""
        << a_place->f_GetTexture()
        << "\": "
        << space
        << ": " << empty;


    return a_out;
}
