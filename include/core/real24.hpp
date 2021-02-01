#pragma once
#include "core.hpp"

namespace rmath{
    typedef class real24 : public core::realbase<0b0011, real24>{
        public: 
        real24();
        ~real24();


        real24& zero();
        real24& one() ;

        // operators
        operator const float();
        operator const double();

        // signed section
        operator const std::int8_t();
        operator const std::int16_t();
        operator const std::int64_t();
        operator const std::int32_t();
        // unsigned section
        operator const std::uint8_t();
        operator const std::uint16_t();
        operator const std::uint32_t();
        operator const std::uint64_t();
    } real24_t;
}
