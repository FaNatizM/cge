#ifndef CWRDMODELPOINT_H
#define CWRDMODELPOINT_H


#include <memory>
#include <iostream>

#include "CWRDModel.h"




namespace NWRD {

    // Модель сущности, которая содержит
    // один объект
    class CModelPoint {
        M_IMPL_SHARED_DECL( CModelPoint )


        public:
            explicit CModelPoint(
                const CObject&
                a_object );

            CObject
            f_GetObject(
                const int a_index = 0 )
                const override;

            CPoint f_GetPoint(
                const int a_index = 0 )
                const override;

            NGE::CTexture
            f_GetTexture(
                const int a_index = 0 )
                const override;

            size_t f_GetObjectsCount()
                const override;

            void f_Loop(
                const TOperation&
                a_operation ) override;

            bool f_Move(
                const CPoint& a_point )
                override;

            static void f_Test();


        private:
            M_IMPL_SHARED_STRUCT(
                SImpl, TImpl )
    };
}




#endif
