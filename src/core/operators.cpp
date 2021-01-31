#include "../../include/rmath.hpp"

namespace rmath {
   namespace func {

      // const value
      const ::rmath::real_t minusOne(0, -1, 1);
      const ::rmath::real_t zero(0, 0, 1);
      const ::rmath::real_t one(0, 1, 1);
      const ::rmath::real_t two(0, 2, 1);
      const ::rmath::real_t NaN(0, 0, 0);
      const ::rmath::real_t positiveInfinity(0, 1, 0);
      const ::rmath::real_t negativeInfinity(0, -1, 0);

      inline const rmath::real_t create(int p, int q, int c) { return {c, p, q}; }
      inline const rmath::real_t create(double rhs) {
         rmath::real_t v;
         if (rhs == std::numeric_limits<double>::infinity()) {
            v = positiveInfinity;
         } else if (rhs == -std::numeric_limits<double>::infinity()) {
            v = negativeInfinity;
         } else {
            v.m = 0;
            v.p = int(rhs * 1000) - int(rhs * 100);
            v.q = 900;
            v = to_prime(v);
         }
         return v;
      }

      inline const bool is_negative(const rmath::real_t& v) {
         return v.m < 0 || v.p < 0 || v.q < 0;
      }

      inline const bool is_inf(const rmath::real_t& v) { return !v.m && v.p && !v.q; }

      inline const bool is_nan(const rmath::real_t& v) {
         return !v.m && !v.p && !v.q;
      }

      inline const bool is_int(const rmath::real_t& v, int value) {
         return !v.m && v.p == value && v.q == 1;
      }

      inline const bool is_zero(const rmath::real_t& v) { return is_int(v, 0); }

      inline const bool is_one(const rmath::real_t& v) { return is_int(v, 1); }

      inline const bool right(const rmath::real_t& v) {
         return v.m == 0 && v.p < v.q;
      }

      inline const bool is_normalize(const rmath::real_t& v) { return !v.m; }

      std::list<uint16_t> get_multipliers(std::size_t value) {
         if (!value) return std::list<uint16_t>();

         std::list<uint16_t> lst;
         ldiv_t delta;
         long divide;
         delta.quot = value;
         divide = 2;
         while (delta.quot != 1) {
            for (;;) {
               delta = std::ldiv(static_cast<long>(value), divide);
               if (delta.rem)
                  ++divide;
               else {
                  value = delta.quot;
                  break;
               }
            }
            lst.push_back(divide);
         }
         return lst;
      }

      const std::size_t NOD(std::size_t lhs, std::size_t rhs) {
         if (lhs == rhs)
            return lhs;
         else if (lhs > rhs)
            std::swap(lhs, rhs);

         // todo: Оптимизировать O(n2) нужен O(n)
         auto arrL = get_multipliers(lhs);
         auto arrR = get_multipliers(rhs);
         auto p1 = arrL.cbegin();
         auto p2 = arrR.cbegin();

         lhs = 1;
         while (p1 != arrL.cend() && p2 != arrR.cend()) {
            if (*p1 == *p2) {
               lhs *= *p2;
               ++p1;
            }
            ++p2;
         }
         return lhs;
      }

      const std::size_t NOK(std::size_t lhs, std::size_t rhs) {
         if (lhs == rhs)
            return lhs;
         else if (lhs > rhs)
            std::swap(lhs, rhs);

         auto arrL = get_multipliers(lhs);
         auto arrR = get_multipliers(rhs);
         auto p1 = arrL.cbegin();
         auto p2 = arrR.cbegin();
         while (p1 != arrL.cend() && p2 != arrR.cend()) {
            if (*p1 == *p2)
               ++p1;
            else
               lhs *= *p2;
            ++p2;
         }

         return lhs;
      }

      inline const rmath::real_t to_prime(rmath::real_t v) {
         auto nod = NOD(abs(v.p), abs(v.q));
         if (nod > 1) {
            v.p = v.p / static_cast<int>(nod);
            v.q = v.q / static_cast<int>(nod);
         }
         return v;
      }

      // To normalize value
      inline const rmath::real_t normalize(rmath::real_t v) {
         if (!is_normalize(v))  // break do normalize value
         {
            v.p = v.m * v.q + v.p;
            v.m = 0;
         }
         return to_prime(v);
      }

      inline const bool eq_lowest(const rmath::real_t& lhs,
                                  const rmath::real_t& rhs) {
         return to_double(lhs) < to_double(rhs);
      }

      // Operation addition
      inline const rmath::real_t add(rmath::real_t lhs, rmath::real_t rhs) {
         if (!lhs.q || !rhs.q) return lhs;

         lhs = normalize(lhs);
         rhs = normalize(rhs);

         auto nok = NOK(lhs.q, rhs.q);  // nok
         lhs.p = lhs.p * (nok / lhs.q);
         lhs.q = nok;
         rhs.p = rhs.p * (nok / rhs.q);
         lhs.p += rhs.p;  // add
         return lhs;
      }

