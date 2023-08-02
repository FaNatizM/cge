#ifndef CBOUNDSMATRIX_H
#define CBOUNDSMATRIX_H


#include <iostream>
#include <vector>




// Шаблонный класс для представления матрицы NxM
template <typename TValue>
class CBoundsMatrix {
    public:

        /**
         * @brief CBoundsMatrix -- Конструктор
         * @param a_rows -- число строк
         * @param a_columns -- число столбцов
         */
        explicit CBoundsMatrix( unsigned int a_rows = 0, unsigned int a_columns = 0 );

        /**
         * @brief CBoundsMatrix -- Конструктор
         * @param a_rows -- строки
         * @param a_columns -- столбцы
         * @param a_size -- размерность массива элементов
         */
        explicit CBoundsMatrix( const std::vector<TValue>& a_elements, const unsigned int a_rows = 0, const unsigned int a_columns = 0 );

        /**
         * @brief CBoundsMatrix -- конструктор копировния
         * @param a_matrix -- матрица данные которой копируются
         */
        explicit CBoundsMatrix( const CBoundsMatrix& a_matrix );

        /**
         * @brief CBoundsMatrix -- конструктор перемещения
         * @param a_matrix -- матрица данные которой перемещаются
         */
        explicit CBoundsMatrix( CBoundsMatrix&& a_matrix );

        /**
         * @brief ~CBoundsMatrix -- деструктор
         */
        virtual ~CBoundsMatrix();

        /**
         * @brief swap -- метод обмена значениями двух матриц
         * @param a_matrix
         */
        void swap( CBoundsMatrix<TValue>& a_matrix );

        /**
         * @brief operator = оператор присваивания пользовательский
         * @param a_matrix
         * @return
         */
        CBoundsMatrix& operator=( const CBoundsMatrix& a_matrix );

        template <typename UValue>

        /**
         * @brief operator = оператор присваивания для переопределения того,
         *  что может попытаться создать копилятор по-умолчанию
         * @param a_matrix
         * @return
         */
        CBoundsMatrix<UValue>& operator=( const CBoundsMatrix<UValue>& a_matrix );

        /**
         * @brief operator = оператор присваивания перемещением
         * @param a_matrix
         * @return
         */
        CBoundsMatrix& operator=( CBoundsMatrix&& a_matrix );

        /**
         * @brief operator () -- оператор доступа к элементу
         * @param a_row -- строка элемента
         * @param a_column -- столбец элемента
         * @param a_default_value -- значение по умолчанию
         * @return Возвращает значение элемента
         */
        TValue operator()( unsigned int a_row, unsigned int a_column, TValue a_default_value = 0 ) const;

        /**
         * @brief operator () -- оператор доступа к элементу на редактирование
         * @param a_row -- строка элемента
         * @param a_column -- столбец элемента
         * @param a_default_value -- значение по умолчанию
         * @return Возвращает значение элемента с возможностью редактирования
         */
        TValue& operator()( unsigned int a_row, unsigned int a_column, TValue& a_default_value );

        /**
         * @brief f_GetRowsCount -- метод получения числа строк в матрице
         * @return Возвращает число строк
         */
        unsigned int f_GetRowsCount() const;

        /**
         * @brief f_GetColumnsCount -- метод получения числа столбцов в матрице
         * @return Возвращает число столбцов
         */
        unsigned int f_GetColumnsCount() const;

        /**
         * @brief f_IsEmplty -- метод проверки пустая ли матрица
         * @return Возвращает true, если матрица пустая
         */
        bool f_IsEmplty() const;

        /**
         * @brief f_GetElementsCount -- метод получения числа элементов в матрице
         * @return  Возвращает число элементов в матрице
         */
        unsigned int f_GetElementsCount() const;

        /**
         * @brief f_GetElement
         * @param a_row
         * @param a_column
         * @param a_element
         * @return
         */
        TValue f_GetElement( unsigned int a_row, unsigned int a_column, TValue a_default_value = 0 ) const;

