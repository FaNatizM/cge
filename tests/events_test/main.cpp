#include <cassert>
#include <iostream>

#include <cge/eng/CCGEEventManagerItem.h>




using namespace NCGE;




bool f_TestEvents() {
    auto events_manager
        = CEventManagerItem();


    auto counter = 0;
    TEventEmitter emitter_1
        = [ &counter ]() -> bool {
        counter++;
    };
    events_manager.f_AddEventEmitter(
        CEventItem::EType::E_Moved
        , emitter_1 );


    TEventEmitter emitter_2
        = [ &counter ]() -> bool {
        counter++;
        counter++;
    };
    events_manager.f_AddEventEmitter(
        CEventItem::EType::E_Moved
        , emitter_2 );


    events_manager.f_EmitEvent(
        CEventItem::EType::E_Moved );


    assert( counter == 3 );
}



int main( int argc, char* argv[] ) {
    std::cout << argv[ 0 ]
        << std::endl << std::endl;

    f_TestEvents();
}
