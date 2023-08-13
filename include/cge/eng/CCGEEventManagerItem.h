#ifndef CCGEEVRNTMANSGETITEM_H
#define CCGEEVRNTMANSGETITEM_H


#include <map>
#include <list>

#include "CCGEEvent.h"




namespace NCGE {
    struct SEventEmitters {
        std::list< TEventEmitter >
            m_emitters;
    };




    class CEventManagerItem {
        public:
            explicit CEventManagerItem();

            int f_AddEventEmitter(
                const CEventItem::EType
                , const TEventEmitter& );

            void f_RemoveEventEmitter(
                const CEventItem::EType
                , const int a_index );

            void f_EmitEvent(
                const CEventItem::EType
            );


        private:

            // На каждый вид события набор
            using TEventsEmitters
             = std::map<
                CEventItem::EType
                , SEventEmitters >;
    };
}




#endif
