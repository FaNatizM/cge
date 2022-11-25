#ifndef CENGINE_H
#define CENGINE_H

#include "CMap.h"




// ����� ��� ��������� �������� ������������ � ���������� ����������
class CEngine {
    public:
        explicit CEngine( const CMap& a_map );

        bool inputAscii( CMapObject&, int, int );

        void f_Draw();

        // ����������� ���� ����������
        void f_Exec();

    private:
        CMap m_map;
        int ascii;
};




#endif
