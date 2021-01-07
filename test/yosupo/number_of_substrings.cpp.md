---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"test/yosupo/number_of_substrings.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nusing ll = long long;\nusing pii = pair<int, int>;\ntemplate\
    \ <class T>\nusing V = vector<T>;\ntemplate <class T>\nusing VV = V<V<T>>;\n\n\
    #define pb push_back\n#define eb emplace_back\n#define mp make_pair\n#define fi\
    \ first\n#define se second\n#define rep(i, n) rep2(i, 0, n)\n#define rep2(i, m,\
    \ n) for (int i = m; i < (n); i++)\n#define per(i, b) per2(i, 0, b)\n#define per2(i,\
    \ a, b) for (int i = int(b) - 1; i >= int(a); i--)\n#define ALL(c) (c).begin(),\
    \ (c).end()\n#define SZ(x) ((int)(x).size())\n\nconstexpr ll TEN(int n) { return\
    \ (n == 0) ? 1 : 10 * TEN(n - 1); }\n\ntemplate <class T, class U>\nvoid chmin(T&\
    \ t, const U& u) {\n    if (t > u) t = u;\n}\ntemplate <class T, class U>\nvoid\
    \ chmax(T& t, const U& u) {\n    if (t < u) t = u;\n}\n\ntemplate <class T, class\
    \ U>\nostream& operator<<(ostream& os, const pair<T, U>& p) {\n    os << \"(\"\
    \ << p.first << \",\" << p.second << \")\";\n    return os;\n}\n\ntemplate <class\
    \ T>\nostream& operator<<(ostream& os, const vector<T>& v) {\n    os << \"{\"\
    ;\n    rep(i, v.size()) {\n        if (i) os << \",\";\n        os << v[i];\n\
    \    }\n    os << \"}\";\n    return os;\n}\n\n#ifdef LOCAL\nvoid debug_out()\
    \ { cerr << endl; }\ntemplate <typename Head, typename... Tail>\nvoid debug_out(Head\
    \ H, Tail... T) {\n    cerr << \" \" << H;\n    debug_out(T...);\n}\n#define debug(...)\
    \ \\\n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n\
    #define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n\
    #define debug(...) (void(0))\n#define dump(x) (void(0))\n#endif\n\nnamespace suffix_array\
    \ {\ntemplate <class T>\nvoid induce(int n, const T s[], bool isL[], int sa[],\
    \ int l_head[], int B) {\n    int buf[B + 2];\n    copy_n(l_head, B + 2, buf);\n\
    \n    for (int i = 0; i < n; ++i) {\n        if (sa[i] > 0 && isL[sa[i] - 1])\
    \ {\n            int pos = (int)s[sa[i] - 1];\n            sa[buf[pos]++] = sa[i]\
    \ - 1;\n        }\n    }\n\n    copy_n(l_head, B + 2, buf);\n\n    for (int i\
    \ = n - 1; i >= 0; --i) {\n        if (sa[i] > 0 && !isL[sa[i] - 1]) {\n     \
    \       int pos = (int)s[sa[i] - 1];\n            sa[--buf[pos + 1]] = sa[i] -\
    \ 1;\n        }\n    }\n}\n\n// sentinel must be added to the end of s in advance\n\
    \ntemplate <class T>\nvoid SA_IS(int n, const T s[], int sa[], int B = 200) {\n\
    \    bool isL[n];\n\n    isL[n - 1] = false;\n\n    for (int i = n - 2; i >= 0;\
    \ --i) {\n        isL[i] = (s[i] > s[i + 1] || (s[i] == s[i + 1] && isL[i + 1]));\n\
    \    }\n\n    int l_head[B + 2] = {0};\n\n    for (int i = 0; i < n; ++i) ++l_head[(int)s[i]];\n\
    \n    int sum = 0;\n\n    for (int i = 0; i <= B + 1; ++i) {\n        l_head[i]\
    \ += sum;\n        swap(sum, l_head[i]);\n    }\n\n    vector<int> lms;\n    int\
    \ lms_id[n];\n\n    fill_n(lms_id, n, -1);\n\n    int buf[B + 2];\n    copy_n(l_head,\
    \ B + 2, buf);\n\n    int now = 0;\n\n    fill_n(sa, n, -1);\n\n    for (int i\
    \ = 1; i < n; ++i) {\n        if (isL[i - 1] && !isL[i]) {\n            lms_id[i]\
    \ = now++;\n            lms.push_back(i);\n            sa[--buf[(int)s[i] + 1]]\
    \ = i;\n        }\n    }\n\n    vector<int> lms2 = lms;\n    induce(n, s, isL,\
    \ sa, l_head, B);\n\n    now = 0;\n\n    for (int i = 0; i < n; ++i) {\n     \
    \   if (lms_id[sa[i]] != -1) {\n            lms[now++] = sa[i];\n        }\n \
    \   }\n\n    int s_lms[now], sa_lms[now + 1];\n\n    now = 0;\n    s_lms[lms_id[lms[0]]]\
    \ = 0;\n\n    for (int i = 1; i < lms.size(); ++i) {\n        int u = lms[i -\
    \ 1], v = lms[i];\n\n        bool diff = false;\n\n        for (int j = 0; j <\
    \ n; ++j) {\n            if (s[u + j] != s[v + j] || isL[u + j] != isL[v + j])\
    \ {\n                diff = true;\n                break;\n            }\n\n \
    \           if (j > 0 && (lms_id[u + j] != -1 || lms_id[v + j] != -1)) break;\n\
    \        }\n\n        if (diff) now++;\n        s_lms[lms_id[lms[i]]] = now;\n\
    \    }\n\n    if (now + 1 != lms.size()) {\n        SA_IS(lms.size(), s_lms, sa_lms,\
    \ now);\n    } else {\n        for (int i = 0; i < lms.size(); ++i) {\n      \
    \      sa_lms[s_lms[i]] = i;\n        }\n    }\n\n    for (int i = 0; i < lms.size();\
    \ ++i) {\n        lms[i] = lms2[sa_lms[i]];\n    }\n\n    copy_n(l_head, B + 2,\
    \ buf);\n\n    fill_n(sa, n, -1);\n\n    for (int i = (int)lms.size() - 1; i >=\
    \ 0; --i) {\n        int p = s[lms[i]];\n        sa[--buf[p + 1]] = lms[i];\n\
    \    }\n\n    induce(n, s, isL, sa, l_head, B);\n}\n\ntemplate <class T>\nvoid\
    \ LCP(int n, const T s[], const int sa[], int lcp[]) {\n    int rsa[n + 1];\n\
    \    for (int i = 0; i <= n; i++) {\n        rsa[sa[i]] = i;\n    }\n\n    int\
    \ h = 0;\n    for (int i = 0; i < n; i++) {\n        int j = sa[rsa[i] - 1];\n\
    \n        if (h > 0) h--;\n        for (; j + h < n && i + h < n; h++) {\n   \
    \         if (s[j + h] != s[i + h]) break;\n        }\n        lcp[rsa[i] - 1]\
    \ = h;\n    }\n}\n};  // namespace suffix_array\n\nconst int maxn = 500010;\n\
    char s[maxn];\nint sa[maxn], lcp[maxn];\n\nint main() {\n    scanf(\"%s\", s);\n\
    \    int n = strlen(s);\n    suffix_array::SA_IS(n + 1, s, sa);\n    suffix_array::LCP(n,\
    \ s, sa, lcp);\n    ll ans = n * ll(n + 1) / 2;\n    rep(i, n) ans -= lcp[i];\n\
    \    cout << ans << endl;\n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n\
    using pii = pair<int, int>;\ntemplate <class T>\nusing V = vector<T>;\ntemplate\
    \ <class T>\nusing VV = V<V<T>>;\n\n#define pb push_back\n#define eb emplace_back\n\
    #define mp make_pair\n#define fi first\n#define se second\n#define rep(i, n) rep2(i,\
    \ 0, n)\n#define rep2(i, m, n) for (int i = m; i < (n); i++)\n#define per(i, b)\
    \ per2(i, 0, b)\n#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)\n\
    #define ALL(c) (c).begin(), (c).end()\n#define SZ(x) ((int)(x).size())\n\nconstexpr\
    \ ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }\n\ntemplate <class\
    \ T, class U>\nvoid chmin(T& t, const U& u) {\n    if (t > u) t = u;\n}\ntemplate\
    \ <class T, class U>\nvoid chmax(T& t, const U& u) {\n    if (t < u) t = u;\n\
    }\n\ntemplate <class T, class U>\nostream& operator<<(ostream& os, const pair<T,\
    \ U>& p) {\n    os << \"(\" << p.first << \",\" << p.second << \")\";\n    return\
    \ os;\n}\n\ntemplate <class T>\nostream& operator<<(ostream& os, const vector<T>&\
    \ v) {\n    os << \"{\";\n    rep(i, v.size()) {\n        if (i) os << \",\";\n\
    \        os << v[i];\n    }\n    os << \"}\";\n    return os;\n}\n\n#ifdef LOCAL\n\
    void debug_out() { cerr << endl; }\ntemplate <typename Head, typename... Tail>\n\
    void debug_out(Head H, Tail... T) {\n    cerr << \" \" << H;\n    debug_out(T...);\n\
    }\n#define debug(...) \\\n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"\
    ]:\", debug_out(__VA_ARGS__)\n#define dump(x) cerr << __LINE__ << \" \" << #x\
    \ << \" = \" << (x) << endl\n#else\n#define debug(...) (void(0))\n#define dump(x)\
    \ (void(0))\n#endif\n\nnamespace suffix_array {\ntemplate <class T>\nvoid induce(int\
    \ n, const T s[], bool isL[], int sa[], int l_head[], int B) {\n    int buf[B\
    \ + 2];\n    copy_n(l_head, B + 2, buf);\n\n    for (int i = 0; i < n; ++i) {\n\
    \        if (sa[i] > 0 && isL[sa[i] - 1]) {\n            int pos = (int)s[sa[i]\
    \ - 1];\n            sa[buf[pos]++] = sa[i] - 1;\n        }\n    }\n\n    copy_n(l_head,\
    \ B + 2, buf);\n\n    for (int i = n - 1; i >= 0; --i) {\n        if (sa[i] >\
    \ 0 && !isL[sa[i] - 1]) {\n            int pos = (int)s[sa[i] - 1];\n        \
    \    sa[--buf[pos + 1]] = sa[i] - 1;\n        }\n    }\n}\n\n// sentinel must\
    \ be added to the end of s in advance\n\ntemplate <class T>\nvoid SA_IS(int n,\
    \ const T s[], int sa[], int B = 200) {\n    bool isL[n];\n\n    isL[n - 1] =\
    \ false;\n\n    for (int i = n - 2; i >= 0; --i) {\n        isL[i] = (s[i] > s[i\
    \ + 1] || (s[i] == s[i + 1] && isL[i + 1]));\n    }\n\n    int l_head[B + 2] =\
    \ {0};\n\n    for (int i = 0; i < n; ++i) ++l_head[(int)s[i]];\n\n    int sum\
    \ = 0;\n\n    for (int i = 0; i <= B + 1; ++i) {\n        l_head[i] += sum;\n\
    \        swap(sum, l_head[i]);\n    }\n\n    vector<int> lms;\n    int lms_id[n];\n\
    \n    fill_n(lms_id, n, -1);\n\n    int buf[B + 2];\n    copy_n(l_head, B + 2,\
    \ buf);\n\n    int now = 0;\n\n    fill_n(sa, n, -1);\n\n    for (int i = 1; i\
    \ < n; ++i) {\n        if (isL[i - 1] && !isL[i]) {\n            lms_id[i] = now++;\n\
    \            lms.push_back(i);\n            sa[--buf[(int)s[i] + 1]] = i;\n  \
    \      }\n    }\n\n    vector<int> lms2 = lms;\n    induce(n, s, isL, sa, l_head,\
    \ B);\n\n    now = 0;\n\n    for (int i = 0; i < n; ++i) {\n        if (lms_id[sa[i]]\
    \ != -1) {\n            lms[now++] = sa[i];\n        }\n    }\n\n    int s_lms[now],\
    \ sa_lms[now + 1];\n\n    now = 0;\n    s_lms[lms_id[lms[0]]] = 0;\n\n    for\
    \ (int i = 1; i < lms.size(); ++i) {\n        int u = lms[i - 1], v = lms[i];\n\
    \n        bool diff = false;\n\n        for (int j = 0; j < n; ++j) {\n      \
    \      if (s[u + j] != s[v + j] || isL[u + j] != isL[v + j]) {\n             \
    \   diff = true;\n                break;\n            }\n\n            if (j >\
    \ 0 && (lms_id[u + j] != -1 || lms_id[v + j] != -1)) break;\n        }\n\n   \
    \     if (diff) now++;\n        s_lms[lms_id[lms[i]]] = now;\n    }\n\n    if\
    \ (now + 1 != lms.size()) {\n        SA_IS(lms.size(), s_lms, sa_lms, now);\n\
    \    } else {\n        for (int i = 0; i < lms.size(); ++i) {\n            sa_lms[s_lms[i]]\
    \ = i;\n        }\n    }\n\n    for (int i = 0; i < lms.size(); ++i) {\n     \
    \   lms[i] = lms2[sa_lms[i]];\n    }\n\n    copy_n(l_head, B + 2, buf);\n\n  \
    \  fill_n(sa, n, -1);\n\n    for (int i = (int)lms.size() - 1; i >= 0; --i) {\n\
    \        int p = s[lms[i]];\n        sa[--buf[p + 1]] = lms[i];\n    }\n\n   \
    \ induce(n, s, isL, sa, l_head, B);\n}\n\ntemplate <class T>\nvoid LCP(int n,\
    \ const T s[], const int sa[], int lcp[]) {\n    int rsa[n + 1];\n    for (int\
    \ i = 0; i <= n; i++) {\n        rsa[sa[i]] = i;\n    }\n\n    int h = 0;\n  \
    \  for (int i = 0; i < n; i++) {\n        int j = sa[rsa[i] - 1];\n\n        if\
    \ (h > 0) h--;\n        for (; j + h < n && i + h < n; h++) {\n            if\
    \ (s[j + h] != s[i + h]) break;\n        }\n        lcp[rsa[i] - 1] = h;\n   \
    \ }\n}\n};  // namespace suffix_array\n\nconst int maxn = 500010;\nchar s[maxn];\n\
    int sa[maxn], lcp[maxn];\n\nint main() {\n    scanf(\"%s\", s);\n    int n = strlen(s);\n\
    \    suffix_array::SA_IS(n + 1, s, sa);\n    suffix_array::LCP(n, s, sa, lcp);\n\
    \    ll ans = n * ll(n + 1) / 2;\n    rep(i, n) ans -= lcp[i];\n    cout << ans\
    \ << endl;\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: test/yosupo/number_of_substrings.cpp
  requiredBy: []
  timestamp: '2020-09-11 21:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/yosupo/number_of_substrings.cpp
layout: document
redirect_from:
- /library/test/yosupo/number_of_substrings.cpp
- /library/test/yosupo/number_of_substrings.cpp.html
title: test/yosupo/number_of_substrings.cpp
---
