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
  bundledCode: "#line 1 \"cpp_src/other/CountSubsequence.hpp\"\n// ABC239F\n// count\
    \ distinct subsequences\ntemplate <class T>\nMint count_subsequence(const V<T>&\
    \ vec) {\n    map<T, int> la;\n    int n = SZ(vec);\n    V<Mint> dp(n), ps(n +\
    \ 1);\n\n    rep(i, n) {\n        int l = -1;\n        if (la.count(vec[i])) {\n\
    \            l = la[vec[i]];\n        }\n\n        if (l == -1) {\n          \
    \  dp[i]++;\n            l = 0;\n        }\n\n        dp[i] += ps[i] - ps[l];\n\
    \        ps[i + 1] = ps[i] + dp[i];\n        la[vec[i]] = i;\n    }\n\n    Mint\
    \ ans = accumulate(ALL(dp), Mint(0)) + 1;\n    return ans;\n}\n"
  code: "// ABC239F\n// count distinct subsequences\ntemplate <class T>\nMint count_subsequence(const\
    \ V<T>& vec) {\n    map<T, int> la;\n    int n = SZ(vec);\n    V<Mint> dp(n),\
    \ ps(n + 1);\n\n    rep(i, n) {\n        int l = -1;\n        if (la.count(vec[i]))\
    \ {\n            l = la[vec[i]];\n        }\n\n        if (l == -1) {\n      \
    \      dp[i]++;\n            l = 0;\n        }\n\n        dp[i] += ps[i] - ps[l];\n\
    \        ps[i + 1] = ps[i] + dp[i];\n        la[vec[i]] = i;\n    }\n\n    Mint\
    \ ans = accumulate(ALL(dp), Mint(0)) + 1;\n    return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/other/CountSubsequence.hpp
  requiredBy: []
  timestamp: '2022-01-02 16:22:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/other/CountSubsequence.hpp
layout: document
redirect_from:
- /library/cpp_src/other/CountSubsequence.hpp
- /library/cpp_src/other/CountSubsequence.hpp.html
title: cpp_src/other/CountSubsequence.hpp
---
