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
  bundledCode: "#line 1 \"cpp_src/graph/Dinic.hpp\"\n// O(V^2 E)\ntemplate <class\
    \ F>\nstruct Dinic {\n    static constexpr F INF = numeric_limits<F>::max();\n\
    \n    struct Edge {\n        int to, rev;\n        F cap;\n        Edge(int to,\
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
    \     while ((f = dfs(s, t, INF)) > 0) flow += f;\n        }\n    }\n\n    //\
    \ after calling max_flow\n    // vector of {0, 1} (S side : 0)\n    V<int> mincut(int\
    \ S = 0) {\n        V<int> vis(g.size());\n        V<int> res(g.size(), 1);\n\
    \        min_dfs(S, res, vis);\n        return res;\n    }\n\n    void min_dfs(int\
    \ v, V<int>& col, V<int>& vis) {\n        col[v] = 0;\n        vis[v] = 1;\n \
    \       for (auto e : g[v]) {\n            if (!vis[e.to] && e.cap > 0) {\n  \
    \              min_dfs(e.to, col, vis);\n            }\n        }\n    }\n};\n\
    \n// GCJ 2022 Round 2C\n// mat[i][j] := 0,1 (whether i-j exists)\n// (size of\
    \ max_matching, assignment)\npair<int, V<int>> max_matching(const VV<int>& mat)\
    \ {\n    int L = SZ(mat);\n    if (L == 0) {\n        return mp(0, V<int>{});\n\
    \    }\n\n    int R = SZ(mat[0]);\n    int cnt_node = L + R + 2;\n    int S =\
    \ cnt_node - 2, T = cnt_node - 1;\n    Dinic<int> g(cnt_node);\n    V<int> to(L,\
    \ -1);\n\n    rep(i, L) {\n        g.add_edge(S, i, 1);\n        rep(j, R) {\n\
    \            if (mat[i][j]) {\n                g.add_edge(i, j + L, 1);\n    \
    \        }\n        }\n    }\n    rep(j, R) g.add_edge(j + L, T, 1);\n\n    int\
    \ mf = g.max_flow(S, T);\n    rep(i, L) {\n        for (auto e : g.g[i]) {\n \
    \           if (e.to >= L && e.to < L + R && e.cap == 0) {\n                to[i]\
    \ = e.to - L;\n            }\n        }\n    }\n    return make_pair(mf, to);\n\
    }\n"
  code: "// O(V^2 E)\ntemplate <class F>\nstruct Dinic {\n    static constexpr F INF\
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
    \     }\n    }\n\n    // after calling max_flow\n    // vector of {0, 1} (S side\
    \ : 0)\n    V<int> mincut(int S = 0) {\n        V<int> vis(g.size());\n      \
    \  V<int> res(g.size(), 1);\n        min_dfs(S, res, vis);\n        return res;\n\
    \    }\n\n    void min_dfs(int v, V<int>& col, V<int>& vis) {\n        col[v]\
    \ = 0;\n        vis[v] = 1;\n        for (auto e : g[v]) {\n            if (!vis[e.to]\
    \ && e.cap > 0) {\n                min_dfs(e.to, col, vis);\n            }\n \
    \       }\n    }\n};\n\n// GCJ 2022 Round 2C\n// mat[i][j] := 0,1 (whether i-j\
    \ exists)\n// (size of max_matching, assignment)\npair<int, V<int>> max_matching(const\
    \ VV<int>& mat) {\n    int L = SZ(mat);\n    if (L == 0) {\n        return mp(0,\
    \ V<int>{});\n    }\n\n    int R = SZ(mat[0]);\n    int cnt_node = L + R + 2;\n\
    \    int S = cnt_node - 2, T = cnt_node - 1;\n    Dinic<int> g(cnt_node);\n  \
    \  V<int> to(L, -1);\n\n    rep(i, L) {\n        g.add_edge(S, i, 1);\n      \
    \  rep(j, R) {\n            if (mat[i][j]) {\n                g.add_edge(i, j\
    \ + L, 1);\n            }\n        }\n    }\n    rep(j, R) g.add_edge(j + L, T,\
    \ 1);\n\n    int mf = g.max_flow(S, T);\n    rep(i, L) {\n        for (auto e\
    \ : g.g[i]) {\n            if (e.to >= L && e.to < L + R && e.cap == 0) {\n  \
    \              to[i] = e.to - L;\n            }\n        }\n    }\n    return\
    \ make_pair(mf, to);\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/Dinic.hpp
  requiredBy: []
  timestamp: '2022-05-22 15:10:18+09:00'
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
