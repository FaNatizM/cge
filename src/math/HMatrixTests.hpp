#ifndef HBOUNDSMATRIXTESTS_H
#define HBOUNDSMATRIXTESTS_H


#include <cassert>

#include "CBoundsMatrix.hpp"
#include "CSquareMatrix.hpp"
#include "HMatrixOperations.hpp"




namespace HMatrix {

    /**
     * @brief f_TestsBoundsMatrix -- функция для тестирования прямоугольной матрицы
     */
    void f_TestsBoundsMatrix() {
        std::cout << std::endl << std::endl << "Тестирование прямоугольных матриц..." << std::endl;


        // Общие операции с матрицами
        // Проверяем корректность создания пустой матрицы
        CBoundsMatrix<int> matrix_empty;
        assert( matrix_empty.f_IsEmplty() == true );
        assert( matrix_empty.f_GetRowsCount() == 0 );
        assert( matrix_empty.f_GetColumnsCount() == 0 );
        assert( matrix_empty.f_GetElementsCount() == 0 );
        assert( matrix_empty.f_GetElement( 0, 0 ) == 0 );


        // Проверяем корректность создания матрицы
        CBoundsMatrix<int> matrix( 3, 2 );
        assert( matrix.f_IsEmplty() == false );
        assert( matrix.f_GetRowsCount() == 3 );
        assert( matrix.f_GetColumnsCount() == 2 );
        assert( matrix.f_GetElement( 0, 0 ) == 0 );
        assert( matrix.f_GetElement( 0, 1 ) == 1 );
        assert( matrix.f_GetElement( 1, 0 ) == 2 );
        assert( matrix.f_GetElement( 1, 1 ) == 3 );
        assert( matrix.f_GetElement( 2, 0 ) == 4 );
        assert( matrix.f_GetElement( 2, 1 ) == 5 );
        assert( matrix.f_GetElementsCount() == 6 );


        // Проверяем корректность изменения элемента
        assert( matrix.f_SetElement( 2, 0, 44 ) == true );
        assert( matrix.f_GetElement( 2, 0 ) == 44 );


        // Проверяем корректность изменения несуществующего в матрице элемента
        assert( matrix.f_SetElement( 3, 3, 55 ) == false );
        assert( matrix.f_GetElement( 3, 3 ) == 0 );


        // Проверяем корректность транспонирования
        matrix.f_Transpon();
        assert( matrix.f_GetElement( 0, 0 ) == 0 );
        assert( matrix.f_GetElement( 0, 1 ) == 2 );
        assert( matrix.f_GetElement( 0, 2 ) == 44 );
        assert( matrix.f_GetElement( 1, 0 ) == 1 );
        assert( matrix.f_GetElement( 1, 1 ) == 3 );
        assert( matrix.f_GetElement( 1, 2 ) == 5 );


        // Проверяем корректность создания матрицы через массив элементов
        const std::vector<int> elements = { 1, 2, 3
                                            , 4, 5, 6
                                            , 7, 8, 9
                                            , 10, 11, 12 };
        CBoundsMatrix<int> matrix_hand( elements, 4, 3 );
        assert( matrix_hand.f_IsEmplty() == false );
        assert( matrix_hand.f_GetRowsCount() == 4 );
        assert( matrix_hand.f_GetColumnsCount() == 3 );
        assert( matrix_hand.f_GetElement( 0, 0 ) == 1 );
        assert( matrix_hand.f_GetElement( 0, 1 ) == 2 );
        assert( matrix_hand.f_GetElement( 0, 2 ) == 3 );
        assert( matrix_hand.f_GetElement( 1, 0 ) == 4 );
        assert( matrix_hand.f_GetElement( 1, 1 ) == 5 );
        assert( matrix_hand.f_GetElement( 1, 2 ) == 6 );
        assert( matrix_hand.f_GetElement( 2, 0 ) == 7 );
        assert( matrix_hand.f_GetElement( 2, 1 ) == 8 );
        assert( matrix_hand.f_GetElement( 2, 2 ) == 9 );
        assert( matrix_hand.f_GetElement( 3, 0 ) == 10 );
        assert( matrix_hand.f_GetElement( 3, 1 ) == 11 );
        assert( matrix_hand.f_GetElement( 3, 2 ) == 12 );
        assert( matrix_hand.f_GetElementsCount() == 12 );


        // Проверяем случай несовпадения количества элементов в инициализирующем массиве с количеством элементов в матрицу
        CBoundsMatrix<int> matrix_hand_incorrect( elements, 3, 2 );
        assert( matrix_hand_incorrect.f_IsEmplty() == false );
        assert( matrix_hand_incorrect.f_GetRowsCount() == 3 );
        assert( matrix_hand_incorrect.f_GetColumnsCount() == 2 );
        assert( matrix_hand_incorrect.f_GetElement( 0, 0 ) == 0 );
        assert( matrix_hand_incorrect.f_GetElement( 0, 1 ) == 1 );
        assert( matrix_hand_incorrect.f_GetElement( 1, 0 ) == 2 );
        assert( matrix_hand_incorrect.f_GetElement( 1, 1 ) == 3 );
        assert( matrix_hand_incorrect.f_GetElement( 2, 0 ) == 4 );
        assert( matrix_hand_incorrect.f_GetElement( 2, 1 ) == 5 );
        assert( matrix_hand_incorrect.f_GetElementsCount() == 6 );
    }



