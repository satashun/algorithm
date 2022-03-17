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
    - https://ei1333.hateblo.jp/entry/2017/09/11/211011
    - https://nyaannyaan.github.io/library/misc/mo.hpp
  bundledCode: "#line 1 \"cpp_src/other/Mo.hpp\"\n// O(NB + Q(N/B)) (B : numver of\
    \ blocks)\n// set B = sqrt(Q) -> O(N sqrt(Q) * F)\n// F : cost of operation\n\
    // ref : https://ei1333.hateblo.jp/entry/2017/09/11/211011\n// ref : https://nyaannyaan.github.io/library/misc/mo.hpp\n\
    \nstruct Mo {\n    V<int> left, right, order;\n    V<bool> v;\n    int n, Bsize,\
    \ nl, nr, ptr;\n\n    Mo(int n) : n(n), nl(0), nr(0), ptr(0), v(n) {}\n\n    //[l,\
    \ r)\n    void insert(int l, int r) {\n        left.push_back(l);\n        right.push_back(r);\n\
    \    }\n\n    void build() {\n        // Bsize = n / min<int>(n, sqrt(left.size()));\n\
    \        Bsize = max<int>(\n            1, 1.0 * n / max<double>(1.0, sqrt(left.size()\
    \ * 2.0 / 3.0)));\n        order.resize(left.size());\n        iota(order.begin(),\
    \ order.end(), 0);\n        sort(order.begin(), order.end(), [&](int a, int b)\
    \ {\n            if (left[a] / Bsize != left[b] / Bsize)\n                return\
    \ left[a] < left[b];\n            else\n                return right[a] < right[b];\n\
    \        });\n    }\n\n    // return next event id\n    int proceed() {\n    \
    \    if (ptr == order.size()) return -1;\n        int id = order[ptr];\n     \
    \   while (nl > left[id]) query(--nl);\n        while (nr < right[id]) query(nr++);\n\
    \        while (nl < left[id]) query(nl++);\n        while (nr > right[id]) query(--nr);\n\
    \        return (order[ptr++]);\n    }\n\n    void query(int p) {\n        v[p]\
    \ = !v[p];\n        if (v[p])\n            add(p);\n        else\n           \
    \ del(p);\n    }\n\n    void add(int p) {\n    }\n\n    void del(int p) {\n  \
    \  }\n};\n"
  code: "// O(NB + Q(N/B)) (B : numver of blocks)\n// set B = sqrt(Q) -> O(N sqrt(Q)\
    \ * F)\n// F : cost of operation\n// ref : https://ei1333.hateblo.jp/entry/2017/09/11/211011\n\
    // ref : https://nyaannyaan.github.io/library/misc/mo.hpp\n\nstruct Mo {\n   \
    \ V<int> left, right, order;\n    V<bool> v;\n    int n, Bsize, nl, nr, ptr;\n\
    \n    Mo(int n) : n(n), nl(0), nr(0), ptr(0), v(n) {}\n\n    //[l, r)\n    void\
    \ insert(int l, int r) {\n        left.push_back(l);\n        right.push_back(r);\n\
    \    }\n\n    void build() {\n        // Bsize = n / min<int>(n, sqrt(left.size()));\n\
    \        Bsize = max<int>(\n            1, 1.0 * n / max<double>(1.0, sqrt(left.size()\
    \ * 2.0 / 3.0)));\n        order.resize(left.size());\n        iota(order.begin(),\
    \ order.end(), 0);\n        sort(order.begin(), order.end(), [&](int a, int b)\
    \ {\n            if (left[a] / Bsize != left[b] / Bsize)\n                return\
    \ left[a] < left[b];\n            else\n                return right[a] < right[b];\n\
    \        });\n    }\n\n    // return next event id\n    int proceed() {\n    \
    \    if (ptr == order.size()) return -1;\n        int id = order[ptr];\n     \
    \   while (nl > left[id]) query(--nl);\n        while (nr < right[id]) query(nr++);\n\
    \        while (nl < left[id]) query(nl++);\n        while (nr > right[id]) query(--nr);\n\
    \        return (order[ptr++]);\n    }\n\n    void query(int p) {\n        v[p]\
    \ = !v[p];\n        if (v[p])\n            add(p);\n        else\n           \
    \ del(p);\n    }\n\n    void add(int p) {\n    }\n\n    void del(int p) {\n  \
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/other/Mo.hpp
  requiredBy: []
  timestamp: '2022-03-17 11:21:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/other/Mo.hpp
layout: document
redirect_from:
- /library/cpp_src/other/Mo.hpp
- /library/cpp_src/other/Mo.hpp.html
title: cpp_src/other/Mo.hpp
---
