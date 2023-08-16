#include <cassert>
#include <iostream>

#include <cge/eng/CCGEEventManagerItem.h>




using namespace NCGE;




bool f_TestEvents() {
    std::cout << "f_TestEvents()\n";
    auto events_manager
        = CEventManagerItem();


    auto counter = 0;
    TEventEmitter emitter_1
        = [ &counter ]() -> bool {
        counter++;
        return true;
    };

    events_manager.f_AddEventEmitter(
        CEventItem::EType::E_Moved
        , "emitter_1"
        , emitter_1 );


    TEventEmitter emitter_2
        = [ &counter ]() -> bool {
        counter++;
        counter++;
        return true;
    };
    events_manager.f_AddEventEmitter(
        CEventItem::EType::E_Moved
        , "emitter_2"
        , emitter_2 );


    events_manager.f_EmitEvent(
        CEventItem::EType::E_Moved );


    assert( counter == 3 );


    return true;
}



int main( int argc, char* argv[] ) {
    std::cout << argv[ 0 ]
        << std::endl << std::endl;

    f_TestEvents();
}
