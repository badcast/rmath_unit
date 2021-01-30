#include <core.hpp>
#include <real8.hpp>
#include <real16.hpp>
#include <real32.hpp>

namespace rmath{
    class real24 : public core::realbase{
        std::int8_t data[2];
        public: 
        real16();
        
    }real24_t;
}