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
  bundledCode: "#line 1 \"test/learning/exp.cpp\"\n// Gennady Korotkevich Contest\
    \ 5 E\n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n\
    using pii = pair<int, int>;\ntemplate <class T>\nusing V = vector<T>;\ntemplate\
    \ <class T>\nusing VV = V<V<T>>;\n\n#define pb push_back\n#define eb emplace_back\n\
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
    \ (void(0))\n#endif\n\ntemplate <unsigned int MOD>\nstruct ModInt {\n    using\
    \ uint = unsigned int;\n    using ull = unsigned long long;\n    using M = ModInt;\n\
    \n    uint v;\n\n    ModInt(ll _v = 0) { set_norm(_v % MOD + MOD); }\n    M& set_norm(uint\
    \ _v) {  //[0, MOD * 2)->[0, MOD)\n        v = (_v < MOD) ? _v : _v - MOD;\n \
    \       return *this;\n    }\n\n    explicit operator bool() const { return v\
    \ != 0; }\n    M operator+(const M& a) const { return M().set_norm(v + a.v); }\n\
    \    M operator-(const M& a) const { return M().set_norm(v + MOD - a.v); }\n \
    \   M operator*(const M& a) const { return M().set_norm(ull(v) * a.v % MOD); }\n\
    \    M operator/(const M& a) const { return *this * a.inv(); }\n    M& operator+=(const\
    \ M& a) { return *this = *this + a; }\n    M& operator-=(const M& a) { return\
    \ *this = *this - a; }\n    M& operator*=(const M& a) { return *this = *this *\
    \ a; }\n    M& operator/=(const M& a) { return *this = *this / a; }\n    M operator-()\
    \ const { return M() - *this; }\n    M& operator++(int) { return *this = *this\
    \ + 1; }\n    M& operator--(int) { return *this = *this - 1; }\n\n    M pow(ll\
    \ n) const {\n        if (n < 0) return inv().pow(-n);\n        M x = *this, res\
    \ = 1;\n        while (n) {\n            if (n & 1) res *= x;\n            x *=\
    \ x;\n            n >>= 1;\n        }\n        return res;\n    }\n\n    M inv()\
    \ const {\n        ll a = v, b = MOD, p = 1, q = 0, t;\n        while (b != 0)\
    \ {\n            t = a / b;\n            swap(a -= t * b, b);\n            swap(p\
    \ -= t * q, q);\n        }\n        return M(p);\n    }\n\n    bool operator==(const\
    \ M& a) const { return v == a.v; }\n    bool operator!=(const M& a) const { return\
    \ v != a.v; }\n    friend ostream& operator<<(ostream& os, const M& a) { return\
    \ os << a.v; }\n    static uint get_mod() { return MOD; }\n};\n\nusing Mint =\
    \ ModInt<998244353>;\n\nconst int maxv = 10000010;\n\nV<Mint> fact(maxv), ifact(maxv),\
    \ inv(maxv);\n\nvoid init() {\n    fact[0] = 1;\n    for (int i = 1; i < maxv;\
    \ ++i) {\n        fact[i] = fact[i - 1] * i;\n    }\n\n    ifact[maxv - 1] = fact[maxv\
    \ - 1].inv();\n\n    for (int i = maxv - 2; i >= 0; --i) {\n        ifact[i] =\
    \ ifact[i + 1] * (i + 1);\n    }\n\n    for (int i = 1; i < maxv; ++i) {\n   \
    \     inv[i] = ifact[i] * fact[i - 1];\n    }\n}\n\nMint comb(int n, int r) {\n\
    \    if (n < 0 || r < 0 || r > n) return Mint(0);\n    return fact[n] * ifact[r]\
    \ * ifact[n - r];\n}\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    init();\n\n    int n, k, x;\n    cin >> n >> k >> x;\n\n    V<Mint> P(k +\
    \ 1);\n    rep(i, k + 1) {\n        double a;\n        cin >> a;\n        a *=\
    \ 10000;\n        P[i] = Mint(int(a + 0.1)) / 10000;\n    }\n\n    V<Mint> Q(x\
    \ + 1);\n    Q[0] = P[0].pow(n);\n    auto ip0 = P[0].inv();\n\n    rep(i, x)\
    \ {\n        Mint a;\n        for (int j = 1; j <= k; ++j) {\n            if (i\
    \ + 1 - j >= 0) {\n                a += Q[i + 1 - j] * P[j] * j;\n           \
    \ }\n        }\n        a = a * n;\n        for (int j = 1; j <= k; ++j) {\n \
    \           if (i + 1 - j >= 0) {\n                a -= Q[i + 1 - j] * P[j] *\
    \ (i + 1 - j);\n            }\n        }\n        Q[i + 1] = a * ip0 * inv[i +\
    \ 1];\n    }\n    Mint s;\n    rep(i, x + 1) {\n        if (i == x) Q[i] = Mint(1)\
    \ - s;\n        s += Q[i];\n    }\n    Mint ans;\n    rep(i, x + 1) ans += Q[i]\
    \ * i;\n    cout << ans << endl;\n\n    return 0;\n}\n"
  code: "// Gennady Korotkevich Contest 5 E\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing pii = pair<int, int>;\ntemplate <class\
    \ T>\nusing V = vector<T>;\ntemplate <class T>\nusing VV = V<V<T>>;\n\n#define\
    \ pb push_back\n#define eb emplace_back\n#define mp make_pair\n#define fi first\n\
    #define se second\n#define rep(i, n) rep2(i, 0, n)\n#define rep2(i, m, n) for\
    \ (int i = m; i < (n); i++)\n#define per(i, b) per2(i, 0, b)\n#define per2(i,\
    \ a, b) for (int i = int(b) - 1; i >= int(a); i--)\n#define ALL(c) (c).begin(),\
    \ (c).end()\n#define SZ(x) ((int)(x).size())\n\nconstexpr ll TEN(int n) { return\
    \ (n == 0) ? 1 : 10 * TEN(n - 1); }\n\ntemplate <class T, class U>\nvoid chmin(T&\
    \ t, const U& u) {\n    if (t > u) t = u;\n}\ntemplate <class T, class U>\nvoid\
    \ chmax(T& t, const U& u) {\n    if (t < u) t = u;\n}\n\ntemplate <class T, class\
    \ U>\nostream& operator<<(ostream& os, const pair<T, U>& p) {\n    os << \"(\"\
    \ << p.first << \",\" << p.second << \")\";\n    return os;\n}\n\ntemplate <class\
    \ T>\nostream& operator<<(ostream& os, const vector<T>& v) {\n    os << \"{\"\
    ;\n    rep(i, v.size()) {\n        if (i) os << \",\";\n        os << v[i];\n\
    \    }\n    os << \"}\";\n    return os;\n}\n\n#ifdef LOCAL\nvoid debug_out()\
    \ { cerr << endl; }\ntemplate <typename Head, typename... Tail>\nvoid debug_out(Head\
    \ H, Tail... T) {\n    cerr << \" \" << H;\n    debug_out(T...);\n}\n#define debug(...)\
    \ \\\n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n\
    #define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n\
    #define debug(...) (void(0))\n#define dump(x) (void(0))\n#endif\n\ntemplate <unsigned\
    \ int MOD>\nstruct ModInt {\n    using uint = unsigned int;\n    using ull = unsigned\
    \ long long;\n    using M = ModInt;\n\n    uint v;\n\n    ModInt(ll _v = 0) {\
    \ set_norm(_v % MOD + MOD); }\n    M& set_norm(uint _v) {  //[0, MOD * 2)->[0,\
    \ MOD)\n        v = (_v < MOD) ? _v : _v - MOD;\n        return *this;\n    }\n\
    \n    explicit operator bool() const { return v != 0; }\n    M operator+(const\
    \ M& a) const { return M().set_norm(v + a.v); }\n    M operator-(const M& a) const\
    \ { return M().set_norm(v + MOD - a.v); }\n    M operator*(const M& a) const {\
    \ return M().set_norm(ull(v) * a.v % MOD); }\n    M operator/(const M& a) const\
    \ { return *this * a.inv(); }\n    M& operator+=(const M& a) { return *this =\
    \ *this + a; }\n    M& operator-=(const M& a) { return *this = *this - a; }\n\
    \    M& operator*=(const M& a) { return *this = *this * a; }\n    M& operator/=(const\
    \ M& a) { return *this = *this / a; }\n    M operator-() const { return M() -\
    \ *this; }\n    M& operator++(int) { return *this = *this + 1; }\n    M& operator--(int)\
    \ { return *this = *this - 1; }\n\n    M pow(ll n) const {\n        if (n < 0)\
    \ return inv().pow(-n);\n        M x = *this, res = 1;\n        while (n) {\n\
    \            if (n & 1) res *= x;\n            x *= x;\n            n >>= 1;\n\
    \        }\n        return res;\n    }\n\n    M inv() const {\n        ll a =\
    \ v, b = MOD, p = 1, q = 0, t;\n        while (b != 0) {\n            t = a /\
    \ b;\n            swap(a -= t * b, b);\n            swap(p -= t * q, q);\n   \
    \     }\n        return M(p);\n    }\n\n    bool operator==(const M& a) const\
    \ { return v == a.v; }\n    bool operator!=(const M& a) const { return v != a.v;\
    \ }\n    friend ostream& operator<<(ostream& os, const M& a) { return os << a.v;\
    \ }\n    static uint get_mod() { return MOD; }\n};\n\nusing Mint = ModInt<998244353>;\n\
    \nconst int maxv = 10000010;\n\nV<Mint> fact(maxv), ifact(maxv), inv(maxv);\n\n\
    void init() {\n    fact[0] = 1;\n    for (int i = 1; i < maxv; ++i) {\n      \
    \  fact[i] = fact[i - 1] * i;\n    }\n\n    ifact[maxv - 1] = fact[maxv - 1].inv();\n\
    \n    for (int i = maxv - 2; i >= 0; --i) {\n        ifact[i] = ifact[i + 1] *\
    \ (i + 1);\n    }\n\n    for (int i = 1; i < maxv; ++i) {\n        inv[i] = ifact[i]\
    \ * fact[i - 1];\n    }\n}\n\nMint comb(int n, int r) {\n    if (n < 0 || r <\
    \ 0 || r > n) return Mint(0);\n    return fact[n] * ifact[r] * ifact[n - r];\n\
    }\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n \
    \   init();\n\n    int n, k, x;\n    cin >> n >> k >> x;\n\n    V<Mint> P(k +\
    \ 1);\n    rep(i, k + 1) {\n        double a;\n        cin >> a;\n        a *=\
    \ 10000;\n        P[i] = Mint(int(a + 0.1)) / 10000;\n    }\n\n    V<Mint> Q(x\
    \ + 1);\n    Q[0] = P[0].pow(n);\n    auto ip0 = P[0].inv();\n\n    rep(i, x)\
    \ {\n        Mint a;\n        for (int j = 1; j <= k; ++j) {\n            if (i\
    \ + 1 - j >= 0) {\n                a += Q[i + 1 - j] * P[j] * j;\n           \
    \ }\n        }\n        a = a * n;\n        for (int j = 1; j <= k; ++j) {\n \
    \           if (i + 1 - j >= 0) {\n                a -= Q[i + 1 - j] * P[j] *\
    \ (i + 1 - j);\n            }\n        }\n        Q[i + 1] = a * ip0 * inv[i +\
    \ 1];\n    }\n    Mint s;\n    rep(i, x + 1) {\n        if (i == x) Q[i] = Mint(1)\
    \ - s;\n        s += Q[i];\n    }\n    Mint ans;\n    rep(i, x + 1) ans += Q[i]\
    \ * i;\n    cout << ans << endl;\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: test/learning/exp.cpp
  requiredBy: []
  timestamp: '2020-09-01 14:11:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/learning/exp.cpp
layout: document
redirect_from:
- /library/test/learning/exp.cpp
- /library/test/learning/exp.cpp.html
title: test/learning/exp.cpp
---
