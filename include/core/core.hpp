//Class for all real type base
#pragma once

#include <cstdint>

namespace rmath{
    namespace core{
       template<const int _size>
        class realbase{ // abstract class
           protected:
              int8_t _buffer[_size];
           public:

            //operators
            virtual operator float()=0;
            virtual operator double()=0;

            //signed section
            virtual operator std::int8_t()=0;
            virtual operator std::int16_t()=0; 
            virtual operator std::int64_t()=0;
            virtual operator std::int32_t()=0;
            
            //unsigned section
            virtual operator std::uint8_t()=0;
            virtual operator std::uint16_t()=0;
            virtual operator std::uint32_t()=0;
            virtual operator std::uint64_t()=0;
        };
    }
}