      // Operation subtraction
      inline const rmath::real_t sub(rmath::real_t lhs, rmath::real_t rhs) {
         decltype(NOK(0, 0)) nok;  // get the type (is optimal variant) c++ 14
         lhs = normalize(lhs);
         rhs = normalize(rhs);
         nok = NOK(lhs.q, rhs.q);  // nok
         lhs.p = lhs.p * (nok / lhs.q);
         lhs.q = nok;
         rhs.p = rhs.p * (nok / rhs.q);
         lhs.p -= rhs.p;  // sub
         return lhs;
      }

      // оператор умножения
      inline const rmath::real_t mul(rmath::real_t lhs, rmath::real_t rhs,
                                     bool toPrime) {
         lhs = normalize(lhs);
         rhs = normalize(rhs);

         lhs.p *= rhs.p;
         lhs.q *= rhs.q;

         if (toPrime) lhs = to_prime(lhs);

         return lhs;
      }

      // оператор деления
      inline const rmath::real_t div(rmath::real_t lhs, rmath::real_t rhs,
                                     bool toPrime) {
         lhs = normalize(lhs);
         rhs = normalize(rhs);

         std::swap(rhs.p, rhs.q);  // операция перевернуть

         lhs.p *= rhs.p;
         lhs.q *= rhs.q;

         if (toPrime) lhs = to_prime(lhs);

         return lhs;
      }

      inline const rmath::real_t mix(rmath::real_t value) {
         value = normalize(value);
         if (!right(value)) {
            value.m = value.p / value.q;
            value.p = value.p % value.q;
         }
         return value;
      }

      inline const double to_double(rmath::real_t val) {
         val = normalize(val);
         return static_cast<double>(val.p) / val.q;
      }

      // ----------------- operators

      const rmath::real_t operator+(const rmath::real_t& lhs,
                                    const rmath::real_t& rhs) {
         return add(lhs, rhs);
      }

      const rmath::real_t operator-(const rmath::real_t& lhs,
                                    const rmath::real_t& rhs) {
         return sub(lhs, rhs);
      }

      const rmath::real_t operator/(const rmath::real_t& lhs,
                                    const rmath::real_t& rhs) {
         return div(lhs, rhs);
      }

      const rmath::real_t operator*(const rmath::real_t& lhs,
                                    const rmath::real_t& rhs) {
         return mul(lhs, rhs, true);
      }

      const rmath::real_t operator+(const rmath::real_t& lhs, const double& rhs) {
         rmath::real_t num = lhs + rmath::real_t(rhs);
         return num;
      }
      const rmath::real_t operator-(const rmath::real_t& lhs, const double& rhs) {
         rmath::real_t num = lhs - rmath::real_t(rhs);
         return num;
      }
      const rmath::real_t operator*(const rmath::real_t& lhs, const double& rhs) {
         rmath::real_t num = lhs * rmath::real_t(rhs);
         return num;
      }
      const rmath::real_t operator/(const rmath::real_t& lhs, const double& rhs) {
         rmath::real_t num = lhs / rmath::real_t(rhs);
         return num;
      }

      const rmath::real_t operator+(const double& lhs, const rmath::real_t& rhs) {
         return rhs + lhs;
      }
      const rmath::real_t operator-(const double& lhs, const rmath::real_t& rhs) {
         return rhs - lhs;
      }
      const rmath::real_t operator*(const double& lhs, const rmath::real_t& rhs) {
         return rhs * lhs;
      }
      const rmath::real_t operator/(const double& lhs, const rmath::real_t& rhs) {
         return rhs / lhs;
      }

      const bool operator==(const rmath::real_t& lhs, const rmath::real_t& rhs) {
         double num = to_double(lhs);
         double num2 = to_double(rhs);
         return num == num2;
      }

      const bool operator>(rmath::real_t lhs, rmath::real_t rhs) {
         lhs = normalize(lhs);
         rhs = normalize(rhs);

         if (lhs.q == rhs.q)
            return lhs.p > rhs.p;
         else if (lhs.p == rhs.p)
            return lhs.q < rhs.q;

         return to_double(lhs) > to_double(rhs);
      }

      const bool operator<(rmath::real_t lhs, rmath::real_t rhs) {
         lhs = normalize(lhs);
         rhs = normalize(rhs);

         if (lhs.q == rhs.q)
            return lhs.p < rhs.p;
         else if (lhs.p == rhs.p)
            return lhs.q > rhs.q;

         return to_double(lhs) < to_double(rhs);
      }

      const bool operator==(const rmath::real_t& lhs, const double& rhs) {
         return to_double(lhs) == rhs;
      }

      const bool operator==(const double& lhs, const rmath::real_t& rhs) {
         return rhs == lhs;
      }
   }  // namespace func
}  // namespace rmath