        bool f_SetElement( unsigned int a_row, unsigned int a_column, TValue a_element ) const;

        /**
         * @brief f_Visual -- метод визуализации матрицы
         */
        void f_Visual() const;

        // Должна быть const!
        /**
         * @brief f_Visual -- метод визуализации элемента матрицы
         * @param a_row -- строка элемента
         * @param a_column -- столбец элемента
         */
        void f_Visual( unsigned int a_row, unsigned int a_column ) const;

        /**
         * @brief f_Transpon -- функция транспонирования матрицы
         */
        void f_Transpon();

    protected:

        /**
         * @brief f_GetElements -- метод доступа к элементам матрицы
         * @return
         */
        TValue** f_GetElements() const;

        /**
         * @brief f_GetElements -- метод доступа к элементам матрицы
         * @return
         */
        // TValue**& f_GetElements() { return m_elements; };

    private:

        /**
         * @brief f_CreateElements -- метод выделения памяти на элементы
         */
        void f_CreateElements();

        /**
         * @brief f_Init -- метод инициализации начальными значениями
         */
        void f_Init();

        /**
         * @brief f_ClearElements -- метод очистки элементов матрицы
         * @param a_elements -- массив элементов
         * @param a_rows -- число строк массива
         */
        void f_ClearElements( TValue** a_elements, unsigned int a_rows );


    // members:
    private:
        unsigned int m_rows;    //!< размерность матрицы по X
        unsigned int m_columns; //!< размерность матрицы по Y
        TValue** m_elements;    //!< двумерный массив для хранения элементов матрицы
};




template<typename TValue>
CBoundsMatrix<TValue>::CBoundsMatrix( unsigned int a_rows, unsigned int a_columns )
    : m_rows( a_rows )
    , m_columns( a_columns )
    , m_elements( nullptr ) {

    if ( ! f_IsEmplty() ) {

        // Выделяем память на массив эелментов
        f_CreateElements();

        // Инициализируем значениями
        f_Init();
    }
}



template<typename TValue>
CBoundsMatrix<TValue>::CBoundsMatrix( const std::vector<TValue>& a_elements, const unsigned int a_rows, const unsigned int a_columns )
    : m_rows( a_rows )
    , m_columns( a_columns )
    , m_elements( nullptr ) {

    if ( ! f_IsEmplty() ) {

        // Выделяем память на массив эелментов
        f_CreateElements();

        if ( a_elements.size() == ( a_rows * a_columns ) ) {

            // Заполняем элементы элементами из массива, если размерность совпадает
            int row = 0;
            int column = 0;
            for ( unsigned int counter = 0; counter < a_elements.size(); counter++ ) {
                if ( ( counter > 0 ) && ( counter ) % m_columns == 0 ) {
                    row++;
                }

                column = counter - row * m_columns;

                m_elements[ row ][ column ] = a_elements.at( counter );
            }
        } else {

            // Инициализируем значениями
            f_Init();
        }
    }
}



template<typename TValue>
CBoundsMatrix<TValue>::CBoundsMatrix( const CBoundsMatrix& a_matrix )
    : m_rows( a_matrix.m_rows )
    , m_columns( a_matrix.m_columns )
    , m_elements( nullptr ) {

    if ( ! f_IsEmplty() ) {

        // Выделяем память на массив эелментов
        f_CreateElements();

        // Заполняем элементы из матрицы, которую нужно скопировать
        for ( unsigned int row = 0; row < m_rows; row++ ) {
            for ( unsigned int column = 0; column < m_columns; column++ ) {
                m_elements[ row ][ column ] = a_matrix( row, column );
            }
        }
    }
}



