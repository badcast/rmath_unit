#pragma once

#include <cstdint>

namespace rmath {
   namespace core {
      namespace RSerializer {
         void set_real(const int8_t* source, const std::size_t& m, int x, int y);

         void set_real(const int8_t* source, const std::size_t& n, int x, int y, int z);

         void set_reall(const int8_t* source, const std::size_t& n, std::int64_t x, std::int64_t y);

         void set_reall(const int8_t* source, const std::size_t& n, std::int64_t x, std::int64_t y, std::int64_t z);

         void get_double(const int8_t* source, const std::size_t& n, double* dest);

         void get_float(const int8_t* source, const std::size_t& n, float* dest);

         void set_double(const double& source, int8_t* dest, const std::size_t& n);

         void set_float(const float& source, int8_t* dest, const std::size_t& n);

         // signed section

         void get_int8(const int8_t* source, const std::size_t& n, std::int8_t* dest);

         void get_int16(const int8_t* source, const std::size_t& n, std::int16_t* dest);

         void get_int32(const int8_t* source, const std::size_t& n, std::int32_t* dest);

         void get_int64(const int8_t* source, const std::size_t& n, std::int64_t* dest);

         void set_int8(const std::int8_t& source, int8_t* dest, const std::size_t& n);

         void set_int16(const std::int16_t& source, int8_t* dest, const std::size_t& n);

         void set_int32(const std::int32_t& source, int8_t* dest, const std::size_t& n);

         void set_int64(const std::int64_t& source, int8_t* dest, const std::size_t& n);

         // unsigned section template<typename target>
         void get_uint8(const int8_t* source, const std::size_t& n, std::uint8_t* dest);

         void get_uint16(const int8_t* source, const std::size_t& n, std::uint16_t* dest);

         void get_uint32(const int8_t* source, const std::size_t& n, std::uint32_t* dest);

         void get_uint64(const int8_t* source, const std::size_t& n, std::uint64_t* dest);

         void set_uint8(const std::uint8_t& source, int8_t* dest, const std::size_t& n);

         void set_uint16(const std::uint16_t& source, int8_t* dest, const std::size_t& n);

         void set_uint32(const std::uint32_t& source, int8_t* dest, const std::size_t& n);

         void set_uint64(const std::uint64_t& source, int8_t* dest, const std::size_t& n);
      }  // namespace RSerializer
   }  // namespace core
}  // namespace rmath
