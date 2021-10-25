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
  bundledCode: "#line 2 \"cpp_src/graph/GraphBase.hpp\"\n\ntemplate <class T>\nclass\
    \ Edge {\n   public:\n    int from, to, idx;\n    T cost;\n\n    Edge() = default;\n\
    \    Edge(int from, int to, T cost = T(1), int idx = -1)\n        : from(from),\
    \ to(to), cost(cost), idx(idx) {}\n    operator int() const { return to; }\n\n\
    \    bool operator<(const Edge& e) const { return cost < e.cost; }\n};\n\ntemplate\
    \ <class T>\nclass Graph {\n   public:\n    using E = Edge<T>;\n    vector<vector<E>>\
    \ g;\n    vector<E> edges;\n    int es;\n\n    Graph() {}\n    Graph(int n) :\
    \ g(n), edges(0), es(0){};\n\n    int size() const { return g.size(); }\n\n  \
    \  virtual void add_directed_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es++);\n    }\n\n    virtual void add_edge(int from, int to, T cost\
    \ = 1) {\n        g[from].emplace_back(from, to, cost, es);\n        g[to].emplace_back(to,\
    \ from, cost, es++);\n    }\n\n    inline vector<E>& operator[](const int& k)\
    \ { return g[k]; }\n\n    inline const vector<E>& operator[](const int& k) const\
    \ {\n        return g[k];\n    }\n\n    void read(int M, int offset = -1, bool\
    \ directed = false,\n              bool weighted = false) {\n        for (int\
    \ i = 0; i < M; i++) {\n            int a, b;\n            cin >> a >> b;\n  \
    \          a += offset;\n            b += offset;\n            T c = T(1);\n \
    \           if (weighted) cin >> c;\n            edges.emplace_back(a, b, c);\n\
    \            if (directed)\n                add_directed_edge(a, b, c);\n    \
    \        else\n                add_edge(a, b, c);\n        }\n    }\n};\n\ntemplate\
    \ <class T>\nV<T> bfs(const Graph<T>& g, int s = 0) {\n    int n = g.size();\n\
    \    V<T> ds(n, numeric_limits<T>::max() / 2);\n    using P = pair<T, int>;\n\
    \    queue<int> que;\n    que.push(s);\n    ds[s] = 0;\n\n    while (!que.empty())\
    \ {\n        auto v = que.front();\n        que.pop();\n        for (auto e :\
    \ g[v]) {\n            T nx = ds[v] + 1;\n            if (ds[e.to] > nx) {\n \
    \               ds[e.to] = nx;\n                que.push(e.to);\n            }\n\
    \        }\n    }\n    return ds;\n}\n\ntemplate <class T>\nV<T> dijkstra(const\
    \ Graph<T>& g, int s = 0) {\n    int n = g.size();\n    V<T> ds(n, numeric_limits<T>::max()\
    \ / 2);\n    using P = pair<T, int>;\n    priority_queue<P, V<P>, greater<P>>\
    \ que;\n    que.emplace(0, s);\n    ds[s] = 0;\n    while (!que.empty()) {\n \
    \       auto p = que.top();\n        que.pop();\n        int v = p.se;\n     \
    \   if (ds[v] < p.fi) continue;\n        for (auto e : g[v]) {\n            T\
    \ nx = ds[v] + e.cost;\n            if (ds[e.to] > nx) {\n                ds[e.to]\
    \ = nx;\n                que.emplace(nx, e.to);\n            }\n        }\n  \
    \  }\n    return ds;\n}\n"
  code: "#pragma once\n\ntemplate <class T>\nclass Edge {\n   public:\n    int from,\
    \ to, idx;\n    T cost;\n\n    Edge() = default;\n    Edge(int from, int to, T\
    \ cost = T(1), int idx = -1)\n        : from(from), to(to), cost(cost), idx(idx)\
    \ {}\n    operator int() const { return to; }\n\n    bool operator<(const Edge&\
    \ e) const { return cost < e.cost; }\n};\n\ntemplate <class T>\nclass Graph {\n\
    \   public:\n    using E = Edge<T>;\n    vector<vector<E>> g;\n    vector<E> edges;\n\
    \    int es;\n\n    Graph() {}\n    Graph(int n) : g(n), edges(0), es(0){};\n\n\
    \    int size() const { return g.size(); }\n\n    virtual void add_directed_edge(int\
    \ from, int to, T cost = 1) {\n        g[from].emplace_back(from, to, cost, es++);\n\
    \    }\n\n    virtual void add_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n\n\
    \    inline vector<E>& operator[](const int& k) { return g[k]; }\n\n    inline\
    \ const vector<E>& operator[](const int& k) const {\n        return g[k];\n  \
    \  }\n\n    void read(int M, int offset = -1, bool directed = false,\n       \
    \       bool weighted = false) {\n        for (int i = 0; i < M; i++) {\n    \
    \        int a, b;\n            cin >> a >> b;\n            a += offset;\n   \
    \         b += offset;\n            T c = T(1);\n            if (weighted) cin\
    \ >> c;\n            edges.emplace_back(a, b, c);\n            if (directed)\n\
    \                add_directed_edge(a, b, c);\n            else\n             \
    \   add_edge(a, b, c);\n        }\n    }\n};\n\ntemplate <class T>\nV<T> bfs(const\
    \ Graph<T>& g, int s = 0) {\n    int n = g.size();\n    V<T> ds(n, numeric_limits<T>::max()\
    \ / 2);\n    using P = pair<T, int>;\n    queue<int> que;\n    que.push(s);\n\
    \    ds[s] = 0;\n\n    while (!que.empty()) {\n        auto v = que.front();\n\
    \        que.pop();\n        for (auto e : g[v]) {\n            T nx = ds[v] +\
    \ 1;\n            if (ds[e.to] > nx) {\n                ds[e.to] = nx;\n     \
    \           que.push(e.to);\n            }\n        }\n    }\n    return ds;\n\
    }\n\ntemplate <class T>\nV<T> dijkstra(const Graph<T>& g, int s = 0) {\n    int\
    \ n = g.size();\n    V<T> ds(n, numeric_limits<T>::max() / 2);\n    using P =\
    \ pair<T, int>;\n    priority_queue<P, V<P>, greater<P>> que;\n    que.emplace(0,\
    \ s);\n    ds[s] = 0;\n    while (!que.empty()) {\n        auto p = que.top();\n\
    \        que.pop();\n        int v = p.se;\n        if (ds[v] < p.fi) continue;\n\
    \        for (auto e : g[v]) {\n            T nx = ds[v] + e.cost;\n         \
    \   if (ds[e.to] > nx) {\n                ds[e.to] = nx;\n                que.emplace(nx,\
    \ e.to);\n            }\n        }\n    }\n    return ds;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/GraphBase.hpp
  requiredBy: []
  timestamp: '2021-10-25 19:28:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/lca.test.cpp
documentation_of: cpp_src/graph/GraphBase.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/GraphBase.hpp
- /library/cpp_src/graph/GraphBase.hpp.html
title: cpp_src/graph/GraphBase.hpp
---
