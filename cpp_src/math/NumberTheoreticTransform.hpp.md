---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/ntt.md
    links: []
  bundledCode: "#line 1 \"cpp_src/math/NumberTheoreticTransform.hpp\"\n/**\n * @docs\
    \ docs/ntt.md\n */\n\ntemplate <class D>\nstruct NumberTheoreticTransform {\n\
    \    D root;\n    V<D> roots = {0, 1};\n    V<int> rev = {0, 1};\n    int base\
    \ = 1, max_base = -1;\n\n    void init() {\n        int mod = D::get_mod();\n\
    \        int tmp = mod - 1;\n        max_base = 0;\n        while (tmp % 2 ==\
    \ 0) {\n            tmp /= 2;\n            max_base++;\n        }\n\n        root\
    \ = 2;\n\n        while (true) {\n            if (root.pow(1 << max_base).v ==\
    \ 1) {\n                if (root.pow(1 << (max_base - 1)).v != 1) {\n        \
    \            break;\n                }\n            }\n            root++;\n \
    \       }\n    }\n\n    void ensure_base(int nbase) {\n        if (max_base ==\
    \ -1) init();\n        if (nbase <= base) return;\n        assert(nbase <= max_base);\n\
    \n        rev.resize(1 << nbase);\n        for (int i = 0; i < (1 << nbase); ++i)\
    \ {\n            rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));\n   \
    \     }\n        roots.resize(1 << nbase);\n\n        while (base < nbase) {\n\
    \            D z = root.pow(1 << (max_base - 1 - base));\n            for (int\
    \ i = 1 << (base - 1); i < (1 << base); ++i) {\n                roots[i << 1]\
    \ = roots[i];\n                roots[(i << 1) + 1] = roots[i] * z;\n         \
    \   }\n            ++base;\n        }\n    }\n\n    void ntt(V<D>& a, bool inv\
    \ = false) {\n        int n = a.size();\n        // assert((n & (n - 1)) == 0);\n\
    \        int zeros = __builtin_ctz(n);\n        ensure_base(zeros);\n        int\
    \ shift = base - zeros;\n\n        for (int i = 0; i < n; i++) {\n           \
    \ if (i < (rev[i] >> shift)) {\n                swap(a[i], a[rev[i] >> shift]);\n\
    \            }\n        }\n\n        for (int k = 1; k < n; k <<= 1) {\n     \
    \       for (int i = 0; i < n; i += 2 * k) {\n                for (int j = 0;\
    \ j < k; j++) {\n                    D x = a[i + j];\n                    D y\
    \ = a[i + j + k] * roots[j + k];\n                    a[i + j] = x + y;\n    \
    \                a[i + j + k] = x - y;\n                }\n            }\n   \
    \     }\n\n        int v = D(n).inv().v;\n        if (inv) {\n            reverse(a.begin()\
    \ + 1, a.end());\n            for (int i = 0; i < n; i++) {\n                a[i]\
    \ *= v;\n            }\n        }\n    }\n\n    V<D> mul(V<D> a, V<D> b) {\n \
    \       if (a.size() == 0 && b.size() == 0) return {};\n        int s = a.size()\
    \ + b.size() - 1;\n        int nbase = 1;\n        while ((1 << nbase) < s) nbase++;\n\
    \        int sz = 1 << nbase;\n\n        if (sz <= 16) {\n            V<D> ret(s);\n\
    \            for (int i = 0; i < a.size(); i++) {\n                for (int j\
    \ = 0; j < b.size(); j++) ret[i + j] += a[i] * b[j];\n            }\n        \
    \    return ret;\n        }\n\n        a.resize(sz);\n        b.resize(sz);\n\
    \        ntt(a);\n        ntt(b);\n\n        for (int i = 0; i < sz; i++) {\n\
    \            a[i] *= b[i];\n        }\n        ntt(a, true);\n\n        a.resize(s);\n\
    \        return a;\n    }\n};\n\n// T : modint\ntemplate <class T>\nvoid ntt_2d(VV<T>&\
    \ a, bool rev) {\n    if (a.size() == 0 || a[0].size() == 0) return;\n    int\
    \ h = a.size(), w = a[0].size();\n\n    NumberTheoreticTransform<T> fft;\n   \
    \ fft.init();\n\n    for (auto& v : a) {\n        fft.ntt(v, rev);\n    }\n\n\
    \    rep(j, w) {\n        V<T> vh(h);\n        rep(i, h) { vh[i] = a[i][j]; }\n\
    \        fft.ntt(vh, rev);\n        rep(i, h) { a[i][j] = vh[i]; }\n    }\n}\n"
  code: "/**\n * @docs docs/ntt.md\n */\n\ntemplate <class D>\nstruct NumberTheoreticTransform\
    \ {\n    D root;\n    V<D> roots = {0, 1};\n    V<int> rev = {0, 1};\n    int\
    \ base = 1, max_base = -1;\n\n    void init() {\n        int mod = D::get_mod();\n\
    \        int tmp = mod - 1;\n        max_base = 0;\n        while (tmp % 2 ==\
    \ 0) {\n            tmp /= 2;\n            max_base++;\n        }\n\n        root\
    \ = 2;\n\n        while (true) {\n            if (root.pow(1 << max_base).v ==\
    \ 1) {\n                if (root.pow(1 << (max_base - 1)).v != 1) {\n        \
    \            break;\n                }\n            }\n            root++;\n \
    \       }\n    }\n\n    void ensure_base(int nbase) {\n        if (max_base ==\
    \ -1) init();\n        if (nbase <= base) return;\n        assert(nbase <= max_base);\n\
    \n        rev.resize(1 << nbase);\n        for (int i = 0; i < (1 << nbase); ++i)\
    \ {\n            rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));\n   \
    \     }\n        roots.resize(1 << nbase);\n\n        while (base < nbase) {\n\
    \            D z = root.pow(1 << (max_base - 1 - base));\n            for (int\
    \ i = 1 << (base - 1); i < (1 << base); ++i) {\n                roots[i << 1]\
    \ = roots[i];\n                roots[(i << 1) + 1] = roots[i] * z;\n         \
    \   }\n            ++base;\n        }\n    }\n\n    void ntt(V<D>& a, bool inv\
    \ = false) {\n        int n = a.size();\n        // assert((n & (n - 1)) == 0);\n\
    \        int zeros = __builtin_ctz(n);\n        ensure_base(zeros);\n        int\
    \ shift = base - zeros;\n\n        for (int i = 0; i < n; i++) {\n           \
    \ if (i < (rev[i] >> shift)) {\n                swap(a[i], a[rev[i] >> shift]);\n\
    \            }\n        }\n\n        for (int k = 1; k < n; k <<= 1) {\n     \
    \       for (int i = 0; i < n; i += 2 * k) {\n                for (int j = 0;\
    \ j < k; j++) {\n                    D x = a[i + j];\n                    D y\
    \ = a[i + j + k] * roots[j + k];\n                    a[i + j] = x + y;\n    \
    \                a[i + j + k] = x - y;\n                }\n            }\n   \
    \     }\n\n        int v = D(n).inv().v;\n        if (inv) {\n            reverse(a.begin()\
    \ + 1, a.end());\n            for (int i = 0; i < n; i++) {\n                a[i]\
    \ *= v;\n            }\n        }\n    }\n\n    V<D> mul(V<D> a, V<D> b) {\n \
    \       if (a.size() == 0 && b.size() == 0) return {};\n        int s = a.size()\
    \ + b.size() - 1;\n        int nbase = 1;\n        while ((1 << nbase) < s) nbase++;\n\
    \        int sz = 1 << nbase;\n\n        if (sz <= 16) {\n            V<D> ret(s);\n\
    \            for (int i = 0; i < a.size(); i++) {\n                for (int j\
    \ = 0; j < b.size(); j++) ret[i + j] += a[i] * b[j];\n            }\n        \
    \    return ret;\n        }\n\n        a.resize(sz);\n        b.resize(sz);\n\
    \        ntt(a);\n        ntt(b);\n\n        for (int i = 0; i < sz; i++) {\n\
    \            a[i] *= b[i];\n        }\n        ntt(a, true);\n\n        a.resize(s);\n\
    \        return a;\n    }\n};\n\n// T : modint\ntemplate <class T>\nvoid ntt_2d(VV<T>&\
    \ a, bool rev) {\n    if (a.size() == 0 || a[0].size() == 0) return;\n    int\
    \ h = a.size(), w = a[0].size();\n\n    NumberTheoreticTransform<T> fft;\n   \
    \ fft.init();\n\n    for (auto& v : a) {\n        fft.ntt(v, rev);\n    }\n\n\
    \    rep(j, w) {\n        V<T> vh(h);\n        rep(i, h) { vh[i] = a[i][j]; }\n\
    \        fft.ntt(vh, rev);\n        rep(i, h) { a[i][j] = vh[i]; }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/math/NumberTheoreticTransform.hpp
  requiredBy: []
  timestamp: '2022-01-02 16:22:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/math/NumberTheoreticTransform.hpp
layout: document
redirect_from:
- /library/cpp_src/math/NumberTheoreticTransform.hpp
- /library/cpp_src/math/NumberTheoreticTransform.hpp.html
title: cpp_src/math/NumberTheoreticTransform.hpp
---
## 前提
- $p - 1$ が十分大きい $2$ べきで割り切れる場合に $\mod p$ で積を計算する
- modint ライブラリと併用する

## 例題

2D NTT

- https://yukicoder.me/problems/no/1241

- https://atcoder.jp/contests/jag2013spring/tasks/icpc2013spring_f (まだ)