#ifndef HMATRIXOPERATIONS_H
#define HMATRIXOPERATIONS_H


#include <iostream>

#include "CBoundsMatrix.hpp"




// Класс для матрицы 2 x n
template <typename TValue>
class CMatrixTwoColumns : public CBoundsMatrix<TValue> {
    public:
        explicit CMatrixTwoColumns( unsigned int a_rows )
            : CBoundsMatrix<TValue>( a_rows, 2 ) {
        }
};



// Класс для матрицы 1 x n
template <typename TValue>
class CMatrixOneColumn : public CBoundsMatrix<TValue> {
    public:
        explicit CMatrixOneColumn( unsigned int a_rows )
            : CBoundsMatrix<TValue>( a_rows, 1 ) {
        }
};




namespace HMatrix {

    template <typename TValue>

    /**
     * @brief f_Triangulate -- функция триангуляции двух матриц
     * @brief f_Triangulate -- функция триангуляции двух матриц
     * @param a_matrix_2xn
     * @param a_matrix_1xn
     * @return возвращает результирующую матрицу
     */

    CMatrixOneColumn<TValue> f_Triangulate( const CMatrixTwoColumns<TValue>& a_matrix_2xn, const CMatrixOneColumn<TValue>& a_matrix_1xn ) {

        std::cout << "f_Triangulate()" << std::endl;

        // Отображаем матрицы
        a_matrix_2xn.f_Visual();
        a_matrix_1xn.f_Visual();


        // Алгоритм
        // ...


        // Печать результата на экран
        CMatrixOneColumn<TValue> result_matrix( 2 );

        std::cout << "Triangulation result:";
        result_matrix.f_Visual();

        return result_matrix;
    }



    template<typename TValue>

    /**
     * @brief f_Muliply -- функция перемножения матриц
     * @param a_matrix_left -- левая матрица
     * @param a_matrix_right -- правая матрица
     */
    static bool f_Muliply( const CBoundsMatrix<TValue>& a_matrix_left
                           , const CBoundsMatrix<TValue>& a_matrix_right
                           , CBoundsMatrix<TValue>& a_matrix_result ) {

        // Проверка возможности перемножения матриц
        if ( a_matrix_left.f_GetColumnsCount() != a_matrix_right.f_GetRowsCount() ) {

            // Перемножить матрицы нельзя
            return false;
        }


        // Создаём результирующую матрицу
        const unsigned int matrix_rows = a_matrix_left.f_GetRowsCount();
        const unsigned int matrix_columns = a_matrix_right.f_GetColumnsCount();
        CBoundsMatrix<TValue> matrix( matrix_rows, matrix_columns );

        // Перемножаем
        for ( unsigned int row = 0; row < a_matrix_left.f_GetRowsCount(); row++ ) {
            for ( unsigned int column = 0; column < a_matrix_right.f_GetColumnsCount(); column++ ) {
                matrix.f_SetElement( row, column, 0 );

                for ( unsigned int row_counter = 0; row_counter < a_matrix_right.f_GetRowsCount(); row_counter++ ) {
                    TValue element = matrix( row, column );
                    element = element + ( a_matrix_left( row, row_counter ) * a_matrix_right( row_counter, column ) );
                    matrix.f_SetElement( row, column, element );
                }
            }
        }

        // Возвращаем результат через обмен
        a_matrix_result.swap( matrix );

        // std::cout << "Перемноженная матрица:";
        // std::cout << a_matrix_result;

        return true;
   }
}




#endif // HMATRIXOPERATIONS_H
