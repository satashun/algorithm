---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/scc.test.cpp
    title: test/yosupo/scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/graph/SCC.hpp\"\n// ABC214H\n// ABC245F\n// if i\
    \ -> j, then cmp[i] <= cmp[j]\n// g_comp : compressed DAG\n\ntemplate <class T>\n\
    struct SCC : Graph<T> {\n   public:\n    using Graph<T>::Graph;\n    using Graph<T>::g;\n\
    \    Graph<T> rg;\n\n    V<int> vs, cmp, vis;\n    VV<int> comps;\n\n    // allow\
    \ multiple edges\n    Graph<T> g_comp;\n\n    void dfs(int v) {\n        vis[v]\
    \ = true;\n\n        for (auto e : g[v]) {\n            if (!vis[e.to]) {\n  \
    \              dfs(e.to);\n            }\n        }\n\n        vs.push_back(v);\n\
    \    }\n\n    void rdfs(int v, int k) {\n        vis[v] = true;\n        cmp[v]\
    \ = k;\n\n        for (auto e : rg[v]) {\n            if (!vis[e.to]) {\n    \
    \            rdfs(e.to, k);\n            }\n        }\n    }\n\n    void init()\
    \ {\n        int n = g.size();\n        rg = Graph<T>(n);\n        rep(i, n) {\n\
    \            for (auto e : g[i]) {\n                rg.add_directed_edge(e.to,\
    \ e.from, e.cost);\n            }\n        }\n\n        vs.clear();\n        cmp\
    \ = V<int>(n);\n        vis = V<int>(n);\n\n        rep(v, n) if (!vis[v]) dfs(v);\n\
    \n        fill(vis.begin(), vis.end(), false);\n\n        int k = 0;\n       \
    \ reverse(vs.begin(), vs.end());\n\n        for (int v : vs) {\n            if\
    \ (!vis[v]) {\n                rdfs(v, k++);\n            }\n        }\n\n   \
    \     comps.resize(k);\n        rep(v, n) { comps[cmp[v]].push_back(v); }\n\n\
    \        g_comp = Graph<T>(k);\n\n        rep(i, n) {\n            for (auto e\
    \ : g[i]) {\n                if (cmp[i] != cmp[e.to]) {\n                    g_comp.add_directed_edge(cmp[i],\
    \ cmp[e.to], e.cost);\n                }\n            }\n        }\n    }\n};\n"
  code: "// ABC214H\n// ABC245F\n// if i -> j, then cmp[i] <= cmp[j]\n// g_comp :\
    \ compressed DAG\n\ntemplate <class T>\nstruct SCC : Graph<T> {\n   public:\n\
    \    using Graph<T>::Graph;\n    using Graph<T>::g;\n    Graph<T> rg;\n\n    V<int>\
    \ vs, cmp, vis;\n    VV<int> comps;\n\n    // allow multiple edges\n    Graph<T>\
    \ g_comp;\n\n    void dfs(int v) {\n        vis[v] = true;\n\n        for (auto\
    \ e : g[v]) {\n            if (!vis[e.to]) {\n                dfs(e.to);\n   \
    \         }\n        }\n\n        vs.push_back(v);\n    }\n\n    void rdfs(int\
    \ v, int k) {\n        vis[v] = true;\n        cmp[v] = k;\n\n        for (auto\
    \ e : rg[v]) {\n            if (!vis[e.to]) {\n                rdfs(e.to, k);\n\
    \            }\n        }\n    }\n\n    void init() {\n        int n = g.size();\n\
    \        rg = Graph<T>(n);\n        rep(i, n) {\n            for (auto e : g[i])\
    \ {\n                rg.add_directed_edge(e.to, e.from, e.cost);\n           \
    \ }\n        }\n\n        vs.clear();\n        cmp = V<int>(n);\n        vis =\
    \ V<int>(n);\n\n        rep(v, n) if (!vis[v]) dfs(v);\n\n        fill(vis.begin(),\
    \ vis.end(), false);\n\n        int k = 0;\n        reverse(vs.begin(), vs.end());\n\
    \n        for (int v : vs) {\n            if (!vis[v]) {\n                rdfs(v,\
    \ k++);\n            }\n        }\n\n        comps.resize(k);\n        rep(v,\
    \ n) { comps[cmp[v]].push_back(v); }\n\n        g_comp = Graph<T>(k);\n\n    \
    \    rep(i, n) {\n            for (auto e : g[i]) {\n                if (cmp[i]\
    \ != cmp[e.to]) {\n                    g_comp.add_directed_edge(cmp[i], cmp[e.to],\
    \ e.cost);\n                }\n            }\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/SCC.hpp
  requiredBy: []
  timestamp: '2022-05-22 15:10:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/scc.test.cpp
documentation_of: cpp_src/graph/SCC.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/SCC.hpp
- /library/cpp_src/graph/SCC.hpp.html
title: cpp_src/graph/SCC.hpp
---
