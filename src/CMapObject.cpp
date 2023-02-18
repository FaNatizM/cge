#include "CMapObject.h"




class CMapObjectPrivate {
    public:
        explicit CMapObjectPrivate()
            : m_x( 0 )
            , m_y( 0 )
            , m_symbol( 'X' ) {
        }


    public:
        int m_x;
        int m_y;

        char m_symbol;
};




CMapObject::CMapObject()
    : m_impl( TMapObjectPrivate( new CMapObjectPrivate() ) ) {
}



void CMapObject::f_SetSymbol(const char sym) {
    m_impl->m_symbol = sym;
}

char& CMapObject::f_GetSymbol() const {
    return (char&)m_impl->m_symbol;
}

void CMapObject::f_SetXPos(const int x) {
    m_impl->m_x = x;
}

int& CMapObject::f_GetXPos() const {
    return (int&)m_impl->m_x;
}

void CMapObject::f_SetYPos(const int y) {
    m_impl->m_y = y;
}

int& CMapObject::f_GetYPos() const {
    return (int&)m_impl->m_y;
}
