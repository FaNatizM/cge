#ifndef CCGEITEM_H
#define CCGEITEM_H


#include <iostream>

#include <cge/CCGEEntity.h>




namespace NWRD {
    enum class TItemType {
        EUndefined = -1
    };





    M_POINTER_TYPE( CItem, TItem )



    class CItem : public CEntity {
        M_IMPL_SHARED_V_DECL( CItem )


        public:
            explicit CItem(
                const TItemType a_type
                    = TItemType
                        ::EUndefined
                , const TModel&
                    a_model
                    = CModel::f_Create() );

        public:
            M_MAKE_SHARED(
                CItem, TItem )

            TItemType f_GetType() const;

            bool f_IsUndefined() const;

            static bool f_Test();


        private:
            M_IMPL_SHARED_STRUCT(
                SImpl, TImpl )
    };
}




std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CItem& a_item );



std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::TItem& a_item );




#endif
