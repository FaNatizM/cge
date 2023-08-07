#include <iostream>

#include <cassert>

#include "CGame.h"
#include "CUI.h"




using namespace NSnake;




int main() {
    CGame game;
    const auto ui
        = NSnake::CCommandFactory::f_Create(
            game );

    NCGE::CEngine engine(
        ui
        , game.f_GetDrawer() );
    engine.f_Exec();


    return 0;
}
