---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1297.test.cpp
    title: test/yukicoder/1297.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/kth-competitive-programming/kactl/blob/master/content/data-structures/LineContainer.h
  bundledCode: "#line 1 \"cpp_src/other/LineContainer.hpp\"\n// modified\n// https://github.com/kth-competitive-programming/kactl/blob/master/content/data-structures/LineContainer.h\n\
    // lines : y = kx + m\n// find maximum at x\n\nstruct Line {\n    mutable ll k,\
    \ m, p;\n    bool operator<(const Line& o) const { return k < o.k; }\n    bool\
    \ operator<(ll x) const { return p < x; }\n};\n\ntemplate <bool maximum>\nstruct\
    \ LineContainer : multiset<Line, less<>> {\n    // (for doubles, use inf = 1/.0,\
    \ div(a,b) = a/b)\n    static const ll inf = LLONG_MAX;\n    ll div(ll a, ll b)\
    \ {  // floored division\n        return a / b - ((a ^ b) < 0 && a % b);\n   \
    \ }\n    bool isect(iterator x, iterator y) {\n        if (y == end()) return\
    \ x->p = inf, 0;\n        if (x->k == y->k)\n            x->p = x->m > y->m ?\
    \ inf : -inf;\n        else\n            x->p = div(y->m - x->m, x->k - y->k);\n\
    \        return x->p >= y->p;\n    }\n    void add(ll k, ll m) {\n        if (!maximum)\
    \ k = -k, m = -m;\n        auto z = insert({k, m, 0}), y = z++, x = y;\n     \
    \   while (isect(y, z)) z = erase(z);\n        if (x != begin() && isect(--x,\
    \ y)) isect(x, y = erase(y));\n        while ((y = x) != begin() && (--x)->p >=\
    \ y->p) isect(x, erase(y));\n    }\n    ll query(ll x) {\n        assert(!empty());\n\
    \        auto l = *lower_bound(x);\n        auto res = l.k * x + l.m;\n      \
    \  if (!maximum) res = -res;\n        return res;\n    }\n};\n"
  code: "// modified\n// https://github.com/kth-competitive-programming/kactl/blob/master/content/data-structures/LineContainer.h\n\
    // lines : y = kx + m\n// find maximum at x\n\nstruct Line {\n    mutable ll k,\
    \ m, p;\n    bool operator<(const Line& o) const { return k < o.k; }\n    bool\
    \ operator<(ll x) const { return p < x; }\n};\n\ntemplate <bool maximum>\nstruct\
    \ LineContainer : multiset<Line, less<>> {\n    // (for doubles, use inf = 1/.0,\
    \ div(a,b) = a/b)\n    static const ll inf = LLONG_MAX;\n    ll div(ll a, ll b)\
    \ {  // floored division\n        return a / b - ((a ^ b) < 0 && a % b);\n   \
    \ }\n    bool isect(iterator x, iterator y) {\n        if (y == end()) return\
    \ x->p = inf, 0;\n        if (x->k == y->k)\n            x->p = x->m > y->m ?\
    \ inf : -inf;\n        else\n            x->p = div(y->m - x->m, x->k - y->k);\n\
    \        return x->p >= y->p;\n    }\n    void add(ll k, ll m) {\n        if (!maximum)\
    \ k = -k, m = -m;\n        auto z = insert({k, m, 0}), y = z++, x = y;\n     \
    \   while (isect(y, z)) z = erase(z);\n        if (x != begin() && isect(--x,\
    \ y)) isect(x, y = erase(y));\n        while ((y = x) != begin() && (--x)->p >=\
    \ y->p) isect(x, erase(y));\n    }\n    ll query(ll x) {\n        assert(!empty());\n\
    \        auto l = *lower_bound(x);\n        auto res = l.k * x + l.m;\n      \
    \  if (!maximum) res = -res;\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/other/LineContainer.hpp
  requiredBy: []
  timestamp: '2021-01-07 18:27:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1297.test.cpp
documentation_of: cpp_src/other/LineContainer.hpp
layout: document
redirect_from:
- /library/cpp_src/other/LineContainer.hpp
- /library/cpp_src/other/LineContainer.hpp.html
title: cpp_src/other/LineContainer.hpp
---
