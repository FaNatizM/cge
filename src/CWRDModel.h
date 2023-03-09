#ifndef CWRDMODEL_H
#define CWRDMODEL_H


#include <memory>
#include <iostream>

#include "CWRDObject.h"




namespace NWRD {

    // Базовый класс модели объекта
    class CModel {
        M_IMPL_SHARED_V_DECL( CModel )


        public:
            using TOperation
                = std::function<
                    void( const CObject&)
                    >;


        public:
            virtual CObject f_GetObject(
                const int a_index = 0 )
                const = 0;

            virtual CPoint f_GetPoint(
                const int a_index = 0 )
                const = 0;

            virtual NGE::CTexture
            f_GetTexture(
                const int a_index = 0 )
                const = 0;

            virtual
            size_t f_GetObjectsCount()
                const = 0;

            // Обход всех объектов
            // модели
            virtual void f_Loop(
                const TOperation&
                a_operation ) = 0;

            // Перемещение модели
            virtual bool f_Move(
                const CPoint& a_point )
                = 0;

        protected:
            explicit CModel();
    };
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CModel& a_model );




#endif