    /**
     * @brief f_TestsSquareMatrix -- тестирование квадратных матриц
     */
    void f_TestsSquareMatrix() {
        std::cout << std::endl << std::endl << "Тестирование квадратных матриц..." << std::endl;


        // Общие операции с матрицами
        // Проверяем корректность создания пустой матрицы
        CSquareMatrix<int> matrix_empty;
        assert( matrix_empty.f_IsEmplty() == true );
        assert( matrix_empty.f_GetSize() == 0 );
        assert( matrix_empty.f_GetRowsCount() == 0 );
        assert( matrix_empty.f_GetColumnsCount() == 0 );
        assert( matrix_empty.f_GetElementsCount() == 0 );
        assert( matrix_empty.f_GetElement( 0, 0 ) == 0 );

        // Проверяем корректность создания матрицы
        CSquareMatrix<int> matrix( 2 );
        assert( matrix.f_IsEmplty() == false );
        assert( matrix.f_GetSize() == 2 );
        assert( matrix.f_GetRowsCount() == 2 );
        assert( matrix.f_GetColumnsCount() == 2 );
        assert( matrix.f_GetElement( 0, 0 ) == 0 );
        assert( matrix.f_GetElement( 0, 1 ) == 1 );
        assert( matrix.f_GetElement( 1, 0 ) == 2 );
        assert( matrix.f_GetElement( 1, 1 ) == 3 );


        // Проверяем вычисление определителя
        int det = 0;

        // Для пустой матрицы
        CSquareMatrix<int> matrix_0x0( 0 );
        assert( matrix_0x0.f_GetDet( &det ) == false );
        assert( det == 0 );

        // Для матрицы 1x1
        CSquareMatrix<int> matrix_1x1( 1 );
        assert( matrix_1x1.f_GetDet( &det ) == true );
        assert( det == matrix_1x1.f_GetElement( 0, 0 ) );

        // Для матрицы 2x2
        CSquareMatrix<int> matrix_2x2( 2 );
        assert( matrix_2x2.f_GetDet( &det ) == true );
        int det_2x2 = ( matrix_2x2.f_GetElement( 0, 0 ) * matrix_2x2.f_GetElement( 1, 1 )
                        - matrix_2x2.f_GetElement( 1, 0 ) * matrix_2x2.f_GetElement( 0, 1 ) );
        assert( det == det_2x2 );

        // Для матрицы 3x3
        CSquareMatrix<int> matrix_3x3( 3 );
        assert( matrix_3x3.f_GetDet( &det ) == true );
        assert( det == 0 );

        // Для матрицы 4x4
        CSquareMatrix<int> matrix_4x4( 4 );
        matrix_4x4.f_SetElement( 0, 0, 2 );
        matrix_4x4.f_SetElement( 0, 1, 2 );
        matrix_4x4.f_SetElement( 0, 2, 4 );
        matrix_4x4.f_SetElement( 0, 3, 5 );

        matrix_4x4.f_SetElement( 1, 0, 1 );
        matrix_4x4.f_SetElement( 1, 1, 0 );
        matrix_4x4.f_SetElement( 1, 2, 5 );
        matrix_4x4.f_SetElement( 1, 3, 0 );

        matrix_4x4.f_SetElement( 2, 0, 0 );
        matrix_4x4.f_SetElement( 2, 1, 3 );
        matrix_4x4.f_SetElement( 2, 2, 0 );
        matrix_4x4.f_SetElement( 2, 3, 9 );

        matrix_4x4.f_SetElement( 3, 0, 0 );
        matrix_4x4.f_SetElement( 3, 1, -2 );
        matrix_4x4.f_SetElement( 3, 2, 0 );
        matrix_4x4.f_SetElement( 3, 3, 7 );

        assert( matrix_4x4.f_GetDet( &det ) == true );
        assert( det == -234 );
    }



