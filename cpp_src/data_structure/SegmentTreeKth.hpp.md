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
  bundledCode: "#line 1 \"cpp_src/data_structure/SegmentTreeKth.hpp\"\ntemplate <class\
    \ T>\nclass segtree {\n   public:\n    VV<T> dat;\n    int sz;\n\n    segtree()\
    \ = default;\n\n    void init(const vector<T>& vec) {\n        for (sz = 1; sz\
    \ < (int)vec.size(); sz *= 2)\n            ;\n        dat.resize(sz * 2);\n\n\
    \        rep(i, sz * 2) { dat[i].clear(); }\n\n        rep(i, vec.size()) { dat[sz\
    \ - 1 + i].pb(vec[i]); }\n\n        for (int i = sz - 2; i >= 0; --i) {\n    \
    \        int lc = i * 2 + 1, rc = i * 2 + 2;\n            dat[i].resize(dat[lc].size()\
    \ + dat[rc].size());\n            merge(dat[lc].begin(), dat[lc].end(), dat[rc].begin(),\n\
    \                  dat[rc].end(), dat[i].begin());\n        }\n    }\n\n    int\
    \ ask(int a, int b, T t, int k, int l, int r) {\n        if (b <= l || r <= a)\
    \ return 0;\n        if (a <= l && r <= b) {\n            return lower_bound(ALL(dat[k]),\
    \ t) - dat[k].begin();\n        }\n\n        return ask(a, b, t, k * 2 + 1, l,\
    \ (l + r) / 2) +\n               ask(a, b, t, k * 2 + 2, (l + r) / 2, r);\n  \
    \  }\n\n    int ask(int a, int b, T t) { return ask(a, b, t, 0, 0, sz); }\n};\n"
  code: "template <class T>\nclass segtree {\n   public:\n    VV<T> dat;\n    int\
    \ sz;\n\n    segtree() = default;\n\n    void init(const vector<T>& vec) {\n \
    \       for (sz = 1; sz < (int)vec.size(); sz *= 2)\n            ;\n        dat.resize(sz\
    \ * 2);\n\n        rep(i, sz * 2) { dat[i].clear(); }\n\n        rep(i, vec.size())\
    \ { dat[sz - 1 + i].pb(vec[i]); }\n\n        for (int i = sz - 2; i >= 0; --i)\
    \ {\n            int lc = i * 2 + 1, rc = i * 2 + 2;\n            dat[i].resize(dat[lc].size()\
    \ + dat[rc].size());\n            merge(dat[lc].begin(), dat[lc].end(), dat[rc].begin(),\n\
    \                  dat[rc].end(), dat[i].begin());\n        }\n    }\n\n    int\
    \ ask(int a, int b, T t, int k, int l, int r) {\n        if (b <= l || r <= a)\
    \ return 0;\n        if (a <= l && r <= b) {\n            return lower_bound(ALL(dat[k]),\
    \ t) - dat[k].begin();\n        }\n\n        return ask(a, b, t, k * 2 + 1, l,\
    \ (l + r) / 2) +\n               ask(a, b, t, k * 2 + 2, (l + r) / 2, r);\n  \
    \  }\n\n    int ask(int a, int b, T t) { return ask(a, b, t, 0, 0, sz); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/data_structure/SegmentTreeKth.hpp
  requiredBy: []
  timestamp: '2022-01-02 16:22:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/data_structure/SegmentTreeKth.hpp
layout: document
redirect_from:
- /library/cpp_src/data_structure/SegmentTreeKth.hpp
- /library/cpp_src/data_structure/SegmentTreeKth.hpp.html
title: cpp_src/data_structure/SegmentTreeKth.hpp
---
