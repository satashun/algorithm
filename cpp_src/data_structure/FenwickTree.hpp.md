---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0343.test.cpp
    title: test/aoj/0343.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_add_range_sum.test.cpp
    title: test/yosupo/point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/data_structure/FenwickTree.hpp\"\ntemplate<class\
    \ T>\nstruct BIT {\n\tint n;\n\tvector<T> bit;\n\n\tBIT(int _n = 0) : n(_n), bit(n\
    \ + 1) {}\n\n\t//sum of [0, i), 0 <= i <= n\n\tT sum(int i) {\n\t\tT s = 0;\n\t\
    \twhile (i > 0) {\n\t\t\ts += bit[i];\n\t\t\ti -= i & -i;\n\t\t}\n\t\treturn s;\n\
    \t}\n\n\t//0 <= i < n\n\tvoid add(int i, T x) {\n\t\t++i;\n\t\twhile (i <= n)\
    \ {\n\t\t\tbit[i] += x;\n\t\t\ti += i & -i;\n\t\t}\n\t}\n\n\t//[l, r) 0 <= l <\
    \ r < n\n\tT sum(int l, int r) {\n\t\treturn sum(r) - sum(l);\n\t}\n\n\t// verify!!!!\n\
    \t//smallest i, sum(i) >= w, none -> n + 1\n\tint lower_bound(T w) {\n\t\tif (w\
    \ <= 0) return 0;\n\t\tint x = 0, l = 1;\n\t\twhile (l * 2 <= n) l *= 2;\n\n\t\
    \tfor (int k = l; k > 0; k /= 2) {\n\t\t\tif (x + k <= n && bit[x + k] < w) {\n\
    \t\t\t\tw -= bit[x + k];\n\t\t\t\tx += k;\n\t\t\t}\n\t\t}\n\t\treturn x + 1;\n\
    \t}\n};\n"
  code: "template<class T>\nstruct BIT {\n\tint n;\n\tvector<T> bit;\n\n\tBIT(int\
    \ _n = 0) : n(_n), bit(n + 1) {}\n\n\t//sum of [0, i), 0 <= i <= n\n\tT sum(int\
    \ i) {\n\t\tT s = 0;\n\t\twhile (i > 0) {\n\t\t\ts += bit[i];\n\t\t\ti -= i &\
    \ -i;\n\t\t}\n\t\treturn s;\n\t}\n\n\t//0 <= i < n\n\tvoid add(int i, T x) {\n\
    \t\t++i;\n\t\twhile (i <= n) {\n\t\t\tbit[i] += x;\n\t\t\ti += i & -i;\n\t\t}\n\
    \t}\n\n\t//[l, r) 0 <= l < r < n\n\tT sum(int l, int r) {\n\t\treturn sum(r) -\
    \ sum(l);\n\t}\n\n\t// verify!!!!\n\t//smallest i, sum(i) >= w, none -> n + 1\n\
    \tint lower_bound(T w) {\n\t\tif (w <= 0) return 0;\n\t\tint x = 0, l = 1;\n\t\
    \twhile (l * 2 <= n) l *= 2;\n\n\t\tfor (int k = l; k > 0; k /= 2) {\n\t\t\tif\
    \ (x + k <= n && bit[x + k] < w) {\n\t\t\t\tw -= bit[x + k];\n\t\t\t\tx += k;\n\
    \t\t\t}\n\t\t}\n\t\treturn x + 1;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/data_structure/FenwickTree.hpp
  requiredBy: []
  timestamp: '2021-12-30 18:51:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/point_add_range_sum.test.cpp
  - test/aoj/0343.test.cpp
documentation_of: cpp_src/data_structure/FenwickTree.hpp
layout: document
redirect_from:
- /library/cpp_src/data_structure/FenwickTree.hpp
- /library/cpp_src/data_structure/FenwickTree.hpp.html
title: cpp_src/data_structure/FenwickTree.hpp
---
