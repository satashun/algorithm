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
    - https://atcoder.jp/contests/abc332/tasks/abc332_f
  bundledCode: "#line 1 \"cpp_src/data_structure/LazySegmentTreeHelper/RangeMulAdd.hpp\"\
    \n// https://atcoder.jp/contests/abc332/tasks/abc332_f\n// range a*x+b\n\n\nstruct\
    \ U {\n    using T2 = pair<Mint, Mint>;\n    using T1 = Mint;\n    static T2 id2()\
    \ { return mp(Mint(1), Mint(0)); }\n    static T1 id1() { return Mint(0); }\n\
    \    static T1 op11(const T1& a, const T1& b) { return a + b; }\n    static T1\
    \ op21(const T2& b, const T1& a) { return a * b.fi + b.se; }\n    // a : new!\n\
    \    static T2 op22(const T2& a, const T2& b) {\n        return mp(a.fi * b.fi,\
    \ a.fi * b.se + a.se);\n    }\n};\n"
  code: "// https://atcoder.jp/contests/abc332/tasks/abc332_f\n// range a*x+b\n\n\n\
    struct U {\n    using T2 = pair<Mint, Mint>;\n    using T1 = Mint;\n    static\
    \ T2 id2() { return mp(Mint(1), Mint(0)); }\n    static T1 id1() { return Mint(0);\
    \ }\n    static T1 op11(const T1& a, const T1& b) { return a + b; }\n    static\
    \ T1 op21(const T2& b, const T1& a) { return a * b.fi + b.se; }\n    // a : new!\n\
    \    static T2 op22(const T2& a, const T2& b) {\n        return mp(a.fi * b.fi,\
    \ a.fi * b.se + a.se);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/data_structure/LazySegmentTreeHelper/RangeMulAdd.hpp
  requiredBy: []
  timestamp: '2023-12-31 13:48:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/data_structure/LazySegmentTreeHelper/RangeMulAdd.hpp
layout: document
redirect_from:
- /library/cpp_src/data_structure/LazySegmentTreeHelper/RangeMulAdd.hpp
- /library/cpp_src/data_structure/LazySegmentTreeHelper/RangeMulAdd.hpp.html
title: cpp_src/data_structure/LazySegmentTreeHelper/RangeMulAdd.hpp
---
