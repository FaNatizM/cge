#include "CWRDObject.h"




namespace NWRD {
    struct CObject::SImpl {
        public:
            explicit SImpl(
                const CPoint& a_point
                , const NGE::CTexture&
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

            // Точка
            CPoint m_point;

            // Текстура
            NGE::CTexture m_texture;
    };
}




NWRD::CObject::SImpl::SImpl(
    const CPoint& a_point
    , const NGE::CTexture& a_texture )
    : m_point( a_point )
    , m_texture( a_texture ) {
}




namespace NWRD {
    M_IMPL_UNIQUE( CObject, SImpl )
}




NWRD::CObject::CObject(
    const CPoint& a_point
    , const NGE::CTexture& a_texture )
    : m_impl(
        SImpl::f_Create(
            a_point, a_texture ) ) {
}



CPoint
NWRD::CObject::f_GetPoint() const {
    return m_impl->m_point;
}



NGE::CTexture
NWRD::CObject::f_GetTexture() const {
    return m_impl->m_texture;
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::TObject& a_object ) {

    a_out << a_object.f_GetPoint()
        << "\""
        << a_object.f_GetTexture()
        << "\"";


    return a_out;
}
