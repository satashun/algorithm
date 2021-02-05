---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp_src/string/Zalgo.hpp
    title: cpp_src/string/Zalgo.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/yosupo/Z.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
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
    #line 1 \"cpp_src/string/Zalgo.hpp\"\nvector<int> Z_algo(const string &S) {\n\t\
    vector<int> A(S.size());\n\tA[0] = S.size();\n\tint i = 1, j = 0;\n\twhile (i\
    \ < S.size()) {\n\t\twhile (i+j < S.size() && S[j] == S[i+j]) ++j;\n\t\tA[i] =\
    \ j;\n\t\tif (j == 0) { ++i; continue; }\n\t\tint k = 1;\n\t\twhile (i+k < S.size()\
    \ && k+A[k] < j) A[i+k] = A[k], ++k;\n\t\ti += k; j -= k;\n\t}\n\treturn A;\n\
    }\n#line 57 \"test/yosupo/Z.test.cpp\"\n#undef call_from_test\n\nint main() {\n\
    \    string S;\n    cin >> S;\n    V<int> vec = Z_algo(S);\n    int n = vec.size();\n\
    \    rep(i, n) cout << vec[i] << (i == n - 1 ? '\\n' : ' ');\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\nusing pii =\
    \ pair<int, int>;\ntemplate <class T>\nusing V = vector<T>;\ntemplate <class T>\n\
    using VV = V<V<T>>;\n\n#define pb push_back\n#define eb emplace_back\n#define\
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
    #include \"../../cpp_src/string/Zalgo.hpp\"\n#undef call_from_test\n\nint main()\
    \ {\n    string S;\n    cin >> S;\n    V<int> vec = Z_algo(S);\n    int n = vec.size();\n\
    \    rep(i, n) cout << vec[i] << (i == n - 1 ? '\\n' : ' ');\n    return 0;\n}"
  dependsOn:
  - cpp_src/string/Zalgo.hpp
  isVerificationFile: true
  path: test/yosupo/Z.test.cpp
  requiredBy: []
  timestamp: '2020-12-31 16:46:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Z.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Z.test.cpp
- /verify/test/yosupo/Z.test.cpp.html
title: test/yosupo/Z.test.cpp
---
