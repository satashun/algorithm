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
    - http://miller-rabin.appspot.com/
    - https://joisino.hatenablog.com/entry/2017/08/03/210000
    - https://misteer.hatenablog.com/entry/miller-rabin
    - https://yukicoder.me/problems/no/3030
  bundledCode: "#line 1 \"cpp_src/number_theory/DefiniteMillerRabin.hpp\"\ntemplate\
    \ <class T>\nT powmod(T x, ll k, T m) {\n    x %= m;\n    T res(1);\n    while\
    \ (k) {\n        if (k & 1) {\n            res = res * x % m;\n        }\n   \
    \     k >>= 1;\n        x = x * x % m;\n    }\n    return res;\n}\n\n// see :\
    \ https://joisino.hatenablog.com/entry/2017/08/03/210000\n// see : https://misteer.hatenablog.com/entry/miller-rabin\n\
    // test : https://yukicoder.me/problems/no/3030\n// ref : http://miller-rabin.appspot.com/\n\
    // check if n is prime\n// n < 4,759,123,141 -> call miller_rabin\n// 2^64 > n\
    \ >= 4,759,123,141 -> call miller_rabin_big\n// O(k log^3 n)\n\nbool miller_rabin(ll\
    \ n) {\n    static const vector<ll> v = {2, 7, 61};\n    if (n < 2) {\n      \
    \  return false;\n    } else if (n == 2) {\n        return true;\n    } else if\
    \ (n % 2 == 0) {\n        return false;\n    }\n\n    ull d = n - 1;\n    int\
    \ s = 0;\n    while (d % 2 == 0) {\n        d /= 2;\n        s++;\n    }\n   \
    \ for (auto a : v) {\n        if (a % n == 0) continue;\n        auto x = powmod(a,\
    \ d, n);\n        if (x == 1 || x == n - 1) continue;\n\n        rep(r, s) {\n\
    \            auto y = x * x % n;\n            if (y == 1) {\n                if\
    \ (x != 1 && x != n - 1) {\n                    return false;\n              \
    \  } else {\n                    x = 1;\n                    break;\n        \
    \        }\n            }\n            x = y;\n        }\n        if (x != 1)\
    \ return false;\n    }\n    return true;\n}\n\nusing R = __int128_t;\nusing ull\
    \ = unsigned long long;\nbool miller_rabin_big(ull n) {\n    static const vector<R>\
    \ v = {2,      325,     9375,      28178,\n                                450775,\
    \ 9780504, 1795265022};\n\n    if (n < 2) {\n        return false;\n    } else\
    \ if (n == 2) {\n        return true;\n    } else if (n % 2 == 0) {\n        return\
    \ false;\n    }\n\n    ull d = n - 1;\n    int s = 0;\n    while (d % 2 == 0)\
    \ {\n        d /= 2;\n        s++;\n    }\n    for (auto a : v) {\n        if\
    \ (a % n == 0) continue;\n        auto x = powmod(a, d, R(n));\n        if (x\
    \ == 1 || x == n - 1) continue;\n\n        rep(r, s) {\n            auto y = x\
    \ * x % n;\n            if (y == 1) {\n                if (x != 1 && x != n -\
    \ 1) {\n                    return false;\n                } else {\n        \
    \            x = 1;\n                    break;\n                }\n         \
    \   }\n            x = y;\n        }\n        if (x != 1) return false;\n    }\n\
    \    return true;\n}\n"
  code: "template <class T>\nT powmod(T x, ll k, T m) {\n    x %= m;\n    T res(1);\n\
    \    while (k) {\n        if (k & 1) {\n            res = res * x % m;\n     \
    \   }\n        k >>= 1;\n        x = x * x % m;\n    }\n    return res;\n}\n\n\
    // see : https://joisino.hatenablog.com/entry/2017/08/03/210000\n// see : https://misteer.hatenablog.com/entry/miller-rabin\n\
    // test : https://yukicoder.me/problems/no/3030\n// ref : http://miller-rabin.appspot.com/\n\
    // check if n is prime\n// n < 4,759,123,141 -> call miller_rabin\n// 2^64 > n\
    \ >= 4,759,123,141 -> call miller_rabin_big\n// O(k log^3 n)\n\nbool miller_rabin(ll\
    \ n) {\n    static const vector<ll> v = {2, 7, 61};\n    if (n < 2) {\n      \
    \  return false;\n    } else if (n == 2) {\n        return true;\n    } else if\
    \ (n % 2 == 0) {\n        return false;\n    }\n\n    ull d = n - 1;\n    int\
    \ s = 0;\n    while (d % 2 == 0) {\n        d /= 2;\n        s++;\n    }\n   \
    \ for (auto a : v) {\n        if (a % n == 0) continue;\n        auto x = powmod(a,\
    \ d, n);\n        if (x == 1 || x == n - 1) continue;\n\n        rep(r, s) {\n\
    \            auto y = x * x % n;\n            if (y == 1) {\n                if\
    \ (x != 1 && x != n - 1) {\n                    return false;\n              \
    \  } else {\n                    x = 1;\n                    break;\n        \
    \        }\n            }\n            x = y;\n        }\n        if (x != 1)\
    \ return false;\n    }\n    return true;\n}\n\nusing R = __int128_t;\nusing ull\
    \ = unsigned long long;\nbool miller_rabin_big(ull n) {\n    static const vector<R>\
    \ v = {2,      325,     9375,      28178,\n                                450775,\
    \ 9780504, 1795265022};\n\n    if (n < 2) {\n        return false;\n    } else\
    \ if (n == 2) {\n        return true;\n    } else if (n % 2 == 0) {\n        return\
    \ false;\n    }\n\n    ull d = n - 1;\n    int s = 0;\n    while (d % 2 == 0)\
    \ {\n        d /= 2;\n        s++;\n    }\n    for (auto a : v) {\n        if\
    \ (a % n == 0) continue;\n        auto x = powmod(a, d, R(n));\n        if (x\
    \ == 1 || x == n - 1) continue;\n\n        rep(r, s) {\n            auto y = x\
    \ * x % n;\n            if (y == 1) {\n                if (x != 1 && x != n -\
    \ 1) {\n                    return false;\n                } else {\n        \
    \            x = 1;\n                    break;\n                }\n         \
    \   }\n            x = y;\n        }\n        if (x != 1) return false;\n    }\n\
    \    return true;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/number_theory/DefiniteMillerRabin.hpp
  requiredBy: []
  timestamp: '2022-02-27 23:48:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/number_theory/DefiniteMillerRabin.hpp
layout: document
redirect_from:
- /library/cpp_src/number_theory/DefiniteMillerRabin.hpp
- /library/cpp_src/number_theory/DefiniteMillerRabin.hpp.html
title: cpp_src/number_theory/DefiniteMillerRabin.hpp
---
