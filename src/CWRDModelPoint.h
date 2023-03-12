#ifndef CWRDMODELPOINT_H
#define CWRDMODELPOINT_H


#include <iostream>

#include "CWRDModel.h"




namespace NWRD {
    M_POINTER_TYPE( CModelPoint, TModelPoint )



    // Модель сущности, которая содержит
    // один объект
    class CModelPoint : public CModel {
        M_IMPL_SHARED_DECL( CModelPoint )


        public:
            explicit CModelPoint(
                const CObject&
                a_object
                = CObject() );

        public:
            M_MAKE_SHARED( CModelPoint, TModelPoint )

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

            bool f_ContainsObject(
                const CObject& a_object )
                const override;

            size_t f_GetObjectsCount()
                const override;

            bool f_Loop(
                const TOperation&
                a_operation ) override;

            TPoints f_CheckMove(
                const CPoint& a_point )
                const override;

            bool f_Move(
                const TPoints& a_points )
                override;

            std::ostream& f_Visual(
                std::ostream& a_out )
                const override;

            static void f_Test();


        private:
            M_IMPL_SHARED_STRUCT(
                SImpl, TImpl )
    };
}




#endif
