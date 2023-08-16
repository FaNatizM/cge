#include "cge/eng/CCGEEventManagerItem.h"
#include <iostream>




using namespace NCGE;




CEventManagerItem::CEventManagerItem()
    : m_emitters() {
}



void CEventManagerItem
::f_AddEventEmitter(
    const CEventItem::EType a_event
    , const std::string& a_emitter_key
    , const TEventEmitter& a_emitter ) {
    auto event
        = m_emitters.find(
            a_event );

    if ( event == m_emitters.end() ) {
        m_emitters.emplace(
            a_event
            , SEventTypeEmitters(
                { {
                    a_emitter_key
                    , a_emitter } } ) );
        return;
    }


    event->second.m_emitters.emplace(
        a_emitter_key
        , a_emitter );
}



void CEventManagerItem::
    f_RemoveEventEmitter(
        const CEventItem::EType a_event
        , const std::string&
            a_emitter_key ) {
}



void CEventManagerItem::f_EmitEvent(
    const CEventItem::EType a_event ) {
    auto event
        = m_emitters.find(
            a_event );

    if ( event == m_emitters.end() ) {
        return;
    }


    auto emitter_itr = event->second
        .m_emitters.begin();
    while ( emitter_itr
        != event->second.m_emitters
            .end() ) {
        auto emitter
           = emitter_itr->second;
        emitter();
        emitter_itr++;
    }
}
