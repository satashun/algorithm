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
  bundledCode: "#line 1 \"cpp_src/graph/helper/RevGraph.hpp\"\n// ABC209E, ABC261H\n\
    template <class T>\nGraph<T> rev_graph(const Graph<T>& g) {\n    int n = g.size();\n\
    \    Graph<T> rg(n);\n    rep(i, n) {\n        for (auto e : g[i]) {\n       \
    \     swap(e.from, e.to);\n            rg[e.from].pb(e);\n        }\n    }\n \
    \   return rg;\n}\n"
  code: "// ABC209E, ABC261H\ntemplate <class T>\nGraph<T> rev_graph(const Graph<T>&\
    \ g) {\n    int n = g.size();\n    Graph<T> rg(n);\n    rep(i, n) {\n        for\
    \ (auto e : g[i]) {\n            swap(e.from, e.to);\n            rg[e.from].pb(e);\n\
    \        }\n    }\n    return rg;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/helper/RevGraph.hpp
  requiredBy: []
  timestamp: '2022-12-31 14:31:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/helper/RevGraph.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/helper/RevGraph.hpp
- /library/cpp_src/graph/helper/RevGraph.hpp.html
title: cpp_src/graph/helper/RevGraph.hpp
---
