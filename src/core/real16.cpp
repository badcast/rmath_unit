#include "../../include/rmath.hpp"

using namespace rmath;

real16::real16() {

}

real16::~real16() {}

// operators
real16::operator const float() { return 0; }
real16::operator const double(){ return 0; }

// signed section
real16::operator const std::int8_t() { return 0; }
real16::operator const std::int16_t() { return 0; }
real16::operator const std::int64_t() { return 0; }
real16::operator const std::int32_t() { return 0; }
// unsigned section
real16::operator const std::uint8_t() { return 0; }
real16::operator const std::uint16_t() { return 0; }
real16::operator const std::uint32_t() { return 0; }
real16::operator const std::uint64_t() { return 0; }
