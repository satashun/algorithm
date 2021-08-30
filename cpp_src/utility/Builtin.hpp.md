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
  bundledCode: '#line 1 "cpp_src/utility/Builtin.hpp"

    int topbit(int t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }

    int topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }

    int botbit(int a) { return a == 0 ? 32 : __builtin_ctz(a); }

    int botbit(ll a) { return a == 0 ? 64 : __builtin_ctzll(a); }

    int popcount(int t) { return __builtin_popcount(t); }

    int popcount(ll t) { return __builtin_popcountll(t); }

    int bit_parity(int t) { return __builtin_parity(t); }

    int bit_parity(ll t) { return __builtin_parityll(t); }

    '
  code: 'int topbit(int t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }

    int topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }

    int botbit(int a) { return a == 0 ? 32 : __builtin_ctz(a); }

    int botbit(ll a) { return a == 0 ? 64 : __builtin_ctzll(a); }

    int popcount(int t) { return __builtin_popcount(t); }

    int popcount(ll t) { return __builtin_popcountll(t); }

    int bit_parity(int t) { return __builtin_parity(t); }

    int bit_parity(ll t) { return __builtin_parityll(t); }'
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/utility/Builtin.hpp
  requiredBy: []
  timestamp: '2021-08-30 10:48:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/utility/Builtin.hpp
layout: document
redirect_from:
- /library/cpp_src/utility/Builtin.hpp
- /library/cpp_src/utility/Builtin.hpp.html
title: cpp_src/utility/Builtin.hpp
---
