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
    \ std;\n\nusing ll = long long;\nusing ull = unsigned long long;\nusing pii =\
    \ pair<int, int>;\ntemplate<class T> using V = vector<T>;\ntemplate<class T> using\
    \ VV = V<V<T>>;\ntemplate<class T>\nV<T> make_vec(size_t a) {\n    return V<T>(a);\n\
    }\ntemplate<class T, class... Ts>\nauto make_vec(size_t a, Ts... ts) {\n  return\
    \ V<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));\n}\n\n#define pb push_back\n\
    #define eb emplace_back\n#define mp make_pair\n#define fi first\n#define se second\n\
    #define rep(i,n) rep2(i,0,n)\n#define rep2(i,m,n) for(int i=m;i<(n);i++)\n#define\
    \ per(i,b) per2(i,0,b)\n#define per2(i,a,b) for(int i=int(b)-1;i>=int(a);i--)\n\
    #define ALL(c) (c).begin(),(c).end()\n#define SZ(x) ((int)(x).size())\n\nconstexpr\
    \ ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }\n\ntemplate<class T,\
    \ class U> void chmin(T& t, const U& u) { if (t > u) t = u; }\ntemplate<class\
    \ T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }\n\ntemplate<class\
    \ T, class U>\nostream& operator<<(ostream& os, const pair<T, U>& p) {\n    os<<\"\
    (\"<<p.first<<\",\"<<p.second<<\")\";\n    return os;\n}\n\ntemplate<class T>\n\
    ostream& operator<<(ostream& os, const vector<T>& v) {\n    os<<\"{\";\n    rep(i,\
    \ v.size()) {\n        if (i) os<<\",\";\n        os<<v[i];\n    }\n    os<<\"\
    }\";\n    return os;\n}\n\n#ifdef LOCAL\nvoid debug_out() { cerr << endl; }\n\
    template<typename Head, typename... Tail>\nvoid debug_out(Head H, Tail... T) {\n\
    \    cerr << \" \" << H;\n    debug_out(T...);\n}\n#define debug(...) cerr <<\
    \ __LINE__ << \" [\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n#define\
    \ dump(x) cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n#define\
    \ debug(...) (void(0))\n#define dump(x) (void(0))\n#endif\n\nint main() {\n  \
    \  cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    return 0;\n}\n"
  code: "//#pragma GCC optimize(\"Ofast\")\n//#pragma GCC optimize(\"unroll-loops\"\
    )\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing pii = pair<int, int>;\ntemplate<class T> using\
    \ V = vector<T>;\ntemplate<class T> using VV = V<V<T>>;\ntemplate<class T>\nV<T>\
    \ make_vec(size_t a) {\n    return V<T>(a);\n}\ntemplate<class T, class... Ts>\n\
    auto make_vec(size_t a, Ts... ts) {\n  return V<decltype(make_vec<T>(ts...))>(a,\
    \ make_vec<T>(ts...));\n}\n\n#define pb push_back\n#define eb emplace_back\n#define\
    \ mp make_pair\n#define fi first\n#define se second\n#define rep(i,n) rep2(i,0,n)\n\
    #define rep2(i,m,n) for(int i=m;i<(n);i++)\n#define per(i,b) per2(i,0,b)\n#define\
    \ per2(i,a,b) for(int i=int(b)-1;i>=int(a);i--)\n#define ALL(c) (c).begin(),(c).end()\n\
    #define SZ(x) ((int)(x).size())\n\nconstexpr ll TEN(int n) { return (n == 0) ?\
    \ 1 : 10 * TEN(n-1); }\n\ntemplate<class T, class U> void chmin(T& t, const U&\
    \ u) { if (t > u) t = u; }\ntemplate<class T, class U> void chmax(T& t, const\
    \ U& u) { if (t < u) t = u; }\n\ntemplate<class T, class U>\nostream& operator<<(ostream&\
    \ os, const pair<T, U>& p) {\n    os<<\"(\"<<p.first<<\",\"<<p.second<<\")\";\n\
    \    return os;\n}\n\ntemplate<class T>\nostream& operator<<(ostream& os, const\
    \ vector<T>& v) {\n    os<<\"{\";\n    rep(i, v.size()) {\n        if (i) os<<\"\
    ,\";\n        os<<v[i];\n    }\n    os<<\"}\";\n    return os;\n}\n\n#ifdef LOCAL\n\
    void debug_out() { cerr << endl; }\ntemplate<typename Head, typename... Tail>\n\
    void debug_out(Head H, Tail... T) {\n    cerr << \" \" << H;\n    debug_out(T...);\n\
    }\n#define debug(...) cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n\
    #define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n\
    #define debug(...) (void(0))\n#define dump(x) (void(0))\n#endif\n\nint main()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/template.cpp
  requiredBy: []
  timestamp: '2021-05-08 14:23:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/template.cpp
layout: document
redirect_from:
- /library/cpp_src/template.cpp
- /library/cpp_src/template.cpp.html
title: cpp_src/template.cpp
---
