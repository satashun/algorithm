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
  bundledCode: "#line 1 \"cpp_src/graph/helper/TwoColor.hpp\"\ntemplate <class T>\n\
    pair<bool, V<int>> two_color(const Graph<T>& g) {\n    int n = g.size();\n   \
    \ V<int> col(n, -1);\n\n    auto rec = [&](auto&& f, int v, int c) -> bool {\n\
    \        for (auto e : g[v]) {\n            if (col[e.to] == -1) {\n         \
    \       col[e.to] = c ^ 1;\n                if (!f(f, e.to, c ^ 1)) {\n      \
    \              return false;\n                }\n            } else if (col[e.to]\
    \ == c) {\n                return false;\n            }\n        }\n        return\
    \ true;\n    };\n\n    rep(i, n) {\n        if (col[i] == -1) {\n            if\
    \ (!rec(rec, i, 0)) {\n                return mp(false, col);\n            }\n\
    \        }\n    }\n    return mp(true, col);\n}\n"
  code: "template <class T>\npair<bool, V<int>> two_color(const Graph<T>& g) {\n \
    \   int n = g.size();\n    V<int> col(n, -1);\n\n    auto rec = [&](auto&& f,\
    \ int v, int c) -> bool {\n        for (auto e : g[v]) {\n            if (col[e.to]\
    \ == -1) {\n                col[e.to] = c ^ 1;\n                if (!f(f, e.to,\
    \ c ^ 1)) {\n                    return false;\n                }\n          \
    \  } else if (col[e.to] == c) {\n                return false;\n            }\n\
    \        }\n        return true;\n    };\n\n    rep(i, n) {\n        if (col[i]\
    \ == -1) {\n            if (!rec(rec, i, 0)) {\n                return mp(false,\
    \ col);\n            }\n        }\n    }\n    return mp(true, col);\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/helper/TwoColor.hpp
  requiredBy: []
  timestamp: '2022-05-08 14:32:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/helper/TwoColor.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/helper/TwoColor.hpp
- /library/cpp_src/graph/helper/TwoColor.hpp.html
title: cpp_src/graph/helper/TwoColor.hpp
---
