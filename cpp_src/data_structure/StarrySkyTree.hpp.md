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
  bundledCode: "#line 1 \"cpp_src/data_structure/StarrySkyTree.hpp\"\nstruct starry_sky_tree\
    \ {\n    const int inf = -1e9;\n    V<int> all, ma;\n    int sz;\n\n    void init(int\
    \ n) {\n        sz = 1;\n        while (sz < n) sz *= 2;\n        all.resize(sz\
    \ * 2);\n        ma.resize(sz * 2);\n    }\n\n    void add(int a, int b, int x,\
    \ int k, int l, int r) {\n        if (b <= l || r <= a) return;\n        if (a\
    \ <= l && r <= b) {\n            all[k] += x;\n            return;\n        }\n\
    \n        add(a, b, x, k * 2 + 1, l, (l + r) / 2);\n        add(a, b, x, k * 2\
    \ + 2, (l + r) / 2, r);\n        ma[k] =\n            max(ma[k * 2 + 1] + all[k\
    \ * 2 + 1], ma[k * 2 + 2] + all[k * 2 + 2]);\n    }\n\n    int get(int a, int\
    \ b, int k, int l, int r) {\n        if (b <= l || r <= a) return inf;\n     \
    \   if (a <= l && r <= b) {\n            return ma[k] + all[k];\n        }\n\n\
    \        int lc = get(a, b, k * 2 + 1, l, (l + r) / 2);\n        int rc = get(a,\
    \ b, k * 2 + 2, (l + r) / 2, r);\n        return max(lc, rc) + all[k];\n    }\n\
    \n    int get() { return ma[0] + all[0]; }\n} seg;\n\nint sz;\nconst int INF =\
    \ TEN(9);\n\nstruct starry_sky_tree {\n    int all[1<<19], ma[1<<19], cnt[1<<19];\n\
    \n    void init(int n) {\n        sz = 1;\n        while (sz < n) sz *= 2;\n \
    \       rep(i, sz * 2) {\n            all[i] = 0;\n            ma[i] = 0;\n  \
    \          cnt[i] = 0;\n        }\n        for (int i = sz - 1; i < sz * 2 - 1;\
    \ ++i) {\n            cnt[i] = 1;\n        }\n        for (int i = sz - 1 + n;\
    \ i < sz * 2 - 1; ++i) {\n            ma[i] = INF;\n        }\n        for (int\
    \ i = sz - 2; i >= 0; --i) {\n            ma[i] = min(ma[i * 2 + 1], ma[i * 2\
    \ + 2]);\n            cnt[i] = 0;\n            if (ma[i] == ma[i * 2 + 1]) {\n\
    \                cnt[i] += cnt[i * 2 + 1];\n            }\n            if (ma[i]\
    \ == ma[i * 2 + 2]) {\n                cnt[i] += cnt[i * 2 + 2];\n           \
    \ }           \n        }\n    }\n\n    void add(int a, int b, int x, int k, int\
    \ l, int r) {\n        if (b <= l || r <= a) return ;\n        if (a <= l && r\
    \ <= b) {\n            all[k] += x; return ; \n        }\n\n        add(a, b,\
    \ x, k * 2 + 1, l, (l + r) / 2);\n        add(a, b, x, k * 2 + 2, (l + r) / 2,\
    \ r);\n        ma[k] = min(ma[k * 2 + 1] + all[k * 2 + 1], ma[k * 2 + 2] + all[k\
    \ * 2 + 2]);\n        cnt[k] = 0;\n        if (ma[k] == ma[k * 2 + 1] + all[k\
    \ * 2 + 1]) {\n            cnt[k] += cnt[k * 2 + 1];\n        }\n        if (ma[k]\
    \ == ma[k * 2 + 2] + all[k * 2 + 2]) {\n            cnt[k] += cnt[k * 2 + 2];\n\
    \        }        \n    }\n\n    pii get(int a, int b, int k, int l, int r) {\n\
    \        if (b <= l || r <= a) return mp(INF, 0);\n        if (a <= l && r <=\
    \ b) {\n            return mp(ma[k] + all[k], cnt[k]);\n        }\n\n        pii\
    \ lc = get(a, b, k * 2 + 1, l, (l + r) / 2);\n        pii rc = get(a, b, k * 2\
    \ + 2, (l + r) / 2, r);\n        int num = 0;\n        int mini = min(lc.fi, rc.fi);\n\
    \        if (mini == lc.fi) {\n            num += lc.se;\n        }\n        if\
    \ (mini == rc.fi) {\n            num += rc.se;\n        }\n        return mp(mini\
    \ + all[k], num);\n    }\n} seg;\n"
  code: "struct starry_sky_tree {\n    const int inf = -1e9;\n    V<int> all, ma;\n\
    \    int sz;\n\n    void init(int n) {\n        sz = 1;\n        while (sz < n)\
    \ sz *= 2;\n        all.resize(sz * 2);\n        ma.resize(sz * 2);\n    }\n\n\
    \    void add(int a, int b, int x, int k, int l, int r) {\n        if (b <= l\
    \ || r <= a) return;\n        if (a <= l && r <= b) {\n            all[k] += x;\n\
    \            return;\n        }\n\n        add(a, b, x, k * 2 + 1, l, (l + r)\
    \ / 2);\n        add(a, b, x, k * 2 + 2, (l + r) / 2, r);\n        ma[k] =\n \
    \           max(ma[k * 2 + 1] + all[k * 2 + 1], ma[k * 2 + 2] + all[k * 2 + 2]);\n\
    \    }\n\n    int get(int a, int b, int k, int l, int r) {\n        if (b <= l\
    \ || r <= a) return inf;\n        if (a <= l && r <= b) {\n            return\
    \ ma[k] + all[k];\n        }\n\n        int lc = get(a, b, k * 2 + 1, l, (l +\
    \ r) / 2);\n        int rc = get(a, b, k * 2 + 2, (l + r) / 2, r);\n        return\
    \ max(lc, rc) + all[k];\n    }\n\n    int get() { return ma[0] + all[0]; }\n}\
    \ seg;\n\nint sz;\nconst int INF = TEN(9);\n\nstruct starry_sky_tree {\n    int\
    \ all[1<<19], ma[1<<19], cnt[1<<19];\n\n    void init(int n) {\n        sz = 1;\n\
    \        while (sz < n) sz *= 2;\n        rep(i, sz * 2) {\n            all[i]\
    \ = 0;\n            ma[i] = 0;\n            cnt[i] = 0;\n        }\n        for\
    \ (int i = sz - 1; i < sz * 2 - 1; ++i) {\n            cnt[i] = 1;\n        }\n\
    \        for (int i = sz - 1 + n; i < sz * 2 - 1; ++i) {\n            ma[i] =\
    \ INF;\n        }\n        for (int i = sz - 2; i >= 0; --i) {\n            ma[i]\
    \ = min(ma[i * 2 + 1], ma[i * 2 + 2]);\n            cnt[i] = 0;\n            if\
    \ (ma[i] == ma[i * 2 + 1]) {\n                cnt[i] += cnt[i * 2 + 1];\n    \
    \        }\n            if (ma[i] == ma[i * 2 + 2]) {\n                cnt[i]\
    \ += cnt[i * 2 + 2];\n            }           \n        }\n    }\n\n    void add(int\
    \ a, int b, int x, int k, int l, int r) {\n        if (b <= l || r <= a) return\
    \ ;\n        if (a <= l && r <= b) {\n            all[k] += x; return ; \n   \
    \     }\n\n        add(a, b, x, k * 2 + 1, l, (l + r) / 2);\n        add(a, b,\
    \ x, k * 2 + 2, (l + r) / 2, r);\n        ma[k] = min(ma[k * 2 + 1] + all[k *\
    \ 2 + 1], ma[k * 2 + 2] + all[k * 2 + 2]);\n        cnt[k] = 0;\n        if (ma[k]\
    \ == ma[k * 2 + 1] + all[k * 2 + 1]) {\n            cnt[k] += cnt[k * 2 + 1];\n\
    \        }\n        if (ma[k] == ma[k * 2 + 2] + all[k * 2 + 2]) {\n         \
    \   cnt[k] += cnt[k * 2 + 2];\n        }        \n    }\n\n    pii get(int a,\
    \ int b, int k, int l, int r) {\n        if (b <= l || r <= a) return mp(INF,\
    \ 0);\n        if (a <= l && r <= b) {\n            return mp(ma[k] + all[k],\
    \ cnt[k]);\n        }\n\n        pii lc = get(a, b, k * 2 + 1, l, (l + r) / 2);\n\
    \        pii rc = get(a, b, k * 2 + 2, (l + r) / 2, r);\n        int num = 0;\n\
    \        int mini = min(lc.fi, rc.fi);\n        if (mini == lc.fi) {\n       \
    \     num += lc.se;\n        }\n        if (mini == rc.fi) {\n            num\
    \ += rc.se;\n        }\n        return mp(mini + all[k], num);\n    }\n} seg;"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/data_structure/StarrySkyTree.hpp
  requiredBy: []
  timestamp: '2021-02-05 11:44:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/data_structure/StarrySkyTree.hpp
layout: document
redirect_from:
- /library/cpp_src/data_structure/StarrySkyTree.hpp
- /library/cpp_src/data_structure/StarrySkyTree.hpp.html
title: cpp_src/data_structure/StarrySkyTree.hpp
---
