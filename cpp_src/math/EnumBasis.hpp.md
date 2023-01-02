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
  bundledCode: "#line 1 \"cpp_src/math/EnumBasis.hpp\"\n// ABC283G\n// modified noshi\
    \ basis\n\ntemplate <class T>\nV<T> enum_basis(V<T> a) {\n    V<T> basis;\n\n\
    \    for (auto e : a) {\n        for (auto b : basis) chmin(e, e ^ b);\n     \
    \   if (e) {\n            for (auto& x : basis) {\n                chmin(x, x\
    \ ^ e);\n            }\n            basis.push_back(e);\n        }\n    }\n  \
    \  return basis;\n}\n"
  code: "// ABC283G\n// modified noshi basis\n\ntemplate <class T>\nV<T> enum_basis(V<T>\
    \ a) {\n    V<T> basis;\n\n    for (auto e : a) {\n        for (auto b : basis)\
    \ chmin(e, e ^ b);\n        if (e) {\n            for (auto& x : basis) {\n  \
    \              chmin(x, x ^ e);\n            }\n            basis.push_back(e);\n\
    \        }\n    }\n    return basis;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/math/EnumBasis.hpp
  requiredBy: []
  timestamp: '2023-01-02 15:43:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/math/EnumBasis.hpp
layout: document
redirect_from:
- /library/cpp_src/math/EnumBasis.hpp
- /library/cpp_src/math/EnumBasis.hpp.html
title: cpp_src/math/EnumBasis.hpp
---
