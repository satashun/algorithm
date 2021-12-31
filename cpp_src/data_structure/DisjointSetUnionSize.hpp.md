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
  bundledCode: "#line 1 \"cpp_src/data_structure/DisjointSetUnionSize.hpp\"\nclass\
    \ unionfind {\n\tvector<int> par, size;\n\npublic:\n\tvoid init(int n) {\n\t\t\
    par.resize(n);\n\t\tsize.resize(n);\n\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\
    \tpar[i] = i;\n\t\t\tsize[i] = 1;\n\t\t}\n\t}\n\n\tint find(int x) {\n\t\tif (par[x]\
    \ == x) return x;\n\t\telse return par[x] = find(par[x]);\n\t}\n\n\tvoid unite(int\
    \ x, int y) {\n\t\tx = find(x);\n\t\ty = find(y);\n\t\tif (x == y) return ;\n\t\
    \tif (size[x] < size[y]) swap(x, y);\n\n\t\tpar[y] = x;\n\t\tsize[x] += size[y];\n\
    \t}\n\n\tbool same(int x, int y) { return (find(x) == find(y)); }\n\tint get_size(int\
    \ x) { return size[find(x)]; }\n\n};\n"
  code: "class unionfind {\n\tvector<int> par, size;\n\npublic:\n\tvoid init(int n)\
    \ {\n\t\tpar.resize(n);\n\t\tsize.resize(n);\n\n\t\tfor (int i = 0; i < n; i++)\
    \ {\n\t\t\tpar[i] = i;\n\t\t\tsize[i] = 1;\n\t\t}\n\t}\n\n\tint find(int x) {\n\
    \t\tif (par[x] == x) return x;\n\t\telse return par[x] = find(par[x]);\n\t}\n\n\
    \tvoid unite(int x, int y) {\n\t\tx = find(x);\n\t\ty = find(y);\n\t\tif (x ==\
    \ y) return ;\n\t\tif (size[x] < size[y]) swap(x, y);\n\n\t\tpar[y] = x;\n\t\t\
    size[x] += size[y];\n\t}\n\n\tbool same(int x, int y) { return (find(x) == find(y));\
    \ }\n\tint get_size(int x) { return size[find(x)]; }\n\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/data_structure/DisjointSetUnionSize.hpp
  requiredBy: []
  timestamp: '2022-01-01 02:21:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/data_structure/DisjointSetUnionSize.hpp
layout: document
redirect_from:
- /library/cpp_src/data_structure/DisjointSetUnionSize.hpp
- /library/cpp_src/data_structure/DisjointSetUnionSize.hpp.html
title: cpp_src/data_structure/DisjointSetUnionSize.hpp
---
