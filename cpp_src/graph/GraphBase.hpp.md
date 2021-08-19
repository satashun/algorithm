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
  bundledCode: "#line 2 \"cpp_src/graph/GraphBase.hpp\"\n\ntemplate <class T>\nclass\
    \ Edge {\n   public:\n    int from, to, idx;\n    T cost;\n\n    Edge() = default;\n\
    \    Edge(int from, int to, T cost = T(1), int idx = -1)\n        : from(from),\
    \ to(to), cost(cost), idx(idx) {}\n    operator int() const { return to; }\n};\n\
    \ntemplate <class T>\nclass Graph {\n   public:\n    using E = Edge<T>;\n    vector<vector<E>>\
    \ g;\n    vector<E> edges;\n    int sz, es;\n\n    Graph() {}\n    Graph(int n)\
    \ : sz(n), g(n), edges(0), es(0){};\n\n    virtual void add_directed_edge(int\
    \ from, int to, T cost = 1) {\n        g[from].emplace_back(from, to, cost, es++);\n\
    \    }\n\n    virtual void add_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n\n\
    \    void read(int M, int offset = -1, bool directed = false,\n              bool\
    \ weighted = false) {\n        for (int i = 0; i < M; i++) {\n            int\
    \ a, b;\n            cin >> a >> b;\n            a += offset;\n            b +=\
    \ offset;\n            T c = T(1);\n            if (weighted) cin >> c;\n    \
    \        edges.emplace_back(a, b, c);\n            if (directed)\n           \
    \     add_directed_edge(a, b, c);\n            else\n                add_edge(a,\
    \ b, c);\n        }\n    }\n};\n"
  code: "#pragma once\n\ntemplate <class T>\nclass Edge {\n   public:\n    int from,\
    \ to, idx;\n    T cost;\n\n    Edge() = default;\n    Edge(int from, int to, T\
    \ cost = T(1), int idx = -1)\n        : from(from), to(to), cost(cost), idx(idx)\
    \ {}\n    operator int() const { return to; }\n};\n\ntemplate <class T>\nclass\
    \ Graph {\n   public:\n    using E = Edge<T>;\n    vector<vector<E>> g;\n    vector<E>\
    \ edges;\n    int sz, es;\n\n    Graph() {}\n    Graph(int n) : sz(n), g(n), edges(0),\
    \ es(0){};\n\n    virtual void add_directed_edge(int from, int to, T cost = 1)\
    \ {\n        g[from].emplace_back(from, to, cost, es++);\n    }\n\n    virtual\
    \ void add_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n\n\
    \    void read(int M, int offset = -1, bool directed = false,\n              bool\
    \ weighted = false) {\n        for (int i = 0; i < M; i++) {\n            int\
    \ a, b;\n            cin >> a >> b;\n            a += offset;\n            b +=\
    \ offset;\n            T c = T(1);\n            if (weighted) cin >> c;\n    \
    \        edges.emplace_back(a, b, c);\n            if (directed)\n           \
    \     add_directed_edge(a, b, c);\n            else\n                add_edge(a,\
    \ b, c);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/GraphBase.hpp
  requiredBy: []
  timestamp: '2021-08-18 21:00:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/GraphBase.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/GraphBase.hpp
- /library/cpp_src/graph/GraphBase.hpp.html
title: cpp_src/graph/GraphBase.hpp
---
