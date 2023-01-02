#include "rational.h"
#include <iostream>
#include <string>
#include <sstream>

Rational::Rational() {
  numerator_ = 0;
  denominator_ = 1;
}

Rational::Rational(int n) {  // NOLINT
  numerator_ = n;
  denominator_ = 1;
}

Rational::Rational(int a, int b) {
  numerator_ = a;
  denominator_ = b;
  Cut();
}

void Rational::Cut() {
  if (denominator_ == 0) {
    throw RationalDivisionByZero();
  }

  if (numerator_ < 0 && denominator_ < 0) {
    numerator_ = abs(numerator_);
    denominator_ = abs(denominator_);
  } else if (numerator_ < 0 || denominator_ < 0) {
    numerator_ = -abs(numerator_);
    denominator_ = abs(denominator_);
  }

  int a = abs(numerator_), b = abs(denominator_);
  while (b) {
    a %= b;
    std::swap(a, b);
  }
  numerator_ /= a;
  denominator_ /= a;
}

int Rational::GetNumerator() const {
  return numerator_;
}

int Rational::GetDenominator() const {
  return denominator_;
}

void Rational::SetNumerator(int num) {
  numerator_ = num;
  Cut();
}

void Rational::SetDenominator(int num) {
  denominator_ = num;
  Cut();
}

Rational operator+(Rational a, Rational b) {
  return Rational(a.GetNumerator() * b.GetDenominator() + b.GetNumerator() * a.GetDenominator(),
                  a.GetDenominator() * b.GetDenominator());
}

Rational operator-(Rational a, Rational b) {
  return Rational(a.GetNumerator() * b.GetDenominator() - b.GetNumerator() * a.GetDenominator(),
                  a.GetDenominator() * b.GetDenominator());
}

Rational operator*(Rational a, Rational b) {
  return Rational(a.GetNumerator() * b.GetNumerator(), a.GetDenominator() * b.GetDenominator());
}

Rational operator/(Rational a, Rational b) {
  return Rational(a.GetNumerator() * b.GetDenominator(), a.GetDenominator() * b.GetNumerator());
}

Rational operator+=(Rational& a, Rational b) {
  a = a + b;
  return a;
}

Rational operator-=(Rational& a, Rational b) {
  a = a - b;
  return a;
}

Rational operator*=(Rational& a, Rational b) {
  a = a * b;
  return a;
}

Rational operator/=(Rational& a, Rational b) {
  a = a / b;
  return a;
}

Rational Rational::operator+() const {
  return *this;
}

Rational Rational::operator-() const {
  return Rational(-numerator_, denominator_);
}

Rational Rational::operator++() {
  numerator_ += denominator_;
  return *this;
}

Rational Rational::operator--() {
  numerator_ -= denominator_;
  return *this;
}

Rational Rational::operator++(int) {
  Rational temp = *this;
  ++(*this);
  return temp;
}

Rational Rational::operator--(int) {
  Rational temp = *this;
  --(*this);
  return temp;
}

std::ostream& operator<<(std::ostream& out, Rational r) {
  if (r.GetDenominator() != 1) {
    out << r.GetNumerator() << "/" << r.GetDenominator();
  } else {
    out << r.GetNumerator();
  }

  return out;
}

std::istream& operator>>(std::istream& in, Rational& r) {
  std::string s;
  in >> s;
  bool more_one = false;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '/') {
      more_one = true;
      s[i] = ' ';
    }
  }

  int a, b = 1;
  std::stringstream strm;
  strm << s;
  if (more_one) {
    strm >> a >> b;
  } else {
    strm >> a;
  }

  r = Rational(a, b);
  return in;
}

bool operator<(const Rational& a, const Rational& b) {
  if (a.GetNumerator() > 0 && b.GetNumerator() > 0) {
    return a.GetNumerator() * b.GetDenominator() < b.GetNumerator() * a.GetDenominator();
  }
  if (a.GetNumerator() < 0 && b.GetNumerator() < 0) {
    return a.GetNumerator() * b.GetDenominator() > b.GetNumerator() * a.GetDenominator();
  }
  return a.GetNumerator() < b.GetNumerator();
}

bool operator>(const Rational& a, const Rational& b) {
  if (a.GetNumerator() > 0 && b.GetNumerator() > 0) {
    return a.GetNumerator() * b.GetDenominator() > b.GetNumerator() * a.GetDenominator();
  }
  if (a.GetNumerator() < 0 && b.GetNumerator() < 0) {
    return a.GetNumerator() * b.GetDenominator() < b.GetNumerator() * a.GetDenominator();
  }
  return a.GetNumerator() > b.GetNumerator();
}

bool operator==(const Rational& a, const Rational& b) {
  return a.GetNumerator() == b.GetNumerator() && a.GetNumerator() == b.GetNumerator();
}

bool operator!=(const Rational& a, const Rational& b) {
  return a.GetNumerator() != b.GetNumerator() || a.GetNumerator() != b.GetNumerator();
}

bool operator<=(const Rational& a, const Rational& b) {
  return a == b || a < b;
}

bool operator>=(const Rational& a, const Rational& b) {
  return a == b || a > b;
}
