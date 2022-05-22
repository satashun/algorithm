---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_range_sum.test.cpp
    title: test/yosupo/static_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/data_structure/RangeSum1D.hpp\"\ntemplate <class\
    \ T>\nV<T> cumsum(const V<T>& vec) {\n    int n = vec.size();\n    V<T> res(n\
    \ + 1);\n    rep(i, n) { res[i + 1] = res[i] + vec[i]; }\n    return res;\n}\n"
  code: "template <class T>\nV<T> cumsum(const V<T>& vec) {\n    int n = vec.size();\n\
    \    V<T> res(n + 1);\n    rep(i, n) { res[i + 1] = res[i] + vec[i]; }\n    return\
    \ res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/data_structure/RangeSum1D.hpp
  requiredBy: []
  timestamp: '2022-05-22 15:10:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/static_range_sum.test.cpp
documentation_of: cpp_src/data_structure/RangeSum1D.hpp
layout: document
redirect_from:
- /library/cpp_src/data_structure/RangeSum1D.hpp
- /library/cpp_src/data_structure/RangeSum1D.hpp.html
title: cpp_src/data_structure/RangeSum1D.hpp
---
