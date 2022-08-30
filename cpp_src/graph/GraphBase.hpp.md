---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: cpp_src/graph/EulerianTrail.hpp
    title: Eulerian Trail
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lca.test.cpp
    title: test/yosupo/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/scc.test.cpp
    title: test/yosupo/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/shortest_path.test.cpp
    title: test/yosupo/shortest_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two_edge_connected_components.test.cpp
    title: test/yosupo/two_edge_connected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yukicoder-583.test.cpp
    title: test/yukicoder/yukicoder-583.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/graph/GraphBase.hpp\"\ntemplate <class T>\nclass\
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
    \        else\n                add_edge(a, b, c);\n        }\n    }\n};\n"
  code: "template <class T>\nclass Edge {\n   public:\n    int from, to, idx;\n  \
    \  T cost;\n\n    Edge() = default;\n    Edge(int from, int to, T cost = T(1),\
    \ int idx = -1)\n        : from(from), to(to), cost(cost), idx(idx) {}\n    operator\
    \ int() const { return to; }\n\n    bool operator<(const Edge& e) const { return\
    \ cost < e.cost; }\n};\n\ntemplate <class T>\nclass Graph {\n   public:\n    using\
    \ E = Edge<T>;\n    vector<vector<E>> g;\n    vector<E> edges;\n    int es;\n\n\
    \    Graph() {}\n    Graph(int n) : g(n), edges(0), es(0){};\n\n    int size()\
    \ const { return g.size(); }\n\n    virtual void add_directed_edge(int from, int\
    \ to, T cost = 1) {\n        g[from].emplace_back(from, to, cost, es++);\n   \
    \ }\n\n    virtual void add_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n\n\
    \    inline vector<E>& operator[](const int& k) { return g[k]; }\n\n    inline\
    \ const vector<E>& operator[](const int& k) const {\n        return g[k];\n  \
    \  }\n\n    void read(int M, int offset = -1, bool directed = false,\n       \
    \       bool weighted = false) {\n        for (int i = 0; i < M; i++) {\n    \
    \        int a, b;\n            cin >> a >> b;\n            a += offset;\n   \
    \         b += offset;\n            T c = T(1);\n            if (weighted) cin\
    \ >> c;\n            edges.emplace_back(a, b, c);\n            if (directed)\n\
    \                add_directed_edge(a, b, c);\n            else\n             \
    \   add_edge(a, b, c);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/GraphBase.hpp
  requiredBy:
  - cpp_src/graph/EulerianTrail.hpp
  timestamp: '2022-07-02 19:40:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yukicoder-583.test.cpp
  - test/yosupo/two_edge_connected_components.test.cpp
  - test/yosupo/shortest_path.test.cpp
  - test/yosupo/scc.test.cpp
  - test/yosupo/lca.test.cpp
documentation_of: cpp_src/graph/GraphBase.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/GraphBase.hpp
- /library/cpp_src/graph/GraphBase.hpp.html
title: cpp_src/graph/GraphBase.hpp
---
