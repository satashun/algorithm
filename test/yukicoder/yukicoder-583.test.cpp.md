---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: cpp_src/data_structure/DisjointSetUnion.hpp
    title: cpp_src/data_structure/DisjointSetUnion.hpp
  - icon: ':x:'
    path: cpp_src/graph/EulerianTrail.hpp
    title: Eulerian Trail
  - icon: ':question:'
    path: cpp_src/graph/GraphBase.hpp
    title: cpp_src/graph/GraphBase.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/583
    links:
    - https://yukicoder.me/problems/no/583
  bundledCode: "#line 1 \"test/yukicoder/yukicoder-583.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/583\"\n#pragma region satashun\n//#pragma\
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
    \ 1 \"cpp_src/data_structure/DisjointSetUnion.hpp\"\nclass unionfind {\n    vector<int>\
    \ par, rank;\n\n   public:\n    void init(int n) {\n        par.resize(n);\n \
    \       rank.resize(n);\n\n        for (int i = 0; i < n; i++) {\n           \
    \ par[i] = i;\n            rank[i] = 0;\n        }\n    }\n\n    unionfind() {}\n\
    \    unionfind(int n) { init(n); }\n\n    int find(int x) {\n        if (par[x]\
    \ == x)\n            return x;\n        else\n            return par[x] = find(par[x]);\n\
    \    }\n\n    bool unite(int x, int y) {\n        x = find(x);\n        y = find(y);\n\
    \        if (x == y) return false;\n\n        if (rank[x] < rank[y])\n       \
    \     par[x] = y;\n        else {\n            par[y] = x;\n            if (rank[x]\
    \ == rank[y]) ++rank[x];\n        }\n        return true;\n    }\n\n    bool same(int\
    \ x, int y) { return (find(x) == find(y)); }\n};\n#line 1 \"cpp_src/graph/EulerianTrail.hpp\"\
    \n// modified https://ei1333.github.io/library/graph/others/eulerian-trail.hpp\n\
    // allow multiple edges and self loops, multiple components\ntemplate <class T,\
    \ bool directed>\nstruct EulerianTrail : Graph<T> {\n   public:\n    using Graph<T>::g;\n\
    \    using Graph<T>::Graph;\n    using Graph<T>::edges;\n    using Graph<T>::es;\n\
    \    using E = Edge<T>;\n\n    V<int> used_vertex, used_edge, deg;\n\n    void\
    \ init(int n) {\n        deg.assign(n, 0);\n        used_vertex.assign(n, 0);\n\
    \    }\n\n    void add_directed_edge(int from, int to, T cost = 1) {\n       \
    \ g[from].emplace_back(from, to, cost, es++);\n        deg[from]++;\n        deg[to]--;\n\
    \    }\n\n    void add_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n        deg[from]++;\n\
    \        deg[to]++;\n    }\n\n    EulerianTrail(int n) : Graph<T>(n), used_vertex(n),\
    \ deg(n) {}\n\n    E get_edge(int idx) const { return edges[idx]; }\n\n    VV<int>\
    \ enumerate_eulerian_trail() {\n        if (directed) {\n            for (auto&\
    \ v : deg)\n                if (v != 0) return {};\n        } else {\n       \
    \     for (auto& v : deg)\n                if (v & 1) return {};\n        }\n\
    \        used_edge.assign(es, 0);\n        VV<int> res;\n        rep(i, g.size())\
    \ {\n            if (!SZ(g[i]) || used_vertex[i]) continue;\n            res.push_back(go(i));\n\
    \        }\n        return res;\n    }\n\n    // yukicoder 583\n    VV<int> enumerate_semi_eulerian_trail()\
    \ {\n        unionfind uf(g.size());\n        for (auto& e : edges) {\n      \
    \      uf.unite(e.from, e.to);\n        }\n        VV<int> group(g.size());\n\
    \        rep(i, g.size()) group[uf.find(i)].push_back(i);\n\n        VV<int> res;\n\
    \        used_edge.assign(es, 0);\n\n        for (auto& vs : group) {\n      \
    \      if (!SZ(vs)) continue;\n            int s = -1, t = -1;\n            if\
    \ (directed) {\n                for (auto& v : vs) {\n                    if (abs(deg[v])\
    \ > 1) {\n                        return {};\n                    } else if (deg[v]\
    \ == 1) {\n                        if (s != -1) return {};\n                 \
    \       s = v;\n                    }\n                }\n            } else {\n\
    \                for (auto& v : vs) {\n                    if (deg[v] & 1) {\n\
    \                        if (s == -1)\n                            s = v;\n  \
    \                      else if (t == -1)\n                            t = v;\n\
    \                        else\n                            return {};\n      \
    \              }\n                }\n            }\n            debug(s, t);\n\
    \            if (s == -1) s = vs[0];\n            res.emplace_back(go(s));\n \
    \           if (!SZ(res.back())) res.pop_back();\n        }\n        return res;\n\
    \    }\n\n    // return {id of edges}\n    V<int> go(int s) {\n        stack<pair<int,\
    \ int>> st;\n        V<int> ord;\n        st.emplace(s, -1);\n        while (!st.empty())\
    \ {\n            int idx = st.top().first;\n            used_vertex[idx] = true;\n\
    \            if (g[idx].empty()) {\n                ord.emplace_back(st.top().second);\n\
    \                st.pop();\n            } else {\n                auto e = g[idx].back();\n\
    \                g[idx].pop_back();\n                if (used_edge[e.idx]) continue;\n\
    \                used_edge[e.idx] = true;\n                st.emplace(e.to, e.idx);\n\
    \            }\n        }\n        ord.pop_back();\n        reverse(ord.begin(),\
    \ ord.end());\n        return ord;\n    }\n};\n#line 1 \"cpp_src/graph/GraphBase.hpp\"\
    \ntemplate <class T>\nclass Edge {\n   public:\n    int from, to, idx;\n    T\
    \ cost;\n\n    Edge() = default;\n    Edge(int from, int to, T cost = T(1), int\
    \ idx = -1)\n        : from(from), to(to), cost(cost), idx(idx) {}\n    operator\
    \ int() const { return to; }\n\n    bool operator<(const Edge& e) const { return\
    \ cost < e.cost; }\n};\n\ntemplate <class T>\nclass Graph {\n   public:\n    using\
    \ E = Edge<T>;\n    vector<vector<E>> g;\n    vector<E> edges;\n    int es;\n\n\
    \    Graph() {}\n    Graph(int n) : g(n), edges(0), es(0){};\n\n    int size()\
    \ const { return g.size(); }\n\n    virtual void add_directed_edge(int from, int\
    \ to, T cost = 1) {\n        g[from].emplace_back(from, to, cost, es++);\n   \
    \ }\n\n    virtual void add_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n\n\
    \    inline vector<E>& operator[](const int& k) { return g[k]; }\n\n    inline\
    \ const vector<E>& operator[](const int& k) const {\n        return g[k];\n  \
    \  }\n\n    void read(int M, int offset = -1, bool directed = false,\n       \
    \       bool weighted = false) {\n        for (int i = 0; i < M; i++) {\n    \
    \        int a, b;\n            cin >> a >> b;\n            a += offset;\n   \
    \         b += offset;\n            T c = T(1);\n            if (weighted) cin\
    \ >> c;\n            edges.emplace_back(a, b, c);\n            if (directed)\n\
    \                add_directed_edge(a, b, c);\n            else\n             \
    \   add_edge(a, b, c);\n        }\n    }\n};\n#line 158 \"test/yukicoder/yukicoder-583.test.cpp\"\
    \n#undef call_from_test\n\nint main() {\n    int N, M;\n    cin >> N >> M;\n \
    \   V<int> A(M), B(M);\n    EulerianTrail<int, false> g(N);\n    g.read(M, 0);\n\
    \n    auto res = g.enumerate_semi_eulerian_trail();\n    show(SZ(res) == 1 ? \"\
    YES\" : \"NO\");\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/583\"\n#pragma region\
    \ satashun\n//#pragma GCC optimize(\"Ofast\")\n//#pragma GCC optimize(\"unroll-loops\"\
    )\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing uint = unsigned int;\n\
    using ll = long long;\nusing ull = unsigned long long;\nusing pii = pair<int,\
    \ int>;\ntemplate <class T>\nusing V = vector<T>;\ntemplate <class T>\nusing VV\
    \ = V<V<T>>;\n\ntemplate <class T>\nV<T> make_vec(size_t a) {\n    return V<T>(a);\n\
    }\n\ntemplate <class T, class... Ts>\nauto make_vec(size_t a, Ts... ts) {\n  \
    \  return V<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));\n}\n\n#define\
    \ pb push_back\n#define eb emplace_back\n#define mp make_pair\n#define fi first\n\
    #define se second\n#define rep(i, n) rep2(i, 0, n)\n#define rep2(i, m, n) for\
    \ (int i = m; i < (n); i++)\n#define per(i, b) per2(i, 0, b)\n#define per2(i,\
    \ a, b) for (int i = int(b) - 1; i >= int(a); i--)\n#define ALL(c) (c).begin(),\
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
    \ \"../../cpp_src/data_structure/DisjointSetUnion.hpp\"\n#include \"../../cpp_src/graph/EulerianTrail.hpp\"\
    \n#include \"../../cpp_src/graph/GraphBase.hpp\"\n#undef call_from_test\n\nint\
    \ main() {\n    int N, M;\n    cin >> N >> M;\n    V<int> A(M), B(M);\n    EulerianTrail<int,\
    \ false> g(N);\n    g.read(M, 0);\n\n    auto res = g.enumerate_semi_eulerian_trail();\n\
    \    show(SZ(res) == 1 ? \"YES\" : \"NO\");\n    return 0;\n}"
  dependsOn:
  - cpp_src/data_structure/DisjointSetUnion.hpp
  - cpp_src/graph/EulerianTrail.hpp
  - cpp_src/graph/GraphBase.hpp
  isVerificationFile: true
  path: test/yukicoder/yukicoder-583.test.cpp
  requiredBy: []
  timestamp: '2022-07-02 20:49:02+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/yukicoder-583.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/yukicoder-583.test.cpp
- /verify/test/yukicoder/yukicoder-583.test.cpp.html
title: test/yukicoder/yukicoder-583.test.cpp
---
