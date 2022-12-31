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
    - https://atcoder.jp/contests/abc237/submissions/30181965
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 289, in update\n    uncommented_lines = get_uncommented_code(path, iquotes=self.iquotes,\
    \ compiler=self.compiler).splitlines(keepends=True)\n                        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 195, in get_uncommented_code\n    code = _get_uncommented_code(path.resolve(),\
    \ iquotes_options=tuple(iquotes_options), compiler=compiler)\n           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 188, in _get_uncommented_code\n    return subprocess.check_output(command)\n\
    \           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/subprocess.py\"\
    , line 466, in check_output\n    return run(*popenargs, stdout=PIPE, timeout=timeout,\
    \ check=True,\n           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/subprocess.py\"\
    , line 571, in run\n    raise CalledProcessError(retcode, process.args,\nsubprocess.CalledProcessError:\
    \ Command '['g++', '-x', 'c++', '-I', '/home/runner/work/algorithm/algorithm',\
    \ '-fpreprocessed', '-dD', '-E', '/home/runner/work/algorithm/algorithm/cpp_src/data_structure/LazySegmentTree.hpp']'\
    \ returned non-zero exit status 1.\n"
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
    \ 1; --i) {\n            a[i] = U::op11(a[(i << 1) | 0], a[(i << 1) | 1]);\n \
    \       }\n    }\n\n    inline T1 reflect(int k) {\n        return b[k] == U::id2()\
    \ ? a[k] : U::op21(b[k], a[k]);\n    }\n\n    void up(int i) {\n        while\
    \ (i >>= 1) {\n            a[i] = U::op11(reflect((i << 1) | 0), reflect((i <<\
    \ 1) | 1));\n        }\n    }\n\n    void propagate(int p) {\n        for (int\
    \ h = H; h > 0; --h) {\n            int i = p >> h;\n            a[i] = reflect(i);\n\
    \            b[i << 1 | 0] = U::op22(b[i], b[i << 1 | 0]);\n            b[i <<\
    \ 1 | 1] = U::op22(b[i], b[i << 1 | 1]);\n            b[i] = U::id2();\n     \
    \   }\n    }\n\n    void set(int p, T1 x) {\n        p += sz;\n        propagate(p);\n\
    \        a[p] = x;\n        b[p] = U::id2();\n        up(p);\n    }\n\n    T1\
    \ get(int p) {\n        p += sz;\n        propagate(p);\n        return reflect(p);\n\
    \    }\n\n    // action on [p, q)\n    void apply(int p, int q, T2 x) {\n    \
    \    if (p >= q) return;\n        p += sz, q += sz;\n        propagate(p);\n \
    \       propagate(q - 1);\n\n        for (int l = p, r = q; l < r; l >>= 1, r\
    \ >>= 1) {\n            if (l & 1) b[l] = U::op22(x, b[l]), l++;\n           \
    \ if (r & 1) --r, b[r] = U::op22(x, b[r]);\n        }\n        up(p);\n      \
    \  up(q - 1);\n    }\n\n    T1 get(int l, int r) {\n        if (l >= r) return\
    \ U::id1();\n        l += sz, r += sz;\n        propagate(l);\n        propagate(r\
    \ - 1);\n\n        T1 lval = U::id1(), rval = U::id1();\n\n        for (; l <\
    \ r; l >>= 1, r >>= 1) {\n            if (l & 1) lval = U::op11(lval, reflect(l++));\n\
    \            if (r & 1) rval = U::op11(reflect(--r), rval);\n        }\n     \
    \   return U::op11(lval, rval);\n    }\n};\n\n/*\nABC 237 G\nhttps://atcoder.jp/contests/abc237/submissions/30181965\n\
    struct U {\n    // number of 1, all\n    using T1 = pii;\n    using T2 = int;\n\
    \    static T1 id1() { return mp(0, 0); }\n    static T2 id2() { return -1; }\n\
    \    static T1 op11(const T1& a, const T1& b) {\n        return mp(a.fi + b.fi,\
    \ a.se + b.se);\n    }\n\n    static T1 op21(const T2& b, const T1& a) {\n   \
    \     pii res = a;\n        if (b == 0)\n            res.fi = 0;\n        else\
    \ if (b == 1)\n            res.fi = res.se;\n        return res;\n    }\n    //\
    \ a : new!\n    static T2 op22(const T2& a, const T2& b) {\n        if (a == id2())\n\
    \            return b;\n        else\n            return a;\n    }\n};/*"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/data_structure/LazySegmentTree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/data_structure/LazySegmentTree.hpp
layout: document
redirect_from:
- /library/cpp_src/data_structure/LazySegmentTree.hpp
- /library/cpp_src/data_structure/LazySegmentTree.hpp.html
title: cpp_src/data_structure/LazySegmentTree.hpp
---
