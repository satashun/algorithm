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
    - https://atcoder.jp/contests/abc265/submissions/42179632
  bundledCode: "#line 1 \"cpp_src/data_structure/LazySegmentTreeHelper/012Inversion.hpp\"\
    \n// ABC265G\n// submission : https://atcoder.jp/contests/abc265/submissions/42179632\n\
    \nstruct U {\n    using T1 = array<array<ll, 3>, 3>;\n    using T2 = array<ll,\
    \ 3>;\n\n    static T1 id1() {\n        T1 res;\n        rep(i, 3) rep(j, 3) res[i][j]\
    \ = 0;\n        return res;\n    }\n    static T2 id2() {\n        T2 res;\n \
    \       rep(i, 3) res[i] = i;\n        return res;\n    }\n    static T1 op11(const\
    \ T1& a, const T1& b) {\n        T1 res = id1();\n        rep(i, 3) {\n      \
    \      rep(j, 3) {\n                res[i][j] += a[i][j] + b[i][j];\n        \
    \        if (i != j) {\n                    res[i][j] += a[i][i] * b[j][j];\n\
    \                }\n            }\n        }\n\n        return res;\n    }\n\n\
    \    static T1 op21(const T2& b, const T1& a) {\n        T1 res = id1();\n   \
    \     rep(i, 3) {\n            rep(j, 3) {\n                if (i == j || b[i]\
    \ != b[j]) {\n                    res[b[i]][b[j]] += a[i][j];\n              \
    \  }\n            }\n        }\n        return res;\n    }\n\n    // order : b\
    \ -> a\n    static T2 op22(const T2& a, const T2& b) {\n        T2 res;\n    \
    \    rep(i, 3) res[i] = a[b[i]];\n        return res;\n    }\n};\n"
  code: "// ABC265G\n// submission : https://atcoder.jp/contests/abc265/submissions/42179632\n\
    \nstruct U {\n    using T1 = array<array<ll, 3>, 3>;\n    using T2 = array<ll,\
    \ 3>;\n\n    static T1 id1() {\n        T1 res;\n        rep(i, 3) rep(j, 3) res[i][j]\
    \ = 0;\n        return res;\n    }\n    static T2 id2() {\n        T2 res;\n \
    \       rep(i, 3) res[i] = i;\n        return res;\n    }\n    static T1 op11(const\
    \ T1& a, const T1& b) {\n        T1 res = id1();\n        rep(i, 3) {\n      \
    \      rep(j, 3) {\n                res[i][j] += a[i][j] + b[i][j];\n        \
    \        if (i != j) {\n                    res[i][j] += a[i][i] * b[j][j];\n\
    \                }\n            }\n        }\n\n        return res;\n    }\n\n\
    \    static T1 op21(const T2& b, const T1& a) {\n        T1 res = id1();\n   \
    \     rep(i, 3) {\n            rep(j, 3) {\n                if (i == j || b[i]\
    \ != b[j]) {\n                    res[b[i]][b[j]] += a[i][j];\n              \
    \  }\n            }\n        }\n        return res;\n    }\n\n    // order : b\
    \ -> a\n    static T2 op22(const T2& a, const T2& b) {\n        T2 res;\n    \
    \    rep(i, 3) res[i] = a[b[i]];\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/data_structure/LazySegmentTreeHelper/012Inversion.hpp
  requiredBy: []
  timestamp: '2023-07-23 15:21:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/data_structure/LazySegmentTreeHelper/012Inversion.hpp
layout: document
redirect_from:
- /library/cpp_src/data_structure/LazySegmentTreeHelper/012Inversion.hpp
- /library/cpp_src/data_structure/LazySegmentTreeHelper/012Inversion.hpp.html
title: cpp_src/data_structure/LazySegmentTreeHelper/012Inversion.hpp
---
