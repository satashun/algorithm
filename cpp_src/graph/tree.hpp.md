---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: cpp_src/graph/graph_template.hpp
    title: cpp_src/graph/graph_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
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
    };\n#line 2 \"cpp_src/graph/tree.hpp\"\n\ntemplate <class T>\nclass forest : public\
    \ Graph<T> {\n   public:\n    using Graph<T>::g;\n    using Graph<T>::edges;\n\
    \    forest = default;\n    forest(int n) : g(n){};\n};\n"
  code: "#include \"graph_template.hpp\"\n\ntemplate <class T>\nclass forest : public\
    \ Graph<T> {\n   public:\n    using Graph<T>::g;\n    using Graph<T>::edges;\n\
    \    forest = default;\n    forest(int n) : g(n){};\n};"
  dependsOn:
  - cpp_src/graph/graph_template.hpp
  isVerificationFile: false
  path: cpp_src/graph/tree.hpp
  requiredBy: []
  timestamp: '2020-12-31 16:46:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/tree.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/tree.hpp
- /library/cpp_src/graph/tree.hpp.html
title: cpp_src/graph/tree.hpp
---
