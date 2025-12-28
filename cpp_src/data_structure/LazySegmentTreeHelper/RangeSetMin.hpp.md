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
  bundledCode: "#line 1 \"cpp_src/data_structure/LazySegmentTreeHelper/RangeSetMin.hpp\"\
    \n// T1 : result, T2 : action\n// range set, range minimum\n// ABC382F\n\nconstexpr\
    \ int INF = TEN(9);\n\nstruct U {\n    using T1 = int;\n    using T2 = int;\n\
    \    static T1 id1() { return INF; }\n    static T2 id2() { return INF; }\n  \
    \  static T1 op11(const T1& a, const T1& b) { return min(a, b); }\n    static\
    \ T1 op21(const T2& b, const T1& a) {\n        if (b == INF)\n            return\
    \ a;\n        else\n            return b;\n    }\n    // a : new!\n    static\
    \ T2 op22(const T2& a, const T2& b) {\n        if (a == INF)\n            return\
    \ b;\n        else\n            return a;\n    }\n};\n"
  code: "// T1 : result, T2 : action\n// range set, range minimum\n// ABC382F\n\n\
    constexpr int INF = TEN(9);\n\nstruct U {\n    using T1 = int;\n    using T2 =\
    \ int;\n    static T1 id1() { return INF; }\n    static T2 id2() { return INF;\
    \ }\n    static T1 op11(const T1& a, const T1& b) { return min(a, b); }\n    static\
    \ T1 op21(const T2& b, const T1& a) {\n        if (b == INF)\n            return\
    \ a;\n        else\n            return b;\n    }\n    // a : new!\n    static\
    \ T2 op22(const T2& a, const T2& b) {\n        if (a == INF)\n            return\
    \ b;\n        else\n            return a;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/data_structure/LazySegmentTreeHelper/RangeSetMin.hpp
  requiredBy: []
  timestamp: '2025-12-28 17:44:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/data_structure/LazySegmentTreeHelper/RangeSetMin.hpp
layout: document
redirect_from:
- /library/cpp_src/data_structure/LazySegmentTreeHelper/RangeSetMin.hpp
- /library/cpp_src/data_structure/LazySegmentTreeHelper/RangeSetMin.hpp.html
title: cpp_src/data_structure/LazySegmentTreeHelper/RangeSetMin.hpp
---
