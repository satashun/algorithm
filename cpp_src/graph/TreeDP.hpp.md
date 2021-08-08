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
  bundledCode: "#line 1 \"cpp_src/graph/TreeDP.hpp\"\ntemplate <class N, class E>\n\
    class treedp {\n   public:\n    int n;\n    const VV<E>& g;\n    V<N> a, b;  //\
    \ temporary, b : left\n    V<N> res, sub, bus;\n\n    void dfs_pre(int v, int\
    \ p) {\n        a[v].init(v);\n        E up;\n        for (auto e : g[v]) {\n\
    \            if (e != p) {\n                dfs_pre(e, v);\n                b[e]\
    \ = a[v];\n                a[v] = a[v] + a[e];\n            } else {\n       \
    \         up = e;\n            }\n        }\n        sub[v] = a[v];\n        if\
    \ (p != -1) a[v] = a[v].up(up);\n    }\n\n    void dfs_all(int v, int p, N cur)\
    \ {\n        for (int i = int(g[v].size()) - 1; i >= 0; --i) {\n            auto\
    \ e = g[v][i];\n            if (e == p) continue;\n            bus[e] = cur +\
    \ b[e];\n            dfs_all(e, v, bus[e].up(e));\n            cur = cur + a[e];\n\
    \        }\n        res[v] = cur;\n    }\n\n    treedp(const vvc<E>& gg, int root\
    \ = 0)\n        : n(gg.size()), g(gg), a(n), b(n), res(n), sub(n), bus(n) {\n\
    \        dfs_pre(root, -1);\n        N tmp;\n        tmp.init(root);\n       \
    \ dfs_all(root, -1, tmp);\n    }\n};\n\n/*\nstruct N {\n    void init(int v) {}\n\
    \n    // v -> to -> *\n    // after calculation on vertices under to\n    // consider\
    \ the edge (v - to)\n\n    N up(int to) const {\n        N res = *this;\n    \
    \    return res;\n    }\n\n    N operator+(const N& r) const {\n        N res\
    \ = *this;\n        return res;\n    }\n};\n\nvoid slv() {\n    int n;\n    treedp<N,\
    \ int> dp(n);\n}*/\n"
  code: "template <class N, class E>\nclass treedp {\n   public:\n    int n;\n   \
    \ const VV<E>& g;\n    V<N> a, b;  // temporary, b : left\n    V<N> res, sub,\
    \ bus;\n\n    void dfs_pre(int v, int p) {\n        a[v].init(v);\n        E up;\n\
    \        for (auto e : g[v]) {\n            if (e != p) {\n                dfs_pre(e,\
    \ v);\n                b[e] = a[v];\n                a[v] = a[v] + a[e];\n   \
    \         } else {\n                up = e;\n            }\n        }\n      \
    \  sub[v] = a[v];\n        if (p != -1) a[v] = a[v].up(up);\n    }\n\n    void\
    \ dfs_all(int v, int p, N cur) {\n        for (int i = int(g[v].size()) - 1; i\
    \ >= 0; --i) {\n            auto e = g[v][i];\n            if (e == p) continue;\n\
    \            bus[e] = cur + b[e];\n            dfs_all(e, v, bus[e].up(e));\n\
    \            cur = cur + a[e];\n        }\n        res[v] = cur;\n    }\n\n  \
    \  treedp(const vvc<E>& gg, int root = 0)\n        : n(gg.size()), g(gg), a(n),\
    \ b(n), res(n), sub(n), bus(n) {\n        dfs_pre(root, -1);\n        N tmp;\n\
    \        tmp.init(root);\n        dfs_all(root, -1, tmp);\n    }\n};\n\n/*\nstruct\
    \ N {\n    void init(int v) {}\n\n    // v -> to -> *\n    // after calculation\
    \ on vertices under to\n    // consider the edge (v - to)\n\n    N up(int to)\
    \ const {\n        N res = *this;\n        return res;\n    }\n\n    N operator+(const\
    \ N& r) const {\n        N res = *this;\n        return res;\n    }\n};\n\nvoid\
    \ slv() {\n    int n;\n    treedp<N, int> dp(n);\n}*/"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/TreeDP.hpp
  requiredBy: []
  timestamp: '2021-08-08 16:09:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/TreeDP.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/TreeDP.hpp
- /library/cpp_src/graph/TreeDP.hpp.html
title: cpp_src/graph/TreeDP.hpp
---
