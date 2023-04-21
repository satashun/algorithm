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
  bundledCode: "#line 1 \"cpp_src/graph/helper/TopologicalSort.hpp\"\n// lexicographically\
    \ smallest\ntemplate <class T>\nV<int> topological_sort(const Graph<T>& g) {\n\
    \    int n = g.size();\n\n    priority_queue<int, V<int>, greater<int>> que;\n\
    \n    V<int> indeg(n);\n    rep(i, n) {\n        for (auto e : g[i]) {\n     \
    \       indeg[e.to]++;\n        }\n    }\n\n    rep(i, n) if (indeg[i] == 0) que.push(i);\n\
    \n    V<int> res;\n    while (!que.empty()) {\n        int v = que.top();\n  \
    \      que.pop();\n        res.pb(v);\n\n        for (auto e : g[v]) {\n     \
    \       if (--indeg[e.to] == 0) {\n                que.emplace(e.to);\n      \
    \      }\n        }\n    }\n\n    if (SZ(res) < n) return V<int>{};\n    return\
    \ res;\n}\n"
  code: "// lexicographically smallest\ntemplate <class T>\nV<int> topological_sort(const\
    \ Graph<T>& g) {\n    int n = g.size();\n\n    priority_queue<int, V<int>, greater<int>>\
    \ que;\n\n    V<int> indeg(n);\n    rep(i, n) {\n        for (auto e : g[i]) {\n\
    \            indeg[e.to]++;\n        }\n    }\n\n    rep(i, n) if (indeg[i] ==\
    \ 0) que.push(i);\n\n    V<int> res;\n    while (!que.empty()) {\n        int\
    \ v = que.top();\n        que.pop();\n        res.pb(v);\n\n        for (auto\
    \ e : g[v]) {\n            if (--indeg[e.to] == 0) {\n                que.emplace(e.to);\n\
    \            }\n        }\n    }\n\n    if (SZ(res) < n) return V<int>{};\n  \
    \  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/helper/TopologicalSort.hpp
  requiredBy: []
  timestamp: '2023-04-22 00:40:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/helper/TopologicalSort.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/helper/TopologicalSort.hpp
- /library/cpp_src/graph/helper/TopologicalSort.hpp.html
title: cpp_src/graph/helper/TopologicalSort.hpp
---
