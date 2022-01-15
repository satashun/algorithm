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
  bundledCode: "#line 1 \"cpp_src/graph/helper/GetPath.hpp\"\n// ABC233F\n// pick\
    \ a path from a to b : O(n)\ntemplate <class T>\nV<pair<int, Edge<T>>> get_path(const\
    \ Graph<T>& g, int a, int b) {\n    using E = Edge<T>;\n\n    int n = g.size();\n\
    \    V<int> par(n, -1);\n    V<E> par_edge(n);\n    auto rec = [&](auto&& f, int\
    \ v, int p, E pe) -> void {\n        par[v] = p;\n        par_edge[v] = pe;\n\
    \        for (auto e : g[v]) {\n            if (e.to == p) continue;\n       \
    \     f(f, e.to, v, e);\n        }\n    };\n    rec(rec, a, -1, E());\n    if\
    \ (par[b] == -1) return {};\n    V<pair<int, E>> vec;\n    int cur = b;\n    while\
    \ (cur != a) {\n        vec.emplace_back(par[cur], par_edge[cur]);\n        cur\
    \ = par[cur];\n    }\n    reverse(ALL(vec));\n    return vec;\n}\n"
  code: "// ABC233F\n// pick a path from a to b : O(n)\ntemplate <class T>\nV<pair<int,\
    \ Edge<T>>> get_path(const Graph<T>& g, int a, int b) {\n    using E = Edge<T>;\n\
    \n    int n = g.size();\n    V<int> par(n, -1);\n    V<E> par_edge(n);\n    auto\
    \ rec = [&](auto&& f, int v, int p, E pe) -> void {\n        par[v] = p;\n   \
    \     par_edge[v] = pe;\n        for (auto e : g[v]) {\n            if (e.to ==\
    \ p) continue;\n            f(f, e.to, v, e);\n        }\n    };\n    rec(rec,\
    \ a, -1, E());\n    if (par[b] == -1) return {};\n    V<pair<int, E>> vec;\n \
    \   int cur = b;\n    while (cur != a) {\n        vec.emplace_back(par[cur], par_edge[cur]);\n\
    \        cur = par[cur];\n    }\n    reverse(ALL(vec));\n    return vec;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/helper/GetPath.hpp
  requiredBy: []
  timestamp: '2022-01-15 23:16:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/helper/GetPath.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/helper/GetPath.hpp
- /library/cpp_src/graph/helper/GetPath.hpp.html
title: cpp_src/graph/helper/GetPath.hpp
---
