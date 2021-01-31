#pragma once
#include "core.hpp"

namespace rmath {

   typedef class real16 : public core::realbase<0b0010> {
      public:
         real16();
         ~real16();

         // operators
         operator float();
         operator double();

         // signed section
         operator std::int8_t();
         operator std::int16_t();
         operator std::int64_t();
         operator std::int32_t();
         // unsigned section
         operator std::uint8_t();
         operator std::uint16_t();
         operator std::uint32_t();
         operator std::uint64_t();
   } real16_t;


}  // namespace rmath
