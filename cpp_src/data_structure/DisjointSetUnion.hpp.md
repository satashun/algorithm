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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/data_structure/DisjointSetUnion.hpp\"\nclass unionfind\
    \ {\n\tvector<int> par, rank;\n\npublic:\n\tvoid init(int n) {\n\t\tpar.resize(n);\n\
    \t\trank.resize(n);\n\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tpar[i] = i;\n\t\
    \t\trank[i] = 0;\n\t\t}\n\t}\n\n\tint find(int x) {\n\t\tif (par[x] == x) return\
    \ x;\n\t\telse return par[x] = find(par[x]);\n\t}\n\n\tvoid unite(int x, int y)\
    \ {\n\t\tx = find(x);\n\t\ty = find(y);\n\t\tif (x == y) return ;\n\n\t\tif (rank[x]\
    \ < rank[y]) par[x] = y;\n\t\telse {\n\t\t\tpar[y] = x;\n\t\t\tif (rank[x] ==\
    \ rank[y]) ++rank[x];\n\t\t}\n\t}\n\n\tbool same(int x, int y) { return (find(x)\
    \ == find(y)); }\n};\n"
  code: "class unionfind {\n\tvector<int> par, rank;\n\npublic:\n\tvoid init(int n)\
    \ {\n\t\tpar.resize(n);\n\t\trank.resize(n);\n\n\t\tfor (int i = 0; i < n; i++)\
    \ {\n\t\t\tpar[i] = i;\n\t\t\trank[i] = 0;\n\t\t}\n\t}\n\n\tint find(int x) {\n\
    \t\tif (par[x] == x) return x;\n\t\telse return par[x] = find(par[x]);\n\t}\n\n\
    \tvoid unite(int x, int y) {\n\t\tx = find(x);\n\t\ty = find(y);\n\t\tif (x ==\
    \ y) return ;\n\n\t\tif (rank[x] < rank[y]) par[x] = y;\n\t\telse {\n\t\t\tpar[y]\
    \ = x;\n\t\t\tif (rank[x] == rank[y]) ++rank[x];\n\t\t}\n\t}\n\n\tbool same(int\
    \ x, int y) { return (find(x) == find(y)); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/data_structure/DisjointSetUnion.hpp
  requiredBy: []
  timestamp: '2020-09-17 22:26:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/unionfind.test.cpp
  - test/aoj/ALDS1_11_D.test.cpp
documentation_of: cpp_src/data_structure/DisjointSetUnion.hpp
layout: document
redirect_from:
- /library/cpp_src/data_structure/DisjointSetUnion.hpp
- /library/cpp_src/data_structure/DisjointSetUnion.hpp.html
title: cpp_src/data_structure/DisjointSetUnion.hpp
---