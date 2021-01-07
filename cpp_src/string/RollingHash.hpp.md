---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.test.cpp
    title: test/aoj/ALDS1_14_B.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/string/RollingHash.hpp\"\nclass RollingHash {\n\
    \   public:\n    using u128 = __uint128_t;\n    using u64 = uint64_t;\n\n    static\
    \ const u64 mod = (1ull << 61ull) - 1;\n    vector<u64> power;\n    const u64\
    \ base;\n\n    static inline u64 add(u64 a, u64 b) {\n        if ((a += b) >=\
    \ mod) a -= mod;\n        return a;\n    }\n\n    static inline u64 mul(u64 a,\
    \ u64 b) {\n        u128 c = (u128)a * b;\n        return add(c >> 61, c & mod);\n\
    \    }\n\n    // make sure that no different characters / elements have the same\
    \ value\n    // modulo base\n    static inline u64 generate_base(int minB = 1000)\
    \ {\n        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \        uniform_int_distribution<u64> rand(minB, RollingHash::mod - 1);\n   \
    \     return rand(mt);\n    }\n\n    inline void expand(int sz) {\n        if\
    \ (power.size() <= sz) {\n            int pre_sz = (int)power.size();\n      \
    \      power.resize(sz + 1);\n            for (int i = pre_sz - 1; i < sz; i++)\
    \ {\n                power[i + 1] = mul(power[i], base);\n            }\n    \
    \    }\n    }\n\n    explicit RollingHash(u64 base = generate_base()) : base(base),\
    \ power{1} {}\n\n    vector<u64> build(const string& s) const {\n        int sz\
    \ = s.size();\n        vector<u64> vhash(sz + 1);\n        for (int i = 0; i <\
    \ sz; i++) {\n            vhash[i + 1] = add(mul(vhash[i], base), s[i]);\n   \
    \     }\n        return vhash;\n    }\n\n    template <class T>\n    vector<u64>\
    \ build(const vector<T>& s) const {\n        int sz = s.size();\n        vector<u64>\
    \ vhash(sz + 1);\n        for (int i = 0; i < sz; i++) {\n            vhash[i\
    \ + 1] = add(mul(vhash[i], base), s[i]);\n        }\n        return vhash;\n \
    \   }\n\n    u64 query(const vector<u64>& s, int l, int r) {\n        expand(r\
    \ - l);\n        return add(s[r], mod - mul(s[l], power[r - l]));\n    }\n\n \
    \   u64 merge(u64 h1, u64 h2, int h2len) {\n        expand(h2len);\n        return\
    \ add(mul(h1, power[h2len]), h2);\n    }\n\n    u64 whole_hash(const string& s)\
    \ const {\n        int sz = s.size();\n        u64 res = 0;\n        for (auto&\
    \ c : s) res = add(mul(res, base), c);\n        return res;\n    }\n};\n"
  code: "class RollingHash {\n   public:\n    using u128 = __uint128_t;\n    using\
    \ u64 = uint64_t;\n\n    static const u64 mod = (1ull << 61ull) - 1;\n    vector<u64>\
    \ power;\n    const u64 base;\n\n    static inline u64 add(u64 a, u64 b) {\n \
    \       if ((a += b) >= mod) a -= mod;\n        return a;\n    }\n\n    static\
    \ inline u64 mul(u64 a, u64 b) {\n        u128 c = (u128)a * b;\n        return\
    \ add(c >> 61, c & mod);\n    }\n\n    // make sure that no different characters\
    \ / elements have the same value\n    // modulo base\n    static inline u64 generate_base(int\
    \ minB = 1000) {\n        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \        uniform_int_distribution<u64> rand(minB, RollingHash::mod - 1);\n   \
    \     return rand(mt);\n    }\n\n    inline void expand(int sz) {\n        if\
    \ (power.size() <= sz) {\n            int pre_sz = (int)power.size();\n      \
    \      power.resize(sz + 1);\n            for (int i = pre_sz - 1; i < sz; i++)\
    \ {\n                power[i + 1] = mul(power[i], base);\n            }\n    \
    \    }\n    }\n\n    explicit RollingHash(u64 base = generate_base()) : base(base),\
    \ power{1} {}\n\n    vector<u64> build(const string& s) const {\n        int sz\
    \ = s.size();\n        vector<u64> vhash(sz + 1);\n        for (int i = 0; i <\
    \ sz; i++) {\n            vhash[i + 1] = add(mul(vhash[i], base), s[i]);\n   \
    \     }\n        return vhash;\n    }\n\n    template <class T>\n    vector<u64>\
    \ build(const vector<T>& s) const {\n        int sz = s.size();\n        vector<u64>\
    \ vhash(sz + 1);\n        for (int i = 0; i < sz; i++) {\n            vhash[i\
    \ + 1] = add(mul(vhash[i], base), s[i]);\n        }\n        return vhash;\n \
    \   }\n\n    u64 query(const vector<u64>& s, int l, int r) {\n        expand(r\
    \ - l);\n        return add(s[r], mod - mul(s[l], power[r - l]));\n    }\n\n \
    \   u64 merge(u64 h1, u64 h2, int h2len) {\n        expand(h2len);\n        return\
    \ add(mul(h1, power[h2len]), h2);\n    }\n\n    u64 whole_hash(const string& s)\
    \ const {\n        int sz = s.size();\n        u64 res = 0;\n        for (auto&\
    \ c : s) res = add(mul(res, base), c);\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/string/RollingHash.hpp
  requiredBy: []
  timestamp: '2020-12-31 16:46:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_14_B.test.cpp
documentation_of: cpp_src/string/RollingHash.hpp
layout: document
redirect_from:
- /library/cpp_src/string/RollingHash.hpp
- /library/cpp_src/string/RollingHash.hpp.html
title: cpp_src/string/RollingHash.hpp
---
