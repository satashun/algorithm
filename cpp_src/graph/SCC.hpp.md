---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/scc.test.cpp
    title: test/yosupo/scc.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/graph/SCC.hpp\"\nstruct SCC {\n    int n;\n    VV<int>\
    \ g, rg;\n    V<int> vs, cmp;\n    V<bool> vis;\n\n    SCC(){}\n    SCC(int n)\
    \ : n(n) {\n        g = rg = VV<int>(n);\n        vs = cmp = V<int>(n);\n    \
    \    vis = V<bool>(n);\n    }\n\n    void add_edge(int from, int to) {\n     \
    \   g[from].push_back(to);\n        rg[to].push_back(from);\n    }\n\n    void\
    \ dfs(int v) {\n        vis[v] = true;\n\n        for (int to : g[v]) {\n    \
    \        if (!vis[to]) {\n                dfs(to);\n            }\n        }\n\
    \n        vs.push_back(v);\n    }\n\n    void rdfs(int v, int k, V<int>& vec)\
    \ {\n        vis[v] = true;\n        cmp[v] = k;\n        vec.push_back(v);\n\n\
    \        for (int to : rg[v]) {\n            if (!vis[to]) {\n               \
    \ rdfs(to, k, vec);\n            }\n        }\n    }\n\n    VV<int> calc() {\n\
    \        rep(v, n) if (!vis[v]) dfs(v);\n\n        fill(vis.begin(), vis.end(),\
    \ false);\n\n        int k = 0;\n        reverse(vs.begin(), vs.end());\n\n  \
    \      VV<int> vcomp;\n\n        for (int v : vs) {\n            if (!vis[v])\
    \ {\n                V<int> vec;\n                rdfs(v, k++, vec);\n       \
    \         vcomp.push_back(vec);\n            }\n        }\n\n        return vcomp;\n\
    \    }\n};\n"
  code: "struct SCC {\n    int n;\n    VV<int> g, rg;\n    V<int> vs, cmp;\n    V<bool>\
    \ vis;\n\n    SCC(){}\n    SCC(int n) : n(n) {\n        g = rg = VV<int>(n);\n\
    \        vs = cmp = V<int>(n);\n        vis = V<bool>(n);\n    }\n\n    void add_edge(int\
    \ from, int to) {\n        g[from].push_back(to);\n        rg[to].push_back(from);\n\
    \    }\n\n    void dfs(int v) {\n        vis[v] = true;\n\n        for (int to\
    \ : g[v]) {\n            if (!vis[to]) {\n                dfs(to);\n         \
    \   }\n        }\n\n        vs.push_back(v);\n    }\n\n    void rdfs(int v, int\
    \ k, V<int>& vec) {\n        vis[v] = true;\n        cmp[v] = k;\n        vec.push_back(v);\n\
    \n        for (int to : rg[v]) {\n            if (!vis[to]) {\n              \
    \  rdfs(to, k, vec);\n            }\n        }\n    }\n\n    VV<int> calc() {\n\
    \        rep(v, n) if (!vis[v]) dfs(v);\n\n        fill(vis.begin(), vis.end(),\
    \ false);\n\n        int k = 0;\n        reverse(vs.begin(), vs.end());\n\n  \
    \      VV<int> vcomp;\n\n        for (int v : vs) {\n            if (!vis[v])\
    \ {\n                V<int> vec;\n                rdfs(v, k++, vec);\n       \
    \         vcomp.push_back(vec);\n            }\n        }\n\n        return vcomp;\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/SCC.hpp
  requiredBy: []
  timestamp: '2020-04-01 18:25:18+09:00'
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
