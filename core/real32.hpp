#pragma once
#include <core.hpp>
#include <real8.hpp>

namespace rmath{

class real32: public core::realbase {
    int m; // целое
    int p; // числитель
    int q; // знаменатель

    real32() = default;

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

    operator double();
    real32& operator+=(const real32& rhs);
    real32& operator-=(const real32& rhs);
    real32& operator*=(const real32& rhs);
    real32& operator/=(const real32& rhs);
} real_t; // real type is default (32 bits)
}