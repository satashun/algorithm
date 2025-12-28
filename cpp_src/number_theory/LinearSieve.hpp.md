---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/blog/entry/54090?mobile=true&locale=en
    - https://cp-algorithms.com/algebra/prime-sieve-linear.html
  bundledCode: "#line 1 \"cpp_src/number_theory/LinearSieve.hpp\"\n// https://cp-algorithms.com/algebra/prime-sieve-linear.html\n\
    // mimic ksun48 implementation\n// can calculate multiplicative functions, totient:\
    \ ARC185E\n// https://codeforces.com/blog/entry/54090?mobile=true&locale=en\n\n\
    const int X = 1e7;\n\nbitset<X> is_prime;\nvector<int> pr;\n\nint mu[X];   //\
    \ moebius\nint pf[X];   // pf[i] := smallest prime p s.t. p | i\nint phi[X]; \
    \ // Euler's totient\n\nvoid sieve() {\n    is_prime.flip();\n    is_prime[0]\
    \ = is_prime[1] = false;\n    mu[1] = 1;\n\n    for (int i = 2; i < X; i++) {\n\
    \        if (is_prime[i]) {\n            pr.push_back(i);\n            pf[i] =\
    \ i;\n            mu[i] = -1;\n            phi[i] = i - 1;\n        }\n\n    \
    \    for (int p : pr) {\n            if (ll(i) * p >= X) break;\n            is_prime[i\
    \ * p] = false;\n            mu[i * p] = -mu[i];\n            phi[i * p] = phi[i]\
    \ * p;\n            pf[i * p] = p;\n\n            if (i % p == 0) {\n        \
    \        mu[i * p] = 0;\n                phi[i * p] = phi[i] * (p - 1);\n    \
    \            break;\n            }\n        }\n    }\n}\n\nstruct PrimePrepare\
    \ {\n    PrimePrepare() { sieve(); }\n} prep_prime;\n\nvector<pii> factorize(int\
    \ x) {\n    vector<pii> vec;\n    while (pf[x] > 1) {\n        int d = pf[x];\n\
    \        int c = 0;\n        while (x % d == 0) {\n            x /= d;\n     \
    \       c++;\n        }\n        vec.emplace_back(d, c);\n    }\n    if (x !=\
    \ 1) {\n        vec.emplace_back(x, 1);\n    }\n    return vec;\n}\n"
  code: "// https://cp-algorithms.com/algebra/prime-sieve-linear.html\n// mimic ksun48\
    \ implementation\n// can calculate multiplicative functions, totient: ARC185E\n\
    // https://codeforces.com/blog/entry/54090?mobile=true&locale=en\n\nconst int\
    \ X = 1e7;\n\nbitset<X> is_prime;\nvector<int> pr;\n\nint mu[X];   // moebius\n\
    int pf[X];   // pf[i] := smallest prime p s.t. p | i\nint phi[X];  // Euler's\
    \ totient\n\nvoid sieve() {\n    is_prime.flip();\n    is_prime[0] = is_prime[1]\
    \ = false;\n    mu[1] = 1;\n\n    for (int i = 2; i < X; i++) {\n        if (is_prime[i])\
    \ {\n            pr.push_back(i);\n            pf[i] = i;\n            mu[i] =\
    \ -1;\n            phi[i] = i - 1;\n        }\n\n        for (int p : pr) {\n\
    \            if (ll(i) * p >= X) break;\n            is_prime[i * p] = false;\n\
    \            mu[i * p] = -mu[i];\n            phi[i * p] = phi[i] * p;\n     \
    \       pf[i * p] = p;\n\n            if (i % p == 0) {\n                mu[i\
    \ * p] = 0;\n                phi[i * p] = phi[i] * (p - 1);\n                break;\n\
    \            }\n        }\n    }\n}\n\nstruct PrimePrepare {\n    PrimePrepare()\
    \ { sieve(); }\n} prep_prime;\n\nvector<pii> factorize(int x) {\n    vector<pii>\
    \ vec;\n    while (pf[x] > 1) {\n        int d = pf[x];\n        int c = 0;\n\
    \        while (x % d == 0) {\n            x /= d;\n            c++;\n       \
    \ }\n        vec.emplace_back(d, c);\n    }\n    if (x != 1) {\n        vec.emplace_back(x,\
    \ 1);\n    }\n    return vec;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/number_theory/LinearSieve.hpp
  requiredBy: []
  timestamp: '2025-12-28 17:44:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/number_theory/LinearSieve.hpp
layout: document
redirect_from:
- /library/cpp_src/number_theory/LinearSieve.hpp
- /library/cpp_src/number_theory/LinearSieve.hpp.html
title: cpp_src/number_theory/LinearSieve.hpp
---
