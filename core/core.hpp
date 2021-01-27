//Class for all real type base
#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <limits>
#include <list>
namespace rmath{
    namespace core{
        class realbase{
            public: 
            realbase();

            virtual operator double();
            virtual operator std::int32_t();
            virtual operator std::int64_t();
            virtual operator std::int16_t();
        }
    }

}