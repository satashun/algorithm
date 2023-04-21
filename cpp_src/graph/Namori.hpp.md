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
  bundledCode: "#line 1 \"cpp_src/graph/Namori.hpp\"\n// allow multiple components\n\
    // ABC266F, ABC296E\ntemplate <class T>\nclass Namori : public Graph<T> {\n  \
    \ public:\n    using Graph<T>::edges;\n    using Graph<T>::g;\n    using Graph<T>::Graph;\n\
    \    using E = Edge<T>;\n    using Graph<T>::es;\n\n    V<int> deg, par;\n   \
    \ VV<E> g2;  // g2 for tree from cycles\n    V<bool> vis;\n    VV<int> cycles;\n\
    \    V<int> rt;\n\n    Namori() {}\n    Namori(int n) : Graph<T>(n), g2(n) {\n\
    \        deg = V<int>(n);\n        par = V<int>(n, -1);\n        vis = V<bool>(n);\n\
    \        rt = V<int>(n);\n    }\n\n    void add_edge(int from, int to, T cost\
    \ = 1) {\n        g[from].emplace_back(from, to, cost, es);\n        g[to].emplace_back(to,\
    \ from, cost, es++);\n        ++deg[from], ++deg[to];\n    }\n\n    void dfs(int\
    \ v, V<int>& cycle) {\n        vis[v] = true;\n        cycle.pb(v);\n\n      \
    \  for (auto e : g[v]) {\n            if (deg[e.to] == 2 && !vis[e.to]) {\n  \
    \              dfs(e.to, cycle);\n            }\n        }\n    }\n\n    void\
    \ dfs2(int v, int p, int r) {\n        rt[v] = r;\n        for (auto e : g2[v])\
    \ {\n            if (e.to != p) {\n                dfs2(e.to, v, r);\n       \
    \     }\n        }\n    }\n\n    void build() {\n        queue<int> que;\n   \
    \     rep(i, g.size()) {\n            if (deg[i] == 1) {\n                que.push(i);\n\
    \            }\n        }\n\n        while (!que.empty()) {\n            int v\
    \ = que.front();\n            que.pop();\n            vis[v] = true;\n       \
    \     for (auto e : g[v]) {\n                auto re = e;\n                swap(re.from,\
    \ re.to);\n                if (deg[e.to] > 1) {\n                    g2[e.to].pb(re);\n\
    \                    par[v] = e.to;\n\n                    if (--deg[e.to] ==\
    \ 1) {\n                        que.push(e.to);\n                    }\n     \
    \           }\n            }\n        }\n\n        rep(i, g.size()) if (deg[i]\
    \ == 2 && !vis[i]) {\n            cycles.eb(V<int>{});\n            dfs(i, cycles.back());\n\
    \            V<int> cyc = cycles.back();\n            for (int v : cyc) {\n  \
    \              dfs2(v, -1, v);\n            }\n        }\n    }\n};\n"
  code: "// allow multiple components\n// ABC266F, ABC296E\ntemplate <class T>\nclass\
    \ Namori : public Graph<T> {\n   public:\n    using Graph<T>::edges;\n    using\
    \ Graph<T>::g;\n    using Graph<T>::Graph;\n    using E = Edge<T>;\n    using\
    \ Graph<T>::es;\n\n    V<int> deg, par;\n    VV<E> g2;  // g2 for tree from cycles\n\
    \    V<bool> vis;\n    VV<int> cycles;\n    V<int> rt;\n\n    Namori() {}\n  \
    \  Namori(int n) : Graph<T>(n), g2(n) {\n        deg = V<int>(n);\n        par\
    \ = V<int>(n, -1);\n        vis = V<bool>(n);\n        rt = V<int>(n);\n    }\n\
    \n    void add_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n        ++deg[from],\
    \ ++deg[to];\n    }\n\n    void dfs(int v, V<int>& cycle) {\n        vis[v] =\
    \ true;\n        cycle.pb(v);\n\n        for (auto e : g[v]) {\n            if\
    \ (deg[e.to] == 2 && !vis[e.to]) {\n                dfs(e.to, cycle);\n      \
    \      }\n        }\n    }\n\n    void dfs2(int v, int p, int r) {\n        rt[v]\
    \ = r;\n        for (auto e : g2[v]) {\n            if (e.to != p) {\n       \
    \         dfs2(e.to, v, r);\n            }\n        }\n    }\n\n    void build()\
    \ {\n        queue<int> que;\n        rep(i, g.size()) {\n            if (deg[i]\
    \ == 1) {\n                que.push(i);\n            }\n        }\n\n        while\
    \ (!que.empty()) {\n            int v = que.front();\n            que.pop();\n\
    \            vis[v] = true;\n            for (auto e : g[v]) {\n             \
    \   auto re = e;\n                swap(re.from, re.to);\n                if (deg[e.to]\
    \ > 1) {\n                    g2[e.to].pb(re);\n                    par[v] = e.to;\n\
    \n                    if (--deg[e.to] == 1) {\n                        que.push(e.to);\n\
    \                    }\n                }\n            }\n        }\n\n      \
    \  rep(i, g.size()) if (deg[i] == 2 && !vis[i]) {\n            cycles.eb(V<int>{});\n\
    \            dfs(i, cycles.back());\n            V<int> cyc = cycles.back();\n\
    \            for (int v : cyc) {\n                dfs2(v, -1, v);\n          \
    \  }\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/Namori.hpp
  requiredBy: []
  timestamp: '2023-04-22 00:40:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/Namori.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/Namori.hpp
- /library/cpp_src/graph/Namori.hpp.html
title: cpp_src/graph/Namori.hpp
---
