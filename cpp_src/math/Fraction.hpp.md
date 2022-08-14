---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/math/Fraction.hpp\"\ntemplate <class T>\nT gcd(T\
    \ a, T b) {\n    return b ? gcd(b, a % b) : a;\n}\n\n// a / b\ntemplate <class\
    \ T>\nstruct Fraction {\n    T a, b;\n    Fraction(T _a = 0) : a(_a), b(1) {}\n\
    \    Fraction(T _a, T _b) {\n        if (_b < 0) {\n            _a *= -1;\n  \
    \          _b *= -1;\n        }\n        T g = gcd(abs(_a), abs(_b));\n      \
    \  a = _a / g;\n        b = _b / g;\n    }\n\n    using F = Fraction;\n\n    F\
    \ operator-() const {\n        F f;\n        f.a = -a;\n        f.b = b;\n   \
    \     return f;\n    }\n\n    F operator+(const F& r) const { return {r.b * a\
    \ + b * r.a, b * r.b}; }\n    F operator-(const F& r) const { return *this + (-r);\
    \ }\n    F operator*(const F& r) const { return {a * r.a, b * r.b}; }\n    F operator/(const\
    \ F& r) const { return {a * r.b, b * r.a}; }\n    F& operator+=(const F& r) {\
    \ return *this = *this + r; }\n    F& operator-=(const F& r) { return *this =\
    \ *this - r; }\n    F& operator*=(const F& r) { return *this = *this * r; }\n\
    \    F& operator/=(const F& r) { return *this = *this / r; }\n    bool operator<(const\
    \ F& r) const { return a * r.b < b * r.a; }\n    bool operator>(const F& r) const\
    \ { return r < *this; }\n    bool operator<=(const F& r) const { return !(r <\
    \ *this); }\n    bool operator>=(const F& r) const { return !(*this < r); }\n\
    \    bool operator==(const F& r) const { return !(*this < r) && !(r < *this);\
    \ }\n    bool operator!=(const F& r) const { return !(*this == r); }\n    friend\
    \ ostream& operator<<(ostream& os, const F& v) {\n        return os << v.a <<\
    \ '/' << v.b;\n    }\n};\n"
  code: "template <class T>\nT gcd(T a, T b) {\n    return b ? gcd(b, a % b) : a;\n\
    }\n\n// a / b\ntemplate <class T>\nstruct Fraction {\n    T a, b;\n    Fraction(T\
    \ _a = 0) : a(_a), b(1) {}\n    Fraction(T _a, T _b) {\n        if (_b < 0) {\n\
    \            _a *= -1;\n            _b *= -1;\n        }\n        T g = gcd(abs(_a),\
    \ abs(_b));\n        a = _a / g;\n        b = _b / g;\n    }\n\n    using F =\
    \ Fraction;\n\n    F operator-() const {\n        F f;\n        f.a = -a;\n  \
    \      f.b = b;\n        return f;\n    }\n\n    F operator+(const F& r) const\
    \ { return {r.b * a + b * r.a, b * r.b}; }\n    F operator-(const F& r) const\
    \ { return *this + (-r); }\n    F operator*(const F& r) const { return {a * r.a,\
    \ b * r.b}; }\n    F operator/(const F& r) const { return {a * r.b, b * r.a};\
    \ }\n    F& operator+=(const F& r) { return *this = *this + r; }\n    F& operator-=(const\
    \ F& r) { return *this = *this - r; }\n    F& operator*=(const F& r) { return\
    \ *this = *this * r; }\n    F& operator/=(const F& r) { return *this = *this /\
    \ r; }\n    bool operator<(const F& r) const { return a * r.b < b * r.a; }\n \
    \   bool operator>(const F& r) const { return r < *this; }\n    bool operator<=(const\
    \ F& r) const { return !(r < *this); }\n    bool operator>=(const F& r) const\
    \ { return !(*this < r); }\n    bool operator==(const F& r) const { return !(*this\
    \ < r) && !(r < *this); }\n    bool operator!=(const F& r) const { return !(*this\
    \ == r); }\n    friend ostream& operator<<(ostream& os, const F& v) {\n      \
    \  return os << v.a << '/' << v.b;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/math/Fraction.hpp
  requiredBy: []
  timestamp: '2022-08-15 00:42:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/math/Fraction.hpp
layout: document
redirect_from:
- /library/cpp_src/math/Fraction.hpp
- /library/cpp_src/math/Fraction.hpp.html
title: cpp_src/math/Fraction.hpp
---
