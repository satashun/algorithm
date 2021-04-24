---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: cpp_src/graph/GraphBase.hpp
    title: cpp_src/graph/GraphBase.hpp
  _extendedRequiredBy: []
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
    \ add_edge(int a, int b, T c) = 0;\n};\n#line 2 \"cpp_src/graph/Ttree.hpp\"\n\n\
    template <class T>\nclass forest : public Graph<T> {\n   public:\n    using Graph<T>::g;\n\
    \    using Graph<T>::edges;\n    forest = default;\n    forest(int n) : g(n){};\n\
    };\n"
  code: "#include \"GraphBase.hpp\"\n\ntemplate <class T>\nclass forest : public Graph<T>\
    \ {\n   public:\n    using Graph<T>::g;\n    using Graph<T>::edges;\n    forest\
    \ = default;\n    forest(int n) : g(n){};\n};"
  dependsOn:
  - cpp_src/graph/GraphBase.hpp
  isVerificationFile: false
  path: cpp_src/graph/Ttree.hpp
  requiredBy: []
  timestamp: '2021-04-24 23:46:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/Ttree.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/Ttree.hpp
- /library/cpp_src/graph/Ttree.hpp.html
title: cpp_src/graph/Ttree.hpp
---
