#pragma once

#include <list>

#include "real16.hpp"
#include "real24.hpp"
#include "real32.hpp"
#include "real8.hpp"

namespace rmath {

   namespace func {
      // const value
      extern const ::rmath::real_t minusOne;          // initialized in cpp file
      extern const ::rmath::real_t zero;              // initialized in cpp file
      extern const ::rmath::real_t one;               // initialized in cpp file
      extern const ::rmath::real_t two;               // initialized in cpp file
      extern const ::rmath::real_t NaN;               // initialized in cpp file
      extern const ::rmath::real_t positiveInfinity;  // initialized in cpp file
      extern const ::rmath::real_t negativeInfinity;  // initialized in cpp file

      inline const rmath::real_t create(int p, int q, int c = 0);
      inline const rmath::real_t create(double rhs);
      inline const bool is_negative(const rmath::real_t &v);
      inline const bool is_inf(const rmath::real_t &v);
      inline const bool is_nan(const rmath::real_t &v);
      inline const bool is_int(const rmath::real_t &v);
      inline const bool is_int(const rmath::real_t &v, int value);
      inline const bool is_zero(const rmath::real_t &v);
      inline const bool is_one(const rmath::real_t &v);
      inline const bool is_right(const rmath::real_t &v);
      inline const bool is_normalize(const rmath::real_t &v);
      std::list<uint16_t> get_multipliers(std::size_t value);
      const std::size_t nod(std::size_t lhs, std::size_t rhs);
      const std::size_t nok(std::size_t lhs, std::size_t rhs);
      inline const rmath::real_t prime(rmath::real_t v);
      // To normalize value
      inline const rmath::real_t normalize(rmath::real_t v);
      // Operation addition
      inline const rmath::real_t add(rmath::real_t lhs, rmath::real_t rhs);
      // Operation subtraction
      inline const rmath::real_t sub(rmath::real_t lhs, rmath::real_t rhs);
      // оператор умножения   }
      inline const rmath::real_t mul(rmath::real_t lhs, rmath::real_t rhs,
                                     bool toPrime = true);
      // оператор деления
      inline const rmath::real_t div(rmath::real_t lhs, rmath::real_t rhs,
                                     bool toPrime = true);
      inline const rmath::real_t mix(rmath::real_t value);
      inline const double to_double(rmath::real_t val);


      template <typename T>
      struct get_value {
         public:
            get_value(const T &value);
            // is not defined
      };

      template <>
      struct get_value<::rmath::real8> {
         public:
            get_value(const ::rmath::real8 &value);
            std::uint32_t x;
            std::uint32_t y;
            std::uint32_t z;
            // is negative
            bool is_negative;
            // is digit10
            bool is_digit10;
            // is infinity value
            bool is_infinity;
            /* is frac*/
            bool is_frac;
            double result;
      };

      template <>
      struct get_value<::rmath::real16> {
         public:
            get_value(const ::rmath::real16 &value);
            std::uint32_t x;
            std::uint32_t y;
            std::uint32_t z;
            // is negative
            bool is_negative;
            // is digit10
            bool is_digit10;
            // is infinity value
            bool is_infinity;
            /* is frac*/
            bool is_frac;
                  double result;
      };

      template <>
      class get_value<::rmath::real24> {
            get_value(const ::rmath::real24 &value);
            std::uint32_t x;
            std::uint32_t y;
            std::uint32_t z;
            // is negative
            bool is_negative;
            // is digit10
            bool is_digit10;
            // is infinity value
            bool is_infinity;
            /* is frac*/
            bool is_frac;
            double result;
      };

      template <>
      struct get_value<::rmath::real32> {
         public:
            get_value(const ::rmath::real32 &value);
            std::uint32_t x;
            std::uint32_t y;
            std::uint32_t z;
            // is negative
            bool is_negative;
            // is digit10
            bool is_digit10;
            // is infinity value
            bool is_infinity;
            /* is frac*/
            bool is_frac;
            double result;
      };

      template <typename T>
      inline get_value<T> get(const T &source) {
         return get_value<T>(source);
      }

   }  // namespace func
}  // namespace rmath
