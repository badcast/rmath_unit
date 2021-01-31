#include "../../include/rmath.hpp"

using namespace rmath;

real8::real8() {

}

real8::~real8() {

}



// operators
real8::operator float() { return 0; }
real8::operator double(){
   return {};
}


// signed section
real8::operator std::int8_t() { return 0; }
real8::operator std::int16_t() { return 0; }
real8::operator std::int64_t() { return 0; }
real8::operator std::int32_t() { return 0; }
// unsigned section
real8::operator std::uint8_t() { return 0; }
real8::operator std::uint16_t() { return 0; }
real8::operator std::uint32_t() { return 0; }
real8::operator std::uint64_t() { return 0; }
