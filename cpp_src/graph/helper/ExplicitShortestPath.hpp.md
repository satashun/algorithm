---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/shortest_path.test.cpp
    title: test/yosupo/shortest_path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"cpp_src/graph/helper/ExplicitShortestPath.hpp\"\n// ABC222E\n\
    // ABC218F\n// dfs tree only with shortest paths\ntemplate <class T>\ntuple<V<T>,\
    \ V<int>, V<Edge<T>>> bfs_with_path(const Graph<T>& g, int s = 0,\n          \
    \                                    int ban = -1) {\n    using E = Edge<T>;\n\
    \    const T inf = numeric_limits<T>::max() / 2;\n    int n = g.size();\n\n  \
    \  V<T> ds(n, inf);\n    using P = pair<T, int>;\n    queue<int> que;\n    que.push(s);\n\
    \    ds[s] = 0;\n    V<int> par(n, -1);\n    V<E> par_edge(n);\n\n    while (!que.empty())\
    \ {\n        auto v = que.front();\n        que.pop();\n        for (auto e :\
    \ g[v]) {\n            if (e.idx == ban) continue;\n            T nx = ds[v] +\
    \ e.cost;\n            if (ds[e.to] > nx) {\n                par[e.to] = v;\n\
    \                par_edge[e.to] = e;\n                ds[e.to] = nx;\n       \
    \         que.push(e.to);\n            }\n        }\n    }\n\n    for (auto& x\
    \ : ds)\n        if (x == inf) x = -1;\n    return make_tuple(ds, par, par_edge);\n\
    }\n\n// https://judge.yosupo.jp/problem/shortest_path\ntemplate <class T>\ntuple<V<T>,\
    \ V<int>, V<Edge<T>>> dijkstra_with_path(const Graph<T>& g, int s = 0,\n     \
    \                                              int ban = -1) {\n    using E =\
    \ Edge<T>;\n    const T inf = numeric_limits<T>::max() / 2;\n    int n = g.size();\n\
    \n    V<T> ds(n, inf);\n    using P = pair<T, int>;\n    priority_queue<P, V<P>,\
    \ greater<P>> que;\n    que.emplace(0, s);\n    ds[s] = 0;\n\n    V<int> par(n,\
    \ -1);\n    V<E> par_edge(n);\n\n    while (!que.empty()) {\n        auto p =\
    \ que.top();\n        que.pop();\n        int v = p.se;\n        if (ds[v] < p.fi)\
    \ continue;\n        for (auto e : g[v]) {\n            T nx = ds[v] + e.cost;\n\
    \            if (ds[e.to] > nx) {\n                ds[e.to] = nx;\n          \
    \      par[e.to] = v;\n                par_edge[e.to] = e;\n                que.emplace(nx,\
    \ e.to);\n            }\n        }\n    }\n\n    for (auto& x : ds)\n        if\
    \ (x == inf) x = -1;\n    return make_tuple(ds, par, par_edge);\n}\n"
  code: "// ABC222E\n// ABC218F\n// dfs tree only with shortest paths\ntemplate <class\
    \ T>\ntuple<V<T>, V<int>, V<Edge<T>>> bfs_with_path(const Graph<T>& g, int s =\
    \ 0,\n                                              int ban = -1) {\n    using\
    \ E = Edge<T>;\n    const T inf = numeric_limits<T>::max() / 2;\n    int n = g.size();\n\
    \n    V<T> ds(n, inf);\n    using P = pair<T, int>;\n    queue<int> que;\n   \
    \ que.push(s);\n    ds[s] = 0;\n    V<int> par(n, -1);\n    V<E> par_edge(n);\n\
    \n    while (!que.empty()) {\n        auto v = que.front();\n        que.pop();\n\
    \        for (auto e : g[v]) {\n            if (e.idx == ban) continue;\n    \
    \        T nx = ds[v] + e.cost;\n            if (ds[e.to] > nx) {\n          \
    \      par[e.to] = v;\n                par_edge[e.to] = e;\n                ds[e.to]\
    \ = nx;\n                que.push(e.to);\n            }\n        }\n    }\n\n\
    \    for (auto& x : ds)\n        if (x == inf) x = -1;\n    return make_tuple(ds,\
    \ par, par_edge);\n}\n\n// https://judge.yosupo.jp/problem/shortest_path\ntemplate\
    \ <class T>\ntuple<V<T>, V<int>, V<Edge<T>>> dijkstra_with_path(const Graph<T>&\
    \ g, int s = 0,\n                                                   int ban =\
    \ -1) {\n    using E = Edge<T>;\n    const T inf = numeric_limits<T>::max() /\
    \ 2;\n    int n = g.size();\n\n    V<T> ds(n, inf);\n    using P = pair<T, int>;\n\
    \    priority_queue<P, V<P>, greater<P>> que;\n    que.emplace(0, s);\n    ds[s]\
    \ = 0;\n\n    V<int> par(n, -1);\n    V<E> par_edge(n);\n\n    while (!que.empty())\
    \ {\n        auto p = que.top();\n        que.pop();\n        int v = p.se;\n\
    \        if (ds[v] < p.fi) continue;\n        for (auto e : g[v]) {\n        \
    \    T nx = ds[v] + e.cost;\n            if (ds[e.to] > nx) {\n              \
    \  ds[e.to] = nx;\n                par[e.to] = v;\n                par_edge[e.to]\
    \ = e;\n                que.emplace(nx, e.to);\n            }\n        }\n   \
    \ }\n\n    for (auto& x : ds)\n        if (x == inf) x = -1;\n    return make_tuple(ds,\
    \ par, par_edge);\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/helper/ExplicitShortestPath.hpp
  requiredBy: []
  timestamp: '2022-05-08 14:32:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/shortest_path.test.cpp
documentation_of: cpp_src/graph/helper/ExplicitShortestPath.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/helper/ExplicitShortestPath.hpp
- /library/cpp_src/graph/helper/ExplicitShortestPath.hpp.html
title: cpp_src/graph/helper/ExplicitShortestPath.hpp
---
