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
  bundledCode: "#line 1 \"cpp_src/graph/CentroidDecomposition.hpp\"\n// ABC291H\n\
    template <class T>\nclass CentroidDecomposition {\n   public:\n    const int INF\
    \ = 1e9;\n\n    int n;\n    V<int> centroid, subtree_size;\n    Graph<T> g;\n\
    \    VV<int> tree;\n\n    CentroidDecomposition(Graph<T> g) : g(g) {\n       \
    \ n = g.size();\n        centroid = V<int>(n);\n        subtree_size = V<int>(n);\n\
    \        tree = VV<int>(n);\n    }\n\n    int compute_subtree_size(int v, int\
    \ p) {\n        int c = 1;\n        for (auto e : g[v]) {\n            if (e.to\
    \ == p || centroid[e.to]) continue;\n            c += compute_subtree_size(e.to,\
    \ v);\n        }\n        return subtree_size[v] = c;\n    }\n\n    pair<int,\
    \ int> search_centroid(int v, int p, int t) {\n        auto res = make_pair(INF,\
    \ -1);\n        int s = 1, m = 0;\n\n        for (auto e : g[v]) {\n         \
    \   if (e.to == p || centroid[e.to]) continue;\n\n            res = min(res, search_centroid(e.to,\
    \ v, t));\n            m = max(m, subtree_size[e.to]);\n            s += subtree_size[e.to];\n\
    \        }\n\n        m = max(m, t - s);\n        res = min(res, mp(m, v));\n\
    \        return res;\n    }\n\n    // return centroid\n    int solve_sub(int v)\
    \ {\n        compute_subtree_size(v, -1);\n        int s = search_centroid(v,\
    \ -1, subtree_size[v]).second;\n        centroid[s] = 1;\n\n        // centroid\
    \ = s !!!!!\n\n        for (auto e : g[s]) {\n            if (centroid[e.to])\
    \ continue;\n            int tr = solve_sub(e.to);\n            tree[s].pb(tr);\n\
    \        }\n        return s;\n    }\n};\n"
  code: "// ABC291H\ntemplate <class T>\nclass CentroidDecomposition {\n   public:\n\
    \    const int INF = 1e9;\n\n    int n;\n    V<int> centroid, subtree_size;\n\
    \    Graph<T> g;\n    VV<int> tree;\n\n    CentroidDecomposition(Graph<T> g) :\
    \ g(g) {\n        n = g.size();\n        centroid = V<int>(n);\n        subtree_size\
    \ = V<int>(n);\n        tree = VV<int>(n);\n    }\n\n    int compute_subtree_size(int\
    \ v, int p) {\n        int c = 1;\n        for (auto e : g[v]) {\n           \
    \ if (e.to == p || centroid[e.to]) continue;\n            c += compute_subtree_size(e.to,\
    \ v);\n        }\n        return subtree_size[v] = c;\n    }\n\n    pair<int,\
    \ int> search_centroid(int v, int p, int t) {\n        auto res = make_pair(INF,\
    \ -1);\n        int s = 1, m = 0;\n\n        for (auto e : g[v]) {\n         \
    \   if (e.to == p || centroid[e.to]) continue;\n\n            res = min(res, search_centroid(e.to,\
    \ v, t));\n            m = max(m, subtree_size[e.to]);\n            s += subtree_size[e.to];\n\
    \        }\n\n        m = max(m, t - s);\n        res = min(res, mp(m, v));\n\
    \        return res;\n    }\n\n    // return centroid\n    int solve_sub(int v)\
    \ {\n        compute_subtree_size(v, -1);\n        int s = search_centroid(v,\
    \ -1, subtree_size[v]).second;\n        centroid[s] = 1;\n\n        // centroid\
    \ = s !!!!!\n\n        for (auto e : g[s]) {\n            if (centroid[e.to])\
    \ continue;\n            int tr = solve_sub(e.to);\n            tree[s].pb(tr);\n\
    \        }\n        return s;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/CentroidDecomposition.hpp
  requiredBy: []
  timestamp: '2023-04-22 00:40:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/CentroidDecomposition.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/CentroidDecomposition.hpp
- /library/cpp_src/graph/CentroidDecomposition.hpp.html
title: cpp_src/graph/CentroidDecomposition.hpp
---
