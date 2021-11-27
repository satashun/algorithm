---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/number_theory/GaussGcd.cpp\"\nll near(ll x, ll d)\
    \ {\n    bool p = x >= 0;\n    x = abs(x);\n    ll t = x % d * 2 >= d ? x / d\
    \ + 1 : x / d;\n    if (!p) t = -t;\n    return t;\n}\n\npair<ll, ll> get(ll p,\
    \ ll q, ll r, ll s) {\n    if (r == 0 && s == 0) return mp(p, q);\n    ll g =\
    \ r * r + s * s;\n    ll np = near(p * r + q * s, g), nq = near(q * r - p * s,\
    \ g);\n    ll a = p - (np * r - nq * s), b = q - (nq * r + np * s);\n    return\
    \ get(r, s, a, b);\n};\n"
  code: "ll near(ll x, ll d) {\n    bool p = x >= 0;\n    x = abs(x);\n    ll t =\
    \ x % d * 2 >= d ? x / d + 1 : x / d;\n    if (!p) t = -t;\n    return t;\n}\n\
    \npair<ll, ll> get(ll p, ll q, ll r, ll s) {\n    if (r == 0 && s == 0) return\
    \ mp(p, q);\n    ll g = r * r + s * s;\n    ll np = near(p * r + q * s, g), nq\
    \ = near(q * r - p * s, g);\n    ll a = p - (np * r - nq * s), b = q - (nq * r\
    \ + np * s);\n    return get(r, s, a, b);\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/number_theory/GaussGcd.cpp
  requiredBy: []
  timestamp: '2021-11-27 23:06:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/number_theory/GaussGcd.cpp
layout: document
redirect_from:
- /library/cpp_src/number_theory/GaussGcd.cpp
- /library/cpp_src/number_theory/GaussGcd.cpp.html
title: cpp_src/number_theory/GaussGcd.cpp
---
