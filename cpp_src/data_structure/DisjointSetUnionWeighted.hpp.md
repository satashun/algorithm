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
  bundledCode: "#line 1 \"cpp_src/data_structure/DisjointSetUnionWeighted.hpp\"\n\
    // ABC328F\n// ref: maspy's library\n// G:\u7FA4\n\ntemplate <typename G>\nstruct\
    \ WeightedUnionFind {\n    using E = typename G::value_type;\n\n    int n, n_comp;\n\
    \    V<int> par, size;\n    V<E> dif;\n\n    WeightedUnionFind(int n) : n(n),\
    \ n_comp(n), dif(n, G::unit()), size(n, 1) {\n        par.resize(n);\n       \
    \ iota(ALL(par), 0);\n    }\n\n    // (root, val[root]=unit \u3068\u3057\u305F\
    \u3068\u304D\u306E val[v])\n    pair<int, E> get(int v) {\n        E res = G::unit();\n\
    \        while (v != par[v]) {\n            res = G::op(dif[v], res);\n      \
    \      res = G::op(dif[par[v]], res);\n            dif[v] = G::op(dif[par[v]],\
    \ dif[v]);\n            v = par[v] = par[par[v]];\n        }\n        return {v,\
    \ res};\n    }\n\n    pair<int, E> operator[](int v) { return get(v); }\n\n  \
    \  int merge(int from, int to, E x) {\n        auto [v1, x1] = get(from);\n  \
    \      auto [v2, x2] = get(to);\n        if (v1 == v2 && G::op(x1, x) != x2) return\
    \ -1;\n        if (v1 == v2) return 0;\n        if (size[v1] < size[v2]) {\n \
    \           swap(v1, v2);\n            swap(x1, x2);\n            x = G::inverse(x);\n\
    \        }\n        x = G::op(x1, x);\n        x = G::op(x, G::inverse(x2));\n\
    \n        dif[v2] = x;\n        par[v2] = v1;\n        size[v1] += size[v2];\n\
    \        n_comp--;\n        return 1;\n    }\n};\n\ntemplate <typename T>\nstruct\
    \ Monoid_Add {\n    using value_type = T;\n    static constexpr T op(const T&\
    \ x, const T& y) { return x + y; }\n    static constexpr T inverse(const T& x)\
    \ { return -x; }\n    static constexpr T unit() { return T(0); }\n};\n"
  code: "// ABC328F\n// ref: maspy's library\n// G:\u7FA4\n\ntemplate <typename G>\n\
    struct WeightedUnionFind {\n    using E = typename G::value_type;\n\n    int n,\
    \ n_comp;\n    V<int> par, size;\n    V<E> dif;\n\n    WeightedUnionFind(int n)\
    \ : n(n), n_comp(n), dif(n, G::unit()), size(n, 1) {\n        par.resize(n);\n\
    \        iota(ALL(par), 0);\n    }\n\n    // (root, val[root]=unit \u3068\u3057\
    \u305F\u3068\u304D\u306E val[v])\n    pair<int, E> get(int v) {\n        E res\
    \ = G::unit();\n        while (v != par[v]) {\n            res = G::op(dif[v],\
    \ res);\n            res = G::op(dif[par[v]], res);\n            dif[v] = G::op(dif[par[v]],\
    \ dif[v]);\n            v = par[v] = par[par[v]];\n        }\n        return {v,\
    \ res};\n    }\n\n    pair<int, E> operator[](int v) { return get(v); }\n\n  \
    \  int merge(int from, int to, E x) {\n        auto [v1, x1] = get(from);\n  \
    \      auto [v2, x2] = get(to);\n        if (v1 == v2 && G::op(x1, x) != x2) return\
    \ -1;\n        if (v1 == v2) return 0;\n        if (size[v1] < size[v2]) {\n \
    \           swap(v1, v2);\n            swap(x1, x2);\n            x = G::inverse(x);\n\
    \        }\n        x = G::op(x1, x);\n        x = G::op(x, G::inverse(x2));\n\
    \n        dif[v2] = x;\n        par[v2] = v1;\n        size[v1] += size[v2];\n\
    \        n_comp--;\n        return 1;\n    }\n};\n\ntemplate <typename T>\nstruct\
    \ Monoid_Add {\n    using value_type = T;\n    static constexpr T op(const T&\
    \ x, const T& y) { return x + y; }\n    static constexpr T inverse(const T& x)\
    \ { return -x; }\n    static constexpr T unit() { return T(0); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/data_structure/DisjointSetUnionWeighted.hpp
  requiredBy: []
  timestamp: '2023-12-31 13:48:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/data_structure/DisjointSetUnionWeighted.hpp
layout: document
redirect_from:
- /library/cpp_src/data_structure/DisjointSetUnionWeighted.hpp
- /library/cpp_src/data_structure/DisjointSetUnionWeighted.hpp.html
title: cpp_src/data_structure/DisjointSetUnionWeighted.hpp
---
