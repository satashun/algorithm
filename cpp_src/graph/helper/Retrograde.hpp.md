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
  bundledCode: "#line 1 \"cpp_src/graph/helper/Retrograde.hpp\"\n// ABC209E\n// cannot\
    \ move -> lose\n// 1:win, 0:lose, -1:draw\ntemplate <class T>\nV<int> retrograde(const\
    \ Graph<T>& g) {\n    int n = g.size();\n    auto rg = rev_graph(g);\n    V<int>\
    \ deg(n);\n    rep(i, n) deg[i] = SZ(g[i]);\n    queue<int> que;\n    V<int> res(n,\
    \ -1);\n\n    rep(i, n) {\n        if (deg[i] == 0) {\n            res[i] = 0;\n\
    \            que.push(i);\n        }\n    }\n\n    while (!que.empty()) {\n  \
    \      int v = que.front();\n        que.pop();\n        for (auto e : rg[v])\
    \ {\n            if (res[e.to] == -1) {\n                deg[e.to]--;\n      \
    \          if (res[v] == 0) {\n                    res[e.to] = 1;\n          \
    \          que.push(e.to);\n                } else if (deg[e.to] == 0) {\n   \
    \                 res[e.to] = 0;\n                    que.push(e.to);\n      \
    \          }\n            }\n        }\n    }\n    return res;\n}\n"
  code: "// ABC209E\n// cannot move -> lose\n// 1:win, 0:lose, -1:draw\ntemplate <class\
    \ T>\nV<int> retrograde(const Graph<T>& g) {\n    int n = g.size();\n    auto\
    \ rg = rev_graph(g);\n    V<int> deg(n);\n    rep(i, n) deg[i] = SZ(g[i]);\n \
    \   queue<int> que;\n    V<int> res(n, -1);\n\n    rep(i, n) {\n        if (deg[i]\
    \ == 0) {\n            res[i] = 0;\n            que.push(i);\n        }\n    }\n\
    \n    while (!que.empty()) {\n        int v = que.front();\n        que.pop();\n\
    \        for (auto e : rg[v]) {\n            if (res[e.to] == -1) {\n        \
    \        deg[e.to]--;\n                if (res[v] == 0) {\n                  \
    \  res[e.to] = 1;\n                    que.push(e.to);\n                } else\
    \ if (deg[e.to] == 0) {\n                    res[e.to] = 0;\n                \
    \    que.push(e.to);\n                }\n            }\n        }\n    }\n   \
    \ return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/helper/Retrograde.hpp
  requiredBy: []
  timestamp: '2022-09-03 23:41:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/helper/Retrograde.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/helper/Retrograde.hpp
- /library/cpp_src/graph/helper/Retrograde.hpp.html
title: cpp_src/graph/helper/Retrograde.hpp
---
