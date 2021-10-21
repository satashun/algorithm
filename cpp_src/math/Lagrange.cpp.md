---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/ei1333/library/blob/master/math/combinatorics/lagrange-polynomial.cpp
  bundledCode: "#line 1 \"cpp_src/math/Lagrange.cpp\"\n// https://github.com/ei1333/library/blob/master/math/combinatorics/lagrange-polynomial.cpp\n\
    // y_i = f(i) for i = 0, 1, ..., N\n// evaluate f(t)\n\ntemplate <typename T>\n\
    T lagrange_polynomial(const vector<T> &y, ll t) {\n    int N = y.size() - 1;\n\
    \    if (t <= N) return y[t];\n    T ret(0);\n    vector<T> dp(N + 1, 1), pd(N\
    \ + 1, 1);\n    for (int i = 0; i < N; i++) dp[i + 1] = dp[i] * (t - i);\n   \
    \ for (int i = N; i > 0; i--) pd[i - 1] = pd[i] * (t - i);\n    for (int i = 0;\
    \ i <= N; i++) {\n        T tmp = y[i] * dp[i] * pd[i] * ifact[i] * ifact[N -\
    \ i];\n        if ((N - i) & 1)\n            ret -= tmp;\n        else\n     \
    \       ret += tmp;\n    }\n    return ret;\n}\n"
  code: "// https://github.com/ei1333/library/blob/master/math/combinatorics/lagrange-polynomial.cpp\n\
    // y_i = f(i) for i = 0, 1, ..., N\n// evaluate f(t)\n\ntemplate <typename T>\n\
    T lagrange_polynomial(const vector<T> &y, ll t) {\n    int N = y.size() - 1;\n\
    \    if (t <= N) return y[t];\n    T ret(0);\n    vector<T> dp(N + 1, 1), pd(N\
    \ + 1, 1);\n    for (int i = 0; i < N; i++) dp[i + 1] = dp[i] * (t - i);\n   \
    \ for (int i = N; i > 0; i--) pd[i - 1] = pd[i] * (t - i);\n    for (int i = 0;\
    \ i <= N; i++) {\n        T tmp = y[i] * dp[i] * pd[i] * ifact[i] * ifact[N -\
    \ i];\n        if ((N - i) & 1)\n            ret -= tmp;\n        else\n     \
    \       ret += tmp;\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/math/Lagrange.cpp
  requiredBy: []
  timestamp: '2021-10-21 19:43:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/math/Lagrange.cpp
layout: document
redirect_from:
- /library/cpp_src/math/Lagrange.cpp
- /library/cpp_src/math/Lagrange.cpp.html
title: cpp_src/math/Lagrange.cpp
---
