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
  bundledCode: "#line 1 \"cpp_src/number_theory/Factorize.hpp\"\nusing R = __int128;\n\
    \nll pollrard_single(ll n) {\n    auto f = [&](ll x) { return ((R)x * x + 1) %\
    \ n; };\n    if (miller_rabin_big(n)) return n;\n    if (n % 2 == 0) return 2;\n\
    \    ll st = 0;\n    while (true) {\n        st++;\n\n        ll x = st, y = f(x);\n\
    \        while (true) {\n            ll p = gcd((y - x + n), n);\n           \
    \ if (p == 0 || p == n) break;\n            if (p != 1) return p;\n          \
    \  x = f(x);\n            y = f(f(y));\n        }\n    }\n}\n\nV<ll> pollrard(ll\
    \ n) {\n    if (n == 1) return {};\n    ll x = pollrard_single(n);\n    if (x\
    \ == n) return {x};\n    V<ll> v1 = pollrard(x), v2 = pollrard(n / x);\n    v1.insert(v1.end(),\
    \ ALL(v2));\n    return v1;\n}\n"
  code: "using R = __int128;\n\nll pollrard_single(ll n) {\n    auto f = [&](ll x)\
    \ { return ((R)x * x + 1) % n; };\n    if (miller_rabin_big(n)) return n;\n  \
    \  if (n % 2 == 0) return 2;\n    ll st = 0;\n    while (true) {\n        st++;\n\
    \n        ll x = st, y = f(x);\n        while (true) {\n            ll p = gcd((y\
    \ - x + n), n);\n            if (p == 0 || p == n) break;\n            if (p !=\
    \ 1) return p;\n            x = f(x);\n            y = f(f(y));\n        }\n \
    \   }\n}\n\nV<ll> pollrard(ll n) {\n    if (n == 1) return {};\n    ll x = pollrard_single(n);\n\
    \    if (x == n) return {x};\n    V<ll> v1 = pollrard(x), v2 = pollrard(n / x);\n\
    \    v1.insert(v1.end(), ALL(v2));\n    return v1;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/number_theory/Factorize.hpp
  requiredBy: []
  timestamp: '2022-03-17 11:21:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/number_theory/Factorize.hpp
layout: document
redirect_from:
- /library/cpp_src/number_theory/Factorize.hpp
- /library/cpp_src/number_theory/Factorize.hpp.html
title: cpp_src/number_theory/Factorize.hpp
---