template<typename TValue>
CBoundsMatrix<TValue>::CBoundsMatrix( CBoundsMatrix&& a_matrix )
    : m_rows( a_matrix.m_rows )
    , m_columns( a_matrix.m_columns )
    , m_elements( a_matrix.m_elements ) {

    a_matrix.m_elements = nullptr;


    // std::cout << "Moving CBoundsMatrix()" << std::endl;
}



template<typename TValue>
CBoundsMatrix<TValue>::~CBoundsMatrix() {
    f_ClearElements( m_elements, m_rows );
}



template<typename TValue>
void CBoundsMatrix<TValue>::swap( CBoundsMatrix<TValue>& a_matrix ) {

    // Переписать
    // Очень дорого, по-хорошему, нужно хранить данные
    // матрицы в указателе на класс CBoundsMatrixPrivate

    // Сохраняем исходные значения правой части
    // TValue** elements_origin = m_elements;
    std::swap( m_elements, a_matrix.m_elements );
    unsigned int rows_origin = m_rows;
    unsigned int columns_origin = m_columns;

    // Меняем правую часть
    // m_elements = a_matrix.m_elements;
    m_rows = a_matrix.m_rows;
    m_columns = a_matrix.m_columns;

    // Меняем левую часть
    // a_matrix.m_elements = elements_origin;
    a_matrix.m_rows = rows_origin;
    a_matrix.m_columns = columns_origin;
}



template<typename TValue>
CBoundsMatrix<TValue>& CBoundsMatrix<TValue>::operator=( const CBoundsMatrix<TValue>& a_matrix ) {

    CBoundsMatrix<TValue> temp_matrix( a_matrix );
    swap( temp_matrix );


    // std::cout << "Coping CBoundsMatrix::operator=" << std::endl;

    return *this;
}



template<typename TValue>
CBoundsMatrix<TValue>& CBoundsMatrix<TValue>::operator=( CBoundsMatrix&& a_matrix ) {
    if ( this == &a_matrix ) {
        return *this;
    }


    f_ClearElements( m_elements, m_rows );

    m_elements = a_matrix.m_elements;
    m_rows = a_matrix.m_rows;
    m_columns = a_matrix.m_columns;

    a_matrix.m_elements = nullptr;


    // std::cout << "Moving CBoundsMatrix::operator=" << std::endl;

    return *this;
}



template<typename TValue>
TValue CBoundsMatrix<TValue>::operator()( unsigned int a_row, unsigned int a_column, TValue a_default_value ) const {
    return f_GetElement( a_row, a_column, a_default_value );
}



template<typename TValue>
TValue& CBoundsMatrix<TValue>::operator()( unsigned int a_row, unsigned int a_column, TValue& a_default_value ) {
    if ( a_row >= m_rows || a_column >= m_columns ) {

        std::cout << "Error! matrix indices out of range" << std::endl;
        return a_default_value;
    }

    return m_elements[ a_row ][ a_column ];
}



template <typename TValue>
template <typename UValue>
CBoundsMatrix<UValue>& CBoundsMatrix<TValue>::operator=( const CBoundsMatrix<UValue>& a_matrix ) {

    CBoundsMatrix<UValue> temp_matrix( a_matrix );
    swap( temp_matrix );

    return *this;
}



template<typename TValue>
unsigned int CBoundsMatrix<TValue>::f_GetRowsCount() const {
    return m_rows;
}



template<typename TValue>
unsigned int CBoundsMatrix<TValue>::f_GetColumnsCount() const {
    return m_columns;
}



template<typename TValue>
bool CBoundsMatrix<TValue>::f_IsEmplty() const {
    if ( m_rows < 1 || m_columns < 1 ) {
        return true;
    }

    return false;
}



template<typename TValue>
unsigned int CBoundsMatrix<TValue>::f_GetElementsCount() const {
    return ( m_rows * m_columns );
}



