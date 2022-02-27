---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/other/FastTransformation.cpp\"\n//g(S) = \u03A3\
    [S\u2286T]f(T)\nrep(i, n) rep(j, 1 << n) if(!(j & 1 << i)) f[j] += f[j | (1 <<\
    \ i)];\n\n//g(S) = \u03A3[T\u2286S]f(T)\nrep(i, n) rep(j, 1 << n) if (j & (1 <<\
    \ i)) f[j] += f[j ^ (1<<i)];\n\n//mobius f(S) = \u03A3[T\u2286S](-1)^|S - T| g(T)\
    \ \nrep(i, n) rep(j, 1 << n) if(j & 1 << i) f[j] -= f[j ^ 1 << i];\n\n//including\
    \ mask\nfor (int i = mask; i < (1 << n); i = ((i+1) | mask)) ;\n\n//subset of\
    \ mask \nfor (int i = mask; i >= 0; --i) {\n\ti &= mask;\n}\n"
  code: "//g(S) = \u03A3[S\u2286T]f(T)\nrep(i, n) rep(j, 1 << n) if(!(j & 1 << i))\
    \ f[j] += f[j | (1 << i)];\n\n//g(S) = \u03A3[T\u2286S]f(T)\nrep(i, n) rep(j,\
    \ 1 << n) if (j & (1 << i)) f[j] += f[j ^ (1<<i)];\n\n//mobius f(S) = \u03A3[T\u2286\
    S](-1)^|S - T| g(T) \nrep(i, n) rep(j, 1 << n) if(j & 1 << i) f[j] -= f[j ^ 1\
    \ << i];\n\n//including mask\nfor (int i = mask; i < (1 << n); i = ((i+1) | mask))\
    \ ;\n\n//subset of mask \nfor (int i = mask; i >= 0; --i) {\n\ti &= mask;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/other/FastTransformation.cpp
  requiredBy: []
  timestamp: '2022-02-27 23:48:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/other/FastTransformation.cpp
layout: document
redirect_from:
- /library/cpp_src/other/FastTransformation.cpp
- /library/cpp_src/other/FastTransformation.cpp.html
title: cpp_src/other/FastTransformation.cpp
---
