---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/Fiduccia.md
    links:
    - https://codeforces.com/contest/2180/submission/354246719
    - https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a#%E5%BD%A2%E5%BC%8F%E7%9A%84%E3%81%B9%E3%81%8D%E7%B4%9A%E6%95%B0
  bundledCode: "#line 1 \"cpp_src/math/Fiduccia.cpp\"\n/**\n * @docs docs/Fiduccia.md\n\
    \ */\n\n// ref :\n// https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a#%E5%BD%A2%E5%BC%8F%E7%9A%84%E3%81%B9%E3%81%8D%E7%B4%9A%E6%95%B0\n\
    // a_i = \\sum_{j=1}^d c_j * a_{i-j}\n// input\n// a_0, a_1, a_2, ..., a_{d-1}\n\
    // c_1, c_2, c_3, ..., c_d\n// n\n// calculate a_n\n// CF global 31 F2 : https://codeforces.com/contest/2180/submission/354246719\n\
    \ntemplate <class T>\nPoly<T> find_linear_recurrence(const V<T>& s) {\n    auto\
    \ bm = berlekamp_massey(s);\n    bm.pop_back();\n    reverse(ALL(bm));\n    return\
    \ bm;\n}\n\ntemplate <class T>\nT fiduccia(V<T> a, V<T> c, ll n) {\n    if (n\
    \ < a.size()) return a[n];\n    int k = SZ(c);\n    // char poly\n    V<T> vc(k\
    \ + 1);\n    rep(i, k) vc[k - 1 - i] = -c[i];\n    vc[k] = 1;\n\n    Poly<T> mono{0,\
    \ 1};\n    mono = mono.powmod(n, vc);\n\n    T ans = 0;\n    for (int i = 0; i\
    \ < k; ++i) {\n        ans += mono.at(i) * a[i];\n    }\n    return ans;\n}\n\n\
    template <class T>\nT findKth(V<T> a, ll K) {\n    if (K < SZ(a)) return a[K];\n\
    \    auto c = find_linear_recurrence(a);\n\n    return fiduccia(a, c, K);\n}\n"
  code: "/**\n * @docs docs/Fiduccia.md\n */\n\n// ref :\n// https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a#%E5%BD%A2%E5%BC%8F%E7%9A%84%E3%81%B9%E3%81%8D%E7%B4%9A%E6%95%B0\n\
    // a_i = \\sum_{j=1}^d c_j * a_{i-j}\n// input\n// a_0, a_1, a_2, ..., a_{d-1}\n\
    // c_1, c_2, c_3, ..., c_d\n// n\n// calculate a_n\n// CF global 31 F2 : https://codeforces.com/contest/2180/submission/354246719\n\
    \ntemplate <class T>\nPoly<T> find_linear_recurrence(const V<T>& s) {\n    auto\
    \ bm = berlekamp_massey(s);\n    bm.pop_back();\n    reverse(ALL(bm));\n    return\
    \ bm;\n}\n\ntemplate <class T>\nT fiduccia(V<T> a, V<T> c, ll n) {\n    if (n\
    \ < a.size()) return a[n];\n    int k = SZ(c);\n    // char poly\n    V<T> vc(k\
    \ + 1);\n    rep(i, k) vc[k - 1 - i] = -c[i];\n    vc[k] = 1;\n\n    Poly<T> mono{0,\
    \ 1};\n    mono = mono.powmod(n, vc);\n\n    T ans = 0;\n    for (int i = 0; i\
    \ < k; ++i) {\n        ans += mono.at(i) * a[i];\n    }\n    return ans;\n}\n\n\
    template <class T>\nT findKth(V<T> a, ll K) {\n    if (K < SZ(a)) return a[K];\n\
    \    auto c = find_linear_recurrence(a);\n\n    return fiduccia(a, c, K);\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/math/Fiduccia.cpp
  requiredBy: []
  timestamp: '2026-01-01 00:55:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/math/Fiduccia.cpp
layout: document
redirect_from:
- /library/cpp_src/math/Fiduccia.cpp
- /library/cpp_src/math/Fiduccia.cpp.html
title: cpp_src/math/Fiduccia.cpp
---
## 例題

- tdpc

- https://www.codechef.com/problems/RNG