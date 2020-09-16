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
  bundledCode: "#line 1 \"cpp_src/math/polynomial.hpp\"\n//depends on FFT libs\n//basically\
    \ use with ModInt\n\nNumberTheoreticTransform<Mint> ntt;\n\ntemplate<class D>\n\
    struct Poly : public V<D> {\n\ttemplate<class...Args>\n\tPoly(Args...args):V<D>(args...){}\n\
    \tPoly(initializer_list<D>init):V<D>(init.begin(),init.end()){}\n\n\tint size()\
    \ const { return V<D>::size(); }\n\tD at(int p) const { return (p < this->size()\
    \ ? (*this)[p] : D(0)); }\n\n\t//first len terms\n\tPoly pref(int len) const {\n\
    \t\treturn Poly(this->begin(), this->begin() + min(this->size(), len));\n\t}\n\
    \n\t//for polynomial division\n\tPoly rev() const {\n\t\tPoly res = *this;\n\t\
    \treverse(res.begin(), res.end());\n\t\treturn res;\n\t} \t\n\n\tPoly operator+(const\
    \ Poly& r) const {\n\t\tauto n = max(size(), r.size());\n\t\tV<D> tmp(n);\n\t\t\
    for (int i = 0; i < n; ++i) {\n\t\t\ttmp[i] = at(i) + r.at(i);\n\t\t}\n\t\treturn\
    \ tmp;\n\t}\n\tPoly operator-(const Poly& r) const {\n\t\tauto n = max(size(),\
    \ r.size());\n\t\tV<D> tmp(n);\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\ttmp[i]\
    \ = at(i) - r.at(i);\n\t\t}\n\t\treturn tmp;\n\t}\n\n\t//scalar\n\tPoly operator*(const\
    \ D& k) const {\n\t\tint n = size();\n\t\tV<D> tmp(n);\n\t\tfor (int i = 0; i\
    \ < n; ++i) {\n\t\t\ttmp[i] = at(i) * k;\n\t\t}\n\t\treturn tmp;\n\t}\n\n\tPoly\
    \ operator*(const Poly& r) const {\n\t\tPoly a = *this;\n\t\tPoly b = r;\n\t\t\
    auto v = ntt.mul(a, b);\n\t\treturn v; \n\t}\n\n\t//scalar\n\tPoly operator/(const\
    \ D& k) const {\n\t\treturn *this * k.inv();\n\t}\n\n\tPoly operator/(const Poly&\
    \ r) const {\n\t\tif (size() < r.size()) {\n\t\t\treturn {{}};\n\t\t}\n\t\tint\
    \ d = size() - r.size() + 1;\n\t\treturn (rev().pref(d) * r.rev().inv(d)).pref(d).rev();\n\
    \t}\n\n\tPoly operator%(const Poly& r) const {\n\t\tauto res = *this - *this /\
    \ r * r;\n\t\twhile (res.size() && !res.back()) {\n\t\t\tres.pop_back();\n\t\t\
    }\n\t\treturn res;\n\t}\n\n\tPoly diff() const {\n\t\tV<D> res(max(0, size() -\
    \ 1));\n\t\tfor (int i = 1; i < size(); ++i) {\n\t\t\tres[i - 1] = at(i) * i;\n\
    \t\t}\n\t\treturn res;\n\t}\n\n\tPoly inte() const {\n\t\tV<D> res(size() + 1);\n\
    \t\tfor (int i = 0; i < size(); ++i) {\n\t\t\tres[i + 1] = at(i) / (D)(i + 1);\n\
    \t\t}\n\t\treturn res;\n\t}\n\n\t//f * f.inv(m) === 1 mod (x^m)\n\t//f_0 ^ -1\
    \ must exist\n\tPoly inv(int m) const {\n\t\tPoly res = Poly({D(1) / at(0)});\n\
    \t\tfor (int i = 1; i < m; i *= 2) {\n\t\t\tres = (res * D(2) - res * res * pref(i\
    \ * 2)).pref(i * 2);\n\t\t}\n\t\treturn res.pref(m);\n\t}\n\n\t//f_0 = 1 must\
    \ hold\n\tPoly log(int n) const {\n\t\tauto f = pref(n);\n\t\treturn (f.diff()\
    \ * f.inv(n - 1)).pref(n - 1).inte();\n\t}\n\n\t//f_0 = 0 must hold\n\tPoly exp(int\
    \ n) const {\n\t\tauto h = diff();\n\t\tPoly f({1}), g({1});\n\n\t\tfor (int m\
    \ = 1; m < n; m *= 2) {\t\t\n\t\t\tg = (g * D(2) - f * g * g).pref(m); \n\t\t\t\
    auto q = h.pref(m - 1);\n\t\t\tauto w = (q + g * (f.diff() - f * q)).pref(m *\
    \ 2 - 1);\n\t\t\tf = (f + f * (*this - w.inte()).pref(m * 2)).pref(m * 2);\n\t\
    \t}\n\n\t\treturn f.pref(n);\n\t}\n\n\t//be careful when k = 0\n\tPoly pow(int\
    \ n, ll k) const {\n\t\treturn (log(n) * (D)k).exp(n);\n\t}\n\n\t//f_0 = 1 must\
    \ hold (use it with modular sqrt)\n\t//CF250E\n\tPoly sqrt(int n) const {\n\t\t\
    Poly f = pref(n);\n\t\tPoly g({1});\n\t\tfor (int i = 1; i < n; i *= 2) {\n\t\t\
    \tg = (g + f.pref(i * 2) * g.inv(i * 2)) * D(2).inv();\n\t\t}\n\t\treturn g.pref(n);\n\
    \t}\n\n\tD eval(D x) const {\n\t\tD res = 0, c = 1;\n\t\tfor (auto a : *this)\
    \ {\n\t\t\tres += a * c;\n\t\t\tc *= x;\n\t\t}\n\t\treturn res;\n\t} \n\n\tPoly&\
    \ operator+=(const Poly& r) { return *this = *this + r; }\n\tPoly& operator-=(const\
    \ Poly& r) { return *this = *this - r; }\n\tPoly& operator*=(const D& r) { return\
    \ *this = *this * r; }\n\tPoly& operator*=(const Poly& r) { return *this = *this\
    \ * r; }\n\tPoly& operator/=(const Poly& r) { return *this = *this / r; }\n\t\
    Poly& operator/=(const D &r) { return *this = *this / r; }\n\tPoly& operator%=(const\
    \ Poly& r) { return *this = *this % r; }\n\n\tfriend ostream& operator<<(ostream&\
    \ os, const Poly& pl) {\n\t\tif (pl.size() == 0) return os << \"0\";\n\t\tfor\
    \ (int i = 0; i < pl.size(); ++i) {\n\t\t\tif (pl[i]) {\n\t\t\t\tos << pl[i] <<\
    \ \"x^\" << i;\n\t\t\t\tif (i + 1 != pl.size()) os << \",\";\n\t\t\t}\n\t\t}\n\
    \t\treturn os;\n\t}\n};\n\n//calculate characteristic polynomial\n//c_0 * s_i\
    \ + c_1 * s_{i+1} + ... + c_k * s_{i+k} = 0\n//c_k = -1\n\ntemplate<class T>\n\
    Poly<T> berlekamp_massey(const V<T>& s) {\n\tint n = int(s.size());\n\tV<T> b\
    \ = {T(-1)}, c = {T(-1)};\n\tT y = Mint(1);\n\tfor (int ed = 1; ed <= n; ed++)\
    \ {\n\t\tint l = int(c.size()), m = int(b.size());\n\t\tT x = 0;\n\t\tfor (int\
    \ i = 0; i < l; i++) {\n\t\t\tx += c[i] * s[ed - l + i];\n\t\t}\n\t\tb.push_back(0);\n\
    \t\tm++;\n\t\tif (!x) {\n\t\t\tcontinue;\n\t\t}\n\t\tT freq = x / y;\n\t\tif (l\
    \ < m) {\n\t\t\tauto tmp = c;\n\t\t\tc.insert(begin(c), m - l, Mint(0));\n\t\t\
    \tfor (int i = 0; i < m; i++) {\n\t\t\t\tc[m - 1 - i] -= freq * b[m - 1 - i];\n\
    \t\t\t}\n\t\t\tb = tmp;\n\t\t\ty = x;\n\t\t} else {\n\t\t\tfor (int i = 0; i <\
    \ m; i++) {\n\t\t\t\tc[l - 1 - i] -= freq * b[m - 1 - i];\n\t\t\t}\n\t\t}\n\t\
    }\n\treturn c;\n}\n"
  code: "//depends on FFT libs\n//basically use with ModInt\n\nNumberTheoreticTransform<Mint>\
    \ ntt;\n\ntemplate<class D>\nstruct Poly : public V<D> {\n\ttemplate<class...Args>\n\
    \tPoly(Args...args):V<D>(args...){}\n\tPoly(initializer_list<D>init):V<D>(init.begin(),init.end()){}\n\
    \n\tint size() const { return V<D>::size(); }\n\tD at(int p) const { return (p\
    \ < this->size() ? (*this)[p] : D(0)); }\n\n\t//first len terms\n\tPoly pref(int\
    \ len) const {\n\t\treturn Poly(this->begin(), this->begin() + min(this->size(),\
    \ len));\n\t}\n\n\t//for polynomial division\n\tPoly rev() const {\n\t\tPoly res\
    \ = *this;\n\t\treverse(res.begin(), res.end());\n\t\treturn res;\n\t} \t\n\n\t\
    Poly operator+(const Poly& r) const {\n\t\tauto n = max(size(), r.size());\n\t\
    \tV<D> tmp(n);\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\ttmp[i] = at(i) + r.at(i);\n\
    \t\t}\n\t\treturn tmp;\n\t}\n\tPoly operator-(const Poly& r) const {\n\t\tauto\
    \ n = max(size(), r.size());\n\t\tV<D> tmp(n);\n\t\tfor (int i = 0; i < n; ++i)\
    \ {\n\t\t\ttmp[i] = at(i) - r.at(i);\n\t\t}\n\t\treturn tmp;\n\t}\n\n\t//scalar\n\
    \tPoly operator*(const D& k) const {\n\t\tint n = size();\n\t\tV<D> tmp(n);\n\t\
    \tfor (int i = 0; i < n; ++i) {\n\t\t\ttmp[i] = at(i) * k;\n\t\t}\n\t\treturn\
    \ tmp;\n\t}\n\n\tPoly operator*(const Poly& r) const {\n\t\tPoly a = *this;\n\t\
    \tPoly b = r;\n\t\tauto v = ntt.mul(a, b);\n\t\treturn v; \n\t}\n\n\t//scalar\n\
    \tPoly operator/(const D& k) const {\n\t\treturn *this * k.inv();\n\t}\n\n\tPoly\
    \ operator/(const Poly& r) const {\n\t\tif (size() < r.size()) {\n\t\t\treturn\
    \ {{}};\n\t\t}\n\t\tint d = size() - r.size() + 1;\n\t\treturn (rev().pref(d)\
    \ * r.rev().inv(d)).pref(d).rev();\n\t}\n\n\tPoly operator%(const Poly& r) const\
    \ {\n\t\tauto res = *this - *this / r * r;\n\t\twhile (res.size() && !res.back())\
    \ {\n\t\t\tres.pop_back();\n\t\t}\n\t\treturn res;\n\t}\n\n\tPoly diff() const\
    \ {\n\t\tV<D> res(max(0, size() - 1));\n\t\tfor (int i = 1; i < size(); ++i) {\n\
    \t\t\tres[i - 1] = at(i) * i;\n\t\t}\n\t\treturn res;\n\t}\n\n\tPoly inte() const\
    \ {\n\t\tV<D> res(size() + 1);\n\t\tfor (int i = 0; i < size(); ++i) {\n\t\t\t\
    res[i + 1] = at(i) / (D)(i + 1);\n\t\t}\n\t\treturn res;\n\t}\n\n\t//f * f.inv(m)\
    \ === 1 mod (x^m)\n\t//f_0 ^ -1 must exist\n\tPoly inv(int m) const {\n\t\tPoly\
    \ res = Poly({D(1) / at(0)});\n\t\tfor (int i = 1; i < m; i *= 2) {\n\t\t\tres\
    \ = (res * D(2) - res * res * pref(i * 2)).pref(i * 2);\n\t\t}\n\t\treturn res.pref(m);\n\
    \t}\n\n\t//f_0 = 1 must hold\n\tPoly log(int n) const {\n\t\tauto f = pref(n);\n\
    \t\treturn (f.diff() * f.inv(n - 1)).pref(n - 1).inte();\n\t}\n\n\t//f_0 = 0 must\
    \ hold\n\tPoly exp(int n) const {\n\t\tauto h = diff();\n\t\tPoly f({1}), g({1});\n\
    \n\t\tfor (int m = 1; m < n; m *= 2) {\t\t\n\t\t\tg = (g * D(2) - f * g * g).pref(m);\
    \ \n\t\t\tauto q = h.pref(m - 1);\n\t\t\tauto w = (q + g * (f.diff() - f * q)).pref(m\
    \ * 2 - 1);\n\t\t\tf = (f + f * (*this - w.inte()).pref(m * 2)).pref(m * 2);\n\
    \t\t}\n\n\t\treturn f.pref(n);\n\t}\n\n\t//be careful when k = 0\n\tPoly pow(int\
    \ n, ll k) const {\n\t\treturn (log(n) * (D)k).exp(n);\n\t}\n\n\t//f_0 = 1 must\
    \ hold (use it with modular sqrt)\n\t//CF250E\n\tPoly sqrt(int n) const {\n\t\t\
    Poly f = pref(n);\n\t\tPoly g({1});\n\t\tfor (int i = 1; i < n; i *= 2) {\n\t\t\
    \tg = (g + f.pref(i * 2) * g.inv(i * 2)) * D(2).inv();\n\t\t}\n\t\treturn g.pref(n);\n\
    \t}\n\n\tD eval(D x) const {\n\t\tD res = 0, c = 1;\n\t\tfor (auto a : *this)\
    \ {\n\t\t\tres += a * c;\n\t\t\tc *= x;\n\t\t}\n\t\treturn res;\n\t} \n\n\tPoly&\
    \ operator+=(const Poly& r) { return *this = *this + r; }\n\tPoly& operator-=(const\
    \ Poly& r) { return *this = *this - r; }\n\tPoly& operator*=(const D& r) { return\
    \ *this = *this * r; }\n\tPoly& operator*=(const Poly& r) { return *this = *this\
    \ * r; }\n\tPoly& operator/=(const Poly& r) { return *this = *this / r; }\n\t\
    Poly& operator/=(const D &r) { return *this = *this / r; }\n\tPoly& operator%=(const\
    \ Poly& r) { return *this = *this % r; }\n\n\tfriend ostream& operator<<(ostream&\
    \ os, const Poly& pl) {\n\t\tif (pl.size() == 0) return os << \"0\";\n\t\tfor\
    \ (int i = 0; i < pl.size(); ++i) {\n\t\t\tif (pl[i]) {\n\t\t\t\tos << pl[i] <<\
    \ \"x^\" << i;\n\t\t\t\tif (i + 1 != pl.size()) os << \",\";\n\t\t\t}\n\t\t}\n\
    \t\treturn os;\n\t}\n};\n\n//calculate characteristic polynomial\n//c_0 * s_i\
    \ + c_1 * s_{i+1} + ... + c_k * s_{i+k} = 0\n//c_k = -1\n\ntemplate<class T>\n\
    Poly<T> berlekamp_massey(const V<T>& s) {\n\tint n = int(s.size());\n\tV<T> b\
    \ = {T(-1)}, c = {T(-1)};\n\tT y = Mint(1);\n\tfor (int ed = 1; ed <= n; ed++)\
    \ {\n\t\tint l = int(c.size()), m = int(b.size());\n\t\tT x = 0;\n\t\tfor (int\
    \ i = 0; i < l; i++) {\n\t\t\tx += c[i] * s[ed - l + i];\n\t\t}\n\t\tb.push_back(0);\n\
    \t\tm++;\n\t\tif (!x) {\n\t\t\tcontinue;\n\t\t}\n\t\tT freq = x / y;\n\t\tif (l\
    \ < m) {\n\t\t\tauto tmp = c;\n\t\t\tc.insert(begin(c), m - l, Mint(0));\n\t\t\
    \tfor (int i = 0; i < m; i++) {\n\t\t\t\tc[m - 1 - i] -= freq * b[m - 1 - i];\n\
    \t\t\t}\n\t\t\tb = tmp;\n\t\t\ty = x;\n\t\t} else {\n\t\t\tfor (int i = 0; i <\
    \ m; i++) {\n\t\t\t\tc[l - 1 - i] -= freq * b[m - 1 - i];\n\t\t\t}\n\t\t}\n\t\
    }\n\treturn c;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/math/polynomial.hpp
  requiredBy: []
  timestamp: '2020-09-17 02:07:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/math/polynomial.hpp
layout: document
redirect_from:
- /library/cpp_src/math/polynomial.hpp
- /library/cpp_src/math/polynomial.hpp.html
title: cpp_src/math/polynomial.hpp
---
