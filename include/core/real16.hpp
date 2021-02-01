#pragma once
#include "core.hpp"

namespace rmath {

   typedef class real16 : public core::realbase<0b0010, real16> {
      public:
         real16();
         ~real16();

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
   } real16_t;

}  // namespace rmath
