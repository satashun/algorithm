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
  bundledCode: "#line 1 \"cpp_src/number_theory/Brute.hpp\"\n// O(sqrt(x))\nll totient(ll\
    \ x) {\n    ll res = x;\n    for (ll i = 2; i * i <= x; ++i) {\n        if (x\
    \ % i == 0) {\n            res = res / i * (i - 1);\n            while (x % i\
    \ == 0) {\n                x /= i;\n            }\n        }\n    }\n    if (x\
    \ != 1) {\n        res = res / x * (x - 1);\n    }\n    return res;\n}\n\n// O(sqrt(x))\n\
    bool is_prime(ll x) {\n    if (x <= 1) return false;\n    for (ll i = 2; i * i\
    \ <= x; ++i) {\n        if (x % i == 0) return false;\n    }\n    return true;\n\
    }\n\n// p:prime\n// ord p of n!\nll ord_fac(ll n, ll p) {\n    ll res = 0;\n \
    \   while (n) {\n        n /= p;\n        res += n;\n    }\n    return res;\n\
    }\n"
  code: "// O(sqrt(x))\nll totient(ll x) {\n    ll res = x;\n    for (ll i = 2; i\
    \ * i <= x; ++i) {\n        if (x % i == 0) {\n            res = res / i * (i\
    \ - 1);\n            while (x % i == 0) {\n                x /= i;\n         \
    \   }\n        }\n    }\n    if (x != 1) {\n        res = res / x * (x - 1);\n\
    \    }\n    return res;\n}\n\n// O(sqrt(x))\nbool is_prime(ll x) {\n    if (x\
    \ <= 1) return false;\n    for (ll i = 2; i * i <= x; ++i) {\n        if (x %\
    \ i == 0) return false;\n    }\n    return true;\n}\n\n// p:prime\n// ord p of\
    \ n!\nll ord_fac(ll n, ll p) {\n    ll res = 0;\n    while (n) {\n        n /=\
    \ p;\n        res += n;\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/number_theory/Brute.hpp
  requiredBy: []
  timestamp: '2022-03-17 13:38:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/number_theory/Brute.hpp
layout: document
redirect_from:
- /library/cpp_src/number_theory/Brute.hpp
- /library/cpp_src/number_theory/Brute.hpp.html
title: cpp_src/number_theory/Brute.hpp
---
