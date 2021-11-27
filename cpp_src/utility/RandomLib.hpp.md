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
  bundledCode: "#line 1 \"cpp_src/utility/RandomLib.hpp\"\nll rand_int(ll l, ll r)\
    \ {  //[l,r]\n    static mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    return uniform_int_distribution<ll>(l, r)(gen);\n}\n\ndouble rand_norm(double\
    \ mean = 0.0, double sd = 1.0) {\n    static mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    return normal_distribution<>(mean, sd)(gen);\n}\n\n// x/y\nbool rand_prob(ll\
    \ x, ll y) { return rand_int(1, y) <= x; }\n\n// Fisher\u2013Yates\ntemplate <class\
    \ T>\nvector<T> random_perm(vector<T> vec) {\n    vector<T> res;\n    rep(i, vec.size())\
    \ {\n        res.pb(vec[i]);\n        int j = rand_int(0, i);\n        swap(res[j],\
    \ res[i]);\n    }\n    return res;\n}\n"
  code: "ll rand_int(ll l, ll r) {  //[l,r]\n    static mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    return uniform_int_distribution<ll>(l, r)(gen);\n}\n\ndouble rand_norm(double\
    \ mean = 0.0, double sd = 1.0) {\n    static mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    return normal_distribution<>(mean, sd)(gen);\n}\n\n// x/y\nbool rand_prob(ll\
    \ x, ll y) { return rand_int(1, y) <= x; }\n\n// Fisher\u2013Yates\ntemplate <class\
    \ T>\nvector<T> random_perm(vector<T> vec) {\n    vector<T> res;\n    rep(i, vec.size())\
    \ {\n        res.pb(vec[i]);\n        int j = rand_int(0, i);\n        swap(res[j],\
    \ res[i]);\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/utility/RandomLib.hpp
  requiredBy: []
  timestamp: '2021-11-27 23:06:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/utility/RandomLib.hpp
layout: document
redirect_from:
- /library/cpp_src/utility/RandomLib.hpp
- /library/cpp_src/utility/RandomLib.hpp.html
title: cpp_src/utility/RandomLib.hpp
---
