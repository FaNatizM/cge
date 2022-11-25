#ifndef CMAPOBJECT_H
#define CMAPOBJECT_H

#include <memory>



class CMapObjectPrivate;
using TMapObjectPrivate = std::shared_ptr< CMapObjectPrivate >;



class CMapObject {
    public:
        explicit CMapObject();

        char& f_GetSymbol() const;
        void f_SetSymbol(const char);

        int& f_GetXPos() const;
        void f_SetXPos(const int);

        int& f_GetYPos() const;
        void f_SetYPos(const int);

    private:
        TMapObjectPrivate m_impl;
};




#endif
