#ifndef CWRDMODEL_H
#define CWRDMODEL_H


#include <iostream>
#include <functional>

#include "CWRDObject.h"




namespace NWRD {
    M_POINTER_TYPE( CModel, TModel )



    // Базовый класс модели объекта
    class CModel {
        M_IMPL_SHARED_V_DECL( CModel )


        public:
            using TOperation
                = std::function<
                    bool( const CObject& )
                >;


        public:
            explicit CModel();

            M_MAKE_SHARED(
                CModel, TModel)

            virtual CObject f_GetObject(
                const int a_index = 0 )
                const;

            virtual CPoint f_GetPoint(
                const int a_index = 0 )
                const;

            virtual TPoints f_GetPoints() const;

            virtual NGE::CTexture
            f_GetTexture(
                const int a_index = 0 )
                const;

            virtual
            bool f_ContainsObject(
                const CObject& a_object )
                const;

            virtual
            size_t f_GetObjectsCount()
                const;

            // Обход всех объектов
            // модели
            virtual bool f_Loop(
                const TOperation&
                a_operation );

            virtual TPoints f_CheckMove(
                const CPoint& a_point
                , TPoints& a_points_free )
                const;

            // Перемещение модели
            virtual bool f_Move(
                const TPoints& a_points );

            virtual
            std::ostream& f_Visual(
                std::ostream& a_out )
                const;

            static void f_Test();
    };
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CModel& a_model );



std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::TModel& a_model );




#endif
