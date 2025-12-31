---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/arc151/submissions/71591899
  bundledCode: "#line 1 \"cpp_src/string/SAIS copy.cpp\"\n// vector version\n// ARC151E:\
    \ https://atcoder.jp/contests/arc151/submissions/71591899\n\nnamespace suffix_array\
    \ {\ntemplate <class T>\nvoid induce(int n, V<T>& s, V<int> isL, V<int>& sa, V<int>\
    \ l_head, int B) {\n    V<int> buf = l_head;\n\n    for (int i = 0; i < n; ++i)\
    \ {\n        if (sa[i] > 0 && isL[sa[i] - 1]) {\n            int pos = (int)s[sa[i]\
    \ - 1];\n            sa[buf[pos]++] = sa[i] - 1;\n        }\n    }\n\n    buf\
    \ = l_head;\n    for (int i = n - 1; i >= 0; --i) {\n        if (sa[i] > 0 &&\
    \ !isL[sa[i] - 1]) {\n            int pos = (int)s[sa[i] - 1];\n            sa[--buf[pos\
    \ + 1]] = sa[i] - 1;\n        }\n    }\n}\n\n// sentinel must be added to the\
    \ end of s in advance\n\ntemplate <class T>\nvoid SA_IS(int n, V<T>& s, V<int>&\
    \ sa, int B = 200) {\n    V<int> isL(n);\n    isL[n - 1] = false;\n\n    for (int\
    \ i = n - 2; i >= 0; --i) {\n        isL[i] = (s[i] > s[i + 1] || (s[i] == s[i\
    \ + 1] && isL[i + 1]));\n    }\n\n    V<int> l_head(B + 2);\n    for (int i =\
    \ 0; i < n; ++i) ++l_head[(int)s[i]];\n\n    int sum = 0;\n\n    for (int i =\
    \ 0; i <= B + 1; ++i) {\n        l_head[i] += sum;\n        swap(sum, l_head[i]);\n\
    \    }\n\n    V<int> lms;\n    V<int> lms_id(n, -1);\n\n    V<int> buf = l_head;\n\
    \    int now = 0;\n    rep(i, n) sa[i] = -1;\n\n    for (int i = 1; i < n; ++i)\
    \ {\n        if (isL[i - 1] && !isL[i]) {\n            lms_id[i] = now++;\n  \
    \          lms.push_back(i);\n            sa[--buf[(int)s[i] + 1]] = i;\n    \
    \    }\n    }\n\n    V<int> lms2 = lms;\n    induce(n, s, isL, sa, l_head, B);\n\
    \n    now = 0;\n\n    for (int i = 0; i < n; ++i) {\n        if (lms_id[sa[i]]\
    \ != -1) {\n            lms[now++] = sa[i];\n        }\n    }\n\n    V<int> s_lms(now),\
    \ sa_lms(now + 1);\n\n    now = 0;\n    s_lms[lms_id[lms[0]]] = 0;\n\n    for\
    \ (int i = 1; i < lms.size(); ++i) {\n        int u = lms[i - 1], v = lms[i];\n\
    \n        bool diff = false;\n\n        for (int j = 0; j < n; ++j) {\n      \
    \      if (s[u + j] != s[v + j] || isL[u + j] != isL[v + j]) {\n             \
    \   diff = true;\n                break;\n            }\n\n            if (j >\
    \ 0 && (lms_id[u + j] != -1 || lms_id[v + j] != -1)) break;\n        }\n\n   \
    \     if (diff) now++;\n        s_lms[lms_id[lms[i]]] = now;\n    }\n\n    if\
    \ (now + 1 != lms.size()) {\n        SA_IS(lms.size(), s_lms, sa_lms, now);\n\
    \    } else {\n        for (int i = 0; i < lms.size(); ++i) {\n            sa_lms[s_lms[i]]\
    \ = i;\n        }\n    }\n\n    for (int i = 0; i < lms.size(); ++i) {\n     \
    \   lms[i] = lms2[sa_lms[i]];\n    }\n\n    buf = l_head;\n    rep(i, n) sa[i]\
    \ = -1;\n\n    for (int i = (int)lms.size() - 1; i >= 0; --i) {\n        int p\
    \ = s[lms[i]];\n        sa[--buf[p + 1]] = lms[i];\n    }\n\n    induce(n, s,\
    \ isL, sa, l_head, B);\n}\n\ntemplate <class T>\nvoid LCP(int n, V<T> s, V<int>\
    \ sa, V<int>& lcp) {\n    V<int> rsa(n + 1);\n    for (int i = 0; i <= n; i++)\
    \ {\n        rsa[sa[i]] = i;\n    }\n\n    int h = 0;\n    for (int i = 0; i <\
    \ n; i++) {\n        int j = sa[rsa[i] - 1];\n\n        if (h > 0) h--;\n    \
    \    for (; j + h < n && i + h < n; h++) {\n            if (s[j + h] != s[i +\
    \ h]) break;\n        }\n        lcp[rsa[i] - 1] = h;\n    }\n}\n};  // namespace\
    \ suffix_array\n"
  code: "// vector version\n// ARC151E: https://atcoder.jp/contests/arc151/submissions/71591899\n\
    \nnamespace suffix_array {\ntemplate <class T>\nvoid induce(int n, V<T>& s, V<int>\
    \ isL, V<int>& sa, V<int> l_head, int B) {\n    V<int> buf = l_head;\n\n    for\
    \ (int i = 0; i < n; ++i) {\n        if (sa[i] > 0 && isL[sa[i] - 1]) {\n    \
    \        int pos = (int)s[sa[i] - 1];\n            sa[buf[pos]++] = sa[i] - 1;\n\
    \        }\n    }\n\n    buf = l_head;\n    for (int i = n - 1; i >= 0; --i) {\n\
    \        if (sa[i] > 0 && !isL[sa[i] - 1]) {\n            int pos = (int)s[sa[i]\
    \ - 1];\n            sa[--buf[pos + 1]] = sa[i] - 1;\n        }\n    }\n}\n\n\
    // sentinel must be added to the end of s in advance\n\ntemplate <class T>\nvoid\
    \ SA_IS(int n, V<T>& s, V<int>& sa, int B = 200) {\n    V<int> isL(n);\n    isL[n\
    \ - 1] = false;\n\n    for (int i = n - 2; i >= 0; --i) {\n        isL[i] = (s[i]\
    \ > s[i + 1] || (s[i] == s[i + 1] && isL[i + 1]));\n    }\n\n    V<int> l_head(B\
    \ + 2);\n    for (int i = 0; i < n; ++i) ++l_head[(int)s[i]];\n\n    int sum =\
    \ 0;\n\n    for (int i = 0; i <= B + 1; ++i) {\n        l_head[i] += sum;\n  \
    \      swap(sum, l_head[i]);\n    }\n\n    V<int> lms;\n    V<int> lms_id(n, -1);\n\
    \n    V<int> buf = l_head;\n    int now = 0;\n    rep(i, n) sa[i] = -1;\n\n  \
    \  for (int i = 1; i < n; ++i) {\n        if (isL[i - 1] && !isL[i]) {\n     \
    \       lms_id[i] = now++;\n            lms.push_back(i);\n            sa[--buf[(int)s[i]\
    \ + 1]] = i;\n        }\n    }\n\n    V<int> lms2 = lms;\n    induce(n, s, isL,\
    \ sa, l_head, B);\n\n    now = 0;\n\n    for (int i = 0; i < n; ++i) {\n     \
    \   if (lms_id[sa[i]] != -1) {\n            lms[now++] = sa[i];\n        }\n \
    \   }\n\n    V<int> s_lms(now), sa_lms(now + 1);\n\n    now = 0;\n    s_lms[lms_id[lms[0]]]\
    \ = 0;\n\n    for (int i = 1; i < lms.size(); ++i) {\n        int u = lms[i -\
    \ 1], v = lms[i];\n\n        bool diff = false;\n\n        for (int j = 0; j <\
    \ n; ++j) {\n            if (s[u + j] != s[v + j] || isL[u + j] != isL[v + j])\
    \ {\n                diff = true;\n                break;\n            }\n\n \
    \           if (j > 0 && (lms_id[u + j] != -1 || lms_id[v + j] != -1)) break;\n\
    \        }\n\n        if (diff) now++;\n        s_lms[lms_id[lms[i]]] = now;\n\
    \    }\n\n    if (now + 1 != lms.size()) {\n        SA_IS(lms.size(), s_lms, sa_lms,\
    \ now);\n    } else {\n        for (int i = 0; i < lms.size(); ++i) {\n      \
    \      sa_lms[s_lms[i]] = i;\n        }\n    }\n\n    for (int i = 0; i < lms.size();\
    \ ++i) {\n        lms[i] = lms2[sa_lms[i]];\n    }\n\n    buf = l_head;\n    rep(i,\
    \ n) sa[i] = -1;\n\n    for (int i = (int)lms.size() - 1; i >= 0; --i) {\n   \
    \     int p = s[lms[i]];\n        sa[--buf[p + 1]] = lms[i];\n    }\n\n    induce(n,\
    \ s, isL, sa, l_head, B);\n}\n\ntemplate <class T>\nvoid LCP(int n, V<T> s, V<int>\
    \ sa, V<int>& lcp) {\n    V<int> rsa(n + 1);\n    for (int i = 0; i <= n; i++)\
    \ {\n        rsa[sa[i]] = i;\n    }\n\n    int h = 0;\n    for (int i = 0; i <\
    \ n; i++) {\n        int j = sa[rsa[i] - 1];\n\n        if (h > 0) h--;\n    \
    \    for (; j + h < n && i + h < n; h++) {\n            if (s[j + h] != s[i +\
    \ h]) break;\n        }\n        lcp[rsa[i] - 1] = h;\n    }\n}\n};  // namespace\
    \ suffix_array"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/string/SAIS copy.cpp
  requiredBy: []
  timestamp: '2026-01-01 00:55:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/string/SAIS copy.cpp
layout: document
redirect_from:
- /library/cpp_src/string/SAIS copy.cpp
- /library/cpp_src/string/SAIS copy.cpp.html
title: cpp_src/string/SAIS copy.cpp
---
