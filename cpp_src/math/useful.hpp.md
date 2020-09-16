---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"cpp_src/math/useful.hpp\"\nconstexpr ll floor_sqrt(ll n)\
    \ {\n\tif (n == 0) return 0;\n\treturn llround(floor(sqrt(n)));\n}\n\n//from USACO\n\
    using ull = unsigned long long;\nusing L = __uint128_t;\n\nstruct FastMod {\n\t\
    ull b, m;\n\tFastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}\n\tull reduce(ull\
    \ a) {\n\t\tull q = (ull)((L(m) * a) >> 64);\n\t\tull r = a - q * b; // can be\
    \ proven that 0 <= r < 2*b\n\t\treturn r >= b ? r - b : r;\n\t}\n};\n"
  code: "constexpr ll floor_sqrt(ll n) {\n\tif (n == 0) return 0;\n\treturn llround(floor(sqrt(n)));\n\
    }\n\n//from USACO\nusing ull = unsigned long long;\nusing L = __uint128_t;\n\n\
    struct FastMod {\n\tull b, m;\n\tFastMod(ull b) : b(b), m(ull((L(1) << 64) / b))\
    \ {}\n\tull reduce(ull a) {\n\t\tull q = (ull)((L(m) * a) >> 64);\n\t\tull r =\
    \ a - q * b; // can be proven that 0 <= r < 2*b\n\t\treturn r >= b ? r - b : r;\n\
    \t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/math/useful.hpp
  requiredBy: []
  timestamp: '2020-09-17 02:07:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/math/useful.hpp
layout: document
redirect_from:
- /library/cpp_src/math/useful.hpp
- /library/cpp_src/math/useful.hpp.html
title: cpp_src/math/useful.hpp
---
