---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/data_structure/WeightedUnion.cpp\"\nstruct weighted_union\
    \ {\n    // i2g[i] := \u30A2\u30A4\u30C6\u30E0 i \u306E\u6240\u5C5E\u3059\u308B\
    \u30B0\u30EB\u30FC\u30D7\u306E\u756A\u53F7\n    // g2i[g] := \u30B0\u30EB\u30FC\
    \u30D7 g \u306B\u6240\u5C5E\u3059\u308B\u30A2\u30A4\u30C6\u30E0\u305F\u3061\n\n\
    \    vector<int> i2g;\n    vector<vector<int>> g2i;\n\n    void init(int n) {\n\
    \        i2g.resize(n);\n        g2i.resize(n);\n        gg.resize(n);\n     \
    \   for (int i = 0; i < n; ++i) {\n            i2g[i] = i;\n            g2i[i].assign(1,\
    \ i);\n        }\n    }\n\n    int find(int i) { return i2g[i]; }\n\n    void\
    \ merge(int ia, int ib) {\n        if (g2i[i2g[ia]].size() < g2i[i2g[ib]].size())\
    \ {\n            swap(ia, ib);\n        }\n\n        int ga = i2g[ia], gb = i2g[ib];\n\
    \        if (ga == gb) return;\n        for (int j : g2i[gb]) i2g[j] = ga;\n \
    \       g2i[ga].insert(g2i[ga].end(), g2i[gb].begin(), g2i[gb].end());\n     \
    \   g2i[gb].clear();\n    }\n\n    bool is_same_group(int ia, int ib) { return\
    \ i2g[ia] == i2g[ib]; }\n};\n"
  code: "struct weighted_union {\n    // i2g[i] := \u30A2\u30A4\u30C6\u30E0 i \u306E\
    \u6240\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\u306E\u756A\u53F7\n    // g2i[g]\
    \ := \u30B0\u30EB\u30FC\u30D7 g \u306B\u6240\u5C5E\u3059\u308B\u30A2\u30A4\u30C6\
    \u30E0\u305F\u3061\n\n    vector<int> i2g;\n    vector<vector<int>> g2i;\n\n \
    \   void init(int n) {\n        i2g.resize(n);\n        g2i.resize(n);\n     \
    \   gg.resize(n);\n        for (int i = 0; i < n; ++i) {\n            i2g[i] =\
    \ i;\n            g2i[i].assign(1, i);\n        }\n    }\n\n    int find(int i)\
    \ { return i2g[i]; }\n\n    void merge(int ia, int ib) {\n        if (g2i[i2g[ia]].size()\
    \ < g2i[i2g[ib]].size()) {\n            swap(ia, ib);\n        }\n\n        int\
    \ ga = i2g[ia], gb = i2g[ib];\n        if (ga == gb) return;\n        for (int\
    \ j : g2i[gb]) i2g[j] = ga;\n        g2i[ga].insert(g2i[ga].end(), g2i[gb].begin(),\
    \ g2i[gb].end());\n        g2i[gb].clear();\n    }\n\n    bool is_same_group(int\
    \ ia, int ib) { return i2g[ia] == i2g[ib]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/data_structure/WeightedUnion.cpp
  requiredBy: []
  timestamp: '2022-08-15 00:42:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/data_structure/WeightedUnion.cpp
layout: document
redirect_from:
- /library/cpp_src/data_structure/WeightedUnion.cpp
- /library/cpp_src/data_structure/WeightedUnion.cpp.html
title: cpp_src/data_structure/WeightedUnion.cpp
---
