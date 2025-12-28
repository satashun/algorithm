---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/contest/2180/submission/354246719
    - https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a#%E5%BD%A2%E5%BC%8F%E7%9A%84%E3%81%B9%E3%81%8D%E7%B4%9A%E6%95%B0
  bundledCode: "#line 1 \"cpp_src/math/BostanMori.hpp\"\n// ref :\n// https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a#%E5%BD%A2%E5%BC%8F%E7%9A%84%E3%81%B9%E3%81%8D%E7%B4%9A%E6%95%B0\n\
    // a_i = \\sum_{j=1}^d c_j * a_{i-j}\n// input\n// a_0, a_1, a_2, ..., a_{d-1}\n\
    // c_1, c_2, c_3, ..., c_d\n// n\n// calculate a_n\n\n// CF global 31 F2 : https://codeforces.com/contest/2180/submission/354246719\n\
    \ntemplate <class T>\nPoly<T> find_linear_recurrence(const V<T>& s) {\n    auto\
    \ bm = berlekamp_massey(s);\n    bm.pop_back();\n    reverse(ALL(bm));\n    return\
    \ bm;\n}\n\ntemplate <class T>\nT bostan_mori(Poly<T> a, Poly<T> c, ll n) {\n\
    \    if (n < a.size()) return a[n];\n    using P = Poly<T>;\n\n    auto even =\
    \ [&](const P& a) {\n        int sz = SZ(a);\n        P b((sz + 1) / 2);\n   \
    \     for (int i = 0; i < SZ(a); i += 2) {\n            b[i / 2] = a[i];\n   \
    \     }\n        return b;\n    };\n    auto odd = [&](const P& a) {\n       \
    \ int sz = SZ(a);\n        P b(sz / 2);\n        for (int i = 1; i < SZ(a); i\
    \ += 2) {\n            b[i / 2] = a[i];\n        }\n        return b;\n    };\n\
    \    // a(x) -> a(-x)\n    auto neg = [&](const P& a) {\n        auto b = a;\n\
    \        for (int i = 1; i < SZ(b); i += 2) {\n            b[i] = -b[i];\n   \
    \     }\n        return b;\n    };\n\n    int d = SZ(c);\n    P q(d + 1);\n  \
    \  q[0] = 1;\n    rep(i, SZ(c)) q[i + 1] = -c[i];\n    P p = a * q;\n    p = p.pref(d);\n\
    \n    while (n > 0) {\n        auto u = p * neg(q);\n        if (n % 2 == 0) {\n\
    \            p = even(u);\n        } else {\n            p = odd(u);\n       \
    \ }\n        q = even(q * neg(q));\n        n /= 2;\n    }\n    return p[0] /\
    \ q[0];\n}\n\ntemplate <class T>\nT findKth(V<T> a, ll K) {\n    if (K < SZ(a))\
    \ return a[K];\n    auto c = find_linear_recurrence(a);\n\n    int d = SZ(c);\n\
    \    Poly<Mint> a_pl(d);\n    rep(i, d) { a_pl[i] = a[i]; }\n\n    return bostan_mori(a_pl,\
    \ c, K);\n}\n"
  code: "// ref :\n// https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a#%E5%BD%A2%E5%BC%8F%E7%9A%84%E3%81%B9%E3%81%8D%E7%B4%9A%E6%95%B0\n\
    // a_i = \\sum_{j=1}^d c_j * a_{i-j}\n// input\n// a_0, a_1, a_2, ..., a_{d-1}\n\
    // c_1, c_2, c_3, ..., c_d\n// n\n// calculate a_n\n\n// CF global 31 F2 : https://codeforces.com/contest/2180/submission/354246719\n\
    \ntemplate <class T>\nPoly<T> find_linear_recurrence(const V<T>& s) {\n    auto\
    \ bm = berlekamp_massey(s);\n    bm.pop_back();\n    reverse(ALL(bm));\n    return\
    \ bm;\n}\n\ntemplate <class T>\nT bostan_mori(Poly<T> a, Poly<T> c, ll n) {\n\
    \    if (n < a.size()) return a[n];\n    using P = Poly<T>;\n\n    auto even =\
    \ [&](const P& a) {\n        int sz = SZ(a);\n        P b((sz + 1) / 2);\n   \
    \     for (int i = 0; i < SZ(a); i += 2) {\n            b[i / 2] = a[i];\n   \
    \     }\n        return b;\n    };\n    auto odd = [&](const P& a) {\n       \
    \ int sz = SZ(a);\n        P b(sz / 2);\n        for (int i = 1; i < SZ(a); i\
    \ += 2) {\n            b[i / 2] = a[i];\n        }\n        return b;\n    };\n\
    \    // a(x) -> a(-x)\n    auto neg = [&](const P& a) {\n        auto b = a;\n\
    \        for (int i = 1; i < SZ(b); i += 2) {\n            b[i] = -b[i];\n   \
    \     }\n        return b;\n    };\n\n    int d = SZ(c);\n    P q(d + 1);\n  \
    \  q[0] = 1;\n    rep(i, SZ(c)) q[i + 1] = -c[i];\n    P p = a * q;\n    p = p.pref(d);\n\
    \n    while (n > 0) {\n        auto u = p * neg(q);\n        if (n % 2 == 0) {\n\
    \            p = even(u);\n        } else {\n            p = odd(u);\n       \
    \ }\n        q = even(q * neg(q));\n        n /= 2;\n    }\n    return p[0] /\
    \ q[0];\n}\n\ntemplate <class T>\nT findKth(V<T> a, ll K) {\n    if (K < SZ(a))\
    \ return a[K];\n    auto c = find_linear_recurrence(a);\n\n    int d = SZ(c);\n\
    \    Poly<Mint> a_pl(d);\n    rep(i, d) { a_pl[i] = a[i]; }\n\n    return bostan_mori(a_pl,\
    \ c, K);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/math/BostanMori.hpp
  requiredBy: []
  timestamp: '2025-12-28 17:44:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
documentation_of: cpp_src/math/BostanMori.hpp
layout: document
redirect_from:
- /library/cpp_src/math/BostanMori.hpp
- /library/cpp_src/math/BostanMori.hpp.html
title: cpp_src/math/BostanMori.hpp
---
