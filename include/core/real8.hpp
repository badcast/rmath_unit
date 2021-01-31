#pragma once

#include "core.hpp"

namespace rmath {
   // real8 contained void* type
   typedef class real8 : public core::realbase<0b0001> {
      public:
         real8();
         ~real8();

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

   } real8_t, real_low_t;

}  // namespace rmath
