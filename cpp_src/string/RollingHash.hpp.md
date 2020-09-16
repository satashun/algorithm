---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"cpp_src/string/RollingHash.hpp\"\n// from ei1333\n\ntemplate\
    \ <unsigned mod>\nstruct RollingHash {\n    vector<unsigned> hashed, power;\n\n\
    \    inline unsigned mul(unsigned a, unsigned b) const {\n        unsigned long\
    \ long x = (unsigned long long)a * b;\n        unsigned xh = (unsigned)(x >> 32),\
    \ xl = (unsigned)x, d, m;\n        asm(\"divl %4; \\n\\t\" : \"=a\"(d), \"=d\"\
    (m) : \"d\"(xh), \"a\"(xl), \"r\"(mod));\n        return m;\n    }\n\n    RollingHash(const\
    \ string &s, unsigned base = 10007) {\n        int sz = (int)s.size();\n     \
    \   hashed.assign(sz + 1, 0);\n        power.assign(sz + 1, 0);\n        power[0]\
    \ = 1;\n        for (int i = 0; i < sz; i++) {\n            power[i + 1] = mul(power[i],\
    \ base);\n            hashed[i + 1] = mul(hashed[i], base) + s[i];\n         \
    \   if (hashed[i + 1] >= mod) hashed[i + 1] -= mod;\n        }\n    }\n\n    unsigned\
    \ get(int l, int r) const {\n        unsigned ret = hashed[r] + mod - mul(hashed[l],\
    \ power[r - l]);\n        if (ret >= mod) ret -= mod;\n        return ret;\n \
    \   }\n\n    unsigned connect(unsigned h1, int h2, int h2len) const {\n      \
    \  unsigned ret = mul(h1, power[h2len]) + h2;\n        if (ret >= mod) ret -=\
    \ mod;\n        return ret;\n    }\n\n    int LCP(const RollingHash<mod> &b, int\
    \ l1, int r1, int l2, int r2) {\n        int len = min(r1 - l1, r2 - l2);\n  \
    \      int low = -1, high = len + 1;\n        while (high - low > 1) {\n     \
    \       int mid = (low + high) / 2;\n            if (get(l1, l1 + mid) == b.get(l2,\
    \ l2 + mid))\n                low = mid;\n            else\n                high\
    \ = mid;\n        }\n        return (low);\n    }\n};\n\nusing RH = RollingHash<1000000007>;\n"
  code: "// from ei1333\n\ntemplate <unsigned mod>\nstruct RollingHash {\n    vector<unsigned>\
    \ hashed, power;\n\n    inline unsigned mul(unsigned a, unsigned b) const {\n\
    \        unsigned long long x = (unsigned long long)a * b;\n        unsigned xh\
    \ = (unsigned)(x >> 32), xl = (unsigned)x, d, m;\n        asm(\"divl %4; \\n\\\
    t\" : \"=a\"(d), \"=d\"(m) : \"d\"(xh), \"a\"(xl), \"r\"(mod));\n        return\
    \ m;\n    }\n\n    RollingHash(const string &s, unsigned base = 10007) {\n   \
    \     int sz = (int)s.size();\n        hashed.assign(sz + 1, 0);\n        power.assign(sz\
    \ + 1, 0);\n        power[0] = 1;\n        for (int i = 0; i < sz; i++) {\n  \
    \          power[i + 1] = mul(power[i], base);\n            hashed[i + 1] = mul(hashed[i],\
    \ base) + s[i];\n            if (hashed[i + 1] >= mod) hashed[i + 1] -= mod;\n\
    \        }\n    }\n\n    unsigned get(int l, int r) const {\n        unsigned\
    \ ret = hashed[r] + mod - mul(hashed[l], power[r - l]);\n        if (ret >= mod)\
    \ ret -= mod;\n        return ret;\n    }\n\n    unsigned connect(unsigned h1,\
    \ int h2, int h2len) const {\n        unsigned ret = mul(h1, power[h2len]) + h2;\n\
    \        if (ret >= mod) ret -= mod;\n        return ret;\n    }\n\n    int LCP(const\
    \ RollingHash<mod> &b, int l1, int r1, int l2, int r2) {\n        int len = min(r1\
    \ - l1, r2 - l2);\n        int low = -1, high = len + 1;\n        while (high\
    \ - low > 1) {\n            int mid = (low + high) / 2;\n            if (get(l1,\
    \ l1 + mid) == b.get(l2, l2 + mid))\n                low = mid;\n            else\n\
    \                high = mid;\n        }\n        return (low);\n    }\n};\n\n\
    using RH = RollingHash<1000000007>;"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/string/RollingHash.hpp
  requiredBy: []
  timestamp: '2020-07-17 17:57:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/string/RollingHash.hpp
layout: document
redirect_from:
- /library/cpp_src/string/RollingHash.hpp
- /library/cpp_src/string/RollingHash.hpp.html
title: cpp_src/string/RollingHash.hpp
---
