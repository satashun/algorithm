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
  bundledCode: "#line 1 \"cpp_src/data_structure/FenwickTree2D.hpp\"\ntemplate <typename\
    \ T>\nstruct BIT2D {\n    int N, M;\n    VV<T> bit;\n    BIT2D(int P, int Q) :\
    \ N(P + 3), M(Q + 3) { bit.assign(N, vector<T>(M, 0)); }\n\n    void add(int r,\
    \ int c, T x) {\n        r++, c++;\n        for (int i = r; i < N; i += (i & -i))\
    \ {\n            for (int j = c; j < M; j += (j & -j)) {\n                bit[i][j]\
    \ += x;\n            }\n        }\n    }\n\n    // 0 <= r <= N, 0 <= c <= M\n\
    \    // sum of [0,r)x[0,c)\n    T sum(int r, int c) {\n        T s(0);\n     \
    \   for (int i = r; i > 0; i -= (i & -i)) {\n            for (int j = c; j > 0;\
    \ j -= (j & -j)) {\n                s += bit[i][j];\n            }\n        }\n\
    \        return s;\n    }\n\n    // sum of [r1,r2)x[c1,c2)\n    T sum(int r1,\
    \ int c1, int r2, int c2) {\n        return sum(r2, c2) - sum(r2, c1) - sum(r1,\
    \ c2) + sum(r1, c1);\n    }\n};\n"
  code: "template <typename T>\nstruct BIT2D {\n    int N, M;\n    VV<T> bit;\n  \
    \  BIT2D(int P, int Q) : N(P + 3), M(Q + 3) { bit.assign(N, vector<T>(M, 0));\
    \ }\n\n    void add(int r, int c, T x) {\n        r++, c++;\n        for (int\
    \ i = r; i < N; i += (i & -i)) {\n            for (int j = c; j < M; j += (j &\
    \ -j)) {\n                bit[i][j] += x;\n            }\n        }\n    }\n\n\
    \    // 0 <= r <= N, 0 <= c <= M\n    // sum of [0,r)x[0,c)\n    T sum(int r,\
    \ int c) {\n        T s(0);\n        for (int i = r; i > 0; i -= (i & -i)) {\n\
    \            for (int j = c; j > 0; j -= (j & -j)) {\n                s += bit[i][j];\n\
    \            }\n        }\n        return s;\n    }\n\n    // sum of [r1,r2)x[c1,c2)\n\
    \    T sum(int r1, int c1, int r2, int c2) {\n        return sum(r2, c2) - sum(r2,\
    \ c1) - sum(r1, c2) + sum(r1, c1);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/data_structure/FenwickTree2D.hpp
  requiredBy: []
  timestamp: '2022-02-12 18:33:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/data_structure/FenwickTree2D.hpp
layout: document
redirect_from:
- /library/cpp_src/data_structure/FenwickTree2D.hpp
- /library/cpp_src/data_structure/FenwickTree2D.hpp.html
title: cpp_src/data_structure/FenwickTree2D.hpp
---
