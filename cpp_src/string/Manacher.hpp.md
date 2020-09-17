---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"cpp_src/string/Manacher.hpp\"\nvector<int> manacher(const\
    \ string &_s) {\n    int n = _s.size();\n\n    string s(n*2-1, '#');\n\n    for\
    \ (int i = 0; i < n; ++i) {\n        s[i*2] = _s[i];\n    }\n\n    n = s.size();\n\
    \n    vector<int> rad(n);\n\n    int i = 0, j = 0;\n\n    while (i < n) {\n  \
    \      while (i-j >= 0 && i+j<n && s[i-j] == s[i+j]) ++j;\n        rad[i] = j;\n\
    \n        int k = 1;\n        while (i-k >= 0 && i+k < n && k+rad[i-k] < j) {\n\
    \            rad[i+k] = rad[i-k];\n            ++k;\n        }\n\n        i +=\
    \ k;\n        j -= k;\n    }\n\n    return rad;\n}\n"
  code: "vector<int> manacher(const string &_s) {\n    int n = _s.size();\n\n    string\
    \ s(n*2-1, '#');\n\n    for (int i = 0; i < n; ++i) {\n        s[i*2] = _s[i];\n\
    \    }\n\n    n = s.size();\n\n    vector<int> rad(n);\n\n    int i = 0, j = 0;\n\
    \n    while (i < n) {\n        while (i-j >= 0 && i+j<n && s[i-j] == s[i+j]) ++j;\n\
    \        rad[i] = j;\n\n        int k = 1;\n        while (i-k >= 0 && i+k < n\
    \ && k+rad[i-k] < j) {\n            rad[i+k] = rad[i-k];\n            ++k;\n \
    \       }\n\n        i += k;\n        j -= k;\n    }\n\n    return rad;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/string/Manacher.hpp
  requiredBy: []
  timestamp: '2020-09-17 22:27:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/string/Manacher.hpp
layout: document
redirect_from:
- /library/cpp_src/string/Manacher.hpp
- /library/cpp_src/string/Manacher.hpp.html
title: cpp_src/string/Manacher.hpp
---
