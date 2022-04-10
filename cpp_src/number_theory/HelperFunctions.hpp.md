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
  bundledCode: "#line 1 \"cpp_src/number_theory/HelperFunctions.hpp\"\n// floor(a\
    \ / b)\ntemplate <class T>\nT div_floor(T a, T b) {\n    return a / b - (((a ^\
    \ b) < 0 && a % b != 0) ? 1 : 0);\n}\n\n// ceil(a / b)\ntemplate <class T>\nT\
    \ div_ceil(T a, T b) {\n    return a / b + (((a ^ b) > 0 && a % b != 0) ? 1 :\
    \ 0);\n}\n\nconstexpr ll floor_sqrt(ll n) {\n    if (n == 0) return 0;\n    return\
    \ llround(trunc(floor(sqrt((long double)n))));\n}\n\n// from USACO\nusing ull\
    \ = unsigned long long;\nusing L = __uint128_t;\n\nstruct FastMod {\n    ull b,\
    \ m;\n    FastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}\n    ull reduce(ull\
    \ a) {\n        ull q = (ull)((L(m) * a) >> 64);\n        ull r = a - q * b; \
    \ // can be proven that 0 <= r < 2*b\n        return r >= b ? r - b : r;\n   \
    \ }\n};\n"
  code: "// floor(a / b)\ntemplate <class T>\nT div_floor(T a, T b) {\n    return\
    \ a / b - (((a ^ b) < 0 && a % b != 0) ? 1 : 0);\n}\n\n// ceil(a / b)\ntemplate\
    \ <class T>\nT div_ceil(T a, T b) {\n    return a / b + (((a ^ b) > 0 && a % b\
    \ != 0) ? 1 : 0);\n}\n\nconstexpr ll floor_sqrt(ll n) {\n    if (n == 0) return\
    \ 0;\n    return llround(trunc(floor(sqrt((long double)n))));\n}\n\n// from USACO\n\
    using ull = unsigned long long;\nusing L = __uint128_t;\n\nstruct FastMod {\n\
    \    ull b, m;\n    FastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}\n    ull\
    \ reduce(ull a) {\n        ull q = (ull)((L(m) * a) >> 64);\n        ull r = a\
    \ - q * b;  // can be proven that 0 <= r < 2*b\n        return r >= b ? r - b\
    \ : r;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/number_theory/HelperFunctions.hpp
  requiredBy: []
  timestamp: '2022-04-10 12:39:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/number_theory/HelperFunctions.hpp
layout: document
redirect_from:
- /library/cpp_src/number_theory/HelperFunctions.hpp
- /library/cpp_src/number_theory/HelperFunctions.hpp.html
title: cpp_src/number_theory/HelperFunctions.hpp
---
