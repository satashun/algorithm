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
  bundledCode: "#line 1 \"cpp_src/other/Mo.hpp\"\nstruct Mo {\n\tV<int> left, right,\
    \ order;\n\tV<bool> v;\n\tint Bsize, nl, nr, ptr;\n\n\tMo(int n) : Bsize((int)sqrt(n+1)),\
    \ nl(0), nr(0), ptr(0), v(n) {}\n\n\t//[l, r)\n\tvoid insert(int l, int r) {\n\
    \t\tleft.push_back(l);\n\t\tright.push_back(r);\n\t}\n\n\tvoid build() {\n\t\t\
    order.resize(left.size());\n\t\tiota(order.begin(), order.end(), 0);\n\t\tsort(order.begin(),\
    \ order.end(), [&](int a, int b) {\n\t\t\tif (left[a] / Bsize != left[b] / Bsize)\
    \ return left[a] < left[b];\n\t\t\telse return right[a] < right[b];\n\t\t});\n\
    \t}\n\n\t//return next event id\n\tint proceed() {\n\t\tif (ptr == order.size())\
    \ return -1;\n\t\tint id = order[ptr];\n\t\twhile (nl > left[id]) query(--nl);\n\
    \t\twhile (nr < right[id]) query(nr++);\n\t\twhile (nl < left[id]) query(nl++);\n\
    \t\twhile (nr > right[id]) query(--nr);\n\t\treturn (order[ptr++]);\n\t}\n\n\t\
    void query(int p) {\n\t\tv[p] = !v[p];\n\t\tif (v[p]) add(p);\n\t\telse del(p);\n\
    \t}\n\n\tvoid add(int p) {\n\t}\n\n\tvoid del(int p) {\n\t}\n};\n"
  code: "struct Mo {\n\tV<int> left, right, order;\n\tV<bool> v;\n\tint Bsize, nl,\
    \ nr, ptr;\n\n\tMo(int n) : Bsize((int)sqrt(n+1)), nl(0), nr(0), ptr(0), v(n)\
    \ {}\n\n\t//[l, r)\n\tvoid insert(int l, int r) {\n\t\tleft.push_back(l);\n\t\t\
    right.push_back(r);\n\t}\n\n\tvoid build() {\n\t\torder.resize(left.size());\n\
    \t\tiota(order.begin(), order.end(), 0);\n\t\tsort(order.begin(), order.end(),\
    \ [&](int a, int b) {\n\t\t\tif (left[a] / Bsize != left[b] / Bsize) return left[a]\
    \ < left[b];\n\t\t\telse return right[a] < right[b];\n\t\t});\n\t}\n\n\t//return\
    \ next event id\n\tint proceed() {\n\t\tif (ptr == order.size()) return -1;\n\t\
    \tint id = order[ptr];\n\t\twhile (nl > left[id]) query(--nl);\n\t\twhile (nr\
    \ < right[id]) query(nr++);\n\t\twhile (nl < left[id]) query(nl++);\n\t\twhile\
    \ (nr > right[id]) query(--nr);\n\t\treturn (order[ptr++]);\n\t}\n\n\tvoid query(int\
    \ p) {\n\t\tv[p] = !v[p];\n\t\tif (v[p]) add(p);\n\t\telse del(p);\n\t}\n\n\t\
    void add(int p) {\n\t}\n\n\tvoid del(int p) {\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/other/Mo.hpp
  requiredBy: []
  timestamp: '2020-03-27 19:07:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/other/Mo.hpp
layout: document
redirect_from:
- /library/cpp_src/other/Mo.hpp
- /library/cpp_src/other/Mo.hpp.html
title: cpp_src/other/Mo.hpp
---
