---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lca.test.cpp
    title: test/yosupo/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/graph/LCA.hpp\"\ntemplate <class E>\nstruct LCA\
    \ {\n    VV<int> anc;\n    V<int> dep;\n    int lg;\n    const Graph<E>& g;\n\n\
    \    LCA(const Graph<E>& g, int root = 0) : g(g) {\n        int n = g.size();\n\
    \        lg = 1;\n        while ((1 << lg) < n) lg++;\n        anc = VV<int>(lg,\
    \ V<int>(n, -1));\n        dep = V<int>(n);\n        dfs(root, -1, 0);\n\n   \
    \     for (int i = 1; i < lg; i++) {\n            for (int j = 0; j < n; j++)\
    \ {\n                anc[i][j] =\n                    (anc[i - 1][j] == -1) ?\
    \ -1 : anc[i - 1][anc[i - 1][j]];\n            }\n        }\n    }\n\n    void\
    \ dfs(int v, int p, int d) {\n        anc[0][v] = p;\n        dep[v] = d;\n  \
    \      for (auto e : g[v]) {\n            if (e.to == p) continue;\n         \
    \   dfs(e.to, v, d + 1);\n        }\n    }\n\n    int query(int u, int v) {\n\
    \        if (dep[u] < dep[v]) swap(u, v);\n        int df = dep[u] - dep[v];\n\
    \        for (int i = lg - 1; i >= 0; --i) {\n            if ((df >> i) & 1) {\n\
    \                df -= (1 << i);\n                u = anc[i][u];\n           \
    \ }\n        }\n        if (u == v) return u;\n        for (int i = lg - 1; i\
    \ >= 0; --i) {\n            if (anc[i][u] != anc[i][v]) {\n                u =\
    \ anc[i][u];\n                v = anc[i][v];\n            }\n        }\n     \
    \   return anc[0][u];\n    }\n\n    int dist(int a, int b) {\n        int lc =\
    \ query(a, b);\n        return dep[a] + dep[b] - dep[lc] * 2;\n    }\n};\n"
  code: "template <class E>\nstruct LCA {\n    VV<int> anc;\n    V<int> dep;\n   \
    \ int lg;\n    const Graph<E>& g;\n\n    LCA(const Graph<E>& g, int root = 0)\
    \ : g(g) {\n        int n = g.size();\n        lg = 1;\n        while ((1 << lg)\
    \ < n) lg++;\n        anc = VV<int>(lg, V<int>(n, -1));\n        dep = V<int>(n);\n\
    \        dfs(root, -1, 0);\n\n        for (int i = 1; i < lg; i++) {\n       \
    \     for (int j = 0; j < n; j++) {\n                anc[i][j] =\n           \
    \         (anc[i - 1][j] == -1) ? -1 : anc[i - 1][anc[i - 1][j]];\n          \
    \  }\n        }\n    }\n\n    void dfs(int v, int p, int d) {\n        anc[0][v]\
    \ = p;\n        dep[v] = d;\n        for (auto e : g[v]) {\n            if (e.to\
    \ == p) continue;\n            dfs(e.to, v, d + 1);\n        }\n    }\n\n    int\
    \ query(int u, int v) {\n        if (dep[u] < dep[v]) swap(u, v);\n        int\
    \ df = dep[u] - dep[v];\n        for (int i = lg - 1; i >= 0; --i) {\n       \
    \     if ((df >> i) & 1) {\n                df -= (1 << i);\n                u\
    \ = anc[i][u];\n            }\n        }\n        if (u == v) return u;\n    \
    \    for (int i = lg - 1; i >= 0; --i) {\n            if (anc[i][u] != anc[i][v])\
    \ {\n                u = anc[i][u];\n                v = anc[i][v];\n        \
    \    }\n        }\n        return anc[0][u];\n    }\n\n    int dist(int a, int\
    \ b) {\n        int lc = query(a, b);\n        return dep[a] + dep[b] - dep[lc]\
    \ * 2;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/LCA.hpp
  requiredBy: []
  timestamp: '2021-10-28 16:07:17+09:00'
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
