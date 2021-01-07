---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"test/yosupo/min_cost_b_flow.cpp\"\n// SSP, TLE\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\nusing pii =\
    \ pair<int, int>;\ntemplate <class T>\nusing V = vector<T>;\ntemplate <class T>\n\
    using VV = V<V<T>>;\n\n#define pb push_back\n#define eb emplace_back\n#define\
    \ mp make_pair\n#define fi first\n#define se second\n#define rep(i, n) rep2(i,\
    \ 0, n)\n#define rep2(i, m, n) for (int i = m; i < (n); i++)\n#define per(i, b)\
    \ per2(i, 0, b)\n#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)\n\
    #define ALL(c) (c).begin(), (c).end()\n\nconstexpr ll TEN(int n) { return (n ==\
    \ 0) ? 1 : 10 * TEN(n - 1); }\n\ntemplate <class T, class U>\nvoid chmin(T& t,\
    \ const U& u) {\n    if (t > u) t = u;\n}\ntemplate <class T, class U>\nvoid chmax(T&\
    \ t, const U& u) {\n    if (t < u) t = u;\n}\n\ntemplate <class T, class U>\n\
    ostream& operator<<(ostream& os, const pair<T, U>& p) {\n    os << \"(\" << p.first\
    \ << \",\" << p.second << \")\";\n    return os;\n}\n\ntemplate <class T>\nostream&\
    \ operator<<(ostream& os, const vector<T>& v) {\n    os << \"{\";\n    rep(i,\
    \ v.size()) {\n        if (i) os << \",\";\n        os << v[i];\n    }\n    os\
    \ << \"}\";\n    return os;\n}\n\n#ifdef LOCAL\nvoid debug_out() { cerr << endl;\
    \ }\ntemplate <typename Head, typename... Tail>\nvoid debug_out(Head H, Tail...\
    \ T) {\n    cerr << \" \" << H;\n    debug_out(T...);\n}\n#define debug(...) \\\
    \n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n\
    #define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n\
    #define debug(...) (void(0))\n#define dump(x) (void(0))\n#endif\n\nusing R = __int128;\n\
    \nstring to_string(R x) {\n    if (x == 0) return \"0\";\n    string s;\n    bool\
    \ r = 0;\n    if (x < 0) {\n        r = 1;\n        x = -x;\n    }\n    while\
    \ (x > 0) {\n        s.pb('0' + x % 10);\n        x /= 10;\n    }\n    if (r)\
    \ s.pb('-');\n    reverse(ALL(s));\n    return s;\n}\n\ntemplate <class C, class\
    \ D>  // capacity, distance\nstruct MinCostFlow {\n    struct edge {\n       \
    \ int to, rev, id;\n        C cap;\n        D cost;\n        edge(int to, C cap,\
    \ D cost, int rev, int id)\n            : to(to), cap(cap), cost(cost), rev(rev),\
    \ id(id){};\n    };\n\n    using E = edge;\n\n    const D INF = D(1) << 120;\n\
    \n    int n;\n    VV<E> g;\n    V<D> h, dst;\n    V<int> prevv, preve;\n    V<C>\
    \ b;\n    D val;\n\n    MinCostFlow(int n)\n        : n(n), g(n), h(n), dst(n),\
    \ prevv(n), preve(n), b(n), val(0) {}\n\n    // watch out for self loops!\n  \
    \  void add_edge(int f, int t, C cap, D cost, int id, bool need = false) {\n \
    \       if (!need && cost >= 0) {\n            int szt = (int)g[t].size() + (f\
    \ == t);\n            g[f].emplace_back(t, cap, cost, szt, id);\n            int\
    \ szf = (int)g[f].size() - 1;\n            g[t].emplace_back(f, 0, -cost, szf,\
    \ -1);\n        } else {\n            b[f] -= cap;\n            b[t] += cap;\n\
    \            val += cost * cap;\n            if (!need) {\n                int\
    \ szt = (int)g[t].size() + (f == t);\n                g[f].emplace_back(t, 0,\
    \ cost, szt, id);\n                int szf = (int)g[f].size() - 1;\n         \
    \       g[t].emplace_back(f, cap, -cost, szf, -1);\n            }\n        }\n\
    \    }\n\n    void init_negative(int s) {\n        fill(h.begin(), h.end(), INF);\n\
    \        h[s] = 0;\n        for (int t = 0; t < n; ++t) {\n            for (int\
    \ i = 0; i < n; ++i) {\n                for (auto e : g[i]) {\n              \
    \      if (!e.cap || h[i] == INF) continue;\n                    h[e.to] = min(h[e.to],\
    \ h[i] + e.cost);\n                }\n            }\n        }\n    }\n\n    D\
    \ exec(int s, int t, C f) {\n        D res = 0;\n        using Data = pair<D,\
    \ int>;\n\n        while (f > 0) {\n            priority_queue<Data, vector<Data>,\
    \ greater<Data>> que;\n            fill(dst.begin(), dst.end(), INF);\n      \
    \      dst[s] = 0;\n            que.push(Data(0, s));\n\n            while (!que.empty())\
    \ {\n                auto p = que.top();\n                que.pop();\n       \
    \         int v = p.se;\n                if (dst[v] < p.fi) continue;\n      \
    \          rep(i, g[v].size()) {\n                    auto e = g[v][i];\n    \
    \                D nd = dst[v] + e.cost + h[v] - h[e.to];\n                  \
    \  if (e.cap > 0 && dst[e.to] > nd) {\n                        dst[e.to] = nd;\n\
    \                        prevv[e.to] = v;\n                        preve[e.to]\
    \ = i;\n                        que.push(Data(dst[e.to], e.to));\n           \
    \         }\n                }\n            }\n\n            if (dst[t] == INF)\
    \ return D(-INF);\n            rep(i, n) h[i] += dst[i];\n\n            C d =\
    \ f;\n            for (int v = t; v != s; v = prevv[v]) {\n                d =\
    \ min(d, g[prevv[v]][preve[v]].cap);\n            }\n            f -= d;\n   \
    \         res += d * h[t];\n            for (int v = t; v != s; v = prevv[v])\
    \ {\n                edge& e = g[prevv[v]][preve[v]];\n                e.cap -=\
    \ d;\n                g[v][e.rev].cap += d;\n            }\n        }\n\n    \
    \    return res;\n    }\n};\n\nvoid ng() {\n    cout << \"infeasible\" << endl;\n\
    \    exit(0);\n}\n\nint main() {\n    int n, m;\n    cin >> n >> m;\n    MinCostFlow<R,\
    \ R> flow(n + 2);\n    rep(i, n) {\n        ll x;\n        cin >> x;\n       \
    \ flow.b[i] = x;\n    }\n    V<R> fl(m);\n\n    rep(i, m) {\n        int s, t,\
    \ l, u, c;\n        cin >> s >> t >> l >> u >> c;\n        if (l > 0) {\n    \
    \        flow.add_edge(s, t, l, c, -1, true);\n        } else {\n            flow.add_edge(t,\
    \ s, -l, -c, -1, true);\n        }\n\n        flow.add_edge(s, t, u - l, c, i);\n\
    \        fl[i] = l;\n    }\n\n    int s = n, t = n + 1;\n    R bs = 0, ps = 0;\n\
    \    {\n        rep(i, n) {\n            bs += flow.b[i];\n            if (flow.b[i]\
    \ > 0) {\n                ps += flow.b[i];\n                flow.add_edge(s, i,\
    \ flow.b[i], 0, -1);\n            } else {\n                flow.add_edge(i, t,\
    \ -flow.b[i], 0, -1);\n            }\n        }\n        if (bs != 0) {\n    \
    \        ng();\n        }\n    }\n\n    flow.init_negative(s);\n\n    auto ct\
    \ = flow.exec(s, t, ps);\n    if (ct == -flow.INF) ng();\n    R ans = ct + flow.val;\n\
    \n    rep(i, n) {\n        for (auto e : flow.g[i]) {\n            if (e.id >=\
    \ 0) {\n                fl[e.id] += flow.g[e.to][e.rev].cap;\n            }\n\
    \        }\n    }\n\n    cout << to_string(ans) << endl;\n    const R inf = TEN(15);\n\
    \    rep(i, n) cout << to_string(max(min(flow.h[i], inf), -inf)) << endl;\n  \
    \  rep(i, m) cout << to_string(fl[i]) << endl;\n    return 0;\n}\n"
  code: "// SSP, TLE\n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll\
    \ = long long;\nusing pii = pair<int, int>;\ntemplate <class T>\nusing V = vector<T>;\n\
    template <class T>\nusing VV = V<V<T>>;\n\n#define pb push_back\n#define eb emplace_back\n\
    #define mp make_pair\n#define fi first\n#define se second\n#define rep(i, n) rep2(i,\
    \ 0, n)\n#define rep2(i, m, n) for (int i = m; i < (n); i++)\n#define per(i, b)\
    \ per2(i, 0, b)\n#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)\n\
    #define ALL(c) (c).begin(), (c).end()\n\nconstexpr ll TEN(int n) { return (n ==\
    \ 0) ? 1 : 10 * TEN(n - 1); }\n\ntemplate <class T, class U>\nvoid chmin(T& t,\
    \ const U& u) {\n    if (t > u) t = u;\n}\ntemplate <class T, class U>\nvoid chmax(T&\
    \ t, const U& u) {\n    if (t < u) t = u;\n}\n\ntemplate <class T, class U>\n\
    ostream& operator<<(ostream& os, const pair<T, U>& p) {\n    os << \"(\" << p.first\
    \ << \",\" << p.second << \")\";\n    return os;\n}\n\ntemplate <class T>\nostream&\
    \ operator<<(ostream& os, const vector<T>& v) {\n    os << \"{\";\n    rep(i,\
    \ v.size()) {\n        if (i) os << \",\";\n        os << v[i];\n    }\n    os\
    \ << \"}\";\n    return os;\n}\n\n#ifdef LOCAL\nvoid debug_out() { cerr << endl;\
    \ }\ntemplate <typename Head, typename... Tail>\nvoid debug_out(Head H, Tail...\
    \ T) {\n    cerr << \" \" << H;\n    debug_out(T...);\n}\n#define debug(...) \\\
    \n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n\
    #define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n\
    #define debug(...) (void(0))\n#define dump(x) (void(0))\n#endif\n\nusing R = __int128;\n\
    \nstring to_string(R x) {\n    if (x == 0) return \"0\";\n    string s;\n    bool\
    \ r = 0;\n    if (x < 0) {\n        r = 1;\n        x = -x;\n    }\n    while\
    \ (x > 0) {\n        s.pb('0' + x % 10);\n        x /= 10;\n    }\n    if (r)\
    \ s.pb('-');\n    reverse(ALL(s));\n    return s;\n}\n\ntemplate <class C, class\
    \ D>  // capacity, distance\nstruct MinCostFlow {\n    struct edge {\n       \
    \ int to, rev, id;\n        C cap;\n        D cost;\n        edge(int to, C cap,\
    \ D cost, int rev, int id)\n            : to(to), cap(cap), cost(cost), rev(rev),\
    \ id(id){};\n    };\n\n    using E = edge;\n\n    const D INF = D(1) << 120;\n\
    \n    int n;\n    VV<E> g;\n    V<D> h, dst;\n    V<int> prevv, preve;\n    V<C>\
    \ b;\n    D val;\n\n    MinCostFlow(int n)\n        : n(n), g(n), h(n), dst(n),\
    \ prevv(n), preve(n), b(n), val(0) {}\n\n    // watch out for self loops!\n  \
    \  void add_edge(int f, int t, C cap, D cost, int id, bool need = false) {\n \
    \       if (!need && cost >= 0) {\n            int szt = (int)g[t].size() + (f\
    \ == t);\n            g[f].emplace_back(t, cap, cost, szt, id);\n            int\
    \ szf = (int)g[f].size() - 1;\n            g[t].emplace_back(f, 0, -cost, szf,\
    \ -1);\n        } else {\n            b[f] -= cap;\n            b[t] += cap;\n\
    \            val += cost * cap;\n            if (!need) {\n                int\
    \ szt = (int)g[t].size() + (f == t);\n                g[f].emplace_back(t, 0,\
    \ cost, szt, id);\n                int szf = (int)g[f].size() - 1;\n         \
    \       g[t].emplace_back(f, cap, -cost, szf, -1);\n            }\n        }\n\
    \    }\n\n    void init_negative(int s) {\n        fill(h.begin(), h.end(), INF);\n\
    \        h[s] = 0;\n        for (int t = 0; t < n; ++t) {\n            for (int\
    \ i = 0; i < n; ++i) {\n                for (auto e : g[i]) {\n              \
    \      if (!e.cap || h[i] == INF) continue;\n                    h[e.to] = min(h[e.to],\
    \ h[i] + e.cost);\n                }\n            }\n        }\n    }\n\n    D\
    \ exec(int s, int t, C f) {\n        D res = 0;\n        using Data = pair<D,\
    \ int>;\n\n        while (f > 0) {\n            priority_queue<Data, vector<Data>,\
    \ greater<Data>> que;\n            fill(dst.begin(), dst.end(), INF);\n      \
    \      dst[s] = 0;\n            que.push(Data(0, s));\n\n            while (!que.empty())\
    \ {\n                auto p = que.top();\n                que.pop();\n       \
    \         int v = p.se;\n                if (dst[v] < p.fi) continue;\n      \
    \          rep(i, g[v].size()) {\n                    auto e = g[v][i];\n    \
    \                D nd = dst[v] + e.cost + h[v] - h[e.to];\n                  \
    \  if (e.cap > 0 && dst[e.to] > nd) {\n                        dst[e.to] = nd;\n\
    \                        prevv[e.to] = v;\n                        preve[e.to]\
    \ = i;\n                        que.push(Data(dst[e.to], e.to));\n           \
    \         }\n                }\n            }\n\n            if (dst[t] == INF)\
    \ return D(-INF);\n            rep(i, n) h[i] += dst[i];\n\n            C d =\
    \ f;\n            for (int v = t; v != s; v = prevv[v]) {\n                d =\
    \ min(d, g[prevv[v]][preve[v]].cap);\n            }\n            f -= d;\n   \
    \         res += d * h[t];\n            for (int v = t; v != s; v = prevv[v])\
    \ {\n                edge& e = g[prevv[v]][preve[v]];\n                e.cap -=\
    \ d;\n                g[v][e.rev].cap += d;\n            }\n        }\n\n    \
    \    return res;\n    }\n};\n\nvoid ng() {\n    cout << \"infeasible\" << endl;\n\
    \    exit(0);\n}\n\nint main() {\n    int n, m;\n    cin >> n >> m;\n    MinCostFlow<R,\
    \ R> flow(n + 2);\n    rep(i, n) {\n        ll x;\n        cin >> x;\n       \
    \ flow.b[i] = x;\n    }\n    V<R> fl(m);\n\n    rep(i, m) {\n        int s, t,\
    \ l, u, c;\n        cin >> s >> t >> l >> u >> c;\n        if (l > 0) {\n    \
    \        flow.add_edge(s, t, l, c, -1, true);\n        } else {\n            flow.add_edge(t,\
    \ s, -l, -c, -1, true);\n        }\n\n        flow.add_edge(s, t, u - l, c, i);\n\
    \        fl[i] = l;\n    }\n\n    int s = n, t = n + 1;\n    R bs = 0, ps = 0;\n\
    \    {\n        rep(i, n) {\n            bs += flow.b[i];\n            if (flow.b[i]\
    \ > 0) {\n                ps += flow.b[i];\n                flow.add_edge(s, i,\
    \ flow.b[i], 0, -1);\n            } else {\n                flow.add_edge(i, t,\
    \ -flow.b[i], 0, -1);\n            }\n        }\n        if (bs != 0) {\n    \
    \        ng();\n        }\n    }\n\n    flow.init_negative(s);\n\n    auto ct\
    \ = flow.exec(s, t, ps);\n    if (ct == -flow.INF) ng();\n    R ans = ct + flow.val;\n\
    \n    rep(i, n) {\n        for (auto e : flow.g[i]) {\n            if (e.id >=\
    \ 0) {\n                fl[e.id] += flow.g[e.to][e.rev].cap;\n            }\n\
    \        }\n    }\n\n    cout << to_string(ans) << endl;\n    const R inf = TEN(15);\n\
    \    rep(i, n) cout << to_string(max(min(flow.h[i], inf), -inf)) << endl;\n  \
    \  rep(i, m) cout << to_string(fl[i]) << endl;\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: test/yosupo/min_cost_b_flow.cpp
  requiredBy: []
  timestamp: '2020-08-06 01:21:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/yosupo/min_cost_b_flow.cpp
layout: document
redirect_from:
- /library/test/yosupo/min_cost_b_flow.cpp
- /library/test/yosupo/min_cost_b_flow.cpp.html
title: test/yosupo/min_cost_b_flow.cpp
---
