---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/two_edge_connected_components.test.cpp
    title: test/yosupo/two_edge_connected_components.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/graph/LowLink.hpp\"\n// based on ei1333\n// allow\
    \ self loops, multiple edges\ntemplate <class T>\nstruct LowLink : Graph<T> {\n\
    \   public:\n    using Graph<T>::Graph;\n    using Graph<T>::g;\n    vector<int>\
    \ ord, low, articulation;\n    vector<Edge<T>> bridge;\n\n    virtual void build()\
    \ {\n        used.assign(g.size(), 0);\n        ord.assign(g.size(), 0);\n   \
    \     low.assign(g.size(), 0);\n        int k = 0;\n        for (int i = 0; i\
    \ < g.size(); i++) {\n            if (!used[i]) dfs(i, -1, k);\n        }\n  \
    \  }\n\n   private:\n    vector<int> used;\n\n    void dfs(int v, int par, int&\
    \ k) {\n        used[v] = true;\n        low[v] = ord[v] = k++;\n        bool\
    \ is_articulation = false, seen = false;\n        int cnt = 0;\n        for (auto&\
    \ e : g[v]) {\n            if (e.to == par && !exchange(seen, true)) {\n     \
    \           continue;\n            }\n            if (!used[e.to]) {\n       \
    \         ++cnt;\n                dfs(e.to, v, k);\n                low[v] = min(low[v],\
    \ low[e.to]);\n                is_articulation |= (par >= 0 && low[e.to] >= ord[v]);\n\
    \                if (ord[v] < low[e.to]) bridge.emplace_back(e);\n           \
    \ } else {\n                low[v] = min(low[v], ord[e.to]);\n            }\n\
    \        }\n        is_articulation |= (par == -1 && cnt > 1);\n        if (is_articulation)\
    \ articulation.push_back(v);\n    }\n};\n"
  code: "// based on ei1333\n// allow self loops, multiple edges\ntemplate <class\
    \ T>\nstruct LowLink : Graph<T> {\n   public:\n    using Graph<T>::Graph;\n  \
    \  using Graph<T>::g;\n    vector<int> ord, low, articulation;\n    vector<Edge<T>>\
    \ bridge;\n\n    virtual void build() {\n        used.assign(g.size(), 0);\n \
    \       ord.assign(g.size(), 0);\n        low.assign(g.size(), 0);\n        int\
    \ k = 0;\n        for (int i = 0; i < g.size(); i++) {\n            if (!used[i])\
    \ dfs(i, -1, k);\n        }\n    }\n\n   private:\n    vector<int> used;\n\n \
    \   void dfs(int v, int par, int& k) {\n        used[v] = true;\n        low[v]\
    \ = ord[v] = k++;\n        bool is_articulation = false, seen = false;\n     \
    \   int cnt = 0;\n        for (auto& e : g[v]) {\n            if (e.to == par\
    \ && !exchange(seen, true)) {\n                continue;\n            }\n    \
    \        if (!used[e.to]) {\n                ++cnt;\n                dfs(e.to,\
    \ v, k);\n                low[v] = min(low[v], low[e.to]);\n                is_articulation\
    \ |= (par >= 0 && low[e.to] >= ord[v]);\n                if (ord[v] < low[e.to])\
    \ bridge.emplace_back(e);\n            } else {\n                low[v] = min(low[v],\
    \ ord[e.to]);\n            }\n        }\n        is_articulation |= (par == -1\
    \ && cnt > 1);\n        if (is_articulation) articulation.push_back(v);\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/LowLink.hpp
  requiredBy: []
  timestamp: '2021-10-25 19:28:02+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/two_edge_connected_components.test.cpp
documentation_of: cpp_src/graph/LowLink.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/LowLink.hpp
- /library/cpp_src/graph/LowLink.hpp.html
title: cpp_src/graph/LowLink.hpp
---
