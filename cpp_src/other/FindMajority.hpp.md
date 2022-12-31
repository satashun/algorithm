---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/other/FindMajority.hpp\"\n// ABC272G\n// need to\
    \ check if it is actually majority\ntemplate <class T>\nT find_majority(const\
    \ V<T>& a) {\n    T x = a[0];\n    int c = 0;\n    for (int i = 0; i < SZ(a);\
    \ ++i) {\n        if (c == 0) {\n            x = a[i];\n            c = 1;\n \
    \       } else if (a[i] == x)\n            c++;\n        else\n            c--;\n\
    \    }\n    return x;\n}\n"
  code: "// ABC272G\n// need to check if it is actually majority\ntemplate <class\
    \ T>\nT find_majority(const V<T>& a) {\n    T x = a[0];\n    int c = 0;\n    for\
    \ (int i = 0; i < SZ(a); ++i) {\n        if (c == 0) {\n            x = a[i];\n\
    \            c = 1;\n        } else if (a[i] == x)\n            c++;\n       \
    \ else\n            c--;\n    }\n    return x;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/other/FindMajority.hpp
  requiredBy: []
  timestamp: '2022-12-31 14:31:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/other/FindMajority.hpp
layout: document
redirect_from:
- /library/cpp_src/other/FindMajority.hpp
- /library/cpp_src/other/FindMajority.hpp.html
title: cpp_src/other/FindMajority.hpp
---
