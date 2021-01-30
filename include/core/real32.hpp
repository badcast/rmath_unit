#pragma once

#include "core.hpp"
#include "real8.hpp"
#include "real16.hpp"
#include "real24.hpp"

namespace rmath{

  typedef class real32: public core::realbase {
    std::int8_t data[4];
    int m; // целое
    int p; // числитель
    int q; // знаменатель

  public:
    real32();

    real32(const int& m, const int& p, const int& q);

    explicit real32(const double& rhs);
    explicit real32(const int32_t& rhs)
        : real32(static_cast<int64_t>(rhs))
    {
    }
    explicit real32(const uint32_t& rhs)
        : real32(static_cast<uint64_t>(rhs))
    {
    }
    explicit real32(const int64_t& rhs);
    explicit real32(const uint64_t& rhs);

    real32& operator+=(const real32& rhs);
    real32& operator-=(const real32& rhs);
    real32& operator*=(const real32& rhs);
    real32& operator/=(const real32& rhs);

    //operators
    operator float();
    operator double();

    //signed section
    operator std::int8_t();
    operator std::int16_t();
    operator std::int64_t();
    operator std::int32_t();

    //unsigned section
    operator std::uint8_t();
    operator std::uint16_t();
    operator std::uint32_t();
    operator std::uint64_t();
} real_t;
}