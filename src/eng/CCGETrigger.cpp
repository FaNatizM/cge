#include <cge/eng/CCGETrigger.h>
#include <cge/HCGEMacroses.h>




namespace NCGE {
    class CTrigger::SImpl {
        protected:
            explicit SImpl() {
            }

        public:
            virtual ~SImpl() {
            }

            virtual const TEventEmitter&
                f_GetEventEmitter()
                const = 0;
    };



    class SImplOne
        : public CTrigger::SImpl {
        public:
            explicit SImplOne(
                const TCondition&
                    a_condition
                , const TAction&
                    a_action );

            M_MAKE_SHARED(
                SImplOne
                , CTrigger::TImpl )

            const TEventEmitter&
                f_GetEventEmitter()
                const override;


        public:
            TCondition m_condition;
            TAction m_action;
            TEventEmitter
                m_event_emitter;
    };



    class SImplElse
        : public CTrigger::SImpl {
        public:
            explicit SImplElse(
                const TCondition&
                    a_condition
                , const TAction&
                    a_action
                , const TAction&
                    a_action_else );

            M_MAKE_SHARED(
                SImplElse
                , CTrigger::TImpl )

            const TEventEmitter&
                f_GetEventEmitter()
                const override;


        public:
            TEventEmitter
                m_event_emitter;
            TCondition m_condition;
            TAction m_action;
            TAction m_action_else;
    };
}




using namespace NCGE;
SImplOne::SImplOne(
    const TCondition& a_condition
    , const TAction& a_action )
    : CTrigger::SImpl()
    , m_condition( a_condition )
    , m_action( a_action )
    , m_event_emitter(
        [ this ]() -> bool {
            if ( m_condition->f_Check()
                == true ) {
                m_action->f_Do();
                return true;
            }

            return false;
        }
    ) {
}



const TEventEmitter&
SImplOne::f_GetEventEmitter() const {
    return m_event_emitter;
}




SImplElse::SImplElse(
    const TCondition& a_condition
    , const TAction& a_action
    , const TAction& a_action_else )
    : CTrigger::SImpl()
    , m_condition( a_condition )
    , m_action( a_action )
    , m_action_else( a_action_else )
    , m_event_emitter(
        [ this ]() -> bool {
            if ( m_condition->f_Check()
                == true ) {
                m_action->f_Do();
                return true;
            } else {
                m_action_else->f_Do();
            }

            return false;
        }
    ) {
}



const TEventEmitter&
SImplElse::f_GetEventEmitter() const {
    return m_event_emitter;
}



CTrigger::CTrigger(
    const TCondition& a_condition
    , const TAction& a_action )
    : m_impl(
        SImplOne::f_Create(
            a_condition
            , a_action ) ) {
}



CTrigger::CTrigger(
    const TCondition& a_condition
    , const TAction& a_action
    , const TAction& a_action_else )
    : m_impl(
        SImplElse::f_Create(
            a_condition
            , a_action
            , a_action_else ) ) {
}



const TEventEmitter&
CTrigger::f_GetEventEmitter() const {
    return m_impl->f_GetEventEmitter();
}
