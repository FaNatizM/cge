#ifndef CCGEEVENT_H
#define CCGEEVENT_H


#include <functional>




namespace NCGE {
    using TEventEmitter
        = std::function< bool() >;




    class CEventItem {
        public:
            enum class EType {
                E_Moved = 0
            };


        private:
            CEventItem() = delete;
    };
}




#endif
