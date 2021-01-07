---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: cpp_src/graph/tree.hpp
    title: cpp_src/graph/tree.hpp
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"cpp_src/graph/graph_template.hpp\"\n\ntemplate <class T>\n\
    class Edge {\n    int from, to;\n    T cost;\n\n    Edge() = default;\n    Edge(int\
    \ from, int to, T cost = T(1), int idx = -1)\n        : from(from), to(to), cost(cost),\
    \ idx(idx) {}\n};\n\ntemplate <class T>\nclass Graph {\n   public:\n    using\
    \ E = Edge<T>;\n    vector<vector<E>> > g;\n    vector<E> edges;\n\n    Graph()\
    \ = default;\n    Graph(int n) : g(n), edges(0){};\n\n    virtual void add_edge(int\
    \ a, int b, T c);\n    /*\n        void add_edge(int a, int b, T c = T(1), bool\
    \ directed = false) {\n            int id = (int)edges.size();\n            g[a].emplace_back(a,\
    \ b, c);\n            if (!directed) g[b].emplace_back(b, a, c);\n        }*/\n\
    };\n"
  code: "#pragma once\n\ntemplate <class T>\nclass Edge {\n    int from, to;\n   \
    \ T cost;\n\n    Edge() = default;\n    Edge(int from, int to, T cost = T(1),\
    \ int idx = -1)\n        : from(from), to(to), cost(cost), idx(idx) {}\n};\n\n\
    template <class T>\nclass Graph {\n   public:\n    using E = Edge<T>;\n    vector<vector<E>>\
    \ > g;\n    vector<E> edges;\n\n    Graph() = default;\n    Graph(int n) : g(n),\
    \ edges(0){};\n\n    virtual void add_edge(int a, int b, T c);\n    /*\n     \
    \   void add_edge(int a, int b, T c = T(1), bool directed = false) {\n       \
    \     int id = (int)edges.size();\n            g[a].emplace_back(a, b, c);\n \
    \           if (!directed) g[b].emplace_back(b, a, c);\n        }*/\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/graph_template.hpp
  requiredBy:
  - cpp_src/graph/tree.hpp
  timestamp: '2020-12-31 16:46:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/graph_template.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/graph_template.hpp
- /library/cpp_src/graph/graph_template.hpp.html
title: cpp_src/graph/graph_template.hpp
---
