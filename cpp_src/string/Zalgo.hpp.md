---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Z.test.cpp
    title: test/yosupo/Z.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/string/Zalgo.hpp\"\nvector<int> Z_algo(const string\
    \ &S) {\n\tvector<int> A(S.size());\n\tA[0] = S.size();\n\tint i = 1, j = 0;\n\
    \twhile (i < S.size()) {\n\t\twhile (i+j < S.size() && S[j] == S[i+j]) ++j;\n\t\
    \tA[i] = j;\n\t\tif (j == 0) { ++i; continue; }\n\t\tint k = 1;\n\t\twhile (i+k\
    \ < S.size() && k+A[k] < j) A[i+k] = A[k], ++k;\n\t\ti += k; j -= k;\n\t}\n\t\
    return A;\n}\n"
  code: "vector<int> Z_algo(const string &S) {\n\tvector<int> A(S.size());\n\tA[0]\
    \ = S.size();\n\tint i = 1, j = 0;\n\twhile (i < S.size()) {\n\t\twhile (i+j <\
    \ S.size() && S[j] == S[i+j]) ++j;\n\t\tA[i] = j;\n\t\tif (j == 0) { ++i; continue;\
    \ }\n\t\tint k = 1;\n\t\twhile (i+k < S.size() && k+A[k] < j) A[i+k] = A[k], ++k;\n\
    \t\ti += k; j -= k;\n\t}\n\treturn A;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/string/Zalgo.hpp
  requiredBy: []
  timestamp: '2020-07-17 17:57:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Z.test.cpp
documentation_of: cpp_src/string/Zalgo.hpp
layout: document
redirect_from:
- /library/cpp_src/string/Zalgo.hpp
- /library/cpp_src/string/Zalgo.hpp.html
title: cpp_src/string/Zalgo.hpp
---
