#include <cge/CCGETexture.h>

#include <iostream>




namespace NCGE {
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




NCGE::CTexture::CTexture(
    const TTexture a_texture )
    : m_impl(
        std::make_shared< SImpl >(
            a_texture ) ) {
}



bool NCGE::CTexture::operator==(
    const CTexture& a_other ) const {
    if ( m_impl->m_texture
        != a_other.m_impl
            ->m_texture ) {
        return false;
    }


    return true;
}



bool NCGE::CTexture::f_IsUndefined(
    ) const {
    return m_impl->m_texture
        == C_UNDEFINED;
}



NCGE::TTexture NCGE::CTexture::f_Get()
    const {
        return m_impl->m_texture;
}



void NCGE::CTexture::f_Draw() const {
    std::cout << m_impl->m_texture;
}



std::ostream& operator<<(
    std::ostream& a_out
    , const NCGE::CTexture& a_texture ) {
    a_out << a_texture.f_Get();

    return a_out;
}

