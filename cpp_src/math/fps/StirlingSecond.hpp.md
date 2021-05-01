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
    - https://min-25.hatenablog.com/entry/2015/04/07/160154
  bundledCode: "#line 1 \"cpp_src/math/fps/StirlingSecond.hpp\"\n// divide n people\
    \ into k groups\n// enumerate S(n, k)\n// for 0 \\leq k \\leq n\n// S(n, k) =\
    \ \\sum_{i=1}^k (-1)^(n-k) * \\binom{k}{i} * i^n\n// We can calculate i^n in O(n\
    \ loglog n) time\n// ref : https://min-25.hatenablog.com/entry/2015/04/07/160154\n\
    \nV<Mint> stirling_second(int n) {\n    V<Mint> a(n + 1), b(n + 1);\n    for (int\
    \ i = 0; i <= n; ++i) {\n        a[i] = ifact[i] * (i % 2 ? -1 : 1);\n       \
    \ b[i] = Mint(i).pow(n) * ifact[i];\n    }\n    auto c = ntt.mul(a, b);\n    c.resize(n\
    \ + 1);\n    return c;\n}\n"
  code: "// divide n people into k groups\n// enumerate S(n, k)\n// for 0 \\leq k\
    \ \\leq n\n// S(n, k) = \\sum_{i=1}^k (-1)^(n-k) * \\binom{k}{i} * i^n\n// We\
    \ can calculate i^n in O(n loglog n) time\n// ref : https://min-25.hatenablog.com/entry/2015/04/07/160154\n\
    \nV<Mint> stirling_second(int n) {\n    V<Mint> a(n + 1), b(n + 1);\n    for (int\
    \ i = 0; i <= n; ++i) {\n        a[i] = ifact[i] * (i % 2 ? -1 : 1);\n       \
    \ b[i] = Mint(i).pow(n) * ifact[i];\n    }\n    auto c = ntt.mul(a, b);\n    c.resize(n\
    \ + 1);\n    return c;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/math/fps/StirlingSecond.hpp
  requiredBy: []
  timestamp: '2021-05-01 18:46:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/math/fps/StirlingSecond.hpp
layout: document
redirect_from:
- /library/cpp_src/math/fps/StirlingSecond.hpp
- /library/cpp_src/math/fps/StirlingSecond.hpp.html
title: cpp_src/math/fps/StirlingSecond.hpp
---
