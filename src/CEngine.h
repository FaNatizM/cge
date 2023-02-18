#ifndef CENGINE_H
#define CENGINE_H

#include <memory>

#include "CMap.h"




// Движок
// Реализует цикл обработки пользовательского ввода и отрисовки экрана
class CEnginePrivate;
using TEnginePrivate = std::shared_ptr< CEnginePrivate >;



class CEngine {
    public:
        explicit CEngine( const CMap& a_map );

        // Цикл выполнения
        void f_Exec();

    private:
        TEnginePrivate m_impl;
};




#endif
