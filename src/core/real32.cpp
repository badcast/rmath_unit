#include "../../include/rmath.hpp"

using namespace rmath;
using namespace rmath::func;

real32::real32(){

}

real32::~real32(){

}

real32::real32(const int& m, const int& p, const int& q)
{
   this->m = m;
   this->p = p;
   this->q = q;
}
real32::real32(const int64_t& rhs)
{
   this->m = 0;
   this->p = rhs;
   this->q = 1;
}
real32::real32(const uint64_t& rhs)
{
   this->m = 0;
   this->p = rhs;
   this->q = 1;
}
real32::real32(const double& rhs)
{
   if (rhs == std::numeric_limits<double>::infinity()) {
      *this = rmath::func::positiveInfinity;
   } else if (rhs == -std::numeric_limits<double>::infinity()) {
      *this = rmath::func::negativeInfinity;
   } else {
      m = 0;
      p = int(rhs * 1000) - int(rhs * 100);
      q = 900;
      *this = to_prime(*this);
   }
}

// operators
real32& real32::operator+=(const real32& rhs) { return *this = func::add(*this, rhs); }

real32& real32::operator-=(const real32& rhs) { return *this = func::sub(*this, rhs); }

real32& real32::operator*=(const real32& rhs) { return *this = func::mul(*this,rhs); }

real32& real32::operator/=(const real32& rhs) { return *this = func::div(*this, rhs); }

real32::operator float() { return static_cast<float>(this->operator double()); }
real32::operator double() { return func::to_double(*this); }

// signed section
real32::operator std::int8_t() { return 0; }
real32::operator std::int16_t() { return 0; }
real32::operator std::int64_t() { return 0; }
real32::operator std::int32_t() { return 0; }
// unsigned section
real32::operator std::uint8_t() { return 0; }
real32::operator std::uint16_t() { return 0; }
real32::operator std::uint32_t() { return 0; }
real32::operator std::uint64_t() { return 0; }
