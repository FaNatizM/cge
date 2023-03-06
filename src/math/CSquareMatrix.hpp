#ifndef CSQUAREMATRIX_H
#define CSQUAREMATRIX_H


#include <iostream>

#include "CBoundsMatrix.hpp"




// Класс для "квадратной" матрицы n x n
template <typename TValue>
class CSquareMatrix : public CBoundsMatrix<TValue> {
    public:

        /**
         * @brief CSquareMatrix -- конструктор
         * @param a_size -- размер матрицы
         */
        explicit CSquareMatrix( unsigned int a_size = 0 );

        /**
         * @brief CBoundsMatrix -- конструктор копировния
         * @param a_matrix -- матрица данные которой копируются
         */
        explicit CSquareMatrix( const CSquareMatrix& a_matrix );

        /**
         * @brief CBoundsMatrix -- конструктор перемещения
         * @param a_matrix -- матрица данные которой копируются
         */
        explicit CSquareMatrix( CSquareMatrix&& a_matrix );

        /**
         * @brief ~CSquareMatrix -- деструктор
         */
        virtual ~CSquareMatrix() {
        }

        // Операторы присваивания
        // ...
        /**
         * @brief operator = оператор присваивания копированием
         * @param a_matrix
         * @return
         */
        CSquareMatrix& operator=( const CSquareMatrix& a_matrix );

        CSquareMatrix& operator=( CSquareMatrix&& a_matrix );

        unsigned int f_GetSize() const;

        /**
         * @brief f_InitMinor -- метод заполнения минорной матрицы
         * @param a_matrix_minor -- минорная матрица, которую нужно заполнить
         * @param a_row -- вычёркиваямая строка
         * @param a_column -- вычёркиваемый столбец
         * @return Возвращает true, если удалось заполнить минорную матрицу, иначе возвращает false
         */
        bool f_InitMinor( CSquareMatrix<TValue>& a_matrix_minor, unsigned int a_row, unsigned int a_column );

        /**
         * @brief f_GetDet -- функция вычисления определителя матрицы
         * @return
         */
        bool f_GetDet( TValue* a_det );

        // Вычисление обратной матрицы
        // ...
};




template<typename TValue>
CSquareMatrix<TValue>::CSquareMatrix( unsigned int a_size )
    : CBoundsMatrix<TValue>( a_size, a_size ) {
    // std::cout << "Default CSquareMatrix()" << std::endl;
}



template<typename TValue>
CSquareMatrix<TValue>::CSquareMatrix( const CSquareMatrix& a_matrix )
    : CBoundsMatrix<TValue>( a_matrix ) {
    // std::cout << "Coping CSquareMatrix()" << std::endl;
}



template<typename TValue>
CSquareMatrix<TValue>::CSquareMatrix( CSquareMatrix&& a_matrix )
    : CBoundsMatrix<TValue>( a_matrix ) {
    // std::cout << "Moving CSquareMatrix()" << std::endl;
}



template<typename TValue>
CSquareMatrix<TValue>& CSquareMatrix<TValue>::operator=( const CSquareMatrix& a_matrix ) {
    CSquareMatrix<TValue> temp_matrix( a_matrix );
    this->swap( temp_matrix );


    // std::cout << "Coping CSquareMatrix::operator=" << std::endl;

    return *this;
}



template<typename TValue>
CSquareMatrix<TValue>& CSquareMatrix<TValue>::operator=( CSquareMatrix&& a_matrix ) {
    if ( this == &a_matrix ) {
        return *this;
    }

    CBoundsMatrix<TValue>::operator =( std::move( a_matrix ) );


    // std::cout << "Moving CSquareMatrix::operator=" << std::endl;

    return *this;
}



template<typename TValue>
unsigned int CSquareMatrix<TValue>::f_GetSize() const {
    return this->f_GetRowsCount();
}



template<typename TValue>
bool CSquareMatrix<TValue>::f_InitMinor( CSquareMatrix<TValue>& a_matrix_minor, unsigned int a_row, unsigned int a_column ) {

    // Проверяем корректность исходной матрицы
    if ( a_row > this->f_GetRowsCount() || a_column > this->f_GetColumnsCount() ) {

        // Не можем вычеркнуть строку или столбец, если их индекс больше размеров матрицы
        return false;
    }


    // Создаём минорную матрицу
    const unsigned int rows_minor = this->f_GetRowsCount() - 1;
    CSquareMatrix<TValue> minor_matrix( rows_minor );


    // Заполняем минорную матрицу значениями
    // Обходим исходную матрицу
    unsigned int row_minor = 0;
    for ( unsigned int row = 0; row < this->f_GetRowsCount(); row++ ) {

        // Проверка на вычеркнутую строку
        if ( row == a_row ) {

            // Это вычеркнутая строка
            // Переходим к следующей
            continue;
        }

        // Обходим столбцы невычеркнутой строки
        for ( unsigned int column = 0, column_minor = 0; column < this->f_GetRowsCount(); column++ ){

            // Проверка на вычеркнутый столбец
            if ( column == a_column ) {

                // Это вычеркнутый столбец
                // Переходим к следующему
                continue;
            }

            // Опеределение элемента минорной матрицы
            TValue element = this->f_GetElements()[ row ][ column ];

            minor_matrix.f_SetElement( row_minor, column_minor, element );
            column_minor++;
        }

        row_minor++;
    }


    // Возвращаем минорную матрицу
    // Используем оператор присваивания перемещением!
    a_matrix_minor = std::move( minor_matrix );

    return true;
}



template<typename TValue>
bool CSquareMatrix<TValue>::f_GetDet( TValue* a_det ) {

    if ( this->f_IsEmplty() ) {
        std::cout << "f_GetDet > Неверный размер матрицы!" << std::endl;
        return false;
    }


    // Случай матрицы из одного элемента
    if ( this->f_GetRowsCount() == 1 ) {
        *a_det = this->f_GetElements()[ 0 ][ 0 ];
        return true;
    }

    // Случай матрицы из четырёх элементов
    if ( this->f_GetRowsCount() == 2 ) {
        *a_det = this->f_GetElements()[ 0 ][ 0 ] * this->f_GetElements()[ 1 ][ 1 ] - this->f_GetElements()[ 1 ][ 0 ] * this->f_GetElements()[ 0 ][ 1 ];
        return true;
    }


    // Временная переменная для хранения определителя
    TValue temp_det = 0;

    // степень миноров (алгебраических дополнений)
    // -1 ^ ( N строки элемента + N столбца элемента
    int minor_power = 1;

    // Идём по строкам
    for ( unsigned int row = 0; row < this->f_GetRowsCount(); row++ ) {

        // Создаём и заполняем минорную матрицу
        CSquareMatrix<TValue> minor_matrix;
        f_InitMinor( minor_matrix, 0, row );

        // Вычисляем определитель минорной матрицы
        TValue minor_det = 0;
        minor_matrix.f_GetDet( &minor_det );

        // Вычисляем определитель исходной матрицы
        TValue matrix_element = this->f_GetElements()[ 0 ][ row ];
        temp_det = temp_det + minor_power * matrix_element * minor_det;
        minor_power = -minor_power;
    }

    *a_det = temp_det;


    return true;
}




#endif // CSQUAREMATRIX_H
