---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_set_range_composite.test.cpp
    title: test/yosupo/point_set_range_composite.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"cpp_src/math/modint.hpp\"\ntemplate <unsigned int MOD>\n\
    struct ModInt {\n    using uint = unsigned int;\n    using ull = unsigned long\
    \ long;\n    using M = ModInt;\n\n    uint v;\n\n    ModInt(ll _v = 0) { set_norm(_v\
    \ % MOD + MOD); }\n    M& set_norm(uint _v) {  //[0, MOD * 2)->[0, MOD)\n    \
    \    v = (_v < MOD) ? _v : _v - MOD;\n        return *this;\n    }\n\n    explicit\
    \ operator bool() const { return v != 0; }\n    M operator+(const M& a) const\
    \ { return M().set_norm(v + a.v); }\n    M operator-(const M& a) const { return\
    \ M().set_norm(v + MOD - a.v); }\n    M operator*(const M& a) const { return M().set_norm(ull(v)\
    \ * a.v % MOD); }\n    M operator/(const M& a) const { return *this * a.inv();\
    \ }\n    M& operator+=(const M& a) { return *this = *this + a; }\n    M& operator-=(const\
    \ M& a) { return *this = *this - a; }\n    M& operator*=(const M& a) { return\
    \ *this = *this * a; }\n    M& operator/=(const M& a) { return *this = *this /\
    \ a; }\n    M operator-() const { return M() - *this; }\n    M& operator++(int)\
    \ { return *this = *this + 1; }\n    M& operator--(int) { return *this = *this\
    \ - 1; }\n\n    M pow(ll n) const {\n        if (n < 0) return inv().pow(-n);\n\
    \        M x = *this, res = 1;\n        while (n) {\n            if (n & 1) res\
    \ *= x;\n            x *= x;\n            n >>= 1;\n        }\n        return\
    \ res;\n    }\n\n    M inv() const {\n        ll a = v, b = MOD, p = 1, q = 0,\
    \ t;\n        while (b != 0) {\n            t = a / b;\n            swap(a -=\
    \ t * b, b);\n            swap(p -= t * q, q);\n        }\n        return M(p);\n\
    \    }\n\n    bool operator==(const M& a) const { return v == a.v; }\n    bool\
    \ operator!=(const M& a) const { return v != a.v; }\n    friend ostream& operator<<(ostream&\
    \ os, const M& a) { return os << a.v; }\n    static uint get_mod() { return MOD;\
    \ }\n};\n\n// using Mint = ModInt<1000000007>;\n"
  code: "template <unsigned int MOD>\nstruct ModInt {\n    using uint = unsigned int;\n\
    \    using ull = unsigned long long;\n    using M = ModInt;\n\n    uint v;\n\n\
    \    ModInt(ll _v = 0) { set_norm(_v % MOD + MOD); }\n    M& set_norm(uint _v)\
    \ {  //[0, MOD * 2)->[0, MOD)\n        v = (_v < MOD) ? _v : _v - MOD;\n     \
    \   return *this;\n    }\n\n    explicit operator bool() const { return v != 0;\
    \ }\n    M operator+(const M& a) const { return M().set_norm(v + a.v); }\n   \
    \ M operator-(const M& a) const { return M().set_norm(v + MOD - a.v); }\n    M\
    \ operator*(const M& a) const { return M().set_norm(ull(v) * a.v % MOD); }\n \
    \   M operator/(const M& a) const { return *this * a.inv(); }\n    M& operator+=(const\
    \ M& a) { return *this = *this + a; }\n    M& operator-=(const M& a) { return\
    \ *this = *this - a; }\n    M& operator*=(const M& a) { return *this = *this *\
    \ a; }\n    M& operator/=(const M& a) { return *this = *this / a; }\n    M operator-()\
    \ const { return M() - *this; }\n    M& operator++(int) { return *this = *this\
    \ + 1; }\n    M& operator--(int) { return *this = *this - 1; }\n\n    M pow(ll\
    \ n) const {\n        if (n < 0) return inv().pow(-n);\n        M x = *this, res\
    \ = 1;\n        while (n) {\n            if (n & 1) res *= x;\n            x *=\
    \ x;\n            n >>= 1;\n        }\n        return res;\n    }\n\n    M inv()\
    \ const {\n        ll a = v, b = MOD, p = 1, q = 0, t;\n        while (b != 0)\
    \ {\n            t = a / b;\n            swap(a -= t * b, b);\n            swap(p\
    \ -= t * q, q);\n        }\n        return M(p);\n    }\n\n    bool operator==(const\
    \ M& a) const { return v == a.v; }\n    bool operator!=(const M& a) const { return\
    \ v != a.v; }\n    friend ostream& operator<<(ostream& os, const M& a) { return\
    \ os << a.v; }\n    static uint get_mod() { return MOD; }\n};\n\n// using Mint\
    \ = ModInt<1000000007>;"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/math/modint.hpp
  requiredBy: []
  timestamp: '2020-09-17 02:06:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/point_set_range_composite.test.cpp
documentation_of: cpp_src/math/modint.hpp
layout: document
redirect_from:
- /library/cpp_src/math/modint.hpp
- /library/cpp_src/math/modint.hpp.html
title: cpp_src/math/modint.hpp
---
