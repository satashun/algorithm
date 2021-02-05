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
    \ 1;\n    for (int i = 1; i < maxv; ++i) {\n        fact[i] = fact[i-1] * i;\n\
    \    }\n\n    ifact[maxv-1] = fact[maxv-1].inv();\n\n    for (int i = maxv - 2;\
    \ i >= 0; --i) {\n        ifact[i] = ifact[i+1] * (i+1);\n    }\n\n    for (int\
    \ i = 1; i < maxv; ++i) {\n        inv[i] = ifact[i] * fact[i-1];\n    }\n}\n\n\
    Mint comb(int n, int r) {\n    if (n < 0 || r < 0 || r > n) return Mint(0);\n\
    \    return fact[n] * ifact[r] * ifact[n-r];\n}\n"
  code: "const int maxv = 1000010;\n\nV<Mint> fact(maxv), ifact(maxv), inv(maxv);\n\
    \nvoid init() {\n    fact[0] = 1;\n    for (int i = 1; i < maxv; ++i) {\n    \
    \    fact[i] = fact[i-1] * i;\n    }\n\n    ifact[maxv-1] = fact[maxv-1].inv();\n\
    \n    for (int i = maxv - 2; i >= 0; --i) {\n        ifact[i] = ifact[i+1] * (i+1);\n\
    \    }\n\n    for (int i = 1; i < maxv; ++i) {\n        inv[i] = ifact[i] * fact[i-1];\n\
    \    }\n}\n\nMint comb(int n, int r) {\n    if (n < 0 || r < 0 || r > n) return\
    \ Mint(0);\n    return fact[n] * ifact[r] * ifact[n-r];\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/math/ModularOperation.hpp
  requiredBy: []
  timestamp: '2020-09-17 22:13:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/math/ModularOperation.hpp
layout: document
redirect_from:
- /library/cpp_src/math/ModularOperation.hpp
- /library/cpp_src/math/ModularOperation.hpp.html
title: cpp_src/math/ModularOperation.hpp
---
