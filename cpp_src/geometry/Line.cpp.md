---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/geometry/Line.cpp\"\nusing Line = tuple<ll, ll,\
    \ ll>;\n\n// ax + by + c = 0\n\nLine normalize(ll a, ll b, ll c) {\n    if (a\
    \ < 0) {\n        a *= -1, b *= -1, c *= -1;\n    }\n    if (a == 0 && b < 0)\
    \ {\n        a *= -1, b *= -1, c *= -1;\n    }\n    ll d = gcd(abs(a), abs(b));\n\
    \    d = gcd(d, abs(c));\n    a /= d, b /= d, c /= d;\n    return make_tuple(a,\
    \ b, c);\n}\n"
  code: "using Line = tuple<ll, ll, ll>;\n\n// ax + by + c = 0\n\nLine normalize(ll\
    \ a, ll b, ll c) {\n    if (a < 0) {\n        a *= -1, b *= -1, c *= -1;\n   \
    \ }\n    if (a == 0 && b < 0) {\n        a *= -1, b *= -1, c *= -1;\n    }\n \
    \   ll d = gcd(abs(a), abs(b));\n    d = gcd(d, abs(c));\n    a /= d, b /= d,\
    \ c /= d;\n    return make_tuple(a, b, c);\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/geometry/Line.cpp
  requiredBy: []
  timestamp: '2022-01-02 16:22:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/geometry/Line.cpp
layout: document
redirect_from:
- /library/cpp_src/geometry/Line.cpp
- /library/cpp_src/geometry/Line.cpp.html
title: cpp_src/geometry/Line.cpp
---
