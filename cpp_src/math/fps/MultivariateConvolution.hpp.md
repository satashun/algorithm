---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://nyaannyaan.github.io/library/ntt/multivariate-multiplication.hpp
    - https://rushcheyo.blog.uoj.ac/blog/6547
  bundledCode: "#line 1 \"cpp_src/math/fps/MultivariateConvolution.hpp\"\n// reference\n\
    // https://nyaannyaan.github.io/library/ntt/multivariate-multiplication.hpp\n\
    // https://rushcheyo.blog.uoj.ac/blog/6547\n\n// f(x_1, x_2, ..., x_k) * g(x_1,\
    \ x_2, ..., x_k) mod (x_1^n_1, \\cdots, x_k^n_k)\n// base : {n_1, n_2, \\cdots,\
    \ n_k}\n// i = i_1 + i_2 * n_1 + \\cdots + i_k * (n_1 * n_2 \\cdots * n_{k-1})\n\
    // also useful for subset convolution\n\ntemplate <class T>\nV<T> multivariate_convolution(V<T>\
    \ a, V<T> b, V<int> base) {\n    NumberTheoreticTransform<T> ntt;\n    ntt.init();\n\
    \n    int K = base.size();\n\n    if (K == 0) {\n        return V<T>{a[0] * b[0]};\n\
    \    }\n\n    int n = a.size();\n    int w = 1;\n    while (w < n * 2) w *= 2;\n\
    \n    V<int> chi(n);\n    for (int i = 0; i < n; ++i) {\n        int t = i;\n\
    \        int res = 0;\n        for (int j = 0; j < K - 1; ++j) {\n           \
    \ t /= base[j];\n            res = (res + t) % K;\n        }\n        chi[i] =\
    \ res;\n    }\n\n    VV<T> F(K, V<T>(w)), G(K, V<T>(w));\n\n    for (int i = 0;\
    \ i < n; ++i) {\n        F[chi[i]][i] += a[i];\n        G[chi[i]][i] += b[i];\n\
    \    }\n\n    for (int i = 0; i < K; ++i) {\n        ntt.ntt(F[i]);\n        ntt.ntt(G[i]);\n\
    \    }\n\n    VV<T> A(K, V<T>(w));\n    rep(p, w) {\n        V<Mint> res(K);\n\
    \        rep(i, K) {\n            rep(j, K) { res[(i + j) % K] += F[i][p] * G[j][p];\
    \ }\n        }\n        rep(i, K) A[i][p] += res[i];\n    }\n    rep(i, K) ntt.ntt(A[i],\
    \ true);\n    V<T> res(n);\n    rep(i, n) res[i] = A[chi[i]][i];\n    return res;\n\
    }\n"
  code: "// reference\n// https://nyaannyaan.github.io/library/ntt/multivariate-multiplication.hpp\n\
    // https://rushcheyo.blog.uoj.ac/blog/6547\n\n// f(x_1, x_2, ..., x_k) * g(x_1,\
    \ x_2, ..., x_k) mod (x_1^n_1, \\cdots, x_k^n_k)\n// base : {n_1, n_2, \\cdots,\
    \ n_k}\n// i = i_1 + i_2 * n_1 + \\cdots + i_k * (n_1 * n_2 \\cdots * n_{k-1})\n\
    // also useful for subset convolution\n\ntemplate <class T>\nV<T> multivariate_convolution(V<T>\
    \ a, V<T> b, V<int> base) {\n    NumberTheoreticTransform<T> ntt;\n    ntt.init();\n\
    \n    int K = base.size();\n\n    if (K == 0) {\n        return V<T>{a[0] * b[0]};\n\
    \    }\n\n    int n = a.size();\n    int w = 1;\n    while (w < n * 2) w *= 2;\n\
    \n    V<int> chi(n);\n    for (int i = 0; i < n; ++i) {\n        int t = i;\n\
    \        int res = 0;\n        for (int j = 0; j < K - 1; ++j) {\n           \
    \ t /= base[j];\n            res = (res + t) % K;\n        }\n        chi[i] =\
    \ res;\n    }\n\n    VV<T> F(K, V<T>(w)), G(K, V<T>(w));\n\n    for (int i = 0;\
    \ i < n; ++i) {\n        F[chi[i]][i] += a[i];\n        G[chi[i]][i] += b[i];\n\
    \    }\n\n    for (int i = 0; i < K; ++i) {\n        ntt.ntt(F[i]);\n        ntt.ntt(G[i]);\n\
    \    }\n\n    VV<T> A(K, V<T>(w));\n    rep(p, w) {\n        V<Mint> res(K);\n\
    \        rep(i, K) {\n            rep(j, K) { res[(i + j) % K] += F[i][p] * G[j][p];\
    \ }\n        }\n        rep(i, K) A[i][p] += res[i];\n    }\n    rep(i, K) ntt.ntt(A[i],\
    \ true);\n    V<T> res(n);\n    rep(i, n) res[i] = A[chi[i]][i];\n    return res;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/math/fps/MultivariateConvolution.hpp
  requiredBy: []
  timestamp: '2021-10-02 23:37:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/math/fps/MultivariateConvolution.hpp
layout: document
redirect_from:
- /library/cpp_src/math/fps/MultivariateConvolution.hpp
- /library/cpp_src/math/fps/MultivariateConvolution.hpp.html
title: cpp_src/math/fps/MultivariateConvolution.hpp
---
