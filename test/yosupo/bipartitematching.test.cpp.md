---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp_src/graph/Dinic.hpp
    title: cpp_src/graph/Dinic.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"test/yosupo/bipartitematching.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nusing ll = long long;\nusing pii = pair<int, int>;\ntemplate\
    \ <class T>\nusing V = vector<T>;\ntemplate <class T>\nusing VV = V<V<T>>;\n\n\
    #define pb push_back\n#define eb emplace_back\n#define mp make_pair\n#define fi\
    \ first\n#define se second\n#define rep(i, n) rep2(i, 0, n)\n#define rep2(i, m,\
    \ n) for (int i = m; i < (n); i++)\n#define per(i, b) per2(i, 0, b)\n#define per2(i,\
    \ a, b) for (int i = int(b) - 1; i >= int(a); i--)\n#define ALL(c) (c).begin(),\
    \ (c).end()\n\nconstexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1);\
    \ }\n\ntemplate <class T, class U>\nvoid chmin(T& t, const U& u) {\n    if (t\
    \ > u) t = u;\n}\ntemplate <class T, class U>\nvoid chmax(T& t, const U& u) {\n\
    \    if (t < u) t = u;\n}\n\ntemplate <class T, class U>\nostream& operator<<(ostream&\
    \ os, const pair<T, U>& p) {\n    os << \"(\" << p.first << \",\" << p.second\
    \ << \")\";\n    return os;\n}\n\ntemplate <class T>\nostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    os << \"{\";\n    rep(i, v.size()) {\n      \
    \  if (i) os << \",\";\n        os << v[i];\n    }\n    os << \"}\";\n    return\
    \ os;\n}\n\n#ifdef LOCAL\nvoid debug_out() { cerr << endl; }\ntemplate <typename\
    \ Head, typename... Tail>\nvoid debug_out(Head H, Tail... T) {\n    cerr << \"\
    \ \" << H;\n    debug_out(T...);\n}\n#define debug(...) \\\n    cerr << __LINE__\
    \ << \" [\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n#define dump(x)\
    \ cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n#define debug(...)\
    \ (void(0))\n#define dump(x) (void(0))\n#endif\n\n#define call_from_test\n#line\
    \ 1 \"cpp_src/graph/Dinic.hpp\"\n// O(V^2 E)\nstruct Dinic {\n    using F = ll;\n\
    \    static constexpr F INF = numeric_limits<F>::max();\n\n    struct Edge {\n\
    \        int to, rev;\n        F cap;\n        Edge(int to, F cap, int rev) :\
    \ to(to), cap(cap), rev(rev){};\n    };\n\n    using E = Edge;\n\n    VV<E> g;\n\
    \    V<int> level, iter;\n\n    Dinic() {}\n    Dinic(int n) : g(n), level(n),\
    \ iter(n) {}\n\n    void add_edge(int from, int to, F cap) {\n        g[from].emplace_back(to,\
    \ cap, (int)g[to].size());\n        g[to].emplace_back(from, 0, (int)g[from].size()\
    \ - 1);\n    }\n\n    void bfs(int s) {\n        fill(ALL(level), -1);\n     \
    \   queue<int> que;\n        level[s] = 0;\n        que.push(s);\n\n        while\
    \ (!que.empty()) {\n            int v = que.front();\n            que.pop();\n\
    \            for (auto& e : g[v]) {\n                if (e.cap > 0 && level[e.to]\
    \ < 0) {\n                    level[e.to] = level[v] + 1;\n                  \
    \  que.push(e.to);\n                }\n            }\n        }\n    }\n\n   \
    \ F dfs(int v, int t, F f) {\n        if (v == t) return f;\n        for (int&\
    \ i = iter[v]; i < g[v].size(); i++) {\n            auto& e = g[v][i];\n     \
    \       if (e.cap > 0 && level[v] < level[e.to]) {\n                F d = dfs(e.to,\
    \ t, min(f, e.cap));\n                if (d > 0) {\n                    e.cap\
    \ -= d;\n                    g[e.to][e.rev].cap += d;\n                    return\
    \ d;\n                }\n            }\n        }\n        return 0;\n    }\n\n\
    \    F max_flow(int s, int t) {\n        F flow = 0;\n        while (true) {\n\
    \            bfs(s);\n            if (level[t] < 0) return flow;\n           \
    \ fill(ALL(iter), 0);\n            F f;\n            while ((f = dfs(s, t, INF))\
    \ > 0) flow += f;\n        }\n    }\n};\n#line 68 \"test/yosupo/bipartitematching.test.cpp\"\
    \n#undef call_from_test\n\nint main() {\n    int L, R, M;\n    scanf(\"%d %d %d\"\
    , &L, &R, &M);\n    int n = L + R + 2;\n    int s = n - 2, t = n - 1;\n    Dinic\
    \ g(n);\n    rep(i, M) {\n        int a, b;\n        scanf(\"%d%d\", &a, &b);\n\
    \        g.add_edge(a, b + L, 1);\n    }\n    rep(i, L) g.add_edge(s, i, 1);\n\
    \    rep(i, R) g.add_edge(i + L, t, 1);\n\n    int K = g.max_flow(s, t);\n\n \
    \   printf(\"%d\\n\", K);\n    rep(i, L) {\n        int mt = -1;\n        for\
    \ (auto e : g.g[i])\n            if (e.to >= L && e.to < L + R && e.cap == 0)\
    \ {\n                mt = e.to;\n            }\n        if (mt != -1) {\n    \
    \        printf(\"%d %d\\n\", i, mt - L);\n        }\n    }\n\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include\
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
    #define debug(...) (void(0))\n#define dump(x) (void(0))\n#endif\n\n#define call_from_test\n\
    #include \"../../cpp_src/graph/Dinic.hpp\"\n#undef call_from_test\n\nint main()\
    \ {\n    int L, R, M;\n    scanf(\"%d %d %d\", &L, &R, &M);\n    int n = L + R\
    \ + 2;\n    int s = n - 2, t = n - 1;\n    Dinic g(n);\n    rep(i, M) {\n    \
    \    int a, b;\n        scanf(\"%d%d\", &a, &b);\n        g.add_edge(a, b + L,\
    \ 1);\n    }\n    rep(i, L) g.add_edge(s, i, 1);\n    rep(i, R) g.add_edge(i +\
    \ L, t, 1);\n\n    int K = g.max_flow(s, t);\n\n    printf(\"%d\\n\", K);\n  \
    \  rep(i, L) {\n        int mt = -1;\n        for (auto e : g.g[i])\n        \
    \    if (e.to >= L && e.to < L + R && e.cap == 0) {\n                mt = e.to;\n\
    \            }\n        if (mt != -1) {\n            printf(\"%d %d\\n\", i, mt\
    \ - L);\n        }\n    }\n\n    return 0;\n}"
  dependsOn:
  - cpp_src/graph/Dinic.hpp
  isVerificationFile: true
  path: test/yosupo/bipartitematching.test.cpp
  requiredBy: []
  timestamp: '2020-07-17 17:36:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/bipartitematching.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/bipartitematching.test.cpp
- /verify/test/yosupo/bipartitematching.test.cpp.html
title: test/yosupo/bipartitematching.test.cpp
---
