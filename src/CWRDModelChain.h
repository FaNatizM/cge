#ifndef CWRDMODELCHAIN_H
#define CWRDMODELCHAIN_H


#include <iostream>

#include "CWRDModel.h"




namespace NWRD {
    M_POINTER_TYPE(
        CModelChain, TModelChain )



    // Модель сущности, которая содержит
    // цепочку объектов
    class CModelChain : public CModel {
        M_IMPL_SHARED_DECL( CModelChain )


        public:
            explicit CModelChain(
                const CObject& a_head
                , const CObject& a_body
                , const CObject& a_tail
            );

        public:
            M_MAKE_SHARED(
                CModelChain
                , TModelChain )

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
