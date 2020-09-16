---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/assignment
    links:
    - https://judge.yosupo.jp/problem/assignment
  bundledCode: "#line 1 \"test/yosupo/assignment.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\nusing\
    \ pii = pair<int, int>;\ntemplate <class T>\nusing V = vector<T>;\ntemplate <class\
    \ T>\nusing VV = V<V<T>>;\n\n#define pb push_back\n#define eb emplace_back\n#define\
    \ mp make_pair\n#define fi first\n#define se second\n#define rep(i, n) rep2(i,\
    \ 0, n)\n#define rep2(i, m, n) for (int i = m; i < (n); i++)\n#define ALL(c) (c).begin(),\
    \ (c).end()\n\n#ifdef LOCAL\n#define dump(x) cerr << __LINE__ << \" \" << #x <<\
    \ \" = \" << (x) << endl\n#else\n#define dump(x) true\n#endif\n\nconstexpr ll\
    \ TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }\n\ntemplate <class T,\
    \ class U>\nvoid chmin(T& t, const U& u) {\n    if (t > u) t = u;\n}\ntemplate\
    \ <class T, class U>\nvoid chmax(T& t, const U& u) {\n    if (t < u) t = u;\n\
    }\n\ntemplate <class T, class U>\nostream& operator<<(ostream& os, const pair<T,\
    \ U>& p) {\n    os << \"(\" << p.first << \",\" << p.second << \")\";\n    return\
    \ os;\n}\n\ntemplate <class T>\nostream& operator<<(ostream& os, const vector<T>&\
    \ v) {\n    os << \"{\";\n    rep(i, v.size()) {\n        if (i) os << \",\";\n\
    \        os << v[i];\n    }\n    os << \"}\";\n    return os;\n}\n\n/*\n#define\
    \ call_from_test\n#include \"../../cpp_src/data_structure/unionfind.hpp\"\n#undef\
    \ call_from_test\n*/\n\ntemplate <class C, class D>  // capacity, distance\nstruct\
    \ MinCostFlow {\n    struct edge {\n        int to, rev;\n        C cap;\n   \
    \     D cost;\n        edge(int to, C cap, D cost, int rev)\n            : to(to),\
    \ cap(cap), cost(cost), rev(rev){};\n    };\n\n    using E = edge;\n\n    const\
    \ D INF = numeric_limits<D>::max() / D(3);\n\n    int n;\n    VV<E> g;\n    V<D>\
    \ h, dst;\n    V<int> prevv, preve;\n\n    MinCostFlow(int n) : n(n), g(n), h(n),\
    \ dst(n), prevv(n), preve(n) {}\n\n    void add_edge(int f, int t, C cap, D cost)\
    \ {\n        g[f].emplace_back(t, cap, cost, (int)g[t].size());\n        g[t].emplace_back(f,\
    \ 0, -cost, (int)g[f].size() - 1);\n    }\n\n    void init_negative(int s) {\n\
    \        fill(h.begin(), h.end(), INF);\n        h[s] = 0;\n        for (int t\
    \ = 0; t < n; ++t) {\n            for (int i = 0; i < n; ++i) {\n            \
    \    for (auto e : g[i]) {\n                    if (!e.cap || h[i] == INF) continue;\n\
    \                    h[e.to] = min(h[e.to], h[i] + e.cost);\n                }\n\
    \            }\n        }\n    }\n\n    D exec(int s, int t, C f) {\n        D\
    \ res = 0;\n        using Data = pair<D, int>;\n\n        while (f > 0) {\n  \
    \          priority_queue<Data, vector<Data>, greater<Data>> que;\n          \
    \  fill(dst.begin(), dst.end(), INF);\n            dst[s] = 0;\n            que.push(Data(0,\
    \ s));\n\n            while (!que.empty()) {\n                auto p = que.top();\n\
    \                que.pop();\n                int v = p.se;\n                if\
    \ (dst[v] < p.fi) continue;\n\n                rep(i, g[v].size()) {\n       \
    \             auto e = g[v][i];\n                    D nd = dst[v] + e.cost +\
    \ h[v] - h[e.to];\n                    if (e.cap > 0 && dst[e.to] > nd) {\n  \
    \                      dst[e.to] = nd;\n                        prevv[e.to] =\
    \ v;\n                        preve[e.to] = i;\n                        que.push(Data(dst[e.to],\
    \ e.to));\n                    }\n                }\n            }\n\n       \
    \     if (dst[t] == INF) return D(-1);\n            rep(i, n) h[i] += dst[i];\n\
    \n            C d = f;\n            for (int v = t; v != s; v = prevv[v]) {\n\
    \                d = min(d, g[prevv[v]][preve[v]].cap);\n            }\n     \
    \       f -= d;\n            res += d * h[t];\n            for (int v = t; v !=\
    \ s; v = prevv[v]) {\n                edge& e = g[prevv[v]][preve[v]];\n     \
    \           e.cap -= d;\n                g[v][e.rev].cap += d;\n            }\n\
    \        }\n\n        return res;\n    }\n};\n\nint main() {\n    int n;\n   \
    \ cin >> n;\n    int N = n * 2 + 2;\n    int s = N - 2, t = N - 1;\n    MinCostFlow<ll,\
    \ ll> mcf(N);\n    rep(i, n) {\n        rep(j, n) {\n            int x;\n    \
    \        cin >> x;\n            mcf.add_edge(i, j + n, 1, x);\n        }\n   \
    \     mcf.add_edge(s, i, 1, 0);\n        mcf.add_edge(i + n, t, 1, 0);\n    }\n\
    \    mcf.init_negative(s);\n    ll X = mcf.exec(s, t, n);\n    cout << X << endl;\n\
    \    rep(i, N) {\n        for (auto e : mcf.g[i]) {\n            if (e.to >= n\
    \ && e.to < n * 2 && e.cap == 0) {\n                cout << e.to - n << \" \"\
    ;\n            }\n        }\n    }\n    cout << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\nusing pii =\
    \ pair<int, int>;\ntemplate <class T>\nusing V = vector<T>;\ntemplate <class T>\n\
    using VV = V<V<T>>;\n\n#define pb push_back\n#define eb emplace_back\n#define\
    \ mp make_pair\n#define fi first\n#define se second\n#define rep(i, n) rep2(i,\
    \ 0, n)\n#define rep2(i, m, n) for (int i = m; i < (n); i++)\n#define ALL(c) (c).begin(),\
    \ (c).end()\n\n#ifdef LOCAL\n#define dump(x) cerr << __LINE__ << \" \" << #x <<\
    \ \" = \" << (x) << endl\n#else\n#define dump(x) true\n#endif\n\nconstexpr ll\
    \ TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }\n\ntemplate <class T,\
    \ class U>\nvoid chmin(T& t, const U& u) {\n    if (t > u) t = u;\n}\ntemplate\
    \ <class T, class U>\nvoid chmax(T& t, const U& u) {\n    if (t < u) t = u;\n\
    }\n\ntemplate <class T, class U>\nostream& operator<<(ostream& os, const pair<T,\
    \ U>& p) {\n    os << \"(\" << p.first << \",\" << p.second << \")\";\n    return\
    \ os;\n}\n\ntemplate <class T>\nostream& operator<<(ostream& os, const vector<T>&\
    \ v) {\n    os << \"{\";\n    rep(i, v.size()) {\n        if (i) os << \",\";\n\
    \        os << v[i];\n    }\n    os << \"}\";\n    return os;\n}\n\n/*\n#define\
    \ call_from_test\n#include \"../../cpp_src/data_structure/unionfind.hpp\"\n#undef\
    \ call_from_test\n*/\n\ntemplate <class C, class D>  // capacity, distance\nstruct\
    \ MinCostFlow {\n    struct edge {\n        int to, rev;\n        C cap;\n   \
    \     D cost;\n        edge(int to, C cap, D cost, int rev)\n            : to(to),\
    \ cap(cap), cost(cost), rev(rev){};\n    };\n\n    using E = edge;\n\n    const\
    \ D INF = numeric_limits<D>::max() / D(3);\n\n    int n;\n    VV<E> g;\n    V<D>\
    \ h, dst;\n    V<int> prevv, preve;\n\n    MinCostFlow(int n) : n(n), g(n), h(n),\
    \ dst(n), prevv(n), preve(n) {}\n\n    void add_edge(int f, int t, C cap, D cost)\
    \ {\n        g[f].emplace_back(t, cap, cost, (int)g[t].size());\n        g[t].emplace_back(f,\
    \ 0, -cost, (int)g[f].size() - 1);\n    }\n\n    void init_negative(int s) {\n\
    \        fill(h.begin(), h.end(), INF);\n        h[s] = 0;\n        for (int t\
    \ = 0; t < n; ++t) {\n            for (int i = 0; i < n; ++i) {\n            \
    \    for (auto e : g[i]) {\n                    if (!e.cap || h[i] == INF) continue;\n\
    \                    h[e.to] = min(h[e.to], h[i] + e.cost);\n                }\n\
    \            }\n        }\n    }\n\n    D exec(int s, int t, C f) {\n        D\
    \ res = 0;\n        using Data = pair<D, int>;\n\n        while (f > 0) {\n  \
    \          priority_queue<Data, vector<Data>, greater<Data>> que;\n          \
    \  fill(dst.begin(), dst.end(), INF);\n            dst[s] = 0;\n            que.push(Data(0,\
    \ s));\n\n            while (!que.empty()) {\n                auto p = que.top();\n\
    \                que.pop();\n                int v = p.se;\n                if\
    \ (dst[v] < p.fi) continue;\n\n                rep(i, g[v].size()) {\n       \
    \             auto e = g[v][i];\n                    D nd = dst[v] + e.cost +\
    \ h[v] - h[e.to];\n                    if (e.cap > 0 && dst[e.to] > nd) {\n  \
    \                      dst[e.to] = nd;\n                        prevv[e.to] =\
    \ v;\n                        preve[e.to] = i;\n                        que.push(Data(dst[e.to],\
    \ e.to));\n                    }\n                }\n            }\n\n       \
    \     if (dst[t] == INF) return D(-1);\n            rep(i, n) h[i] += dst[i];\n\
    \n            C d = f;\n            for (int v = t; v != s; v = prevv[v]) {\n\
    \                d = min(d, g[prevv[v]][preve[v]].cap);\n            }\n     \
    \       f -= d;\n            res += d * h[t];\n            for (int v = t; v !=\
    \ s; v = prevv[v]) {\n                edge& e = g[prevv[v]][preve[v]];\n     \
    \           e.cap -= d;\n                g[v][e.rev].cap += d;\n            }\n\
    \        }\n\n        return res;\n    }\n};\n\nint main() {\n    int n;\n   \
    \ cin >> n;\n    int N = n * 2 + 2;\n    int s = N - 2, t = N - 1;\n    MinCostFlow<ll,\
    \ ll> mcf(N);\n    rep(i, n) {\n        rep(j, n) {\n            int x;\n    \
    \        cin >> x;\n            mcf.add_edge(i, j + n, 1, x);\n        }\n   \
    \     mcf.add_edge(s, i, 1, 0);\n        mcf.add_edge(i + n, t, 1, 0);\n    }\n\
    \    mcf.init_negative(s);\n    ll X = mcf.exec(s, t, n);\n    cout << X << endl;\n\
    \    rep(i, N) {\n        for (auto e : mcf.g[i]) {\n            if (e.to >= n\
    \ && e.to < n * 2 && e.cap == 0) {\n                cout << e.to - n << \" \"\
    ;\n            }\n        }\n    }\n    cout << endl;\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/assignment.test.cpp
  requiredBy: []
  timestamp: '2020-07-17 17:36:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/assignment.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/assignment.test.cpp
- /verify/test/yosupo/assignment.test.cpp.html
title: test/yosupo/assignment.test.cpp
---
