---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bipartitematching.test.cpp
    title: test/yosupo/bipartitematching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/graph/Dinic.hpp\"\n// O(V^2 E)\nstruct Dinic {\n\
    \    using F = ll;\n    static constexpr F INF = numeric_limits<F>::max();\n\n\
    \    struct Edge {\n        int to, rev;\n        F cap;\n        Edge(int to,\
    \ F cap, int rev) : to(to), cap(cap), rev(rev){};\n    };\n\n    using E = Edge;\n\
    \n    VV<E> g;\n    V<int> level, iter;\n\n    Dinic() {}\n    Dinic(int n) :\
    \ g(n), level(n), iter(n) {}\n\n    void add_edge(int from, int to, F cap) {\n\
    \        g[from].emplace_back(to, cap, (int)g[to].size());\n        g[to].emplace_back(from,\
    \ 0, (int)g[from].size() - 1);\n    }\n\n    void bfs(int s) {\n        fill(ALL(level),\
    \ -1);\n        queue<int> que;\n        level[s] = 0;\n        que.push(s);\n\
    \n        while (!que.empty()) {\n            int v = que.front();\n         \
    \   que.pop();\n            for (auto& e : g[v]) {\n                if (e.cap\
    \ > 0 && level[e.to] < 0) {\n                    level[e.to] = level[v] + 1;\n\
    \                    que.push(e.to);\n                }\n            }\n     \
    \   }\n    }\n\n    F dfs(int v, int t, F f) {\n        if (v == t) return f;\n\
    \        for (int& i = iter[v]; i < g[v].size(); i++) {\n            auto& e =\
    \ g[v][i];\n            if (e.cap > 0 && level[v] < level[e.to]) {\n         \
    \       F d = dfs(e.to, t, min(f, e.cap));\n                if (d > 0) {\n   \
    \                 e.cap -= d;\n                    g[e.to][e.rev].cap += d;\n\
    \                    return d;\n                }\n            }\n        }\n\
    \        return 0;\n    }\n\n    F max_flow(int s, int t) {\n        F flow =\
    \ 0;\n        while (true) {\n            bfs(s);\n            if (level[t] <\
    \ 0) return flow;\n            fill(ALL(iter), 0);\n            F f;\n       \
    \     while ((f = dfs(s, t, INF)) > 0) flow += f;\n        }\n    }\n};\n"
  code: "// O(V^2 E)\nstruct Dinic {\n    using F = ll;\n    static constexpr F INF\
    \ = numeric_limits<F>::max();\n\n    struct Edge {\n        int to, rev;\n   \
    \     F cap;\n        Edge(int to, F cap, int rev) : to(to), cap(cap), rev(rev){};\n\
    \    };\n\n    using E = Edge;\n\n    VV<E> g;\n    V<int> level, iter;\n\n  \
    \  Dinic() {}\n    Dinic(int n) : g(n), level(n), iter(n) {}\n\n    void add_edge(int\
    \ from, int to, F cap) {\n        g[from].emplace_back(to, cap, (int)g[to].size());\n\
    \        g[to].emplace_back(from, 0, (int)g[from].size() - 1);\n    }\n\n    void\
    \ bfs(int s) {\n        fill(ALL(level), -1);\n        queue<int> que;\n     \
    \   level[s] = 0;\n        que.push(s);\n\n        while (!que.empty()) {\n  \
    \          int v = que.front();\n            que.pop();\n            for (auto&\
    \ e : g[v]) {\n                if (e.cap > 0 && level[e.to] < 0) {\n         \
    \           level[e.to] = level[v] + 1;\n                    que.push(e.to);\n\
    \                }\n            }\n        }\n    }\n\n    F dfs(int v, int t,\
    \ F f) {\n        if (v == t) return f;\n        for (int& i = iter[v]; i < g[v].size();\
    \ i++) {\n            auto& e = g[v][i];\n            if (e.cap > 0 && level[v]\
    \ < level[e.to]) {\n                F d = dfs(e.to, t, min(f, e.cap));\n     \
    \           if (d > 0) {\n                    e.cap -= d;\n                  \
    \  g[e.to][e.rev].cap += d;\n                    return d;\n                }\n\
    \            }\n        }\n        return 0;\n    }\n\n    F max_flow(int s, int\
    \ t) {\n        F flow = 0;\n        while (true) {\n            bfs(s);\n   \
    \         if (level[t] < 0) return flow;\n            fill(ALL(iter), 0);\n  \
    \          F f;\n            while ((f = dfs(s, t, INF)) > 0) flow += f;\n   \
    \     }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/Dinic.hpp
  requiredBy: []
  timestamp: '2020-06-06 01:31:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/bipartitematching.test.cpp
documentation_of: cpp_src/graph/Dinic.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/Dinic.hpp
- /library/cpp_src/graph/Dinic.hpp.html
title: cpp_src/graph/Dinic.hpp
---
