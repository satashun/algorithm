---
data:
  _extendedDependsOn:
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
    #line 1 \"cpp_src/graph/SCC.hpp\"\nstruct SCC {\n    int n;\n    VV<int> g, rg;\n\
    \    V<int> vs, cmp;\n    V<bool> vis;\n\n    SCC(){}\n    SCC(int n) : n(n) {\n\
    \        g = rg = VV<int>(n);\n        vs = cmp = V<int>(n);\n        vis = V<bool>(n);\n\
    \    }\n\n    void add_edge(int from, int to) {\n        g[from].push_back(to);\n\
    \        rg[to].push_back(from);\n    }\n\n    void dfs(int v) {\n        vis[v]\
    \ = true;\n\n        for (int to : g[v]) {\n            if (!vis[to]) {\n    \
    \            dfs(to);\n            }\n        }\n\n        vs.push_back(v);\n\
    \    }\n\n    void rdfs(int v, int k, V<int>& vec) {\n        vis[v] = true;\n\
    \        cmp[v] = k;\n        vec.push_back(v);\n\n        for (int to : rg[v])\
    \ {\n            if (!vis[to]) {\n                rdfs(to, k, vec);\n        \
    \    }\n        }\n    }\n\n    VV<int> calc() {\n        rep(v, n) if (!vis[v])\
    \ dfs(v);\n\n        fill(vis.begin(), vis.end(), false);\n\n        int k = 0;\n\
    \        reverse(vs.begin(), vs.end());\n\n        VV<int> vcomp;\n\n        for\
    \ (int v : vs) {\n            if (!vis[v]) {\n                V<int> vec;\n  \
    \              rdfs(v, k++, vec);\n                vcomp.push_back(vec);\n   \
    \         }\n        }\n\n        return vcomp;\n    }\n};\n#line 50 \"test/yosupo/scc.test.cpp\"\
    \n#undef call_from_test\n\nint main() {\n\tint N, M; scanf(\"%d %d\", &N, &M);\n\
    \tSCC scc(N);\n\trep(i, M) {\n\t\tint a, b;\n\t\tscanf(\"%d %d\", &a, &b);\n\t\
    \tscc.add_edge(a, b);\n\t}\n\tauto v = scc.calc();\n\tprintf(\"%d\\n\", v.size());\n\
    \trep(i, v.size()) {\n\t\tauto &vec = v[i];\n\t\tint sz = vec.size();\n\t\tprintf(\"\
    %d\", sz);\n\t\tfor (int j = 0; j < vec.size(); ++j) {\n\t\t\tprintf(\" %d\",\
    \ vec[j]);\n\t\t}\n\t\tputs(\"\");\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include <bits/stdc++.h>\n\
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
    return os;\n}\n\n#define call_from_test\n#include \"../../cpp_src/graph/SCC.hpp\"\
    \n#undef call_from_test\n\nint main() {\n\tint N, M; scanf(\"%d %d\", &N, &M);\n\
    \tSCC scc(N);\n\trep(i, M) {\n\t\tint a, b;\n\t\tscanf(\"%d %d\", &a, &b);\n\t\
    \tscc.add_edge(a, b);\n\t}\n\tauto v = scc.calc();\n\tprintf(\"%d\\n\", v.size());\n\
    \trep(i, v.size()) {\n\t\tauto &vec = v[i];\n\t\tint sz = vec.size();\n\t\tprintf(\"\
    %d\", sz);\n\t\tfor (int j = 0; j < vec.size(); ++j) {\n\t\t\tprintf(\" %d\",\
    \ vec[j]);\n\t\t}\n\t\tputs(\"\");\n\t}\n\treturn 0;\n}"
  dependsOn:
  - cpp_src/graph/SCC.hpp
  isVerificationFile: true
  path: test/yosupo/scc.test.cpp
  requiredBy: []
  timestamp: '2020-04-01 18:25:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/scc.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/scc.test.cpp
- /verify/test/yosupo/scc.test.cpp.html
title: test/yosupo/scc.test.cpp
---
