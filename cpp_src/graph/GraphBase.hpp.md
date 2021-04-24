---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: cpp_src/graph/Ttree.hpp
    title: cpp_src/graph/Ttree.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"cpp_src/graph/GraphBase.hpp\"\n\ntemplate <class T>\nclass\
    \ Edge {\n    int from, to;\n    T cost;\n\n    Edge() = default;\n    Edge(int\
    \ from, int to, T cost = T(1), int idx = -1)\n        : from(from), to(to), cost(cost),\
    \ idx(idx) {}\n};\n\ntemplate <class T>\nclass Graph {\n   public:\n    using\
    \ E = Edge<T>;\n    vector<vector<E>> > g;\n    vector<E> edges;\n    int sz;\n\
    \n    Graph() {}\n    Graph(int n) : sz(n), g(n), edges(0){};\n\n    virtual void\
    \ add_edge(int a, int b, T c) = 0;\n};\n"
  code: "#pragma once\n\ntemplate <class T>\nclass Edge {\n    int from, to;\n   \
    \ T cost;\n\n    Edge() = default;\n    Edge(int from, int to, T cost = T(1),\
    \ int idx = -1)\n        : from(from), to(to), cost(cost), idx(idx) {}\n};\n\n\
    template <class T>\nclass Graph {\n   public:\n    using E = Edge<T>;\n    vector<vector<E>>\
    \ > g;\n    vector<E> edges;\n    int sz;\n\n    Graph() {}\n    Graph(int n)\
    \ : sz(n), g(n), edges(0){};\n\n    virtual void add_edge(int a, int b, T c) =\
    \ 0;\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/GraphBase.hpp
  requiredBy:
  - cpp_src/graph/Ttree.hpp
  timestamp: '2021-04-24 23:46:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/GraphBase.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/GraphBase.hpp
- /library/cpp_src/graph/GraphBase.hpp.html
title: cpp_src/graph/GraphBase.hpp
---
