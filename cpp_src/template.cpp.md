---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/template.cpp\"\n//#pragma GCC optimize(\"Ofast\"\
    )\n//#pragma GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing pii = pair<int, int>;\ntemplate<class T>\
    \ using V = vector<T>;\ntemplate<class T> using VV = V<V<T>>;\n\n#define pb push_back\n\
    #define eb emplace_back\n#define mp make_pair\n#define fi first\n#define se second\n\
    #define rep(i,n) rep2(i,0,n)\n#define rep2(i,m,n) for(int i=m;i<(n);i++)\n#define\
    \ per(i,b) per2(i,0,b)\n#define per2(i,a,b) for(int i=int(b)-1;i>=int(a);i--)\n\
    #define ALL(c) (c).begin(),(c).end()\n#define SZ(x) ((int)(x).size())\n\nconstexpr\
    \ ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }\n\ntemplate<class T,\
    \ class U> void chmin(T& t, const U& u) { if (t > u) t = u; }\ntemplate<class\
    \ T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }\n\ntemplate<class\
    \ T, class U>\nostream& operator<<(ostream& os, const pair<T, U>& p) {\n\tos<<\"\
    (\"<<p.first<<\",\"<<p.second<<\")\";\n\treturn os;\n}\n\ntemplate<class T>\n\
    ostream& operator<<(ostream& os, const vector<T>& v) {\n\tos<<\"{\";\n\trep(i,\
    \ v.size()) {\n\t\tif (i) os<<\",\";\n\t\tos<<v[i];\n\t}\n\tos<<\"}\";\n\treturn\
    \ os;\n}\n\n#ifdef LOCAL\nvoid debug_out() { cerr << endl; }\ntemplate<typename\
    \ Head, typename... Tail>\nvoid debug_out(Head H, Tail... T) {\n\tcerr << \" \"\
    \ << H;\n\tdebug_out(T...);\n}\n#define debug(...) cerr << __LINE__ << \" [\"\
    \ << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n#define dump(x) cerr << __LINE__\
    \ << \" \" << #x << \" = \" << (x) << endl\n#else\n#define debug(...) (void(0))\n\
    #define dump(x) (void(0))\n#endif\n\nint main() {\n\tcin.tie(nullptr);\n\tios::sync_with_stdio(false);\n\
    \treturn 0;\n}\n"
  code: "//#pragma GCC optimize(\"Ofast\")\n//#pragma GCC optimize(\"unroll-loops\"\
    )\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\nusing\
    \ pii = pair<int, int>;\ntemplate<class T> using V = vector<T>;\ntemplate<class\
    \ T> using VV = V<V<T>>;\n\n#define pb push_back\n#define eb emplace_back\n#define\
    \ mp make_pair\n#define fi first\n#define se second\n#define rep(i,n) rep2(i,0,n)\n\
    #define rep2(i,m,n) for(int i=m;i<(n);i++)\n#define per(i,b) per2(i,0,b)\n#define\
    \ per2(i,a,b) for(int i=int(b)-1;i>=int(a);i--)\n#define ALL(c) (c).begin(),(c).end()\n\
    #define SZ(x) ((int)(x).size())\n\nconstexpr ll TEN(int n) { return (n == 0) ?\
    \ 1 : 10 * TEN(n-1); }\n\ntemplate<class T, class U> void chmin(T& t, const U&\
    \ u) { if (t > u) t = u; }\ntemplate<class T, class U> void chmax(T& t, const\
    \ U& u) { if (t < u) t = u; }\n\ntemplate<class T, class U>\nostream& operator<<(ostream&\
    \ os, const pair<T, U>& p) {\n\tos<<\"(\"<<p.first<<\",\"<<p.second<<\")\";\n\t\
    return os;\n}\n\ntemplate<class T>\nostream& operator<<(ostream& os, const vector<T>&\
    \ v) {\n\tos<<\"{\";\n\trep(i, v.size()) {\n\t\tif (i) os<<\",\";\n\t\tos<<v[i];\n\
    \t}\n\tos<<\"}\";\n\treturn os;\n}\n\n#ifdef LOCAL\nvoid debug_out() { cerr <<\
    \ endl; }\ntemplate<typename Head, typename... Tail>\nvoid debug_out(Head H, Tail...\
    \ T) {\n\tcerr << \" \" << H;\n\tdebug_out(T...);\n}\n#define debug(...) cerr\
    \ << __LINE__ << \" [\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n#define\
    \ dump(x) cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n#define\
    \ debug(...) (void(0))\n#define dump(x) (void(0))\n#endif\n\nint main() {\n\t\
    cin.tie(nullptr);\n\tios::sync_with_stdio(false);\n\treturn 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/template.cpp
  requiredBy: []
  timestamp: '2021-02-18 22:43:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/template.cpp
layout: document
redirect_from:
- /library/cpp_src/template.cpp
- /library/cpp_src/template.cpp.html
title: cpp_src/template.cpp
---
