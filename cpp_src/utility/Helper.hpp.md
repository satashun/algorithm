---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/static_range_sum.test.cpp
    title: test/yosupo/static_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/utility/Helper.hpp\"\ntemplate <class T>\nvoid make_unique(vector<T>&\
    \ v) {\n    sort(v.begin(), v.end());\n    v.erase(unique(v.begin(), v.end()),\
    \ v.end());\n}\n\ntemplate <class T>\nT pow(T x, ll k) {\n    T res(1);\n    while\
    \ (k) {\n        if (k & 1) {\n            res = res * x;\n        }\n       \
    \ k >>= 1;\n        x = x * x;\n    }\n    return res;\n}\n\n// x^k mod m\ntemplate\
    \ <class T>\nT powmod(T x, ll k, T m) {\n    T res(1);\n    while (k) {\n    \
    \    if (k & 1) {\n            res = res * x % m;\n        }\n        k >>= 1;\n\
    \        x = x * x % m;\n    }\n    return res;\n}\n\ntemplate <class T>\nV<T>\
    \ cumsum(const V<T>& vec) {\n    int n = vec.size();\n    V<T> res(n + 1);\n \
    \   rep(i, n) { res[i + 1] = res[i] + vec[i]; }\n    return res;\n}\n\ntemplate\
    \ <class T>\nV<int> compress(const V<T>& vec) {\n    int n = SZ(vec);\n    auto\
    \ xs = vec;\n    mkuni(xs);\n    V<int> res(n);\n    rep(i, n) { res[i] = lower_bound(ALL(xs),\
    \ vec[i]) - xs.begin(); }\n    return res;\n}\n\n// 0 <= vec[i] < n\ntemplate\
    \ <class T>\nll inversion(const V<T>& vec) {\n    int n = vec.size();\n    BIT<int>\
    \ bit(n + 10);\n    ll res = 0;\n    rep(i, n) {\n        res += i - bit.sum(vec[i]\
    \ + 1);\n        bit.add(vec[i], 1);\n    }\n    return res;\n}\n"
  code: "template <class T>\nvoid make_unique(vector<T>& v) {\n    sort(v.begin(),\
    \ v.end());\n    v.erase(unique(v.begin(), v.end()), v.end());\n}\n\ntemplate\
    \ <class T>\nT pow(T x, ll k) {\n    T res(1);\n    while (k) {\n        if (k\
    \ & 1) {\n            res = res * x;\n        }\n        k >>= 1;\n        x =\
    \ x * x;\n    }\n    return res;\n}\n\n// x^k mod m\ntemplate <class T>\nT powmod(T\
    \ x, ll k, T m) {\n    T res(1);\n    while (k) {\n        if (k & 1) {\n    \
    \        res = res * x % m;\n        }\n        k >>= 1;\n        x = x * x %\
    \ m;\n    }\n    return res;\n}\n\ntemplate <class T>\nV<T> cumsum(const V<T>&\
    \ vec) {\n    int n = vec.size();\n    V<T> res(n + 1);\n    rep(i, n) { res[i\
    \ + 1] = res[i] + vec[i]; }\n    return res;\n}\n\ntemplate <class T>\nV<int>\
    \ compress(const V<T>& vec) {\n    int n = SZ(vec);\n    auto xs = vec;\n    mkuni(xs);\n\
    \    V<int> res(n);\n    rep(i, n) { res[i] = lower_bound(ALL(xs), vec[i]) - xs.begin();\
    \ }\n    return res;\n}\n\n// 0 <= vec[i] < n\ntemplate <class T>\nll inversion(const\
    \ V<T>& vec) {\n    int n = vec.size();\n    BIT<int> bit(n + 10);\n    ll res\
    \ = 0;\n    rep(i, n) {\n        res += i - bit.sum(vec[i] + 1);\n        bit.add(vec[i],\
    \ 1);\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/utility/Helper.hpp
  requiredBy: []
  timestamp: '2022-08-15 00:42:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/static_range_sum.test.cpp
documentation_of: cpp_src/utility/Helper.hpp
layout: document
redirect_from:
- /library/cpp_src/utility/Helper.hpp
- /library/cpp_src/utility/Helper.hpp.html
title: cpp_src/utility/Helper.hpp
---
