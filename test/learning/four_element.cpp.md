---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"test/learning/four_element.cpp\"\n#pragma GCC optimize(\"\
    O3\")\n#pragma GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nusing ll = long long;\nusing pii = pair<int, int>;\ntemplate\
    \ <class T>\nusing V = vector<T>;\ntemplate <class T>\nusing VV = V<V<T>>;\n\n\
    #define pb push_back\n#define eb emplace_back\n#define mp make_pair\n#define fi\
    \ first\n#define se second\n#define rep(i, n) rep2(i, 0, n)\n#define rep2(i, m,\
    \ n) for (int i = m; i < (n); i++)\n#define per(i, b) per2(i, 0, b)\n#define per2(i,\
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
    \nconst int maxv = 1000010;\n\nV<Mint> fact(maxv), ifact(maxv), inv(maxv);\n\n\
    void init() {\n    fact[0] = 1;\n    for (int i = 1; i < maxv; ++i) {\n      \
    \  fact[i] = fact[i - 1] * i;\n    }\n\n    ifact[maxv - 1] = fact[maxv - 1].inv();\n\
    \n    for (int i = maxv - 2; i >= 0; --i) {\n        ifact[i] = ifact[i + 1] *\
    \ (i + 1);\n    }\n\n    for (int i = 1; i < maxv; ++i) {\n        inv[i] = ifact[i]\
    \ * fact[i - 1];\n    }\n}\n\ninline Mint comb(int n, int k) {\n    if (k < 0)\
    \ return 0;\n    Mint res = ifact[k];\n    rep(i, k) res = res * (n - i);\n  \
    \  return res;\n}\n\nconst Mint i2 = (Mint::get_mod() + 1) / 2;\n\nusing R = __int128;\n\
    \nint main() {\n    init();\n\n    int n, s;\n    cin >> n >> s;\n    V<pii> vec;\n\
    \    rep(i, n) {\n        int l, r;\n        cin >> l >> r;\n        vec.eb(1,\
    \ l);\n        vec.eb(-1, r + 1);\n    }\n\n    Mint x, y, z, u, v;\n\n    {\n\
    \        V<pair<int, Mint>> a[4], b[4];\n        for (auto& p : vec) {\n     \
    \       for (auto& q : vec) {\n                int k = p.se + q.se;\n        \
    \        Mint c = Mint(p.fi) * q.fi;\n                rep(t, 4) {\n          \
    \          a[t].eb(k, c * comb(s - k + 3, t));\n                    b[t].eb(k,\
    \ c * comb(-k, t));\n                }\n            }\n        }\n        rep(t,\
    \ 4) {\n            sort(ALL(a[t]), [&](pair<int, Mint> p, pair<int, Mint> q)\
    \ {\n                return p.fi < q.fi;\n            });\n            sort(ALL(b[t]),\
    \ [&](pair<int, Mint> p, pair<int, Mint> q) {\n                return p.fi < q.fi;\n\
    \            });\n        }\n        rep(t, 4) {\n            Mint cur;\n    \
    \        for (auto& p : a[t]) cur += p.se;\n            int now = (int)a[t].size()\
    \ - 1;\n            for (auto& q : b[3 - t]) {\n                while (now >=\
    \ 0 && a[t][now].fi + q.fi > s) {\n                    cur -= a[t][now--].se;\n\
    \                }\n                x += q.se * cur;\n            }\n        }\n\
    \    }\n\n    R sum = 0;\n\n    for (auto& p : vec) {\n        rep(i, vec.size())\
    \ {\n            rep(j, i + 1) {\n                auto &q = vec[i], &r = vec[j];\n\
    \                ll k = s - (p.se * 2 + q.se + r.se);\n                int c =\
    \ p.fi * q.fi * r.fi * (j != i ? 2 : 1);\n                if (k >= 0) {\n    \
    \                if (k & 1) {\n                        ll r = (k - 1) / 2;\n \
    \                       sum += (r + 2) * (r + 1) * c * 2;\n                  \
    \  } else {\n                        ll r = k / 2;\n                        sum\
    \ += (r * 2 + 2) * (r + 1) * c;\n                    }\n                }\n  \
    \          }\n        }\n    }\n    y = sum % Mint::get_mod();\n    y *= i2;\n\
    \n    for (auto& p : vec) {\n        for (auto& q : vec) {\n            int k\
    \ = (p.se + q.se) * 2;\n            Mint c = Mint(p.fi) * q.fi;\n            if\
    \ (k <= s) {\n                int r = s - k;\n                if (r % 2 == 0)\
    \ {\n                    z += c * (r / 2 + 1);\n                }\n          \
    \  }\n        }\n    }\n\n    for (auto& p : vec) {\n        for (auto& q : vec)\
    \ {\n            Mint c = Mint(p.fi) * q.fi;\n            int k = p.se * 3 + q.se;\n\
    \            if (k <= s) {\n                int r = s - k;\n                u\
    \ += c * (r / 3 + 1);\n            }\n        }\n    }\n\n    for (auto& p : vec)\
    \ {\n        Mint c = Mint(p.fi);\n        int k = p.se * 4;\n        if (k <=\
    \ s) {\n            int r = s - k;\n            if (r % 4 == 0) v += c;\n    \
    \    }\n    }\n\n    debug(x.v, y.v, z.v, u.v, v.v);\n    cout << ((x - y * 6\
    \ + z * 3 + u * 8 - v * 6) / 24).v << endl;\n\n    return 0;\n}\n"
  code: "#pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\")\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\nusing pii =\
    \ pair<int, int>;\ntemplate <class T>\nusing V = vector<T>;\ntemplate <class T>\n\
    using VV = V<V<T>>;\n\n#define pb push_back\n#define eb emplace_back\n#define\
    \ mp make_pair\n#define fi first\n#define se second\n#define rep(i, n) rep2(i,\
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
    \ ModInt<998244353>;\n\nconst int maxv = 1000010;\n\nV<Mint> fact(maxv), ifact(maxv),\
    \ inv(maxv);\n\nvoid init() {\n    fact[0] = 1;\n    for (int i = 1; i < maxv;\
    \ ++i) {\n        fact[i] = fact[i - 1] * i;\n    }\n\n    ifact[maxv - 1] = fact[maxv\
    \ - 1].inv();\n\n    for (int i = maxv - 2; i >= 0; --i) {\n        ifact[i] =\
    \ ifact[i + 1] * (i + 1);\n    }\n\n    for (int i = 1; i < maxv; ++i) {\n   \
    \     inv[i] = ifact[i] * fact[i - 1];\n    }\n}\n\ninline Mint comb(int n, int\
    \ k) {\n    if (k < 0) return 0;\n    Mint res = ifact[k];\n    rep(i, k) res\
    \ = res * (n - i);\n    return res;\n}\n\nconst Mint i2 = (Mint::get_mod() + 1)\
    \ / 2;\n\nusing R = __int128;\n\nint main() {\n    init();\n\n    int n, s;\n\
    \    cin >> n >> s;\n    V<pii> vec;\n    rep(i, n) {\n        int l, r;\n   \
    \     cin >> l >> r;\n        vec.eb(1, l);\n        vec.eb(-1, r + 1);\n    }\n\
    \n    Mint x, y, z, u, v;\n\n    {\n        V<pair<int, Mint>> a[4], b[4];\n \
    \       for (auto& p : vec) {\n            for (auto& q : vec) {\n           \
    \     int k = p.se + q.se;\n                Mint c = Mint(p.fi) * q.fi;\n    \
    \            rep(t, 4) {\n                    a[t].eb(k, c * comb(s - k + 3, t));\n\
    \                    b[t].eb(k, c * comb(-k, t));\n                }\n       \
    \     }\n        }\n        rep(t, 4) {\n            sort(ALL(a[t]), [&](pair<int,\
    \ Mint> p, pair<int, Mint> q) {\n                return p.fi < q.fi;\n       \
    \     });\n            sort(ALL(b[t]), [&](pair<int, Mint> p, pair<int, Mint>\
    \ q) {\n                return p.fi < q.fi;\n            });\n        }\n    \
    \    rep(t, 4) {\n            Mint cur;\n            for (auto& p : a[t]) cur\
    \ += p.se;\n            int now = (int)a[t].size() - 1;\n            for (auto&\
    \ q : b[3 - t]) {\n                while (now >= 0 && a[t][now].fi + q.fi > s)\
    \ {\n                    cur -= a[t][now--].se;\n                }\n         \
    \       x += q.se * cur;\n            }\n        }\n    }\n\n    R sum = 0;\n\n\
    \    for (auto& p : vec) {\n        rep(i, vec.size()) {\n            rep(j, i\
    \ + 1) {\n                auto &q = vec[i], &r = vec[j];\n                ll k\
    \ = s - (p.se * 2 + q.se + r.se);\n                int c = p.fi * q.fi * r.fi\
    \ * (j != i ? 2 : 1);\n                if (k >= 0) {\n                    if (k\
    \ & 1) {\n                        ll r = (k - 1) / 2;\n                      \
    \  sum += (r + 2) * (r + 1) * c * 2;\n                    } else {\n         \
    \               ll r = k / 2;\n                        sum += (r * 2 + 2) * (r\
    \ + 1) * c;\n                    }\n                }\n            }\n       \
    \ }\n    }\n    y = sum % Mint::get_mod();\n    y *= i2;\n\n    for (auto& p :\
    \ vec) {\n        for (auto& q : vec) {\n            int k = (p.se + q.se) * 2;\n\
    \            Mint c = Mint(p.fi) * q.fi;\n            if (k <= s) {\n        \
    \        int r = s - k;\n                if (r % 2 == 0) {\n                 \
    \   z += c * (r / 2 + 1);\n                }\n            }\n        }\n    }\n\
    \n    for (auto& p : vec) {\n        for (auto& q : vec) {\n            Mint c\
    \ = Mint(p.fi) * q.fi;\n            int k = p.se * 3 + q.se;\n            if (k\
    \ <= s) {\n                int r = s - k;\n                u += c * (r / 3 + 1);\n\
    \            }\n        }\n    }\n\n    for (auto& p : vec) {\n        Mint c\
    \ = Mint(p.fi);\n        int k = p.se * 4;\n        if (k <= s) {\n          \
    \  int r = s - k;\n            if (r % 4 == 0) v += c;\n        }\n    }\n\n \
    \   debug(x.v, y.v, z.v, u.v, v.v);\n    cout << ((x - y * 6 + z * 3 + u * 8 -\
    \ v * 6) / 24).v << endl;\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: test/learning/four_element.cpp
  requiredBy: []
  timestamp: '2020-09-01 14:11:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/learning/four_element.cpp
layout: document
redirect_from:
- /library/test/learning/four_element.cpp
- /library/test/learning/four_element.cpp.html
title: test/learning/four_element.cpp
---
