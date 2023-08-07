#ifndef CUI_H
#define CUI_H


#include <cge/CCGEUI.h>

#include "CGame.h"




namespace NSnake {
    class CCommandFactory
        : public
          NCGE::NUI::CCommandFactory {
        public:
            explicit CCommandFactory(
                const CGame& a_game );

        public:
            M_MAKE_SHARED(
                CCommandFactory
                , NCGE::NUI::TCommandFactory )

            NCGE::NUI::TCommand
                f_ProcessInput()
                override;


        private:
            M_IMPL_SHARED_STRUCT_IMPL()
    };
}




#endif
