---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/yosupo/bitwise_xor_convolution.cpp
    title: test/yosupo/bitwise_xor_convolution.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/other/FWT.hpp\"\n//vector size : power of 2\n\n\
    template<class T>\nvoid and_fwt(vector<T>& f) {\n    int n = f.size();\n    for\
    \ (int d = 1; d < n; d <<= 1) {\n        for (int i = 0; i < n; i += d * 2) {\n\
    \            for (int j = 0; j < d; ++j) {\n                T x = f[i+j], y =\
    \ f[i+j+d];\n                f[i+j] = x + y;\n            }\n        }\n    }\n\
    }\n\ntemplate<class T>\nvoid and_ifwt(vector<T>& f) {\n    int n = f.size();\n\
    \    for (int d = 1; d < n; d <<= 1) {\n        for (int i = 0; i < n; i += d\
    \ * 2) {\n            for (int j = 0; j < d; ++j) {\n                T x = f[i+j],\
    \ y = f[i+j+d];\n                f[i+j] = x - y;\n            }\n        }\n \
    \   }\n}\n\ntemplate <class T>\nvoid xor_fwt(vector<T>& f, bool rev) {\n    int\
    \ n = f.size();\n    for (int d = 1; d < n; d <<= 1) {\n        for (int i = 0;\
    \ i < n; i += d * 2) {\n            for (int j = 0; j < d; ++j) {\n          \
    \      T x = f[i + j], y = f[i + j + d];\n                f[i + j] = x + y;\n\
    \                f[i + j + d] = x - y;\n            }\n        }\n    }\n\n  \
    \  if (rev) {\n        T r = T(1) / n;\n        for (auto& x : f) x *= r;\n  \
    \  }\n}\n"
  code: "//vector size : power of 2\n\ntemplate<class T>\nvoid and_fwt(vector<T>&\
    \ f) {\n    int n = f.size();\n    for (int d = 1; d < n; d <<= 1) {\n       \
    \ for (int i = 0; i < n; i += d * 2) {\n            for (int j = 0; j < d; ++j)\
    \ {\n                T x = f[i+j], y = f[i+j+d];\n                f[i+j] = x +\
    \ y;\n            }\n        }\n    }\n}\n\ntemplate<class T>\nvoid and_ifwt(vector<T>&\
    \ f) {\n    int n = f.size();\n    for (int d = 1; d < n; d <<= 1) {\n       \
    \ for (int i = 0; i < n; i += d * 2) {\n            for (int j = 0; j < d; ++j)\
    \ {\n                T x = f[i+j], y = f[i+j+d];\n                f[i+j] = x -\
    \ y;\n            }\n        }\n    }\n}\n\ntemplate <class T>\nvoid xor_fwt(vector<T>&\
    \ f, bool rev) {\n    int n = f.size();\n    for (int d = 1; d < n; d <<= 1) {\n\
    \        for (int i = 0; i < n; i += d * 2) {\n            for (int j = 0; j <\
    \ d; ++j) {\n                T x = f[i + j], y = f[i + j + d];\n             \
    \   f[i + j] = x + y;\n                f[i + j + d] = x - y;\n            }\n\
    \        }\n    }\n\n    if (rev) {\n        T r = T(1) / n;\n        for (auto&\
    \ x : f) x *= r;\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/other/FWT.hpp
  requiredBy:
  - test/yosupo/bitwise_xor_convolution.cpp
  timestamp: '2021-02-19 20:19:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/other/FWT.hpp
layout: document
redirect_from:
- /library/cpp_src/other/FWT.hpp
- /library/cpp_src/other/FWT.hpp.html
title: cpp_src/other/FWT.hpp
---
