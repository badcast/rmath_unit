#pragma once

#include "core.hpp"

namespace rmath {

    typedef class real32 : public core::realbase<0b0100, real32> {
        private:
            using rtype = real32;

        public:
            int m;  // целое
            int p;  // числитель
            int q;  // знаменатель

            real32();
            ~real32();

            real32(const int& x, const int& y, const int& z);

            real32(const double& rhs);
            real32(const int32_t& rhs) : real32(static_cast<int64_t>(rhs)) {}
            real32(const uint32_t& rhs) : real32(static_cast<uint64_t>(rhs)) {}
            real32(const int64_t& rhs);
            real32(const uint64_t& rhs);

            rtype& zero();
            rtype& one();
            rtype& set(const int& x);
            void get(int &x, int &y);
            void get(int &x, int &y, int &z);

            const rtype operator +(const rtype& rhs);
            const rtype operator -(const rtype& rhs);
            const rtype operator *(const rtype& rhs);
            const rtype operator /(const rtype& rhs);
            rtype& operator +=(const rtype& rhs);
            rtype& operator -=(const rtype& rhs);
            rtype& operator *=(const rtype& rhs);
            rtype& operator /=(const rtype& rhs);

            // operators
            operator float();
            operator double();

            // signed section
            operator const std::int8_t();
            operator const std::int16_t();
            operator const std::int64_t();
            operator const std::int32_t();

            // unsigned section
            operator const std::uint8_t();
            operator const std::uint16_t();
            operator const std::uint32_t();
            operator const std::uint64_t();
    } real_t, real32_t;

}  // namespace rmath
