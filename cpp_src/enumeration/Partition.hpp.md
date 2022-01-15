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
  bundledCode: "#line 1 \"cpp_src/enumeration/Partition.hpp\"\nvoid enum_partition(int\
    \ rem, int la, V<int>& cur, VV<int>& all) {\n    if (rem == 0) {\n        all.pb(cur);\n\
    \        return;\n    }\n    for (int j = la; j <= rem; ++j) {\n        cur.push_back(j);\n\
    \        enum_partition(rem - j, j, cur, all);\n        cur.pop_back();\n    }\n\
    }\n\n// ABC226F\n// N=50 : 204226\nVV<int> enum_partition_exec(int N) {\n    VV<int>\
    \ vec;\n    {\n        V<int> cur;\n        enum_partition(N, 1, cur, vec);\n\
    \    }\n    return vec;\n}\n"
  code: "void enum_partition(int rem, int la, V<int>& cur, VV<int>& all) {\n    if\
    \ (rem == 0) {\n        all.pb(cur);\n        return;\n    }\n    for (int j =\
    \ la; j <= rem; ++j) {\n        cur.push_back(j);\n        enum_partition(rem\
    \ - j, j, cur, all);\n        cur.pop_back();\n    }\n}\n\n// ABC226F\n// N=50\
    \ : 204226\nVV<int> enum_partition_exec(int N) {\n    VV<int> vec;\n    {\n  \
    \      V<int> cur;\n        enum_partition(N, 1, cur, vec);\n    }\n    return\
    \ vec;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/enumeration/Partition.hpp
  requiredBy: []
  timestamp: '2022-01-15 23:16:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/enumeration/Partition.hpp
layout: document
redirect_from:
- /library/cpp_src/enumeration/Partition.hpp
- /library/cpp_src/enumeration/Partition.hpp.html
title: cpp_src/enumeration/Partition.hpp
---
