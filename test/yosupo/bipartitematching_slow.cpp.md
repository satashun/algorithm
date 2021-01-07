---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"test/yosupo/bipartitematching_slow.cpp\"\n#include <bits/stdc++.h>\n\
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
    \ (void(0))\n#define dump(x) (void(0))\n#endif\n\n/*\n#define call_from_test\n\
    #undef call_from_test\n*/\n\nstruct bipartite_matching {\n    int n;\n    VV<int>\
    \ g;\n    V<int> match;\n    V<bool> used;\n    bipartite_matching() {}\n    bipartite_matching(int\
    \ n) : n(n), g(n), match(n), used(n) {}\n\n    void add_edge(int u, int v) {\n\
    \        g[u].push_back(v);\n        g[v].push_back(u);\n    }\n\n    bool dfs(int\
    \ v) {\n        used[v] = true;\n\n        for (int u : g[v]) {\n            int\
    \ w = match[u];\n            if (w < 0 || (!used[w] && dfs(w))) {\n          \
    \      match[v] = u;\n                match[u] = v;\n                return true;\n\
    \            }\n        }\n\n        return false;\n    }\n\n    int calc() {\n\
    \        int res = 0;\n        fill(match.begin(), match.end(), -1);\n\n     \
    \   for (int v = 0; v < n; ++v) {\n            if (match[v] < 0) {\n         \
    \       fill(used.begin(), used.end(), false);\n                res += dfs(v);\n\
    \            }\n        }\n        return res;\n    }\n};\n\nint main() {\n  \
    \  int L, R, M;\n    scanf(\"%d %d %d\", &L, &R, &M);\n    int n = L + R;\n  \
    \  bipartite_matching g(n);\n    rep(i, M) {\n        int a, b;\n        scanf(\"\
    %d%d\", &a, &b);\n        g.add_edge(a, b + L);\n    }\n\n    int K = g.calc();\n\
    \    printf(\"%d\\n\", K);\n    rep(i, L) {\n        if (g.match[i] != -1) {\n\
    \            printf(\"%d %d\\n\", i, g.match[i] - L);\n        }\n    }\n\n  \
    \  return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n\
    using pii = pair<int, int>;\ntemplate <class T>\nusing V = vector<T>;\ntemplate\
    \ <class T>\nusing VV = V<V<T>>;\n\n#define pb push_back\n#define eb emplace_back\n\
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
    #define debug(...) (void(0))\n#define dump(x) (void(0))\n#endif\n\n/*\n#define\
    \ call_from_test\n#undef call_from_test\n*/\n\nstruct bipartite_matching {\n \
    \   int n;\n    VV<int> g;\n    V<int> match;\n    V<bool> used;\n    bipartite_matching()\
    \ {}\n    bipartite_matching(int n) : n(n), g(n), match(n), used(n) {}\n\n   \
    \ void add_edge(int u, int v) {\n        g[u].push_back(v);\n        g[v].push_back(u);\n\
    \    }\n\n    bool dfs(int v) {\n        used[v] = true;\n\n        for (int u\
    \ : g[v]) {\n            int w = match[u];\n            if (w < 0 || (!used[w]\
    \ && dfs(w))) {\n                match[v] = u;\n                match[u] = v;\n\
    \                return true;\n            }\n        }\n\n        return false;\n\
    \    }\n\n    int calc() {\n        int res = 0;\n        fill(match.begin(),\
    \ match.end(), -1);\n\n        for (int v = 0; v < n; ++v) {\n            if (match[v]\
    \ < 0) {\n                fill(used.begin(), used.end(), false);\n           \
    \     res += dfs(v);\n            }\n        }\n        return res;\n    }\n};\n\
    \nint main() {\n    int L, R, M;\n    scanf(\"%d %d %d\", &L, &R, &M);\n    int\
    \ n = L + R;\n    bipartite_matching g(n);\n    rep(i, M) {\n        int a, b;\n\
    \        scanf(\"%d%d\", &a, &b);\n        g.add_edge(a, b + L);\n    }\n\n  \
    \  int K = g.calc();\n    printf(\"%d\\n\", K);\n    rep(i, L) {\n        if (g.match[i]\
    \ != -1) {\n            printf(\"%d %d\\n\", i, g.match[i] - L);\n        }\n\
    \    }\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: test/yosupo/bipartitematching_slow.cpp
  requiredBy: []
  timestamp: '2021-01-07 20:07:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/yosupo/bipartitematching_slow.cpp
layout: document
redirect_from:
- /library/test/yosupo/bipartitematching_slow.cpp
- /library/test/yosupo/bipartitematching_slow.cpp.html
title: test/yosupo/bipartitematching_slow.cpp
---
