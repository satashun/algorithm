---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp_src/graph/GraphBase.hpp
    title: cpp_src/graph/GraphBase.hpp
  - icon: ':heavy_check_mark:'
    path: cpp_src/graph/SCC.hpp
    title: cpp_src/graph/SCC.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/yosupo/scc.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \n\n//#pragma GCC optimize(\"Ofast\")\n//#pragma GCC optimize(\"unroll-loops\"\
    )\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing pii = pair<int, int>;\ntemplate <class T>\n\
    using V = vector<T>;\ntemplate <class T>\nusing VV = V<V<T>>;\n\ntemplate <class\
    \ T>\nV<T> make_vec(size_t a) {\n    return V<T>(a);\n}\n\ntemplate <class T,\
    \ class... Ts>\nauto make_vec(size_t a, Ts... ts) {\n    return V<decltype(make_vec<T>(ts...))>(a,\
    \ make_vec<T>(ts...));\n}\n\n#define pb push_back\n#define eb emplace_back\n#define\
    \ mp make_pair\n#define fi first\n#define se second\n#define rep(i, n) rep2(i,\
    \ 0, n)\n#define rep2(i, m, n) for (int i = m; i < (n); i++)\n#define per(i, b)\
    \ per2(i, 0, b)\n#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)\n\
    #define ALL(c) (c).begin(), (c).end()\n#define SZ(x) ((int)(x).size())\n\nconstexpr\
    \ ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }\n\ntemplate <class\
    \ T, class U>\nvoid chmin(T& t, const U& u) {\n    if (t > u) t = u;\n}\ntemplate\
    \ <class T, class U>\nvoid chmax(T& t, const U& u) {\n    if (t < u) t = u;\n\
    }\n\ntemplate <class T>\nvoid mkuni(vector<T>& v) {\n    sort(ALL(v));\n    v.erase(unique(ALL(v)),\
    \ end(v));\n}\n\ntemplate <class T>\nvector<int> sort_by(const vector<T>& v) {\n\
    \    vector<int> res(v.size());\n    iota(res.begin(), res.end(), 0);\n    sort(res.begin(),\
    \ res.end(), [&](int i, int j) { return v[i] < v[j]; });\n    return res;\n}\n\
    \ntemplate <class T, class U>\nistream& operator>>(istream& is, pair<T, U>& p)\
    \ {\n    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate <class T, class\
    \ U>\nostream& operator<<(ostream& os, const pair<T, U>& p) {\n    os << \"(\"\
    \ << p.first << \",\" << p.second << \")\";\n    return os;\n}\n\ntemplate <class\
    \ T>\nistream& operator>>(istream& is, vector<T>& v) {\n    for (auto& x : v)\
    \ {\n        is >> x;\n    }\n    return is;\n}\n\ntemplate <class T>\nostream&\
    \ operator<<(ostream& os, const vector<T>& v) {\n    os << \"{\";\n    rep(i,\
    \ v.size()) {\n        if (i) os << \",\";\n        os << v[i];\n    }\n    os\
    \ << \"}\";\n    return os;\n}\n\n#ifdef LOCAL\nvoid debug_out() { cerr << endl;\
    \ }\ntemplate <typename Head, typename... Tail>\nvoid debug_out(Head H, Tail...\
    \ T) {\n    cerr << \" \" << H;\n    debug_out(T...);\n}\n#define debug(...) \\\
    \n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n\
    #define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n\
    #define debug(...) (void(0))\n#define dump(x) (void(0))\n#endif\n\ntemplate <class\
    \ T>\nvoid scan(vector<T>& v, T offset = T(0)) {\n    for (auto& x : v) {\n  \
    \      cin >> x;\n        x += offset;\n    }\n}\n\ntemplate <class T>\nvoid print(T\
    \ x, int suc = 1) {\n    cout << x;\n    if (suc == 1)\n        cout << \"\\n\"\
    ;\n    else if (suc == 2)\n        cout << \" \";\n}\n\ntemplate <class T>\nvoid\
    \ print(const vector<T>& v, int suc = 1) {\n    for (int i = 0; i < v.size();\
    \ ++i)\n        print(v[i], i == int(v.size()) - 1 ? suc : 2);\n}\n\nstruct prepare_io\
    \ {\n    prepare_io() {\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(10);\n    }\n} prep_io;\n\n#define call_from_test\n\
    #line 1 \"cpp_src/graph/GraphBase.hpp\"\ntemplate <class T>\nclass Edge {\n  \
    \ public:\n    int from, to, idx;\n    T cost;\n\n    Edge() = default;\n    Edge(int\
    \ from, int to, T cost = T(1), int idx = -1)\n        : from(from), to(to), cost(cost),\
    \ idx(idx) {}\n    operator int() const { return to; }\n\n    bool operator<(const\
    \ Edge& e) const { return cost < e.cost; }\n};\n\ntemplate <class T>\nclass Graph\
    \ {\n   public:\n    using E = Edge<T>;\n    vector<vector<E>> g;\n    vector<E>\
    \ edges;\n    int es;\n\n    Graph() {}\n    Graph(int n) : g(n), edges(0), es(0){};\n\
    \n    int size() const { return g.size(); }\n\n    virtual void add_directed_edge(int\
    \ from, int to, T cost = 1) {\n        g[from].emplace_back(from, to, cost, es++);\n\
    \    }\n\n    virtual void add_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n\n\
    \    inline vector<E>& operator[](const int& k) { return g[k]; }\n\n    inline\
    \ const vector<E>& operator[](const int& k) const {\n        return g[k];\n  \
    \  }\n\n    void read(int M, int offset = -1, bool directed = false,\n       \
    \       bool weighted = false) {\n        for (int i = 0; i < M; i++) {\n    \
    \        int a, b;\n            cin >> a >> b;\n            a += offset;\n   \
    \         b += offset;\n            T c = T(1);\n            if (weighted) cin\
    \ >> c;\n            edges.emplace_back(a, b, c);\n            if (directed)\n\
    \                add_directed_edge(a, b, c);\n            else\n             \
    \   add_edge(a, b, c);\n        }\n    }\n};\n\n// cost = 1 or tree\ntemplate\
    \ <class T>\nV<T> bfs(const Graph<T>& g, int s = 0) {\n    const T inf = numeric_limits<T>::max()\
    \ / 2;\n    int n = g.size();\n\n    V<T> ds(n, inf);\n    using P = pair<T, int>;\n\
    \    queue<int> que;\n    que.push(s);\n    ds[s] = 0;\n\n    while (!que.empty())\
    \ {\n        auto v = que.front();\n        que.pop();\n        for (auto e :\
    \ g[v]) {\n            T nx = ds[v] + e.cost;\n            if (ds[e.to] > nx)\
    \ {\n                ds[e.to] = nx;\n                que.push(e.to);\n       \
    \     }\n        }\n    }\n    for (auto& x : ds)\n        if (x == inf) x = -1;\n\
    \    return ds;\n}\n\n//must be optimized\ntemplate <class T>\nV<T> bfs01(const\
    \ Graph<T>& g, int s = 0) {\n    const T inf = numeric_limits<T>::max() / 2;\n\
    \    int n = g.size();\n\n    V<T> ds(n, inf);\n    using P = pair<T, int>;\n\
    \    deque<int> que;\n    que.push_back(s);\n    ds[s] = 0;\n\n    while (!que.empty())\
    \ {\n        auto v = que.front();\n        que.pop_front();\n        for (auto\
    \ e : g[v]) {\n            T nx = ds[v] + e.cost;\n            if (ds[e.to] >\
    \ nx) {\n                ds[e.to] = nx;\n                if (e.cost == 0) {\n\
    \                    que.push_front(e.to);\n                } else {\n       \
    \             que.push_back(e.to);\n                }\n            }\n       \
    \ }\n    }\n    for (auto& x : ds)\n        if (x == inf) x = -1;\n    return\
    \ ds;\n}\n\ntemplate <class T>\nV<T> dijkstra(const Graph<T>& g, int s = 0) {\n\
    \    const T inf = numeric_limits<T>::max() / 2;\n    int n = g.size();\n\n  \
    \  V<T> ds(n, inf);\n    using P = pair<T, int>;\n    priority_queue<P, V<P>,\
    \ greater<P>> que;\n    que.emplace(0, s);\n    ds[s] = 0;\n    while (!que.empty())\
    \ {\n        auto p = que.top();\n        que.pop();\n        int v = p.se;\n\
    \        if (ds[v] < p.fi) continue;\n        for (auto e : g[v]) {\n        \
    \    T nx = ds[v] + e.cost;\n            if (ds[e.to] > nx) {\n              \
    \  ds[e.to] = nx;\n                que.emplace(nx, e.to);\n            }\n   \
    \     }\n    }\n    for (auto& x : ds)\n        if (x == inf) x = -1;\n    return\
    \ ds;\n}\n#line 1 \"cpp_src/graph/SCC.hpp\"\n// ABC214H\n// if i -> j, then cmp[i]\
    \ <= cmp[j]\n// g_comp : compressed DAG\n\ntemplate <class T>\nstruct SCC : Graph<T>\
    \ {\n   public:\n    using Graph<T>::Graph;\n    using Graph<T>::g;\n    Graph<T>\
    \ rg;\n\n    V<int> vs, cmp, vis;\n    VV<int> comps;\n\n    // allow multiple\
    \ edges\n    Graph<T> g_comp;\n\n    void dfs(int v) {\n        vis[v] = true;\n\
    \n        for (auto e : g[v]) {\n            if (!vis[e.to]) {\n             \
    \   dfs(e.to);\n            }\n        }\n\n        vs.push_back(v);\n    }\n\n\
    \    void rdfs(int v, int k) {\n        vis[v] = true;\n        cmp[v] = k;\n\n\
    \        for (auto e : rg[v]) {\n            if (!vis[e.to]) {\n             \
    \   rdfs(e.to, k);\n            }\n        }\n    }\n\n    void init() {\n   \
    \     int n = g.size();\n        rg = Graph<T>(n);\n        rep(i, n) {\n    \
    \        for (auto e : g[i]) {\n                rg.add_directed_edge(e.to, e.from,\
    \ e.cost);\n            }\n        }\n\n        vs = cmp = V<int>(n);\n      \
    \  vis = V<int>(n);\n\n        rep(v, n) if (!vis[v]) dfs(v);\n\n        fill(vis.begin(),\
    \ vis.end(), false);\n\n        int k = 0;\n        reverse(vs.begin(), vs.end());\n\
    \n        for (int v : vs) {\n            if (!vis[v]) {\n                rdfs(v,\
    \ k++);\n            }\n        }\n\n        comps.resize(k);\n        rep(v,\
    \ n) { comps[cmp[v]].push_back(v); }\n\n        g_comp = Graph<T>(k);\n\n    \
    \    rep(i, n) {\n            for (auto e : g[i]) {\n                if (cmp[i]\
    \ != cmp[e.to]) {\n                    g_comp.add_directed_edge(cmp[i], cmp[e.to],\
    \ e.cost);\n                }\n            }\n        }\n    }\n};\n#line 143\
    \ \"test/yosupo/scc.test.cpp\"\n#undef call_from_test\n\nint main() {\n    int\
    \ N, M;\n    cin >> N >> M;\n    SCC<int> g(N);\n    g.read(M, 0, 1, 0);\n   \
    \ g.init();\n    auto vv = g.comps;\n    print(SZ(vv));\n    for (auto v : vv)\
    \ {\n        cout << SZ(v) << ' ';\n        print(v);\n    }\n\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n//#pragma GCC\
    \ optimize(\"Ofast\")\n//#pragma GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using pii = pair<int, int>;\ntemplate <class T>\nusing V = vector<T>;\ntemplate\
    \ <class T>\nusing VV = V<V<T>>;\n\ntemplate <class T>\nV<T> make_vec(size_t a)\
    \ {\n    return V<T>(a);\n}\n\ntemplate <class T, class... Ts>\nauto make_vec(size_t\
    \ a, Ts... ts) {\n    return V<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));\n\
    }\n\n#define pb push_back\n#define eb emplace_back\n#define mp make_pair\n#define\
    \ fi first\n#define se second\n#define rep(i, n) rep2(i, 0, n)\n#define rep2(i,\
    \ m, n) for (int i = m; i < (n); i++)\n#define per(i, b) per2(i, 0, b)\n#define\
    \ per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)\n#define ALL(c) (c).begin(),\
    \ (c).end()\n#define SZ(x) ((int)(x).size())\n\nconstexpr ll TEN(int n) { return\
    \ (n == 0) ? 1 : 10 * TEN(n - 1); }\n\ntemplate <class T, class U>\nvoid chmin(T&\
    \ t, const U& u) {\n    if (t > u) t = u;\n}\ntemplate <class T, class U>\nvoid\
    \ chmax(T& t, const U& u) {\n    if (t < u) t = u;\n}\n\ntemplate <class T>\n\
    void mkuni(vector<T>& v) {\n    sort(ALL(v));\n    v.erase(unique(ALL(v)), end(v));\n\
    }\n\ntemplate <class T>\nvector<int> sort_by(const vector<T>& v) {\n    vector<int>\
    \ res(v.size());\n    iota(res.begin(), res.end(), 0);\n    sort(res.begin(),\
    \ res.end(), [&](int i, int j) { return v[i] < v[j]; });\n    return res;\n}\n\
    \ntemplate <class T, class U>\nistream& operator>>(istream& is, pair<T, U>& p)\
    \ {\n    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate <class T, class\
    \ U>\nostream& operator<<(ostream& os, const pair<T, U>& p) {\n    os << \"(\"\
    \ << p.first << \",\" << p.second << \")\";\n    return os;\n}\n\ntemplate <class\
    \ T>\nistream& operator>>(istream& is, vector<T>& v) {\n    for (auto& x : v)\
    \ {\n        is >> x;\n    }\n    return is;\n}\n\ntemplate <class T>\nostream&\
    \ operator<<(ostream& os, const vector<T>& v) {\n    os << \"{\";\n    rep(i,\
    \ v.size()) {\n        if (i) os << \",\";\n        os << v[i];\n    }\n    os\
    \ << \"}\";\n    return os;\n}\n\n#ifdef LOCAL\nvoid debug_out() { cerr << endl;\
    \ }\ntemplate <typename Head, typename... Tail>\nvoid debug_out(Head H, Tail...\
    \ T) {\n    cerr << \" \" << H;\n    debug_out(T...);\n}\n#define debug(...) \\\
    \n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n\
    #define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n\
    #define debug(...) (void(0))\n#define dump(x) (void(0))\n#endif\n\ntemplate <class\
    \ T>\nvoid scan(vector<T>& v, T offset = T(0)) {\n    for (auto& x : v) {\n  \
    \      cin >> x;\n        x += offset;\n    }\n}\n\ntemplate <class T>\nvoid print(T\
    \ x, int suc = 1) {\n    cout << x;\n    if (suc == 1)\n        cout << \"\\n\"\
    ;\n    else if (suc == 2)\n        cout << \" \";\n}\n\ntemplate <class T>\nvoid\
    \ print(const vector<T>& v, int suc = 1) {\n    for (int i = 0; i < v.size();\
    \ ++i)\n        print(v[i], i == int(v.size()) - 1 ? suc : 2);\n}\n\nstruct prepare_io\
    \ {\n    prepare_io() {\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(10);\n    }\n} prep_io;\n\n#define call_from_test\n\
    #include \"../../cpp_src/graph/GraphBase.hpp\"\n#include \"../../cpp_src/graph/SCC.hpp\"\
    \n#undef call_from_test\n\nint main() {\n    int N, M;\n    cin >> N >> M;\n \
    \   SCC<int> g(N);\n    g.read(M, 0, 1, 0);\n    g.init();\n    auto vv = g.comps;\n\
    \    print(SZ(vv));\n    for (auto v : vv) {\n        cout << SZ(v) << ' ';\n\
    \        print(v);\n    }\n\n    return 0;\n}"
  dependsOn:
  - cpp_src/graph/GraphBase.hpp
  - cpp_src/graph/SCC.hpp
  isVerificationFile: true
  path: test/yosupo/scc.test.cpp
  requiredBy: []
  timestamp: '2022-03-21 17:35:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/scc.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/scc.test.cpp
- /verify/test/yosupo/scc.test.cpp.html
title: test/yosupo/scc.test.cpp
---
