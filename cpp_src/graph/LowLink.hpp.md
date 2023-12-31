---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two_edge_connected_components.test.cpp
    title: test/yosupo/two_edge_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/LowLink.md
    links: []
  bundledCode: "#line 1 \"cpp_src/graph/LowLink.hpp\"\n/**\n * @docs docs/LowLink.md\n\
    \ */\n\n// based on ei1333\n// allow self loops, multiple edges\ntemplate <class\
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
    };\n"
  code: "/**\n * @docs docs/LowLink.md\n */\n\n// based on ei1333\n// allow self loops,\
    \ multiple edges\ntemplate <class T>\nstruct LowLink : Graph<T> {\n   public:\n\
    \    using Graph<T>::Graph;\n    using Graph<T>::g;\n    vector<int> ord, low,\
    \ articulation;\n    vector<Edge<T>> bridge;\n\n    virtual void build() {\n \
    \       used.assign(g.size(), 0);\n        ord.assign(g.size(), 0);\n        low.assign(g.size(),\
    \ 0);\n        int k = 0;\n        for (int i = 0; i < g.size(); i++) {\n    \
    \        if (!used[i]) dfs(i, -1, k);\n        }\n    }\n\n   private:\n    vector<int>\
    \ used;\n\n    void dfs(int v, int par, int& k) {\n        used[v] = true;\n \
    \       low[v] = ord[v] = k++;\n        bool is_articulation = false, seen = false;\n\
    \        int cnt = 0;\n        for (auto& e : g[v]) {\n            if (e.to ==\
    \ par && !exchange(seen, true)) {\n                continue;\n            }\n\
    \            if (!used[e.to]) {\n                ++cnt;\n                dfs(e.to,\
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
  timestamp: '2023-12-31 13:48:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/two_edge_connected_components.test.cpp
documentation_of: cpp_src/graph/LowLink.hpp
layout: document
title: LowLink
---

## 橋
- DFS 木の辺 uv が橋 $\iff$ ord[$u$] < low_[$v$]

## 関節点
- DFS 木の根が関節点 $\iff$ (次数) > $1$
- DFS 木の根以外の頂点 $u$ が関節点 $\iff$ $u$ のある子 $v$ に対し ord[$u$] $\leq$ low[$v$]
- 特に、上記を満たす頂点の個数が、$u$ を取り除いたときの連結成分数 


## 参考

- [グラフ探索アルゴリズムとその応用](https://hos.ac/slides/20110504_graph.pdf)
