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
  bundledCode: "#line 1 \"cpp_src/graph/Tree.hpp\"\ntemplate <class T>\npii find_diam(Graph<T>&\
    \ g) {\n    int r = 0;\n    auto ds = bfs(g, r);\n    int r2 = max_element(ALL(ds))\
    \ - ds.begin();\n    auto ds2 = bfs(g, r2);\n    int r3 = max_element(ALL(ds2))\
    \ - ds2.begin();\n    auto ds3 = bfs(g, r3);\n    return mp(r2, r3);\n}\n"
  code: "template <class T>\npii find_diam(Graph<T>& g) {\n    int r = 0;\n    auto\
    \ ds = bfs(g, r);\n    int r2 = max_element(ALL(ds)) - ds.begin();\n    auto ds2\
    \ = bfs(g, r2);\n    int r3 = max_element(ALL(ds2)) - ds2.begin();\n    auto ds3\
    \ = bfs(g, r3);\n    return mp(r2, r3);\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/Tree.hpp
  requiredBy: []
  timestamp: '2022-03-21 17:35:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/Tree.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/Tree.hpp
- /library/cpp_src/graph/Tree.hpp.html
title: cpp_src/graph/Tree.hpp
---
