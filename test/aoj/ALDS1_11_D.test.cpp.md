---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 258, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../cpp_src/data_structure/unionfind.hpp:\
    \ line -1: no such header\n"
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
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/ALDS1_11_D.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/ALDS1_11_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_11_D.test.cpp
- /verify/test/aoj/ALDS1_11_D.test.cpp.html
title: test/aoj/ALDS1_11_D.test.cpp
---
