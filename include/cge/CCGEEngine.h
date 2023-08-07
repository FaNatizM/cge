#ifndef CCGEENGINE_H
#define CCGEENGINE_H

#include <memory>
#include <functional>

#include <cge/export.h>

#include <cge/CCGEUI.h>




// Движок
// Реализует цикл обработки
// пользовательского ввода
// и отрисовки экрана
namespace NCGE {
    using TDrawer
        = std::function< void() >;



    CGE_EXPORT class CEngine {
        public:
            explicit CEngine(
                const
                NUI::TCommandFactory&
                , const TDrawer& );

            // Цикл выполнения
            void f_Exec();


        private:
            M_IMPL_SHARED_STRUCT_IMPL()
    };
}




#endif
