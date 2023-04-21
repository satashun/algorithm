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
    - https://atcoder.jp/contests/abc293/submissions/39637410
    - https://atcoder.jp/contests/abc293/submissions/40402531
    - https://ei1333.hateblo.jp/entry/2017/09/11/211011
    - https://nyaannyaan.github.io/library/misc/mo.hpp
  bundledCode: "#line 1 \"cpp_src/other/Mo.hpp\"\n// O(NB + Q(N/B)) (B : numver of\
    \ blocks)\n// set B = sqrt(Q) -> O(N sqrt(Q) * F)\n// F : cost of operation\n\
    // ref : https://ei1333.hateblo.jp/entry/2017/09/11/211011\n// ref : https://nyaannyaan.github.io/library/misc/mo.hpp\n\
    \n// O(NB + Q(N/B)) (B : numver of blocks)\n// set B = sqrt(Q) -> O(N sqrt(Q)\
    \ * F)\n// F : cost of operation\n// ref : https://ei1333.hateblo.jp/entry/2017/09/11/211011\n\
    // ref : https://nyaannyaan.github.io/library/misc/mo.hpp\n// https://atcoder.jp/contests/abc293/submissions/39637410\n\
    // my sub: https://atcoder.jp/contests/abc293/submissions/40402531\n\nstruct Mo\
    \ {\n    V<int> left, right, order;\n    int n, Bsize, nl, nr, ptr;\n\n    Mo(int\
    \ n) : n(n), nl(0), nr(0), ptr(0) {}\n\n    //[l, r)\n    void insert(int l, int\
    \ r) {\n        left.push_back(l);\n        right.push_back(r);\n    }\n\n   \
    \ void build() {\n        // Bsize = n / min<int>(n, sqrt(left.size()));\n   \
    \     Bsize = max<int>(\n            1, 1.0 * n / max<double>(1.0, sqrt(left.size()\
    \ * 2.0 / 3.0)));\n        order.resize(left.size());\n        iota(order.begin(),\
    \ order.end(), 0);\n        sort(order.begin(), order.end(), [&](int a, int b)\
    \ {\n            if (left[a] / Bsize != left[b] / Bsize)\n                return\
    \ left[a] < left[b];\n            else\n                return right[a] < right[b];\n\
    \        });\n    }\n\n    // return next event id\n    int proceed() {\n    \
    \    if (ptr == order.size()) return -1;\n        int id = order[ptr];\n     \
    \   while (nl > left[id]) query(--nl);\n        while (nr < right[id]) query(nr++);\n\
    \        while (nl < left[id]) query(nl++);\n        while (nr > right[id]) query(--nr);\n\
    \        return (order[ptr++]);\n    }\n\n    void query(int p) {}\n\n    template\
    \ <typename AL, typename AR, typename DL, typename DR, typename F>\n    void run(AL\
    \ add_left, AR add_right, DL del_left, DR del_right, F f) {\n        nl = 0, nr\
    \ = 0;\n        for (auto id : order) {\n            while (nl > left[id]) add_left(--nl);\n\
    \            while (nr < right[id]) add_right(nr++);\n            while (nl <\
    \ left[id]) del_left(nl++);\n            while (nr > right[id]) del_right(--nr);\n\
    \            f(id);\n        }\n    }\n\n    template <typename A, typename D,\
    \ typename F>\n    void run(A add, D del, F f) {\n        run(add, add, del, del,\
    \ f);\n    }\n};\n"
  code: "// O(NB + Q(N/B)) (B : numver of blocks)\n// set B = sqrt(Q) -> O(N sqrt(Q)\
    \ * F)\n// F : cost of operation\n// ref : https://ei1333.hateblo.jp/entry/2017/09/11/211011\n\
    // ref : https://nyaannyaan.github.io/library/misc/mo.hpp\n\n// O(NB + Q(N/B))\
    \ (B : numver of blocks)\n// set B = sqrt(Q) -> O(N sqrt(Q) * F)\n// F : cost\
    \ of operation\n// ref : https://ei1333.hateblo.jp/entry/2017/09/11/211011\n//\
    \ ref : https://nyaannyaan.github.io/library/misc/mo.hpp\n// https://atcoder.jp/contests/abc293/submissions/39637410\n\
    // my sub: https://atcoder.jp/contests/abc293/submissions/40402531\n\nstruct Mo\
    \ {\n    V<int> left, right, order;\n    int n, Bsize, nl, nr, ptr;\n\n    Mo(int\
    \ n) : n(n), nl(0), nr(0), ptr(0) {}\n\n    //[l, r)\n    void insert(int l, int\
    \ r) {\n        left.push_back(l);\n        right.push_back(r);\n    }\n\n   \
    \ void build() {\n        // Bsize = n / min<int>(n, sqrt(left.size()));\n   \
    \     Bsize = max<int>(\n            1, 1.0 * n / max<double>(1.0, sqrt(left.size()\
    \ * 2.0 / 3.0)));\n        order.resize(left.size());\n        iota(order.begin(),\
    \ order.end(), 0);\n        sort(order.begin(), order.end(), [&](int a, int b)\
    \ {\n            if (left[a] / Bsize != left[b] / Bsize)\n                return\
    \ left[a] < left[b];\n            else\n                return right[a] < right[b];\n\
    \        });\n    }\n\n    // return next event id\n    int proceed() {\n    \
    \    if (ptr == order.size()) return -1;\n        int id = order[ptr];\n     \
    \   while (nl > left[id]) query(--nl);\n        while (nr < right[id]) query(nr++);\n\
    \        while (nl < left[id]) query(nl++);\n        while (nr > right[id]) query(--nr);\n\
    \        return (order[ptr++]);\n    }\n\n    void query(int p) {}\n\n    template\
    \ <typename AL, typename AR, typename DL, typename DR, typename F>\n    void run(AL\
    \ add_left, AR add_right, DL del_left, DR del_right, F f) {\n        nl = 0, nr\
    \ = 0;\n        for (auto id : order) {\n            while (nl > left[id]) add_left(--nl);\n\
    \            while (nr < right[id]) add_right(nr++);\n            while (nl <\
    \ left[id]) del_left(nl++);\n            while (nr > right[id]) del_right(--nr);\n\
    \            f(id);\n        }\n    }\n\n    template <typename A, typename D,\
    \ typename F>\n    void run(A add, D del, F f) {\n        run(add, add, del, del,\
    \ f);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/other/Mo.hpp
  requiredBy: []
  timestamp: '2023-04-22 00:40:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/other/Mo.hpp
layout: document
redirect_from:
- /library/cpp_src/other/Mo.hpp
- /library/cpp_src/other/Mo.hpp.html
title: cpp_src/other/Mo.hpp
---