    // Функции тестов
    /**
     * @brief f_TestTriangulation_1 -- тест тринагуляции 1-м наборе матриц
     */
    void f_TestTriangulation_1() {
        std::cout << std::endl << std::endl << "Тестирование алгоритма триангуляции..." << std::endl;

        // Тестируем создание пустой матрицы
        CMatrixTwoColumns<double> matrix_nx2_empty( 0 );
        assert( matrix_nx2_empty.f_IsEmplty() == true );
        assert( matrix_nx2_empty.f_GetRowsCount() == 0 );
        assert( matrix_nx2_empty.f_GetColumnsCount() == 2 );
        assert( matrix_nx2_empty.f_GetElement( 0, 0 ) == 0 );

        // Тестируем создание пустой матрицы
        CMatrixOneColumn<double> matrix_nx1_empty( 0 );
        assert( matrix_nx1_empty.f_IsEmplty() == true );
        assert( matrix_nx1_empty.f_GetRowsCount() == 0 );
        assert( matrix_nx1_empty.f_GetColumnsCount() == 1 );
        assert( matrix_nx1_empty.f_GetElement( 0, 0 ) == 0 );


        // Заполняем первую матрицу 3x2
        CMatrixTwoColumns<double> matrix_3x2( 3 );
        assert( matrix_3x2.f_IsEmplty() == false );
        assert( matrix_3x2.f_GetRowsCount() == 3 );
        assert( matrix_3x2.f_GetColumnsCount() == 2 );
        matrix_3x2.f_SetElement( 0, 0, 1.0 );
        matrix_3x2.f_SetElement( 0, 1, 2.0 );
        matrix_3x2.f_SetElement( 1, 0, 3.0 );
        matrix_3x2.f_SetElement( 1, 1, 4.0 );
        matrix_3x2.f_SetElement( 2, 0, 5.0 );
        matrix_3x2.f_SetElement( 2, 1, 6.0 );
        assert( matrix_3x2.f_GetElement( 0, 0 ) == 1.0 );
        assert( matrix_3x2.f_GetElement( 0, 1 ) == 2.0 );
        assert( matrix_3x2.f_GetElement( 1, 0 ) == 3.0 );
        assert( matrix_3x2.f_GetElement( 1, 1 ) == 4.0 );
        assert( matrix_3x2.f_GetElement( 2, 0 ) == 5.0 );
        assert( matrix_3x2.f_GetElement( 2, 1 ) == 6.0 );


        // Заполняем вторую матрицу
        CMatrixOneColumn<double> matrix_3x1( 3 );
        assert( matrix_3x1.f_IsEmplty() == false );
        assert( matrix_3x1.f_GetRowsCount() == 3 );
        assert( matrix_3x1.f_GetColumnsCount() == 1 );
        matrix_3x1.f_SetElement( 0, 0, 1.0 );
        matrix_3x1.f_SetElement( 1, 0, 2.0 );
        matrix_3x1.f_SetElement( 2, 0, 3.0 );
        assert( matrix_3x2.f_GetElement( 0, 0 ) == 1.0 );
        assert( matrix_3x2.f_GetElement( 0, 1 ) == 2.0 );
        assert( matrix_3x2.f_GetElement( 1, 0 ) == 3.0 );


        // Делаем триангуляцию
        CMatrixOneColumn<double> matrix_triangulated = f_Triangulate( matrix_3x2, matrix_3x1 );
        assert( matrix_triangulated.f_GetElement( 0, 0 ) == 0 );
        assert( matrix_triangulated.f_GetElement( 1, 0 ) == 1 );
    }



    /**
     * @brief f_TestMatrixOperations -- функция для регрессионного тестирования
     */
    void f_TestMatrixOperations() {
        std::cout << std::endl << std::endl << "Тестирование операций над матрицами..." << std::endl;


        // Тестирование перемножения матриц
        std::cout << std::endl << std::endl << "Тестирование перемножения матриц..." << std::endl;

        CBoundsMatrix<int> matrix_left( 3, 2 );
        CBoundsMatrix<int> matrix_right( 2, 4 );
        CBoundsMatrix<int> matrix_multipyed;
        assert( HMatrix::f_Muliply( matrix_left, matrix_right, matrix_multipyed ) == true );
        assert( matrix_multipyed.f_GetElement( 0, 0 ) == 4 );
        assert( matrix_multipyed.f_GetElement( 0, 1 ) == 5 );
        assert( matrix_multipyed.f_GetElement( 0, 2 ) == 6 );
        assert( matrix_multipyed.f_GetElement( 0, 3 ) == 7 );

        assert( matrix_multipyed.f_GetElement( 1, 0 ) == 12 );
        assert( matrix_multipyed.f_GetElement( 1, 1 ) == 17 );
        assert( matrix_multipyed.f_GetElement( 1, 2 ) == 22 );
        assert( matrix_multipyed.f_GetElement( 1, 3 ) == 27 );

        assert( matrix_multipyed.f_GetElement( 2, 0 ) == 20 );
        assert( matrix_multipyed.f_GetElement( 2, 1 ) == 29 );
        assert( matrix_multipyed.f_GetElement( 2, 2 ) == 38 );
        assert( matrix_multipyed.f_GetElement( 2, 3 ) == 47 );


        // Тестирование триангуляции
        f_TestTriangulation_1();
    }



    /**
     * @brief f_MatrixTests -- общий тест матриц
     */
    void f_Test() {
        f_TestsBoundsMatrix();
        f_TestsSquareMatrix();
        f_TestMatrixOperations();
    }
}




#endif // HBOUNDSMATRIXTESTS_H
