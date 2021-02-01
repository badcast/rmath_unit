#include "../../include/core/RSerializer.hpp"
#include "../../include/rmath.hpp"

using namespace rmath;
using namespace rmath::func;

real32::real32() {}

real32::~real32() {}

real32::real32(const int& x, const int& y, const int& z) {
   core::RSerializer::set_real(this->_raw, size(), x, y, z);
   // down is code
   this->m = x;
   this->p = y;
   this->q = z;
}
real32::real32(const int64_t& rhs) {
   core::RSerializer::set_int64(rhs, this->_raw, size());
    // down is code
   this->m = 0;
   this->p = rhs;
   this->q = 1;
}
real32::real32(const uint64_t& rhs) {
   core::RSerializer::set_uint64(rhs, this->_raw, size());
    // down is code
   this->m = 0;
   this->p = rhs;
   this->q = 1;
}
real32::real32(const double& rhs) {
   core::RSerializer::set_double(rhs, this->_raw, size());
    // down is code
   if (rhs == std::numeric_limits<double>::infinity()) {
      *this = rmath::func::positiveInfinity;
   } else if (rhs == -std::numeric_limits<double>::infinity()) {
      *this = rmath::func::negativeInfinity;
   } else {
      m = 0;
      p = int(rhs * 1000) - int(rhs * 100);
      q = 900;
      *this = prime(*this);
   }
}

// function
real32& real32::one() {
   core::RSerializer::set_int32(1, this->_raw, size());
   return *this;
}

real32& real32::zero() {
   core::RSerializer::set_int32(0, this->_raw, size());
   return *this;
}

// operators

real32::operator float() {
   float num;
   core::RSerializer::get_float(this->_raw, size(), &num);
   return num;
}
real32::operator double() {
   double num;
   core::RSerializer::get_double(this->_raw, size(), &num);
   return num;
}

// signed section
real32::operator const std::int8_t() {
   std::int8_t num;
   core::RSerializer::get_int8(this->_raw, size(), &num);
   return num;
}
real32::operator const std::int16_t() {
   std::int16_t num;
   core::RSerializer::get_int16(this->_raw, size(), &num);
   return num;
}

real32::operator const std::int64_t() {
   std::int64_t num;
   core::RSerializer::get_int64(this->_raw, size(), &num);
   return num;
}
real32::operator const std::int32_t() {
   std::int32_t num;
   core::RSerializer::get_int32(this->_raw, size(), &num);
   return num;
}
// unsigned section
real32::operator const std::uint8_t() {
   std::uint8_t num;
   core::RSerializer::get_uint8(this->_raw, size(), &num);
   return num;
}
real32::operator const std::uint16_t() {
   std::uint16_t num;
   core::RSerializer::get_uint16(this->_raw, size(), &num);
   return num;
}
real32::operator const std::uint32_t() {
   std::uint32_t num;
   core::RSerializer::get_uint32(this->_raw, size(), &num);
   return num;
}

real32::operator const std::uint64_t() {
   std::uint64_t num;
   core::RSerializer::get_uint64(this->_raw, size(), &num);
   return num;
}
