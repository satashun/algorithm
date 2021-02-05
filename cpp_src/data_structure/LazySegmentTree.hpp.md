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
    - https://atcoder.jp/contests/tenka1-2016-qualb/tasks/tenka1_2016_qualB_d
  bundledCode: "#line 1 \"cpp_src/data_structure/LazySegmentTree.hpp\"\n// index of\
    \ root = 1\n// T1 : array value type\n// T2 : action type\n\ntemplate <class U>\n\
    struct segtree {\n    using T1 = typename U::T1;\n    using T2 = typename U::T2;\n\
    \    int sz, H;\n\n    V<T1> a;\n    V<T2> b;\n\n    segtree() { sz = H = -1;\
    \ }\n    segtree(int n) {\n        sz = 1, H = 0;\n        while (sz < n) {\n\
    \            sz *= 2, ++H;\n        }\n        a.assign(sz * 2, U::id1());\n \
    \       b.assign(sz * 2, U::id2());\n    }\n\n    segtree(const V<T1>& vec) {\n\
    \        int n = vec.size();\n        sz = 1, H = 0;\n        while (sz < n) {\n\
    \            sz *= 2, ++H;\n        }\n\n        a.assign(sz * 2, U::id1());\n\
    \        b.assign(sz * 2, U::id2());\n\n        for (int i = 0; i < n; ++i) {\n\
    \            a[sz + i] = vec[i];\n        }\n        for (int i = sz - 1; i >=\
    \ 1; --i) {\n            a[i] = U::op11(a[i << 1 | 0], a[i << 1 | 1]);\n     \
    \   }\n    }\n\n    void up(int i) {\n        while (i >>= 1) {\n            T1\
    \ xl = U::op21(b[i << 1 | 0], a[i << 1 | 0]);\n            T1 xr = U::op21(b[i\
    \ << 1 | 1], a[i << 1 | 1]);\n            a[i] = U::op11(xl, xr);\n        }\n\
    \    }\n\n    void propagate(int p) {\n        for (int h = H; h > 0; --h) {\n\
    \            int i = p >> h;\n            a[i] = U::op21(b[i], a[i]);\n      \
    \      b[i << 1 | 0] = U::op22(b[i], b[i << 1 | 0]);\n            b[i << 1 | 1]\
    \ = U::op22(b[i], b[i << 1 | 1]);\n            b[i] = U::id2();\n        }\n \
    \   }\n\n    // action on [p, q)\n    void apply(int p, int q, T2 x) {\n     \
    \   if (p == q) return;\n        p += sz, q += sz;\n        propagate(p);\n  \
    \      propagate(q - 1);\n\n        for (int l = p, r = q; l < r; l >>= 1, r >>=\
    \ 1) {\n            if (l & 1) b[l] = U::op22(x, b[l]), ++l;\n            if (r\
    \ & 1) --r, b[r] = U::op22(x, b[r]);\n        }\n        up(p);\n        up(q\
    \ - 1);\n    }\n\n    T1 get(int l, int r) {\n        if (l == r) return U::id1();\n\
    \        l += sz, r += sz;\n        propagate(l);\n        propagate(r - 1);\n\
    \n        T1 lval = U::id1(), rval = U::id1();\n\n        for (; l < r; l >>=\
    \ 1, r >>= 1) {\n            if (l & 1) lval = U::op11(lval, U::op21(b[l], a[l])),\
    \ ++l;\n            if (r & 1) --r, rval = U::op11(U::op21(b[r], a[r]), rval);\n\
    \        }\n        return U::op11(lval, rval);\n    }\n};\n\n// for https://atcoder.jp/contests/tenka1-2016-qualb/tasks/tenka1_2016_qualB_d\n\
    // range addition and range minimum query needed, initialization must be cared\n\
    // (set all to 0, while id1 = INF)\n\n// modify only U for use\n\nconstexpr ll\
    \ INF = TEN(18);\n\nstruct U {\n    using T1 = ll;\n    using T2 = ll;\n    static\
    \ T1 id1() { return INF; }\n    static T2 id2() { return 0; }\n    static T1 op11(const\
    \ T1& a, const T1& b) { return min(a, b); }\n    static T1 op21(const T2& b, const\
    \ T1& a) { return b + a; }\n    static T2 op22(const T2& a, const T2& b) { return\
    \ a + b; }\n};\n"
  code: "// index of root = 1\n// T1 : array value type\n// T2 : action type\n\ntemplate\
    \ <class U>\nstruct segtree {\n    using T1 = typename U::T1;\n    using T2 =\
    \ typename U::T2;\n    int sz, H;\n\n    V<T1> a;\n    V<T2> b;\n\n    segtree()\
    \ { sz = H = -1; }\n    segtree(int n) {\n        sz = 1, H = 0;\n        while\
    \ (sz < n) {\n            sz *= 2, ++H;\n        }\n        a.assign(sz * 2, U::id1());\n\
    \        b.assign(sz * 2, U::id2());\n    }\n\n    segtree(const V<T1>& vec) {\n\
    \        int n = vec.size();\n        sz = 1, H = 0;\n        while (sz < n) {\n\
    \            sz *= 2, ++H;\n        }\n\n        a.assign(sz * 2, U::id1());\n\
    \        b.assign(sz * 2, U::id2());\n\n        for (int i = 0; i < n; ++i) {\n\
    \            a[sz + i] = vec[i];\n        }\n        for (int i = sz - 1; i >=\
    \ 1; --i) {\n            a[i] = U::op11(a[i << 1 | 0], a[i << 1 | 1]);\n     \
    \   }\n    }\n\n    void up(int i) {\n        while (i >>= 1) {\n            T1\
    \ xl = U::op21(b[i << 1 | 0], a[i << 1 | 0]);\n            T1 xr = U::op21(b[i\
    \ << 1 | 1], a[i << 1 | 1]);\n            a[i] = U::op11(xl, xr);\n        }\n\
    \    }\n\n    void propagate(int p) {\n        for (int h = H; h > 0; --h) {\n\
    \            int i = p >> h;\n            a[i] = U::op21(b[i], a[i]);\n      \
    \      b[i << 1 | 0] = U::op22(b[i], b[i << 1 | 0]);\n            b[i << 1 | 1]\
    \ = U::op22(b[i], b[i << 1 | 1]);\n            b[i] = U::id2();\n        }\n \
    \   }\n\n    // action on [p, q)\n    void apply(int p, int q, T2 x) {\n     \
    \   if (p == q) return;\n        p += sz, q += sz;\n        propagate(p);\n  \
    \      propagate(q - 1);\n\n        for (int l = p, r = q; l < r; l >>= 1, r >>=\
    \ 1) {\n            if (l & 1) b[l] = U::op22(x, b[l]), ++l;\n            if (r\
    \ & 1) --r, b[r] = U::op22(x, b[r]);\n        }\n        up(p);\n        up(q\
    \ - 1);\n    }\n\n    T1 get(int l, int r) {\n        if (l == r) return U::id1();\n\
    \        l += sz, r += sz;\n        propagate(l);\n        propagate(r - 1);\n\
    \n        T1 lval = U::id1(), rval = U::id1();\n\n        for (; l < r; l >>=\
    \ 1, r >>= 1) {\n            if (l & 1) lval = U::op11(lval, U::op21(b[l], a[l])),\
    \ ++l;\n            if (r & 1) --r, rval = U::op11(U::op21(b[r], a[r]), rval);\n\
    \        }\n        return U::op11(lval, rval);\n    }\n};\n\n// for https://atcoder.jp/contests/tenka1-2016-qualb/tasks/tenka1_2016_qualB_d\n\
    // range addition and range minimum query needed, initialization must be cared\n\
    // (set all to 0, while id1 = INF)\n\n// modify only U for use\n\nconstexpr ll\
    \ INF = TEN(18);\n\nstruct U {\n    using T1 = ll;\n    using T2 = ll;\n    static\
    \ T1 id1() { return INF; }\n    static T2 id2() { return 0; }\n    static T1 op11(const\
    \ T1& a, const T1& b) { return min(a, b); }\n    static T1 op21(const T2& b, const\
    \ T1& a) { return b + a; }\n    static T2 op22(const T2& a, const T2& b) { return\
    \ a + b; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/data_structure/LazySegmentTree.hpp
  requiredBy: []
  timestamp: '2020-07-17 17:57:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/data_structure/LazySegmentTree.hpp
layout: document
redirect_from:
- /library/cpp_src/data_structure/LazySegmentTree.hpp
- /library/cpp_src/data_structure/LazySegmentTree.hpp.html
title: cpp_src/data_structure/LazySegmentTree.hpp
---
