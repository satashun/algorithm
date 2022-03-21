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
  bundledCode: "#line 1 \"cpp_src/math/ModularOperation.hpp\"\nV<Mint> fact, ifact,\
    \ inv;\nVV<Mint> small_comb;\n\nvoid mod_init() {\n    const int maxv = 1000010;\n\
    \    const int maxvv = 5000;\n\n    fact.resize(maxv);\n    ifact.resize(maxv);\n\
    \    inv.resize(maxv);\n\n    small_comb = make_vec<Mint>(maxvv, maxvv);\n\n \
    \   fact[0] = 1;\n    for (int i = 1; i < maxv; ++i) {\n        fact[i] = fact[i\
    \ - 1] * i;\n    }\n\n    ifact[maxv - 1] = fact[maxv - 1].inv();\n\n    for (int\
    \ i = maxv - 2; i >= 0; --i) {\n        ifact[i] = ifact[i + 1] * (i + 1);\n \
    \   }\n\n    for (int i = 1; i < maxv; ++i) {\n        inv[i] = ifact[i] * fact[i\
    \ - 1];\n    }\n\n    for (int i = 0; i < maxvv; ++i) {\n        small_comb[i][0]\
    \ = small_comb[i][i] = 1;\n        for (int j = 1; j < i; ++j) {\n           \
    \ small_comb[i][j] = small_comb[i - 1][j] + small_comb[i - 1][j - 1];\n      \
    \  }\n    }\n}\n\nMint comb(int n, int r) {\n    if (n < 0 || r < 0 || r > n)\
    \ return Mint(0);\n    if (n < small_comb.size()) return small_comb[n][r];\n \
    \   return fact[n] * ifact[r] * ifact[n - r];\n}\n\nMint inv_comb(int n, int r)\
    \ {\n    if (n < 0 || r < 0 || r > n) return Mint(0);\n    return ifact[n] * fact[r]\
    \ * fact[n - r];\n}\n\n// O(k)\nMint comb_slow(ll n, ll k) {\n    if (n < 0 ||\
    \ k < 0 || k > n) return Mint(0);\n    Mint res = ifact[k];\n    for (int i =\
    \ 0; i < k; ++i) {\n        res = res * (n - i);\n    }\n    return res;\n}\n\n\
    // line up\n// a 'o' + b 'x'\nMint comb2(int a, int b) {\n    if (a < 0 || b <\
    \ 0) return 0;\n    return comb(a + b, a);\n}\n\n// divide a into b groups\nMint\
    \ nhr(int a, int b) {\n    if (b == 0) return Mint(a == 0);\n    return comb(a\
    \ + b - 1, a);\n}\n\n// O(p + log_p n)\n\nMint lucas(ll n, ll k, int p) {\n  \
    \  if (n < 0 || k < 0 || k > n) return Mint(0);\n    Mint res = 1;\n    while\
    \ (n > 0) {\n        res *= comb(n % p, k % p);\n        n /= p;\n        k /=\
    \ p;\n    }\n    return res;\n}\n\nstruct ModPrepare {\n    ModPrepare() { mod_init();\
    \ }\n} prep_mod;\n"
  code: "V<Mint> fact, ifact, inv;\nVV<Mint> small_comb;\n\nvoid mod_init() {\n  \
    \  const int maxv = 1000010;\n    const int maxvv = 5000;\n\n    fact.resize(maxv);\n\
    \    ifact.resize(maxv);\n    inv.resize(maxv);\n\n    small_comb = make_vec<Mint>(maxvv,\
    \ maxvv);\n\n    fact[0] = 1;\n    for (int i = 1; i < maxv; ++i) {\n        fact[i]\
    \ = fact[i - 1] * i;\n    }\n\n    ifact[maxv - 1] = fact[maxv - 1].inv();\n\n\
    \    for (int i = maxv - 2; i >= 0; --i) {\n        ifact[i] = ifact[i + 1] *\
    \ (i + 1);\n    }\n\n    for (int i = 1; i < maxv; ++i) {\n        inv[i] = ifact[i]\
    \ * fact[i - 1];\n    }\n\n    for (int i = 0; i < maxvv; ++i) {\n        small_comb[i][0]\
    \ = small_comb[i][i] = 1;\n        for (int j = 1; j < i; ++j) {\n           \
    \ small_comb[i][j] = small_comb[i - 1][j] + small_comb[i - 1][j - 1];\n      \
    \  }\n    }\n}\n\nMint comb(int n, int r) {\n    if (n < 0 || r < 0 || r > n)\
    \ return Mint(0);\n    if (n < small_comb.size()) return small_comb[n][r];\n \
    \   return fact[n] * ifact[r] * ifact[n - r];\n}\n\nMint inv_comb(int n, int r)\
    \ {\n    if (n < 0 || r < 0 || r > n) return Mint(0);\n    return ifact[n] * fact[r]\
    \ * fact[n - r];\n}\n\n// O(k)\nMint comb_slow(ll n, ll k) {\n    if (n < 0 ||\
    \ k < 0 || k > n) return Mint(0);\n    Mint res = ifact[k];\n    for (int i =\
    \ 0; i < k; ++i) {\n        res = res * (n - i);\n    }\n    return res;\n}\n\n\
    // line up\n// a 'o' + b 'x'\nMint comb2(int a, int b) {\n    if (a < 0 || b <\
    \ 0) return 0;\n    return comb(a + b, a);\n}\n\n// divide a into b groups\nMint\
    \ nhr(int a, int b) {\n    if (b == 0) return Mint(a == 0);\n    return comb(a\
    \ + b - 1, a);\n}\n\n// O(p + log_p n)\n\nMint lucas(ll n, ll k, int p) {\n  \
    \  if (n < 0 || k < 0 || k > n) return Mint(0);\n    Mint res = 1;\n    while\
    \ (n > 0) {\n        res *= comb(n % p, k % p);\n        n /= p;\n        k /=\
    \ p;\n    }\n    return res;\n}\n\nstruct ModPrepare {\n    ModPrepare() { mod_init();\
    \ }\n} prep_mod;"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/math/ModularOperation.hpp
  requiredBy: []
  timestamp: '2022-03-21 17:35:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/math/ModularOperation.hpp
layout: document
redirect_from:
- /library/cpp_src/math/ModularOperation.hpp
- /library/cpp_src/math/ModularOperation.hpp.html
title: cpp_src/math/ModularOperation.hpp
---
