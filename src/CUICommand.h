#ifndef CUICOMMAND_H
#define CUICOMMAND_H


#include <memory>

#include "CGame.h"




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
            static TCommand f_Create( const CGame& a_game );

            // Создание команды движения
            static TCommand f_Create(
                const CGame& a_game
                , const EMoveSide a_side );

            // Создание команды выход
            static TCommand f_CreateExit( const CGame& a_game );

            // Если команду не удалось обработать,
            // то игра будет завершена
            virtual bool f_Execute() = 0;

        protected:
            explicit CCommand( const CGame& a_game );

            CGame& f_GetGame();


        private:
            CGame m_game;
    };
}




#endif
