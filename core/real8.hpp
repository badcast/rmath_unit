#pragma once

#include <core.hpp>

namespace rmath{
    //real8 contained void* type
    class real8 : public core::realbase{
        char data[1]; //len 8 bits

        public:
            virtual operator float();
            virtual operator double();

            //signed section
            virtual operator std::int8_t();
            virtual operator std::int16_t(); 
            virtual operator std::int64_t();
            virtual operator std::int32_t();
            
            //unsigned section
            virtual operator std::uint8_t();
            virtual operator std::uint16_t();
            virtual operator std::uint32_t();
            virtual operator std::uint64_t();
             
    } real8_t;


    
}