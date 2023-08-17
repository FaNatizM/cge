#ifndef CCGEACTION_H
#define CCGEACTION_H


#include <memory>

#include <cge/HCGEMacroses.h>




namespace NCGE {
    M_POINTER_TYPE(
        CAction, TAction )
    class CAction {
        protected:
            explicit CAction();

        public:
            virtual ~CAction();

            virtual void f_Do() = 0;
    };
}




#endif
