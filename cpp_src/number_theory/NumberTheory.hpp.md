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
  bundledCode: "#line 1 \"cpp_src/number_theory/NumberTheory.hpp\"\n//O(sqrt(x))\n\
    ll totient(ll x) {\n\tll res = x;\n\tfor (ll i = 2; i * i <= x; ++i) {\n\t\tif\
    \ (x % i == 0) {\n\t\t\tres = res / i * (i-1);\n\t\t\twhile (x % i == 0) {\n\t\
    \t\t\tx /= i;\n\t\t\t}\n\t\t}\n\t}\n\tif (x != 1) {\n\t\tres = res / x * (x -\
    \ 1);\n\t}\n\treturn res;\n}\n\n// p:prime\n// ord p of n!\nll ord_fac(ll n, ll\
    \ p) {\n    ll res = 0;\n    while (n) {\n        n /= p;\n        res += n;\n\
    \    }\n    return res;\n}\n\n\nusing R = __int128;\n\nll pollrard_single(ll n)\
    \ {\n\tauto f = [&](ll x) {\n\t\treturn ((R)x * x + 1) % n;\n\t}\n\tif (is_prime(n))\
    \ return n;\n\tint x = 0;\n\twhile (true) {\n\t\tx++;\n\t\tll y = f(x);\n\t\t\
    while (true) {\n\t\t\tll p = __gcd((y - x + n), n);\n\t\t\tif (p == 0 || p ==\
    \ n) break;\n\t\t\tif (p != 1) return p;\n\t\t\tx = f(x);\n\t\t\ty = f(f(y));\n\
    \t\t}\n\t}\n}\n\nV<ll> pollrard(ll n) {\n\tif (n == 1) return {};\n\tll x = pollrard_single(n);\n\
    \tif (x == n) return {x};\n\tV<ll> v1 = pollrard(x), v2 = pollrard(n / x);\n\t\
    v1.insert(v1.end(), ALL(v2));\n\treturn v1;\n}\n"
  code: "//O(sqrt(x))\nll totient(ll x) {\n\tll res = x;\n\tfor (ll i = 2; i * i <=\
    \ x; ++i) {\n\t\tif (x % i == 0) {\n\t\t\tres = res / i * (i-1);\n\t\t\twhile\
    \ (x % i == 0) {\n\t\t\t\tx /= i;\n\t\t\t}\n\t\t}\n\t}\n\tif (x != 1) {\n\t\t\
    res = res / x * (x - 1);\n\t}\n\treturn res;\n}\n\n// p:prime\n// ord p of n!\n\
    ll ord_fac(ll n, ll p) {\n    ll res = 0;\n    while (n) {\n        n /= p;\n\
    \        res += n;\n    }\n    return res;\n}\n\n\nusing R = __int128;\n\nll pollrard_single(ll\
    \ n) {\n\tauto f = [&](ll x) {\n\t\treturn ((R)x * x + 1) % n;\n\t}\n\tif (is_prime(n))\
    \ return n;\n\tint x = 0;\n\twhile (true) {\n\t\tx++;\n\t\tll y = f(x);\n\t\t\
    while (true) {\n\t\t\tll p = __gcd((y - x + n), n);\n\t\t\tif (p == 0 || p ==\
    \ n) break;\n\t\t\tif (p != 1) return p;\n\t\t\tx = f(x);\n\t\t\ty = f(f(y));\n\
    \t\t}\n\t}\n}\n\nV<ll> pollrard(ll n) {\n\tif (n == 1) return {};\n\tll x = pollrard_single(n);\n\
    \tif (x == n) return {x};\n\tV<ll> v1 = pollrard(x), v2 = pollrard(n / x);\n\t\
    v1.insert(v1.end(), ALL(v2));\n\treturn v1;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/number_theory/NumberTheory.hpp
  requiredBy: []
  timestamp: '2022-02-12 18:33:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/number_theory/NumberTheory.hpp
layout: document
redirect_from:
- /library/cpp_src/number_theory/NumberTheory.hpp
- /library/cpp_src/number_theory/NumberTheory.hpp.html
title: cpp_src/number_theory/NumberTheory.hpp
---
