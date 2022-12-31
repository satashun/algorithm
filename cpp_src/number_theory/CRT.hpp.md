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
    struct EG { ll g, x, y; };\n\nEG ext_gcd(ll a, ll b) {\n\tif (b == 0) {\n\t\t\
    if (a >= 0) return EG{a, 1, 0};\n\t\telse return EG{-a, -1, 0};\n\t} else {\n\t\
    \tauto e = ext_gcd(b, a % b);\n\t\treturn EG{e.g, e.y, e.x - a / b * e.y};\n\t\
    }\n}\n\nll inv_mod(ll x, ll md) {\n\tauto z = ext_gcd(x, md).x;\n\treturn (z %\
    \ md + md) % md;\n}\n\n// ** 271\n// find x s.t. x = b_i mod c_i\npair<ll, ll>\
    \ crt(const V<ll>& b, const V<ll>& c) {\n\tint n = int(b.size());\n\tll r = 0,\
    \ m = 1;\n\tfor (int i = 0; i < n; i++) {\n\t\tauto eg = ext_gcd(m, c[i]);\n\t\
    \tll g = eg.g, im = eg.x;\n\t\tif ((b[i] - r) % g) return {0, -1};\n\t\tll tmp\
    \ = (b[i] - r) / g * im % (c[i] / g);\n\t\tr += m * tmp;\n\t\tm *= c[i] / g;\n\
    \t}\n\treturn {(r % m + m) % m, m};\n}\n"
  code: "/// g:gcd(a, b), ax+by=g\nstruct EG { ll g, x, y; };\n\nEG ext_gcd(ll a,\
    \ ll b) {\n\tif (b == 0) {\n\t\tif (a >= 0) return EG{a, 1, 0};\n\t\telse return\
    \ EG{-a, -1, 0};\n\t} else {\n\t\tauto e = ext_gcd(b, a % b);\n\t\treturn EG{e.g,\
    \ e.y, e.x - a / b * e.y};\n\t}\n}\n\nll inv_mod(ll x, ll md) {\n\tauto z = ext_gcd(x,\
    \ md).x;\n\treturn (z % md + md) % md;\n}\n\n// ** 271\n// find x s.t. x = b_i\
    \ mod c_i\npair<ll, ll> crt(const V<ll>& b, const V<ll>& c) {\n\tint n = int(b.size());\n\
    \tll r = 0, m = 1;\n\tfor (int i = 0; i < n; i++) {\n\t\tauto eg = ext_gcd(m,\
    \ c[i]);\n\t\tll g = eg.g, im = eg.x;\n\t\tif ((b[i] - r) % g) return {0, -1};\n\
    \t\tll tmp = (b[i] - r) / g * im % (c[i] / g);\n\t\tr += m * tmp;\n\t\tm *= c[i]\
    \ / g;\n\t}\n\treturn {(r % m + m) % m, m};\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/number_theory/CRT.hpp
  requiredBy: []
  timestamp: '2022-12-31 14:31:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/number_theory/CRT.hpp
layout: document
redirect_from:
- /library/cpp_src/number_theory/CRT.hpp
- /library/cpp_src/number_theory/CRT.hpp.html
title: cpp_src/number_theory/CRT.hpp
---
