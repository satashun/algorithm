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
  bundledCode: "#line 1 \"cpp_src/graph/helper/CountSpanningTree.hpp\"\n// ABC 253\
    \ H\ntemplate <class T>\nT count_spanning_tree(int N, int mask, const V<pii>&\
    \ es) {\n    V<int> id(N, -1);\n    int now = 0;\n    rep(j, N) {\n        if\
    \ (mask >> j & 1) {\n            id[j] = now++;\n        }\n    }\n\n    Matrix<Mint>\
    \ A(now, now);\n    V<int> deg(now);\n    for (auto [a, b] : es) {\n        if\
    \ (id[a] != -1 && id[b] != -1) {\n            deg[id[a]]++;\n            deg[id[b]]++;\n\
    \            A.a[id[a]][id[b]]--;\n            A.a[id[b]][id[a]]--;\n        }\n\
    \    }\n\n    rep(i, now) A.a[i][i] = deg[i];\n\n    V<int> sa(now - 1), sb(now\
    \ - 1);\n    iota(ALL(sa), 0);\n    iota(ALL(sb), 0);\n    auto B = sub_matrix(A,\
    \ sa, sb);\n    return det(B);\n}\n"
  code: "// ABC 253 H\ntemplate <class T>\nT count_spanning_tree(int N, int mask,\
    \ const V<pii>& es) {\n    V<int> id(N, -1);\n    int now = 0;\n    rep(j, N)\
    \ {\n        if (mask >> j & 1) {\n            id[j] = now++;\n        }\n   \
    \ }\n\n    Matrix<Mint> A(now, now);\n    V<int> deg(now);\n    for (auto [a,\
    \ b] : es) {\n        if (id[a] != -1 && id[b] != -1) {\n            deg[id[a]]++;\n\
    \            deg[id[b]]++;\n            A.a[id[a]][id[b]]--;\n            A.a[id[b]][id[a]]--;\n\
    \        }\n    }\n\n    rep(i, now) A.a[i][i] = deg[i];\n\n    V<int> sa(now\
    \ - 1), sb(now - 1);\n    iota(ALL(sa), 0);\n    iota(ALL(sb), 0);\n    auto B\
    \ = sub_matrix(A, sa, sb);\n    return det(B);\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/helper/CountSpanningTree.hpp
  requiredBy: []
  timestamp: '2022-07-02 19:40:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/helper/CountSpanningTree.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/helper/CountSpanningTree.hpp
- /library/cpp_src/graph/helper/CountSpanningTree.hpp.html
title: cpp_src/graph/helper/CountSpanningTree.hpp
---
