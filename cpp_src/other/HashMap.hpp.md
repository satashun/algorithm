---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://xorshift.di.unimi.it/splitmix64.c
    - https://codeforces.com/blog/entry/62393
  bundledCode: "#line 1 \"cpp_src/other/HashMap.hpp\"\n#include <ext/pb_ds/assoc_container.hpp>\n\
    \n// https://codeforces.com/blog/entry/62393\nstruct splitmix64_hash {\n    static\
    \ uint64_t splitmix64(uint64_t x) {\n        // http://xorshift.di.unimi.it/splitmix64.c\n\
    \        x += 0x9e3779b97f4a7c15;\n        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n\
    \        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n        return x ^ (x >> 31);\n\
    \    }\n\n    size_t operator()(uint64_t x) const {\n        static const uint64_t\
    \ FIXED_RANDOM =\n            std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \        return splitmix64(x + FIXED_RANDOM);\n    }\n};\n\ntemplate <typename\
    \ K, typename V, typename Hash = splitmix64_hash>\nusing hash_map = __gnu_pbds::gp_hash_table<K,\
    \ V, Hash>;\n\ntemplate <typename K, typename Hash = splitmix64_hash>\nusing hash_set\
    \ = hash_map<K, __gnu_pbds::null_type, Hash>;\n"
  code: "#include <ext/pb_ds/assoc_container.hpp>\n\n// https://codeforces.com/blog/entry/62393\n\
    struct splitmix64_hash {\n    static uint64_t splitmix64(uint64_t x) {\n     \
    \   // http://xorshift.di.unimi.it/splitmix64.c\n        x += 0x9e3779b97f4a7c15;\n\
    \        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n        x = (x ^ (x >> 27))\
    \ * 0x94d049bb133111eb;\n        return x ^ (x >> 31);\n    }\n\n    size_t operator()(uint64_t\
    \ x) const {\n        static const uint64_t FIXED_RANDOM =\n            std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \        return splitmix64(x + FIXED_RANDOM);\n    }\n};\n\ntemplate <typename\
    \ K, typename V, typename Hash = splitmix64_hash>\nusing hash_map = __gnu_pbds::gp_hash_table<K,\
    \ V, Hash>;\n\ntemplate <typename K, typename Hash = splitmix64_hash>\nusing hash_set\
    \ = hash_map<K, __gnu_pbds::null_type, Hash>;"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/other/HashMap.hpp
  requiredBy: []
  timestamp: '2025-12-28 17:44:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/other/HashMap.hpp
layout: document
redirect_from:
- /library/cpp_src/other/HashMap.hpp
- /library/cpp_src/other/HashMap.hpp.html
title: cpp_src/other/HashMap.hpp
---
