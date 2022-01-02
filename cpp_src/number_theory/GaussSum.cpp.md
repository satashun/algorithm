---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://mathforum.org/library/drmath/view/73120.html
    - https://min-25.hatenablog.com/entry/2018/04/27/225535
  bundledCode: "#line 1 \"cpp_src/number_theory/GaussSum.cpp\"\n//x_i=floor((a*i+b)/c),\
    \ i=0,1,..n-1\n//a,c>0, b>=0\n//http://mathforum.org/library/drmath/view/73120.html\n\
    //https://min-25.hatenablog.com/entry/2018/04/27/225535\n\nll gauss_sum(ll n,\
    \ ll a, ll b, ll c) {\n\tif (n == 0) return 0;\n\tll res = 0;\n\t{\n\t\tll p =\
    \ a / c;\n\t\tres += n * (n-1) / 2 * p;\n\t\ta %= c;\n\t}\n\t{\n\t\tll p = b /\
    \ c;\n\t\tres += n * p;\n\t\tb %= c;\n\t}\n\tif (a == 0) return res;\n\tll top\
    \ = (a * (n-1) + b) / c;\n\tres += top * n;\n\tll h = 1;\n\tif (h <= top) {\n\t\
    \tres -= gauss_sum(top - h + 1, c, c * h - (b + 1), a) + top - h + 1;\n\t}\n\t\
    return res;\n}\n"
  code: "//x_i=floor((a*i+b)/c), i=0,1,..n-1\n//a,c>0, b>=0\n//http://mathforum.org/library/drmath/view/73120.html\n\
    //https://min-25.hatenablog.com/entry/2018/04/27/225535\n\nll gauss_sum(ll n,\
    \ ll a, ll b, ll c) {\n\tif (n == 0) return 0;\n\tll res = 0;\n\t{\n\t\tll p =\
    \ a / c;\n\t\tres += n * (n-1) / 2 * p;\n\t\ta %= c;\n\t}\n\t{\n\t\tll p = b /\
    \ c;\n\t\tres += n * p;\n\t\tb %= c;\n\t}\n\tif (a == 0) return res;\n\tll top\
    \ = (a * (n-1) + b) / c;\n\tres += top * n;\n\tll h = 1;\n\tif (h <= top) {\n\t\
    \tres -= gauss_sum(top - h + 1, c, c * h - (b + 1), a) + top - h + 1;\n\t}\n\t\
    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/number_theory/GaussSum.cpp
  requiredBy: []
  timestamp: '2022-01-02 16:22:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/number_theory/GaussSum.cpp
layout: document
redirect_from:
- /library/cpp_src/number_theory/GaussSum.cpp
- /library/cpp_src/number_theory/GaussSum.cpp.html
title: cpp_src/number_theory/GaussSum.cpp
---
