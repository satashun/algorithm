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
  bundledCode: "#line 1 \"cpp_src/math/ModularOperation.hpp\"\nconst int maxv = 1000010;\n\
    \nV<Mint> fact(maxv), ifact(maxv), inv(maxv);\n\nvoid init() {\n    fact[0] =\
    \ 1;\n    for (int i = 1; i < maxv; ++i) {\n        fact[i] = fact[i - 1] * i;\n\
    \    }\n\n    ifact[maxv - 1] = fact[maxv - 1].inv();\n\n    for (int i = maxv\
    \ - 2; i >= 0; --i) {\n        ifact[i] = ifact[i + 1] * (i + 1);\n    }\n\n \
    \   for (int i = 1; i < maxv; ++i) {\n        inv[i] = ifact[i] * fact[i - 1];\n\
    \    }\n}\n\nMint comb(int n, int r) {\n    if (n < 0 || r < 0 || r > n) return\
    \ Mint(0);\n    return fact[n] * ifact[r] * ifact[n - r];\n}\n\n// O(k)\n\nMint\
    \ comb_slow(ll n, ll k) {\n    Mint res = 1;\n    for (int i = 0; i < k; ++i)\
    \ {\n        res = res * (n - i) * inv[i + 1];\n    }\n    return res;\n}\n\n\
    // line up\n// a 'o' + b 'x'\nMint comb2(int a, int b) {\n    if (a < 0 || b <\
    \ 0) return 0;\n    return comb(a + b, a);\n}\n\n// O(p + log_p n)\n\nMint lucas(ll\
    \ n, ll k, int p) {\n    if (n < 0 || k < 0 || k > n) return Mint(0);\n    Mint\
    \ res = 1;\n    while (n > 0) {\n        res *= comb(n % p, k % p);\n        n\
    \ /= p;\n        k /= p;\n    }\n    return res;\n}\n"
  code: "const int maxv = 1000010;\n\nV<Mint> fact(maxv), ifact(maxv), inv(maxv);\n\
    \nvoid init() {\n    fact[0] = 1;\n    for (int i = 1; i < maxv; ++i) {\n    \
    \    fact[i] = fact[i - 1] * i;\n    }\n\n    ifact[maxv - 1] = fact[maxv - 1].inv();\n\
    \n    for (int i = maxv - 2; i >= 0; --i) {\n        ifact[i] = ifact[i + 1] *\
    \ (i + 1);\n    }\n\n    for (int i = 1; i < maxv; ++i) {\n        inv[i] = ifact[i]\
    \ * fact[i - 1];\n    }\n}\n\nMint comb(int n, int r) {\n    if (n < 0 || r <\
    \ 0 || r > n) return Mint(0);\n    return fact[n] * ifact[r] * ifact[n - r];\n\
    }\n\n// O(k)\n\nMint comb_slow(ll n, ll k) {\n    Mint res = 1;\n    for (int\
    \ i = 0; i < k; ++i) {\n        res = res * (n - i) * inv[i + 1];\n    }\n   \
    \ return res;\n}\n\n// line up\n// a 'o' + b 'x'\nMint comb2(int a, int b) {\n\
    \    if (a < 0 || b < 0) return 0;\n    return comb(a + b, a);\n}\n\n// O(p +\
    \ log_p n)\n\nMint lucas(ll n, ll k, int p) {\n    if (n < 0 || k < 0 || k > n)\
    \ return Mint(0);\n    Mint res = 1;\n    while (n > 0) {\n        res *= comb(n\
    \ % p, k % p);\n        n /= p;\n        k /= p;\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/math/ModularOperation.hpp
  requiredBy: []
  timestamp: '2021-04-19 01:11:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/math/ModularOperation.hpp
layout: document
redirect_from:
- /library/cpp_src/math/ModularOperation.hpp
- /library/cpp_src/math/ModularOperation.hpp.html
title: cpp_src/math/ModularOperation.hpp
---