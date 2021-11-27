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
    - http://qnighy.hatenablog.com/entry/20100117/1263734784
    - http://stackoverflow.com/questions/13792118/kmp-prefix-table
    - http://tokyo-ct.net/usr/kosaka/for_students/jissen1/akiyojissen1/kougi16.html
  bundledCode: "#line 1 \"cpp_src/string/kmp.cpp\"\n// http://qnighy.hatenablog.com/entry/20100117/1263734784\n\
    // http://stackoverflow.com/questions/13792118/kmp-prefix-table\n// http://tokyo-ct.net/usr/kosaka/for_students/jissen1/akiyojissen1/kougi16.html\n\
    \nvector<int> pre_kmp(string pat) {\n\tint k;\n\tvector<int> table((int)pat.size()\
    \ + 1);\n\ttable[0] = -1;\n\n\tfor (int i = 1; i <= pat.size(); ++i) {\n\t\tk\
    \ = table[i-1];\n\n\t\twhile (k >= 0) {\n\t\t\tif (pat[k] == pat[i-1]) break;\n\
    \t\t\telse k = table[k];\n\t\t}\n\n\t\ttable[i] = k + 1;\n\t}\n\n\treturn table;\n\
    }\n\nint match(string t, string p, vector<int> fail) {\n\tint n = t.size(), m\
    \ = p.size();\n\tint count = 0;\n\n\tfor (int i = 0, k = 0; i < n; ++i) {\n\t\t\
    while (k >= 0 && p[k] != t[i]) {\n\t\t\tk = fail[k];\n\t\t}\n\t\tif (++k >= m)\
    \ {\n\t\t\t++count; // match at t[i-m+1 .. i]\n\t\t\tk = fail[k];\n\t\t}\n\t}\n\
    \treturn count;\n}\n"
  code: "// http://qnighy.hatenablog.com/entry/20100117/1263734784\n// http://stackoverflow.com/questions/13792118/kmp-prefix-table\n\
    // http://tokyo-ct.net/usr/kosaka/for_students/jissen1/akiyojissen1/kougi16.html\n\
    \nvector<int> pre_kmp(string pat) {\n\tint k;\n\tvector<int> table((int)pat.size()\
    \ + 1);\n\ttable[0] = -1;\n\n\tfor (int i = 1; i <= pat.size(); ++i) {\n\t\tk\
    \ = table[i-1];\n\n\t\twhile (k >= 0) {\n\t\t\tif (pat[k] == pat[i-1]) break;\n\
    \t\t\telse k = table[k];\n\t\t}\n\n\t\ttable[i] = k + 1;\n\t}\n\n\treturn table;\n\
    }\n\nint match(string t, string p, vector<int> fail) {\n\tint n = t.size(), m\
    \ = p.size();\n\tint count = 0;\n\n\tfor (int i = 0, k = 0; i < n; ++i) {\n\t\t\
    while (k >= 0 && p[k] != t[i]) {\n\t\t\tk = fail[k];\n\t\t}\n\t\tif (++k >= m)\
    \ {\n\t\t\t++count; // match at t[i-m+1 .. i]\n\t\t\tk = fail[k];\n\t\t}\n\t}\n\
    \treturn count;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/string/kmp.cpp
  requiredBy: []
  timestamp: '2021-11-27 23:06:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/string/kmp.cpp
layout: document
redirect_from:
- /library/cpp_src/string/kmp.cpp
- /library/cpp_src/string/kmp.cpp.html
title: cpp_src/string/kmp.cpp
---
