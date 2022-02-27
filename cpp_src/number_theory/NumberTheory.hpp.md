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
  bundledCode: "#line 1 \"cpp_src/number_theory/NumberTheory.hpp\"\n// O(sqrt(x))\n\
    ll totient(ll x) {\n    ll res = x;\n    for (ll i = 2; i * i <= x; ++i) {\n \
    \       if (x % i == 0) {\n            res = res / i * (i - 1);\n            while\
    \ (x % i == 0) {\n                x /= i;\n            }\n        }\n    }\n \
    \   if (x != 1) {\n        res = res / x * (x - 1);\n    }\n    return res;\n\
    }\n\n// O(sqrt(x))\nbool is_prime(ll x) {\n    if (x <= 1) return false;\n   \
    \ for (ll i = 2; i * i <= x; ++i) {\n        if (x % i == 0) return false;\n \
    \   }\n    return true;\n}\n\n// p:prime\n// ord p of n!\nll ord_fac(ll n, ll\
    \ p) {\n    ll res = 0;\n    while (n) {\n        n /= p;\n        res += n;\n\
    \    }\n    return res;\n}\n\nusing R = __int128;\n\nll pollrard_single(ll n)\
    \ {\n    auto f = [&](ll x) { return ((R)x * x + 1) % n; } if (is_prime(n)) return\
    \ n;\n    int x = 0;\n    while (true) {\n        x++;\n        ll y = f(x);\n\
    \        while (true) {\n            ll p = __gcd((y - x + n), n);\n         \
    \   if (p == 0 || p == n) break;\n            if (p != 1) return p;\n        \
    \    x = f(x);\n            y = f(f(y));\n        }\n    }\n}\n\nV<ll> pollrard(ll\
    \ n) {\n    if (n == 1) return {};\n    ll x = pollrard_single(n);\n    if (x\
    \ == n) return {x};\n    V<ll> v1 = pollrard(x), v2 = pollrard(n / x);\n    v1.insert(v1.end(),\
    \ ALL(v2));\n    return v1;\n}\n"
  code: "// O(sqrt(x))\nll totient(ll x) {\n    ll res = x;\n    for (ll i = 2; i\
    \ * i <= x; ++i) {\n        if (x % i == 0) {\n            res = res / i * (i\
    \ - 1);\n            while (x % i == 0) {\n                x /= i;\n         \
    \   }\n        }\n    }\n    if (x != 1) {\n        res = res / x * (x - 1);\n\
    \    }\n    return res;\n}\n\n// O(sqrt(x))\nbool is_prime(ll x) {\n    if (x\
    \ <= 1) return false;\n    for (ll i = 2; i * i <= x; ++i) {\n        if (x %\
    \ i == 0) return false;\n    }\n    return true;\n}\n\n// p:prime\n// ord p of\
    \ n!\nll ord_fac(ll n, ll p) {\n    ll res = 0;\n    while (n) {\n        n /=\
    \ p;\n        res += n;\n    }\n    return res;\n}\n\nusing R = __int128;\n\n\
    ll pollrard_single(ll n) {\n    auto f = [&](ll x) { return ((R)x * x + 1) % n;\
    \ } if (is_prime(n)) return n;\n    int x = 0;\n    while (true) {\n        x++;\n\
    \        ll y = f(x);\n        while (true) {\n            ll p = __gcd((y - x\
    \ + n), n);\n            if (p == 0 || p == n) break;\n            if (p != 1)\
    \ return p;\n            x = f(x);\n            y = f(f(y));\n        }\n    }\n\
    }\n\nV<ll> pollrard(ll n) {\n    if (n == 1) return {};\n    ll x = pollrard_single(n);\n\
    \    if (x == n) return {x};\n    V<ll> v1 = pollrard(x), v2 = pollrard(n / x);\n\
    \    v1.insert(v1.end(), ALL(v2));\n    return v1;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/number_theory/NumberTheory.hpp
  requiredBy: []
  timestamp: '2022-02-27 23:48:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/number_theory/NumberTheory.hpp
layout: document
redirect_from:
- /library/cpp_src/number_theory/NumberTheory.hpp
- /library/cpp_src/number_theory/NumberTheory.hpp.html
title: cpp_src/number_theory/NumberTheory.hpp
---
