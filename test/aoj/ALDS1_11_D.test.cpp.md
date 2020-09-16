---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp_src/data_structure/unionfind.hpp
    title: cpp_src/data_structure/unionfind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D
  bundledCode: "#line 1 \"test/aoj/ALDS1_11_D.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#define call_from_test\n\
    #line 1 \"cpp_src/data_structure/unionfind.hpp\"\nclass unionfind {\n\tvector<int>\
    \ par, rank;\n\npublic:\n\tvoid init(int n) {\n\t\tpar.resize(n);\n\t\trank.resize(n);\n\
    \n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tpar[i] = i;\n\t\t\trank[i] = 0;\n\t\
    \t}\n\t}\n\n\tint find(int x) {\n\t\tif (par[x] == x) return x;\n\t\telse return\
    \ par[x] = find(par[x]);\n\t}\n\n\tvoid unite(int x, int y) {\n\t\tx = find(x);\n\
    \t\ty = find(y);\n\t\tif (x == y) return ;\n\n\t\tif (rank[x] < rank[y]) par[x]\
    \ = y;\n\t\telse {\n\t\t\tpar[y] = x;\n\t\t\tif (rank[x] == rank[y]) ++rank[x];\n\
    \t\t}\n\t}\n\n\tbool same(int x, int y) { return (find(x) == find(y)); }\n};\n\
    #line 9 \"test/aoj/ALDS1_11_D.test.cpp\"\n#undef call_from_test\n\nusing ll =\
    \ long long;\nusing pii = pair<int, int>;\ntemplate<class T> using V = vector<T>;\n\
    template<class T> using VV = V<V<T>>;\n\n#define pb push_back\n#define eb emplace_back\n\
    #define mp make_pair\n#define fi first\n#define se second\n#define rep(i,n) rep2(i,0,n)\n\
    #define rep2(i,m,n) for(int i=m;i<(n);i++)\n#define ALL(c) (c).begin(),(c).end()\n\
    \n#ifdef LOCAL\n#define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" <<\
    \ (x) << endl\n#else \n#define dump(x) true\n#endif\n\nconstexpr ll TEN(int n)\
    \ { return (n == 0) ? 1 : 10 * TEN(n-1); }\n\ntemplate<class T, class U> void\
    \ chmin(T& t, const U& u) { if (t > u) t = u; }\ntemplate<class T, class U> void\
    \ chmax(T& t, const U& u) { if (t < u) t = u; }\n\ntemplate<class T, class U>\n\
    ostream& operator<<(ostream& os, const pair<T, U>& p) {\n\tos<<\"(\"<<p.first<<\"\
    ,\"<<p.second<<\")\";\n\treturn os;\n}\n\ntemplate<class T>\nostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n\tos<<\"{\";\n\trep(i, v.size()) {\n\t\tif (i) os<<\"\
    ,\";\n\t\tos<<v[i];\n\t}\n\tos<<\"}\";\n\treturn os;\n}\n\nint main() {\n\tint\
    \ n, m; cin >> n >> m;\n\tunionfind uf;\n\tuf.init(n);\n\n\trep(i, m) {\n\t\t\
    int a, b;\n\t\tcin >> a >> b;\n\t\tuf.unite(a, b);\n\t}\n\tint q; cin >> q;\n\t\
    while (q--) {\n\t\tint a, b;\n\t\tcin >> a >> b;\n\t\tputs(uf.same(a, b) ? \"\
    yes\" : \"no\");\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../cpp_src/data_structure/unionfind.hpp\"\n#undef call_from_test\n\
    \nusing ll = long long;\nusing pii = pair<int, int>;\ntemplate<class T> using\
    \ V = vector<T>;\ntemplate<class T> using VV = V<V<T>>;\n\n#define pb push_back\n\
    #define eb emplace_back\n#define mp make_pair\n#define fi first\n#define se second\n\
    #define rep(i,n) rep2(i,0,n)\n#define rep2(i,m,n) for(int i=m;i<(n);i++)\n#define\
    \ ALL(c) (c).begin(),(c).end()\n\n#ifdef LOCAL\n#define dump(x) cerr << __LINE__\
    \ << \" \" << #x << \" = \" << (x) << endl\n#else \n#define dump(x) true\n#endif\n\
    \nconstexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }\n\ntemplate<class\
    \ T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }\ntemplate<class\
    \ T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }\n\ntemplate<class\
    \ T, class U>\nostream& operator<<(ostream& os, const pair<T, U>& p) {\n\tos<<\"\
    (\"<<p.first<<\",\"<<p.second<<\")\";\n\treturn os;\n}\n\ntemplate<class T>\n\
    ostream& operator<<(ostream& os, const vector<T>& v) {\n\tos<<\"{\";\n\trep(i,\
    \ v.size()) {\n\t\tif (i) os<<\",\";\n\t\tos<<v[i];\n\t}\n\tos<<\"}\";\n\treturn\
    \ os;\n}\n\nint main() {\n\tint n, m; cin >> n >> m;\n\tunionfind uf;\n\tuf.init(n);\n\
    \n\trep(i, m) {\n\t\tint a, b;\n\t\tcin >> a >> b;\n\t\tuf.unite(a, b);\n\t}\n\
    \tint q; cin >> q;\n\twhile (q--) {\n\t\tint a, b;\n\t\tcin >> a >> b;\n\t\tputs(uf.same(a,\
    \ b) ? \"yes\" : \"no\");\n\t}\n\treturn 0;\n}"
  dependsOn:
  - cpp_src/data_structure/unionfind.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_11_D.test.cpp
  requiredBy: []
  timestamp: '2020-09-17 02:07:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_11_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_11_D.test.cpp
- /verify/test/aoj/ALDS1_11_D.test.cpp.html
title: test/aoj/ALDS1_11_D.test.cpp
---
