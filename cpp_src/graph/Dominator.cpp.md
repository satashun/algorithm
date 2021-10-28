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
  bundledCode: "#line 1 \"cpp_src/graph/Dominator.cpp\"\n// modified gifted infants'\
    \ code\n\n// immediately dominate:\n// idom(v) := r -> v \u3067\u5FC5\u305A\u901A\
    \u308B\u9802\u70B9\u306E\u3046\u3061\uFF0C\u4E00\u756A\u8FD1\u3044\u3082\u306E\
    \n// idom(v) -> v \u3067\u8FBA\u3092\u8CBC\u308B\u3068\u6728\u306B\u3067\u304D\
    \u308B\n\ntemplate <class T>\nstruct DominatorTree : Graph<T> {\n    int n;\n\
    \    VV<int> g, rG, bct;\n    V<int> idom, semi, us, id, rId, par, mn, anc;\n\
    \    DominatorTree(int nn) : n(nn) {\n        g.resize(n);\n        rG.resize(n);\n\
    \        bct.resize(n);\n        idom.resize(n, -1);\n        semi.resize(n);\n\
    \        us.resize(n);\n        id.resize(n, -1);\n        rId.resize(n);\n  \
    \      par.resize(n, -1);\n        mn.resize(n);\n        anc.resize(n, -1);\n\
    \        for (int i = 0; i < n; ++i) {\n            semi[i] = i;\n           \
    \ mn[i] = i;\n        }\n    }\n    void add_edge(int a, int b) {\n        g[a].pb(b);\n\
    \        rG[b].pb(a);\n    }\n\n    int find(int v) {\n        if (anc[v] == -1)\
    \ return v;\n        int a = find(anc[v]);\n        if (id[semi[mn[anc[v]]]] <\
    \ id[semi[mn[v]]]) {\n            mn[v] = mn[anc[v]];\n        }\n        return\
    \ anc[v] = a;\n    }\n    void link(int c, int p) { anc[c] = p; }\n    void dfs(int\
    \ v, int p, int& i) {\n        if (id[v] != -1) return;\n        id[v] = i;\n\
    \        rId[i++] = v;\n        par[v] = p;\n        for (int c : g[v]) {\n  \
    \          dfs(c, v, i);\n        }\n    }\n    V<int> calc(int root) {\n    \
    \    int sz = 0;\n        dfs(root, -1, sz);\n        for (int i = sz - 1; i >\
    \ 0; --i) {\n            int w = rId[i];\n            for (int v : rG[w])\n  \
    \              if (id[v] != -1) {\n                    find(v);\n            \
    \        if (id[semi[mn[v]]] < id[semi[w]]) {\n                        semi[w]\
    \ = semi[mn[v]];\n                    }\n                }\n            bct[semi[w]].push_back(w);\n\
    \            for (int v : bct[par[w]]) {\n                find(v);\n         \
    \       us[v] = mn[v];\n            }\n            bct[par[w]].clear();\n    \
    \        link(w, par[w]);\n        }\n        for (int i = 1; i < sz; ++i) {\n\
    \            int w = rId[i];\n            if (semi[w] == semi[us[w]]) {\n    \
    \            idom[w] = semi[w];\n            } else {\n                idom[w]\
    \ = idom[us[w]];\n            }\n        }\n        return idom;\n    }\n};\n"
  code: "// modified gifted infants' code\n\n// immediately dominate:\n// idom(v)\
    \ := r -> v \u3067\u5FC5\u305A\u901A\u308B\u9802\u70B9\u306E\u3046\u3061\uFF0C\
    \u4E00\u756A\u8FD1\u3044\u3082\u306E\n// idom(v) -> v \u3067\u8FBA\u3092\u8CBC\
    \u308B\u3068\u6728\u306B\u3067\u304D\u308B\n\ntemplate <class T>\nstruct DominatorTree\
    \ : Graph<T> {\n    int n;\n    VV<int> g, rG, bct;\n    V<int> idom, semi, us,\
    \ id, rId, par, mn, anc;\n    DominatorTree(int nn) : n(nn) {\n        g.resize(n);\n\
    \        rG.resize(n);\n        bct.resize(n);\n        idom.resize(n, -1);\n\
    \        semi.resize(n);\n        us.resize(n);\n        id.resize(n, -1);\n \
    \       rId.resize(n);\n        par.resize(n, -1);\n        mn.resize(n);\n  \
    \      anc.resize(n, -1);\n        for (int i = 0; i < n; ++i) {\n           \
    \ semi[i] = i;\n            mn[i] = i;\n        }\n    }\n    void add_edge(int\
    \ a, int b) {\n        g[a].pb(b);\n        rG[b].pb(a);\n    }\n\n    int find(int\
    \ v) {\n        if (anc[v] == -1) return v;\n        int a = find(anc[v]);\n \
    \       if (id[semi[mn[anc[v]]]] < id[semi[mn[v]]]) {\n            mn[v] = mn[anc[v]];\n\
    \        }\n        return anc[v] = a;\n    }\n    void link(int c, int p) { anc[c]\
    \ = p; }\n    void dfs(int v, int p, int& i) {\n        if (id[v] != -1) return;\n\
    \        id[v] = i;\n        rId[i++] = v;\n        par[v] = p;\n        for (int\
    \ c : g[v]) {\n            dfs(c, v, i);\n        }\n    }\n    V<int> calc(int\
    \ root) {\n        int sz = 0;\n        dfs(root, -1, sz);\n        for (int i\
    \ = sz - 1; i > 0; --i) {\n            int w = rId[i];\n            for (int v\
    \ : rG[w])\n                if (id[v] != -1) {\n                    find(v);\n\
    \                    if (id[semi[mn[v]]] < id[semi[w]]) {\n                  \
    \      semi[w] = semi[mn[v]];\n                    }\n                }\n    \
    \        bct[semi[w]].push_back(w);\n            for (int v : bct[par[w]]) {\n\
    \                find(v);\n                us[v] = mn[v];\n            }\n   \
    \         bct[par[w]].clear();\n            link(w, par[w]);\n        }\n    \
    \    for (int i = 1; i < sz; ++i) {\n            int w = rId[i];\n           \
    \ if (semi[w] == semi[us[w]]) {\n                idom[w] = semi[w];\n        \
    \    } else {\n                idom[w] = idom[us[w]];\n            }\n       \
    \ }\n        return idom;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/Dominator.cpp
  requiredBy: []
  timestamp: '2021-10-28 16:07:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/Dominator.cpp
layout: document
redirect_from:
- /library/cpp_src/graph/Dominator.cpp
- /library/cpp_src/graph/Dominator.cpp.html
title: cpp_src/graph/Dominator.cpp
---
