---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp_src/graph/LCA.hpp
    title: cpp_src/graph/LCA.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/yosupo/lca.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n\
    using pii = pair<int, int>;\ntemplate<class T> using V = vector<T>;\ntemplate<class\
    \ T> using VV = V<V<T>>;\n\n#define pb push_back\n#define eb emplace_back\n#define\
    \ mp make_pair\n#define fi first\n#define se second\n#define rep(i,n) rep2(i,0,n)\n\
    #define rep2(i,m,n) for(int i=m;i<(n);i++)\n#define ALL(c) (c).begin(),(c).end()\n\
    \n#ifdef LOCAL\n#define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" <<\
    \ (x) << endl\n#else \n#define dump(x) true\n#endif\n\nconstexpr ll TEN(int n)\
    \ { return (n == 0) ? 1 : 10 * TEN(n-1); }\n\ntemplate<class T, class U> void\
    \ chmin(T& t, const U& u) { if (t > u) t = u; }\ntemplate<class T, class U> void\
    \ chmax(T& t, const U& u) { if (t < u) t = u; }\n\ntemplate<class T, class U>\n\
    ostream& operator<<(ostream& os, const pair<T, U>& p) {\n\tos<<\"(\"<<p.first<<\"\
    ,\"<<p.second<<\")\";\n\treturn os;\n}\n\ntemplate<class T>\nostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n\tos<<\"{\";\n\trep(i, v.size()) {\n\t\tif (i) os<<\"\
    ,\";\n\t\tos<<v[i];\n\t}\n\tos<<\"}\";\n\treturn os;\n}\n\n#define call_from_test\n\
    #line 1 \"cpp_src/graph/LCA.hpp\"\n//E : int or edge class\n\ntemplate<class E>\n\
    struct LCA {\n\tVV<int> anc;\n\tV<int> dep;\n\tint lg;\n\tconst VV<E>& g;\n\n\t\
    LCA(const VV<E>& g, int root) : g(g) {\n\t\tint n = g.size();\n\t\tlg = 1;\n\t\
    \twhile ((1 << lg) < n) lg++;\n\t\tanc = VV<int>(lg, V<int>(n, -1));\n\t\tdep\
    \ = V<int>(n);\n\t\tdfs(root, -1, 0);\n\n\t\tfor (int i = 1; i < lg; i++) {\n\t\
    \t\tfor (int j = 0; j < n; j++) {\n\t\t\t\tanc[i][j] = (anc[i - 1][j] == -1) ?\
    \ -1 : anc[i - 1][anc[i - 1][j]];\n\t\t\t}\n\t\t}\t\t\n\t}\n\n\tvoid dfs(int v,\
    \ int p, int d) {\n\t\tanc[0][v] = p;\n\t\tdep[v] = d;\n\t\tfor (auto e : g[v])\
    \ {\n\t\t\tint to = e;\n\t\t\tif (to == p) continue;\n\t\t\tdfs(to, v, d + 1);\n\
    \t\t}\n\t}\n\n\tint query(int u, int v) {\n\t\tif (dep[u] < dep[v]) swap(u, v);\n\
    \t\tint df = dep[u] - dep[v];\n\t\tfor (int i = lg - 1; i >= 0; --i) {\n\t\t\t\
    if ((df >> i) & 1) {\n\t\t\t\tdf -= (1 << i);\n\t\t\t\tu = anc[i][u];\n\t\t\t\
    }\n\t\t}\n\t\tif (u == v) return u;\n\t\tfor (int i = lg - 1; i >= 0; --i) {\n\
    \t\t\tif (anc[i][u] != anc[i][v]) {\n\t\t\t\tu = anc[i][u];\n\t\t\t\tv = anc[i][v];\n\
    \t\t\t}\n\t\t}\n\t\treturn anc[0][u];\n\t}\n};\n#line 50 \"test/yosupo/lca.test.cpp\"\
    \n#undef call_from_test\n\nint main() {\n\tint N, Q; scanf(\"%d %d\", &N, &Q);\n\
    \tV<int> p(N);\n\tVV<int> g(N);\n\tfor (int i = 1; i < N; ++i) {\n\t\tscanf(\"\
    %d\", &p[i]);\n\t\tg[p[i]].pb(i);\n\t}\n\tLCA<int> lca(g, 0);\n\twhile (Q--) {\n\
    \t\tint a, b;\n\t\tscanf(\"%d %d\", &a, &b);\n\t\tint v = lca.query(a, b);\n\t\
    \tprintf(\"%d\\n\", v);\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nusing ll = long long;\nusing pii = pair<int, int>;\ntemplate<class\
    \ T> using V = vector<T>;\ntemplate<class T> using VV = V<V<T>>;\n\n#define pb\
    \ push_back\n#define eb emplace_back\n#define mp make_pair\n#define fi first\n\
    #define se second\n#define rep(i,n) rep2(i,0,n)\n#define rep2(i,m,n) for(int i=m;i<(n);i++)\n\
    #define ALL(c) (c).begin(),(c).end()\n\n#ifdef LOCAL\n#define dump(x) cerr <<\
    \ __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else \n#define dump(x) true\n\
    #endif\n\nconstexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }\n\n\
    template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }\n\
    template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }\n\
    \ntemplate<class T, class U>\nostream& operator<<(ostream& os, const pair<T, U>&\
    \ p) {\n\tos<<\"(\"<<p.first<<\",\"<<p.second<<\")\";\n\treturn os;\n}\n\ntemplate<class\
    \ T>\nostream& operator<<(ostream& os, const vector<T>& v) {\n\tos<<\"{\";\n\t\
    rep(i, v.size()) {\n\t\tif (i) os<<\",\";\n\t\tos<<v[i];\n\t}\n\tos<<\"}\";\n\t\
    return os;\n}\n\n#define call_from_test\n#include \"../../cpp_src/graph/LCA.hpp\"\
    \n#undef call_from_test\n\nint main() {\n\tint N, Q; scanf(\"%d %d\", &N, &Q);\n\
    \tV<int> p(N);\n\tVV<int> g(N);\n\tfor (int i = 1; i < N; ++i) {\n\t\tscanf(\"\
    %d\", &p[i]);\n\t\tg[p[i]].pb(i);\n\t}\n\tLCA<int> lca(g, 0);\n\twhile (Q--) {\n\
    \t\tint a, b;\n\t\tscanf(\"%d %d\", &a, &b);\n\t\tint v = lca.query(a, b);\n\t\
    \tprintf(\"%d\\n\", v);\n\t}\n\treturn 0;\n}"
  dependsOn:
  - cpp_src/graph/LCA.hpp
  isVerificationFile: true
  path: test/yosupo/lca.test.cpp
  requiredBy: []
  timestamp: '2020-04-01 18:25:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/lca.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/lca.test.cpp
- /verify/test/yosupo/lca.test.cpp.html
title: test/yosupo/lca.test.cpp
---
