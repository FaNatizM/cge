#include <cge/CCGEUICommand.h>

#include <iostream>




using namespace NCGE::NUI;
namespace NCGE {
    namespace NUI {
        class CCommandNothing
            : public CCommand {
            public:
                explicit
                    CCommandNothing()
                    : CCommand() {
                }

                bool f_Execute()
                    override {
                    return false;
                }
        };



        class CCommandExit
            : public CCommand {
            public:
                explicit
                    CCommandExit()
                    : CCommand() {
                }

                bool f_Execute()
                    override {
                    return false;
                }
        };
    }
}




CCommand::CCommand() {
}



CCommand::~CCommand() {
}



TCommand CCommand::f_Make() {
    return TCommand(
        new CCommandNothing() );
}


TCommand CCommand::f_MakeExit() {
    return TCommand(
        new CCommandExit() );
}
