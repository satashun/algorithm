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
    - https://ei1333.github.io/library/graph/others/eulerian-trail.hpp
  bundledCode: "#line 1 \"cpp_src/graph/EulerianTrail.hpp\"\n// modified https://ei1333.github.io/library/graph/others/eulerian-trail.hpp\n\
    // allow multiple edges and self loops, multiple components\ntemplate <class T,\
    \ bool directed>\nstruct EulerianTrail : Graph<T> {\n   public:\n    using Graph<T>::g;\n\
    \    using Graph<T>::Graph;\n    using Graph<T>::edges;\n    using Graph<T>::es;\n\
    \    using E = Edge<T>;\n\n    V<int> used_vertex, used_edge, deg;\n\n    void\
    \ init(int n) {\n        deg.assign(n, 0);\n        used_vertex.assign(n, 0);\n\
    \    }\n\n    void add_directed_edge(int from, int to, T cost = 1) {\n       \
    \ g[from].emplace_back(from, to, cost, es++);\n        deg[from]++;\n        deg[to]--;\n\
    \    }\n\n    void add_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n        deg[from]++;\n\
    \        deg[to]++;\n    }\n\n    EulerianTrail(int n) : Graph<T>(n), used_vertex(n),\
    \ deg(n) {}\n\n    E get_edge(int idx) const { return edges[idx]; }\n\n    VV<int>\
    \ enumerate_eulerian_trail() {\n        if (directed) {\n            for (auto&\
    \ v : deg)\n                if (v != 0) return {};\n        } else {\n       \
    \     for (auto& v : deg)\n                if (v & 1) return {};\n        }\n\
    \        used_edge.assign(es, 0);\n        VV<int> res;\n        rep(i, g.size())\
    \ {\n            if (!SZ(g[i]) || used_vertex[i]) continue;\n            res.push_back(go(i));\n\
    \        }\n        return res;\n    }\n\n    // yukicoder 583\n    VV<int> enumerate_semi_eulerian_trail()\
    \ {\n        unionfind uf(g.size());\n        for (auto& e : edges) {\n      \
    \      uf.unite(e.from, e.to);\n        }\n        VV<int> group(g.size());\n\
    \        rep(i, g.size()) group[uf.find(i)].push_back(i);\n\n        VV<int> res;\n\
    \        used_edge.assign(es, 0);\n\n        for (auto& vs : group) {\n      \
    \      if (!SZ(vs)) continue;\n            int s = -1, t = -1;\n            if\
    \ (directed) {\n                for (auto& v : vs) {\n                    if (abs(deg[v])\
    \ > 1) {\n                        return {};\n                    } else if (deg[v]\
    \ == 1) {\n                        if (s != -1) return {};\n                 \
    \       s = v;\n                    }\n                }\n            } else {\n\
    \                for (auto& v : vs) {\n                    if (deg[v] & 1) {\n\
    \                        if (s == -1)\n                            s = v;\n  \
    \                      else if (t == -1)\n                            t = v;\n\
    \                        else\n                            return {};\n      \
    \              }\n                }\n            }\n            debug(s, t);\n\
    \            if (s == -1) s = vs[0];\n            res.emplace_back(go(s));\n \
    \           if (!SZ(res.back())) res.pop_back();\n        }\n        return res;\n\
    \    }\n\n    // return {id of edges}\n    V<int> go(int s) {\n        stack<pair<int,\
    \ int>> st;\n        V<int> ord;\n        st.emplace(s, -1);\n        while (!st.empty())\
    \ {\n            int idx = st.top().first;\n            used_vertex[idx] = true;\n\
    \            if (g[idx].empty()) {\n                ord.emplace_back(st.top().second);\n\
    \                st.pop();\n            } else {\n                auto e = g[idx].back();\n\
    \                g[idx].pop_back();\n                if (used_edge[e.idx]) continue;\n\
    \                used_edge[e.idx] = true;\n                st.emplace(e.to, e.idx);\n\
    \            }\n        }\n        ord.pop_back();\n        reverse(ord.begin(),\
    \ ord.end());\n        return ord;\n    }\n};\n"
  code: "// modified https://ei1333.github.io/library/graph/others/eulerian-trail.hpp\n\
    // allow multiple edges and self loops, multiple components\ntemplate <class T,\
    \ bool directed>\nstruct EulerianTrail : Graph<T> {\n   public:\n    using Graph<T>::g;\n\
    \    using Graph<T>::Graph;\n    using Graph<T>::edges;\n    using Graph<T>::es;\n\
    \    using E = Edge<T>;\n\n    V<int> used_vertex, used_edge, deg;\n\n    void\
    \ init(int n) {\n        deg.assign(n, 0);\n        used_vertex.assign(n, 0);\n\
    \    }\n\n    void add_directed_edge(int from, int to, T cost = 1) {\n       \
    \ g[from].emplace_back(from, to, cost, es++);\n        deg[from]++;\n        deg[to]--;\n\
    \    }\n\n    void add_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n        deg[from]++;\n\
    \        deg[to]++;\n    }\n\n    EulerianTrail(int n) : Graph<T>(n), used_vertex(n),\
    \ deg(n) {}\n\n    E get_edge(int idx) const { return edges[idx]; }\n\n    VV<int>\
    \ enumerate_eulerian_trail() {\n        if (directed) {\n            for (auto&\
    \ v : deg)\n                if (v != 0) return {};\n        } else {\n       \
    \     for (auto& v : deg)\n                if (v & 1) return {};\n        }\n\
    \        used_edge.assign(es, 0);\n        VV<int> res;\n        rep(i, g.size())\
    \ {\n            if (!SZ(g[i]) || used_vertex[i]) continue;\n            res.push_back(go(i));\n\
    \        }\n        return res;\n    }\n\n    // yukicoder 583\n    VV<int> enumerate_semi_eulerian_trail()\
    \ {\n        unionfind uf(g.size());\n        for (auto& e : edges) {\n      \
    \      uf.unite(e.from, e.to);\n        }\n        VV<int> group(g.size());\n\
    \        rep(i, g.size()) group[uf.find(i)].push_back(i);\n\n        VV<int> res;\n\
    \        used_edge.assign(es, 0);\n\n        for (auto& vs : group) {\n      \
    \      if (!SZ(vs)) continue;\n            int s = -1, t = -1;\n            if\
    \ (directed) {\n                for (auto& v : vs) {\n                    if (abs(deg[v])\
    \ > 1) {\n                        return {};\n                    } else if (deg[v]\
    \ == 1) {\n                        if (s != -1) return {};\n                 \
    \       s = v;\n                    }\n                }\n            } else {\n\
    \                for (auto& v : vs) {\n                    if (deg[v] & 1) {\n\
    \                        if (s == -1)\n                            s = v;\n  \
    \                      else if (t == -1)\n                            t = v;\n\
    \                        else\n                            return {};\n      \
    \              }\n                }\n            }\n            debug(s, t);\n\
    \            if (s == -1) s = vs[0];\n            res.emplace_back(go(s));\n \
    \           if (!SZ(res.back())) res.pop_back();\n        }\n        return res;\n\
    \    }\n\n    // return {id of edges}\n    V<int> go(int s) {\n        stack<pair<int,\
    \ int>> st;\n        V<int> ord;\n        st.emplace(s, -1);\n        while (!st.empty())\
    \ {\n            int idx = st.top().first;\n            used_vertex[idx] = true;\n\
    \            if (g[idx].empty()) {\n                ord.emplace_back(st.top().second);\n\
    \                st.pop();\n            } else {\n                auto e = g[idx].back();\n\
    \                g[idx].pop_back();\n                if (used_edge[e.idx]) continue;\n\
    \                used_edge[e.idx] = true;\n                st.emplace(e.to, e.idx);\n\
    \            }\n        }\n        ord.pop_back();\n        reverse(ord.begin(),\
    \ ord.end());\n        return ord;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/EulerianTrail.hpp
  requiredBy: []
  timestamp: '2022-05-22 15:10:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/EulerianTrail.hpp
layout: document
title: Eulerian Trail
---

Euler Path や Euler Circuit を求める．

- 有向/無向に対応
- グラフは simple でなくてもよい
- 連結成分が複数ある場合も対応

## 参考

- [Eulerian path - Wikiwand](https://www.wikiwand.com/en/Eulerian_path#/Hierholzer.27s_algorithm)

- [競プロにおけるオイラー路とその応用について](https://kokiymgch.hatenablog.com/entry/2017/12/07/193238)