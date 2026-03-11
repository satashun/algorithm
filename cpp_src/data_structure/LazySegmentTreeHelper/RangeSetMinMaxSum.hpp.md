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
  bundledCode: "#line 1 \"cpp_src/data_structure/LazySegmentTreeHelper/RangeSetMinMaxSum.hpp\"\
    \n// set val, range min, range max, range sum\n\nstruct Data {\n    ll sum;\n\
    \    int len, mn, mx;\n    Data() {\n        sum = len = 0;\n        mn = INF;\n\
    \        mx = -INF;\n    }\n    Data(ll sum, int len, int mn, int mx)\n      \
    \  : sum(sum), len(len), mn(mn), mx(mx) {};\n};\n\nstruct U {\n    using T1 =\
    \ Data;\n    using T2 = int;\n    static T1 id1() { return Data(); }\n    static\
    \ T2 id2() { return INF; }\n    static T1 op11(const T1& a, const T1& b) {\n \
    \       T1 res;\n        res.len = a.len + b.len;\n        res.sum = a.sum + b.sum;\n\
    \        res.mn = min(a.mn, b.mn);\n        res.mx = max(a.mx, b.mx);\n      \
    \  return res;\n    }\n    static T1 op21(const T2& b, const T1& a) {\n      \
    \  if (b == INF)\n            return a;\n        else {\n            T1 res;\n\
    \            res.len = a.len;\n            res.sum = ll(b) * a.len;\n        \
    \    res.mn = res.mx = b;\n\n            return res;\n        }\n    }\n    //\
    \ a : new!\n    static T2 op22(const T2& a, const T2& b) {\n        if (a == INF)\n\
    \            return b;\n        else\n            return a;\n    }\n};\n"
  code: "// set val, range min, range max, range sum\n\nstruct Data {\n    ll sum;\n\
    \    int len, mn, mx;\n    Data() {\n        sum = len = 0;\n        mn = INF;\n\
    \        mx = -INF;\n    }\n    Data(ll sum, int len, int mn, int mx)\n      \
    \  : sum(sum), len(len), mn(mn), mx(mx) {};\n};\n\nstruct U {\n    using T1 =\
    \ Data;\n    using T2 = int;\n    static T1 id1() { return Data(); }\n    static\
    \ T2 id2() { return INF; }\n    static T1 op11(const T1& a, const T1& b) {\n \
    \       T1 res;\n        res.len = a.len + b.len;\n        res.sum = a.sum + b.sum;\n\
    \        res.mn = min(a.mn, b.mn);\n        res.mx = max(a.mx, b.mx);\n      \
    \  return res;\n    }\n    static T1 op21(const T2& b, const T1& a) {\n      \
    \  if (b == INF)\n            return a;\n        else {\n            T1 res;\n\
    \            res.len = a.len;\n            res.sum = ll(b) * a.len;\n        \
    \    res.mn = res.mx = b;\n\n            return res;\n        }\n    }\n    //\
    \ a : new!\n    static T2 op22(const T2& a, const T2& b) {\n        if (a == INF)\n\
    \            return b;\n        else\n            return a;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/data_structure/LazySegmentTreeHelper/RangeSetMinMaxSum.hpp
  requiredBy: []
  timestamp: '2026-03-12 07:30:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/data_structure/LazySegmentTreeHelper/RangeSetMinMaxSum.hpp
layout: document
redirect_from:
- /library/cpp_src/data_structure/LazySegmentTreeHelper/RangeSetMinMaxSum.hpp
- /library/cpp_src/data_structure/LazySegmentTreeHelper/RangeSetMinMaxSum.hpp.html
title: cpp_src/data_structure/LazySegmentTreeHelper/RangeSetMinMaxSum.hpp
---
