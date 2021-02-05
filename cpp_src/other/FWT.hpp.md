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
  bundledCode: "#line 1 \"cpp_src/other/FWT.hpp\"\n//vector size : power of 2\n\n\
    template<class T>\nvoid and_fwt(vector<T>& f) {\n    int n = f.size();\n    for\
    \ (int d = 1; d < n; d <<= 1) {\n        for (int i = 0; i < n; i += d * 2) {\n\
    \            for (int j = 0; j < d; ++j) {\n                Mint x = f[i+j], y\
    \ = f[i+j+d];\n                f[i+j] = x + y;\n            }\n        }\n   \
    \ }\n}\n\ntemplate<class T>\nvoid and_ifwt(vector<T>& f) {\n    int n = f.size();\n\
    \    for (int d = 1; d < n; d <<= 1) {\n        for (int i = 0; i < n; i += d\
    \ * 2) {\n            for (int j = 0; j < d; ++j) {\n                Mint x =\
    \ f[i+j], y = f[i+j+d];\n                f[i+j] = x - y;\n            }\n    \
    \    }\n    }\n}\n\ntemplate<class T>\nvoid xor_fwt(vector<T>& f) {\n    int n\
    \ = f.size();\n    for (int d = 1; d < n; d <<= 1) {\n        for (int i = 0;\
    \ i < n; i += d * 2) {\n            for (int j = 0; j < d; ++j) {\n          \
    \      Mint x = f[i+j], y = f[i+j+d];\n                f[i+j] = x + y;\n     \
    \           f[i+j+d] = x - y;\n            }\n        }\n    }\n}\n\ntemplate<class\
    \ T>\nvoid xor_ifwt(vector<T>& f) {\n    int n = f.size();\n    for (int d = 1;\
    \ d < n; d <<= 1) {\n        for (int i = 0; i < n; i += d * 2) {\n          \
    \  for (int j = 0; j < d; ++j) {\n                Mint x = f[i+j], y = f[i+j+d];\n\
    \                f[i+j] = (x + y) * i2;\n                f[i+j+d] = (x - y) *\
    \ i2;\n            }\n        }\n    }\n}\n"
  code: "//vector size : power of 2\n\ntemplate<class T>\nvoid and_fwt(vector<T>&\
    \ f) {\n    int n = f.size();\n    for (int d = 1; d < n; d <<= 1) {\n       \
    \ for (int i = 0; i < n; i += d * 2) {\n            for (int j = 0; j < d; ++j)\
    \ {\n                Mint x = f[i+j], y = f[i+j+d];\n                f[i+j] =\
    \ x + y;\n            }\n        }\n    }\n}\n\ntemplate<class T>\nvoid and_ifwt(vector<T>&\
    \ f) {\n    int n = f.size();\n    for (int d = 1; d < n; d <<= 1) {\n       \
    \ for (int i = 0; i < n; i += d * 2) {\n            for (int j = 0; j < d; ++j)\
    \ {\n                Mint x = f[i+j], y = f[i+j+d];\n                f[i+j] =\
    \ x - y;\n            }\n        }\n    }\n}\n\ntemplate<class T>\nvoid xor_fwt(vector<T>&\
    \ f) {\n    int n = f.size();\n    for (int d = 1; d < n; d <<= 1) {\n       \
    \ for (int i = 0; i < n; i += d * 2) {\n            for (int j = 0; j < d; ++j)\
    \ {\n                Mint x = f[i+j], y = f[i+j+d];\n                f[i+j] =\
    \ x + y;\n                f[i+j+d] = x - y;\n            }\n        }\n    }\n\
    }\n\ntemplate<class T>\nvoid xor_ifwt(vector<T>& f) {\n    int n = f.size();\n\
    \    for (int d = 1; d < n; d <<= 1) {\n        for (int i = 0; i < n; i += d\
    \ * 2) {\n            for (int j = 0; j < d; ++j) {\n                Mint x =\
    \ f[i+j], y = f[i+j+d];\n                f[i+j] = (x + y) * i2;\n            \
    \    f[i+j+d] = (x - y) * i2;\n            }\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/other/FWT.hpp
  requiredBy: []
  timestamp: '2020-04-07 22:26:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/other/FWT.hpp
layout: document
redirect_from:
- /library/cpp_src/other/FWT.hpp
- /library/cpp_src/other/FWT.hpp.html
title: cpp_src/other/FWT.hpp
---
