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
  bundledCode: "#line 1 \"cpp_src/math/NumberTheoreticTransform.hpp\"\n//depend on\
    \ ModInt, must use NTT friendly mod\n\ntemplate<class D>\nstruct NumberTheoreticTransform\
    \ {\n\tD root;\n\tV<D> roots = {0, 1};\n\tV<int> rev = {0, 1};\n\tint base = 1,\
    \ max_base = -1;\n\n\tvoid init() {\n\t\tint mod = D::get_mod();\n\t\tint tmp\
    \ = mod - 1;\n\t\tmax_base = 0;\n\t\twhile (tmp % 2 == 0) {\n\t\t\ttmp /= 2;\n\
    \t\t\tmax_base++;\n\t\t}\n\n\t\troot = 2;\n\t\t\n\t\twhile (true) {\n\t\t\tif\
    \ (root.pow(1 << max_base).v == 1) {\n\t\t\t\tif (root.pow(1 << (max_base - 1)).v\
    \ != 1) {\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\troot++;\n\t\t}\n\t}\n\n\
    \tvoid ensure_base(int nbase) {\n\t\tif (max_base == -1) init();\n\t\tif (nbase\
    \ <= base) return;\n\t\tassert(nbase <= max_base);\n\n\t\trev.resize(1 << nbase);\n\
    \t\tfor (int i = 0; i < (1 << nbase); ++i) {\n\t\t\trev[i] = (rev[i >> 1] >> 1)\
    \ + ((i & 1) << (nbase - 1));\n\t\t}\n\t\troots.resize(1 << nbase);\n\n\t\twhile\
    \ (base < nbase) {\n\t\t\tD z = root.pow(1 << (max_base - 1 - base));\n\t\t\t\
    for (int i = 1 << (base - 1); i < (1 << base); ++i) {\n\t\t\t\troots[i << 1] =\
    \ roots[i];\n\t\t\t\troots[(i << 1) + 1] = roots[i] * z;\n\t\t\t}\n\t\t\t++base;\n\
    \t\t}\n\t}\n\n\tvoid ntt(V<D> &a, bool inv = false) {\n\t\tint n = a.size();\n\
    \      //assert((n & (n - 1)) == 0);\n\t\tint zeros = __builtin_ctz(n);\n\t\t\
    ensure_base(zeros);\n\t\tint shift = base - zeros;\n\n\t\tfor (int i = 0; i <\
    \ n; i++) {\n\t\t\tif (i < (rev[i] >> shift)) {\n\t\t\t\tswap(a[i], a[rev[i] >>\
    \ shift]);\n\t\t\t}\n\t\t}\n\n\t\tfor (int k = 1; k < n; k <<= 1) {\n\t\t\tfor\
    \ (int i = 0; i < n; i += 2 * k) {\n\t\t\t\tfor (int j = 0; j < k; j++) {\n\t\t\
    \t\t\tD x = a[i + j];\n\t\t\t\t\tD y = a[i + j + k] * roots[j + k];\n\t\t\t\t\t\
    a[i + j] = x + y;\n\t\t\t\t\ta[i + j + k] = x - y;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\
    \n\t\tint v = D(n).inv().v;\n\t\tif (inv) {\n\t\t\treverse(a.begin() + 1, a.end());\n\
    \t\t\tfor (int i = 0; i < n; i++) {\n\t\t\t\ta[i] *= v;\n\t\t\t}\n\t\t}\n\t}\n\
    \n\tV<D> mul(V<D> a, V<D> b) {\n\t\tif (a.size() == 0 && b.size() == 0) return\
    \ {};\n\t\tint s = a.size() + b.size() - 1;\n\t\tint nbase = 1;\n\t\twhile ((1\
    \ << nbase) < s) nbase++;\n\t\tint sz = 1 << nbase;\n\t\ta.resize(sz);\n\t\tb.resize(sz);\n\
    \t\tntt(a);\n\t\tntt(b);\n\n\t\tfor (int i = 0; i < sz; i++) {\n\t\t\ta[i] *=\
    \ b[i];\n\t\t}\n\t\tntt(a, true);\n\n\t\ta.resize(s);\n\t\treturn a;\n\t}\n};\n"
  code: "//depend on ModInt, must use NTT friendly mod\n\ntemplate<class D>\nstruct\
    \ NumberTheoreticTransform {\n\tD root;\n\tV<D> roots = {0, 1};\n\tV<int> rev\
    \ = {0, 1};\n\tint base = 1, max_base = -1;\n\n\tvoid init() {\n\t\tint mod =\
    \ D::get_mod();\n\t\tint tmp = mod - 1;\n\t\tmax_base = 0;\n\t\twhile (tmp % 2\
    \ == 0) {\n\t\t\ttmp /= 2;\n\t\t\tmax_base++;\n\t\t}\n\n\t\troot = 2;\n\t\t\n\t\
    \twhile (true) {\n\t\t\tif (root.pow(1 << max_base).v == 1) {\n\t\t\t\tif (root.pow(1\
    \ << (max_base - 1)).v != 1) {\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\troot++;\n\
    \t\t}\n\t}\n\n\tvoid ensure_base(int nbase) {\n\t\tif (max_base == -1) init();\n\
    \t\tif (nbase <= base) return;\n\t\tassert(nbase <= max_base);\n\n\t\trev.resize(1\
    \ << nbase);\n\t\tfor (int i = 0; i < (1 << nbase); ++i) {\n\t\t\trev[i] = (rev[i\
    \ >> 1] >> 1) + ((i & 1) << (nbase - 1));\n\t\t}\n\t\troots.resize(1 << nbase);\n\
    \n\t\twhile (base < nbase) {\n\t\t\tD z = root.pow(1 << (max_base - 1 - base));\n\
    \t\t\tfor (int i = 1 << (base - 1); i < (1 << base); ++i) {\n\t\t\t\troots[i <<\
    \ 1] = roots[i];\n\t\t\t\troots[(i << 1) + 1] = roots[i] * z;\n\t\t\t}\n\t\t\t\
    ++base;\n\t\t}\n\t}\n\n\tvoid ntt(V<D> &a, bool inv = false) {\n\t\tint n = a.size();\n\
    \      //assert((n & (n - 1)) == 0);\n\t\tint zeros = __builtin_ctz(n);\n\t\t\
    ensure_base(zeros);\n\t\tint shift = base - zeros;\n\n\t\tfor (int i = 0; i <\
    \ n; i++) {\n\t\t\tif (i < (rev[i] >> shift)) {\n\t\t\t\tswap(a[i], a[rev[i] >>\
    \ shift]);\n\t\t\t}\n\t\t}\n\n\t\tfor (int k = 1; k < n; k <<= 1) {\n\t\t\tfor\
    \ (int i = 0; i < n; i += 2 * k) {\n\t\t\t\tfor (int j = 0; j < k; j++) {\n\t\t\
    \t\t\tD x = a[i + j];\n\t\t\t\t\tD y = a[i + j + k] * roots[j + k];\n\t\t\t\t\t\
    a[i + j] = x + y;\n\t\t\t\t\ta[i + j + k] = x - y;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\
    \n\t\tint v = D(n).inv().v;\n\t\tif (inv) {\n\t\t\treverse(a.begin() + 1, a.end());\n\
    \t\t\tfor (int i = 0; i < n; i++) {\n\t\t\t\ta[i] *= v;\n\t\t\t}\n\t\t}\n\t}\n\
    \n\tV<D> mul(V<D> a, V<D> b) {\n\t\tif (a.size() == 0 && b.size() == 0) return\
    \ {};\n\t\tint s = a.size() + b.size() - 1;\n\t\tint nbase = 1;\n\t\twhile ((1\
    \ << nbase) < s) nbase++;\n\t\tint sz = 1 << nbase;\n\t\ta.resize(sz);\n\t\tb.resize(sz);\n\
    \t\tntt(a);\n\t\tntt(b);\n\n\t\tfor (int i = 0; i < sz; i++) {\n\t\t\ta[i] *=\
    \ b[i];\n\t\t}\n\t\tntt(a, true);\n\n\t\ta.resize(s);\n\t\treturn a;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/math/NumberTheoreticTransform.hpp
  requiredBy: []
  timestamp: '2021-02-05 11:44:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/math/NumberTheoreticTransform.hpp
layout: document
redirect_from:
- /library/cpp_src/math/NumberTheoreticTransform.hpp
- /library/cpp_src/math/NumberTheoreticTransform.hpp.html
title: cpp_src/math/NumberTheoreticTransform.hpp
---
