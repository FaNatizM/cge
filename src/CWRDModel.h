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
                    void( const CObject&)
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

            virtual NGE::CTexture
            f_GetTexture(
                const int a_index = 0 )
                const;

            virtual
            size_t f_GetObjectsCount()
                const;

            // Обход всех объектов
            // модели
            virtual void f_Loop(
                const TOperation&
                a_operation );

            // Перемещение модели
            virtual bool f_Move(
                const CPoint& a_point );

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
