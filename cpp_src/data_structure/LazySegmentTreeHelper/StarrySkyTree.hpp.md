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
  bundledCode: "#line 1 \"cpp_src/data_structure/LazySegmentTreeHelper/StarrySkyTree.hpp\"\
    \n// so called \"starry sky tree\" counting minimum\n// support range addition,\
    \ range minimum, range (count of minimum)\n// GCJ 2022 round 3 problem B\n\nconstexpr\
    \ ll INF = TEN(18);\n\nstruct U {\n    // (minimum, count)\n    using T1 = pair<ll,\
    \ ll>;\n    using T2 = ll;\n\n    static T1 id1() { return mp(INF, 0ll); }\n \
    \   static T2 id2() { return 0; }\n\n    static T1 op11(const T1& a, const T1&\
    \ b) {\n        ll nx_mini = min(a.first, b.first);\n        ll nx_cnt = (a.first\
    \ == nx_mini ? a.second : 0) +\n                    (b.first == nx_mini ? b.second\
    \ : 0);\n        return mp(nx_mini, nx_cnt);\n    }\n\n    static T1 op21(const\
    \ T2& b, const T1& a) {\n        return mp(a.first + b, a.second);\n    }\n  \
    \  // a : new!\n    static T2 op22(const T2& a, const T2& b) { return a + b; }\n\
    };\n"
  code: "// so called \"starry sky tree\" counting minimum\n// support range addition,\
    \ range minimum, range (count of minimum)\n// GCJ 2022 round 3 problem B\n\nconstexpr\
    \ ll INF = TEN(18);\n\nstruct U {\n    // (minimum, count)\n    using T1 = pair<ll,\
    \ ll>;\n    using T2 = ll;\n\n    static T1 id1() { return mp(INF, 0ll); }\n \
    \   static T2 id2() { return 0; }\n\n    static T1 op11(const T1& a, const T1&\
    \ b) {\n        ll nx_mini = min(a.first, b.first);\n        ll nx_cnt = (a.first\
    \ == nx_mini ? a.second : 0) +\n                    (b.first == nx_mini ? b.second\
    \ : 0);\n        return mp(nx_mini, nx_cnt);\n    }\n\n    static T1 op21(const\
    \ T2& b, const T1& a) {\n        return mp(a.first + b, a.second);\n    }\n  \
    \  // a : new!\n    static T2 op22(const T2& a, const T2& b) { return a + b; }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/data_structure/LazySegmentTreeHelper/StarrySkyTree.hpp
  requiredBy: []
  timestamp: '2023-04-22 00:40:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/data_structure/LazySegmentTreeHelper/StarrySkyTree.hpp
layout: document
redirect_from:
- /library/cpp_src/data_structure/LazySegmentTreeHelper/StarrySkyTree.hpp
- /library/cpp_src/data_structure/LazySegmentTreeHelper/StarrySkyTree.hpp.html
title: cpp_src/data_structure/LazySegmentTreeHelper/StarrySkyTree.hpp
---
