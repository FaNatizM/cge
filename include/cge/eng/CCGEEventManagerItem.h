#ifndef CCGEEVRNTMANSGETITEM_H
#define CCGEEVRNTMANSGETITEM_H


#include <map>
#include <string>

#include "CCGEEvent.h"




namespace NCGE {
    using TEventEmittersPool
        = std::map<
            std::string
            , TEventEmitter >;

    struct SEventTypeEmitters {
        explicit SEventTypeEmitters(
            const TEventEmittersPool&
            a_emitters )
            : m_emitters( a_emitters ) {
        }


        TEventEmittersPool m_emitters;
    };




    class CEventManagerItem {
        public:
            explicit CEventManagerItem();

            void f_AddEventEmitter(
                const CEventItem::EType
                , const std::string&
                , const TEventEmitter& );

            void f_RemoveEventEmitter(
                const CEventItem::EType
                , const std::string& );

            void f_EmitEvent(
                const CEventItem::EType
            );


        private:

            // На каждый вид события
            // набор
            using TEventsEmitters
             = std::map<
                CEventItem::EType
                , SEventTypeEmitters >;
            TEventsEmitters m_emitters;
    };
}




#endif
