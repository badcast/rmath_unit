#include <cstring>
#include <stdexcept>

#include "../../include/rmath.hpp"
#include "../../include/core/RSerializer.hpp"

using namespace rmath::core;
using namespace rmath::core::RSerializer;

enum RealContainerMask : char { MASK_NEGATIVE = 0x1, MASK_INT = 0x2 };

const uint32_t bitsArray[4][2] = {{0x1C>>2, 0xE0>>2}, {0x1fc>>2, 0xfe00>>2}, {0x1ffc>>2, 0xFFE000>>2}, {0x1FFFC>>2, 0xFFFE0000>>2}};

void get_member_real32(const int8_t* source, const std::size_t n, int& x, int &y){
   int z;

   if (n < 1 && n > sizeof(int)) throw std::runtime_error("sizeof N is big");
   x = 0;
   z = 2;  // z = 2 >------------------------------>|
   if (*source & RealContainerMask::MASK_INT) { //  |
      std::memcpy(&x, source, n);               //  |
      x >>= z;  // z is 2 -------------------------<|
      y = 1;                                    //  |
   } else {                                     //  |
      //formula:      n * 8 - 2                     |
      //          z = ----------, N > 0             |
      //                  2                         |
      // Дальнейшем оптимизировать этот блок кода.  |
      //todo: Оптимизировать                        |
      //                                            |
      z = (n * 8 - z) / z; // z is 2 --------------<|

      std::memcpy(&x, source, n);
      y = x >>= 2;
      x = x & bitsArray[n-1][0];
      y = y & bitsArray[n-1][1];
      y >>= n * z;
   }
   if ((*source) & RealContainerMask::MASK_NEGATIVE) x *= ~0;
}

void set_member_real32(const int8_t* source, const std::size_t& n, int x, int y){
   if(source == nullptr || n < 1 && n > sizeof(int))
         throw std::runtime_error("argument is invalid");



}

namespace rmath{
   namespace core{
      namespace RSerializer{

         void set_real(const int8_t* source, const std::size_t& m, int x, int y){

         }

         void set_real(const int8_t* source, const std::size_t& n, int x, int y, int z){

         }

         void set_reall(const int8_t* source, const std::size_t& n, std::int64_t x, std::int64_t y){

         }

         void set_reall(const int8_t* source, const std::size_t& n, std::int64_t x, std::int64_t y, std::int64_t z){

         }

         void get_float(const int8_t* source , const std::size_t& n, float* dest) {
            int x,y;
            if(dest == nullptr || source == nullptr)
            {
               throw std::runtime_error("argument is null");
            }

            get_member_real32(source, n,x,y);
            *dest = static_cast<float>(x) / y;
         }

         void get_double(const int8_t* source , const std::size_t& n, double* dest) {
            int x;
            int y;
            if(dest == nullptr || source == nullptr)
            {
               throw std::runtime_error("argument is null");
            }
            get_member_real32(source,  n, x, y);
            *dest = static_cast<double>(x) / y; // calc
         }
         void get_int8(const std::int8_t* source , const std::size_t& n, std::int8_t* dest) {}
         void get_int16(const std::int8_t* source,  const std::size_t& n, std::int16_t* dest) {}
         void get_int32(const std::int8_t* source,  const std::size_t& n, std::int32_t* dest) {}
         void get_int64(const std::int8_t* source,  const std::size_t& n, std::int64_t* dest) {}
         void get_uint8(const std::int8_t* source,  const std::size_t& n, std::uint8_t* dest) {}
         void get_uint16(const std::int8_t* source, const std::size_t& n, std::uint16_t* dest) {}
         void get_uint32(const std::int8_t* source, const std::size_t& n, std::uint32_t* dest) {}
         void get_uint64(const std::int8_t* source, const std::size_t& n, std::uint64_t* dest) {}
         void set_double(const double& source, const std::size_t& n, std::int8_t* dest) {}
         void set_float(const float& source, std::int8_t* dest, const std::size_t& n) {}
         void set_int8(const std::int8_t& source, int8_t* dest, const std::size_t& n) {}
         void set_int16(const std::int16_t& source, int8_t* dest, const std::size_t& n) {}
         void set_int32(const std::int32_t& source, int8_t* dest, const std::size_t& n) {}
         void set_int64(const std::int64_t& source, int8_t* dest, const std::size_t& n) {}
         void set_uint8(const std::uint8_t& source, int8_t* dest, const std::size_t& n) {}
         void set_uint16(const std::uint16_t& source, int8_t* dest, const std::size_t& n) {}
         void set_uint32(const std::uint32_t& source, int8_t* dest, const std::size_t& n) {}
         void set_uint64(const std::uint64_t& source, int8_t* dest, const std::size_t& n) {}
      }
   }
}
