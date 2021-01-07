---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp_src/math/Modular.hpp
    title: cpp_src/math/Modular.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/yosupo/point_set_range_composite.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\nusing pii =\
    \ pair<int, int>;\ntemplate <class T>\nusing V = vector<T>;\ntemplate <class T>\n\
    using VV = V<V<T>>;\n\n#define pb push_back\n#define eb emplace_back\n#define\
    \ mp make_pair\n#define fi first\n#define se second\n#define rep(i, n) rep2(i,\
    \ 0, n)\n#define rep2(i, m, n) for (int i = m; i < (n); i++)\n#define ALL(c) (c).begin(),\
    \ (c).end()\n\n#ifdef LOCAL\n#define dump(x) cerr << __LINE__ << \" \" << #x <<\
    \ \" = \" << (x) << endl\n#else\n#define dump(x) true\n#endif\n\nconstexpr ll\
    \ TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }\n\ntemplate <class T,\
    \ class U>\nvoid chmin(T& t, const U& u) {\n    if (t > u) t = u;\n}\ntemplate\
    \ <class T, class U>\nvoid chmax(T& t, const U& u) {\n    if (t < u) t = u;\n\
    }\n\ntemplate <class T, class U>\nostream& operator<<(ostream& os, const pair<T,\
    \ U>& p) {\n    os << \"(\" << p.first << \",\" << p.second << \")\";\n    return\
    \ os;\n}\n\ntemplate <class T>\nostream& operator<<(ostream& os, const vector<T>&\
    \ v) {\n    os << \"{\";\n    rep(i, v.size()) {\n        if (i) os << \",\";\n\
    \        os << v[i];\n    }\n    os << \"}\";\n    return os;\n}\n\n#define call_from_test\n\
    #line 1 \"cpp_src/math/Modular.hpp\"\ntemplate <unsigned int MOD>\nstruct ModInt\
    \ {\n    using uint = unsigned int;\n    using ull = unsigned long long;\n   \
    \ using M = ModInt;\n\n    uint v;\n\n    ModInt(ll _v = 0) { set_norm(_v % MOD\
    \ + MOD); }\n    M& set_norm(uint _v) {  //[0, MOD * 2)->[0, MOD)\n        v =\
    \ (_v < MOD) ? _v : _v - MOD;\n        return *this;\n    }\n\n    explicit operator\
    \ bool() const { return v != 0; }\n    M operator+(const M& a) const { return\
    \ M().set_norm(v + a.v); }\n    M operator-(const M& a) const { return M().set_norm(v\
    \ + MOD - a.v); }\n    M operator*(const M& a) const { return M().set_norm(ull(v)\
    \ * a.v % MOD); }\n    M operator/(const M& a) const { return *this * a.inv();\
    \ }\n    M& operator+=(const M& a) { return *this = *this + a; }\n    M& operator-=(const\
    \ M& a) { return *this = *this - a; }\n    M& operator*=(const M& a) { return\
    \ *this = *this * a; }\n    M& operator/=(const M& a) { return *this = *this /\
    \ a; }\n    M operator-() const { return M() - *this; }\n    M& operator++(int)\
    \ { return *this = *this + 1; }\n    M& operator--(int) { return *this = *this\
    \ - 1; }\n\n    M pow(ll n) const {\n        if (n < 0) return inv().pow(-n);\n\
    \        M x = *this, res = 1;\n        while (n) {\n            if (n & 1) res\
    \ *= x;\n            x *= x;\n            n >>= 1;\n        }\n        return\
    \ res;\n    }\n\n    M inv() const {\n        ll a = v, b = MOD, p = 1, q = 0,\
    \ t;\n        while (b != 0) {\n            t = a / b;\n            swap(a -=\
    \ t * b, b);\n            swap(p -= t * q, q);\n        }\n        return M(p);\n\
    \    }\n\n    bool operator==(const M& a) const { return v == a.v; }\n    bool\
    \ operator!=(const M& a) const { return v != a.v; }\n    friend ostream& operator<<(ostream&\
    \ os, const M& a) { return os << a.v; }\n    static uint get_mod() { return MOD;\
    \ }\n};\n\n// using Mint = ModInt<1000000007>;\n#line 58 \"test/yosupo/point_set_range_composite.test.cpp\"\
    \n#undef call_from_test\n\nusing Mint = ModInt<998244353>;\n\n// index of root\
    \ = 1\n\ntemplate <class U>\nstruct segtree {\n    using T = typename U::T;\n\
    \    int sz;\n    V<T> dat;\n\n    segtree(const V<T>& a) {\n        int n = a.size();\n\
    \        sz = 1;\n        while (sz < n) sz <<= 1;\n        dat.assign(sz * 2,\
    \ U::id());\n        for (int i = 0; i < n; ++i) {\n            dat[sz + i] =\
    \ a[i];\n        }\n        for (int i = sz - 1; i >= 1; --i) {\n            upd(i);\n\
    \        }\n    }\n\n    void upd(int p) { dat[p] = U::op(dat[p << 1], dat[p <<\
    \ 1 | 1]); }\n\n    void build() {\n        for (int i = sz - 1; i > 0; --i) {\n\
    \            dat[i] = U::op(dat[i << 1], dat[i << 1 | 1]);\n        }\n    }\n\
    \n    void modify(int p, T v) {\n        p += sz;\n        dat[p] = v;\n     \
    \   while (p >>= 1) {\n            dat[p] = U::op(dat[p << 1], dat[p << 1 | 1]);\n\
    \        }\n    }\n\n    //[l, r)\n\n    T query(int l, int r) {\n        T lval\
    \ = U::id(), rval = U::id();\n        int res = 0;\n        for (l += sz, r +=\
    \ sz; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) lval = U::op(lval, dat[l++]);\n\
    \            if (r & 1) rval = U::op(dat[--r], rval);\n        }\n        return\
    \ U::op(lval, rval);\n    }\n};\n\nconst int INF = TEN(9) + 10;\n\nstruct U {\n\
    \    using T = pair<Mint, Mint>;\n    static T id() { return mp(Mint(1), Mint(0));\
    \ }\n    static T op(const T& a, const T& b) {\n        return mp(a.first * b.first,\
    \ a.second * b.first + b.second);\n    }\n};\n\nint main() {\n    int N, Q;\n\
    \    scanf(\"%d %d\", &N, &Q);\n    V<pair<Mint, Mint>> vec(N);\n\n    rep(i,\
    \ N) {\n        int a, b;\n        scanf(\"%d %d\", &a, &b);\n        vec[i] =\
    \ mp(Mint(a), Mint(b));\n    }\n    segtree<U> seg(vec);\n    while (Q--) {\n\
    \        int t;\n        scanf(\"%d\", &t);\n        if (t == 0) {\n         \
    \   int p, c, d;\n            scanf(\"%d %d %d\", &p, &c, &d);\n            seg.modify(p,\
    \ mp(Mint(c), Mint(d)));\n        } else {\n            int l, r, x;\n       \
    \     scanf(\"%d %d %d\", &l, &r, &x);\n            auto f = seg.query(l, r);\n\
    \            printf(\"%d\\n\", (f.fi * Mint(x) + f.se).v);\n        }\n    }\n\
    \n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n\
    using pii = pair<int, int>;\ntemplate <class T>\nusing V = vector<T>;\ntemplate\
    \ <class T>\nusing VV = V<V<T>>;\n\n#define pb push_back\n#define eb emplace_back\n\
    #define mp make_pair\n#define fi first\n#define se second\n#define rep(i, n) rep2(i,\
    \ 0, n)\n#define rep2(i, m, n) for (int i = m; i < (n); i++)\n#define ALL(c) (c).begin(),\
    \ (c).end()\n\n#ifdef LOCAL\n#define dump(x) cerr << __LINE__ << \" \" << #x <<\
    \ \" = \" << (x) << endl\n#else\n#define dump(x) true\n#endif\n\nconstexpr ll\
    \ TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }\n\ntemplate <class T,\
    \ class U>\nvoid chmin(T& t, const U& u) {\n    if (t > u) t = u;\n}\ntemplate\
    \ <class T, class U>\nvoid chmax(T& t, const U& u) {\n    if (t < u) t = u;\n\
    }\n\ntemplate <class T, class U>\nostream& operator<<(ostream& os, const pair<T,\
    \ U>& p) {\n    os << \"(\" << p.first << \",\" << p.second << \")\";\n    return\
    \ os;\n}\n\ntemplate <class T>\nostream& operator<<(ostream& os, const vector<T>&\
    \ v) {\n    os << \"{\";\n    rep(i, v.size()) {\n        if (i) os << \",\";\n\
    \        os << v[i];\n    }\n    os << \"}\";\n    return os;\n}\n\n#define call_from_test\n\
    #include \"../../cpp_src/math/Modular.hpp\"\n#undef call_from_test\n\nusing Mint\
    \ = ModInt<998244353>;\n\n// index of root = 1\n\ntemplate <class U>\nstruct segtree\
    \ {\n    using T = typename U::T;\n    int sz;\n    V<T> dat;\n\n    segtree(const\
    \ V<T>& a) {\n        int n = a.size();\n        sz = 1;\n        while (sz <\
    \ n) sz <<= 1;\n        dat.assign(sz * 2, U::id());\n        for (int i = 0;\
    \ i < n; ++i) {\n            dat[sz + i] = a[i];\n        }\n        for (int\
    \ i = sz - 1; i >= 1; --i) {\n            upd(i);\n        }\n    }\n\n    void\
    \ upd(int p) { dat[p] = U::op(dat[p << 1], dat[p << 1 | 1]); }\n\n    void build()\
    \ {\n        for (int i = sz - 1; i > 0; --i) {\n            dat[i] = U::op(dat[i\
    \ << 1], dat[i << 1 | 1]);\n        }\n    }\n\n    void modify(int p, T v) {\n\
    \        p += sz;\n        dat[p] = v;\n        while (p >>= 1) {\n          \
    \  dat[p] = U::op(dat[p << 1], dat[p << 1 | 1]);\n        }\n    }\n\n    //[l,\
    \ r)\n\n    T query(int l, int r) {\n        T lval = U::id(), rval = U::id();\n\
    \        int res = 0;\n        for (l += sz, r += sz; l < r; l >>= 1, r >>= 1)\
    \ {\n            if (l & 1) lval = U::op(lval, dat[l++]);\n            if (r &\
    \ 1) rval = U::op(dat[--r], rval);\n        }\n        return U::op(lval, rval);\n\
    \    }\n};\n\nconst int INF = TEN(9) + 10;\n\nstruct U {\n    using T = pair<Mint,\
    \ Mint>;\n    static T id() { return mp(Mint(1), Mint(0)); }\n    static T op(const\
    \ T& a, const T& b) {\n        return mp(a.first * b.first, a.second * b.first\
    \ + b.second);\n    }\n};\n\nint main() {\n    int N, Q;\n    scanf(\"%d %d\"\
    , &N, &Q);\n    V<pair<Mint, Mint>> vec(N);\n\n    rep(i, N) {\n        int a,\
    \ b;\n        scanf(\"%d %d\", &a, &b);\n        vec[i] = mp(Mint(a), Mint(b));\n\
    \    }\n    segtree<U> seg(vec);\n    while (Q--) {\n        int t;\n        scanf(\"\
    %d\", &t);\n        if (t == 0) {\n            int p, c, d;\n            scanf(\"\
    %d %d %d\", &p, &c, &d);\n            seg.modify(p, mp(Mint(c), Mint(d)));\n \
    \       } else {\n            int l, r, x;\n            scanf(\"%d %d %d\", &l,\
    \ &r, &x);\n            auto f = seg.query(l, r);\n            printf(\"%d\\n\"\
    , (f.fi * Mint(x) + f.se).v);\n        }\n    }\n\n    return 0;\n}"
  dependsOn:
  - cpp_src/math/Modular.hpp
  isVerificationFile: true
  path: test/yosupo/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2020-12-31 16:46:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_set_range_composite.test.cpp
- /verify/test/yosupo/point_set_range_composite.test.cpp.html
title: test/yosupo/point_set_range_composite.test.cpp
---
