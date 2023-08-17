#include <cassert>
#include <iostream>

#include <cge/eng/CCGEEventManagerItem.h>
#include <cge/eng/CCGETrigger.h>




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




namespace {
    using namespace NCGE;




    struct CConditionTest
        : public CCondition {
        explicit CConditionTest()
            : CCondition() {
        }

        M_MAKE_SHARED(
            CConditionTest
            , TCondition )

        bool f_Check() const override {
            return true;
        }
    };


    struct CActionTest
        : public CAction {
        explicit CActionTest(
            int& a_one )
            : CAction()
            , m_one( a_one ) {
        }

        M_MAKE_SHARED(
            CActionTest
            , TAction )

        void f_Do() override {
            m_one = 1;
        }


        int& m_one;
    };
}



bool f_TestTrigger() {
    std::cout << "f_TestTrigger()\n";


    int one = 0;
    const auto action_test
        = CActionTest::f_Create( one );
    CTrigger trigger_test(
        CConditionTest::f_Create()
        , action_test );


    assert( one == 0 );
    trigger_test.f_GetEventEmitter()();


    assert( one == 1 );


    return true;
}



int main( int argc, char* argv[] ) {
    std::cout << argv[ 0 ]
        << std::endl << std::endl;

    f_TestEvents();
    assert( f_TestTrigger() == true );
}
