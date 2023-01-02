#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include <string>
#include <sstream>

class RationalDivisionByZero {};

class Rational {
 private:
  int numerator_;
  int denominator_;
 public:
  Rational();
  Rational(int);  // NOLINT
  Rational(int, int);
  Rational(const Rational&) = default;

  void Cut();

  int GetNumerator() const;
  int GetDenominator() const;

  void SetNumerator(int);
  void SetDenominator(int);

  Rational operator+() const;
  Rational operator-() const;

  Rational operator++();
  Rational operator--();

  Rational operator++(int);
  Rational operator--(int);
};

Rational operator+(Rational, Rational);
Rational operator-(Rational, Rational);
Rational operator*(Rational, Rational);
Rational operator/(Rational, Rational);

bool operator<(const Rational&, const Rational&);
bool operator>(const Rational&, const Rational&);
bool operator==(const Rational&, const Rational&);
bool operator!=(const Rational&, const Rational&);
bool operator<=(const Rational&, const Rational&);
bool operator>=(const Rational&, const Rational&);

Rational operator+=(Rational&, Rational);
Rational operator-=(Rational&, Rational);
Rational operator*=(Rational&, Rational);
Rational operator/=(Rational&, Rational);

std::ostream& operator<<(std::ostream&, Rational);
std::istream& operator>>(std::istream&, Rational&);

#endif