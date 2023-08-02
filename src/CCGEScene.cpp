#include "CCGEScene.h"

#include <iostream>
#include <map>
#include <cassert>
#include <algorithm>




namespace NGE {
    using TNodes = std::map<
        CPoint, CTexture >;




    struct CScene::SImpl {
        public:
            explicit SImpl(
                const int a_width
                , const int a_height )
                : m_width( a_width )
                , m_height( a_height )
                , m_nodes() {

                if ( m_width <= 0 ) {
                    m_width = 1;
                }

                if ( m_height <= 0 ) {
                    m_height = 1;
                }

                f_InitNodes();
            }

            template< typename... Types >
            static TImpl f_Create(
                Types&& ... a_params ) {
                return std::make_shared<
                    SImpl >(
                        std::forward<
                            Types >(
                                a_params )
                                ... );
            }

            static CTexture
            f_GetTexture();

            void f_InitNodes();


        public:
            int m_width;
            int m_height;
            TNodes m_nodes;
    };
}




NGE::CTexture
NGE::CScene::SImpl::f_GetTexture() {
    static auto texture
        = CTexture();
    return texture;
}



void NGE::CScene::SImpl::f_InitNodes() {
    auto size
        = m_width * m_height;
    for ( int row = 0
        ; row < m_height
        ; row++ ) {
        for ( int column = 0
            ; column < m_width
            ; column++ ) {

            const auto point
                = CPoint( column, row );
            const auto texture
                = f_GetTexture();
            m_nodes[ point ]
                = texture;
        }
    }

    assert( m_nodes.size() == size );
}




NGE::CScene::CScene(
    const int a_width
    , const int a_height )
    : m_impl(
        SImpl::f_Create(
            a_width
            , a_height ) ) {
}



NGE::CScene::TOperation
NGE::CScene::
f_GetVisualOperation() {
    static TOperation f_VisualNode
        = [ = ]( const TNode& a_node )
            -> void {
        std::cout << a_node.first
            << ": " << a_node.second
            << std::endl;
    };

    return f_VisualNode;
}



int NGE::CScene::f_GetWidth() const {
    return m_impl->m_width;
}



int NGE::CScene::f_GetHeight() const {
    return m_impl->m_height;
}



void NGE::CScene::f_Draw() const {
    std::cout << std::endl;

    auto counter = 1;
    for ( auto& node
        : m_impl->m_nodes ) {
        node.second.f_Draw();
        std::cout << " ";

        if ( counter % m_impl->m_width
            == 0 ) {
            std::cout << std::endl;
        }

        counter++;
    }

    std::cout << std::endl;
}



NGE::CTexture NGE::CScene::f_GetTexture(
    const CPoint& a_point )
    const {

    auto node
        = m_impl->m_nodes.find(
            a_point );

    if ( node
        == m_impl->m_nodes.end() ) {
        return CTexture();
    }


    return m_impl->m_nodes[ a_point ];
}



bool NGE::CScene::f_SetTexture(
    const CPoint& a_point
    , const CTexture& a_texture ) {

    // std::cout << a_point << std::endl;

    const auto node
        = m_impl->m_nodes.find(
            a_point );

    if ( node
        == m_impl->m_nodes.end() ) {
        std::cout
            << "NWRD::CScene::"
            << "f_SetTexture: "
            << a_point
            << ": " << a_texture
            << " isn't existed!\n";
        return false;
    }


    m_impl->m_nodes[ a_point ]
        = a_texture;


    return true;
}



void NGE::CScene::f_Loop(
    const TOperation&
        a_operation ) {
    auto begin
        = m_impl->m_nodes.begin();
    auto end
        = m_impl->m_nodes.end();

    std::for_each(
        begin
        , end
        , a_operation );
}



void NGE::CScene::f_LoopConst(
    const TOperation&
        a_operation ) const {
    auto begin
        = m_impl->m_nodes.begin();
    auto end
        = m_impl->m_nodes.end();

    std::for_each(
        begin
        , end
        , a_operation );
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NGE::CScene& a_scene ) {
    a_scene.f_LoopConst(
        NGE::CScene::
        f_GetVisualOperation() );

    return a_out;
}
