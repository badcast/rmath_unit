#include "../../include/core/RSerializer.hpp"
#include "../../include/rmath.hpp"

using namespace rmath;
using namespace rmath::core;

real8::real8() {}

real8::real8(const int& x) {}
real8::real8(const int& x, const int& y) {}
real8::real8(const int& x, const int& y, const int& z) {}
real8::real8(const float& x) {}
real8::real8(const double& x) {}
real8::real8(const real16& rhs) {}
real8::real8(const real24& rhs) {}
real8::real8(const real32& rhs) {}
// function
real8& real8::one() {
    throw std::exception();
    return *this;
}

real8& real8::zero() {
    throw std::exception();
    return *this;
}

// operators
real8::operator const float() const { return 0; }
real8::operator const double() const {
    double d;
    //rmath::core::RSerializer::get_double(this, &d);
    return 0;
}

// signed section
real8::operator const std::int8_t() const { return 0; }
real8::operator const std::int16_t() const { return 0; }
real8::operator const std::int64_t() const { return 0; }
real8::operator const std::int32_t() const { return 0; }
// unsigned section
real8::operator const std::uint8_t() const { return 0; }
real8::operator const std::uint16_t() const { return 0; }
real8::operator const std::uint32_t() const { return 0; }
real8::operator const std::uint64_t() const { return 0; }

const real8 real8::e = real8(1, 7);
