#pragma once
#include "core.hpp"
#include "real8.hpp"
#include "real32.hpp"

namespace rmath{
    class real16 : public core::realbase{
        std::int8_t data[2];
        public: 
        real16();
        
    };
}
