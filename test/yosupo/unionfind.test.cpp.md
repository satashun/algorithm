---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: cpp_src/data_structure/DisjointSetUnion.hpp
    title: cpp_src/data_structure/DisjointSetUnion.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/yosupo/unionfind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\nusing\
    \ pii = pair<int, int>;\ntemplate <class T>\nusing V = vector<T>;\ntemplate <class\
    \ T>\nusing VV = V<V<T>>;\n\n#define pb push_back\n#define eb emplace_back\n#define\
    \ mp make_pair\n#define fi first\n#define se second\n#define rep(i, n) rep2(i,\
    \ 0, n)\n#define rep2(i, m, n) for (int i = m; i < (n); i++)\n#define ALL(c) (c).begin(),\
    \ (c).end()\n\n#ifdef LOCAL\n#define dump(x) cerr << __LINE__ << \" \" << #x <<\
    \ \" = \" << (x) << endl\n#else\n#define dump(x) true\n#endif\n\nconstexpr ll\
    \ TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }\n\ntemplate <class T,\
    \ class U>\nvoid chmin(T& t, const U& u) {\n    if (t > u) t = u;\n}\ntemplate\
    \ <class T, class U>\nvoid chmax(T& t, const U& u) {\n    if (t < u) t = u;\n\
    }\n\ntemplate <class T, class U>\nostream& operator<<(ostream& os, const pair<T,\
    \ U>& p) {\n    os << \"(\" << p.first << \",\" << p.second << \")\";\n    return\
    \ os;\n}\n\ntemplate <class T>\nostream& operator<<(ostream& os, const vector<T>&\
    \ v) {\n    os << \"{\";\n    rep(i, v.size()) {\n        if (i) os << \",\";\n\
    \        os << v[i];\n    }\n    os << \"}\";\n    return os;\n}\n\n#define call_from_test\n\
    #line 1 \"cpp_src/data_structure/DisjointSetUnion.hpp\"\nclass unionfind {\n \
    \   vector<int> par, rank;\n\n   public:\n    void init(int n) {\n        par.resize(n);\n\
    \        rank.resize(n);\n\n        for (int i = 0; i < n; i++) {\n          \
    \  par[i] = i;\n            rank[i] = 0;\n        }\n    }\n\n    unionfind(int\
    \ n) { init(n); }\n\n    int find(int x) {\n        if (par[x] == x)\n       \
    \     return x;\n        else\n            return par[x] = find(par[x]);\n   \
    \ }\n\n    bool unite(int x, int y) {\n        x = find(x);\n        y = find(y);\n\
    \        if (x == y) return false;\n\n        if (rank[x] < rank[y])\n       \
    \     par[x] = y;\n        else {\n            par[y] = x;\n            if (rank[x]\
    \ == rank[y]) ++rank[x];\n        }\n        return true;\n    }\n\n    bool same(int\
    \ x, int y) { return (find(x) == find(y)); }\n};\n#line 57 \"test/yosupo/unionfind.test.cpp\"\
    \n#undef call_from_test\n\nint main() {\n    int N, Q;\n    scanf(\"%d %d\", &N,\
    \ &Q);\n    unionfind uf;\n    uf.init(N);\n\n    rep(i, Q) {\n        int t,\
    \ u, v;\n        scanf(\"%d %d %d\", &t, &u, &v);\n        if (t == 0) {\n   \
    \         uf.unite(u, v);\n        } else {\n            printf(\"%d\\n\", uf.same(u,\
    \ v));\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nusing ll = long long;\nusing pii = pair<int, int>;\ntemplate\
    \ <class T>\nusing V = vector<T>;\ntemplate <class T>\nusing VV = V<V<T>>;\n\n\
    #define pb push_back\n#define eb emplace_back\n#define mp make_pair\n#define fi\
    \ first\n#define se second\n#define rep(i, n) rep2(i, 0, n)\n#define rep2(i, m,\
    \ n) for (int i = m; i < (n); i++)\n#define ALL(c) (c).begin(), (c).end()\n\n\
    #ifdef LOCAL\n#define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" << (x)\
    \ << endl\n#else\n#define dump(x) true\n#endif\n\nconstexpr ll TEN(int n) { return\
    \ (n == 0) ? 1 : 10 * TEN(n - 1); }\n\ntemplate <class T, class U>\nvoid chmin(T&\
    \ t, const U& u) {\n    if (t > u) t = u;\n}\ntemplate <class T, class U>\nvoid\
    \ chmax(T& t, const U& u) {\n    if (t < u) t = u;\n}\n\ntemplate <class T, class\
    \ U>\nostream& operator<<(ostream& os, const pair<T, U>& p) {\n    os << \"(\"\
    \ << p.first << \",\" << p.second << \")\";\n    return os;\n}\n\ntemplate <class\
    \ T>\nostream& operator<<(ostream& os, const vector<T>& v) {\n    os << \"{\"\
    ;\n    rep(i, v.size()) {\n        if (i) os << \",\";\n        os << v[i];\n\
    \    }\n    os << \"}\";\n    return os;\n}\n\n#define call_from_test\n#include\
    \ \"../../cpp_src/data_structure/DisjointSetUnion.hpp\"\n#undef call_from_test\n\
    \nint main() {\n    int N, Q;\n    scanf(\"%d %d\", &N, &Q);\n    unionfind uf;\n\
    \    uf.init(N);\n\n    rep(i, Q) {\n        int t, u, v;\n        scanf(\"%d\
    \ %d %d\", &t, &u, &v);\n        if (t == 0) {\n            uf.unite(u, v);\n\
    \        } else {\n            printf(\"%d\\n\", uf.same(u, v));\n        }\n\
    \    }\n    return 0;\n}"
  dependsOn:
  - cpp_src/data_structure/DisjointSetUnion.hpp
  isVerificationFile: true
  path: test/yosupo/unionfind.test.cpp
  requiredBy: []
  timestamp: '2022-03-24 23:54:57+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/unionfind.test.cpp
- /verify/test/yosupo/unionfind.test.cpp.html
title: test/yosupo/unionfind.test.cpp
---
