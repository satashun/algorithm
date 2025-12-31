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
  bundledCode: "#line 1 \"cpp_src/data_structure/LazySegmentTreeHelper/RangeChminMin.hpp\"\
    \n// T1 : result, T2 : action\n// range chmin, range minimum\n// ABC382F\n\nconstexpr\
    \ int INF = TEN(9);\n\nstruct U {\n    using T1 = int;\n    using T2 = int;\n\
    \    static T1 id1() { return INF; }\n    static T2 id2() { return INF; }\n  \
    \  static T1 op11(const T1& a, const T1& b) { return min(a, b); }\n    static\
    \ T1 op21(const T2& b, const T1& a) { return min(a, b); }\n    // a : new!\n \
    \   static T2 op22(const T2& a, const T2& b) { return min(a, b); }\n};\n"
  code: "// T1 : result, T2 : action\n// range chmin, range minimum\n// ABC382F\n\n\
    constexpr int INF = TEN(9);\n\nstruct U {\n    using T1 = int;\n    using T2 =\
    \ int;\n    static T1 id1() { return INF; }\n    static T2 id2() { return INF;\
    \ }\n    static T1 op11(const T1& a, const T1& b) { return min(a, b); }\n    static\
    \ T1 op21(const T2& b, const T1& a) { return min(a, b); }\n    // a : new!\n \
    \   static T2 op22(const T2& a, const T2& b) { return min(a, b); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/data_structure/LazySegmentTreeHelper/RangeChminMin.hpp
  requiredBy: []
  timestamp: '2026-01-01 00:55:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/data_structure/LazySegmentTreeHelper/RangeChminMin.hpp
layout: document
redirect_from:
- /library/cpp_src/data_structure/LazySegmentTreeHelper/RangeChminMin.hpp
- /library/cpp_src/data_structure/LazySegmentTreeHelper/RangeChminMin.hpp.html
title: cpp_src/data_structure/LazySegmentTreeHelper/RangeChminMin.hpp
---
