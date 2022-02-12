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
  bundledCode: "#line 1 \"cpp_src/other/EnumQuotient.hpp\"\nV<pair<ll, ll>> enum_quotient(ll\
    \ N) {\n    V<pair<ll, ll>> res;\n    ll l = 1;\n    while (l <= N) {\n      \
    \  ll r = N / (N / l) + 1;\n        //[l, r)\n        res.emplace_back(l, r);\n\
    \        l = r;\n    }\n    return res;\n}\n"
  code: "V<pair<ll, ll>> enum_quotient(ll N) {\n    V<pair<ll, ll>> res;\n    ll l\
    \ = 1;\n    while (l <= N) {\n        ll r = N / (N / l) + 1;\n        //[l, r)\n\
    \        res.emplace_back(l, r);\n        l = r;\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/other/EnumQuotient.hpp
  requiredBy: []
  timestamp: '2022-02-12 18:33:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/other/EnumQuotient.hpp
layout: document
redirect_from:
- /library/cpp_src/other/EnumQuotient.hpp
- /library/cpp_src/other/EnumQuotient.hpp.html
title: cpp_src/other/EnumQuotient.hpp
---
