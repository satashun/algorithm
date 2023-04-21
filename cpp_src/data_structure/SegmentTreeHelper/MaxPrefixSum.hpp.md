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
  bundledCode: "#line 1 \"cpp_src/data_structure/SegmentTreeHelper/MaxPrefixSum.hpp\"\
    \n// ABC292H\nconstexpr ll INF = TEN(18);\n\n// maximum prefix sum\nstruct Data\
    \ {\n    ll sum, maxi;\n    Data() { sum = maxi = 0; }\n    Data(ll sum, ll maxi)\
    \ : sum(sum), maxi(maxi) {}\n};\n\n// modify only U\nstruct U {\n    using T =\
    \ Data;\n    static T id() { return Data(0ll, -INF); }\n    static T op(const\
    \ T& a, const T& b) {\n        Data res;\n        res.sum = a.sum + b.sum;\n \
    \       res.maxi = max(a.maxi, a.sum + b.maxi);\n        return res;\n    }\n\
    };\n"
  code: "// ABC292H\nconstexpr ll INF = TEN(18);\n\n// maximum prefix sum\nstruct\
    \ Data {\n    ll sum, maxi;\n    Data() { sum = maxi = 0; }\n    Data(ll sum,\
    \ ll maxi) : sum(sum), maxi(maxi) {}\n};\n\n// modify only U\nstruct U {\n   \
    \ using T = Data;\n    static T id() { return Data(0ll, -INF); }\n    static T\
    \ op(const T& a, const T& b) {\n        Data res;\n        res.sum = a.sum + b.sum;\n\
    \        res.maxi = max(a.maxi, a.sum + b.maxi);\n        return res;\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/data_structure/SegmentTreeHelper/MaxPrefixSum.hpp
  requiredBy: []
  timestamp: '2023-04-22 00:40:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/data_structure/SegmentTreeHelper/MaxPrefixSum.hpp
layout: document
redirect_from:
- /library/cpp_src/data_structure/SegmentTreeHelper/MaxPrefixSum.hpp
- /library/cpp_src/data_structure/SegmentTreeHelper/MaxPrefixSum.hpp.html
title: cpp_src/data_structure/SegmentTreeHelper/MaxPrefixSum.hpp
---
