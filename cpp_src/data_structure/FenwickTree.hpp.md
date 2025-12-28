---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0343.test.cpp
    title: test/aoj/0343.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_add_range_sum.test.cpp
    title: test/yosupo/point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/data_structure/FenwickTree.hpp\"\ntemplate <class\
    \ T>\nstruct BIT {\n    int n;\n    vector<T> bit;\n\n    BIT(int _n = 0) : n(_n),\
    \ bit(n + 1) {}\n\n    // ABC368G\n    BIT(const V<T>& vec) : n(SZ(vec)), bit(n\
    \ + 1) {\n        rep(i, n) bit[i + 1] = vec[i];\n        for (int i = 1; i <=\
    \ n; ++i) {\n            int j = i + (i & -i);\n            if (j <= n) {\n  \
    \              bit[j] += bit[i];\n            }\n        }\n    }\n\n    // sum\
    \ of [0, i), 0 <= i <= n\n    T sum(int i) {\n        T s = 0;\n        while\
    \ (i > 0) {\n            s += bit[i];\n            i -= i & -i;\n        }\n \
    \       return s;\n    }\n\n    // 0 <= i < n\n    void add(int i, T x) {\n  \
    \      ++i;\n        while (i <= n) {\n            bit[i] += x;\n            i\
    \ += i & -i;\n        }\n    }\n\n    //[l, r) 0 <= l < r < n\n    T sum(int l,\
    \ int r) { return sum(r) - sum(l); }\n\n    // ABC392F, ARC197C\n    // smallest\
    \ i, sum(i) >= w, none -> n + 1\n    int lower_bound(T w) {\n        if (w <=\
    \ 0) return 0;\n        int x = 0, l = 1;\n        while (l * 2 <= n) l *= 2;\n\
    \n        for (int k = l; k > 0; k /= 2) {\n            if (x + k <= n && bit[x\
    \ + k] < w) {\n                w -= bit[x + k];\n                x += k;\n   \
    \         }\n        }\n        return x + 1;\n    }\n\n    // ABC380G\n    V<T>\
    \ recover() {\n        V<T> res(n);\n        rep(i, n) res[i] = sum(i, i + 1);\n\
    \        return res;\n    }\n};\n"
  code: "template <class T>\nstruct BIT {\n    int n;\n    vector<T> bit;\n\n    BIT(int\
    \ _n = 0) : n(_n), bit(n + 1) {}\n\n    // ABC368G\n    BIT(const V<T>& vec) :\
    \ n(SZ(vec)), bit(n + 1) {\n        rep(i, n) bit[i + 1] = vec[i];\n        for\
    \ (int i = 1; i <= n; ++i) {\n            int j = i + (i & -i);\n            if\
    \ (j <= n) {\n                bit[j] += bit[i];\n            }\n        }\n  \
    \  }\n\n    // sum of [0, i), 0 <= i <= n\n    T sum(int i) {\n        T s = 0;\n\
    \        while (i > 0) {\n            s += bit[i];\n            i -= i & -i;\n\
    \        }\n        return s;\n    }\n\n    // 0 <= i < n\n    void add(int i,\
    \ T x) {\n        ++i;\n        while (i <= n) {\n            bit[i] += x;\n \
    \           i += i & -i;\n        }\n    }\n\n    //[l, r) 0 <= l < r < n\n  \
    \  T sum(int l, int r) { return sum(r) - sum(l); }\n\n    // ABC392F, ARC197C\n\
    \    // smallest i, sum(i) >= w, none -> n + 1\n    int lower_bound(T w) {\n \
    \       if (w <= 0) return 0;\n        int x = 0, l = 1;\n        while (l * 2\
    \ <= n) l *= 2;\n\n        for (int k = l; k > 0; k /= 2) {\n            if (x\
    \ + k <= n && bit[x + k] < w) {\n                w -= bit[x + k];\n          \
    \      x += k;\n            }\n        }\n        return x + 1;\n    }\n\n   \
    \ // ABC380G\n    V<T> recover() {\n        V<T> res(n);\n        rep(i, n) res[i]\
    \ = sum(i, i + 1);\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/data_structure/FenwickTree.hpp
  requiredBy: []
  timestamp: '2025-12-28 17:44:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0343.test.cpp
  - test/yosupo/point_add_range_sum.test.cpp
documentation_of: cpp_src/data_structure/FenwickTree.hpp
layout: document
redirect_from:
- /library/cpp_src/data_structure/FenwickTree.hpp
- /library/cpp_src/data_structure/FenwickTree.hpp.html
title: cpp_src/data_structure/FenwickTree.hpp
---
