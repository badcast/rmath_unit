//Это версия заголовка является основой для своего изучения

#ifndef __RMATH_H
#define __RMATH_H



namespace rmath {
/*
	features: real8, real16, real24, real32, real64 are for calculating math
*/

inline const double to_double(real32 value);
inline const real32 to_prime(real32 value);
inline const real32 mix(real32 value);

//const value
export const real32 minusOne; //initialized in cpp file
export const real32 zero; //initialized in cpp file
export const real32 one; //initialized in cpp file
export const real32 two; //initialized in cpp file
export const real32 NaN; //initialized in cpp file
export const real32 positiveInfinity; //initialized in cpp file
export const real32 negativeInfinity; //initialized in cpp file

inline const real32 create(int p, int q, int c = 0);
inline const real32 create(double rhs);
inline const bool is_negative(const real32& v);
inline const bool is_inf(const real32& v);
inline const bool is_nan(const real32& v);
inline const bool is_int(const real32& v, int value);
inline const bool is_zero(const real32& v);
inline const bool is_one(const real32& v);
inline const bool right(const real32& v);
inline const bool is_normalize(const real32& value);
std::list<uint16_t> get_multipliers(std::size_t value);
const std::size_t NOD(std::size_t lhs, std::size_t rhs);
const std::size_t NOK(std::size_t lhs, std::size_t rhs);
inline const real32 to_prime(real32 v);
//To normalize value
inline const real32 normalize(real32 v);
inline const bool eq_lowest(const real32& lhs, const real32& rhs);
//Operation addition
inline const real32 add(real32 lhs, real32 rhs);
//Operation subtraction
inline const real32 sub(real32 lhs, real32 rhs);
// оператор умножения
inline const real32 mul(real32 lhs, real32 rhs, bool toPrime = true);
// оператор деления
inline const real32 div(real32 lhs, real32 rhs, bool toPrime = true);
inline const real32 mix(real32 value);
inline const double to_double(real32 val);
}
#endif
