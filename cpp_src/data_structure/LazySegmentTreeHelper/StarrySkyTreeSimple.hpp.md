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
    - https://atcoder.jp/contests/tenka1-2016-qualb/tasks/tenka1_2016_qualB_d
  bundledCode: "#line 1 \"cpp_src/data_structure/LazySegmentTreeHelper/StarrySkyTreeSimple.hpp\"\
    \n// ex: https://atcoder.jp/contests/tenka1-2016-qualb/tasks/tenka1_2016_qualB_d\n\
    // range addition, range minimum\n// initialization must be cared (set all to\
    \ 0, while id1 = INF)\n\nconstexpr ll INF = TEN(18);\n\nstruct U {\n    using\
    \ T1 = ll;\n    using T2 = ll;\n    static T1 id1() { return INF; }\n    static\
    \ T2 id2() { return 0; }\n    static T1 op11(const T1& a, const T1& b) { return\
    \ min(a, b); }\n    static T1 op21(const T2& b, const T1& a) { return b + a; }\n\
    \    // a : new!\n    static T2 op22(const T2& a, const T2& b) { return a + b;\
    \ }\n};\n"
  code: "// ex: https://atcoder.jp/contests/tenka1-2016-qualb/tasks/tenka1_2016_qualB_d\n\
    // range addition, range minimum\n// initialization must be cared (set all to\
    \ 0, while id1 = INF)\n\nconstexpr ll INF = TEN(18);\n\nstruct U {\n    using\
    \ T1 = ll;\n    using T2 = ll;\n    static T1 id1() { return INF; }\n    static\
    \ T2 id2() { return 0; }\n    static T1 op11(const T1& a, const T1& b) { return\
    \ min(a, b); }\n    static T1 op21(const T2& b, const T1& a) { return b + a; }\n\
    \    // a : new!\n    static T2 op22(const T2& a, const T2& b) { return a + b;\
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/data_structure/LazySegmentTreeHelper/StarrySkyTreeSimple.hpp
  requiredBy: []
  timestamp: '2023-04-22 00:40:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/data_structure/LazySegmentTreeHelper/StarrySkyTreeSimple.hpp
layout: document
redirect_from:
- /library/cpp_src/data_structure/LazySegmentTreeHelper/StarrySkyTreeSimple.hpp
- /library/cpp_src/data_structure/LazySegmentTreeHelper/StarrySkyTreeSimple.hpp.html
title: cpp_src/data_structure/LazySegmentTreeHelper/StarrySkyTreeSimple.hpp
---
