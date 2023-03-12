#ifndef CWRDENTITY_H
#define CWRDENTITY_H


#include <memory>
#include <iostream>

#include "CWRDModel.h"
#include "CWRDEntityID.h"




namespace NWRD {
    M_POINTER_TYPE( CEntity, TEntity )



    class CEntity {
        M_IMPL_SHARED_V_DECL( CEntity )


        public:
            M_MAKE_SHARED( CEntity, TEntity )

            static CEntity f_MakeNull();

            bool f_IsEmpty() const;

            CEntityID f_GetID() const;

            CObject
            f_GetObject(
                const int a_index = 0 )
                const;

            void f_AddObject(
                const CObject&
                a_object );

            size_t f_GetObjectsCount()
                const;

            NGE::CTexture
            f_GetTexture(
                const int a_index = 0 )
                const;

            CPoint f_GetPoint(
                const int a_index = 0 )
                const;

            // Метод определения, содержит ли сущность объект
            bool f_ContainsObject(
                const CObject& a_object )
                const;

            virtual bool f_LoopModel(
                const CModel::TOperation&
                a_operation );

            // Функция вычисления перемещения
            // Определяет новое место куда
            // будет передвинута сущность
            // Если сдвигать нечего, то вернёт
            // пустой вектор
            virtual TPoints f_CheckMove(
                const CPoint& a_point )
                const;

            virtual bool f_Move(
                const TPoints& a_points );

            virtual
            std::ostream& f_Visual(
                std::ostream& a_out )
                const;

            static void f_Test();

        public:
            explicit CEntity(
                const TModel& a_model
                = CModel
                    ::f_Create() );


        private:
            M_IMPL_SHARED_STRUCT(
                SImpl, TImpl )
    };
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::TEntity& a_entity );



std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CEntity& a_entity );




#endif
