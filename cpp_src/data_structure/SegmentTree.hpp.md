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
  bundledCode: "#line 1 \"cpp_src/data_structure/SegmentTree.hpp\"\n// index of root\
    \ = 1\n\ntemplate <class U>\nstruct segtree {\n    using T = typename U::T;\n\
    \    int sz;\n    V<T> dat;\n\n    segtree() {}\n    segtree(int n) {\n      \
    \  sz = 1;\n        while (sz < n) sz <<= 1;\n        dat.assign(sz * 2, U::id());\n\
    \    }\n\n    segtree(const V<T>& a) {\n        int n = a.size();\n        sz\
    \ = 1;\n        while (sz < n) sz <<= 1;\n        dat.assign(sz * 2, U::id());\n\
    \        for (int i = 0; i < n; ++i) {\n            dat[sz + i] = a[i];\n    \
    \    }\n        for (int i = sz - 1; i >= 1; --i) {\n            upd(i);\n   \
    \     }\n    }\n\n    void upd(int p) { dat[p] = U::op(dat[p << 1], dat[p << 1\
    \ | 1]); }\n\n    void build() {\n        for (int i = sz - 1; i > 0; --i) {\n\
    \            dat[i] = U::op(dat[i << 1], dat[i << 1 | 1]);\n        }\n    }\n\
    \n    void modify(int p, T v) {\n        p += sz;\n        dat[p] = v;\n     \
    \   while (p >>= 1) {\n            dat[p] = U::op(dat[p << 1], dat[p << 1 | 1]);\n\
    \        }\n    }\n\n    //[l, r)\n\n    T query(int l, int r) {\n        T lval\
    \ = U::id(), rval = U::id();\n        for (l += sz, r += sz; l < r; l >>= 1, r\
    \ >>= 1) {\n            if (l & 1) lval = U::op(lval, dat[l++]);\n           \
    \ if (r & 1) rval = U::op(dat[--r], rval);\n        }\n        return U::op(lval,\
    \ rval);\n    }\n};\n\n// modify only U for use\n\nconstexpr ll INF = TEN(9) +\
    \ 10;\n\nstruct U {\n    using T = ll;\n    static T id() { return INF; }\n  \
    \  static T op(const T& a, const T& b) { return min(a, b); }\n};\n"
  code: "// index of root = 1\n\ntemplate <class U>\nstruct segtree {\n    using T\
    \ = typename U::T;\n    int sz;\n    V<T> dat;\n\n    segtree() {}\n    segtree(int\
    \ n) {\n        sz = 1;\n        while (sz < n) sz <<= 1;\n        dat.assign(sz\
    \ * 2, U::id());\n    }\n\n    segtree(const V<T>& a) {\n        int n = a.size();\n\
    \        sz = 1;\n        while (sz < n) sz <<= 1;\n        dat.assign(sz * 2,\
    \ U::id());\n        for (int i = 0; i < n; ++i) {\n            dat[sz + i] =\
    \ a[i];\n        }\n        for (int i = sz - 1; i >= 1; --i) {\n            upd(i);\n\
    \        }\n    }\n\n    void upd(int p) { dat[p] = U::op(dat[p << 1], dat[p <<\
    \ 1 | 1]); }\n\n    void build() {\n        for (int i = sz - 1; i > 0; --i) {\n\
    \            dat[i] = U::op(dat[i << 1], dat[i << 1 | 1]);\n        }\n    }\n\
    \n    void modify(int p, T v) {\n        p += sz;\n        dat[p] = v;\n     \
    \   while (p >>= 1) {\n            dat[p] = U::op(dat[p << 1], dat[p << 1 | 1]);\n\
    \        }\n    }\n\n    //[l, r)\n\n    T query(int l, int r) {\n        T lval\
    \ = U::id(), rval = U::id();\n        for (l += sz, r += sz; l < r; l >>= 1, r\
    \ >>= 1) {\n            if (l & 1) lval = U::op(lval, dat[l++]);\n           \
    \ if (r & 1) rval = U::op(dat[--r], rval);\n        }\n        return U::op(lval,\
    \ rval);\n    }\n};\n\n// modify only U for use\n\nconstexpr ll INF = TEN(9) +\
    \ 10;\n\nstruct U {\n    using T = ll;\n    static T id() { return INF; }\n  \
    \  static T op(const T& a, const T& b) { return min(a, b); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/data_structure/SegmentTree.hpp
  requiredBy: []
  timestamp: '2020-07-17 17:57:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/data_structure/SegmentTree.hpp
layout: document
redirect_from:
- /library/cpp_src/data_structure/SegmentTree.hpp
- /library/cpp_src/data_structure/SegmentTree.hpp.html
title: cpp_src/data_structure/SegmentTree.hpp
---
