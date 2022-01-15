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
  bundledCode: "#line 1 \"cpp_src/graph/helper/BFSPath.hpp\"\n// ABC218F\n// dfs tree\
    \ only with shortest paths\ntemplate <class T>\ntuple<V<T>, V<int>, V<Edge<T>>>\
    \ bfs_with_path(const Graph<T>& g, int s = 0,\n                              \
    \                int ban = -1) {\n    using E = Edge<T>;\n    const T inf = numeric_limits<T>::max()\
    \ / 2;\n    int n = g.size();\n\n    V<T> ds(n, inf);\n    using P = pair<T, int>;\n\
    \    queue<int> que;\n    que.push(s);\n    ds[s] = 0;\n    V<int> par(n, -1);\n\
    \    V<E> par_edge(n);\n\n    while (!que.empty()) {\n        auto v = que.front();\n\
    \        que.pop();\n        for (auto e : g[v]) {\n            if (e.idx == ban)\
    \ continue;\n            T nx = ds[v] + 1;\n            if (ds[e.to] > nx) {\n\
    \                par[e.to] = v;\n                par_edge[e.to] = e;\n       \
    \         ds[e.to] = nx;\n                que.push(e.to);\n            }\n   \
    \     }\n    }\n\n    for (auto& x : ds)\n        if (x == inf) x = -1;\n    return\
    \ make_tuple(ds, par, par_edge);\n}\n"
  code: "// ABC218F\n// dfs tree only with shortest paths\ntemplate <class T>\ntuple<V<T>,\
    \ V<int>, V<Edge<T>>> bfs_with_path(const Graph<T>& g, int s = 0,\n          \
    \                                    int ban = -1) {\n    using E = Edge<T>;\n\
    \    const T inf = numeric_limits<T>::max() / 2;\n    int n = g.size();\n\n  \
    \  V<T> ds(n, inf);\n    using P = pair<T, int>;\n    queue<int> que;\n    que.push(s);\n\
    \    ds[s] = 0;\n    V<int> par(n, -1);\n    V<E> par_edge(n);\n\n    while (!que.empty())\
    \ {\n        auto v = que.front();\n        que.pop();\n        for (auto e :\
    \ g[v]) {\n            if (e.idx == ban) continue;\n            T nx = ds[v] +\
    \ 1;\n            if (ds[e.to] > nx) {\n                par[e.to] = v;\n     \
    \           par_edge[e.to] = e;\n                ds[e.to] = nx;\n            \
    \    que.push(e.to);\n            }\n        }\n    }\n\n    for (auto& x : ds)\n\
    \        if (x == inf) x = -1;\n    return make_tuple(ds, par, par_edge);\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/helper/BFSPath.hpp
  requiredBy: []
  timestamp: '2022-01-15 23:16:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/helper/BFSPath.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/helper/BFSPath.hpp
- /library/cpp_src/graph/helper/BFSPath.hpp.html
title: cpp_src/graph/helper/BFSPath.hpp
---
