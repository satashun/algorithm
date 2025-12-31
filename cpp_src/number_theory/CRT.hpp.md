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
  bundledCode: "#line 1 \"cpp_src/number_theory/CRT.hpp\"\n/// g:gcd(a, b), ax+by=g\n\
    struct EG {\n    ll g, x, y;\n};\n\nEG ext_gcd(ll a, ll b) {\n    if (b == 0)\
    \ {\n        if (a >= 0)\n            return EG{a, 1, 0};\n        else\n    \
    \        return EG{-a, -1, 0};\n    } else {\n        auto e = ext_gcd(b, a %\
    \ b);\n        return EG{e.g, e.y, e.x - a / b * e.y};\n    }\n}\n\n// ABC315G\n\
    // ax + by = c\n// returs (x0, y0, gcd(a,b))\n// x0, y0 <= max(a,b)^2,|c|\n//\
    \ x = x0 + b't, y = y0 - a't\ntuple<ll, ll, ll> solve_eq(ll a, ll b, ll c) {\n\
    \    auto res = ext_gcd(a, b);\n    ll x = res.x, y = res.y, g = res.g;\n    if\
    \ (c % g) {\n        return make_tuple(-1, -1, -1);\n    }\n    x *= (c % b) /\
    \ g;\n    y *= (c % b) / g;\n    y += c / b;\n    return make_tuple(x, y, g);\n\
    }\n\nll inv_mod(ll x, ll md) {\n    auto z = ext_gcd(x, md).x;\n    return (z\
    \ % md + md) % md;\n}\n\n// ** 271\n// find x s.t. x = b_i mod c_i\npair<ll, ll>\
    \ crt(const V<ll>& b, const V<ll>& c) {\n    int n = int(b.size());\n    ll r\
    \ = 0, m = 1;\n    for (int i = 0; i < n; i++) {\n        auto eg = ext_gcd(m,\
    \ c[i]);\n        ll g = eg.g, im = eg.x;\n        if ((b[i] - r) % g) return\
    \ {0, -1};\n        ll tmp = (b[i] - r) / g * im % (c[i] / g);\n        r += m\
    \ * tmp;\n        m *= c[i] / g;\n    }\n    return {(r % m + m) % m, m};\n}\n"
  code: "/// g:gcd(a, b), ax+by=g\nstruct EG {\n    ll g, x, y;\n};\n\nEG ext_gcd(ll\
    \ a, ll b) {\n    if (b == 0) {\n        if (a >= 0)\n            return EG{a,\
    \ 1, 0};\n        else\n            return EG{-a, -1, 0};\n    } else {\n    \
    \    auto e = ext_gcd(b, a % b);\n        return EG{e.g, e.y, e.x - a / b * e.y};\n\
    \    }\n}\n\n// ABC315G\n// ax + by = c\n// returs (x0, y0, gcd(a,b))\n// x0,\
    \ y0 <= max(a,b)^2,|c|\n// x = x0 + b't, y = y0 - a't\ntuple<ll, ll, ll> solve_eq(ll\
    \ a, ll b, ll c) {\n    auto res = ext_gcd(a, b);\n    ll x = res.x, y = res.y,\
    \ g = res.g;\n    if (c % g) {\n        return make_tuple(-1, -1, -1);\n    }\n\
    \    x *= (c % b) / g;\n    y *= (c % b) / g;\n    y += c / b;\n    return make_tuple(x,\
    \ y, g);\n}\n\nll inv_mod(ll x, ll md) {\n    auto z = ext_gcd(x, md).x;\n   \
    \ return (z % md + md) % md;\n}\n\n// ** 271\n// find x s.t. x = b_i mod c_i\n\
    pair<ll, ll> crt(const V<ll>& b, const V<ll>& c) {\n    int n = int(b.size());\n\
    \    ll r = 0, m = 1;\n    for (int i = 0; i < n; i++) {\n        auto eg = ext_gcd(m,\
    \ c[i]);\n        ll g = eg.g, im = eg.x;\n        if ((b[i] - r) % g) return\
    \ {0, -1};\n        ll tmp = (b[i] - r) / g * im % (c[i] / g);\n        r += m\
    \ * tmp;\n        m *= c[i] / g;\n    }\n    return {(r % m + m) % m, m};\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/number_theory/CRT.hpp
  requiredBy: []
  timestamp: '2026-01-01 00:55:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/number_theory/CRT.hpp
layout: document
redirect_from:
- /library/cpp_src/number_theory/CRT.hpp
- /library/cpp_src/number_theory/CRT.hpp.html
title: cpp_src/number_theory/CRT.hpp
---
