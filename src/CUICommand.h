#ifndef CUICOMMAND_H
#define CUICOMMAND_H


#include <memory>

#include "CMap.h"




namespace NUI {

    // Перечислитель для команды движени в определённую сторону
    enum class EMoveSide {
        E_Left = 0
        , E_Right
        , E_Top
        , E_Bottom
    };




    class CCommand;
    using TCommand = std::shared_ptr< CCommand >;



    // Абстрактная команда
    class CCommand {
        public:
            virtual ~CCommand() {
            }

            // Создание команды бездействия
            static TCommand f_Create( const CMap& a_map );

            // Создание команды движения
            static TCommand f_Create(
                const CMap& a_map
                , const EMoveSide a_side );

            // Создание команды выход
            static TCommand f_CreateExit( const CMap& a_map );

            // Если команду не удалось обработать,
            // то игра будет завершена
            virtual bool f_Execute() = 0;

        protected:
            explicit CCommand( const CMap& a_map );

            CMap& f_GetMap();


        private:
            CMap m_map;
    };
}




#endif
