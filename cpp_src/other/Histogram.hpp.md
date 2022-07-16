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
  bundledCode: "#line 1 \"cpp_src/other/Histogram.hpp\"\n// ** 691\nlong long maximum_rectangle(const\
    \ std::vector<int> &h) {\n    int n = h.size();\n    stack<int> s;\n    vector<int>\
    \ L(n), R(n);\n    for (int i = 0; i < n; i++) {\n        while (s.size() && h[s.top()]\
    \ >= h[i]) s.pop();\n        L[i] = s.size() ? (s.top() + 1) : 0;\n        s.push(i);\n\
    \    }\n    while (s.size()) s.pop();\n    for (int i = n - 1; i >= 0; i--) {\n\
    \        while (s.size() > 0 && h[s.top()] >= h[i]) s.pop();\n        R[i] = s.size()\
    \ ? s.top() : n;\n        s.push(i);\n    }\n    long long res = 0;\n    for (int\
    \ i = 0; i < n; i++) {\n        res = max(res, (long long)h[i] * (R[i] - L[i]));\n\
    \    }\n    return res;\n}\n"
  code: "// ** 691\nlong long maximum_rectangle(const std::vector<int> &h) {\n   \
    \ int n = h.size();\n    stack<int> s;\n    vector<int> L(n), R(n);\n    for (int\
    \ i = 0; i < n; i++) {\n        while (s.size() && h[s.top()] >= h[i]) s.pop();\n\
    \        L[i] = s.size() ? (s.top() + 1) : 0;\n        s.push(i);\n    }\n   \
    \ while (s.size()) s.pop();\n    for (int i = n - 1; i >= 0; i--) {\n        while\
    \ (s.size() > 0 && h[s.top()] >= h[i]) s.pop();\n        R[i] = s.size() ? s.top()\
    \ : n;\n        s.push(i);\n    }\n    long long res = 0;\n    for (int i = 0;\
    \ i < n; i++) {\n        res = max(res, (long long)h[i] * (R[i] - L[i]));\n  \
    \  }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/other/Histogram.hpp
  requiredBy: []
  timestamp: '2022-07-17 01:58:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/other/Histogram.hpp
layout: document
redirect_from:
- /library/cpp_src/other/Histogram.hpp
- /library/cpp_src/other/Histogram.hpp.html
title: cpp_src/other/Histogram.hpp
---
