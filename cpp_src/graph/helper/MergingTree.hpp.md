---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc235/submissions/28567563
  bundledCode: "#line 1 \"cpp_src/graph/helper/MergingTree.hpp\"\n// consider merging\
    \ components\n// by choosing cheapest edges\n// add edges with same cost at the\
    \ same time\n// return : (directed tree, multiple components ?)\n// index of root\
    \ : g.size()-1\n// https://atcoder.jp/contests/abc235/submissions/28567563\n\n\
    template <class T>\npair<Graph<T>, bool> merging_tree(int N, V<Edge<T>> edges)\
    \ {\n    map<T, V<pii>> es;\n    for (auto e : edges) {\n        es[e.cost].eb(e.from,\
    \ e.to);\n    }\n\n    unionfind uf;\n    uf.init(N);\n\n    V<int> id(N);\n \
    \   rep(i, N) id[i] = i;\n\n    Graph<T> g(N * 2 + 10);\n\n    int now = N;\n\n\
    \    for (auto [ct, vec] : es) {\n        V<int> pt;\n        for (auto& [a, b]\
    \ : vec) {\n            a = uf.find(a);\n            b = uf.find(b);\n       \
    \ }\n\n        for (auto [a, b] : vec) {\n            if (a != b) {\n        \
    \        pt.pb(a);\n                pt.pb(b);\n            }\n        }\n\n  \
    \      mkuni(pt);\n        int sz = SZ(pt);\n        unionfind sub;\n        sub.init(sz);\n\
    \n        for (auto [a, b] : vec) {\n            if (a == b) continue;\n     \
    \       a = lower_bound(ALL(pt), a) - pt.begin();\n            b = lower_bound(ALL(pt),\
    \ b) - pt.begin();\n            sub.unite(a, b);\n        }\n        VV<int> gr(sz);\n\
    \        rep(i, sz) gr[sub.find(i)].pb(i);\n\n        for (auto v : gr) {\n  \
    \          if (SZ(v) == 0) continue;\n            V<int> real;\n            for\
    \ (int x : v) real.pb(pt[x]);\n\n            int nid = now++;\n            for\
    \ (int x : real) {\n                g.add_directed_edge(nid, id[x]);\n       \
    \     }\n\n            rep(i, SZ(real)) { uf.unite(real[i], real[0]); }\n    \
    \        id[uf.find(real[0])] = nid;\n        }\n    }\n\n    set<int> st;\n \
    \   rep(i, N) st.insert(id[uf.find(i)]);\n\n    bool fake = 0;\n    if (st.size()\
    \ > 1) {\n        fake = 1;\n        int nid = now++;\n        for (int x : st)\
    \ {\n            g.add_directed_edge(nid, x);\n        }\n    }\n\n    g.resize(now);\n\
    \    return mp(g, fake);\n}\n"
  code: "// consider merging components\n// by choosing cheapest edges\n// add edges\
    \ with same cost at the same time\n// return : (directed tree, multiple components\
    \ ?)\n// index of root : g.size()-1\n// https://atcoder.jp/contests/abc235/submissions/28567563\n\
    \ntemplate <class T>\npair<Graph<T>, bool> merging_tree(int N, V<Edge<T>> edges)\
    \ {\n    map<T, V<pii>> es;\n    for (auto e : edges) {\n        es[e.cost].eb(e.from,\
    \ e.to);\n    }\n\n    unionfind uf;\n    uf.init(N);\n\n    V<int> id(N);\n \
    \   rep(i, N) id[i] = i;\n\n    Graph<T> g(N * 2 + 10);\n\n    int now = N;\n\n\
    \    for (auto [ct, vec] : es) {\n        V<int> pt;\n        for (auto& [a, b]\
    \ : vec) {\n            a = uf.find(a);\n            b = uf.find(b);\n       \
    \ }\n\n        for (auto [a, b] : vec) {\n            if (a != b) {\n        \
    \        pt.pb(a);\n                pt.pb(b);\n            }\n        }\n\n  \
    \      mkuni(pt);\n        int sz = SZ(pt);\n        unionfind sub;\n        sub.init(sz);\n\
    \n        for (auto [a, b] : vec) {\n            if (a == b) continue;\n     \
    \       a = lower_bound(ALL(pt), a) - pt.begin();\n            b = lower_bound(ALL(pt),\
    \ b) - pt.begin();\n            sub.unite(a, b);\n        }\n        VV<int> gr(sz);\n\
    \        rep(i, sz) gr[sub.find(i)].pb(i);\n\n        for (auto v : gr) {\n  \
    \          if (SZ(v) == 0) continue;\n            V<int> real;\n            for\
    \ (int x : v) real.pb(pt[x]);\n\n            int nid = now++;\n            for\
    \ (int x : real) {\n                g.add_directed_edge(nid, id[x]);\n       \
    \     }\n\n            rep(i, SZ(real)) { uf.unite(real[i], real[0]); }\n    \
    \        id[uf.find(real[0])] = nid;\n        }\n    }\n\n    set<int> st;\n \
    \   rep(i, N) st.insert(id[uf.find(i)]);\n\n    bool fake = 0;\n    if (st.size()\
    \ > 1) {\n        fake = 1;\n        int nid = now++;\n        for (int x : st)\
    \ {\n            g.add_directed_edge(nid, x);\n        }\n    }\n\n    g.resize(now);\n\
    \    return mp(g, fake);\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/helper/MergingTree.hpp
  requiredBy: []
  timestamp: '2022-01-15 23:16:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/helper/MergingTree.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/helper/MergingTree.hpp
- /library/cpp_src/graph/helper/MergingTree.hpp.html
title: cpp_src/graph/helper/MergingTree.hpp
---
