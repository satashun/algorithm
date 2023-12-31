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
    - http://mathforum.org/library/drmath/view/73120.html
    - https://min-25.hatenablog.com/entry/2018/04/27/225535
  bundledCode: "#line 1 \"cpp_src/number_theory/GaussSum.hpp\"\n// x_i=floor((a*i+b)/c),\
    \ i=0,1,..n-1\n// a,c>0, b>=0\n// http://mathforum.org/library/drmath/view/73120.html\n\
    // https://min-25.hatenablog.com/entry/2018/04/27/225535\n\nll gauss_sum(ll n,\
    \ ll a, ll b, ll c) {\n    if (n == 0) return 0;\n    ll res = 0;\n    {\n   \
    \     ll p = a / c;\n        res += n * (n - 1) / 2 * p;\n        a %= c;\n  \
    \  }\n    {\n        ll p = b / c;\n        res += n * p;\n        b %= c;\n \
    \   }\n    if (a == 0) return res;\n    ll top = (a * (n - 1) + b) / c;\n    res\
    \ += top * n;\n    ll h = 1;\n    if (h <= top) {\n        res -= gauss_sum(top\
    \ - h + 1, c, c * h - (b + 1), a) + top - h + 1;\n    }\n    return res;\n}\n"
  code: "// x_i=floor((a*i+b)/c), i=0,1,..n-1\n// a,c>0, b>=0\n// http://mathforum.org/library/drmath/view/73120.html\n\
    // https://min-25.hatenablog.com/entry/2018/04/27/225535\n\nll gauss_sum(ll n,\
    \ ll a, ll b, ll c) {\n    if (n == 0) return 0;\n    ll res = 0;\n    {\n   \
    \     ll p = a / c;\n        res += n * (n - 1) / 2 * p;\n        a %= c;\n  \
    \  }\n    {\n        ll p = b / c;\n        res += n * p;\n        b %= c;\n \
    \   }\n    if (a == 0) return res;\n    ll top = (a * (n - 1) + b) / c;\n    res\
    \ += top * n;\n    ll h = 1;\n    if (h <= top) {\n        res -= gauss_sum(top\
    \ - h + 1, c, c * h - (b + 1), a) + top - h + 1;\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/number_theory/GaussSum.hpp
  requiredBy: []
  timestamp: '2023-12-31 13:48:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/number_theory/GaussSum.hpp
layout: document
redirect_from:
- /library/cpp_src/number_theory/GaussSum.hpp
- /library/cpp_src/number_theory/GaussSum.hpp.html
title: cpp_src/number_theory/GaussSum.hpp
---
