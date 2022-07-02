---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: cpp_src/graph/GraphBase.hpp
    title: cpp_src/graph/GraphBase.hpp
  - icon: ':heavy_check_mark:'
    path: cpp_src/graph/helper/ExplicitShortestPath.hpp
    title: cpp_src/graph/helper/ExplicitShortestPath.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/yosupo/shortest_path.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/shortest_path\"\n#pragma region satashun\n//#pragma\
    \ GCC optimize(\"Ofast\")\n//#pragma GCC optimize(\"unroll-loops\")\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nusing uint = unsigned int;\nusing ll\
    \ = long long;\nusing ull = unsigned long long;\nusing pii = pair<int, int>;\n\
    template <class T>\nusing V = vector<T>;\ntemplate <class T>\nusing VV = V<V<T>>;\n\
    \ntemplate <class T>\nV<T> make_vec(size_t a) {\n    return V<T>(a);\n}\n\ntemplate\
    \ <class T, class... Ts>\nauto make_vec(size_t a, Ts... ts) {\n    return V<decltype(make_vec<T>(ts...))>(a,\
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
    \    vector<int> res(v.size());\n    iota(res.begin(), res.end(), 0);\n    stable_sort(res.begin(),\
    \ res.end(),\n                [&](int i, int j) { return v[i] < v[j]; });\n  \
    \  return res;\n}\n\ntemplate <class T, class U>\nistream& operator>>(istream&\
    \ is, pair<T, U>& p) {\n    is >> p.first >> p.second;\n    return is;\n}\n\n\
    template <class T, class U>\nostream& operator<<(ostream& os, const pair<T, U>&\
    \ p) {\n    os << \"(\" << p.first << \",\" << p.second << \")\";\n    return\
    \ os;\n}\n\ntemplate <class T>\nistream& operator>>(istream& is, vector<T>& v)\
    \ {\n    for (auto& x : v) {\n        is >> x;\n    }\n    return is;\n}\n\ntemplate\
    \ <class T>\nostream& operator<<(ostream& os, const vector<T>& v) {\n    os <<\
    \ \"{\";\n    rep(i, v.size()) {\n        if (i) os << \",\";\n        os << v[i];\n\
    \    }\n    os << \"}\";\n    return os;\n}\n\n#ifdef LOCAL\nvoid debug_out()\
    \ { cerr << endl; }\ntemplate <typename Head, typename... Tail>\nvoid debug_out(Head\
    \ H, Tail... T) {\n    cerr << \" \" << H;\n    debug_out(T...);\n}\n#define debug(...)\
    \ \\\n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n\
    #define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n\
    #define debug(...) (void(0))\n#define dump(x) (void(0))\n#endif\n\ntemplate <class\
    \ T>\nvoid scan(vector<T>& v, T offset = T(0)) {\n    for (auto& x : v) {\n  \
    \      cin >> x;\n        x += offset;\n    }\n}\n\ntemplate <class T>\nvoid print(T\
    \ x, int suc = 1) {\n    cout << x;\n    if (suc == 1)\n        cout << \"\\n\"\
    ;\n    else if (suc == 2)\n        cout << \" \";\n}\n\ntemplate <class T>\nvoid\
    \ print(const vector<T>& v, int suc = 1) {\n    for (int i = 0; i < v.size();\
    \ ++i)\n        print(v[i], i == int(v.size()) - 1 ? suc : 2);\n}\n\ntemplate\
    \ <class T>\nvoid show(T x) {\n    print(x, 1);\n}\n\ntemplate <typename Head,\
    \ typename... Tail>\nvoid show(Head H, Tail... T) {\n    print(H, 2);\n    show(T...);\n\
    }\n\nstruct prepare_io {\n    prepare_io() {\n        cin.tie(nullptr);\n    \
    \    ios::sync_with_stdio(false);\n        cout << fixed << setprecision(10);\n\
    \    }\n} prep_io;\n#pragma endregion satashun\n\n#define call_from_test\n#line\
    \ 1 \"cpp_src/graph/GraphBase.hpp\"\ntemplate <class T>\nclass Edge {\n   public:\n\
    \    int from, to, idx;\n    T cost;\n\n    Edge() = default;\n    Edge(int from,\
    \ int to, T cost = T(1), int idx = -1)\n        : from(from), to(to), cost(cost),\
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
    \   add_edge(a, b, c);\n        }\n    }\n};\n#line 1 \"cpp_src/graph/helper/ExplicitShortestPath.hpp\"\
    \n// ABC222E\n// ABC218F\n// dfs tree only with shortest paths\ntemplate <class\
    \ T>\ntuple<V<T>, V<int>, V<Edge<T>>> bfs_with_path(const Graph<T>& g, int s =\
    \ 0,\n                                              int ban = -1) {\n    using\
    \ E = Edge<T>;\n    const T inf = numeric_limits<T>::max() / 2;\n    int n = g.size();\n\
    \n    V<T> ds(n, inf);\n    using P = pair<T, int>;\n    queue<int> que;\n   \
    \ que.push(s);\n    ds[s] = 0;\n    V<int> par(n, -1);\n    V<E> par_edge(n);\n\
    \n    while (!que.empty()) {\n        auto v = que.front();\n        que.pop();\n\
    \        for (auto e : g[v]) {\n            if (e.idx == ban) continue;\n    \
    \        T nx = ds[v] + e.cost;\n            if (ds[e.to] > nx) {\n          \
    \      par[e.to] = v;\n                par_edge[e.to] = e;\n                ds[e.to]\
    \ = nx;\n                que.push(e.to);\n            }\n        }\n    }\n\n\
    \    for (auto& x : ds)\n        if (x == inf) x = -1;\n    return make_tuple(ds,\
    \ par, par_edge);\n}\n\n// https://judge.yosupo.jp/problem/shortest_path\ntemplate\
    \ <class T>\ntuple<V<T>, V<int>, V<Edge<T>>> dijkstra_with_path(const Graph<T>&\
    \ g, int s = 0,\n                                                   int ban =\
    \ -1) {\n    using E = Edge<T>;\n    const T inf = numeric_limits<T>::max() /\
    \ 2;\n    int n = g.size();\n\n    V<T> ds(n, inf);\n    using P = pair<T, int>;\n\
    \    priority_queue<P, V<P>, greater<P>> que;\n    que.emplace(0, s);\n    ds[s]\
    \ = 0;\n\n    V<int> par(n, -1);\n    V<E> par_edge(n);\n\n    while (!que.empty())\
    \ {\n        auto p = que.top();\n        que.pop();\n        int v = p.se;\n\
    \        if (ds[v] < p.fi) continue;\n        for (auto e : g[v]) {\n        \
    \    T nx = ds[v] + e.cost;\n            if (ds[e.to] > nx) {\n              \
    \  ds[e.to] = nx;\n                par[e.to] = v;\n                par_edge[e.to]\
    \ = e;\n                que.emplace(nx, e.to);\n            }\n        }\n   \
    \ }\n\n    for (auto& x : ds)\n        if (x == inf) x = -1;\n    return make_tuple(ds,\
    \ par, par_edge);\n}\n#line 157 \"test/yosupo/shortest_path.test.cpp\"\n#undef\
    \ call_from_test\n\nvoid slv() {\n    int N, M, s, t;\n    cin >> N >> M >> s\
    \ >> t;\n    Graph<ll> g(N);\n    g.read(M, 0, 1, 1);\n    auto [ds, par, par_edge]\
    \ = dijkstra_with_path(g, s);\n    ll X = ds[t];\n    if (X == -1) {\n       \
    \ show(-1);\n        return;\n    }\n    V<pii> es;\n    {\n        int v = t;\n\
    \        while (v != s) {\n            es.eb(par[v], v);\n            v = par[v];\n\
    \        }\n    }\n    reverse(ALL(es));\n    show(X, SZ(es));\n    for (auto\
    \ [a, b] : es) {\n        show(a, b);\n    }\n}\n\nint main() {\n    int cases\
    \ = 1;\n    // cin >> cases;\n    rep(i, cases) slv();\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#pragma\
    \ region satashun\n//#pragma GCC optimize(\"Ofast\")\n//#pragma GCC optimize(\"\
    unroll-loops\")\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing uint\
    \ = unsigned int;\nusing ll = long long;\nusing ull = unsigned long long;\nusing\
    \ pii = pair<int, int>;\ntemplate <class T>\nusing V = vector<T>;\ntemplate <class\
    \ T>\nusing VV = V<V<T>>;\n\ntemplate <class T>\nV<T> make_vec(size_t a) {\n \
    \   return V<T>(a);\n}\n\ntemplate <class T, class... Ts>\nauto make_vec(size_t\
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
    \ res(v.size());\n    iota(res.begin(), res.end(), 0);\n    stable_sort(res.begin(),\
    \ res.end(),\n                [&](int i, int j) { return v[i] < v[j]; });\n  \
    \  return res;\n}\n\ntemplate <class T, class U>\nistream& operator>>(istream&\
    \ is, pair<T, U>& p) {\n    is >> p.first >> p.second;\n    return is;\n}\n\n\
    template <class T, class U>\nostream& operator<<(ostream& os, const pair<T, U>&\
    \ p) {\n    os << \"(\" << p.first << \",\" << p.second << \")\";\n    return\
    \ os;\n}\n\ntemplate <class T>\nistream& operator>>(istream& is, vector<T>& v)\
    \ {\n    for (auto& x : v) {\n        is >> x;\n    }\n    return is;\n}\n\ntemplate\
    \ <class T>\nostream& operator<<(ostream& os, const vector<T>& v) {\n    os <<\
    \ \"{\";\n    rep(i, v.size()) {\n        if (i) os << \",\";\n        os << v[i];\n\
    \    }\n    os << \"}\";\n    return os;\n}\n\n#ifdef LOCAL\nvoid debug_out()\
    \ { cerr << endl; }\ntemplate <typename Head, typename... Tail>\nvoid debug_out(Head\
    \ H, Tail... T) {\n    cerr << \" \" << H;\n    debug_out(T...);\n}\n#define debug(...)\
    \ \\\n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n\
    #define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n\
    #define debug(...) (void(0))\n#define dump(x) (void(0))\n#endif\n\ntemplate <class\
    \ T>\nvoid scan(vector<T>& v, T offset = T(0)) {\n    for (auto& x : v) {\n  \
    \      cin >> x;\n        x += offset;\n    }\n}\n\ntemplate <class T>\nvoid print(T\
    \ x, int suc = 1) {\n    cout << x;\n    if (suc == 1)\n        cout << \"\\n\"\
    ;\n    else if (suc == 2)\n        cout << \" \";\n}\n\ntemplate <class T>\nvoid\
    \ print(const vector<T>& v, int suc = 1) {\n    for (int i = 0; i < v.size();\
    \ ++i)\n        print(v[i], i == int(v.size()) - 1 ? suc : 2);\n}\n\ntemplate\
    \ <class T>\nvoid show(T x) {\n    print(x, 1);\n}\n\ntemplate <typename Head,\
    \ typename... Tail>\nvoid show(Head H, Tail... T) {\n    print(H, 2);\n    show(T...);\n\
    }\n\nstruct prepare_io {\n    prepare_io() {\n        cin.tie(nullptr);\n    \
    \    ios::sync_with_stdio(false);\n        cout << fixed << setprecision(10);\n\
    \    }\n} prep_io;\n#pragma endregion satashun\n\n#define call_from_test\n#include\
    \ \"../../cpp_src/graph/GraphBase.hpp\"\n#include \"../../cpp_src/graph/helper/ExplicitShortestPath.hpp\"\
    \n#undef call_from_test\n\nvoid slv() {\n    int N, M, s, t;\n    cin >> N >>\
    \ M >> s >> t;\n    Graph<ll> g(N);\n    g.read(M, 0, 1, 1);\n    auto [ds, par,\
    \ par_edge] = dijkstra_with_path(g, s);\n    ll X = ds[t];\n    if (X == -1) {\n\
    \        show(-1);\n        return;\n    }\n    V<pii> es;\n    {\n        int\
    \ v = t;\n        while (v != s) {\n            es.eb(par[v], v);\n          \
    \  v = par[v];\n        }\n    }\n    reverse(ALL(es));\n    show(X, SZ(es));\n\
    \    for (auto [a, b] : es) {\n        show(a, b);\n    }\n}\n\nint main() {\n\
    \    int cases = 1;\n    // cin >> cases;\n    rep(i, cases) slv();\n\n    return\
    \ 0;\n}"
  dependsOn:
  - cpp_src/graph/GraphBase.hpp
  - cpp_src/graph/helper/ExplicitShortestPath.hpp
  isVerificationFile: true
  path: test/yosupo/shortest_path.test.cpp
  requiredBy: []
  timestamp: '2022-07-02 19:40:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/shortest_path.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/shortest_path.test.cpp
- /verify/test/yosupo/shortest_path.test.cpp.html
title: test/yosupo/shortest_path.test.cpp
---
