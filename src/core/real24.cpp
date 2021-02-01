#include "../../include/rmath.hpp"

using namespace rmath;

real24::real24() {

}

real24::~real24() {}


//function
real24& real24::one(){
   throw std::exception();
   return *this;
}

real24& real24::zero(){
   throw std::exception();
   return *this;
}


// operators
real24::operator const float() { return 0; }
real24::operator const double(){ return 0; }

// signed section
real24::operator const std::int8_t() { return 0; }
real24::operator const std::int16_t() { return 0; }
real24::operator const std::int64_t() { return 0; }
real24::operator const std::int32_t() { return 0; }
// unsigned section
real24::operator const std::uint8_t() { return 0; }
real24::operator const std::uint16_t() { return 0; }
real24::operator const std::uint32_t() { return 0; }
real24::operator const std::uint64_t() { return 0; }
