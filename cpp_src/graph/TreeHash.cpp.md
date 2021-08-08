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
  bundledCode: "#line 1 \"cpp_src/graph/TreeHash.cpp\"\nclass tree_hash {\n   public:\n\
    \    using u128 = __uint128_t;\n    using u64 = uint64_t;\n\n    static const\
    \ u64 mod = (1ull << 61ull) - 1;\n\n    static inline u64 add(u64 a, u64 b) {\n\
    \        if ((a += b) >= mod) a -= mod;\n        return a;\n    }\n\n    static\
    \ inline u64 mul(u64 a, u64 b) {\n        u128 c = (u128)a * b;\n        return\
    \ add(c >> 61, c & mod);\n    }\n\n    vector<u64> hs;\n    vector<u64> rnum;\n\
    \    const int N;\n    vector<vector<int>> G;\n\n    tree_hash(int N) : N(N),\
    \ G(N), hs(N) {\n        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \        uniform_int_distribution<u64> rand(1000, tree_hash::mod - 1);\n\n   \
    \     while ((int)rnum.size() < N) {\n            auto x = rand(mt);\n       \
    \     rnum.push_back(x);\n        }\n    }\n\n    void add_edge(const int a, const\
    \ int b) {\n        G[a].push_back(b), G[b].push_back(a);\n    }\n\n    pair<int,\
    \ u64> hash_dfs(int v, int p) {\n        int depth = 0;\n        u64 res = 1;\n\
    \        for (auto to : G[v]) {\n            if (to == p) continue;\n        \
    \    auto [d, val] = hash_dfs(to, v);\n            depth = max(depth, d + 1);\n\
    \            res = mul(res, val);\n        }\n        res = add(res, rnum[depth]);\n\
    \        hs[v] = res;\n        return make_pair(depth, res);\n    }\n\n    void\
    \ calc(int root = 0) { hash_dfs(root, -1); }\n};\n"
  code: "class tree_hash {\n   public:\n    using u128 = __uint128_t;\n    using u64\
    \ = uint64_t;\n\n    static const u64 mod = (1ull << 61ull) - 1;\n\n    static\
    \ inline u64 add(u64 a, u64 b) {\n        if ((a += b) >= mod) a -= mod;\n   \
    \     return a;\n    }\n\n    static inline u64 mul(u64 a, u64 b) {\n        u128\
    \ c = (u128)a * b;\n        return add(c >> 61, c & mod);\n    }\n\n    vector<u64>\
    \ hs;\n    vector<u64> rnum;\n    const int N;\n    vector<vector<int>> G;\n\n\
    \    tree_hash(int N) : N(N), G(N), hs(N) {\n        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \        uniform_int_distribution<u64> rand(1000, tree_hash::mod - 1);\n\n   \
    \     while ((int)rnum.size() < N) {\n            auto x = rand(mt);\n       \
    \     rnum.push_back(x);\n        }\n    }\n\n    void add_edge(const int a, const\
    \ int b) {\n        G[a].push_back(b), G[b].push_back(a);\n    }\n\n    pair<int,\
    \ u64> hash_dfs(int v, int p) {\n        int depth = 0;\n        u64 res = 1;\n\
    \        for (auto to : G[v]) {\n            if (to == p) continue;\n        \
    \    auto [d, val] = hash_dfs(to, v);\n            depth = max(depth, d + 1);\n\
    \            res = mul(res, val);\n        }\n        res = add(res, rnum[depth]);\n\
    \        hs[v] = res;\n        return make_pair(depth, res);\n    }\n\n    void\
    \ calc(int root = 0) { hash_dfs(root, -1); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/TreeHash.cpp
  requiredBy: []
  timestamp: '2021-08-08 16:09:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/TreeHash.cpp
layout: document
redirect_from:
- /library/cpp_src/graph/TreeHash.cpp
- /library/cpp_src/graph/TreeHash.cpp.html
title: cpp_src/graph/TreeHash.cpp
---
