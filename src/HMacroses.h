#ifndef HMACROSES_H
#define HMACROSES_H




#define M_IMPL_UNIQUE( a_class, a_impl )\
\
a_class::~a_class() = default;\
\
\
\
a_class::a_class( a_class&& a_other )\
    = default;\
\
\
\
a_class& a_class::operator=(\
    a_class&& a_other ) = default;\
\
\
\
a_class::a_class(\
    const a_class& a_point )\
    : m_impl( nullptr ) {\
    if ( a_point.m_impl != nullptr ) {\
        m_impl = std::make_unique<\
            a_impl >( *a_point.m_impl );\
    }\
}\
\
\
\
a_class& a_class::operator=(\
    const a_class& a_other ) {\
    if ( a_other.m_impl == nullptr ) {\
        this->m_impl = nullptr;\
    } else if (\
        this->m_impl == nullptr ) {\
        this->m_impl\
            = std::make_unique<\
                a_impl >(\
                    *a_other.m_impl );\
    } else {\
        *this->m_impl\
            = *a_other.m_impl;\
    }\
    return *this;\
}\



#define M_IMPL_STRUCT( a_struct, a_type )\
    struct a_struct; \
    using a_type \
        = std::shared_ptr< \
           a_struct >; \
    a_type m_impl; \




#endif
