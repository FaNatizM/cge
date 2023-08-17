#ifndef CCGECONDITION_H
#define CCGECONDITION_H


#include <memory>
#include <cge/HCGEMacroses.h>




namespace NCGE {
    M_POINTER_TYPE(
        CCondition, TCondition )
    class CCondition {
        protected:
            explicit CCondition();

        public:
            virtual ~CCondition();

            virtual bool f_Check() = 0;
    };
}




#endif
