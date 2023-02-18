#ifndef CMAP_H
#define CMAP_H


#include "CMapObject.h"




// Карта
class CMap {
    public:
        explicit CMap( char, int, int, const CMapObject& );

        char& f_GetSymbol() const;
        void f_SetSymbol( const char );

        int& f_GetWidth() const;
        void f_SetWidth( const int );

        int& f_GetHeight() const;
        void f_SetHeight( const int );

        CMapObject& f_GetObject() const;
        void f_SetObject( CMapObject );


    private:

        // Закрыть в std::unique_ptr
        char fillSymbol;

        int width;
        int height;

        CMapObject object;
};




#endif
