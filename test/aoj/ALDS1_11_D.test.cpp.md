---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp_src/data_structure/DisjointSetUnion.hpp
    title: cpp_src/data_structure/DisjointSetUnion.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D
  bundledCode: "#line 1 \"test/aoj/ALDS1_11_D.test.cpp\"\n#define PROBLEM \\\n   \
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D\"\n\n\
    #include <bits/stdc++.h>\n\nusing namespace std;\n\n#define call_from_test\n#line\
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
    \ x, int y) { return (find(x) == find(y)); }\n};\n#line 10 \"test/aoj/ALDS1_11_D.test.cpp\"\
    \n#undef call_from_test\n\nusing ll = long long;\nusing pii = pair<int, int>;\n\
    template <class T>\nusing V = vector<T>;\ntemplate <class T>\nusing VV = V<V<T>>;\n\
    \n#define pb push_back\n#define eb emplace_back\n#define mp make_pair\n#define\
    \ fi first\n#define se second\n#define rep(i, n) rep2(i, 0, n)\n#define rep2(i,\
    \ m, n) for (int i = m; i < (n); i++)\n#define ALL(c) (c).begin(), (c).end()\n\
    \n#ifdef LOCAL\n#define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" <<\
    \ (x) << endl\n#else\n#define dump(x) true\n#endif\n\nconstexpr ll TEN(int n)\
    \ { return (n == 0) ? 1 : 10 * TEN(n - 1); }\n\ntemplate <class T, class U>\n\
    void chmin(T& t, const U& u) {\n    if (t > u) t = u;\n}\ntemplate <class T, class\
    \ U>\nvoid chmax(T& t, const U& u) {\n    if (t < u) t = u;\n}\n\ntemplate <class\
    \ T, class U>\nostream& operator<<(ostream& os, const pair<T, U>& p) {\n    os\
    \ << \"(\" << p.first << \",\" << p.second << \")\";\n    return os;\n}\n\ntemplate\
    \ <class T>\nostream& operator<<(ostream& os, const vector<T>& v) {\n    os <<\
    \ \"{\";\n    rep(i, v.size()) {\n        if (i) os << \",\";\n        os << v[i];\n\
    \    }\n    os << \"}\";\n    return os;\n}\n\nint main() {\n    int n, m;\n \
    \   cin >> n >> m;\n    unionfind uf;\n    uf.init(n);\n\n    rep(i, m) {\n  \
    \      int a, b;\n        cin >> a >> b;\n        uf.unite(a, b);\n    }\n   \
    \ int q;\n    cin >> q;\n    while (q--) {\n        int a, b;\n        cin >>\
    \ a >> b;\n        puts(uf.same(a, b) ? \"yes\" : \"no\");\n    }\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../cpp_src/data_structure/DisjointSetUnion.hpp\"\n#undef call_from_test\n\
    \nusing ll = long long;\nusing pii = pair<int, int>;\ntemplate <class T>\nusing\
    \ V = vector<T>;\ntemplate <class T>\nusing VV = V<V<T>>;\n\n#define pb push_back\n\
    #define eb emplace_back\n#define mp make_pair\n#define fi first\n#define se second\n\
    #define rep(i, n) rep2(i, 0, n)\n#define rep2(i, m, n) for (int i = m; i < (n);\
    \ i++)\n#define ALL(c) (c).begin(), (c).end()\n\n#ifdef LOCAL\n#define dump(x)\
    \ cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n#define dump(x)\
    \ true\n#endif\n\nconstexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n -\
    \ 1); }\n\ntemplate <class T, class U>\nvoid chmin(T& t, const U& u) {\n    if\
    \ (t > u) t = u;\n}\ntemplate <class T, class U>\nvoid chmax(T& t, const U& u)\
    \ {\n    if (t < u) t = u;\n}\n\ntemplate <class T, class U>\nostream& operator<<(ostream&\
    \ os, const pair<T, U>& p) {\n    os << \"(\" << p.first << \",\" << p.second\
    \ << \")\";\n    return os;\n}\n\ntemplate <class T>\nostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    os << \"{\";\n    rep(i, v.size()) {\n      \
    \  if (i) os << \",\";\n        os << v[i];\n    }\n    os << \"}\";\n    return\
    \ os;\n}\n\nint main() {\n    int n, m;\n    cin >> n >> m;\n    unionfind uf;\n\
    \    uf.init(n);\n\n    rep(i, m) {\n        int a, b;\n        cin >> a >> b;\n\
    \        uf.unite(a, b);\n    }\n    int q;\n    cin >> q;\n    while (q--) {\n\
    \        int a, b;\n        cin >> a >> b;\n        puts(uf.same(a, b) ? \"yes\"\
    \ : \"no\");\n    }\n    return 0;\n}"
  dependsOn:
  - cpp_src/data_structure/DisjointSetUnion.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_11_D.test.cpp
  requiredBy: []
  timestamp: '2022-04-10 12:39:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_11_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_11_D.test.cpp
- /verify/test/aoj/ALDS1_11_D.test.cpp.html
title: test/aoj/ALDS1_11_D.test.cpp
---
