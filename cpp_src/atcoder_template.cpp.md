---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/atcoder_template.cpp\"\n#include <bits/stdc++.h>\n\
    #include <atcoder/modint>\nusing namespace std;\nusing namespace atcoder;\n\n\
    using ll = long long;\nusing pii = pair<int, int>;\ntemplate<class T> using V\
    \ = vector<T>;\ntemplate<class T> using VV = V<V<T>>;\n\n#define pb push_back\n\
    #define eb emplace_back\n#define mp make_pair\n#define fi first\n#define se second\n\
    #define rep(i,n) rep2(i,0,n)\n#define rep2(i,m,n) for(int i=m;i<(n);i++)\n#define\
    \ per(i,b) per2(i,0,b)\n#define per2(i,a,b) for(int i=int(b)-1;i>=int(a);i--)\n\
    #define ALL(c) (c).begin(),(c).end()\n#define SZ(x) ((int)(x).size())\n\nconstexpr\
    \ ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }\n\ntemplate<class T,\
    \ class U> void chmin(T& t, const U& u) { if (t > u) t = u; }\ntemplate<class\
    \ T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }\n\ntemplate <class\
    \ T, class U>\nostream& operator<<(ostream& os, const pair<T, U>& p) {\n    os\
    \ << \"(\" << p.first << \",\" << p.second << \")\";\n    return os;\n}\n\ntemplate\
    \ <class T>\nostream& operator<<(ostream& os, const vector<T>& v) {\n    os <<\
    \ \"{\";\n    rep(i, v.size()) {\n        if (i) os << \",\";\n        os << v[i];\n\
    \    }\n    os << \"}\";\n    return os;\n}\n\ntemplate <class T>\nauto operator<<(ostream&\
    \ os, T t) ->\n    typename std::enable_if_t<internal::is_modint<T>::value, ostream&>\
    \ {\n    os << t.val();\n    return os;\n}\n\n#ifdef LOCAL\nvoid debug_out() {\
    \ cerr << endl; }\ntemplate<typename Head, typename... Tail>\nvoid debug_out(Head\
    \ H, Tail... T) {\n    cerr << \" \" << H;\n    debug_out(T...);\n}\n#define debug(...)\
    \ cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n\
    #define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n\
    #define debug(...) (void(0))\n#define dump(x) (void(0))\n#endif\n\nint main()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    return 0;\n\
    }\n"
  code: "#include <bits/stdc++.h>\n#include <atcoder/modint>\nusing namespace std;\n\
    using namespace atcoder;\n\nusing ll = long long;\nusing pii = pair<int, int>;\n\
    template<class T> using V = vector<T>;\ntemplate<class T> using VV = V<V<T>>;\n\
    \n#define pb push_back\n#define eb emplace_back\n#define mp make_pair\n#define\
    \ fi first\n#define se second\n#define rep(i,n) rep2(i,0,n)\n#define rep2(i,m,n)\
    \ for(int i=m;i<(n);i++)\n#define per(i,b) per2(i,0,b)\n#define per2(i,a,b) for(int\
    \ i=int(b)-1;i>=int(a);i--)\n#define ALL(c) (c).begin(),(c).end()\n#define SZ(x)\
    \ ((int)(x).size())\n\nconstexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1);\
    \ }\n\ntemplate<class T, class U> void chmin(T& t, const U& u) { if (t > u) t\
    \ = u; }\ntemplate<class T, class U> void chmax(T& t, const U& u) { if (t < u)\
    \ t = u; }\n\ntemplate <class T, class U>\nostream& operator<<(ostream& os, const\
    \ pair<T, U>& p) {\n    os << \"(\" << p.first << \",\" << p.second << \")\";\n\
    \    return os;\n}\n\ntemplate <class T>\nostream& operator<<(ostream& os, const\
    \ vector<T>& v) {\n    os << \"{\";\n    rep(i, v.size()) {\n        if (i) os\
    \ << \",\";\n        os << v[i];\n    }\n    os << \"}\";\n    return os;\n}\n\
    \ntemplate <class T>\nauto operator<<(ostream& os, T t) ->\n    typename std::enable_if_t<internal::is_modint<T>::value,\
    \ ostream&> {\n    os << t.val();\n    return os;\n}\n\n#ifdef LOCAL\nvoid debug_out()\
    \ { cerr << endl; }\ntemplate<typename Head, typename... Tail>\nvoid debug_out(Head\
    \ H, Tail... T) {\n    cerr << \" \" << H;\n    debug_out(T...);\n}\n#define debug(...)\
    \ cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n\
    #define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n\
    #define debug(...) (void(0))\n#define dump(x) (void(0))\n#endif\n\nint main()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/atcoder_template.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/atcoder_template.cpp
layout: document
redirect_from:
- /library/cpp_src/atcoder_template.cpp
- /library/cpp_src/atcoder_template.cpp.html
title: cpp_src/atcoder_template.cpp
---
