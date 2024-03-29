#include <cge/CCGEObject.h>




namespace NWRD {
    struct CObject::SImpl {
        public:
            explicit SImpl(
                const CPoint& a_point
                , const NCGE::CTexture&
                a_texture );

            M_IMPL_MAKE_STRUCT(
                SImpl, TImpl )


        public:

            // Точка
            CPoint m_point;

            // Текстура
            NCGE::CTexture m_texture;
    };
}




NWRD::CObject::SImpl::SImpl(
    const CPoint& a_point
    , const NCGE::CTexture& a_texture )
    : m_point( a_point )
    , m_texture( a_texture ) {
}




NWRD::CObject
NWRD::CObject::f_MakeNull() {
    static auto null
        = CObject();

    return null;
}



NWRD::CObject::CObject()
    : m_impl(
        SImpl::f_Create(
            CPoint()
            , NCGE::CTexture() ) ) {
}



NWRD::CObject::CObject(
    const CPoint& a_point
    , const NCGE::CTexture& a_texture )
    : m_impl(
        SImpl::f_Create(
            a_point, a_texture ) ) {
}



bool NWRD::CObject::operator==(
    const CObject& a_other ) const {
    if (
        ( f_GetPoint() == a_other.f_GetPoint() )
            == false ) {
        return false;
    }

    if (
        ( f_GetTexture() == a_other.f_GetTexture() )
            == false ) {
        return false;
    }


    return true;
}



bool NWRD::CObject::f_IsNull() const {
    if ( m_impl->m_point.f_IsNull()
        == true ) {
        return true;
    }

    if ( m_impl->m_texture
        .f_IsUndefined()
            == true ) {
        return true;
    }


    return false;
}



CPoint
NWRD::CObject::f_GetPoint() const {
    return m_impl->m_point;
}



void NWRD::CObject::f_SetPoint(
    const CPoint& a_point ) {
    m_impl->m_point = a_point;
}



NCGE::CTexture
NWRD::CObject::f_GetTexture() const {
    return m_impl->m_texture;
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CObject& a_object ) {

    a_out << a_object.f_GetPoint()
        << ": \""
        << a_object.f_GetTexture()
        << "\"";


    return a_out;
}
