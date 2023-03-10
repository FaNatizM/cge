#ifndef CWRDLOCATION_H
#define CWRDLOCATION_H


#include <memory>
#include <functional>

#include "HMacroses.h"
#include "CPoint.h"
#include "CGETexture.h"
#include "CWRDPlace.h"
#include "CWRDItem.h"




namespace NWRD {
    using TPlace
        = std::pair<
            const CPoint, CPlace >;

    using TOperation
        = std::function<
            void( const TPlace& ) >;


    using TItemNode = std::pair<
        const CEntityID, TItem >;

    using TItemOperation
        = std::function<
            void( const TItemNode& ) >;




    class CLocation {
        public:
            M_IMPL_SHARED_DECL(
                CLocation )

            explicit CLocation(
                const int a_width
                , const int a_height );

            static TOperation
            f_GetVisualOperation();

            int f_GetWidth() const;

            int f_GetHeight() const;

            bool f_ExistPlace(
                const CPoint& a_point
                ) const;

            NGE::CTexture
            f_GetTexture(
                const CPoint& a_point )
                const;

            bool f_IsEmpty(
                const CPoint& a_point )
                const;

            void f_Loop(
                const TOperation )
                const;

            void f_Loop(
                const TOperation
                , const CPoint& a_begin
                , const CPoint& a_end
                ) const;

            bool f_SetPlace(
                const CPoint& a_point
                , const CPlace&
                a_place );

            CEntityID f_AddItem(
                const TItem& a_item );

            TItem f_GetItem(
                const CEntityID& a_id ) const;

            bool f_MoveItem(
                const CEntityID& a_id
                , const CPoint& a_point );

            void f_LoopItems(
                const TItemOperation )
                const;


        private:
            M_IMPL_SHARED_STRUCT(
                SImpl, TImpl )
    };
}



std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CLocation& a_location );




#endif
