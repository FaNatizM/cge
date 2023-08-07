#ifndef HCGEMACROSES_H
#define HCGEMACROSES_H




#define M_POINTER_TYPE( a_class, a_type )\
    class a_class;\
    using a_type\
        = std::shared_ptr< a_class >;\



#define M_IMPL_UNIQUE_DECL( a_class )\
    public:\
        ~a_class();\
        a_class( a_class&& a_other );\
        a_class& operator=(\
            a_class&& a_other );\
        a_class(\
            const a_class& a_other );\
        a_class& operator=(\
            const a_class& a_other );\



#define M_IMPL_UNIQUE_V_DECL( a_class )\
    public:\
        virtual ~a_class();\
        a_class( a_class&& a_other );\
        a_class& operator=(\
            a_class&& a_other );\
        a_class(\
            const a_class& a_other );\
        a_class& operator=(\
            const a_class& a_other );\



#define M_IMPL_SHARED_DECL( a_class )\
    public:\
        ~a_class() = default;\
        a_class( a_class&& a_other )\
            = default;\
        a_class& operator=(\
            a_class&& a_other )\
            = default;\
        a_class(\
            const a_class& a_other )\
            = default;\
        a_class& operator=(\
            const a_class& a_other )\
            = default;\



#define M_IMPL_SHARED_V_DECL( a_class )\
    public:\
        virtual ~a_class() = default;\
        a_class( a_class&& a_other )\
            = default;\
        a_class& operator=(\
            a_class&& a_other )\
            = default;\
        a_class(\
            const a_class& a_other )\
            = default;\
        a_class& operator=(\
            const a_class& a_other )\
            = default;\



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



#define M_IMPL_SHARED_STRUCT(\
    a_struct, a_type )\
    struct a_struct; \
    using a_type \
        = std::shared_ptr< \
           a_struct >; \
    a_type m_impl; \



#define M_IMPL_SHARED_STRUCT_IMPL()\
    M_IMPL_SHARED_STRUCT( SImpl, TImpl )



#define M_IMPL_UNIQUE_STRUCT(\
    a_struct, a_type )\
    struct a_struct; \
    using a_type \
        = std::unique_ptr< \
           a_struct >; \
    a_type m_impl; \



#define M_IMPL_UNIQUE_STRUCT_IMPL()\
    M_IMPL_UNIQUE_STRUCT( SImpl, TImpl )



#define M_IMPL_MAKE_STRUCT(\
    a_struct, a_type )\
    template< typename... Types >\
    static a_type f_Create(\
        Types&& ... a_params ) {\
        auto impl\
            = std::make_unique<\
                a_struct >(\
                    std::forward<\
                        Types >( a_params ) ... );\
            return impl;\
    }\



#define M_MAKE_SHARED(\
    a_type, a_pointer )\
    template< typename... Types >\
    static a_pointer f_Create(\
        Types&& ... a_params ) {\
        auto impl\
            = std::make_shared<\
                a_type >(\
                    std::forward<\
                        Types >(\
                            a_params\
                        ) ... );\
            return impl;\
    }\



#endif
