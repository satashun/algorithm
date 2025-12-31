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
    - https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp
  bundledCode: "#line 1 \"cpp_src/data_structure/LazySegmentTree.hpp\"\n// ref:\n\
    // https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp\n\
    \n// index of root = 1\n// T1 : array value type\n// T2 : action type\n\ntemplate\
    \ <class U>\nstruct segtree {\n    using T1 = typename U::T1;\n    using T2 =\
    \ typename U::T2;\n    int sz, H, _n;\n\n    V<T1> a;\n    V<T2> b;\n\n    segtree()\
    \ { sz = H = -1; }\n    segtree(int n) {\n        _n = n;\n        sz = 1, H =\
    \ 0;\n        while (sz < n) {\n            sz *= 2, ++H;\n        }\n       \
    \ a.assign(sz * 2, U::id1());\n        b.assign(sz * 2, U::id2());\n    }\n\n\
    \    segtree(const V<T1>& vec) {\n        int n = vec.size();\n        _n = n;\n\
    \        sz = 1, H = 0;\n        while (sz < n) {\n            sz *= 2, ++H;\n\
    \        }\n\n        a.assign(sz * 2, U::id1());\n        b.assign(sz * 2, U::id2());\n\
    \n        for (int i = 0; i < n; ++i) {\n            a[sz + i] = vec[i];\n   \
    \     }\n        for (int i = sz - 1; i >= 1; --i) {\n            a[i] = U::op11(a[(i\
    \ << 1) | 0], a[(i << 1) | 1]);\n        }\n    }\n\n    inline T1 reflect(int\
    \ k) {\n        return b[k] == U::id2() ? a[k] : U::op21(b[k], a[k]);\n    }\n\
    \n    void up(int i) {\n        while (i >>= 1) {\n            a[i] = U::op11(reflect((i\
    \ << 1) | 0), reflect((i << 1) | 1));\n        }\n    }\n\n    void push(int i)\
    \ {\n        a[i] = reflect(i);\n        if (i < sz) {\n            b[i << 1 |\
    \ 0] = U::op22(b[i], b[i << 1 | 0]);\n            b[i << 1 | 1] = U::op22(b[i],\
    \ b[i << 1 | 1]);\n        }\n        b[i] = U::id2();\n    }\n\n    void propagate(int\
    \ p) {\n        for (int h = H; h > 0; --h) {\n            int i = p >> h;\n \
    \           a[i] = reflect(i);\n            b[i << 1 | 0] = U::op22(b[i], b[i\
    \ << 1 | 0]);\n            b[i << 1 | 1] = U::op22(b[i], b[i << 1 | 1]);\n   \
    \         b[i] = U::id2();\n        }\n    }\n\n    void set(int p, T1 x) {\n\
    \        p += sz;\n        propagate(p);\n        a[p] = x;\n        b[p] = U::id2();\n\
    \        up(p);\n    }\n\n    T1 get(int p) {\n        p += sz;\n        propagate(p);\n\
    \        return reflect(p);\n    }\n\n    // action on [p, q)\n    void apply(int\
    \ p, int q, T2 x) {\n        if (p >= q) return;\n        p += sz, q += sz;\n\
    \        propagate(p);\n        propagate(q - 1);\n\n        for (int l = p, r\
    \ = q; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) b[l] = U::op22(x, b[l]),\
    \ l++;\n            if (r & 1) --r, b[r] = U::op22(x, b[r]);\n        }\n    \
    \    up(p);\n        up(q - 1);\n    }\n\n    T1 prod(int l, int r) {\n      \
    \  if (l >= r) return U::id1();\n        l += sz, r += sz;\n        propagate(l);\n\
    \        propagate(r - 1);\n\n        T1 lval = U::id1(), rval = U::id1();\n\n\
    \        for (; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) lval = U::op11(lval,\
    \ reflect(l++));\n            if (r & 1) rval = U::op11(reflect(--r), rval);\n\
    \        }\n        return U::op11(lval, rval);\n    }\n\n    // G: T1->bool\n\
    \    // find max r s.t. g(f[l, r)) = true\n    // ABC389F, ABC371F\n    template\
    \ <class G>\n    int max_right(int l, G g) {\n        if (l == _n) return _n;\n\
    \        l += sz;\n        propagate(l);\n\n        T1 sm = U::id1();\n      \
    \  do {\n            while (l % 2 == 0) l >>= 1;\n            if (!g(U::op11(sm,\
    \ reflect(l)))) {\n                while (l < sz) {\n                    push(l);\n\
    \                    l = (2 * l);\n                    if (g(U::op11(sm, reflect(l))))\
    \ {\n                        sm = U::op11(sm, reflect(l));\n                 \
    \       l++;\n                    }\n                }\n                return\
    \ l - sz;\n            }\n            sm = U::op11(sm, reflect(l));\n        \
    \    push(l);\n            l++;\n        } while ((l & -l) != l);\n        return\
    \ _n;\n    }\n\n    // G: T1->bool\n    // find min l s.t. f([l, r)) = true\n\
    \    // ABC389F, ABC371F\n    template <class G>\n    int min_left(int r, G g)\
    \ {\n        if (r == 0) return 0;\n        r += sz;\n        propagate(r - 1);\n\
    \n        T1 sm = U::id1();\n        do {\n            r--;\n            while\
    \ (r > 1 && (r % 2)) r >>= 1;\n            if (!g(U::op11(reflect(r), sm))) {\n\
    \                while (r < sz) {\n                    push(r);\n            \
    \        r = (2 * r + 1);\n                    if (g(U::op11(reflect(r), sm)))\
    \ {\n                        sm = U::op11(reflect(r), sm);\n                 \
    \       r--;\n                    }\n                }\n                return\
    \ r + 1 - sz;\n            }\n            sm = U::op11(reflect(r), sm);\n    \
    \    } while ((r & -r) != r);\n        return 0;\n    }\n};\n"
  code: "// ref:\n// https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp\n\
    \n// index of root = 1\n// T1 : array value type\n// T2 : action type\n\ntemplate\
    \ <class U>\nstruct segtree {\n    using T1 = typename U::T1;\n    using T2 =\
    \ typename U::T2;\n    int sz, H, _n;\n\n    V<T1> a;\n    V<T2> b;\n\n    segtree()\
    \ { sz = H = -1; }\n    segtree(int n) {\n        _n = n;\n        sz = 1, H =\
    \ 0;\n        while (sz < n) {\n            sz *= 2, ++H;\n        }\n       \
    \ a.assign(sz * 2, U::id1());\n        b.assign(sz * 2, U::id2());\n    }\n\n\
    \    segtree(const V<T1>& vec) {\n        int n = vec.size();\n        _n = n;\n\
    \        sz = 1, H = 0;\n        while (sz < n) {\n            sz *= 2, ++H;\n\
    \        }\n\n        a.assign(sz * 2, U::id1());\n        b.assign(sz * 2, U::id2());\n\
    \n        for (int i = 0; i < n; ++i) {\n            a[sz + i] = vec[i];\n   \
    \     }\n        for (int i = sz - 1; i >= 1; --i) {\n            a[i] = U::op11(a[(i\
    \ << 1) | 0], a[(i << 1) | 1]);\n        }\n    }\n\n    inline T1 reflect(int\
    \ k) {\n        return b[k] == U::id2() ? a[k] : U::op21(b[k], a[k]);\n    }\n\
    \n    void up(int i) {\n        while (i >>= 1) {\n            a[i] = U::op11(reflect((i\
    \ << 1) | 0), reflect((i << 1) | 1));\n        }\n    }\n\n    void push(int i)\
    \ {\n        a[i] = reflect(i);\n        if (i < sz) {\n            b[i << 1 |\
    \ 0] = U::op22(b[i], b[i << 1 | 0]);\n            b[i << 1 | 1] = U::op22(b[i],\
    \ b[i << 1 | 1]);\n        }\n        b[i] = U::id2();\n    }\n\n    void propagate(int\
    \ p) {\n        for (int h = H; h > 0; --h) {\n            int i = p >> h;\n \
    \           a[i] = reflect(i);\n            b[i << 1 | 0] = U::op22(b[i], b[i\
    \ << 1 | 0]);\n            b[i << 1 | 1] = U::op22(b[i], b[i << 1 | 1]);\n   \
    \         b[i] = U::id2();\n        }\n    }\n\n    void set(int p, T1 x) {\n\
    \        p += sz;\n        propagate(p);\n        a[p] = x;\n        b[p] = U::id2();\n\
    \        up(p);\n    }\n\n    T1 get(int p) {\n        p += sz;\n        propagate(p);\n\
    \        return reflect(p);\n    }\n\n    // action on [p, q)\n    void apply(int\
    \ p, int q, T2 x) {\n        if (p >= q) return;\n        p += sz, q += sz;\n\
    \        propagate(p);\n        propagate(q - 1);\n\n        for (int l = p, r\
    \ = q; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) b[l] = U::op22(x, b[l]),\
    \ l++;\n            if (r & 1) --r, b[r] = U::op22(x, b[r]);\n        }\n    \
    \    up(p);\n        up(q - 1);\n    }\n\n    T1 prod(int l, int r) {\n      \
    \  if (l >= r) return U::id1();\n        l += sz, r += sz;\n        propagate(l);\n\
    \        propagate(r - 1);\n\n        T1 lval = U::id1(), rval = U::id1();\n\n\
    \        for (; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) lval = U::op11(lval,\
    \ reflect(l++));\n            if (r & 1) rval = U::op11(reflect(--r), rval);\n\
    \        }\n        return U::op11(lval, rval);\n    }\n\n    // G: T1->bool\n\
    \    // find max r s.t. g(f[l, r)) = true\n    // ABC389F, ABC371F\n    template\
    \ <class G>\n    int max_right(int l, G g) {\n        if (l == _n) return _n;\n\
    \        l += sz;\n        propagate(l);\n\n        T1 sm = U::id1();\n      \
    \  do {\n            while (l % 2 == 0) l >>= 1;\n            if (!g(U::op11(sm,\
    \ reflect(l)))) {\n                while (l < sz) {\n                    push(l);\n\
    \                    l = (2 * l);\n                    if (g(U::op11(sm, reflect(l))))\
    \ {\n                        sm = U::op11(sm, reflect(l));\n                 \
    \       l++;\n                    }\n                }\n                return\
    \ l - sz;\n            }\n            sm = U::op11(sm, reflect(l));\n        \
    \    push(l);\n            l++;\n        } while ((l & -l) != l);\n        return\
    \ _n;\n    }\n\n    // G: T1->bool\n    // find min l s.t. f([l, r)) = true\n\
    \    // ABC389F, ABC371F\n    template <class G>\n    int min_left(int r, G g)\
    \ {\n        if (r == 0) return 0;\n        r += sz;\n        propagate(r - 1);\n\
    \n        T1 sm = U::id1();\n        do {\n            r--;\n            while\
    \ (r > 1 && (r % 2)) r >>= 1;\n            if (!g(U::op11(reflect(r), sm))) {\n\
    \                while (r < sz) {\n                    push(r);\n            \
    \        r = (2 * r + 1);\n                    if (g(U::op11(reflect(r), sm)))\
    \ {\n                        sm = U::op11(reflect(r), sm);\n                 \
    \       r--;\n                    }\n                }\n                return\
    \ r + 1 - sz;\n            }\n            sm = U::op11(reflect(r), sm);\n    \
    \    } while ((r & -r) != r);\n        return 0;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/data_structure/LazySegmentTree.hpp
  requiredBy: []
  timestamp: '2026-01-01 00:55:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/data_structure/LazySegmentTree.hpp
layout: document
redirect_from:
- /library/cpp_src/data_structure/LazySegmentTree.hpp
- /library/cpp_src/data_structure/LazySegmentTree.hpp.html
title: cpp_src/data_structure/LazySegmentTree.hpp
---
