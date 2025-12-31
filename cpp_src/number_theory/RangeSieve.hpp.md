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
  bundledCode: "#line 1 \"cpp_src/number_theory/RangeSieve.hpp\"\n// ABC412E\n// returns:\
    \ {prime < N}\nV<int> enumerate_prime(int N) {\n    V<int> is_prime(N, 1);\n \
    \   V<int> primes;\n    if (N < 2) return primes;\n    is_prime[0] = is_prime[1]\
    \ = false;\n    for (int i = 2; i * i < N; ++i) {\n        if (is_prime[i]) {\n\
    \            for (int j = i * i; j < N; j += i) is_prime[j] = false;\n       \
    \ }\n    }\n    for (int i = 2; i < N; ++i) {\n        if (is_prime[i]) primes.push_back(i);\n\
    \    }\n    return primes;\n}\n\n// [L,R)\n// 1. enumerate primes < max(sqrt(R),\
    \ R-L)\n// 2. check range\n// res[x] = some prime p, p | x or 0\nV<int> sieve(ll\
    \ L, ll R) {\n    ll n = max<ll>(sqrt(R), R - L) + 1;\n    V<int> res(R - L, 0);\n\
    \    auto vp = enumerate_prime(n);\n\n    for (auto p : vp) {\n        for (ll\
    \ j = max<ll>(p, (L + p - 1) / p) * p; j < R; j += p) {\n            res[j - L]\
    \ = p;\n        }\n    }\n    return res;\n}\n"
  code: "// ABC412E\n// returns: {prime < N}\nV<int> enumerate_prime(int N) {\n  \
    \  V<int> is_prime(N, 1);\n    V<int> primes;\n    if (N < 2) return primes;\n\
    \    is_prime[0] = is_prime[1] = false;\n    for (int i = 2; i * i < N; ++i) {\n\
    \        if (is_prime[i]) {\n            for (int j = i * i; j < N; j += i) is_prime[j]\
    \ = false;\n        }\n    }\n    for (int i = 2; i < N; ++i) {\n        if (is_prime[i])\
    \ primes.push_back(i);\n    }\n    return primes;\n}\n\n// [L,R)\n// 1. enumerate\
    \ primes < max(sqrt(R), R-L)\n// 2. check range\n// res[x] = some prime p, p |\
    \ x or 0\nV<int> sieve(ll L, ll R) {\n    ll n = max<ll>(sqrt(R), R - L) + 1;\n\
    \    V<int> res(R - L, 0);\n    auto vp = enumerate_prime(n);\n\n    for (auto\
    \ p : vp) {\n        for (ll j = max<ll>(p, (L + p - 1) / p) * p; j < R; j +=\
    \ p) {\n            res[j - L] = p;\n        }\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/number_theory/RangeSieve.hpp
  requiredBy: []
  timestamp: '2026-01-01 00:55:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/number_theory/RangeSieve.hpp
layout: document
redirect_from:
- /library/cpp_src/number_theory/RangeSieve.hpp
- /library/cpp_src/number_theory/RangeSieve.hpp.html
title: cpp_src/number_theory/RangeSieve.hpp
---
