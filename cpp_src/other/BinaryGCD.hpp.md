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
    - https://zwxadz.hateblo.jp/entry/2015/04/17/220850
  bundledCode: "#line 1 \"cpp_src/other/BinaryGCD.hpp\"\n// ref : https://zwxadz.hateblo.jp/entry/2015/04/17/220850\n\
    \n// bit op\nint popcnt(uint x) { return __builtin_popcount(x); }\nint popcnt(ull\
    \ x) { return __builtin_popcountll(x); }\nint bsr(uint x) { return 31 - __builtin_clz(x);\
    \ }\nint bsr(ull x) { return 63 - __builtin_clzll(x); }\nint bsf(uint x) { return\
    \ __builtin_ctz(x); }\nint bsf(ull x) { return __builtin_ctzll(x); }\n\n// binary\
    \ gcd\nll binary_gcd(ll _a, ll _b) {\n    ull a = abs(_a), b = abs(_b);\n    if\
    \ (a == 0) return b;\n    if (b == 0) return a;\n    int shift = bsf(a | b);\n\
    \    a >>= bsf(a);\n    do {\n        b >>= bsf(b);\n        if (a > b) swap(a,\
    \ b);\n        b -= a;\n    } while (b);\n    return (a << shift);\n}\n"
  code: "// ref : https://zwxadz.hateblo.jp/entry/2015/04/17/220850\n\n// bit op\n\
    int popcnt(uint x) { return __builtin_popcount(x); }\nint popcnt(ull x) { return\
    \ __builtin_popcountll(x); }\nint bsr(uint x) { return 31 - __builtin_clz(x);\
    \ }\nint bsr(ull x) { return 63 - __builtin_clzll(x); }\nint bsf(uint x) { return\
    \ __builtin_ctz(x); }\nint bsf(ull x) { return __builtin_ctzll(x); }\n\n// binary\
    \ gcd\nll binary_gcd(ll _a, ll _b) {\n    ull a = abs(_a), b = abs(_b);\n    if\
    \ (a == 0) return b;\n    if (b == 0) return a;\n    int shift = bsf(a | b);\n\
    \    a >>= bsf(a);\n    do {\n        b >>= bsf(b);\n        if (a > b) swap(a,\
    \ b);\n        b -= a;\n    } while (b);\n    return (a << shift);\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/other/BinaryGCD.hpp
  requiredBy: []
  timestamp: '2022-03-17 11:21:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/other/BinaryGCD.hpp
layout: document
title: Binary GCD
---

bit shift 以外の除算を使わない GCD

## 使用例

``` cpp
long long a, b;
long long g = binary_gcd(a, b);
```

## 参考

- [Binary GCD algorithm - Wikipedia](https://en.wikipedia.org/wiki/Binary_GCD_algorithm)
- https://zwxadz.hateblo.jp/entry/2015/04/17/220850