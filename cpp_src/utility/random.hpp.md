---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"cpp_src/utility/random.hpp\"\nll rand_int(ll l, ll r) {\
    \  //[l,r]\n    static random_device rd;\n    static mt19937 gen(rd());\n    //\
    \ static mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    return uniform_int_distribution<ll>(l, r)(gen);\n}\n\n// Fisher\u2013Yates\n\
    template <class T>\nvector<T> random_perm(vector<T> vec) {\n    vector<T> res;\n\
    \    rep(i, vec.size()) {\n        res.pb(vec[i]);\n        int j = rand_int(0,\
    \ i);\n        swap(res[j], res[i]);\n    }\n    return res;\n}\n"
  code: "ll rand_int(ll l, ll r) {  //[l,r]\n    static random_device rd;\n    static\
    \ mt19937 gen(rd());\n    // static mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    return uniform_int_distribution<ll>(l, r)(gen);\n}\n\n// Fisher\u2013Yates\n\
    template <class T>\nvector<T> random_perm(vector<T> vec) {\n    vector<T> res;\n\
    \    rep(i, vec.size()) {\n        res.pb(vec[i]);\n        int j = rand_int(0,\
    \ i);\n        swap(res[j], res[i]);\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/utility/random.hpp
  requiredBy: []
  timestamp: '2020-08-06 01:21:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/utility/random.hpp
layout: document
redirect_from:
- /library/cpp_src/utility/random.hpp
- /library/cpp_src/utility/random.hpp.html
title: cpp_src/utility/random.hpp
---
