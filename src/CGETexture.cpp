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



void NGE::CTexture::f_Draw() const {
    std::cout << m_impl->m_texture;
}
