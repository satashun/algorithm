---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp_src/string/RollingHash.hpp
    title: cpp_src/string/RollingHash.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"test/aoj/ALDS1_14_B.test.cpp\"\n#define PROBLEM \\\n   \
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\n\n#define call_from_test\n#line 1 \"\
    cpp_src/string/RollingHash.hpp\"\nclass RollingHash {\n   public:\n    using u128\
    \ = __uint128_t;\n    using u64 = uint64_t;\n\n    static const u64 mod = (1ull\
    \ << 61ull) - 1;\n    vector<u64> power;\n    const u64 base;\n\n    static inline\
    \ u64 add(u64 a, u64 b) {\n        if ((a += b) >= mod) a -= mod;\n        return\
    \ a;\n    }\n\n    static inline u64 mul(u64 a, u64 b) {\n        u128 c = (u128)a\
    \ * b;\n        return add(c >> 61, c & mod);\n    }\n\n    // make sure that\
    \ no different characters / elements have the same value\n    // modulo base\n\
    \    static inline u64 generate_base(int minB = 1000) {\n        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
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
    \ c : s) res = add(mul(res, base), c);\n        return res;\n    }\n};\n#line\
    \ 9 \"test/aoj/ALDS1_14_B.test.cpp\"\n#undef call_from_test\n\nusing ll = long\
    \ long;\nusing pii = pair<int, int>;\ntemplate <class T>\nusing V = vector<T>;\n\
    template <class T>\nusing VV = V<V<T>>;\n\n#define pb push_back\n#define eb emplace_back\n\
    #define mp make_pair\n#define fi first\n#define se second\n#define rep(i, n) rep2(i,\
    \ 0, n)\n#define rep2(i, m, n) for (int i = m; i < (n); i++)\n#define per(i, b)\
    \ per2(i, 0, b)\n#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)\n\
    #define ALL(c) (c).begin(), (c).end()\n#define SZ(x) ((int)(x).size())\n\nconstexpr\
    \ ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }\n\ntemplate <class\
    \ T, class U>\nvoid chmin(T& t, const U& u) {\n    if (t > u) t = u;\n}\ntemplate\
    \ <class T, class U>\nvoid chmax(T& t, const U& u) {\n    if (t < u) t = u;\n\
    }\n\ntemplate <class T, class U>\nostream& operator<<(ostream& os, const pair<T,\
    \ U>& p) {\n    os << \"(\" << p.first << \",\" << p.second << \")\";\n    return\
    \ os;\n}\n\ntemplate <class T>\nostream& operator<<(ostream& os, const vector<T>&\
    \ v) {\n    os << \"{\";\n    rep(i, v.size()) {\n        if (i) os << \",\";\n\
    \        os << v[i];\n    }\n    os << \"}\";\n    return os;\n}\n\n#ifdef LOCAL\n\
    void debug_out() { cerr << endl; }\ntemplate <typename Head, typename... Tail>\n\
    void debug_out(Head H, Tail... T) {\n    cerr << \" \" << H;\n    debug_out(T...);\n\
    }\n#define debug(...) \\\n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"\
    ]:\", debug_out(__VA_ARGS__)\n#define dump(x) cerr << __LINE__ << \" \" << #x\
    \ << \" = \" << (x) << endl\n#else\n#define debug(...) (void(0))\n#define dump(x)\
    \ (void(0))\n#endif\n\nint main() {\n    RollingHash rh;\n    string S, T;\n \
    \   cin >> S >> T;\n    auto vh = rh.build(S);\n    auto thash = rh.whole_hash(T);\n\
    \    int sl = SZ(S), tl = SZ(T);\n    for (int l = 0; l <= sl - tl; ++l) {\n \
    \       if (rh.query(vh, l, l + tl) == thash) {\n            cout << l << '\\\
    n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../cpp_src/string/RollingHash.hpp\"\n#undef call_from_test\n\nusing\
    \ ll = long long;\nusing pii = pair<int, int>;\ntemplate <class T>\nusing V =\
    \ vector<T>;\ntemplate <class T>\nusing VV = V<V<T>>;\n\n#define pb push_back\n\
    #define eb emplace_back\n#define mp make_pair\n#define fi first\n#define se second\n\
    #define rep(i, n) rep2(i, 0, n)\n#define rep2(i, m, n) for (int i = m; i < (n);\
    \ i++)\n#define per(i, b) per2(i, 0, b)\n#define per2(i, a, b) for (int i = int(b)\
    \ - 1; i >= int(a); i--)\n#define ALL(c) (c).begin(), (c).end()\n#define SZ(x)\
    \ ((int)(x).size())\n\nconstexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n\
    \ - 1); }\n\ntemplate <class T, class U>\nvoid chmin(T& t, const U& u) {\n   \
    \ if (t > u) t = u;\n}\ntemplate <class T, class U>\nvoid chmax(T& t, const U&\
    \ u) {\n    if (t < u) t = u;\n}\n\ntemplate <class T, class U>\nostream& operator<<(ostream&\
    \ os, const pair<T, U>& p) {\n    os << \"(\" << p.first << \",\" << p.second\
    \ << \")\";\n    return os;\n}\n\ntemplate <class T>\nostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    os << \"{\";\n    rep(i, v.size()) {\n      \
    \  if (i) os << \",\";\n        os << v[i];\n    }\n    os << \"}\";\n    return\
    \ os;\n}\n\n#ifdef LOCAL\nvoid debug_out() { cerr << endl; }\ntemplate <typename\
    \ Head, typename... Tail>\nvoid debug_out(Head H, Tail... T) {\n    cerr << \"\
    \ \" << H;\n    debug_out(T...);\n}\n#define debug(...) \\\n    cerr << __LINE__\
    \ << \" [\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n#define dump(x)\
    \ cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n#define debug(...)\
    \ (void(0))\n#define dump(x) (void(0))\n#endif\n\nint main() {\n    RollingHash\
    \ rh;\n    string S, T;\n    cin >> S >> T;\n    auto vh = rh.build(S);\n    auto\
    \ thash = rh.whole_hash(T);\n    int sl = SZ(S), tl = SZ(T);\n    for (int l =\
    \ 0; l <= sl - tl; ++l) {\n        if (rh.query(vh, l, l + tl) == thash) {\n \
    \           cout << l << '\\n';\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - cpp_src/string/RollingHash.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_14_B.test.cpp
  requiredBy: []
  timestamp: '2020-12-31 16:46:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_B.test.cpp
- /verify/test/aoj/ALDS1_14_B.test.cpp.html
title: test/aoj/ALDS1_14_B.test.cpp
---
