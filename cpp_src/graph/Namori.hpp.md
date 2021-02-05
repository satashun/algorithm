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
  bundledCode: "#line 1 \"cpp_src/graph/Namori.hpp\"\n// allow multiple components\n\
    \nstruct Namori {\n\tint n;\n\tV<int> deg, par;\n\tVV<int> g, g2; //g2 for tree\
    \ from cycles\n\tV<bool> vis;\n\tVV<int> cycles;\n\n\tNamori(){}\n\tNamori(int\
    \ n) : n(n) {\n\t\tdeg = V<int>(n);\n\t\tpar = V<int>(n, -1);\n\t\tg = VV<int>(n);\n\
    \t\tg2 = VV<int>(n);\n\t\tvis = V<bool>(n);\n\t}\n\n\tvoid add_edge(int a, int\
    \ b) {\n\t\tg[a].pb(b); g[b].pb(a);\n\t\t++deg[a]; ++deg[b];\n\t}\n\n\tvoid dfs(int\
    \ v, V<int>& cycle) {\n\t\tvis[v] = true;\n\t\tcycle.pb(v);\n\n\t\tfor (int to\
    \ : g[v]) if (deg[to] == 2 && !vis[to]) {\n\t\t\tdfs(to, cycle);\n\t\t}\n\t}\n\
    \n\tvoid dfs2(int v, int p) {\n\t\tfor (int to : g2[v]) if (to != p) {\n\t\t\t\
    dfs2(to, v);\n\t\t}\n\t}\n\n\tvoid build() {\n\t\tqueue<int> que;\n\t\trep(i,\
    \ n) {\n\t\t\tif (deg[i] == 1) {\n\t\t\t\tque.push(i);\n\t\t\t}\n\t\t}\n\n\t\t\
    while (!que.empty()) {\n\t\t\tint v = que.front(); que.pop();\n\t\t\tvis[v] =\
    \ true;\n\t\t\tfor (int to : g[v]) if (deg[to] > 1) {\n\t\t\t\tg2[to].pb(v);\n\
    \t\t\t\tpar[v] = to;\n\n\t\t\t\tif (--deg[to] == 1) {\n\t\t\t\t\tque.push(to);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\n\t\trep(i, n) if (deg[i] == 2 && !vis[i]) {\n\t\t\
    \tcycles.eb(V<int>{});\n\t\t\tdfs(i, cycles.back());\n\t\t\tV<int> cyc = cycles.back();\n\
    \t\t\tfor (int v : cyc) {\n\t\t\t\tdfs2(v, -1);\n\t\t\t}\n\t\t}\n\t}\n};\n"
  code: "// allow multiple components\n\nstruct Namori {\n\tint n;\n\tV<int> deg,\
    \ par;\n\tVV<int> g, g2; //g2 for tree from cycles\n\tV<bool> vis;\n\tVV<int>\
    \ cycles;\n\n\tNamori(){}\n\tNamori(int n) : n(n) {\n\t\tdeg = V<int>(n);\n\t\t\
    par = V<int>(n, -1);\n\t\tg = VV<int>(n);\n\t\tg2 = VV<int>(n);\n\t\tvis = V<bool>(n);\n\
    \t}\n\n\tvoid add_edge(int a, int b) {\n\t\tg[a].pb(b); g[b].pb(a);\n\t\t++deg[a];\
    \ ++deg[b];\n\t}\n\n\tvoid dfs(int v, V<int>& cycle) {\n\t\tvis[v] = true;\n\t\
    \tcycle.pb(v);\n\n\t\tfor (int to : g[v]) if (deg[to] == 2 && !vis[to]) {\n\t\t\
    \tdfs(to, cycle);\n\t\t}\n\t}\n\n\tvoid dfs2(int v, int p) {\n\t\tfor (int to\
    \ : g2[v]) if (to != p) {\n\t\t\tdfs2(to, v);\n\t\t}\n\t}\n\n\tvoid build() {\n\
    \t\tqueue<int> que;\n\t\trep(i, n) {\n\t\t\tif (deg[i] == 1) {\n\t\t\t\tque.push(i);\n\
    \t\t\t}\n\t\t}\n\n\t\twhile (!que.empty()) {\n\t\t\tint v = que.front(); que.pop();\n\
    \t\t\tvis[v] = true;\n\t\t\tfor (int to : g[v]) if (deg[to] > 1) {\n\t\t\t\tg2[to].pb(v);\n\
    \t\t\t\tpar[v] = to;\n\n\t\t\t\tif (--deg[to] == 1) {\n\t\t\t\t\tque.push(to);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\n\t\trep(i, n) if (deg[i] == 2 && !vis[i]) {\n\t\t\
    \tcycles.eb(V<int>{});\n\t\t\tdfs(i, cycles.back());\n\t\t\tV<int> cyc = cycles.back();\n\
    \t\t\tfor (int v : cyc) {\n\t\t\t\tdfs2(v, -1);\n\t\t\t}\n\t\t}\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/Namori.hpp
  requiredBy: []
  timestamp: '2020-04-01 18:25:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/Namori.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/Namori.hpp
- /library/cpp_src/graph/Namori.hpp.html
title: cpp_src/graph/Namori.hpp
---
