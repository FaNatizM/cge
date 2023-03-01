#ifndef CGESCENE_H
#define CGESCENE_H




// Graphic Engine namespace
namespace NGE {

    // Класс сцены, на которой происходит отрисовка
    //  Сцена отрисовывается по узлам
    //  В каждом узле отрисовывается конкретный символ
    class CScene {
        public:

            // Настройка сцены
            static void f_Configure(
                const int a_width
                , const int a_height );

            // Задание текстуры по координатам
            static void f_SetTexture(
                const int a_x
                , const int a_y
                , const CTexture& a_texture );

            // Отрисовка сцены
            static void f_Repaint();


        private:
            explicit CScene();
    };
}




#endif
