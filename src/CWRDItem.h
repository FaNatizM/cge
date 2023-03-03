#ifndef CWRDITEM_H
#define CWRDITEM_H


#include <memory>
#include <iostream>

#include "HMacroses.h"
#include "CWRDEntity.h"




namespace NWRD {
    enum class TItemType {
        EUndefined = -1
    };




    class CItem : public CEntity {
        M_IMPL_SHARED_V_DECL( CItem )


        public:
            explicit CItem(
                const TItemType a_type
                    = TItemType::EUndefined
                , const NGE::CTexture& a_texture
                    = NGE::CTexture() );

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




#endif
