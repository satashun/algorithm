---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/graph/FordFulkerson.cpp\"\nstruct FordFulkerson\
    \ {\n    static constexpr int INF = TEN(9);\n\n    struct edge {\n        int\
    \ to, cap, rev;\n    };\n\n    int n;\n    VV<edge> g;\n    V<bool> used;\n\n\
    \    FordFulkerson(int n) : n(n), g(n), used(n) {}\n\n    void add_edge(int from,\
    \ int to, int cap, int rcap) {\n        g[from].push_back((edge){to, cap, (int)g[to].size()});\n\
    \        g[to].push_back((edge){from, rcap, (int)g[from].size() - 1});\n    }\n\
    \n    int dfs(int v, int t, int f) {\n        if (v == t) return f;\n        used[v]\
    \ = true;\n        for (auto& e : g[v]) {\n            if (!used[e.to] && e.cap\
    \ > 0) {\n                int d = dfs(e.to, t, min(f, e.cap));\n             \
    \   if (d > 0) {\n                    e.cap -= d;\n                    g[e.to][e.rev].cap\
    \ += d;\n                    return d;\n                }\n            }\n   \
    \     }\n        return 0;\n    }\n\n    int max_flow(int s, int t) {\n      \
    \  int flow = 0;\n        while (1) {\n            fill(used.begin(), used.end(),\
    \ false);\n            int f = dfs(s, t, INF);\n            if (f == 0) return\
    \ flow;\n            flow += f;\n        }\n    }\n};\n"
  code: "struct FordFulkerson {\n    static constexpr int INF = TEN(9);\n\n    struct\
    \ edge {\n        int to, cap, rev;\n    };\n\n    int n;\n    VV<edge> g;\n \
    \   V<bool> used;\n\n    FordFulkerson(int n) : n(n), g(n), used(n) {}\n\n   \
    \ void add_edge(int from, int to, int cap, int rcap) {\n        g[from].push_back((edge){to,\
    \ cap, (int)g[to].size()});\n        g[to].push_back((edge){from, rcap, (int)g[from].size()\
    \ - 1});\n    }\n\n    int dfs(int v, int t, int f) {\n        if (v == t) return\
    \ f;\n        used[v] = true;\n        for (auto& e : g[v]) {\n            if\
    \ (!used[e.to] && e.cap > 0) {\n                int d = dfs(e.to, t, min(f, e.cap));\n\
    \                if (d > 0) {\n                    e.cap -= d;\n             \
    \       g[e.to][e.rev].cap += d;\n                    return d;\n            \
    \    }\n            }\n        }\n        return 0;\n    }\n\n    int max_flow(int\
    \ s, int t) {\n        int flow = 0;\n        while (1) {\n            fill(used.begin(),\
    \ used.end(), false);\n            int f = dfs(s, t, INF);\n            if (f\
    \ == 0) return flow;\n            flow += f;\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/FordFulkerson.cpp
  requiredBy: []
  timestamp: '2022-05-08 14:32:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/FordFulkerson.cpp
layout: document
redirect_from:
- /library/cpp_src/graph/FordFulkerson.cpp
- /library/cpp_src/graph/FordFulkerson.cpp.html
title: cpp_src/graph/FordFulkerson.cpp
---
