---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/ntt.md
    links:
    - https://atcoder.jp/contests/ABC265/editorial/4577
  bundledCode: "#line 1 \"test/yosupo/pow_of_formal_power_series_sparse.cpp\"\n#pragma\
    \ region satashun\n#include <algorithm>\n#include <array>\n#include <atomic>\n\
    #include <bitset>\n#include <cassert>\n#include <chrono>\n#include <complex>\n\
    #include <condition_variable>\n#include <deque>\n#include <exception>\n#include\
    \ <forward_list>\n#include <fstream>\n#include <functional>\n#include <future>\n\
    #include <initializer_list>\n#include <iomanip>\n#include <ios>\n#include <iosfwd>\n\
    #include <iostream>\n#include <istream>\n#include <iterator>\n#include <limits>\n\
    #include <list>\n#include <locale>\n#include <map>\n#include <memory>\n#include\
    \ <mutex>\n#include <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n\
    #include <random>\n#include <ratio>\n#include <regex>\n#include <scoped_allocator>\n\
    #include <set>\n#include <sstream>\n#include <stack>\n#include <stdexcept>\n#include\
    \ <streambuf>\n#include <string>\n#include <system_error>\n#include <thread>\n\
    #include <tuple>\n#include <type_traits>\n#include <typeindex>\n#include <typeinfo>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include\
    \ <valarray>\n#include <vector>\n// #pragma GCC optimize(\"Ofast\")\n// #pragma\
    \ GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nusing uint = unsigned int;\nusing ll = long long;\nusing ull = unsigned long\
    \ long;\nusing pii = pair<int, int>;\ntemplate <class T>\nusing V = vector<T>;\n\
    template <class T>\nusing VV = V<V<T>>;\n\ntemplate <class T>\nV<T> make_vec(size_t\
    \ a) {\n    return V<T>(a);\n}\n\ntemplate <class T, class... Ts>\nauto make_vec(size_t\
    \ a, Ts... ts) {\n    return V<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));\n\
    }\n\ntemplate <typename T, typename V>\nvoid fill_vec(T& v, const V& val) {\n\
    \    v = val;\n}\n\ntemplate <typename T, typename V>\nvoid fill_vec(vector<T>&\
    \ vec, const V& val) {\n    for (auto& v : vec) fill_vec(v, val);\n}\n\n#define\
    \ pb push_back\n#define eb emplace_back\n#define mp make_pair\n#define fi first\n\
    #define se second\n#define rep(i, n) rep2(i, 0, n)\n#define rep2(i, m, n) for\
    \ (int i = m; i < (n); i++)\n#define per(i, b) per2(i, 0, b)\n#define per2(i,\
    \ a, b) for (int i = int(b) - 1; i >= int(a); i--)\n#define ALL(c) (c).begin(),\
    \ (c).end()\n#define SZ(x) ((int)(x).size())\n\nconstexpr ll TEN(int n) { return\
    \ (n == 0) ? 1 : 10 * TEN(n - 1); }\n\ntemplate <class T, class U>\nvoid chmin(T&\
    \ t, const U& u) {\n    if (t > u) t = u;\n}\ntemplate <class T, class U>\nvoid\
    \ chmax(T& t, const U& u) {\n    if (t < u) t = u;\n}\n\ntemplate <typename T>\n\
    int arglb(const V<T>& v, const T& x) {\n    return distance(v.begin(), lower_bound(ALL(v),\
    \ x));\n}\n\ntemplate <typename T>\nint argub(const V<T>& v, const T& x) {\n \
    \   return distance(v.begin(), upper_bound(ALL(v), x));\n}\n\ntemplate <class\
    \ T>\nvoid mkuni(vector<T>& v) {\n    sort(ALL(v));\n    v.erase(unique(ALL(v)),\
    \ end(v));\n}\n\ntemplate <class T>\nvector<int> sort_by(const vector<T>& v, bool\
    \ increasing = true) {\n    vector<int> res(v.size());\n    iota(res.begin(),\
    \ res.end(), 0);\n\n    if (increasing) {\n        stable_sort(res.begin(), res.end(),\n\
    \                    [&](int i, int j) { return v[i] < v[j]; });\n    } else {\n\
    \        stable_sort(res.begin(), res.end(),\n                    [&](int i, int\
    \ j) { return v[i] > v[j]; });\n    }\n    return res;\n}\n\n// prototype\ntemplate\
    \ <class T, class U>\nostream& operator<<(ostream& os, const pair<T, U>& p);\n\
    \ntemplate <class T>\nostream& operator<<(ostream& os, const vector<T>& v);\n\n\
    template <class T>\nistream& operator>>(istream& is, vector<T>& v);\n\ntemplate\
    \ <class T, size_t sz>\nostream& operator<<(ostream& os, const array<T, sz>& arr);\n\
    \ntemplate <class T>\nostream& operator<<(ostream& os, const set<T>& ST);\n\n\
    template <class T>\nostream& operator<<(ostream& os, const unordered_set<T>& ST);\n\
    \ntemplate <class T>\nostream& operator<<(ostream& os, const multiset<T>& ST);\n\
    \ntemplate <class T, class U>\nostream& operator<<(ostream& os, const map<T, U>&\
    \ MP);\n\ntemplate <class T, class U>\nostream& operator<<(ostream& os, const\
    \ unordered_map<T, U>& MP);\n\nostream& operator<<(ostream& o, __int128_t x);\n\
    \n// io functions\ntemplate <class T, class U>\nistream& operator>>(istream& is,\
    \ pair<T, U>& p) {\n    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate\
    \ <class T, class U>\nostream& operator<<(ostream& os, const pair<T, U>& p) {\n\
    \    os << \"(\" << p.first << \",\" << p.second << \")\";\n    return os;\n}\n\
    \ntemplate <class T>\nistream& operator>>(istream& is, vector<T>& v) {\n    for\
    \ (auto& x : v) {\n        is >> x;\n    }\n    return is;\n}\n\ntemplate <class\
    \ T>\nostream& operator<<(ostream& os, const vector<T>& v) {\n    os << \"{\"\
    ;\n    rep(i, v.size()) {\n        if (i) os << \",\";\n        os << v[i];\n\
    \    }\n    os << \"}\";\n    return os;\n}\n\ntemplate <class T, size_t sz>\n\
    ostream& operator<<(ostream& os, const array<T, sz>& arr) {\n    os << '[';\n\
    \    for (auto v : arr) os << v << ',';\n    os << ']';\n    return os;\n}\n\n\
    template <class T>\nostream& operator<<(ostream& os, const set<T>& ST) {\n   \
    \ os << \"{\";\n    for (auto it = ST.begin(); it != ST.end(); ++it) {\n     \
    \   if (it != ST.begin()) os << \",\";\n        os << *it;\n    }\n    os << \"\
    }\";\n    return os;\n}\n\ntemplate <class T>\nostream& operator<<(ostream& os,\
    \ const unordered_set<T>& ST) {\n    os << \"{\";\n    for (auto it = ST.begin();\
    \ it != ST.end(); ++it) {\n        if (it != ST.begin()) os << \",\";\n      \
    \  os << *it;\n    }\n    os << \"}\";\n    return os;\n}\n\ntemplate <class T>\n\
    ostream& operator<<(ostream& os, const multiset<T>& ST) {\n    os << \"{\";\n\
    \    for (auto it = ST.begin(); it != ST.end(); ++it) {\n        if (it != ST.begin())\
    \ os << \",\";\n        os << *it;\n    }\n    os << \"}\";\n    return os;\n\
    }\n\ntemplate <class T, class U>\nostream& operator<<(ostream& os, const map<T,\
    \ U>& MP) {\n    for (auto it = MP.begin(); it != MP.end(); ++it) {\n        os\
    \ << \"(\" << it->first << \": \" << it->second << \")\";\n    }\n    return os;\n\
    }\n\ntemplate <class T, class U>\nostream& operator<<(ostream& os, const unordered_map<T,\
    \ U>& MP) {\n    for (auto it = MP.begin(); it != MP.end(); ++it) {\n        os\
    \ << \"(\" << it->first << \": \" << it->second << \")\";\n    }\n    return os;\n\
    }\n\nstring to_string(__int128_t x) {\n    if (x == 0) return \"0\";\n    string\
    \ result;\n    if (x < 0) {\n        result += \"-\";\n        x *= -1;\n    }\n\
    \    string t;\n    while (x) {\n        t.push_back('0' + x % 10);\n        x\
    \ /= 10;\n    }\n    reverse(t.begin(), t.end());\n    return result + t;\n}\n\
    \nostream& operator<<(ostream& o, __int128_t x) { return o << to_string(x); }\n\
    \n#ifdef LOCAL\nvoid debug_out() { cerr << endl; }\ntemplate <typename Head, typename...\
    \ Tail>\nvoid debug_out(Head H, Tail... T) {\n    cerr << \" \" << H;\n    debug_out(T...);\n\
    }\n#define debug(...) \\\n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"\
    ]:\", debug_out(__VA_ARGS__)\n#define dump(x) cerr << __LINE__ << \" \" << #x\
    \ << \" = \" << (x) << endl\n#else\n#define debug(...) (void(0))\n#define dump(x)\
    \ (void(0))\n#endif\n\ntemplate <class T>\nV<T>& operator+=(V<T>& vec, const T&\
    \ v) {\n    for (auto& x : vec) x += v;\n    return vec;\n}\n\ntemplate <class\
    \ T>\nV<T>& operator-=(V<T>& vec, const T& v) {\n    for (auto& x : vec) x -=\
    \ v;\n    return vec;\n}\n\n// suc : 1 = newline, 2 = space\ntemplate <class T>\n\
    void print(T x, int suc = 1) {\n    cout << x;\n    if (suc == 1)\n        cout\
    \ << \"\\n\";\n    else if (suc == 2)\n        cout << \" \";\n}\n\ntemplate <class\
    \ T>\nvoid print(const vector<T>& v, int suc = 1) {\n    for (int i = 0; i < v.size();\
    \ ++i)\n        print(v[i], i == int(v.size()) - 1 ? suc : 2);\n}\n\ntemplate\
    \ <class T>\nvoid show(T x) {\n    print(x, 1);\n}\n\ntemplate <typename Head,\
    \ typename... Tail>\nvoid show(Head H, Tail... T) {\n    print(H, 2);\n    show(T...);\n\
    }\n\nint topbit(int t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }\nint topbit(ll\
    \ t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }\nint botbit(int a) { return\
    \ a == 0 ? 32 : __builtin_ctz(a); }\nint botbit(ll a) { return a == 0 ? 64 : __builtin_ctzll(a);\
    \ }\nint popcount(int t) { return __builtin_popcount(t); }\nint popcount(ll t)\
    \ { return __builtin_popcountll(t); }\nint bit_parity(int t) { return __builtin_parity(t);\
    \ }\nint bit_parity(ll t) { return __builtin_parityll(t); }\n\nstruct prepare_io\
    \ {\n    prepare_io() {\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(10);\n    }\n} prep_io;\n#pragma endregion\
    \ satashun\n\ntemplate <unsigned int MOD>\nstruct ModInt {\n    using uint = unsigned\
    \ int;\n    using ull = unsigned long long;\n    using M = ModInt;\n\n    uint\
    \ v;\n\n    ModInt(ll _v = 0) { set_norm(_v % MOD + MOD); }\n    M& set_norm(uint\
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
    \ ModInt<998244353>;\n\nV<Mint> fact, ifact, inv;\nVV<Mint> small_comb;\n\nvoid\
    \ mod_init() {\n    const int maxv = 1000010;\n    const int maxvv = 5000;\n\n\
    \    fact.resize(maxv);\n    ifact.resize(maxv);\n    inv.resize(maxv);\n\n  \
    \  small_comb = make_vec<Mint>(maxvv, maxvv);\n\n    fact[0] = 1;\n    for (int\
    \ i = 1; i < maxv; ++i) {\n        fact[i] = fact[i - 1] * i;\n    }\n\n    ifact[maxv\
    \ - 1] = fact[maxv - 1].inv();\n\n    for (int i = maxv - 2; i >= 0; --i) {\n\
    \        ifact[i] = ifact[i + 1] * (i + 1);\n    }\n\n    for (int i = 1; i <\
    \ maxv; ++i) {\n        inv[i] = ifact[i] * fact[i - 1];\n    }\n\n    for (int\
    \ i = 0; i < maxvv; ++i) {\n        small_comb[i][0] = small_comb[i][i] = 1;\n\
    \        for (int j = 1; j < i; ++j) {\n            small_comb[i][j] = small_comb[i\
    \ - 1][j] + small_comb[i - 1][j - 1];\n        }\n    }\n}\n\nMint comb(int n,\
    \ int r) {\n    if (n < 0 || r < 0 || r > n) return Mint(0);\n    if (n < small_comb.size())\
    \ return small_comb[n][r];\n    return fact[n] * ifact[r] * ifact[n - r];\n}\n\
    \nMint inv_comb(int n, int r) {\n    if (n < 0 || r < 0 || r > n) return Mint(0);\n\
    \    return ifact[n] * fact[r] * fact[n - r];\n}\n\n// O(k)\nMint comb_slow(ll\
    \ n, ll k) {\n    if (n < 0 || k < 0 || k > n) return Mint(0);\n    Mint res =\
    \ ifact[k];\n    for (int i = 0; i < k; ++i) {\n        res = res * (n - i);\n\
    \    }\n    return res;\n}\n\n// line up\n// a 'o' + b 'x'\nMint comb2(int a,\
    \ int b) {\n    if (a < 0 || b < 0) return 0;\n    return comb(a + b, a);\n}\n\
    \n// divide a into b groups\nMint nhr(int a, int b) {\n    if (b == 0) return\
    \ Mint(a == 0);\n    return comb(a + b - 1, a);\n}\n\n// O(p + log_p n)\n\nMint\
    \ lucas(ll n, ll k, int p) {\n    if (n < 0 || k < 0 || k > n) return Mint(0);\n\
    \    Mint res = 1;\n    while (n > 0) {\n        res *= comb(n % p, k % p);\n\
    \        n /= p;\n        k /= p;\n    }\n    return res;\n}\n\nstruct ModPrepare\
    \ {\n    ModPrepare() { mod_init(); }\n} prep_mod;\n\n/**\n * @docs docs/ntt.md\n\
    \ */\n\n// \u89E3\u8AAC: https://atcoder.jp/contests/ABC265/editorial/4577\n\n\
    template <class D>\nstruct NumberTheoreticTransform {\n    D root;\n    V<D> roots\
    \ = {0, 1};\n    V<int> rev = {0, 1};\n    int base = 1, max_base = -1;\n\n  \
    \  void init() {\n        int mod = D::get_mod();\n        int tmp = mod - 1;\n\
    \        max_base = 0;\n        while (tmp % 2 == 0) {\n            tmp /= 2;\n\
    \            max_base++;\n        }\n\n        root = 2;\n\n        while (true)\
    \ {\n            if (root.pow(1 << max_base).v == 1) {\n                if (root.pow(1\
    \ << (max_base - 1)).v != 1) {\n                    break;\n                }\n\
    \            }\n            root++;\n        }\n    }\n\n    void ensure_base(int\
    \ nbase) {\n        if (max_base == -1) init();\n        if (nbase <= base) return;\n\
    \        assert(nbase <= max_base);\n\n        rev.resize(1 << nbase);\n     \
    \   for (int i = 0; i < (1 << nbase); ++i) {\n            rev[i] = (rev[i >> 1]\
    \ >> 1) + ((i & 1) << (nbase - 1));\n        }\n        roots.resize(1 << nbase);\n\
    \n        while (base < nbase) {\n            D z = root.pow(1 << (max_base -\
    \ 1 - base));\n            for (int i = 1 << (base - 1); i < (1 << base); ++i)\
    \ {\n                roots[i << 1] = roots[i];\n                roots[(i << 1)\
    \ + 1] = roots[i] * z;\n            }\n            ++base;\n        }\n    }\n\
    \n    // FPS24 - R\n    void ntt(V<D>& a, bool inv = false) {\n        int n =\
    \ a.size();\n        // assert((n & (n - 1)) == 0);\n        int zeros = __builtin_ctz(n);\n\
    \        ensure_base(zeros);\n        int shift = base - zeros;\n\n        for\
    \ (int i = 0; i < n; i++) {\n            if (i < (rev[i] >> shift)) {\n      \
    \          swap(a[i], a[rev[i] >> shift]);\n            }\n        }\n\n     \
    \   for (int k = 1; k < n; k <<= 1) {\n            for (int i = 0; i < n; i +=\
    \ 2 * k) {\n                for (int j = 0; j < k; j++) {\n                  \
    \  D x = a[i + j];\n                    D y = a[i + j + k] * roots[j + k];\n \
    \                   a[i + j] = x + y;\n                    a[i + j + k] = x -\
    \ y;\n                }\n            }\n        }\n\n        if (inv) {\n    \
    \        int v = D(n).inv().v;\n            reverse(a.begin() + 1, a.end());\n\
    \            for (int i = 0; i < n; i++) {\n                a[i] *= v;\n     \
    \       }\n        }\n    }\n\n    V<D> mul(V<D> a, V<D> b) {\n        if (a.size()\
    \ == 0 && b.size() == 0) return {};\n        int s = a.size() + b.size() - 1;\n\
    \        int nbase = 1;\n        while ((1 << nbase) < s) nbase++;\n        int\
    \ sz = 1 << nbase;\n\n        if (sz <= 16) {\n            V<D> ret(s);\n    \
    \        for (int i = 0; i < a.size(); i++) {\n                for (int j = 0;\
    \ j < b.size(); j++) ret[i + j] += a[i] * b[j];\n            }\n            return\
    \ ret;\n        }\n\n        a.resize(sz);\n        b.resize(sz);\n        ntt(a);\n\
    \        ntt(b);\n\n        for (int i = 0; i < sz; i++) {\n            a[i] *=\
    \ b[i];\n        }\n        ntt(a, true);\n\n        a.resize(s);\n        return\
    \ a;\n    }\n};\n\n// T : modint\ntemplate <class T>\nvoid ntt_2d(VV<T>& a, bool\
    \ rev) {\n    if (a.size() == 0 || a[0].size() == 0) return;\n    int h = a.size(),\
    \ w = a[0].size();\n\n    NumberTheoreticTransform<T> fft;\n    fft.init();\n\n\
    \    for (auto& v : a) {\n        fft.ntt(v, rev);\n    }\n\n    rep(j, w) {\n\
    \        V<T> vh(h);\n        rep(i, h) { vh[i] = a[i][j]; }\n        fft.ntt(vh,\
    \ rev);\n        rep(i, h) { a[i][j] = vh[i]; }\n    }\n}\n\nNumberTheoreticTransform<Mint>\
    \ ntt;\n\nstruct prepare_NTT {\n    prepare_NTT() { ntt.init(); }\n} prep_NTT;\n\
    \ntemplate <class D>\nstruct Poly : public V<D> {\n    template <class... Args>\n\
    \    Poly(Args... args) : V<D>(args...) {}\n    Poly(initializer_list<D> init)\
    \ : V<D>(init.begin(), init.end()) {}\n\n    int size() const { return V<D>::size();\
    \ }\n    D at(int p) const { return (p < this->size() ? (*this)[p] : D(0)); }\n\
    \n    // first len terms\n    Poly pref(int len) const {\n        return Poly(this->begin(),\
    \ this->begin() + min(this->size(), len));\n    }\n\n    // for polynomial division\n\
    \    Poly rev() const {\n        Poly res = *this;\n        reverse(res.begin(),\
    \ res.end());\n        return res;\n    }\n\n    Poly operator+(const Poly& r)\
    \ const {\n        auto n = max(size(), r.size());\n        V<D> tmp(n);\n   \
    \     for (int i = 0; i < n; ++i) {\n            tmp[i] = at(i) + r.at(i);\n \
    \       }\n        return tmp;\n    }\n    Poly operator-(const Poly& r) const\
    \ {\n        auto n = max(size(), r.size());\n        V<D> tmp(n);\n        for\
    \ (int i = 0; i < n; ++i) {\n            tmp[i] = at(i) - r.at(i);\n        }\n\
    \        return tmp;\n    }\n\n    // scalar\n    Poly operator*(const D& k) const\
    \ {\n        int n = size();\n        V<D> tmp(n);\n        for (int i = 0; i\
    \ < n; ++i) {\n            tmp[i] = at(i) * k;\n        }\n        return tmp;\n\
    \    }\n\n    Poly operator*(const Poly& r) const {\n        Poly a = *this;\n\
    \        Poly b = r;\n        auto v = ntt.mul(a, b);\n        return v;\n   \
    \ }\n\n    // scalar\n    Poly operator/(const D& k) const { return *this * k.inv();\
    \ }\n\n    Poly operator/(const Poly& r) const {\n        if (size() < r.size())\
    \ {\n            return {{}};\n        }\n        int d = size() - r.size() +\
    \ 1;\n        return (rev().pref(d) * r.rev().inv(d)).pref(d).rev();\n    }\n\n\
    \    Poly operator%(const Poly& r) const {\n        auto res = *this - *this /\
    \ r * r;\n        while (res.size() && !res.back()) {\n            res.pop_back();\n\
    \        }\n        return res;\n    }\n\n    Poly diff() const {\n        V<D>\
    \ res(max(0, size() - 1));\n        for (int i = 1; i < size(); ++i) {\n     \
    \       res[i - 1] = at(i) * i;\n        }\n        return res;\n    }\n\n   \
    \ Poly inte() const {\n        V<D> res(size() + 1);\n        for (int i = 0;\
    \ i < size(); ++i) {\n            res[i + 1] = at(i) / (D)(i + 1);\n        }\n\
    \        return res;\n    }\n\n    // f * f.inv(m) === 1 mod (x^m)\n    // f_0\
    \ ^ -1 must exist\n    Poly inv(int m) const {\n        Poly res = Poly({D(1)\
    \ / at(0)});\n        for (int i = 1; i < m; i *= 2) {\n            res = (res\
    \ * D(2) - res * res * pref(i * 2)).pref(i * 2);\n        }\n        return res.pref(m);\n\
    \    }\n\n    // f_0 = 1 must hold\n    Poly log(int n) const {\n        auto\
    \ f = pref(n);\n        return (f.diff() * f.inv(n - 1)).pref(n - 1).inte();\n\
    \    }\n\n    // f_0 = 0 must hold\n    Poly exp(int n) const {\n        auto\
    \ h = diff();\n        Poly f({1}), g({1});\n\n        for (int m = 1; m < n;\
    \ m *= 2) {\n            g = (g * D(2) - f * g * g).pref(m);\n            auto\
    \ q = h.pref(m - 1);\n            auto w = (q + g * (f.diff() - f * q)).pref(m\
    \ * 2 - 1);\n            f = (f + f * (*this - w.inte()).pref(m * 2)).pref(m *\
    \ 2);\n        }\n\n        return f.pref(n);\n    }\n\n    // be careful when\
    \ k = 0\n    Poly pow(int n, ll k) const { return (log(n) * (D)k).exp(n); }\n\n\
    \    // f_0 = 1 must hold (use it with modular sqrt)\n    // CF250E\n    Poly\
    \ sqrt(int n) const {\n        Poly f = pref(n);\n        Poly g({1});\n     \
    \   for (int i = 1; i < n; i *= 2) {\n            g = (g + f.pref(i * 2) * g.inv(i\
    \ * 2)) * D(2).inv();\n        }\n        return g.pref(n);\n    }\n\n    D eval(D\
    \ x) const {\n        D res = 0, c = 1;\n        for (auto a : *this) {\n    \
    \        res += a * c;\n            c *= x;\n        }\n        return res;\n\
    \    }\n\n    Poly& operator+=(const Poly& r) { return *this = *this + r; }\n\
    \    Poly& operator-=(const Poly& r) { return *this = *this - r; }\n    Poly&\
    \ operator*=(const D& r) { return *this = *this * r; }\n    Poly& operator*=(const\
    \ Poly& r) { return *this = *this * r; }\n    Poly& operator/=(const Poly& r)\
    \ { return *this = *this / r; }\n    Poly& operator/=(const D& r) { return *this\
    \ = *this / r; }\n    Poly& operator%=(const Poly& r) { return *this = *this %\
    \ r; }\n\n    friend ostream& operator<<(ostream& os, const Poly& pl) {\n    \
    \    if (pl.size() == 0) return os << \"0\";\n        for (int i = 0; i < pl.size();\
    \ ++i) {\n            if (pl[i]) {\n                os << pl[i] << \"x^\" << i;\n\
    \                if (i + 1 != pl.size()) os << \",\";\n            }\n       \
    \ }\n        return os;\n    }\n};\n\n// first d terms of f^k, where f is sparse.\n\
    // O(d * |i | f_i != 0|)\n// FPS24 - A\ntemplate <class T>\nV<T> pow_sparse(const\
    \ Poly<T>& f, ll k, int d) {\n    Poly<T> g(d);\n\n    if (k == 0) {\n       \
    \ if (d > 0) g[0] = 1;\n        return g;\n    }\n\n    V<pair<int, T>> fv;\n\
    \    rep(i, f.size()) {\n        if (f[i] != 0) fv.emplace_back(i, f[i]);\n  \
    \  }\n\n    if (SZ(fv) == 0) {\n        return g;\n    }\n\n    auto [head_pos,\
    \ head_val] = fv[0];\n    fv.erase(fv.begin());\n\n    for (auto& [j, val] : fv)\
    \ {\n        j -= head_pos;\n    }\n\n    Poly<T> gg(d);\n\n    gg[0] = head_val.pow(k);\n\
    \    Mint rev = head_val.inv();\n\n    for (int i = 0; i < d - 1; i++) {\n   \
    \     for (auto [j, val] : fv) {\n            if (i + 1 - j < 0) break;\n    \
    \        gg[i + 1] += gg[i + 1 - j] * val * (T(k) * j - (i - j + 1));\n      \
    \  }\n        gg[i + 1] *= inv[i + 1] * rev;\n    }\n\n    rep(i, d) {\n     \
    \   // k * head_pos < d-i\n        if (head_pos > 0 && k >= (d - i + head_pos\
    \ - 1) / head_pos) break;\n        ll p = k * head_pos + i;\n        g[p] = gg[i];\n\
    \    }\n    return g;\n}\n\nint main() {\n    int N, K;\n    ll M;\n    cin >>\
    \ N >> K >> M;\n    Poly<Mint> pl(N);\n    rep(i, K) {\n        int j, a;\n  \
    \      cin >> j >> a;\n        pl[j] = a;\n    }\n    pl = pow_sparse(pl, M, N);\n\
    \    rep(i, N) { cout << pl[i] << (i != N - 1 ? ' ' : '\\n'); }\n    return 0;\n\
    }\n"
  code: "#pragma region satashun\n#include <algorithm>\n#include <array>\n#include\
    \ <atomic>\n#include <bitset>\n#include <cassert>\n#include <chrono>\n#include\
    \ <complex>\n#include <condition_variable>\n#include <deque>\n#include <exception>\n\
    #include <forward_list>\n#include <fstream>\n#include <functional>\n#include <future>\n\
    #include <initializer_list>\n#include <iomanip>\n#include <ios>\n#include <iosfwd>\n\
    #include <iostream>\n#include <istream>\n#include <iterator>\n#include <limits>\n\
    #include <list>\n#include <locale>\n#include <map>\n#include <memory>\n#include\
    \ <mutex>\n#include <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n\
    #include <random>\n#include <ratio>\n#include <regex>\n#include <scoped_allocator>\n\
    #include <set>\n#include <sstream>\n#include <stack>\n#include <stdexcept>\n#include\
    \ <streambuf>\n#include <string>\n#include <system_error>\n#include <thread>\n\
    #include <tuple>\n#include <type_traits>\n#include <typeindex>\n#include <typeinfo>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include\
    \ <valarray>\n#include <vector>\n// #pragma GCC optimize(\"Ofast\")\n// #pragma\
    \ GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nusing uint = unsigned int;\nusing ll = long long;\nusing ull = unsigned long\
    \ long;\nusing pii = pair<int, int>;\ntemplate <class T>\nusing V = vector<T>;\n\
    template <class T>\nusing VV = V<V<T>>;\n\ntemplate <class T>\nV<T> make_vec(size_t\
    \ a) {\n    return V<T>(a);\n}\n\ntemplate <class T, class... Ts>\nauto make_vec(size_t\
    \ a, Ts... ts) {\n    return V<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));\n\
    }\n\ntemplate <typename T, typename V>\nvoid fill_vec(T& v, const V& val) {\n\
    \    v = val;\n}\n\ntemplate <typename T, typename V>\nvoid fill_vec(vector<T>&\
    \ vec, const V& val) {\n    for (auto& v : vec) fill_vec(v, val);\n}\n\n#define\
    \ pb push_back\n#define eb emplace_back\n#define mp make_pair\n#define fi first\n\
    #define se second\n#define rep(i, n) rep2(i, 0, n)\n#define rep2(i, m, n) for\
    \ (int i = m; i < (n); i++)\n#define per(i, b) per2(i, 0, b)\n#define per2(i,\
    \ a, b) for (int i = int(b) - 1; i >= int(a); i--)\n#define ALL(c) (c).begin(),\
    \ (c).end()\n#define SZ(x) ((int)(x).size())\n\nconstexpr ll TEN(int n) { return\
    \ (n == 0) ? 1 : 10 * TEN(n - 1); }\n\ntemplate <class T, class U>\nvoid chmin(T&\
    \ t, const U& u) {\n    if (t > u) t = u;\n}\ntemplate <class T, class U>\nvoid\
    \ chmax(T& t, const U& u) {\n    if (t < u) t = u;\n}\n\ntemplate <typename T>\n\
    int arglb(const V<T>& v, const T& x) {\n    return distance(v.begin(), lower_bound(ALL(v),\
    \ x));\n}\n\ntemplate <typename T>\nint argub(const V<T>& v, const T& x) {\n \
    \   return distance(v.begin(), upper_bound(ALL(v), x));\n}\n\ntemplate <class\
    \ T>\nvoid mkuni(vector<T>& v) {\n    sort(ALL(v));\n    v.erase(unique(ALL(v)),\
    \ end(v));\n}\n\ntemplate <class T>\nvector<int> sort_by(const vector<T>& v, bool\
    \ increasing = true) {\n    vector<int> res(v.size());\n    iota(res.begin(),\
    \ res.end(), 0);\n\n    if (increasing) {\n        stable_sort(res.begin(), res.end(),\n\
    \                    [&](int i, int j) { return v[i] < v[j]; });\n    } else {\n\
    \        stable_sort(res.begin(), res.end(),\n                    [&](int i, int\
    \ j) { return v[i] > v[j]; });\n    }\n    return res;\n}\n\n// prototype\ntemplate\
    \ <class T, class U>\nostream& operator<<(ostream& os, const pair<T, U>& p);\n\
    \ntemplate <class T>\nostream& operator<<(ostream& os, const vector<T>& v);\n\n\
    template <class T>\nistream& operator>>(istream& is, vector<T>& v);\n\ntemplate\
    \ <class T, size_t sz>\nostream& operator<<(ostream& os, const array<T, sz>& arr);\n\
    \ntemplate <class T>\nostream& operator<<(ostream& os, const set<T>& ST);\n\n\
    template <class T>\nostream& operator<<(ostream& os, const unordered_set<T>& ST);\n\
    \ntemplate <class T>\nostream& operator<<(ostream& os, const multiset<T>& ST);\n\
    \ntemplate <class T, class U>\nostream& operator<<(ostream& os, const map<T, U>&\
    \ MP);\n\ntemplate <class T, class U>\nostream& operator<<(ostream& os, const\
    \ unordered_map<T, U>& MP);\n\nostream& operator<<(ostream& o, __int128_t x);\n\
    \n// io functions\ntemplate <class T, class U>\nistream& operator>>(istream& is,\
    \ pair<T, U>& p) {\n    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate\
    \ <class T, class U>\nostream& operator<<(ostream& os, const pair<T, U>& p) {\n\
    \    os << \"(\" << p.first << \",\" << p.second << \")\";\n    return os;\n}\n\
    \ntemplate <class T>\nistream& operator>>(istream& is, vector<T>& v) {\n    for\
    \ (auto& x : v) {\n        is >> x;\n    }\n    return is;\n}\n\ntemplate <class\
    \ T>\nostream& operator<<(ostream& os, const vector<T>& v) {\n    os << \"{\"\
    ;\n    rep(i, v.size()) {\n        if (i) os << \",\";\n        os << v[i];\n\
    \    }\n    os << \"}\";\n    return os;\n}\n\ntemplate <class T, size_t sz>\n\
    ostream& operator<<(ostream& os, const array<T, sz>& arr) {\n    os << '[';\n\
    \    for (auto v : arr) os << v << ',';\n    os << ']';\n    return os;\n}\n\n\
    template <class T>\nostream& operator<<(ostream& os, const set<T>& ST) {\n   \
    \ os << \"{\";\n    for (auto it = ST.begin(); it != ST.end(); ++it) {\n     \
    \   if (it != ST.begin()) os << \",\";\n        os << *it;\n    }\n    os << \"\
    }\";\n    return os;\n}\n\ntemplate <class T>\nostream& operator<<(ostream& os,\
    \ const unordered_set<T>& ST) {\n    os << \"{\";\n    for (auto it = ST.begin();\
    \ it != ST.end(); ++it) {\n        if (it != ST.begin()) os << \",\";\n      \
    \  os << *it;\n    }\n    os << \"}\";\n    return os;\n}\n\ntemplate <class T>\n\
    ostream& operator<<(ostream& os, const multiset<T>& ST) {\n    os << \"{\";\n\
    \    for (auto it = ST.begin(); it != ST.end(); ++it) {\n        if (it != ST.begin())\
    \ os << \",\";\n        os << *it;\n    }\n    os << \"}\";\n    return os;\n\
    }\n\ntemplate <class T, class U>\nostream& operator<<(ostream& os, const map<T,\
    \ U>& MP) {\n    for (auto it = MP.begin(); it != MP.end(); ++it) {\n        os\
    \ << \"(\" << it->first << \": \" << it->second << \")\";\n    }\n    return os;\n\
    }\n\ntemplate <class T, class U>\nostream& operator<<(ostream& os, const unordered_map<T,\
    \ U>& MP) {\n    for (auto it = MP.begin(); it != MP.end(); ++it) {\n        os\
    \ << \"(\" << it->first << \": \" << it->second << \")\";\n    }\n    return os;\n\
    }\n\nstring to_string(__int128_t x) {\n    if (x == 0) return \"0\";\n    string\
    \ result;\n    if (x < 0) {\n        result += \"-\";\n        x *= -1;\n    }\n\
    \    string t;\n    while (x) {\n        t.push_back('0' + x % 10);\n        x\
    \ /= 10;\n    }\n    reverse(t.begin(), t.end());\n    return result + t;\n}\n\
    \nostream& operator<<(ostream& o, __int128_t x) { return o << to_string(x); }\n\
    \n#ifdef LOCAL\nvoid debug_out() { cerr << endl; }\ntemplate <typename Head, typename...\
    \ Tail>\nvoid debug_out(Head H, Tail... T) {\n    cerr << \" \" << H;\n    debug_out(T...);\n\
    }\n#define debug(...) \\\n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"\
    ]:\", debug_out(__VA_ARGS__)\n#define dump(x) cerr << __LINE__ << \" \" << #x\
    \ << \" = \" << (x) << endl\n#else\n#define debug(...) (void(0))\n#define dump(x)\
    \ (void(0))\n#endif\n\ntemplate <class T>\nV<T>& operator+=(V<T>& vec, const T&\
    \ v) {\n    for (auto& x : vec) x += v;\n    return vec;\n}\n\ntemplate <class\
    \ T>\nV<T>& operator-=(V<T>& vec, const T& v) {\n    for (auto& x : vec) x -=\
    \ v;\n    return vec;\n}\n\n// suc : 1 = newline, 2 = space\ntemplate <class T>\n\
    void print(T x, int suc = 1) {\n    cout << x;\n    if (suc == 1)\n        cout\
    \ << \"\\n\";\n    else if (suc == 2)\n        cout << \" \";\n}\n\ntemplate <class\
    \ T>\nvoid print(const vector<T>& v, int suc = 1) {\n    for (int i = 0; i < v.size();\
    \ ++i)\n        print(v[i], i == int(v.size()) - 1 ? suc : 2);\n}\n\ntemplate\
    \ <class T>\nvoid show(T x) {\n    print(x, 1);\n}\n\ntemplate <typename Head,\
    \ typename... Tail>\nvoid show(Head H, Tail... T) {\n    print(H, 2);\n    show(T...);\n\
    }\n\nint topbit(int t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }\nint topbit(ll\
    \ t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }\nint botbit(int a) { return\
    \ a == 0 ? 32 : __builtin_ctz(a); }\nint botbit(ll a) { return a == 0 ? 64 : __builtin_ctzll(a);\
    \ }\nint popcount(int t) { return __builtin_popcount(t); }\nint popcount(ll t)\
    \ { return __builtin_popcountll(t); }\nint bit_parity(int t) { return __builtin_parity(t);\
    \ }\nint bit_parity(ll t) { return __builtin_parityll(t); }\n\nstruct prepare_io\
    \ {\n    prepare_io() {\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(10);\n    }\n} prep_io;\n#pragma endregion\
    \ satashun\n\ntemplate <unsigned int MOD>\nstruct ModInt {\n    using uint = unsigned\
    \ int;\n    using ull = unsigned long long;\n    using M = ModInt;\n\n    uint\
    \ v;\n\n    ModInt(ll _v = 0) { set_norm(_v % MOD + MOD); }\n    M& set_norm(uint\
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
    \ ModInt<998244353>;\n\nV<Mint> fact, ifact, inv;\nVV<Mint> small_comb;\n\nvoid\
    \ mod_init() {\n    const int maxv = 1000010;\n    const int maxvv = 5000;\n\n\
    \    fact.resize(maxv);\n    ifact.resize(maxv);\n    inv.resize(maxv);\n\n  \
    \  small_comb = make_vec<Mint>(maxvv, maxvv);\n\n    fact[0] = 1;\n    for (int\
    \ i = 1; i < maxv; ++i) {\n        fact[i] = fact[i - 1] * i;\n    }\n\n    ifact[maxv\
    \ - 1] = fact[maxv - 1].inv();\n\n    for (int i = maxv - 2; i >= 0; --i) {\n\
    \        ifact[i] = ifact[i + 1] * (i + 1);\n    }\n\n    for (int i = 1; i <\
    \ maxv; ++i) {\n        inv[i] = ifact[i] * fact[i - 1];\n    }\n\n    for (int\
    \ i = 0; i < maxvv; ++i) {\n        small_comb[i][0] = small_comb[i][i] = 1;\n\
    \        for (int j = 1; j < i; ++j) {\n            small_comb[i][j] = small_comb[i\
    \ - 1][j] + small_comb[i - 1][j - 1];\n        }\n    }\n}\n\nMint comb(int n,\
    \ int r) {\n    if (n < 0 || r < 0 || r > n) return Mint(0);\n    if (n < small_comb.size())\
    \ return small_comb[n][r];\n    return fact[n] * ifact[r] * ifact[n - r];\n}\n\
    \nMint inv_comb(int n, int r) {\n    if (n < 0 || r < 0 || r > n) return Mint(0);\n\
    \    return ifact[n] * fact[r] * fact[n - r];\n}\n\n// O(k)\nMint comb_slow(ll\
    \ n, ll k) {\n    if (n < 0 || k < 0 || k > n) return Mint(0);\n    Mint res =\
    \ ifact[k];\n    for (int i = 0; i < k; ++i) {\n        res = res * (n - i);\n\
    \    }\n    return res;\n}\n\n// line up\n// a 'o' + b 'x'\nMint comb2(int a,\
    \ int b) {\n    if (a < 0 || b < 0) return 0;\n    return comb(a + b, a);\n}\n\
    \n// divide a into b groups\nMint nhr(int a, int b) {\n    if (b == 0) return\
    \ Mint(a == 0);\n    return comb(a + b - 1, a);\n}\n\n// O(p + log_p n)\n\nMint\
    \ lucas(ll n, ll k, int p) {\n    if (n < 0 || k < 0 || k > n) return Mint(0);\n\
    \    Mint res = 1;\n    while (n > 0) {\n        res *= comb(n % p, k % p);\n\
    \        n /= p;\n        k /= p;\n    }\n    return res;\n}\n\nstruct ModPrepare\
    \ {\n    ModPrepare() { mod_init(); }\n} prep_mod;\n\n/**\n * @docs docs/ntt.md\n\
    \ */\n\n// \u89E3\u8AAC: https://atcoder.jp/contests/ABC265/editorial/4577\n\n\
    template <class D>\nstruct NumberTheoreticTransform {\n    D root;\n    V<D> roots\
    \ = {0, 1};\n    V<int> rev = {0, 1};\n    int base = 1, max_base = -1;\n\n  \
    \  void init() {\n        int mod = D::get_mod();\n        int tmp = mod - 1;\n\
    \        max_base = 0;\n        while (tmp % 2 == 0) {\n            tmp /= 2;\n\
    \            max_base++;\n        }\n\n        root = 2;\n\n        while (true)\
    \ {\n            if (root.pow(1 << max_base).v == 1) {\n                if (root.pow(1\
    \ << (max_base - 1)).v != 1) {\n                    break;\n                }\n\
    \            }\n            root++;\n        }\n    }\n\n    void ensure_base(int\
    \ nbase) {\n        if (max_base == -1) init();\n        if (nbase <= base) return;\n\
    \        assert(nbase <= max_base);\n\n        rev.resize(1 << nbase);\n     \
    \   for (int i = 0; i < (1 << nbase); ++i) {\n            rev[i] = (rev[i >> 1]\
    \ >> 1) + ((i & 1) << (nbase - 1));\n        }\n        roots.resize(1 << nbase);\n\
    \n        while (base < nbase) {\n            D z = root.pow(1 << (max_base -\
    \ 1 - base));\n            for (int i = 1 << (base - 1); i < (1 << base); ++i)\
    \ {\n                roots[i << 1] = roots[i];\n                roots[(i << 1)\
    \ + 1] = roots[i] * z;\n            }\n            ++base;\n        }\n    }\n\
    \n    // FPS24 - R\n    void ntt(V<D>& a, bool inv = false) {\n        int n =\
    \ a.size();\n        // assert((n & (n - 1)) == 0);\n        int zeros = __builtin_ctz(n);\n\
    \        ensure_base(zeros);\n        int shift = base - zeros;\n\n        for\
    \ (int i = 0; i < n; i++) {\n            if (i < (rev[i] >> shift)) {\n      \
    \          swap(a[i], a[rev[i] >> shift]);\n            }\n        }\n\n     \
    \   for (int k = 1; k < n; k <<= 1) {\n            for (int i = 0; i < n; i +=\
    \ 2 * k) {\n                for (int j = 0; j < k; j++) {\n                  \
    \  D x = a[i + j];\n                    D y = a[i + j + k] * roots[j + k];\n \
    \                   a[i + j] = x + y;\n                    a[i + j + k] = x -\
    \ y;\n                }\n            }\n        }\n\n        if (inv) {\n    \
    \        int v = D(n).inv().v;\n            reverse(a.begin() + 1, a.end());\n\
    \            for (int i = 0; i < n; i++) {\n                a[i] *= v;\n     \
    \       }\n        }\n    }\n\n    V<D> mul(V<D> a, V<D> b) {\n        if (a.size()\
    \ == 0 && b.size() == 0) return {};\n        int s = a.size() + b.size() - 1;\n\
    \        int nbase = 1;\n        while ((1 << nbase) < s) nbase++;\n        int\
    \ sz = 1 << nbase;\n\n        if (sz <= 16) {\n            V<D> ret(s);\n    \
    \        for (int i = 0; i < a.size(); i++) {\n                for (int j = 0;\
    \ j < b.size(); j++) ret[i + j] += a[i] * b[j];\n            }\n            return\
    \ ret;\n        }\n\n        a.resize(sz);\n        b.resize(sz);\n        ntt(a);\n\
    \        ntt(b);\n\n        for (int i = 0; i < sz; i++) {\n            a[i] *=\
    \ b[i];\n        }\n        ntt(a, true);\n\n        a.resize(s);\n        return\
    \ a;\n    }\n};\n\n// T : modint\ntemplate <class T>\nvoid ntt_2d(VV<T>& a, bool\
    \ rev) {\n    if (a.size() == 0 || a[0].size() == 0) return;\n    int h = a.size(),\
    \ w = a[0].size();\n\n    NumberTheoreticTransform<T> fft;\n    fft.init();\n\n\
    \    for (auto& v : a) {\n        fft.ntt(v, rev);\n    }\n\n    rep(j, w) {\n\
    \        V<T> vh(h);\n        rep(i, h) { vh[i] = a[i][j]; }\n        fft.ntt(vh,\
    \ rev);\n        rep(i, h) { a[i][j] = vh[i]; }\n    }\n}\n\nNumberTheoreticTransform<Mint>\
    \ ntt;\n\nstruct prepare_NTT {\n    prepare_NTT() { ntt.init(); }\n} prep_NTT;\n\
    \ntemplate <class D>\nstruct Poly : public V<D> {\n    template <class... Args>\n\
    \    Poly(Args... args) : V<D>(args...) {}\n    Poly(initializer_list<D> init)\
    \ : V<D>(init.begin(), init.end()) {}\n\n    int size() const { return V<D>::size();\
    \ }\n    D at(int p) const { return (p < this->size() ? (*this)[p] : D(0)); }\n\
    \n    // first len terms\n    Poly pref(int len) const {\n        return Poly(this->begin(),\
    \ this->begin() + min(this->size(), len));\n    }\n\n    // for polynomial division\n\
    \    Poly rev() const {\n        Poly res = *this;\n        reverse(res.begin(),\
    \ res.end());\n        return res;\n    }\n\n    Poly operator+(const Poly& r)\
    \ const {\n        auto n = max(size(), r.size());\n        V<D> tmp(n);\n   \
    \     for (int i = 0; i < n; ++i) {\n            tmp[i] = at(i) + r.at(i);\n \
    \       }\n        return tmp;\n    }\n    Poly operator-(const Poly& r) const\
    \ {\n        auto n = max(size(), r.size());\n        V<D> tmp(n);\n        for\
    \ (int i = 0; i < n; ++i) {\n            tmp[i] = at(i) - r.at(i);\n        }\n\
    \        return tmp;\n    }\n\n    // scalar\n    Poly operator*(const D& k) const\
    \ {\n        int n = size();\n        V<D> tmp(n);\n        for (int i = 0; i\
    \ < n; ++i) {\n            tmp[i] = at(i) * k;\n        }\n        return tmp;\n\
    \    }\n\n    Poly operator*(const Poly& r) const {\n        Poly a = *this;\n\
    \        Poly b = r;\n        auto v = ntt.mul(a, b);\n        return v;\n   \
    \ }\n\n    // scalar\n    Poly operator/(const D& k) const { return *this * k.inv();\
    \ }\n\n    Poly operator/(const Poly& r) const {\n        if (size() < r.size())\
    \ {\n            return {{}};\n        }\n        int d = size() - r.size() +\
    \ 1;\n        return (rev().pref(d) * r.rev().inv(d)).pref(d).rev();\n    }\n\n\
    \    Poly operator%(const Poly& r) const {\n        auto res = *this - *this /\
    \ r * r;\n        while (res.size() && !res.back()) {\n            res.pop_back();\n\
    \        }\n        return res;\n    }\n\n    Poly diff() const {\n        V<D>\
    \ res(max(0, size() - 1));\n        for (int i = 1; i < size(); ++i) {\n     \
    \       res[i - 1] = at(i) * i;\n        }\n        return res;\n    }\n\n   \
    \ Poly inte() const {\n        V<D> res(size() + 1);\n        for (int i = 0;\
    \ i < size(); ++i) {\n            res[i + 1] = at(i) / (D)(i + 1);\n        }\n\
    \        return res;\n    }\n\n    // f * f.inv(m) === 1 mod (x^m)\n    // f_0\
    \ ^ -1 must exist\n    Poly inv(int m) const {\n        Poly res = Poly({D(1)\
    \ / at(0)});\n        for (int i = 1; i < m; i *= 2) {\n            res = (res\
    \ * D(2) - res * res * pref(i * 2)).pref(i * 2);\n        }\n        return res.pref(m);\n\
    \    }\n\n    // f_0 = 1 must hold\n    Poly log(int n) const {\n        auto\
    \ f = pref(n);\n        return (f.diff() * f.inv(n - 1)).pref(n - 1).inte();\n\
    \    }\n\n    // f_0 = 0 must hold\n    Poly exp(int n) const {\n        auto\
    \ h = diff();\n        Poly f({1}), g({1});\n\n        for (int m = 1; m < n;\
    \ m *= 2) {\n            g = (g * D(2) - f * g * g).pref(m);\n            auto\
    \ q = h.pref(m - 1);\n            auto w = (q + g * (f.diff() - f * q)).pref(m\
    \ * 2 - 1);\n            f = (f + f * (*this - w.inte()).pref(m * 2)).pref(m *\
    \ 2);\n        }\n\n        return f.pref(n);\n    }\n\n    // be careful when\
    \ k = 0\n    Poly pow(int n, ll k) const { return (log(n) * (D)k).exp(n); }\n\n\
    \    // f_0 = 1 must hold (use it with modular sqrt)\n    // CF250E\n    Poly\
    \ sqrt(int n) const {\n        Poly f = pref(n);\n        Poly g({1});\n     \
    \   for (int i = 1; i < n; i *= 2) {\n            g = (g + f.pref(i * 2) * g.inv(i\
    \ * 2)) * D(2).inv();\n        }\n        return g.pref(n);\n    }\n\n    D eval(D\
    \ x) const {\n        D res = 0, c = 1;\n        for (auto a : *this) {\n    \
    \        res += a * c;\n            c *= x;\n        }\n        return res;\n\
    \    }\n\n    Poly& operator+=(const Poly& r) { return *this = *this + r; }\n\
    \    Poly& operator-=(const Poly& r) { return *this = *this - r; }\n    Poly&\
    \ operator*=(const D& r) { return *this = *this * r; }\n    Poly& operator*=(const\
    \ Poly& r) { return *this = *this * r; }\n    Poly& operator/=(const Poly& r)\
    \ { return *this = *this / r; }\n    Poly& operator/=(const D& r) { return *this\
    \ = *this / r; }\n    Poly& operator%=(const Poly& r) { return *this = *this %\
    \ r; }\n\n    friend ostream& operator<<(ostream& os, const Poly& pl) {\n    \
    \    if (pl.size() == 0) return os << \"0\";\n        for (int i = 0; i < pl.size();\
    \ ++i) {\n            if (pl[i]) {\n                os << pl[i] << \"x^\" << i;\n\
    \                if (i + 1 != pl.size()) os << \",\";\n            }\n       \
    \ }\n        return os;\n    }\n};\n\n// first d terms of f^k, where f is sparse.\n\
    // O(d * |i | f_i != 0|)\n// FPS24 - A\ntemplate <class T>\nV<T> pow_sparse(const\
    \ Poly<T>& f, ll k, int d) {\n    Poly<T> g(d);\n\n    if (k == 0) {\n       \
    \ if (d > 0) g[0] = 1;\n        return g;\n    }\n\n    V<pair<int, T>> fv;\n\
    \    rep(i, f.size()) {\n        if (f[i] != 0) fv.emplace_back(i, f[i]);\n  \
    \  }\n\n    if (SZ(fv) == 0) {\n        return g;\n    }\n\n    auto [head_pos,\
    \ head_val] = fv[0];\n    fv.erase(fv.begin());\n\n    for (auto& [j, val] : fv)\
    \ {\n        j -= head_pos;\n    }\n\n    Poly<T> gg(d);\n\n    gg[0] = head_val.pow(k);\n\
    \    Mint rev = head_val.inv();\n\n    for (int i = 0; i < d - 1; i++) {\n   \
    \     for (auto [j, val] : fv) {\n            if (i + 1 - j < 0) break;\n    \
    \        gg[i + 1] += gg[i + 1 - j] * val * (T(k) * j - (i - j + 1));\n      \
    \  }\n        gg[i + 1] *= inv[i + 1] * rev;\n    }\n\n    rep(i, d) {\n     \
    \   // k * head_pos < d-i\n        if (head_pos > 0 && k >= (d - i + head_pos\
    \ - 1) / head_pos) break;\n        ll p = k * head_pos + i;\n        g[p] = gg[i];\n\
    \    }\n    return g;\n}\n\nint main() {\n    int N, K;\n    ll M;\n    cin >>\
    \ N >> K >> M;\n    Poly<Mint> pl(N);\n    rep(i, K) {\n        int j, a;\n  \
    \      cin >> j >> a;\n        pl[j] = a;\n    }\n    pl = pow_sparse(pl, M, N);\n\
    \    rep(i, N) { cout << pl[i] << (i != N - 1 ? ' ' : '\\n'); }\n    return 0;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: test/yosupo/pow_of_formal_power_series_sparse.cpp
  requiredBy: []
  timestamp: '2026-03-12 07:30:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/yosupo/pow_of_formal_power_series_sparse.cpp
layout: document
redirect_from:
- /library/test/yosupo/pow_of_formal_power_series_sparse.cpp
- /library/test/yosupo/pow_of_formal_power_series_sparse.cpp.html
title: test/yosupo/pow_of_formal_power_series_sparse.cpp
---
## 前提
- $p - 1$ が十分大きい $2$ べきで割り切れる場合に $\mod p$ で積を計算する
- modint ライブラリと併用する

## 例題

2D NTT

- https://yukicoder.me/problems/no/1241

- https://atcoder.jp/contests/jag2013spring/tasks/icpc2013spring_f (まだ)