#include "../../include/rmath.hpp"

using namespace rmath;

real24::real24() {
}

real24::~real24() {}



// operators
real24::operator float() { return 0; }
real24::operator double(){
}

// signed section
real24::operator std::int8_t() { return 0; }
real24::operator std::int16_t() { return 0; }
real24::operator std::int64_t() { return 0; }
real24::operator std::int32_t() { return 0; }
// unsigned section
real24::operator std::uint8_t() { return 0; }
real24::operator std::uint16_t() { return 0; }
real24::operator std::uint32_t() { return 0; }
real24::operator std::uint64_t() { return 0; }
