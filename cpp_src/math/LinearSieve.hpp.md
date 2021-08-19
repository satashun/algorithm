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
    - https://cp-algorithms.com/algebra/prime-sieve-linear.html
  bundledCode: "#line 1 \"cpp_src/math/LinearSieve.hpp\"\n//https://cp-algorithms.com/algebra/prime-sieve-linear.html\n\
    \nconst int maxv = 10000010;\n// lowest prime factor\nint lp[maxv];\nbool pri[maxv];\n\
    vector<int> pr;\n\nvoid linear_sieve() {\n    for (int i = 2; i < maxv; ++i) pri[i]\
    \ = true;\n    for (int i = 2; i < maxv; ++i) {\n        if (pri[i]) {\n     \
    \       lp[i] = i;\n            pr.pb(i);\n        }\n        for (int j = 0;\n\
    \             j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < maxv; ++j) {\n\
    \            pri[i * pr[j]] = false;\n            lp[i * pr[j]] = pr[j];\n   \
    \         if (i % pr[j] == 0) break;\n        }\n    }\n}\n"
  code: "//https://cp-algorithms.com/algebra/prime-sieve-linear.html\n\nconst int\
    \ maxv = 10000010;\n// lowest prime factor\nint lp[maxv];\nbool pri[maxv];\nvector<int>\
    \ pr;\n\nvoid linear_sieve() {\n    for (int i = 2; i < maxv; ++i) pri[i] = true;\n\
    \    for (int i = 2; i < maxv; ++i) {\n        if (pri[i]) {\n            lp[i]\
    \ = i;\n            pr.pb(i);\n        }\n        for (int j = 0;\n          \
    \   j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < maxv; ++j) {\n       \
    \     pri[i * pr[j]] = false;\n            lp[i * pr[j]] = pr[j];\n          \
    \  if (i % pr[j] == 0) break;\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/math/LinearSieve.hpp
  requiredBy: []
  timestamp: '2021-08-18 21:00:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/math/LinearSieve.hpp
layout: document
redirect_from:
- /library/cpp_src/math/LinearSieve.hpp
- /library/cpp_src/math/LinearSieve.hpp.html
title: cpp_src/math/LinearSieve.hpp
---
