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
  bundledCode: "#line 1 \"cpp_src/other/RLE.hpp\"\n//run length encoding\n\nV<pair<char,\
    \ int>> rle(const string& s) {\n    V<pair<char, int>> res;\n    for (auto c :\
    \ s) {\n        if (res.size() > 0 && res.back().first == c) {\n            res.back().second++;\n\
    \        } else {\n            res.emplace_back(c, 1);\n        }\n    }\n   \
    \ return res;\n}\n\ntemplate <class T>\nV<pair<T, int>> rle(const V<T>& vec) {\n\
    \    V<pair<T, int>> res;\n    for (auto v : vec) {\n        if (res.size() >\
    \ 0 && res.back().first == v) {\n            res.back().second++;\n        } else\
    \ {\n            res.emplace_back(v, 1);\n        }\n    }\n    return res;\n\
    }\n"
  code: "//run length encoding\n\nV<pair<char, int>> rle(const string& s) {\n    V<pair<char,\
    \ int>> res;\n    for (auto c : s) {\n        if (res.size() > 0 && res.back().first\
    \ == c) {\n            res.back().second++;\n        } else {\n            res.emplace_back(c,\
    \ 1);\n        }\n    }\n    return res;\n}\n\ntemplate <class T>\nV<pair<T, int>>\
    \ rle(const V<T>& vec) {\n    V<pair<T, int>> res;\n    for (auto v : vec) {\n\
    \        if (res.size() > 0 && res.back().first == v) {\n            res.back().second++;\n\
    \        } else {\n            res.emplace_back(v, 1);\n        }\n    }\n   \
    \ return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/other/RLE.hpp
  requiredBy: []
  timestamp: '2021-12-30 18:51:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/other/RLE.hpp
layout: document
redirect_from:
- /library/cpp_src/other/RLE.hpp
- /library/cpp_src/other/RLE.hpp.html
title: cpp_src/other/RLE.hpp
---
