// Class for all real type base
#pragma once

#include <cstdint>

namespace rmath {
    class real8;
    class real16;
    class real24;
    class real32;
    class real64;

    namespace func {
        template <typename type>
        struct get_value;

        template <>
        struct get_value<::rmath::real8>;

        template <>
        struct get_value<::rmath::real16>;

        template <>
        struct get_value<::rmath::real24>;

        template <>
        struct get_value<::rmath::real32>;

    }  // namespace func
}  // namespace rmath

namespace rmath {

    namespace core {

        template <const std::size_t _size, typename _Derived>
        class realbase {  // abstract class
                using type = _Derived;
                friend struct ::rmath::func::get_value<::rmath::real8>;
                friend struct ::rmath::func::get_value<::rmath::real16>;
                friend struct ::rmath::func::get_value<::rmath::real24>;
                friend struct ::rmath::func::get_value<::rmath::real32>;

            protected:
                int8_t _raw[_size];

            public:
                static const std::size_t size() { return _size; }
        };
    }  // namespace core
}  // namespace rmath
