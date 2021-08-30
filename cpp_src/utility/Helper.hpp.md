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
  bundledCode: "#line 1 \"cpp_src/utility/Helper.hpp\"\ntemplate <class T>\nvoid make_unique(vector<T>&\
    \ v) {\n    sort(v.begin(), v.end());\n    v.erase(unique(v.begin(), v.end()),\
    \ v.end());\n}\n"
  code: "template <class T>\nvoid make_unique(vector<T>& v) {\n    sort(v.begin(),\
    \ v.end());\n    v.erase(unique(v.begin(), v.end()), v.end());\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/utility/Helper.hpp
  requiredBy: []
  timestamp: '2021-08-30 10:48:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/utility/Helper.hpp
layout: document
redirect_from:
- /library/cpp_src/utility/Helper.hpp
- /library/cpp_src/utility/Helper.hpp.html
title: cpp_src/utility/Helper.hpp
---
