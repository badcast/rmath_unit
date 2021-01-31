#include "../../include/rmath.hpp"

using namespace rmath;

real16::real16() {

}

real16::~real16() {}



// operators
real16::operator float() { return 0; }
real16::operator double(){
}

// signed section
real16::operator std::int8_t() { return 0; }
real16::operator std::int16_t() { return 0; }
real16::operator std::int64_t() { return 0; }
real16::operator std::int32_t() { return 0; }
// unsigned section
real16::operator std::uint8_t() { return 0; }
real16::operator std::uint16_t() { return 0; }
real16::operator std::uint32_t() { return 0; }
real16::operator std::uint64_t() { return 0; }
