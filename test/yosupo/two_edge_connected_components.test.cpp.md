---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ test/yosupo/two_edge_connected_components.test.cpp: line 124: #pragma once found\
    \ in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
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
    \ i == int(v.size()) - 1 ? suc : 2);\n}\n\nstruct prepare_io {\n    prepare_io()\
    \ {\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n       \
    \ cout << fixed << setprecision(10);\n    }\n} prep_io;\n\n/*\n#define call_from_test\n\
    #include \"../../cpp_src/graph/GraphBase.hpp\"\n#include \"../../cpp_src/graph/LCA.hpp\"\
    \n#undef call_from_test\n*/\n\n#pragma once\n\ntemplate <class T>\nclass Edge\
    \ {\n   public:\n    int from, to, idx;\n    T cost;\n\n    Edge() = default;\n\
    \    Edge(int from, int to, T cost = T(1), int idx = -1)\n        : from(from),\
    \ to(to), cost(cost), idx(idx) {}\n    operator int() const { return to; }\n};\n\
    \ntemplate <class T>\nclass Graph {\n   public:\n    using E = Edge<T>;\n    vector<vector<E>>\
    \ g;\n    vector<E> edges;\n    int es;\n\n    Graph() {}\n    Graph(int n) :\
    \ g(n), edges(0), es(0){};\n\n    int size() const { return g.size(); }\n\n  \
    \  virtual void add_directed_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es++);\n    }\n\n    virtual void add_edge(int from, int to, T cost\
    \ = 1) {\n        g[from].emplace_back(from, to, cost, es);\n        g[to].emplace_back(to,\
    \ from, cost, es++);\n    }\n\n    inline vector<E>& operator[](const int& k)\
    \ { return g[k]; }\n\n    inline const vector<E>& operator[](const int& k) const\
    \ { return g[k]; }\n\n    void read(int M, int offset = -1, bool directed = false,\n\
    \              bool weighted = false) {\n        for (int i = 0; i < M; i++) {\n\
    \            int a, b;\n            cin >> a >> b;\n            a += offset;\n\
    \            b += offset;\n            T c = T(1);\n            if (weighted)\
    \ cin >> c;\n            edges.emplace_back(a, b, c);\n            if (directed)\n\
    \                add_directed_edge(a, b, c);\n            else\n             \
    \   add_edge(a, b, c);\n        }\n    }\n};\n\ntemplate <class T>\nV<T> bfs(const\
    \ Graph<T>& g, int s = 0) {\n    int n = g.size();\n    V<T> ds(n, numeric_limits<T>::max()\
    \ / 2);\n    using P = pair<T, int>;\n    queue<int> que;\n    que.push(s);\n\
    \    ds[s] = 0;\n\n    while (!que.empty()) {\n        auto v = que.front();\n\
    \        que.pop();\n        for (auto e : g[v]) {\n            T nx = ds[v] +\
    \ 1;\n            if (ds[e.to] > nx) {\n                ds[e.to] = nx;\n     \
    \           que.push(e.to);\n            }\n        }\n    }\n    return ds;\n\
    }\n\ntemplate <class T>\nV<T> dijkstra(const Graph<T>& g, int s = 0) {\n    int\
    \ n = g.size();\n    V<T> ds(n, numeric_limits<T>::max() / 2);\n    using P =\
    \ pair<T, int>;\n    priority_queue<P, V<P>, greater<P>> que;\n    que.emplace(0,\
    \ s);\n    ds[s] = 0;\n    while (!que.empty()) {\n        auto p = que.top();\n\
    \        que.pop();\n        int v = p.se;\n        if (ds[v] < p.fi) continue;\n\
    \        for (auto e : g[v]) {\n            T nx = ds[v] + e.cost;\n         \
    \   if (ds[e.to] > nx) {\n                ds[e.to] = nx;\n                que.emplace(nx,\
    \ e.to);\n            }\n        }\n    }\n    return ds;\n}\n\n// allow self\
    \ loops, multiple edges\ntemplate <class T>\nstruct LowLink : Graph<T> {\n   public:\n\
    \    using Graph<T>::Graph;\n    using Graph<T>::g;\n    vector<int> ord, low,\
    \ articulation;\n    vector<Edge<T>> bridge;\n\n    virtual void build() {\n \
    \       used.assign(g.size(), 0);\n        ord.assign(g.size(), 0);\n        low.assign(g.size(),\
    \ 0);\n        int k = 0;\n        for (int i = 0; i < g.size(); i++) {\n    \
    \        if (!used[i]) dfs(i, -1, k);\n        }\n    }\n\n   private:\n    vector<int>\
    \ used;\n\n    void dfs(int v, int par, int& k) {\n        used[v] = true;\n \
    \       low[v] = ord[v] = k++;\n        bool is_articulation = false, seen = false;\n\
    \        int cnt = 0;\n        for (auto& e : g[v]) {\n            if (e.to ==\
    \ par && !exchange(seen, true)) {\n                continue;\n            }\n\
    \            if (!used[e.to]) {\n                ++cnt;\n                dfs(e.to,\
    \ v, k);\n                low[v] = min(low[v], low[e.to]);\n                is_articulation\
    \ |= (par >= 0 && low[e.to] >= ord[v]);\n                if (ord[v] < low[e.to])\
    \ bridge.emplace_back(e);\n            } else {\n                low[v] = min(low[v],\
    \ ord[e.to]);\n            }\n        }\n        is_articulation |= (par == -1\
    \ && cnt > 1);\n        if (is_articulation) articulation.push_back(v);\n    }\n\
    };\n\n// tree : u-v -> comp[u]-comp[v]\ntemplate <class T>\nstruct TwoEdgeConnectedComponents\
    \ : LowLink<T> {\n   public:\n    using LowLink<T>::LowLink;\n    using LowLink<T>::g;\n\
    \    using LowLink<T>::ord;\n    using LowLink<T>::low;\n    using LowLink<T>::bridge;\n\
    \n    vector<int> comp;\n    Graph<T> tree;\n    vector<vector<int>> group;\n\n\
    \    void build() {\n        LowLink<T>::build();\n        comp.assign(g.size(),\
    \ -1);\n        int k = 0;\n        for (int i = 0; i < g.size(); i++) {\n   \
    \         if (comp[i] == -1) dfs(i, -1, k);\n        }\n        group.resize(k);\n\
    \        for (int i = 0; i < g.size(); i++) {\n            group[comp[i]].emplace_back(i);\n\
    \        }\n        tree = Graph<T>(k);\n        for (auto& e : bridge) {\n  \
    \          tree.add_edge(comp[e.from], comp[e.to], e.cost);\n        }\n    }\n\
    \n    void show() {\n        print(group.size());\n        for (auto& v : group)\
    \ {\n            cout << SZ(v) << ' ';\n            print(v);\n        }\n   \
    \ }\n\n   private:\n    void dfs(int idx, int par, int& k) {\n        if (par\
    \ >= 0 && ord[par] >= low[idx])\n            comp[idx] = comp[par];\n        else\n\
    \            comp[idx] = k++;\n        for (auto& e : g[idx]) {\n            if\
    \ (comp[e.to] == -1) dfs(e.to, idx, k);\n        }\n    }\n};\n\nint main() {\n\
    \    int N, M;\n    cin >> N >> M;\n\n    TwoEdgeConnectedComponents<int> g(N);\n\
    \    g.read(M, 0);\n    g.build();\n    g.show();\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/two_edge_connected_components.test.cpp
  requiredBy: []
  timestamp: '2021-10-25 19:28:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/two_edge_connected_components.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/two_edge_connected_components.test.cpp
- /verify/test/yosupo/two_edge_connected_components.test.cpp.html
title: test/yosupo/two_edge_connected_components.test.cpp
---