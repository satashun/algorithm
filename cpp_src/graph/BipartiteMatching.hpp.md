---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"cpp_src/graph/BipartiteMatching.hpp\"\n//O(NM)\nstruct bipartite_matching\
    \ {\n    int n;\n    VV<int> g;\n    V<int> match;\n    V<bool> used;\n    bipartite_matching()\
    \ {}\n    bipartite_matching(int n) : n(n), g(n), match(n), used(n) {}\n\n   \
    \ void add_edge(int u, int v) {\n        g[u].push_back(v);\n        g[v].push_back(u);\n\
    \    }\n\n    bool dfs(int v) {\n        used[v] = true;\n\n        for (int u\
    \ : g[v]) {\n            int w = match[u];\n            if (w < 0 || (!used[w]\
    \ && dfs(w))) {\n                match[v] = u;\n                match[u] = v;\n\
    \                return true;\n            }\n        }\n\n        return false;\n\
    \    }\n\n    int calc() {\n        int res = 0;\n        fill(match.begin(),\
    \ match.end(), -1);\n\n        for (int v = 0; v < n; ++v) {\n            if (match[v]\
    \ < 0) {\n                fill(used.begin(), used.end(), false);\n           \
    \     res += dfs(v);\n            }\n        }\n        return res;\n    }\n};\n"
  code: "//O(NM)\nstruct bipartite_matching {\n    int n;\n    VV<int> g;\n    V<int>\
    \ match;\n    V<bool> used;\n    bipartite_matching() {}\n    bipartite_matching(int\
    \ n) : n(n), g(n), match(n), used(n) {}\n\n    void add_edge(int u, int v) {\n\
    \        g[u].push_back(v);\n        g[v].push_back(u);\n    }\n\n    bool dfs(int\
    \ v) {\n        used[v] = true;\n\n        for (int u : g[v]) {\n            int\
    \ w = match[u];\n            if (w < 0 || (!used[w] && dfs(w))) {\n          \
    \      match[v] = u;\n                match[u] = v;\n                return true;\n\
    \            }\n        }\n\n        return false;\n    }\n\n    int calc() {\n\
    \        int res = 0;\n        fill(match.begin(), match.end(), -1);\n\n     \
    \   for (int v = 0; v < n; ++v) {\n            if (match[v] < 0) {\n         \
    \       fill(used.begin(), used.end(), false);\n                res += dfs(v);\n\
    \            }\n        }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/BipartiteMatching.hpp
  requiredBy: []
  timestamp: '2020-07-17 17:36:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/BipartiteMatching.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/BipartiteMatching.hpp
- /library/cpp_src/graph/BipartiteMatching.hpp.html
title: cpp_src/graph/BipartiteMatching.hpp
---
