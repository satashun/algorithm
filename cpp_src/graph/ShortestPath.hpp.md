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
  bundledCode: "#line 1 \"cpp_src/graph/ShortestPath.hpp\"\n// cost = 1 or tree\n\
    template <class T>\nV<T> bfs(const Graph<T>& g, int s = 0) {\n    const T inf\
    \ = numeric_limits<T>::max() / 2;\n    int n = g.size();\n\n    V<T> ds(n, inf);\n\
    \    queue<int> que;\n    que.push(s);\n    ds[s] = 0;\n\n    while (!que.empty())\
    \ {\n        auto v = que.front();\n        que.pop();\n        for (auto e :\
    \ g[v]) {\n            T nx = ds[v] + e.cost;\n            if (ds[e.to] > nx)\
    \ {\n                ds[e.to] = nx;\n                que.push(e.to);\n       \
    \     }\n        }\n    }\n    for (auto& x : ds)\n        if (x == inf) x = -1;\n\
    \    return ds;\n}\n\n// must be optimized\ntemplate <class T>\nV<T> bfs01(const\
    \ Graph<T>& g, int s = 0) {\n    const T inf = numeric_limits<T>::max() / 2;\n\
    \    int n = g.size();\n\n    V<T> ds(n, inf);\n    using P = pair<T, int>;\n\
    \    deque<int> que;\n    que.push_back(s);\n    ds[s] = 0;\n\n    while (!que.empty())\
    \ {\n        auto v = que.front();\n        que.pop_front();\n        for (auto\
    \ e : g[v]) {\n            T nx = ds[v] + e.cost;\n            if (ds[e.to] >\
    \ nx) {\n                ds[e.to] = nx;\n                if (e.cost == 0) {\n\
    \                    que.push_front(e.to);\n                } else {\n       \
    \             que.push_back(e.to);\n                }\n            }\n       \
    \ }\n    }\n    for (auto& x : ds)\n        if (x == inf) x = -1;\n    return\
    \ ds;\n}\n\ntemplate <class T>\nV<T> dijkstra(const Graph<T>& g, int s = 0) {\n\
    \    const T inf = numeric_limits<T>::max() / 2;\n    int n = g.size();\n\n  \
    \  V<T> ds(n, inf);\n    using P = pair<T, int>;\n    priority_queue<P, V<P>,\
    \ greater<P>> que;\n    que.emplace(0, s);\n    ds[s] = 0;\n    while (!que.empty())\
    \ {\n        auto p = que.top();\n        que.pop();\n        int v = p.se;\n\
    \        if (ds[v] < p.fi) continue;\n        for (auto e : g[v]) {\n        \
    \    T nx = ds[v] + e.cost;\n            if (ds[e.to] > nx) {\n              \
    \  ds[e.to] = nx;\n                que.emplace(nx, e.to);\n            }\n   \
    \     }\n    }\n    for (auto& x : ds)\n        if (x == inf) x = -1;\n    return\
    \ ds;\n}\n"
  code: "// cost = 1 or tree\ntemplate <class T>\nV<T> bfs(const Graph<T>& g, int\
    \ s = 0) {\n    const T inf = numeric_limits<T>::max() / 2;\n    int n = g.size();\n\
    \n    V<T> ds(n, inf);\n    queue<int> que;\n    que.push(s);\n    ds[s] = 0;\n\
    \n    while (!que.empty()) {\n        auto v = que.front();\n        que.pop();\n\
    \        for (auto e : g[v]) {\n            T nx = ds[v] + e.cost;\n         \
    \   if (ds[e.to] > nx) {\n                ds[e.to] = nx;\n                que.push(e.to);\n\
    \            }\n        }\n    }\n    for (auto& x : ds)\n        if (x == inf)\
    \ x = -1;\n    return ds;\n}\n\n// must be optimized\ntemplate <class T>\nV<T>\
    \ bfs01(const Graph<T>& g, int s = 0) {\n    const T inf = numeric_limits<T>::max()\
    \ / 2;\n    int n = g.size();\n\n    V<T> ds(n, inf);\n    using P = pair<T, int>;\n\
    \    deque<int> que;\n    que.push_back(s);\n    ds[s] = 0;\n\n    while (!que.empty())\
    \ {\n        auto v = que.front();\n        que.pop_front();\n        for (auto\
    \ e : g[v]) {\n            T nx = ds[v] + e.cost;\n            if (ds[e.to] >\
    \ nx) {\n                ds[e.to] = nx;\n                if (e.cost == 0) {\n\
    \                    que.push_front(e.to);\n                } else {\n       \
    \             que.push_back(e.to);\n                }\n            }\n       \
    \ }\n    }\n    for (auto& x : ds)\n        if (x == inf) x = -1;\n    return\
    \ ds;\n}\n\ntemplate <class T>\nV<T> dijkstra(const Graph<T>& g, int s = 0) {\n\
    \    const T inf = numeric_limits<T>::max() / 2;\n    int n = g.size();\n\n  \
    \  V<T> ds(n, inf);\n    using P = pair<T, int>;\n    priority_queue<P, V<P>,\
    \ greater<P>> que;\n    que.emplace(0, s);\n    ds[s] = 0;\n    while (!que.empty())\
    \ {\n        auto p = que.top();\n        que.pop();\n        int v = p.se;\n\
    \        if (ds[v] < p.fi) continue;\n        for (auto e : g[v]) {\n        \
    \    T nx = ds[v] + e.cost;\n            if (ds[e.to] > nx) {\n              \
    \  ds[e.to] = nx;\n                que.emplace(nx, e.to);\n            }\n   \
    \     }\n    }\n    for (auto& x : ds)\n        if (x == inf) x = -1;\n    return\
    \ ds;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/ShortestPath.hpp
  requiredBy: []
  timestamp: '2022-07-02 19:40:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/ShortestPath.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/ShortestPath.hpp
- /library/cpp_src/graph/ShortestPath.hpp.html
title: cpp_src/graph/ShortestPath.hpp
---
