---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp_src/graph/GraphBase.hpp
    title: cpp_src/graph/GraphBase.hpp
  - icon: ':heavy_check_mark:'
    path: cpp_src/graph/LCA.hpp
    title: cpp_src/graph/LCA.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/yosupo/lca.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \n//#pragma GCC optimize(\"Ofast\")\n//#pragma GCC optimize(\"unroll-loops\")\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\nusing\
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
    \ end(v));\n}\n\ntemplate <class T, class U>\nostream& operator<<(ostream& os,\
    \ const pair<T, U>& p) {\n    os << \"(\" << p.first << \",\" << p.second << \"\
    )\";\n    return os;\n}\n\ntemplate <class T>\nostream& operator<<(ostream& os,\
    \ const vector<T>& v) {\n    os << \"{\";\n    rep(i, v.size()) {\n        if\
    \ (i) os << \",\";\n        os << v[i];\n    }\n    os << \"}\";\n    return os;\n\
    }\n\n#ifdef LOCAL\nvoid debug_out() { cerr << endl; }\ntemplate <typename Head,\
    \ typename... Tail>\nvoid debug_out(Head H, Tail... T) {\n    cerr << \" \" <<\
    \ H;\n    debug_out(T...);\n}\n#define debug(...) \\\n    cerr << __LINE__ <<\
    \ \" [\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n#define dump(x) cerr\
    \ << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n#define debug(...)\
    \ (void(0))\n#define dump(x) (void(0))\n#endif\n\ntemplate <class T>\nvoid scan(vector<T>&\
    \ v, T offset = T(0)) {\n    for (auto& x : v) {\n        cin >> x;\n        x\
    \ += offset;\n    }\n}\n\ntemplate <class T>\nvoid print(T x, int suc = 1) {\n\
    \    cout << x;\n    if (suc == 1)\n        cout << \"\\n\";\n    else if (suc\
    \ == 2)\n        cout << \" \";\n}\n\ntemplate <class T>\nvoid print(const vector<T>&\
    \ v, int suc = 1) {\n    for (int i = 0; i < v.size(); ++i)\n        print(v[i],\
    \ i == int(v.size()) - 1 ? suc : 2);\n}\n\n#define call_from_test\n#line 2 \"\
    cpp_src/graph/GraphBase.hpp\"\n\ntemplate <class T>\nclass Edge {\n   public:\n\
    \    int from, to, idx;\n    T cost;\n\n    Edge() = default;\n    Edge(int from,\
    \ int to, T cost = T(1), int idx = -1)\n        : from(from), to(to), cost(cost),\
    \ idx(idx) {}\n    operator int() const { return to; }\n};\n\ntemplate <class\
    \ T>\nclass Graph {\n   public:\n    using E = Edge<T>;\n    vector<vector<E>>\
    \ g;\n    vector<E> edges;\n    int es;\n\n    Graph() {}\n    Graph(int n) :\
    \ g(n), edges(0), es(0){};\n\n    int size() const { return g.size(); }\n\n  \
    \  virtual void add_directed_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es++);\n    }\n\n    virtual void add_edge(int from, int to, T cost\
    \ = 1) {\n        g[from].emplace_back(from, to, cost, es);\n        g[to].emplace_back(to,\
    \ from, cost, es++);\n    }\n\n    inline vector<E>& operator[](const int& k)\
    \ { return g[k]; }\n\n    inline const vector<E>& operator[](const int& k) const\
    \ {\n        return g[k];\n    }\n\n    void read(int M, int offset = -1, bool\
    \ directed = false,\n              bool weighted = false) {\n        for (int\
    \ i = 0; i < M; i++) {\n            int a, b;\n            cin >> a >> b;\n  \
    \          a += offset;\n            b += offset;\n            T c = T(1);\n \
    \           if (weighted) cin >> c;\n            edges.emplace_back(a, b, c);\n\
    \            if (directed)\n                add_directed_edge(a, b, c);\n    \
    \        else\n                add_edge(a, b, c);\n        }\n    }\n};\n\ntemplate\
    \ <class T>\nV<T> bfs(const Graph<T>& g, int s = 0) {\n    int n = g.size();\n\
    \    V<T> ds(n, numeric_limits<T>::max() / 2);\n    using P = pair<T, int>;\n\
    \    queue<int> que;\n    que.push(s);\n    ds[s] = 0;\n\n    while (!que.empty())\
    \ {\n        auto v = que.front();\n        que.pop();\n        for (auto e :\
    \ g[v]) {\n            T nx = ds[v] + 1;\n            if (ds[e.to] > nx) {\n \
    \               ds[e.to] = nx;\n                que.push(e.to);\n            }\n\
    \        }\n    }\n    return ds;\n}\n\ntemplate <class T>\nV<T> dijkstra(const\
    \ Graph<T>& g, int s = 0) {\n    int n = g.size();\n    V<T> ds(n, numeric_limits<T>::max()\
    \ / 2);\n    using P = pair<T, int>;\n    priority_queue<P, V<P>, greater<P>>\
    \ que;\n    que.emplace(0, s);\n    ds[s] = 0;\n    while (!que.empty()) {\n \
    \       auto p = que.top();\n        que.pop();\n        int v = p.se;\n     \
    \   if (ds[v] < p.fi) continue;\n        for (auto e : g[v]) {\n            T\
    \ nx = ds[v] + e.cost;\n            if (ds[e.to] > nx) {\n                ds[e.to]\
    \ = nx;\n                que.emplace(nx, e.to);\n            }\n        }\n  \
    \  }\n    return ds;\n}\n#line 1 \"cpp_src/graph/LCA.hpp\"\ntemplate <class E>\n\
    struct LCA {\n    VV<int> anc;\n    V<int> dep;\n    int lg;\n    const Graph<E>&\
    \ g;\n\n    LCA(const Graph<E>& g, int root) : g(g) {\n        int n = g.size();\n\
    \        lg = 1;\n        while ((1 << lg) < n) lg++;\n        anc = VV<int>(lg,\
    \ V<int>(n, -1));\n        dep = V<int>(n);\n        dfs(root, -1, 0);\n\n   \
    \     for (int i = 1; i < lg; i++) {\n            for (int j = 0; j < n; j++)\
    \ {\n                anc[i][j] =\n                    (anc[i - 1][j] == -1) ?\
    \ -1 : anc[i - 1][anc[i - 1][j]];\n            }\n        }\n    }\n\n    void\
    \ dfs(int v, int p, int d) {\n        anc[0][v] = p;\n        dep[v] = d;\n  \
    \      for (auto e : g[v]) {\n            if (e.to == p) continue;\n         \
    \   dfs(e.to, v, d + 1);\n        }\n    }\n\n    int query(int u, int v) {\n\
    \        if (dep[u] < dep[v]) swap(u, v);\n        int df = dep[u] - dep[v];\n\
    \        for (int i = lg - 1; i >= 0; --i) {\n            if ((df >> i) & 1) {\n\
    \                df -= (1 << i);\n                u = anc[i][u];\n           \
    \ }\n        }\n        if (u == v) return u;\n        for (int i = lg - 1; i\
    \ >= 0; --i) {\n            if (anc[i][u] != anc[i][v]) {\n                u =\
    \ anc[i][u];\n                v = anc[i][v];\n            }\n        }\n     \
    \   return anc[0][u];\n    }\n\n    int dist(int a, int b) {\n        int lc =\
    \ query(a, b);\n        return dep[a] + dep[b] - dep[lc] * 2;\n    }\n};\n#line\
    \ 112 \"test/yosupo/lca.test.cpp\"\n#undef call_from_test\n\nint main() {\n  \
    \  int N, Q;\n    scanf(\"%d %d\", &N, &Q);\n    V<int> p(N);\n    Graph<int>\
    \ g(N);\n    for (int i = 1; i < N; ++i) {\n        scanf(\"%d\", &p[i]);\n  \
    \      g.add_edge(p[i], i);\n    }\n    LCA<int> lca(g, 0);\n    while (Q--) {\n\
    \        int a, b;\n        scanf(\"%d %d\", &a, &b);\n        int v = lca.query(a,\
    \ b);\n        printf(\"%d\\n\", v);\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n//#pragma GCC optimize(\"\
    Ofast\")\n//#pragma GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\n\
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
    }\n\ntemplate <class T, class U>\nostream& operator<<(ostream& os, const pair<T,\
    \ U>& p) {\n    os << \"(\" << p.first << \",\" << p.second << \")\";\n    return\
    \ os;\n}\n\ntemplate <class T>\nostream& operator<<(ostream& os, const vector<T>&\
    \ v) {\n    os << \"{\";\n    rep(i, v.size()) {\n        if (i) os << \",\";\n\
    \        os << v[i];\n    }\n    os << \"}\";\n    return os;\n}\n\n#ifdef LOCAL\n\
    void debug_out() { cerr << endl; }\ntemplate <typename Head, typename... Tail>\n\
    void debug_out(Head H, Tail... T) {\n    cerr << \" \" << H;\n    debug_out(T...);\n\
    }\n#define debug(...) \\\n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"\
    ]:\", debug_out(__VA_ARGS__)\n#define dump(x) cerr << __LINE__ << \" \" << #x\
    \ << \" = \" << (x) << endl\n#else\n#define debug(...) (void(0))\n#define dump(x)\
    \ (void(0))\n#endif\n\ntemplate <class T>\nvoid scan(vector<T>& v, T offset =\
    \ T(0)) {\n    for (auto& x : v) {\n        cin >> x;\n        x += offset;\n\
    \    }\n}\n\ntemplate <class T>\nvoid print(T x, int suc = 1) {\n    cout << x;\n\
    \    if (suc == 1)\n        cout << \"\\n\";\n    else if (suc == 2)\n       \
    \ cout << \" \";\n}\n\ntemplate <class T>\nvoid print(const vector<T>& v, int\
    \ suc = 1) {\n    for (int i = 0; i < v.size(); ++i)\n        print(v[i], i ==\
    \ int(v.size()) - 1 ? suc : 2);\n}\n\n#define call_from_test\n#include \"../../cpp_src/graph/GraphBase.hpp\"\
    \n#include \"../../cpp_src/graph/LCA.hpp\"\n#undef call_from_test\n\nint main()\
    \ {\n    int N, Q;\n    scanf(\"%d %d\", &N, &Q);\n    V<int> p(N);\n    Graph<int>\
    \ g(N);\n    for (int i = 1; i < N; ++i) {\n        scanf(\"%d\", &p[i]);\n  \
    \      g.add_edge(p[i], i);\n    }\n    LCA<int> lca(g, 0);\n    while (Q--) {\n\
    \        int a, b;\n        scanf(\"%d %d\", &a, &b);\n        int v = lca.query(a,\
    \ b);\n        printf(\"%d\\n\", v);\n    }\n    return 0;\n}"
  dependsOn:
  - cpp_src/graph/GraphBase.hpp
  - cpp_src/graph/LCA.hpp
  isVerificationFile: true
  path: test/yosupo/lca.test.cpp
  requiredBy: []
  timestamp: '2021-10-08 22:49:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/lca.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/lca.test.cpp
- /verify/test/yosupo/lca.test.cpp.html
title: test/yosupo/lca.test.cpp
---
