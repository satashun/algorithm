---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"cpp_src/math/ModintRuntime.hpp\"\ntemplate <typename T>\n\
    struct ModInt {\n    using uint = unsigned int;\n    using ull = unsigned long\
    \ long;\n    using M = ModInt;\n    uint MOD = T::mod;\n\n    uint v;\n\n    ModInt(ll\
    \ _v = 0) { set_norm(_v % MOD + MOD); }\n    M& set_norm(uint _v) {  //[0, MOD\
    \ * 2)->[0, MOD)\n        v = (_v < MOD) ? _v : _v - MOD;\n        return *this;\n\
    \    }\n\n    explicit operator bool() const { return v != 0; }\n    M operator+(const\
    \ M& a) const { return M().set_norm(v + a.v); }\n    M operator-(const M& a) const\
    \ { return M().set_norm(v + MOD - a.v); }\n    M operator*(const M& a) const {\
    \ return M().set_norm(ull(v) * a.v % MOD); }\n    M operator/(const M& a) const\
    \ { return *this * a.inv(); }\n    M& operator+=(const M& a) { return *this =\
    \ *this + a; }\n    M& operator-=(const M& a) { return *this = *this - a; }\n\
    \    M& operator*=(const M& a) { return *this = *this * a; }\n    M& operator/=(const\
    \ M& a) { return *this = *this / a; }\n    M operator-() const { return M() -\
    \ *this; }\n    M& operator++(int) { return *this = *this + 1; }\n    M& operator--(int)\
    \ { return *this = *this - 1; }\n\n    M pow(ll n) const {\n        if (n < 0)\
    \ return inv().pow(-n);\n        M x = *this, res = 1;\n        while (n) {\n\
    \            if (n & 1) res *= x;\n            x *= x;\n            n >>= 1;\n\
    \        }\n        return res;\n    }\n\n    M inv() const { return pow(MOD -\
    \ 2); }\n\n    /*\n\n        M inv() const {\n                ll a = v, b = MOD,\
    \ p = 1, q = 0, t;\n                while (b != 0) {\n                       \
    \ t = a / b;\n                        swap(a -= t * b, b);\n                 \
    \       swap(p -= t * q, q);\n                }\n                return M(p);\n\
    \        }*/\n\n    bool operator==(const M& a) const { return v == a.v; }\n \
    \   bool operator!=(const M& a) const { return v != a.v; }\n    friend ostream&\
    \ operator<<(ostream& os, const M& a) { return os << a.v; }\n    uint get_mod()\
    \ { return MOD; }\n};\n\nstruct ModInfo {\n    static int mod;\n};\n\nint ModInfo::mod;\n\
    int& md = ModInfo::mod;\nusing Mint = ModInt<ModInfo>;\n"
  code: "template <typename T>\nstruct ModInt {\n    using uint = unsigned int;\n\
    \    using ull = unsigned long long;\n    using M = ModInt;\n    uint MOD = T::mod;\n\
    \n    uint v;\n\n    ModInt(ll _v = 0) { set_norm(_v % MOD + MOD); }\n    M& set_norm(uint\
    \ _v) {  //[0, MOD * 2)->[0, MOD)\n        v = (_v < MOD) ? _v : _v - MOD;\n \
    \       return *this;\n    }\n\n    explicit operator bool() const { return v\
    \ != 0; }\n    M operator+(const M& a) const { return M().set_norm(v + a.v); }\n\
    \    M operator-(const M& a) const { return M().set_norm(v + MOD - a.v); }\n \
    \   M operator*(const M& a) const { return M().set_norm(ull(v) * a.v % MOD); }\n\
    \    M operator/(const M& a) const { return *this * a.inv(); }\n    M& operator+=(const\
    \ M& a) { return *this = *this + a; }\n    M& operator-=(const M& a) { return\
    \ *this = *this - a; }\n    M& operator*=(const M& a) { return *this = *this *\
    \ a; }\n    M& operator/=(const M& a) { return *this = *this / a; }\n    M operator-()\
    \ const { return M() - *this; }\n    M& operator++(int) { return *this = *this\
    \ + 1; }\n    M& operator--(int) { return *this = *this - 1; }\n\n    M pow(ll\
    \ n) const {\n        if (n < 0) return inv().pow(-n);\n        M x = *this, res\
    \ = 1;\n        while (n) {\n            if (n & 1) res *= x;\n            x *=\
    \ x;\n            n >>= 1;\n        }\n        return res;\n    }\n\n    M inv()\
    \ const { return pow(MOD - 2); }\n\n    /*\n\n        M inv() const {\n      \
    \          ll a = v, b = MOD, p = 1, q = 0, t;\n                while (b != 0)\
    \ {\n                        t = a / b;\n                        swap(a -= t *\
    \ b, b);\n                        swap(p -= t * q, q);\n                }\n  \
    \              return M(p);\n        }*/\n\n    bool operator==(const M& a) const\
    \ { return v == a.v; }\n    bool operator!=(const M& a) const { return v != a.v;\
    \ }\n    friend ostream& operator<<(ostream& os, const M& a) { return os << a.v;\
    \ }\n    uint get_mod() { return MOD; }\n};\n\nstruct ModInfo {\n    static int\
    \ mod;\n};\n\nint ModInfo::mod;\nint& md = ModInfo::mod;\nusing Mint = ModInt<ModInfo>;"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/math/ModintRuntime.hpp
  requiredBy: []
  timestamp: '2020-09-17 00:08:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/math/ModintRuntime.hpp
layout: document
redirect_from:
- /library/cpp_src/math/ModintRuntime.hpp
- /library/cpp_src/math/ModintRuntime.hpp.html
title: cpp_src/math/ModintRuntime.hpp
---
