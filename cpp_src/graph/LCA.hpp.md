---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lca.test.cpp
    title: test/yosupo/lca.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/graph/LCA.hpp\"\n//E : int or edge class\n\ntemplate<class\
    \ E>\nstruct LCA {\n\tVV<int> anc;\n\tV<int> dep;\n\tint lg;\n\tconst VV<E>& g;\n\
    \n\tLCA(const VV<E>& g, int root) : g(g) {\n\t\tint n = g.size();\n\t\tlg = 1;\n\
    \t\twhile ((1 << lg) < n) lg++;\n\t\tanc = VV<int>(lg, V<int>(n, -1));\n\t\tdep\
    \ = V<int>(n);\n\t\tdfs(root, -1, 0);\n\n\t\tfor (int i = 1; i < lg; i++) {\n\t\
    \t\tfor (int j = 0; j < n; j++) {\n\t\t\t\tanc[i][j] = (anc[i - 1][j] == -1) ?\
    \ -1 : anc[i - 1][anc[i - 1][j]];\n\t\t\t}\n\t\t}\t\t\n\t}\n\n\tvoid dfs(int v,\
    \ int p, int d) {\n\t\tanc[0][v] = p;\n\t\tdep[v] = d;\n\t\tfor (auto e : g[v])\
    \ {\n\t\t\tint to = e;\n\t\t\tif (to == p) continue;\n\t\t\tdfs(to, v, d + 1);\n\
    \t\t}\n\t}\n\n\tint query(int u, int v) {\n\t\tif (dep[u] < dep[v]) swap(u, v);\n\
    \t\tint df = dep[u] - dep[v];\n\t\tfor (int i = lg - 1; i >= 0; --i) {\n\t\t\t\
    if ((df >> i) & 1) {\n\t\t\t\tdf -= (1 << i);\n\t\t\t\tu = anc[i][u];\n\t\t\t\
    }\n\t\t}\n\t\tif (u == v) return u;\n\t\tfor (int i = lg - 1; i >= 0; --i) {\n\
    \t\t\tif (anc[i][u] != anc[i][v]) {\n\t\t\t\tu = anc[i][u];\n\t\t\t\tv = anc[i][v];\n\
    \t\t\t}\n\t\t}\n\t\treturn anc[0][u];\n\t}\n};\n"
  code: "//E : int or edge class\n\ntemplate<class E>\nstruct LCA {\n\tVV<int> anc;\n\
    \tV<int> dep;\n\tint lg;\n\tconst VV<E>& g;\n\n\tLCA(const VV<E>& g, int root)\
    \ : g(g) {\n\t\tint n = g.size();\n\t\tlg = 1;\n\t\twhile ((1 << lg) < n) lg++;\n\
    \t\tanc = VV<int>(lg, V<int>(n, -1));\n\t\tdep = V<int>(n);\n\t\tdfs(root, -1,\
    \ 0);\n\n\t\tfor (int i = 1; i < lg; i++) {\n\t\t\tfor (int j = 0; j < n; j++)\
    \ {\n\t\t\t\tanc[i][j] = (anc[i - 1][j] == -1) ? -1 : anc[i - 1][anc[i - 1][j]];\n\
    \t\t\t}\n\t\t}\t\t\n\t}\n\n\tvoid dfs(int v, int p, int d) {\n\t\tanc[0][v] =\
    \ p;\n\t\tdep[v] = d;\n\t\tfor (auto e : g[v]) {\n\t\t\tint to = e;\n\t\t\tif\
    \ (to == p) continue;\n\t\t\tdfs(to, v, d + 1);\n\t\t}\n\t}\n\n\tint query(int\
    \ u, int v) {\n\t\tif (dep[u] < dep[v]) swap(u, v);\n\t\tint df = dep[u] - dep[v];\n\
    \t\tfor (int i = lg - 1; i >= 0; --i) {\n\t\t\tif ((df >> i) & 1) {\n\t\t\t\t\
    df -= (1 << i);\n\t\t\t\tu = anc[i][u];\n\t\t\t}\n\t\t}\n\t\tif (u == v) return\
    \ u;\n\t\tfor (int i = lg - 1; i >= 0; --i) {\n\t\t\tif (anc[i][u] != anc[i][v])\
    \ {\n\t\t\t\tu = anc[i][u];\n\t\t\t\tv = anc[i][v];\n\t\t\t}\n\t\t}\n\t\treturn\
    \ anc[0][u];\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/LCA.hpp
  requiredBy: []
  timestamp: '2020-02-12 22:31:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/lca.test.cpp
documentation_of: cpp_src/graph/LCA.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/LCA.hpp
- /library/cpp_src/graph/LCA.hpp.html
title: cpp_src/graph/LCA.hpp
---
