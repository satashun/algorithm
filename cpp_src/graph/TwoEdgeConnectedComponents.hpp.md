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
  bundledCode: "#line 1 \"cpp_src/graph/TwoEdgeConnectedComponents.hpp\"\n// based\
    \ on ei1333\n// tree : u-v -> comp[u]-comp[v]\ntemplate <class T>\nstruct TwoEdgeConnectedComponents\
    \ : LowLink<T> {\n   public:\n    using LowLink<T>::LowLink;\n    using LowLink<T>::g;\n\
    \    using LowLink<T>::ord;\n    using LowLink<T>::low;\n    using LowLink<T>::bridge;\n\
    \n    vector<int> comp;\n    Graph<T> tree;\n    vector<vector<int>> group;\n\n\
    \    void build() {\n        LowLink<T>::build();\n        comp.assign(g.size(),\
    \ -1);\n        int k = 0;\n        for (int i = 0; i < g.size(); i++) {\n   \
    \         if (comp[i] == -1) dfs(i, -1, k);\n        }\n        group.resize(k);\n\
    \        for (int i = 0; i < g.size(); i++) {\n            group[comp[i]].emplace_back(i);\n\
    \        }\n        tree = Graph<T>(k);\n        for (auto& e : bridge) {\n  \
    \          tree.add_edge(comp[e.from], comp[e.to], e.cost);\n        }\n    }\n\
    \    /*\n        void show() {\n            print(group.size());\n           \
    \ for (auto& v : group) {\n                cout << SZ(v) << ' ';\n           \
    \     print(v);\n            }\n        }\n    */\n   private:\n    void dfs(int\
    \ idx, int par, int& k) {\n        if (par >= 0 && ord[par] >= low[idx])\n   \
    \         comp[idx] = comp[par];\n        else\n            comp[idx] = k++;\n\
    \        for (auto& e : g[idx]) {\n            if (comp[e.to] == -1) dfs(e.to,\
    \ idx, k);\n        }\n    }\n};\n"
  code: "// based on ei1333\n// tree : u-v -> comp[u]-comp[v]\ntemplate <class T>\n\
    struct TwoEdgeConnectedComponents : LowLink<T> {\n   public:\n    using LowLink<T>::LowLink;\n\
    \    using LowLink<T>::g;\n    using LowLink<T>::ord;\n    using LowLink<T>::low;\n\
    \    using LowLink<T>::bridge;\n\n    vector<int> comp;\n    Graph<T> tree;\n\
    \    vector<vector<int>> group;\n\n    void build() {\n        LowLink<T>::build();\n\
    \        comp.assign(g.size(), -1);\n        int k = 0;\n        for (int i =\
    \ 0; i < g.size(); i++) {\n            if (comp[i] == -1) dfs(i, -1, k);\n   \
    \     }\n        group.resize(k);\n        for (int i = 0; i < g.size(); i++)\
    \ {\n            group[comp[i]].emplace_back(i);\n        }\n        tree = Graph<T>(k);\n\
    \        for (auto& e : bridge) {\n            tree.add_edge(comp[e.from], comp[e.to],\
    \ e.cost);\n        }\n    }\n    /*\n        void show() {\n            print(group.size());\n\
    \            for (auto& v : group) {\n                cout << SZ(v) << ' ';\n\
    \                print(v);\n            }\n        }\n    */\n   private:\n  \
    \  void dfs(int idx, int par, int& k) {\n        if (par >= 0 && ord[par] >= low[idx])\n\
    \            comp[idx] = comp[par];\n        else\n            comp[idx] = k++;\n\
    \        for (auto& e : g[idx]) {\n            if (comp[e.to] == -1) dfs(e.to,\
    \ idx, k);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/TwoEdgeConnectedComponents.hpp
  requiredBy: []
  timestamp: '2021-10-25 19:28:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/TwoEdgeConnectedComponents.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/TwoEdgeConnectedComponents.hpp
- /library/cpp_src/graph/TwoEdgeConnectedComponents.hpp.html
title: cpp_src/graph/TwoEdgeConnectedComponents.hpp
---
