#pragma once

#include <list>

#include "real8.hpp"
#include "real16.hpp"
#include "real24.hpp"
#include "real32.hpp"

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
      inline const bool is_int(const rmath::real_t &v, int value);
      inline const bool is_zero(const rmath::real_t &v);
      inline const bool is_one(const rmath::real_t &v);
      inline const bool right(const rmath::real_t &v);
      inline const bool is_normalize(const rmath::real_t &v);
      std::list<uint16_t> get_multipliers(std::size_t value);
      const std::size_t NOD(std::size_t lhs, std::size_t rhs);
      const std::size_t NOK(std::size_t lhs, std::size_t rhs);
      inline const rmath::real_t to_prime(rmath::real_t v);
      // To normalize value
      inline const rmath::real_t normalize(rmath::real_t v);
      inline const bool eq_lowest(const rmath::real_t &lhs, const rmath::real_t &rhs);
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
   }  // namespace func
}  // namespace rmath
