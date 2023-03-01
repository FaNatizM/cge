#include "CGETexture.h"

#include <iostream>




namespace NGE {
    struct CTexture::SImpl {
        public:
            explicit SImpl(
                const TTexture a_texture )
                : m_texture( a_texture ) {
            }


        public:
            TTexture m_texture;
    };
}




NGE::CTexture::CTexture(
    const TTexture a_texture )
    : m_impl(
        std::make_shared< SImpl >(
            a_texture ) ) {
}



bool NGE::CTexture::operator==(
    const CTexture& a_other ) const {
    if ( m_impl->m_texture
        != a_other.m_impl
            ->m_texture ) {
        return false;
    }


    return true;
}



NGE::TTexture NGE::CTexture::f_Get()
    const {
        return m_impl->m_texture;
}



void NGE::CTexture::f_Draw() const {
    std::cout << m_impl->m_texture;
}



std::ostream& operator<<(
    std::ostream& a_out
    , const NGE::CTexture& a_texture ) {
    a_out << a_texture.f_Get();

    return a_out;
}

