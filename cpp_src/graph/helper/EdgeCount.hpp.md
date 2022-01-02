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
  bundledCode: "#line 1 \"cpp_src/graph/helper/EdgeCount.hpp\"\n// ABC213G (also subset\
    \ convolution)\n// O(N * 2^N)\n// es[S] := #((u,v) s.t. u \\in S & v \\in S)\n\
    \nV<int> edge_count(const VV<int>& e) {\n    int n = SZ(e);\n    V<int> es(1 <<\
    \ n);\n    rep(i, 1 << n) {\n        if (i == 0) continue;\n        int p = -1;\n\
    \n        rep(j, n) if (i >> j & 1) { p = j; }\n        es[i] = es[i ^ (1 << p)];\n\
    \        rep(j, p) if (i >> j & 1) { es[i] += e[j][p]; }\n    }\n    return es;\n\
    }\n"
  code: "// ABC213G (also subset convolution)\n// O(N * 2^N)\n// es[S] := #((u,v)\
    \ s.t. u \\in S & v \\in S)\n\nV<int> edge_count(const VV<int>& e) {\n    int\
    \ n = SZ(e);\n    V<int> es(1 << n);\n    rep(i, 1 << n) {\n        if (i == 0)\
    \ continue;\n        int p = -1;\n\n        rep(j, n) if (i >> j & 1) { p = j;\
    \ }\n        es[i] = es[i ^ (1 << p)];\n        rep(j, p) if (i >> j & 1) { es[i]\
    \ += e[j][p]; }\n    }\n    return es;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/helper/EdgeCount.hpp
  requiredBy: []
  timestamp: '2022-01-02 16:22:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/helper/EdgeCount.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/helper/EdgeCount.hpp
- /library/cpp_src/graph/helper/EdgeCount.hpp.html
title: cpp_src/graph/helper/EdgeCount.hpp
---
