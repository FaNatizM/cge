#ifndef CCGETRIGGER_H
#define CCGETRIGGER_H


#include <memory>

#include "CCGEEvent.h"
#include "CCGECondition.h"
#include "CCGEAction.h"




namespace NCGE {
    class CTrigger {
        public:
            explicit CTrigger(
                const TCondition&
                , const TAction& );

            explicit CTrigger(
                const TCondition&
                , const TAction&
                , const TAction& );

            const TEventEmitter&
                f_GetEventEmitter()
                const;


        public:
            struct SImpl;
            using TImpl
                = std::shared_ptr<
                    SImpl >;

        private:
            TImpl m_impl;

    };
}




#endif
