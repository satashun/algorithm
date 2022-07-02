---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_11_D.test.cpp
    title: test/aoj/ALDS1_11_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/unionfind.test.cpp
    title: test/yosupo/unionfind.test.cpp
  - icon: ':x:'
    path: test/yukicoder/yukicoder-583.test.cpp
    title: test/yukicoder/yukicoder-583.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/data_structure/DisjointSetUnion.hpp\"\nclass unionfind\
    \ {\n    vector<int> par, rank;\n\n   public:\n    void init(int n) {\n      \
    \  par.resize(n);\n        rank.resize(n);\n\n        for (int i = 0; i < n; i++)\
    \ {\n            par[i] = i;\n            rank[i] = 0;\n        }\n    }\n\n \
    \   unionfind() {}\n    unionfind(int n) { init(n); }\n\n    int find(int x) {\n\
    \        if (par[x] == x)\n            return x;\n        else\n            return\
    \ par[x] = find(par[x]);\n    }\n\n    bool unite(int x, int y) {\n        x =\
    \ find(x);\n        y = find(y);\n        if (x == y) return false;\n\n      \
    \  if (rank[x] < rank[y])\n            par[x] = y;\n        else {\n         \
    \   par[y] = x;\n            if (rank[x] == rank[y]) ++rank[x];\n        }\n \
    \       return true;\n    }\n\n    bool same(int x, int y) { return (find(x) ==\
    \ find(y)); }\n};\n"
  code: "class unionfind {\n    vector<int> par, rank;\n\n   public:\n    void init(int\
    \ n) {\n        par.resize(n);\n        rank.resize(n);\n\n        for (int i\
    \ = 0; i < n; i++) {\n            par[i] = i;\n            rank[i] = 0;\n    \
    \    }\n    }\n\n    unionfind() {}\n    unionfind(int n) { init(n); }\n\n   \
    \ int find(int x) {\n        if (par[x] == x)\n            return x;\n       \
    \ else\n            return par[x] = find(par[x]);\n    }\n\n    bool unite(int\
    \ x, int y) {\n        x = find(x);\n        y = find(y);\n        if (x == y)\
    \ return false;\n\n        if (rank[x] < rank[y])\n            par[x] = y;\n \
    \       else {\n            par[y] = x;\n            if (rank[x] == rank[y]) ++rank[x];\n\
    \        }\n        return true;\n    }\n\n    bool same(int x, int y) { return\
    \ (find(x) == find(y)); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/data_structure/DisjointSetUnion.hpp
  requiredBy: []
  timestamp: '2022-04-10 12:39:22+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/yukicoder-583.test.cpp
  - test/yosupo/unionfind.test.cpp
  - test/aoj/ALDS1_11_D.test.cpp
documentation_of: cpp_src/data_structure/DisjointSetUnion.hpp
layout: document
redirect_from:
- /library/cpp_src/data_structure/DisjointSetUnion.hpp
- /library/cpp_src/data_structure/DisjointSetUnion.hpp.html
title: cpp_src/data_structure/DisjointSetUnion.hpp
---
