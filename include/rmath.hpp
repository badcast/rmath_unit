//Это версия заголовка является основой

#pragma once

#include <cstdlib>
#include <limits>
#include <list>

#include "core/core.hpp"
#include "core/operators.hpp"
#include "core/real8.hpp"
#include "core/real16.hpp"
#include "core/real24.hpp"
#include "core/real32.hpp"

namespace rmath
{
  inline const double to_double(real_t value);
  inline const real_t to_prime(real_t value);
  inline const real_t mix(real_t value);

  //const value

//  const real_t minusOne;//initialized in cpp file
//  const  real_t zero;//initialized in cpp file
//  const real_t one;//initialized in cpp file
//  const  real_t two;//initialized in cpp file
//  const  real_t NaN;//initialized in cpp file
//  const  real_t positiveInfinity;//initialized in cpp file
//  const  real_t negativeInfinity;//initialized in cpp file

  inline const real_t create(int p, int q, int c = 0);
  inline const real_t create(double rhs);
  inline const bool is_negative(const real_t& v);
  inline const bool is_inf(const real_t& v);
  inline const bool is_nan(const real_t& v);
  inline const bool is_int(const real_t& v, int value);
  inline const bool is_zero(const real_t& v);
  inline const bool is_one(const real_t& v);
  inline const bool right(const real_t& v);
  inline const bool is_normalize(const real_t& v);
  std::list<uint16_t> get_multipliers(std::size_t value);
  const std::size_t NOD(std::size_t lhs, std::size_t rhs);
  const std::size_t NOK(std::size_t lhs, std::size_t rhs);
  inline const real_t to_prime(real_t v);
  //To normalize value
  inline const real_t normalize(real_t v);
  inline const bool eq_lowest(const real_t& lhs, const real_t& rhs);
  //Operation addition
  inline const real_t add(real_t lhs, real_t rhs);
  //Operation subtraction
  inline const real_t sub(real_t lhs, real_t rhs);
  // оператор умножения
  inline const real_t mul(real_t lhs, real_t rhs, bool toPrime = true);
  // оператор деления
  inline const real_t div(real_t lhs, real_t rhs, bool toPrime = true);
  inline const real_t mix(real_t value);
  inline const double to_double(real_t val);
}
