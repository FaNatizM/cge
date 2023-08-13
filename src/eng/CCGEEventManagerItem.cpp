#include "cge/eng/CCGEEventManagerItem.h"




using namespace NCGE;




CEventManagerItem::CEventManagerItem() {
}



int CEventManagerItem::f_AddEventEmitter(
    const CEventItem::EType a_event
    , const TEventEmitter& a_emitter ) {
    return -1;
}



void CEventManagerItem::
    f_RemoveEventEmitter(
        const CEventItem::EType a_event
        , const int a_index ) {
}



void CEventManagerItem::f_EmitEvent(
    const CEventItem::EType a_event ) {
}
