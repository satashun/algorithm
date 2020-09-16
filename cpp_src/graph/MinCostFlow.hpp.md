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
  bundledCode: "#line 1 \"cpp_src/graph/MinCostFlow.hpp\"\ntemplate <class C, class\
    \ D>  // capacity, distance\nstruct MinCostFlow {\n    struct edge {\n       \
    \ int to, rev;\n        C cap;\n        D cost;\n        edge(int to, C cap, D\
    \ cost, int rev)\n            : to(to), cap(cap), cost(cost), rev(rev){};\n  \
    \  };\n\n    using E = edge;\n\n    const D INF = numeric_limits<D>::max() / D(3);\n\
    \n    int n;\n    VV<E> g;\n    V<D> h, dst;\n    V<int> prevv, preve;\n\n   \
    \ MinCostFlow(int n) : n(n), g(n), h(n), dst(n), prevv(n), preve(n) {}\n\n   \
    \ void add_edge(int f, int t, C cap, D cost) {\n        g[f].emplace_back(t, cap,\
    \ cost, (int)g[t].size());\n        g[t].emplace_back(f, 0, -cost, (int)g[f].size()\
    \ - 1);\n    }\n\n    // true : no negative cycle\n    bool init_negative(int\
    \ s) {\n        fill(h.begin(), h.end(), INF);\n        h[s] = 0;\n        for\
    \ (int t = 0; t <= n; ++t) {\n            for (int i = 0; i < n; ++i) {\n    \
    \            for (auto e : g[i]) {\n                    if (!e.cap) continue;\n\
    \                    if (h[e.to] > h[i] + e.cost && t == n) {\n              \
    \          return false;\n                    }\n                    h[e.to] =\
    \ min(h[e.to], h[i] + e.cost);\n                }\n            }\n        }\n\
    \        return true;\n    }\n\n    D exec(int s, int t, C f) {\n        D res\
    \ = 0;\n        using Data = pair<D, int>;\n        while (f > 0) {\n        \
    \    priority_queue<Data, vector<Data>, greater<Data>> que;\n            fill(dst.begin(),\
    \ dst.end(), INF);\n            dst[s] = 0;\n            que.push(Data(0, s));\n\
    \n            while (!que.empty()) {\n                auto p = que.top();\n  \
    \              que.pop();\n                int v = p.second;\n               \
    \ if (dst[v] < p.first) continue;\n\n                rep(i, g[v].size()) {\n \
    \                   auto e = g[v][i];\n                    D nd = dst[v] + e.cost\
    \ + h[v] - h[e.to];\n                    if (e.cap > 0 && dst[e.to] > nd) {\n\
    \                        dst[e.to] = nd;\n                        prevv[e.to]\
    \ = v;\n                        preve[e.to] = i;\n                        que.push(Data(dst[e.to],\
    \ e.to));\n                    }\n                }\n            }\n\n       \
    \     if (dst[t] == INF) return D(-inf);\n            rep(i, n) h[i] += dst[i];\n\
    \n            C d = f;\n            for (int v = t; v != s; v = prevv[v]) {\n\
    \                d = min(d, g[prevv[v]][preve[v]].cap);\n            }\n     \
    \       f -= d;\n            res += d * h[t];\n            for (int v = t; v !=\
    \ s; v = prevv[v]) {\n                edge& e = g[prevv[v]][preve[v]];\n     \
    \           e.cap -= d;\n                g[v][e.rev].cap += d;\n            }\n\
    \        }\n\n        return res;\n    }\n};\n"
  code: "template <class C, class D>  // capacity, distance\nstruct MinCostFlow {\n\
    \    struct edge {\n        int to, rev;\n        C cap;\n        D cost;\n  \
    \      edge(int to, C cap, D cost, int rev)\n            : to(to), cap(cap), cost(cost),\
    \ rev(rev){};\n    };\n\n    using E = edge;\n\n    const D INF = numeric_limits<D>::max()\
    \ / D(3);\n\n    int n;\n    VV<E> g;\n    V<D> h, dst;\n    V<int> prevv, preve;\n\
    \n    MinCostFlow(int n) : n(n), g(n), h(n), dst(n), prevv(n), preve(n) {}\n\n\
    \    void add_edge(int f, int t, C cap, D cost) {\n        g[f].emplace_back(t,\
    \ cap, cost, (int)g[t].size());\n        g[t].emplace_back(f, 0, -cost, (int)g[f].size()\
    \ - 1);\n    }\n\n    // true : no negative cycle\n    bool init_negative(int\
    \ s) {\n        fill(h.begin(), h.end(), INF);\n        h[s] = 0;\n        for\
    \ (int t = 0; t <= n; ++t) {\n            for (int i = 0; i < n; ++i) {\n    \
    \            for (auto e : g[i]) {\n                    if (!e.cap) continue;\n\
    \                    if (h[e.to] > h[i] + e.cost && t == n) {\n              \
    \          return false;\n                    }\n                    h[e.to] =\
    \ min(h[e.to], h[i] + e.cost);\n                }\n            }\n        }\n\
    \        return true;\n    }\n\n    D exec(int s, int t, C f) {\n        D res\
    \ = 0;\n        using Data = pair<D, int>;\n        while (f > 0) {\n        \
    \    priority_queue<Data, vector<Data>, greater<Data>> que;\n            fill(dst.begin(),\
    \ dst.end(), INF);\n            dst[s] = 0;\n            que.push(Data(0, s));\n\
    \n            while (!que.empty()) {\n                auto p = que.top();\n  \
    \              que.pop();\n                int v = p.second;\n               \
    \ if (dst[v] < p.first) continue;\n\n                rep(i, g[v].size()) {\n \
    \                   auto e = g[v][i];\n                    D nd = dst[v] + e.cost\
    \ + h[v] - h[e.to];\n                    if (e.cap > 0 && dst[e.to] > nd) {\n\
    \                        dst[e.to] = nd;\n                        prevv[e.to]\
    \ = v;\n                        preve[e.to] = i;\n                        que.push(Data(dst[e.to],\
    \ e.to));\n                    }\n                }\n            }\n\n       \
    \     if (dst[t] == INF) return D(-inf);\n            rep(i, n) h[i] += dst[i];\n\
    \n            C d = f;\n            for (int v = t; v != s; v = prevv[v]) {\n\
    \                d = min(d, g[prevv[v]][preve[v]].cap);\n            }\n     \
    \       f -= d;\n            res += d * h[t];\n            for (int v = t; v !=\
    \ s; v = prevv[v]) {\n                edge& e = g[prevv[v]][preve[v]];\n     \
    \           e.cap -= d;\n                g[v][e.rev].cap += d;\n            }\n\
    \        }\n\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/MinCostFlow.hpp
  requiredBy: []
  timestamp: '2020-09-15 11:23:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/MinCostFlow.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/MinCostFlow.hpp
- /library/cpp_src/graph/MinCostFlow.hpp.html
title: cpp_src/graph/MinCostFlow.hpp
---
