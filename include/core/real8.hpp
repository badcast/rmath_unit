#pragma once

#include "core.hpp"

namespace rmath {
   // real8 contained void* type
   typedef class real8 : public core::realbase<0b0001, real8> {
      public:
         real8();
         real8(const int& x);
         real8(const int& x, const int& y);
         real8(const int& x, const int& y, const int& z);
         real8(const float& x);
         real8(const double& x);
         real8(const real16& rhs);
         real8(const real24& rhs);
         real8(const real32& rhs);

         real8& zero();
         real8& one();

         operator const float() const;
         operator const double() const;

         // signed section
         operator const std::int8_t() const;
         operator const std::int16_t() const;
         operator const std::int64_t() const;
         operator const std::int32_t() const;

         // unsigned section
         operator const std::uint8_t() const;
         operator const std::uint16_t() const;
         operator const std::uint32_t() const;
         operator const std::uint64_t() const;

         real8& operator =(const real8&);
         real8& operator =(const real16&);
         real8& operator =(const real24&);
         real8& operator =(const real32&);

         operator bool();

         static const real8 e;
   } real8_t, real_low_t;

}  // namespace rmath
