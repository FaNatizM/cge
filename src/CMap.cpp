#include "CMap.h"


void CMap::f_SetSymbol(const char sym) {
    this->fillSymbol = sym;
}

char& CMap::f_GetSymbol() const {
    return (char&)this->fillSymbol;
}

void CMap::f_SetWidth(const int x) {
    this->width = x;
}

int& CMap::f_GetWidth() const {
    return (int&)this->width;
}

void CMap::f_SetHeight(const int y) {
    this->height = y;
}

int& CMap::f_GetHeight() const {
    return (int&)this->height;
}

void CMap::f_SetObject(CMapObject obj) {
    this->object = obj;
}

CMapObject& CMap::f_GetObject() const {
    return (CMapObject&)this->object;
}



CMap::CMap(char fill, int x_len, int y_len, const CMapObject& obj) {
    this->width = x_len;
    this->height = y_len;
    this->fillSymbol = fill;
    this->object = obj;
}
