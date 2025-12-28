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
  bundledCode: "#line 1 \"cpp_src/utility/Helper.hpp\"\ntemplate <class T>\nvoid make_unique(vector<T>&\
    \ v) {\n    sort(v.begin(), v.end());\n    v.erase(unique(v.begin(), v.end()),\
    \ v.end());\n}\n\ntemplate <class T>\nT pow(T x, ll k) {\n    T res(1);\n    while\
    \ (k) {\n        if (k & 1) {\n            res = res * x;\n        }\n       \
    \ k >>= 1;\n        x = x * x;\n    }\n    return res;\n}\n\n// x^k mod m\n//\
    \ m*m must not overflow!!\ntemplate <class T>\nT powmod(T x, ll k, T m) {\n  \
    \  T res(1);\n    while (k) {\n        if (k & 1) {\n            res = res * x\
    \ % m;\n        }\n        k >>= 1;\n        x = x * x % m;\n    }\n    return\
    \ res;\n}\n\ntemplate <class T>\nV<int> compress(const V<T>& vec) {\n    int n\
    \ = SZ(vec);\n    auto xs = vec;\n    mkuni(xs);\n    V<int> res(n);\n    rep(i,\
    \ n) { res[i] = lower_bound(ALL(xs), vec[i]) - xs.begin(); }\n    return res;\n\
    }\n\n// ABC396F\ntemplate <class T>\nll inversion(const V<T>& vec) {\n    int\
    \ n = vec.size();\n    BIT<int> bit(*max_element(ALL(vec)) + 1);\n    ll res =\
    \ 0;\n    rep(i, n) {\n        res += i - bit.sum(vec[i] + 1);\n        bit.add(vec[i],\
    \ 1);\n    }\n    return res;\n}\n\n// binary search\n// ARC189C\n// strict\n\
    template <class T>\nint longest_increasing_subsequence(const V<T>& vec) {\n  \
    \  int sz = SZ(vec);\n    if (sz == 0) return 0;\n    T INF = *max_element(ALL(vec))\
    \ + 1;\n    V<T> dp(sz + 1, INF);\n    dp[0] = -INF;\n\n    for (auto v : vec)\
    \ {\n        auto it = lower_bound(ALL(dp), v);\n        *it = v;\n    }\n\n \
    \   return arglb(dp, INF) - 1;\n}\n"
  code: "template <class T>\nvoid make_unique(vector<T>& v) {\n    sort(v.begin(),\
    \ v.end());\n    v.erase(unique(v.begin(), v.end()), v.end());\n}\n\ntemplate\
    \ <class T>\nT pow(T x, ll k) {\n    T res(1);\n    while (k) {\n        if (k\
    \ & 1) {\n            res = res * x;\n        }\n        k >>= 1;\n        x =\
    \ x * x;\n    }\n    return res;\n}\n\n// x^k mod m\n// m*m must not overflow!!\n\
    template <class T>\nT powmod(T x, ll k, T m) {\n    T res(1);\n    while (k) {\n\
    \        if (k & 1) {\n            res = res * x % m;\n        }\n        k >>=\
    \ 1;\n        x = x * x % m;\n    }\n    return res;\n}\n\ntemplate <class T>\n\
    V<int> compress(const V<T>& vec) {\n    int n = SZ(vec);\n    auto xs = vec;\n\
    \    mkuni(xs);\n    V<int> res(n);\n    rep(i, n) { res[i] = lower_bound(ALL(xs),\
    \ vec[i]) - xs.begin(); }\n    return res;\n}\n\n// ABC396F\ntemplate <class T>\n\
    ll inversion(const V<T>& vec) {\n    int n = vec.size();\n    BIT<int> bit(*max_element(ALL(vec))\
    \ + 1);\n    ll res = 0;\n    rep(i, n) {\n        res += i - bit.sum(vec[i] +\
    \ 1);\n        bit.add(vec[i], 1);\n    }\n    return res;\n}\n\n// binary search\n\
    // ARC189C\n// strict\ntemplate <class T>\nint longest_increasing_subsequence(const\
    \ V<T>& vec) {\n    int sz = SZ(vec);\n    if (sz == 0) return 0;\n    T INF =\
    \ *max_element(ALL(vec)) + 1;\n    V<T> dp(sz + 1, INF);\n    dp[0] = -INF;\n\n\
    \    for (auto v : vec) {\n        auto it = lower_bound(ALL(dp), v);\n      \
    \  *it = v;\n    }\n\n    return arglb(dp, INF) - 1;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/utility/Helper.hpp
  requiredBy: []
  timestamp: '2025-12-28 17:44:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/utility/Helper.hpp
layout: document
redirect_from:
- /library/cpp_src/utility/Helper.hpp
- /library/cpp_src/utility/Helper.hpp.html
title: cpp_src/utility/Helper.hpp
---
