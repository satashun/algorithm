---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/yosupo/aplusb.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
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
    ,\";\n\t\tos<<v[i];\n\t}\n\tos<<\"}\";\n\treturn os;\n}\n\nint main() {\n\tint\
    \ A, B; cin >> A >> B;\n\tcout << A + B << endl;\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <bits/stdc++.h>\n\
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
    return os;\n}\n\nint main() {\n\tint A, B; cin >> A >> B;\n\tcout << A + B <<\
    \ endl;\n\treturn 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/aplusb.test.cpp
  requiredBy: []
  timestamp: '2020-04-26 04:03:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/aplusb.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/aplusb.test.cpp
- /verify/test/yosupo/aplusb.test.cpp.html
title: test/yosupo/aplusb.test.cpp
---
