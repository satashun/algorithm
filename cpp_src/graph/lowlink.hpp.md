---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"cpp_src/graph/lowlink.hpp\"\nstruct LowLink {\n\tVV<int>\
    \ g;\n\tV<int> ord, low;\n\tV<bool> vis;\n\tvector<pair<int, int> > bridge;\n\t\
    vector<int> articulation;\n\n\tvoid init(int n) {\n\t\tg.resize(n);\n\t\tord.resize(n);\n\
    \t\tlow.resize(n);\n\t\tvis.resize(n);\n\t}\n\n\tvoid add_edge(int u, int v) {\n\
    \t\tg[u].push_back(v);\n\t\tg[v].push_back(u);\n\t}\n\n\tvoid dfs(int v, int p,\
    \ int &k) {\n\t\tvis[v] = true;\n\n\t\tord[v] = k++;\n\t\tlow[v] = ord[v];\n\n\
    \t\tbool isArticulation = false;\n\t\tint ct = 0;\n\n\t\tfor (int to : g[v]) {\n\
    \t\t\tif (!vis[to]) {\n\t\t\t\tct++;\n\t\t\t\tdfs(to, v, k);\n\t\t\t\tlow[v] =\
    \ min(low[v], low[to]);\n\t\t\t\tif (~p && ord[v] <= low[to]) isArticulation =\
    \ true;\n\t\t\t\tif (ord[v] < low[to]) bridge.push_back(minmax(v, to));\n\t\t\t\
    } else if (to != p) {\n\t\t\t\tlow[v] = min(low[v], ord[to]);\n\t\t\t}\n\t\t}\n\
    \n\t\tif (p == -1 && ct > 1) isArticulation = true;\n\t\tif (isArticulation) articulation.push_back(v);\n\
    \t}\n};\n\n//BiConnectedComponents (node)\nVV<pii> bc;\nV<pii> tmp;\n\nvoid gen(int\
    \ v, int p) {\n\tvis[v] = 1;\n\tfor (int to : g[v]) if (to != p) {\n\t\tif (!vis[to]\
    \ || ord[to] < ord[v]) {\n\t\t\ttmp.eb(min(v, to), max(v, to));\n\t\t}\n\t\tif\
    \ (!vis[to]) {\n\t\t\tgen(to, v);\n\t\t\tif (low[to] >= ord[v]) {\n\t\t\t\tbc.eb();\n\
    \t\t\t\twhile (true) {\n\t\t\t\t\tauto e = tmp.back();\n\t\t\t\t\tbc.back().eb(e);\n\
    \t\t\t\t\ttmp.pop_back();\n\t\t\t\t\tif (e.fi == min(to, v) && e.se == max(to,\
    \ v)) {\n\t\t\t\t\t\tbreak;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n}\n\n\
    //edge \n\nint cmp[MX];\nvoid DFS(int v, int p, int &k) {\n\tif (p != -1 && ord[p]\
    \ >= low[v]) {\n\t\tcmp[v] = cmp[p];\n\t} else {\n\t\tcmp[v] = k++;\n\t}\n\n\t\
    for (int to : g[v]) {\n\t\tif (cmp[to] == -1) {\n\t\t\tDFS(to, v, k);\n\t\t}\n\
    \t}\n}\n\nV<int> gg[MX];\nvoid build(int n) {\n\tmemset(cmp, -1, sizeof(cmp));\n\
    \tint k = 0;\n\tfor (int i = 0; i < n; ++i) {\n\t\tif (cmp[i] == -1) {\n\t\t\t\
    DFS(i, -1, k);\n\t\t}\n\t}\n\tfor (auto &e : bridge) {\n\t\tint u = cmp[e.fi],\
    \ v = cmp[e.se];\n\t\tgg[u].push_back(v); gg[v].push_back(u);\n\t}\n}\n"
  code: "struct LowLink {\n\tVV<int> g;\n\tV<int> ord, low;\n\tV<bool> vis;\n\tvector<pair<int,\
    \ int> > bridge;\n\tvector<int> articulation;\n\n\tvoid init(int n) {\n\t\tg.resize(n);\n\
    \t\tord.resize(n);\n\t\tlow.resize(n);\n\t\tvis.resize(n);\n\t}\n\n\tvoid add_edge(int\
    \ u, int v) {\n\t\tg[u].push_back(v);\n\t\tg[v].push_back(u);\n\t}\n\n\tvoid dfs(int\
    \ v, int p, int &k) {\n\t\tvis[v] = true;\n\n\t\tord[v] = k++;\n\t\tlow[v] = ord[v];\n\
    \n\t\tbool isArticulation = false;\n\t\tint ct = 0;\n\n\t\tfor (int to : g[v])\
    \ {\n\t\t\tif (!vis[to]) {\n\t\t\t\tct++;\n\t\t\t\tdfs(to, v, k);\n\t\t\t\tlow[v]\
    \ = min(low[v], low[to]);\n\t\t\t\tif (~p && ord[v] <= low[to]) isArticulation\
    \ = true;\n\t\t\t\tif (ord[v] < low[to]) bridge.push_back(minmax(v, to));\n\t\t\
    \t} else if (to != p) {\n\t\t\t\tlow[v] = min(low[v], ord[to]);\n\t\t\t}\n\t\t\
    }\n\n\t\tif (p == -1 && ct > 1) isArticulation = true;\n\t\tif (isArticulation)\
    \ articulation.push_back(v);\n\t}\n};\n\n//BiConnectedComponents (node)\nVV<pii>\
    \ bc;\nV<pii> tmp;\n\nvoid gen(int v, int p) {\n\tvis[v] = 1;\n\tfor (int to :\
    \ g[v]) if (to != p) {\n\t\tif (!vis[to] || ord[to] < ord[v]) {\n\t\t\ttmp.eb(min(v,\
    \ to), max(v, to));\n\t\t}\n\t\tif (!vis[to]) {\n\t\t\tgen(to, v);\n\t\t\tif (low[to]\
    \ >= ord[v]) {\n\t\t\t\tbc.eb();\n\t\t\t\twhile (true) {\n\t\t\t\t\tauto e = tmp.back();\n\
    \t\t\t\t\tbc.back().eb(e);\n\t\t\t\t\ttmp.pop_back();\n\t\t\t\t\tif (e.fi == min(to,\
    \ v) && e.se == max(to, v)) {\n\t\t\t\t\t\tbreak;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\
    \t}\n\t\t}\n\t}\n}\n\n//edge \n\nint cmp[MX];\nvoid DFS(int v, int p, int &k)\
    \ {\n\tif (p != -1 && ord[p] >= low[v]) {\n\t\tcmp[v] = cmp[p];\n\t} else {\n\t\
    \tcmp[v] = k++;\n\t}\n\n\tfor (int to : g[v]) {\n\t\tif (cmp[to] == -1) {\n\t\t\
    \tDFS(to, v, k);\n\t\t}\n\t}\n}\n\nV<int> gg[MX];\nvoid build(int n) {\n\tmemset(cmp,\
    \ -1, sizeof(cmp));\n\tint k = 0;\n\tfor (int i = 0; i < n; ++i) {\n\t\tif (cmp[i]\
    \ == -1) {\n\t\t\tDFS(i, -1, k);\n\t\t}\n\t}\n\tfor (auto &e : bridge) {\n\t\t\
    int u = cmp[e.fi], v = cmp[e.se];\n\t\tgg[u].push_back(v); gg[v].push_back(u);\n\
    \t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/lowlink.hpp
  requiredBy: []
  timestamp: '2020-09-17 02:07:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/lowlink.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/lowlink.hpp
- /library/cpp_src/graph/lowlink.hpp.html
title: cpp_src/graph/lowlink.hpp
---
