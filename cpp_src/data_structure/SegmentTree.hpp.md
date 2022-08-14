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
    - https://atcoder.jp/contests/practice2/submissions/33977727
    - https://github.com/atcoder/ac-library/blob/master/atcoder/segtree.hpp
  bundledCode: "#line 1 \"cpp_src/data_structure/SegmentTree.hpp\"\n// index of root\
    \ = 1\ntemplate <class U>\nstruct segtree {\n    using T = typename U::T;\n  \
    \  int sz;\n    V<T> dat;\n\n    segtree() {}\n    segtree(int n) : _n(n) {\n\
    \        sz = 1;\n        while (sz < n) sz <<= 1;\n        dat.assign(sz * 2,\
    \ U::id());\n    }\n\n    segtree(const V<T>& a) {\n        int n = a.size();\n\
    \        _n = n;\n        sz = 1;\n        while (sz < n) sz <<= 1;\n        dat.assign(sz\
    \ * 2, U::id());\n        for (int i = 0; i < n; ++i) {\n            dat[sz +\
    \ i] = a[i];\n        }\n        for (int i = sz - 1; i >= 1; --i) {\n       \
    \     upd(i);\n        }\n    }\n\n    void upd(int p) { dat[p] = U::op(dat[p\
    \ << 1], dat[p << 1 | 1]); }\n\n    void build() {\n        for (int i = sz -\
    \ 1; i > 0; --i) {\n            dat[i] = U::op(dat[i << 1], dat[i << 1 | 1]);\n\
    \        }\n    }\n\n    void modify(int p, T v) {\n        p += sz;\n       \
    \ dat[p] = v;\n        while (p >>= 1) {\n            dat[p] = U::op(dat[p <<\
    \ 1], dat[p << 1 | 1]);\n        }\n    }\n\n    T get(int p) const { return dat[p\
    \ + sz]; }\n\n    //[l, r)\n    T query(int l, int r) const {\n        T lval\
    \ = U::id(), rval = U::id();\n        for (l += sz, r += sz; l < r; l >>= 1, r\
    \ >>= 1) {\n            if (l & 1) lval = U::op(lval, dat[l++]);\n           \
    \ if (r & 1) rval = U::op(dat[--r], rval);\n        }\n        return U::op(lval,\
    \ rval);\n    }\n\n    // https://atcoder.jp/contests/practice2/submissions/33977727\n\
    \    // https://github.com/atcoder/ac-library/blob/master/atcoder/segtree.hpp\n\
    \    // find max r s.t. f([l, r)) = true\n    template <class F>\n    int max_right(int\
    \ l, F f) const {\n        // assert(0 <= l && l <= _n);\n        // assert(f(U::id()));\n\
    \n        if (l == sz) return sz;\n        l += sz;\n        auto cur = U::id();\n\
    \        do {\n            while (l % 2 == 0) l >>= 1;\n            if (!f(U::op(cur,\
    \ dat[l]))) {\n                while (l < sz) {\n                    l = l * 2;\n\
    \                    if (f(U::op(cur, dat[l]))) {\n                        cur\
    \ = U::op(cur, dat[l]);\n                        l++;\n                    }\n\
    \                }\n                return l - sz;\n            }\n          \
    \  cur = U::op(cur, dat[l]);\n            l++;\n        } while ((l & -l) != l);\n\
    \        return _n;\n    }\n\n    // needs verification\n    // find min l s.t.\
    \ f([l, r)) = true\n    template <class F>\n    int min_left(int r, F f) const\
    \ {\n        // assert(0 <= r && r <= _n);\n        // assert(f(U::id()));\n\n\
    \        if (r == 0) return 0;\n        r += sz;\n        auto cur = U::id();\n\
    \        do {\n            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n\
    \            if (!f(U::op(dat[r], cur))) {\n                while (r < sz) {\n\
    \                    r = (2 * r + 1);\n                    if (f(U::op(dat[r],\
    \ cur))) {\n                        cur = U::op(dat[r], cur);\n              \
    \          r--;\n                    }\n                }\n                return\
    \ r + 1 - sz;\n            }\n            cur = U::op(dat[r], cur);\n        }\
    \ while ((r & -r) != r);\n        return 0;\n    }\n\n   private:\n    int _n;\n\
    };\n\nconstexpr int INF = TEN(9);\n\n// modify only U\nstruct U {\n    using T\
    \ = int;\n    static T id() { return INF; }\n    static T op(const T& a, const\
    \ T& b) { return min(a, b); }\n};\n"
  code: "// index of root = 1\ntemplate <class U>\nstruct segtree {\n    using T =\
    \ typename U::T;\n    int sz;\n    V<T> dat;\n\n    segtree() {}\n    segtree(int\
    \ n) : _n(n) {\n        sz = 1;\n        while (sz < n) sz <<= 1;\n        dat.assign(sz\
    \ * 2, U::id());\n    }\n\n    segtree(const V<T>& a) {\n        int n = a.size();\n\
    \        _n = n;\n        sz = 1;\n        while (sz < n) sz <<= 1;\n        dat.assign(sz\
    \ * 2, U::id());\n        for (int i = 0; i < n; ++i) {\n            dat[sz +\
    \ i] = a[i];\n        }\n        for (int i = sz - 1; i >= 1; --i) {\n       \
    \     upd(i);\n        }\n    }\n\n    void upd(int p) { dat[p] = U::op(dat[p\
    \ << 1], dat[p << 1 | 1]); }\n\n    void build() {\n        for (int i = sz -\
    \ 1; i > 0; --i) {\n            dat[i] = U::op(dat[i << 1], dat[i << 1 | 1]);\n\
    \        }\n    }\n\n    void modify(int p, T v) {\n        p += sz;\n       \
    \ dat[p] = v;\n        while (p >>= 1) {\n            dat[p] = U::op(dat[p <<\
    \ 1], dat[p << 1 | 1]);\n        }\n    }\n\n    T get(int p) const { return dat[p\
    \ + sz]; }\n\n    //[l, r)\n    T query(int l, int r) const {\n        T lval\
    \ = U::id(), rval = U::id();\n        for (l += sz, r += sz; l < r; l >>= 1, r\
    \ >>= 1) {\n            if (l & 1) lval = U::op(lval, dat[l++]);\n           \
    \ if (r & 1) rval = U::op(dat[--r], rval);\n        }\n        return U::op(lval,\
    \ rval);\n    }\n\n    // https://atcoder.jp/contests/practice2/submissions/33977727\n\
    \    // https://github.com/atcoder/ac-library/blob/master/atcoder/segtree.hpp\n\
    \    // find max r s.t. f([l, r)) = true\n    template <class F>\n    int max_right(int\
    \ l, F f) const {\n        // assert(0 <= l && l <= _n);\n        // assert(f(U::id()));\n\
    \n        if (l == sz) return sz;\n        l += sz;\n        auto cur = U::id();\n\
    \        do {\n            while (l % 2 == 0) l >>= 1;\n            if (!f(U::op(cur,\
    \ dat[l]))) {\n                while (l < sz) {\n                    l = l * 2;\n\
    \                    if (f(U::op(cur, dat[l]))) {\n                        cur\
    \ = U::op(cur, dat[l]);\n                        l++;\n                    }\n\
    \                }\n                return l - sz;\n            }\n          \
    \  cur = U::op(cur, dat[l]);\n            l++;\n        } while ((l & -l) != l);\n\
    \        return _n;\n    }\n\n    // needs verification\n    // find min l s.t.\
    \ f([l, r)) = true\n    template <class F>\n    int min_left(int r, F f) const\
    \ {\n        // assert(0 <= r && r <= _n);\n        // assert(f(U::id()));\n\n\
    \        if (r == 0) return 0;\n        r += sz;\n        auto cur = U::id();\n\
    \        do {\n            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n\
    \            if (!f(U::op(dat[r], cur))) {\n                while (r < sz) {\n\
    \                    r = (2 * r + 1);\n                    if (f(U::op(dat[r],\
    \ cur))) {\n                        cur = U::op(dat[r], cur);\n              \
    \          r--;\n                    }\n                }\n                return\
    \ r + 1 - sz;\n            }\n            cur = U::op(dat[r], cur);\n        }\
    \ while ((r & -r) != r);\n        return 0;\n    }\n\n   private:\n    int _n;\n\
    };\n\nconstexpr int INF = TEN(9);\n\n// modify only U\nstruct U {\n    using T\
    \ = int;\n    static T id() { return INF; }\n    static T op(const T& a, const\
    \ T& b) { return min(a, b); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/data_structure/SegmentTree.hpp
  requiredBy: []
  timestamp: '2022-08-15 00:42:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/data_structure/SegmentTree.hpp
layout: document
redirect_from:
- /library/cpp_src/data_structure/SegmentTree.hpp
- /library/cpp_src/data_structure/SegmentTree.hpp.html
title: cpp_src/data_structure/SegmentTree.hpp
---
