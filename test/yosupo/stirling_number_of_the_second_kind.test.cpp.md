---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind
    _deprecated_at_docs: docs/ntt.md
    links:
    - https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind
  bundledCode: "#line 1 \"test/yosupo/stirling_number_of_the_second_kind.test.cpp\"\
    \n#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind\"\
    \n\n//#pragma GCC optimize(\"Ofast\")\n//#pragma GCC optimize(\"unroll-loops\"\
    )\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = int64_t;\nusing\
    \ ull = uint64_t;\nusing pii = pair<int, int>;\ntemplate <class T>\nusing V =\
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
    \ (void(0))\n#define dump(x) (void(0))\n#endif\n\ntemplate <unsigned int MOD>\n\
    struct ModInt {\n    using uint = unsigned int;\n    using ull = unsigned long\
    \ long;\n    using M = ModInt;\n\n    uint v;\n\n    ModInt(ll _v = 0) { set_norm(_v\
    \ % MOD + MOD); }\n    M& set_norm(uint _v) {  //[0, MOD * 2)->[0, MOD)\n    \
    \    v = (_v < MOD) ? _v : _v - MOD;\n        return *this;\n    }\n\n    explicit\
    \ operator bool() const { return v != 0; }\n    explicit operator int() const\
    \ { return v; }\n    M operator+(const M& a) const { return M().set_norm(v + a.v);\
    \ }\n    M operator-(const M& a) const { return M().set_norm(v + MOD - a.v); }\n\
    \    M operator*(const M& a) const { return M().set_norm(ull(v) * a.v % MOD);\
    \ }\n    M operator/(const M& a) const { return *this * a.inv(); }\n    M& operator+=(const\
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
    \ -= t * q, q);\n        }\n        return M(p);\n    }\n\n    friend ostream&\
    \ operator<<(ostream& os, const M& a) { return os << a.v; }\n    friend istream&\
    \ operator>>(istream& in, M& x) {\n        ll v_;\n        in >> v_;\n       \
    \ x = M(v_);\n        return in;\n    }\n\n    bool operator<(const M& r) const\
    \ { return v < r.v; }\n    bool operator>(const M& r) const { return v < *this;\
    \ }\n    bool operator<=(const M& r) const { return !(r < *this); }\n    bool\
    \ operator>=(const M& r) const { return !(*this < r); }\n    bool operator==(const\
    \ M& a) const { return v == a.v; }\n    bool operator!=(const M& a) const { return\
    \ v != a.v; }\n\n    static uint get_mod() { return MOD; }\n};\n\n// using Mint\
    \ = ModInt<1000000007>;\nusing Mint = ModInt<998244353>;\n\nconst int maxv = 1000010;\n\
    \nV<Mint> fact(maxv), ifact(maxv), inv(maxv);\n\nvoid init() {\n    fact[0] =\
    \ 1;\n    for (int i = 1; i < maxv; ++i) {\n        fact[i] = fact[i - 1] * i;\n\
    \    }\n\n    ifact[maxv - 1] = fact[maxv - 1].inv();\n\n    for (int i = maxv\
    \ - 2; i >= 0; --i) {\n        ifact[i] = ifact[i + 1] * (i + 1);\n    }\n\n \
    \   for (int i = 1; i < maxv; ++i) {\n        inv[i] = ifact[i] * fact[i - 1];\n\
    \    }\n}\n\nMint comb(int n, int r) {\n    if (n < 0 || r < 0 || r > n) return\
    \ Mint(0);\n    return fact[n] * ifact[r] * ifact[n - r];\n}\n\n// O(k)\n\nMint\
    \ comb_slow(ll n, ll k) {\n    Mint res = 1;\n    for (int i = 0; i < k; ++i)\
    \ {\n        res = res * (n - i) * inv[i + 1];\n    }\n    return res;\n}\n\n\
    // line up\n// a 'o' + b 'x'\nMint comb2(int a, int b) {\n    if (a < 0 || b <\
    \ 0) return 0;\n    return comb(a + b, a);\n}\n\n// O(p + log_p n)\n\nMint lucas(ll\
    \ n, ll k, int p) {\n    if (n < 0 || k < 0 || k > n) return Mint(0);\n    Mint\
    \ res = 1;\n    while (n > 0) {\n        res *= comb(n % p, k % p);\n        n\
    \ /= p;\n        k /= p;\n    }\n    return res;\n}\n\n/**\n * @docs docs/ntt.md\n\
    \ */\n\ntemplate <class D>\nstruct NumberTheoreticTransform {\n    D root;\n \
    \   V<D> roots = {0, 1};\n    V<int> rev = {0, 1};\n    int base = 1, max_base\
    \ = -1;\n\n    void init() {\n        int mod = D::get_mod();\n        int tmp\
    \ = mod - 1;\n        max_base = 0;\n        while (tmp % 2 == 0) {\n        \
    \    tmp /= 2;\n            max_base++;\n        }\n\n        root = 2;\n\n  \
    \      while (true) {\n            if (root.pow(1 << max_base).v == 1) {\n   \
    \             if (root.pow(1 << (max_base - 1)).v != 1) {\n                  \
    \  break;\n                }\n            }\n            root++;\n        }\n\
    \    }\n\n    void ensure_base(int nbase) {\n        if (max_base == -1) init();\n\
    \        if (nbase <= base) return;\n        assert(nbase <= max_base);\n\n  \
    \      rev.resize(1 << nbase);\n        for (int i = 0; i < (1 << nbase); ++i)\
    \ {\n            rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));\n   \
    \     }\n        roots.resize(1 << nbase);\n\n        while (base < nbase) {\n\
    \            D z = root.pow(1 << (max_base - 1 - base));\n            for (int\
    \ i = 1 << (base - 1); i < (1 << base); ++i) {\n                roots[i << 1]\
    \ = roots[i];\n                roots[(i << 1) + 1] = roots[i] * z;\n         \
    \   }\n            ++base;\n        }\n    }\n\n    void ntt(V<D>& a, bool inv\
    \ = false) {\n        int n = a.size();\n        // assert((n & (n - 1)) == 0);\n\
    \        int zeros = __builtin_ctz(n);\n        ensure_base(zeros);\n        int\
    \ shift = base - zeros;\n\n        for (int i = 0; i < n; i++) {\n           \
    \ if (i < (rev[i] >> shift)) {\n                swap(a[i], a[rev[i] >> shift]);\n\
    \            }\n        }\n\n        for (int k = 1; k < n; k <<= 1) {\n     \
    \       for (int i = 0; i < n; i += 2 * k) {\n                for (int j = 0;\
    \ j < k; j++) {\n                    D x = a[i + j];\n                    D y\
    \ = a[i + j + k] * roots[j + k];\n                    a[i + j] = x + y;\n    \
    \                a[i + j + k] = x - y;\n                }\n            }\n   \
    \     }\n\n        int v = D(n).inv().v;\n        if (inv) {\n            reverse(a.begin()\
    \ + 1, a.end());\n            for (int i = 0; i < n; i++) {\n                a[i]\
    \ *= v;\n            }\n        }\n    }\n\n    V<D> mul(V<D> a, V<D> b) {\n \
    \       if (a.size() == 0 && b.size() == 0) return {};\n        int s = a.size()\
    \ + b.size() - 1;\n        int nbase = 1;\n        while ((1 << nbase) < s) nbase++;\n\
    \        int sz = 1 << nbase;\n        a.resize(sz);\n        b.resize(sz);\n\
    \        ntt(a);\n        ntt(b);\n\n        for (int i = 0; i < sz; i++) {\n\
    \            a[i] *= b[i];\n        }\n        ntt(a, true);\n\n        a.resize(s);\n\
    \        return a;\n    }\n};\n\n// T : modint\ntemplate <class T>\nvoid ntt_2d(VV<T>&\
    \ a, bool rev) {\n    if (a.size() == 0 || a[0].size() == 0) return;\n    int\
    \ h = a.size(), w = a[0].size();\n\n    NumberTheoreticTransform<T> fft;\n   \
    \ fft.init();\n\n    for (auto& v : a) {\n        fft.ntt(v, rev);\n    }\n\n\
    \    rep(j, w) {\n        V<T> vh(h);\n        rep(i, h) { vh[i] = a[i][j]; }\n\
    \        fft.ntt(vh, rev);\n        rep(i, h) { a[i][j] = vh[i]; }\n    }\n}\n\
    \n// depends on FFT libs\n// basically use with ModInt\n\nNumberTheoreticTransform<Mint>\
    \ ntt;\n\n// divide n people into k groups\n// enumerate S(n, k)\n// for 0 \\\
    leq k \\leq n\n\nV<Mint> stirling_second(int n) {\n    V<Mint> a(n + 1), b(n +\
    \ 1);\n    rep(i, n + 1) {\n        a[i] = ifact[i] * (i % 2 ? -1 : 1);\n    \
    \    b[i] = Mint(i).pow(n) * ifact[i];\n    }\n    auto c = ntt.mul(a, b);\n \
    \   c.resize(n + 1);\n    return c;\n}\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n    init();\n    ntt.init();\n\n    int n;\n\
    \    cin >> n;\n    auto v = stirling_second(n);\n    for (int i = 0; i <= n;\
    \ ++i) {\n        cout << v[i] << (i == n ? '\\n' : ' ');\n    }\n\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind\"\
    \n\n//#pragma GCC optimize(\"Ofast\")\n//#pragma GCC optimize(\"unroll-loops\"\
    )\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = int64_t;\nusing\
    \ ull = uint64_t;\nusing pii = pair<int, int>;\ntemplate <class T>\nusing V =\
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
    \ (void(0))\n#define dump(x) (void(0))\n#endif\n\ntemplate <unsigned int MOD>\n\
    struct ModInt {\n    using uint = unsigned int;\n    using ull = unsigned long\
    \ long;\n    using M = ModInt;\n\n    uint v;\n\n    ModInt(ll _v = 0) { set_norm(_v\
    \ % MOD + MOD); }\n    M& set_norm(uint _v) {  //[0, MOD * 2)->[0, MOD)\n    \
    \    v = (_v < MOD) ? _v : _v - MOD;\n        return *this;\n    }\n\n    explicit\
    \ operator bool() const { return v != 0; }\n    explicit operator int() const\
    \ { return v; }\n    M operator+(const M& a) const { return M().set_norm(v + a.v);\
    \ }\n    M operator-(const M& a) const { return M().set_norm(v + MOD - a.v); }\n\
    \    M operator*(const M& a) const { return M().set_norm(ull(v) * a.v % MOD);\
    \ }\n    M operator/(const M& a) const { return *this * a.inv(); }\n    M& operator+=(const\
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
    \ -= t * q, q);\n        }\n        return M(p);\n    }\n\n    friend ostream&\
    \ operator<<(ostream& os, const M& a) { return os << a.v; }\n    friend istream&\
    \ operator>>(istream& in, M& x) {\n        ll v_;\n        in >> v_;\n       \
    \ x = M(v_);\n        return in;\n    }\n\n    bool operator<(const M& r) const\
    \ { return v < r.v; }\n    bool operator>(const M& r) const { return v < *this;\
    \ }\n    bool operator<=(const M& r) const { return !(r < *this); }\n    bool\
    \ operator>=(const M& r) const { return !(*this < r); }\n    bool operator==(const\
    \ M& a) const { return v == a.v; }\n    bool operator!=(const M& a) const { return\
    \ v != a.v; }\n\n    static uint get_mod() { return MOD; }\n};\n\n// using Mint\
    \ = ModInt<1000000007>;\nusing Mint = ModInt<998244353>;\n\nconst int maxv = 1000010;\n\
    \nV<Mint> fact(maxv), ifact(maxv), inv(maxv);\n\nvoid init() {\n    fact[0] =\
    \ 1;\n    for (int i = 1; i < maxv; ++i) {\n        fact[i] = fact[i - 1] * i;\n\
    \    }\n\n    ifact[maxv - 1] = fact[maxv - 1].inv();\n\n    for (int i = maxv\
    \ - 2; i >= 0; --i) {\n        ifact[i] = ifact[i + 1] * (i + 1);\n    }\n\n \
    \   for (int i = 1; i < maxv; ++i) {\n        inv[i] = ifact[i] * fact[i - 1];\n\
    \    }\n}\n\nMint comb(int n, int r) {\n    if (n < 0 || r < 0 || r > n) return\
    \ Mint(0);\n    return fact[n] * ifact[r] * ifact[n - r];\n}\n\n// O(k)\n\nMint\
    \ comb_slow(ll n, ll k) {\n    Mint res = 1;\n    for (int i = 0; i < k; ++i)\
    \ {\n        res = res * (n - i) * inv[i + 1];\n    }\n    return res;\n}\n\n\
    // line up\n// a 'o' + b 'x'\nMint comb2(int a, int b) {\n    if (a < 0 || b <\
    \ 0) return 0;\n    return comb(a + b, a);\n}\n\n// O(p + log_p n)\n\nMint lucas(ll\
    \ n, ll k, int p) {\n    if (n < 0 || k < 0 || k > n) return Mint(0);\n    Mint\
    \ res = 1;\n    while (n > 0) {\n        res *= comb(n % p, k % p);\n        n\
    \ /= p;\n        k /= p;\n    }\n    return res;\n}\n\n/**\n * @docs docs/ntt.md\n\
    \ */\n\ntemplate <class D>\nstruct NumberTheoreticTransform {\n    D root;\n \
    \   V<D> roots = {0, 1};\n    V<int> rev = {0, 1};\n    int base = 1, max_base\
    \ = -1;\n\n    void init() {\n        int mod = D::get_mod();\n        int tmp\
    \ = mod - 1;\n        max_base = 0;\n        while (tmp % 2 == 0) {\n        \
    \    tmp /= 2;\n            max_base++;\n        }\n\n        root = 2;\n\n  \
    \      while (true) {\n            if (root.pow(1 << max_base).v == 1) {\n   \
    \             if (root.pow(1 << (max_base - 1)).v != 1) {\n                  \
    \  break;\n                }\n            }\n            root++;\n        }\n\
    \    }\n\n    void ensure_base(int nbase) {\n        if (max_base == -1) init();\n\
    \        if (nbase <= base) return;\n        assert(nbase <= max_base);\n\n  \
    \      rev.resize(1 << nbase);\n        for (int i = 0; i < (1 << nbase); ++i)\
    \ {\n            rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));\n   \
    \     }\n        roots.resize(1 << nbase);\n\n        while (base < nbase) {\n\
    \            D z = root.pow(1 << (max_base - 1 - base));\n            for (int\
    \ i = 1 << (base - 1); i < (1 << base); ++i) {\n                roots[i << 1]\
    \ = roots[i];\n                roots[(i << 1) + 1] = roots[i] * z;\n         \
    \   }\n            ++base;\n        }\n    }\n\n    void ntt(V<D>& a, bool inv\
    \ = false) {\n        int n = a.size();\n        // assert((n & (n - 1)) == 0);\n\
    \        int zeros = __builtin_ctz(n);\n        ensure_base(zeros);\n        int\
    \ shift = base - zeros;\n\n        for (int i = 0; i < n; i++) {\n           \
    \ if (i < (rev[i] >> shift)) {\n                swap(a[i], a[rev[i] >> shift]);\n\
    \            }\n        }\n\n        for (int k = 1; k < n; k <<= 1) {\n     \
    \       for (int i = 0; i < n; i += 2 * k) {\n                for (int j = 0;\
    \ j < k; j++) {\n                    D x = a[i + j];\n                    D y\
    \ = a[i + j + k] * roots[j + k];\n                    a[i + j] = x + y;\n    \
    \                a[i + j + k] = x - y;\n                }\n            }\n   \
    \     }\n\n        int v = D(n).inv().v;\n        if (inv) {\n            reverse(a.begin()\
    \ + 1, a.end());\n            for (int i = 0; i < n; i++) {\n                a[i]\
    \ *= v;\n            }\n        }\n    }\n\n    V<D> mul(V<D> a, V<D> b) {\n \
    \       if (a.size() == 0 && b.size() == 0) return {};\n        int s = a.size()\
    \ + b.size() - 1;\n        int nbase = 1;\n        while ((1 << nbase) < s) nbase++;\n\
    \        int sz = 1 << nbase;\n        a.resize(sz);\n        b.resize(sz);\n\
    \        ntt(a);\n        ntt(b);\n\n        for (int i = 0; i < sz; i++) {\n\
    \            a[i] *= b[i];\n        }\n        ntt(a, true);\n\n        a.resize(s);\n\
    \        return a;\n    }\n};\n\n// T : modint\ntemplate <class T>\nvoid ntt_2d(VV<T>&\
    \ a, bool rev) {\n    if (a.size() == 0 || a[0].size() == 0) return;\n    int\
    \ h = a.size(), w = a[0].size();\n\n    NumberTheoreticTransform<T> fft;\n   \
    \ fft.init();\n\n    for (auto& v : a) {\n        fft.ntt(v, rev);\n    }\n\n\
    \    rep(j, w) {\n        V<T> vh(h);\n        rep(i, h) { vh[i] = a[i][j]; }\n\
    \        fft.ntt(vh, rev);\n        rep(i, h) { a[i][j] = vh[i]; }\n    }\n}\n\
    \n// depends on FFT libs\n// basically use with ModInt\n\nNumberTheoreticTransform<Mint>\
    \ ntt;\n\n// divide n people into k groups\n// enumerate S(n, k)\n// for 0 \\\
    leq k \\leq n\n\nV<Mint> stirling_second(int n) {\n    V<Mint> a(n + 1), b(n +\
    \ 1);\n    rep(i, n + 1) {\n        a[i] = ifact[i] * (i % 2 ? -1 : 1);\n    \
    \    b[i] = Mint(i).pow(n) * ifact[i];\n    }\n    auto c = ntt.mul(a, b);\n \
    \   c.resize(n + 1);\n    return c;\n}\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n    init();\n    ntt.init();\n\n    int n;\n\
    \    cin >> n;\n    auto v = stirling_second(n);\n    for (int i = 0; i <= n;\
    \ ++i) {\n        cout << v[i] << (i == n ? '\\n' : ' ');\n    }\n\n    return\
    \ 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/stirling_number_of_the_second_kind.test.cpp
  requiredBy: []
  timestamp: '2021-05-01 18:46:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/stirling_number_of_the_second_kind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/stirling_number_of_the_second_kind.test.cpp
- /verify/test/yosupo/stirling_number_of_the_second_kind.test.cpp.html
title: test/yosupo/stirling_number_of_the_second_kind.test.cpp
---
## 前提
- $p - 1$ が十分大きい $2$ べきで割り切れる場合に $\mod p$ で積を計算する
- modint ライブラリと併用する

## 例題

2D NTT

- https://yukicoder.me/problems/no/1241

- https://atcoder.jp/contests/jag2013spring/tasks/icpc2013spring_f (まだ)