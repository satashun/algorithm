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
  bundledCode: "#line 1 \"cpp_src/graph/TreeDP.hpp\"\n// ABC160F, ABC223G\n\ntemplate\
    \ <class N, class E>\nclass treedp {\n    // a: temporary, b[v] : left of v (when\
    \ rooted at some vertex)\n    // after dfs_pre, a[v] means(dp on subtree at v)\
    \ and consider the edge to the parent\n    \n   public:\n    int n;\n    const\
    \ Graph<E>& g;\n    V<N> a, b;\n    V<N> res, sub, bus;\n\n    void dfs_pre(int\
    \ v, int p) {\n        a[v].init(v);\n        E up;\n        for (auto e : g[v])\
    \ {\n            if (e.to != p) {\n                dfs_pre(e.to, v);\n       \
    \         b[e.to] = a[v];\n                a[v] = a[v] + a[e.to];\n          \
    \  } else {\n                up = e;\n            }\n        }\n        sub[v]\
    \ = a[v];\n        if (p != -1) a[v] = a[v].up(up);\n    }\n\n    void dfs_all(int\
    \ v, int p, N cur) {\n        for (int i = int(g[v].size()) - 1; i >= 0; --i)\
    \ {\n            auto e = g[v][i];\n            if (e.to == p) continue;\n   \
    \         bus[e.to] = cur + b[e.to];\n            dfs_all(e.to, v, bus[e.to].up(e));\n\
    \            cur = cur + a[e.to];\n        }\n        res[v] = cur;\n    }\n\n\
    \    treedp(const Graph<E>& gg, int root = 0)\n        : n(gg.size()), g(gg),\
    \ a(n), b(n), res(n), sub(n), bus(n) {\n        dfs_pre(root, -1);\n        N\
    \ tmp;  // identity\n        dfs_all(root, -1, tmp);\n    }\n\n    void slv()\
    \ {\n    }\n};\n\n/*\n// template<class E>\nstruct Data {\n    Data() {}\n   \
    \ void init(int v) {}\n\n    // v -> to -> *\n    // after calculation on vertices\
    \ under to\n    // consider the edge (v - to)\n\n    // Data up(E to) const {\n\
    \    Data up(int to) const {\n        Data res = *this;\n        return res;\n\
    \    }\n\n    Data operator+(const Data& r) const {\n        Data res = *this;\n\
    \        return res;\n    }\n};\n*/\n"
  code: "// ABC160F, ABC223G\n\ntemplate <class N, class E>\nclass treedp {\n    //\
    \ a: temporary, b[v] : left of v (when rooted at some vertex)\n    // after dfs_pre,\
    \ a[v] means(dp on subtree at v) and consider the edge to the parent\n    \n \
    \  public:\n    int n;\n    const Graph<E>& g;\n    V<N> a, b;\n    V<N> res,\
    \ sub, bus;\n\n    void dfs_pre(int v, int p) {\n        a[v].init(v);\n     \
    \   E up;\n        for (auto e : g[v]) {\n            if (e.to != p) {\n     \
    \           dfs_pre(e.to, v);\n                b[e.to] = a[v];\n             \
    \   a[v] = a[v] + a[e.to];\n            } else {\n                up = e;\n  \
    \          }\n        }\n        sub[v] = a[v];\n        if (p != -1) a[v] = a[v].up(up);\n\
    \    }\n\n    void dfs_all(int v, int p, N cur) {\n        for (int i = int(g[v].size())\
    \ - 1; i >= 0; --i) {\n            auto e = g[v][i];\n            if (e.to ==\
    \ p) continue;\n            bus[e.to] = cur + b[e.to];\n            dfs_all(e.to,\
    \ v, bus[e.to].up(e));\n            cur = cur + a[e.to];\n        }\n        res[v]\
    \ = cur;\n    }\n\n    treedp(const Graph<E>& gg, int root = 0)\n        : n(gg.size()),\
    \ g(gg), a(n), b(n), res(n), sub(n), bus(n) {\n        dfs_pre(root, -1);\n  \
    \      N tmp;  // identity\n        dfs_all(root, -1, tmp);\n    }\n\n    void\
    \ slv() {\n    }\n};\n\n/*\n// template<class E>\nstruct Data {\n    Data() {}\n\
    \    void init(int v) {}\n\n    // v -> to -> *\n    // after calculation on vertices\
    \ under to\n    // consider the edge (v - to)\n\n    // Data up(E to) const {\n\
    \    Data up(int to) const {\n        Data res = *this;\n        return res;\n\
    \    }\n\n    Data operator+(const Data& r) const {\n        Data res = *this;\n\
    \        return res;\n    }\n};\n*/"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/TreeDP.hpp
  requiredBy: []
  timestamp: '2021-10-21 19:43:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/TreeDP.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/TreeDP.hpp
- /library/cpp_src/graph/TreeDP.hpp.html
title: cpp_src/graph/TreeDP.hpp
---
