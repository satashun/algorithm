---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/string/SAIS.cpp\"\nnamespace suffix_array {\n\t\
    template<class T>\n\tvoid induce(int n, const T s[], bool isL[], int sa[], int\
    \ l_head[], int B)\n\t{\n\t\tint buf[B+2];\n\t\tcopy_n(l_head, B+2, buf);\n\n\t\
    \tfor (int i = 0; i < n; ++i) {\n\t\t\tif (sa[i] > 0 && isL[sa[i]-1]) {\n\t\t\t\
    \tint pos = (int)s[sa[i]-1];\n\t\t\t\tsa[buf[pos]++] = sa[i]-1;\n\t\t\t} \n\t\t\
    }\n\n\t\tcopy_n(l_head, B+2, buf);\n\n\t\tfor (int i = n - 1; i >= 0; --i) {\n\
    \t\t\tif (sa[i] > 0 && !isL[sa[i]-1]) {\n\t\t\t\tint pos = (int)s[sa[i]-1];\n\t\
    \t\t\tsa[--buf[pos+1]] = sa[i]-1;\n\t\t\t}\n\t\t}\t\n\t}\n\n\t//sentinel must\
    \ be added to the end of s in advance\n\n\ttemplate<class T>\n\tvoid SA_IS(int\
    \ n, const T s[], int sa[], int B = 200)\n\t{\n\t\tbool isL[n];\n\n\t\tisL[n -\
    \ 1] = false;\n\n\t\tfor (int i = n - 2; i >= 0; --i) { \n\t\t\tisL[i] = (s[i]\
    \ > s[i+1] || (s[i] == s[i+1] && isL[i+1]));\n\t\t}\n\n\t\tint l_head[B+2] = {0};\n\
    \n\t\tfor (int i = 0; i < n; ++i) ++l_head[(int)s[i]];\n\n\t\tint sum = 0;\n\n\
    \t\tfor (int i = 0; i <= B+1; ++i) {\n\t\t\tl_head[i] += sum;\n\t\t\tswap(sum,\
    \ l_head[i]);\n\t\t}\n\n\t\tvector<int> lms;\n\t\tint lms_id[n];\n\n\t\tfill_n(lms_id,\
    \ n, -1);\n\n\t\tint buf[B+2];\n\t\tcopy_n(l_head, B+2, buf);\t\n\n\t\tint now\
    \ = 0;\n\n\t\tfill_n(sa, n, -1);\n\n\t\tfor (int i = 1; i < n; ++i) {\n\t\t\t\
    if (isL[i-1] && !isL[i]) {\n\t\t\t\tlms_id[i] = now++;\n\t\t\t\tlms.push_back(i);\n\
    \t\t\t\tsa[--buf[(int)s[i]+1]] = i;\n\t\t\t}\n\t\t}\n\n\t\tvector<int> lms2 =\
    \ lms;\n\t\tinduce(n, s, isL, sa, l_head, B);\n\n\t\tnow = 0;\n\t\t\n\t\tfor (int\
    \ i = 0; i < n; ++i) {\n\t\t\tif (lms_id[sa[i]] != -1) {\n\t\t\t\tlms[now++] =\
    \ sa[i];\n\t\t\t}\n\t\t}\n\n\t\tint s_lms[now], sa_lms[now+1];\n\n\t\tnow = 0;\n\
    \t\ts_lms[lms_id[lms[0]]] = 0;\n\t\t\n\t\tfor (int i = 1; i < lms.size(); ++i)\
    \ {\n\t\t\tint u = lms[i-1], v = lms[i];\n\n\t\t\tbool diff = false;\n\n\t\t\t\
    for (int j = 0; j < n; ++j) {\n\t\t\t\tif (s[u+j] != s[v+j] || isL[u+j] != isL[v+j])\
    \ {\n\t\t\t\t\tdiff = true;\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\n\t\t\t\tif (j > 0\
    \ && (lms_id[u+j] != -1 || lms_id[v+j] != -1)) break;\n\t\t\t}\n\t\t\t\n\t\t\t\
    if (diff) now++;\n\t\t\ts_lms[lms_id[lms[i]]] = now;\n\t\t}\n\n\t\tif (now+1 !=\
    \ lms.size()) {\n\t\t\tSA_IS(lms.size(), s_lms, sa_lms, now);\n\t\t} else {\n\t\
    \t\tfor (int i = 0; i < lms.size(); ++i) {\n\t\t\t\tsa_lms[s_lms[i]] = i;\n\t\t\
    \t}\n\t\t}\n\n\t\tfor (int i = 0; i < lms.size(); ++i) {\n\t\t\tlms[i] = lms2[sa_lms[i]];\n\
    \t\t}\n\n\t\tcopy_n(l_head, B+2, buf);\n\n\t\tfill_n(sa, n, -1);\n\n\t\tfor (int\
    \ i = (int)lms.size()-1; i >= 0; --i) {\n\t\t\tint p = s[lms[i]];\n\t\t\tsa[--buf[p+1]]\
    \ = lms[i];\n\t\t}\n\n\t\tinduce(n, s, isL, sa, l_head, B);\n\t}\n\n\ttemplate\
    \ <class T>\n\tvoid LCP(int n, const T s[], const int sa[], int lcp[]) {\n\t\t\
    int rsa[n+1];\n\t\tfor (int i = 0; i <= n; i++) {\n\t\t\trsa[sa[i]] = i;\n\t\t\
    }\n\n\t\tint h = 0;\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tint j = sa[rsa[i]-1];\n\
    \n\t\t\tif (h > 0) h--;\n\t\t\tfor (; j+h < n && i+h < n; h++) {\n\t\t\t\tif (s[j+h]\
    \ != s[i+h]) break;\n\t\t\t}\n\t\t\tlcp[rsa[i]-1] = h;\n\t\t}\n\t}\n};\n\n/*\n\
    char c[100010];\n\nint main() {\t\n\tscanf(\"%s\", c);\n\tint n = strlen(c);\n\
    \tint sa[n+1];\n\tint lcp[n];\n\n\tsuffix_array::SA_IS(n + 1, c, sa);\n\tsuffix_array::LCP(n,\
    \ c, sa, lcp);\n\n\tll ans = 0;\n\n\tfor (int i = 1; i <= n; i++) {\n\t\tll m\
    \ = n-sa[i], k = lcp[i-1];\n\t\tans += (k+1+m) * (m-k) / 2;\n\t}\n\n\tcout <<\
    \ ans << endl;\n\treturn 0;\n}*/\n"
  code: "namespace suffix_array {\n\ttemplate<class T>\n\tvoid induce(int n, const\
    \ T s[], bool isL[], int sa[], int l_head[], int B)\n\t{\n\t\tint buf[B+2];\n\t\
    \tcopy_n(l_head, B+2, buf);\n\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tif (sa[i]\
    \ > 0 && isL[sa[i]-1]) {\n\t\t\t\tint pos = (int)s[sa[i]-1];\n\t\t\t\tsa[buf[pos]++]\
    \ = sa[i]-1;\n\t\t\t} \n\t\t}\n\n\t\tcopy_n(l_head, B+2, buf);\n\n\t\tfor (int\
    \ i = n - 1; i >= 0; --i) {\n\t\t\tif (sa[i] > 0 && !isL[sa[i]-1]) {\n\t\t\t\t\
    int pos = (int)s[sa[i]-1];\n\t\t\t\tsa[--buf[pos+1]] = sa[i]-1;\n\t\t\t}\n\t\t\
    }\t\n\t}\n\n\t//sentinel must be added to the end of s in advance\n\n\ttemplate<class\
    \ T>\n\tvoid SA_IS(int n, const T s[], int sa[], int B = 200)\n\t{\n\t\tbool isL[n];\n\
    \n\t\tisL[n - 1] = false;\n\n\t\tfor (int i = n - 2; i >= 0; --i) { \n\t\t\tisL[i]\
    \ = (s[i] > s[i+1] || (s[i] == s[i+1] && isL[i+1]));\n\t\t}\n\n\t\tint l_head[B+2]\
    \ = {0};\n\n\t\tfor (int i = 0; i < n; ++i) ++l_head[(int)s[i]];\n\n\t\tint sum\
    \ = 0;\n\n\t\tfor (int i = 0; i <= B+1; ++i) {\n\t\t\tl_head[i] += sum;\n\t\t\t\
    swap(sum, l_head[i]);\n\t\t}\n\n\t\tvector<int> lms;\n\t\tint lms_id[n];\n\n\t\
    \tfill_n(lms_id, n, -1);\n\n\t\tint buf[B+2];\n\t\tcopy_n(l_head, B+2, buf);\t\
    \n\n\t\tint now = 0;\n\n\t\tfill_n(sa, n, -1);\n\n\t\tfor (int i = 1; i < n; ++i)\
    \ {\n\t\t\tif (isL[i-1] && !isL[i]) {\n\t\t\t\tlms_id[i] = now++;\n\t\t\t\tlms.push_back(i);\n\
    \t\t\t\tsa[--buf[(int)s[i]+1]] = i;\n\t\t\t}\n\t\t}\n\n\t\tvector<int> lms2 =\
    \ lms;\n\t\tinduce(n, s, isL, sa, l_head, B);\n\n\t\tnow = 0;\n\t\t\n\t\tfor (int\
    \ i = 0; i < n; ++i) {\n\t\t\tif (lms_id[sa[i]] != -1) {\n\t\t\t\tlms[now++] =\
    \ sa[i];\n\t\t\t}\n\t\t}\n\n\t\tint s_lms[now], sa_lms[now+1];\n\n\t\tnow = 0;\n\
    \t\ts_lms[lms_id[lms[0]]] = 0;\n\t\t\n\t\tfor (int i = 1; i < lms.size(); ++i)\
    \ {\n\t\t\tint u = lms[i-1], v = lms[i];\n\n\t\t\tbool diff = false;\n\n\t\t\t\
    for (int j = 0; j < n; ++j) {\n\t\t\t\tif (s[u+j] != s[v+j] || isL[u+j] != isL[v+j])\
    \ {\n\t\t\t\t\tdiff = true;\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\n\t\t\t\tif (j > 0\
    \ && (lms_id[u+j] != -1 || lms_id[v+j] != -1)) break;\n\t\t\t}\n\t\t\t\n\t\t\t\
    if (diff) now++;\n\t\t\ts_lms[lms_id[lms[i]]] = now;\n\t\t}\n\n\t\tif (now+1 !=\
    \ lms.size()) {\n\t\t\tSA_IS(lms.size(), s_lms, sa_lms, now);\n\t\t} else {\n\t\
    \t\tfor (int i = 0; i < lms.size(); ++i) {\n\t\t\t\tsa_lms[s_lms[i]] = i;\n\t\t\
    \t}\n\t\t}\n\n\t\tfor (int i = 0; i < lms.size(); ++i) {\n\t\t\tlms[i] = lms2[sa_lms[i]];\n\
    \t\t}\n\n\t\tcopy_n(l_head, B+2, buf);\n\n\t\tfill_n(sa, n, -1);\n\n\t\tfor (int\
    \ i = (int)lms.size()-1; i >= 0; --i) {\n\t\t\tint p = s[lms[i]];\n\t\t\tsa[--buf[p+1]]\
    \ = lms[i];\n\t\t}\n\n\t\tinduce(n, s, isL, sa, l_head, B);\n\t}\n\n\ttemplate\
    \ <class T>\n\tvoid LCP(int n, const T s[], const int sa[], int lcp[]) {\n\t\t\
    int rsa[n+1];\n\t\tfor (int i = 0; i <= n; i++) {\n\t\t\trsa[sa[i]] = i;\n\t\t\
    }\n\n\t\tint h = 0;\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tint j = sa[rsa[i]-1];\n\
    \n\t\t\tif (h > 0) h--;\n\t\t\tfor (; j+h < n && i+h < n; h++) {\n\t\t\t\tif (s[j+h]\
    \ != s[i+h]) break;\n\t\t\t}\n\t\t\tlcp[rsa[i]-1] = h;\n\t\t}\n\t}\n};\n\n/*\n\
    char c[100010];\n\nint main() {\t\n\tscanf(\"%s\", c);\n\tint n = strlen(c);\n\
    \tint sa[n+1];\n\tint lcp[n];\n\n\tsuffix_array::SA_IS(n + 1, c, sa);\n\tsuffix_array::LCP(n,\
    \ c, sa, lcp);\n\n\tll ans = 0;\n\n\tfor (int i = 1; i <= n; i++) {\n\t\tll m\
    \ = n-sa[i], k = lcp[i-1];\n\t\tans += (k+1+m) * (m-k) / 2;\n\t}\n\n\tcout <<\
    \ ans << endl;\n\treturn 0;\n}*/"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/string/SAIS.cpp
  requiredBy: []
  timestamp: '2022-07-17 01:58:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/string/SAIS.cpp
layout: document
redirect_from:
- /library/cpp_src/string/SAIS.cpp
- /library/cpp_src/string/SAIS.cpp.html
title: cpp_src/string/SAIS.cpp
---
