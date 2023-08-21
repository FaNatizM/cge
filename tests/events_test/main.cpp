#include <cassert>
#include <iostream>

#include <cge/eng/CCGEEventManagerItem.h>
#include <cge/CCGEModelPoint.h>
#include <cge/CCGEModelChain.h>
#include <cge/CCGEViewer.h>
#include <cge/CCGEItemsCreator.h>




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



bool f_TestTriggerInLocation() {
    std::cout
        << "f_TestTriggerInLocation()\n";


    int one = 0;
    const auto action_test
        = CActionTest::f_Create( one );
    CTrigger trigger_test(
        CConditionTest::f_Create()
        , action_test );


    auto scene
        = NCGE::CScene( 3, 3 );
    auto location
        = NWRD::CLocation( 4, 4 );
    auto viewer
        = NWRD::CViewer(
            scene
            , location );

    const auto head = NWRD::CObject(
        CPoint( 0, 0 ), NCGE::CTexture( 'x' ) );
    const auto body = NWRD::CObject(
        CPoint( 1, 0 ), head.f_GetTexture() );
    const auto tail = NWRD::CObject(
        CPoint( 2, 0 ), head.f_GetTexture() );
    const auto model
        = NWRD::CModelChain::f_Create(
            head, body, tail
        );
    auto snake_creator
        = NWRD::CItemsCreator(
            NWRD::TItemType::EUndefined
            , model
    );

    auto snake = snake_creator.f_Create();
    auto snake_id
        = location.f_AddItem( snake );

    std::cout << "snake: "
        << snake << std::endl;

    location.f_AddTriggerToItem(
        snake_id
        , CEventItem::EType::E_Moved
        , std::make_pair(
            "test_trigger"
            , trigger_test ) );


    viewer.f_View();
    scene.f_Draw();


    // Проверка смещений
    auto f_Move
        = [ = ](
            NWRD::CLocation& a_location
            , const CPoint& a_point ) {
        assert( a_location.f_MoveItem(
            snake_id
            , a_point )
                == true );

        std::cout << "snake: "
            << snake << std::endl;

        assert(
            ( snake->f_GetPoint() == a_point )
                == true );


        viewer.f_View();
        scene.f_Draw();
    };


    assert( one == 0 );
    f_Move( location, CPoint( 0, 2 ) );
    assert(
        ( snake->f_GetPoint( 1 ) == CPoint( 1, 2 ) )
            == true );
    assert(
        ( snake->f_GetPoint( 2 ) == CPoint( 2, 2 ) )
            == true );


    assert( one == 1 );


    return true;
}



int main( int argc, char* argv[] ) {
    std::cout << argv[ 0 ]
        << std::endl << std::endl;

    f_TestEvents();
    assert( f_TestTrigger() == true );
    assert( f_TestTriggerInLocation() == true );
}
