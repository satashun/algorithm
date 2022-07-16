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
  bundledCode: "#line 1 \"cpp_src/graph/Tree.hpp\"\ntemplate <class T>\nclass Forest\
    \ : public Graph<T> {\n   public:\n    using Graph<T>::edges;\n    using Graph<T>::g;\n\
    \    using Graph<T>::Graph;\n\n    V<int> in, ot, dep, par;\n    V<T> dist;\n\n\
    \    Forest(int n) : Graph<T>(n) {}\n\n    void init() {\n        int sz = g.size();\n\
    \        in = V<int>(sz, -1);\n        ot = V<int>(sz, -1);\n        dep = V<int>(sz,\
    \ -1);\n        par = V<int>(sz, -1);\n        dist = V<int>(sz);\n    }\n\n \
    \   void dfs(int v, int p, int d, int& k) {\n        in[v] = k++;\n        dep[v]\
    \ = d;\n        par[v] = p;\n        for (auto e : g[v]) {\n            if (e.to\
    \ == p) continue;\n            dfs(e.to, v, d + 1, k);\n            dist[e.to]\
    \ = dist[v] + e.cost;\n        }\n        ot[v] = k;\n    }\n\n    void build()\
    \ {\n        int now = 0;\n        for (int i = 0; i < g.size(); ++i) {\n    \
    \        if (in[i] == -1) {\n                dfs(i, -1, 0, now);\n           \
    \ }\n        }\n    }\n};\n\ntemplate <class T>\npii find_diam(Graph<T>& g) {\n\
    \    int r = 0;\n    auto ds = bfs(g, r);\n    int r2 = max_element(ALL(ds)) -\
    \ ds.begin();\n    auto ds2 = bfs(g, r2);\n    int r3 = max_element(ALL(ds2))\
    \ - ds2.begin();\n    auto ds3 = bfs(g, r3);\n    return mp(r2, r3);\n}\n"
  code: "template <class T>\nclass Forest : public Graph<T> {\n   public:\n    using\
    \ Graph<T>::edges;\n    using Graph<T>::g;\n    using Graph<T>::Graph;\n\n   \
    \ V<int> in, ot, dep, par;\n    V<T> dist;\n\n    Forest(int n) : Graph<T>(n)\
    \ {}\n\n    void init() {\n        int sz = g.size();\n        in = V<int>(sz,\
    \ -1);\n        ot = V<int>(sz, -1);\n        dep = V<int>(sz, -1);\n        par\
    \ = V<int>(sz, -1);\n        dist = V<int>(sz);\n    }\n\n    void dfs(int v,\
    \ int p, int d, int& k) {\n        in[v] = k++;\n        dep[v] = d;\n       \
    \ par[v] = p;\n        for (auto e : g[v]) {\n            if (e.to == p) continue;\n\
    \            dfs(e.to, v, d + 1, k);\n            dist[e.to] = dist[v] + e.cost;\n\
    \        }\n        ot[v] = k;\n    }\n\n    void build() {\n        int now =\
    \ 0;\n        for (int i = 0; i < g.size(); ++i) {\n            if (in[i] == -1)\
    \ {\n                dfs(i, -1, 0, now);\n            }\n        }\n    }\n};\n\
    \ntemplate <class T>\npii find_diam(Graph<T>& g) {\n    int r = 0;\n    auto ds\
    \ = bfs(g, r);\n    int r2 = max_element(ALL(ds)) - ds.begin();\n    auto ds2\
    \ = bfs(g, r2);\n    int r3 = max_element(ALL(ds2)) - ds2.begin();\n    auto ds3\
    \ = bfs(g, r3);\n    return mp(r2, r3);\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/Tree.hpp
  requiredBy: []
  timestamp: '2022-07-17 01:58:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/Tree.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/Tree.hpp
- /library/cpp_src/graph/Tree.hpp.html
title: cpp_src/graph/Tree.hpp
---