template<typename TValue>
TValue CBoundsMatrix<TValue>::f_GetElement( unsigned int a_row, unsigned int a_column, TValue a_default_value ) const {
    if ( a_row >= m_rows || a_column >= m_columns ) {

        std::cout << "Error! matrix indices out of range" << std::endl;
        return a_default_value;
    }

    return m_elements[ a_row ][ a_column ];
}



template<typename TValue>
bool CBoundsMatrix<TValue>::f_SetElement(unsigned int a_row, unsigned int a_column, TValue a_element) const {
    if ( a_row >= m_rows || a_column >= m_columns ) {

        std::cout << "Error! matrix indices out of range" << std::endl;
        return false;
    }


    m_elements[ a_row ][ a_column ] = a_element;

    return true;
}



template<typename TValue>
void CBoundsMatrix<TValue>::f_Visual() const {
    std::cout << *this;
}



template<typename TValue>
void CBoundsMatrix<TValue>::f_Visual( unsigned int a_row, unsigned int a_column ) const {
    TValue element = f_GetElement( a_row, a_column );
    std::cout << "( " << a_row << ", " << a_column << " ) = " << element << std::endl;
}



namespace NBoundsMatrix {
    template <typename TValue>
    void swap( CBoundsMatrix<TValue>& a_lhs, CBoundsMatrix<TValue>& a_rhs ) {
        a_lhs.swap( a_rhs );
    }
}



template<typename TValue>
void CBoundsMatrix<TValue>::f_Transpon() {

    // Создаём и заполняем временную матрицу транспонирования
    CBoundsMatrix<TValue> transpon_matrix( m_columns, m_rows );
    for ( unsigned int row = 0; row < m_rows; row++ ) {
        for ( unsigned int column = 0; column < m_columns; column++ ) {
            transpon_matrix.f_SetElement( column, row, m_elements[ row ][ column ] );
        }
    }


    // Присваиваем временную матрицу текущей
    // Используем оператор присваивания перемещением!
    *this = std::move( transpon_matrix );
}



template<typename TValue>
TValue** CBoundsMatrix<TValue>::f_GetElements() const {
    return m_elements;
}



template<typename TValue>
void CBoundsMatrix<TValue>::f_CreateElements() {

    // Выделяем память на строки
    m_elements = new TValue* [ m_rows ];

    // Выделяем память на столбцы
    for ( unsigned int counter = 0; counter < m_rows; counter++ ) {
        m_elements[ counter ] = new TValue[ m_columns ];
    }
}



template<typename TValue>
void CBoundsMatrix<TValue>::f_Init() {

    // Заполняем элементы по умолчанию
    int counter = 0;
    for ( unsigned int row = 0; row < m_rows; row++ ) {
        for ( unsigned int column = 0; column < m_columns; column++ ) {

            // m_elements[ row ][ column ] = rand()%9 + 1;
            m_elements[ row ][ column ] = counter++;
        }
    }
}



template<typename TValue>
void CBoundsMatrix<TValue>::f_ClearElements( TValue** a_elements, unsigned int a_rows ) {
    if ( a_elements == nullptr ) {
        return;
    }


    // Чистим выделенную память
    for ( unsigned int row = 0; row < a_rows; row++ ) {
        delete [] a_elements[ row ];
    }

    delete [] a_elements;
}



template <typename TValue>
inline std::ostream& operator <<( std::ostream& a_out, const CBoundsMatrix<TValue>& a_matrix ) {
    const unsigned int rows = a_matrix.f_GetRowsCount();
    const unsigned int columns = a_matrix.f_GetColumnsCount();

    a_out << std::endl << "matrix " << rows << "x" << columns << ":" << std::endl;


    for ( unsigned int row = 0; row < rows; row++ ) {
        for ( unsigned int column = 0; column < columns; column++) {
            a_out << a_matrix.f_GetElement( row, column ) << " ";
        }

        a_out << std::endl;
    }

    a_out << std::endl;

    return a_out;
}




#endif // CBOUNDSMATRIX_H
