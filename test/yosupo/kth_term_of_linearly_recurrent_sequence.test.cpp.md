---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp_src/math/BostanMori.hpp
    title: cpp_src/math/BostanMori.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
    _deprecated_at_docs: docs/ntt.md
    links:
    - https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
  bundledCode: "#line 1 \"test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp\"\
    \n#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
    \n//#pragma GCC optimize(\"Ofast\")\n//#pragma GCC optimize(\"unroll-loops\")\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = int64_t;\nusing ull\
    \ = uint64_t;\nusing pii = pair<int, int>;\ntemplate <class T>\nusing V = vector<T>;\n\
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
    \ (void(0))\n#endif\n\ntemplate <unsigned int MOD>\nstruct ModInt {\n    using\
    \ uint = unsigned int;\n    using ull = unsigned long long;\n    using M = ModInt;\n\
    \n    uint v;\n\n    ModInt(ll _v = 0) { set_norm(_v % MOD + MOD); }\n    M& set_norm(uint\
    \ _v) {  //[0, MOD * 2)->[0, MOD)\n        v = (_v < MOD) ? _v : _v - MOD;\n \
    \       return *this;\n    }\n\n    explicit operator bool() const { return v\
    \ != 0; }\n    explicit operator int() const { return v; }\n    M operator+(const\
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
    \     }\n        return M(p);\n    }\n\n    friend ostream& operator<<(ostream&\
    \ os, const M& a) { return os << a.v; }\n    friend istream& operator>>(istream&\
    \ in, M& x) {\n        ll v_;\n        in >> v_;\n        x = M(v_);\n       \
    \ return in;\n    }\n\n    bool operator<(const M& r) const { return v < r.v;\
    \ }\n    bool operator>(const M& r) const { return v < *this; }\n    bool operator<=(const\
    \ M& r) const { return !(r < *this); }\n    bool operator>=(const M& r) const\
    \ { return !(*this < r); }\n    bool operator==(const M& a) const { return v ==\
    \ a.v; }\n    bool operator!=(const M& a) const { return v != a.v; }\n\n    static\
    \ uint get_mod() { return MOD; }\n};\n\nusing Mint = ModInt<998244353>;\n\n/**\n\
    \ * @docs docs/ntt.md\n */\n\ntemplate <class D>\nstruct NumberTheoreticTransform\
    \ {\n    D root;\n    V<D> roots = {0, 1};\n    V<int> rev = {0, 1};\n    int\
    \ base = 1, max_base = -1;\n\n    void init() {\n        int mod = D::get_mod();\n\
    \        int tmp = mod - 1;\n        max_base = 0;\n        while (tmp % 2 ==\
    \ 0) {\n            tmp /= 2;\n            max_base++;\n        }\n\n        root\
    \ = 2;\n\n        while (true) {\n            if (root.pow(1 << max_base).v ==\
    \ 1) {\n                if (root.pow(1 << (max_base - 1)).v != 1) {\n        \
    \            break;\n                }\n            }\n            root++;\n \
    \       }\n    }\n\n    void ensure_base(int nbase) {\n        if (max_base ==\
    \ -1) init();\n        if (nbase <= base) return;\n        assert(nbase <= max_base);\n\
    \n        rev.resize(1 << nbase);\n        for (int i = 0; i < (1 << nbase); ++i)\
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
    \ ntt;\n\ntemplate <class D>\nstruct Poly : public V<D> {\n    template <class...\
    \ Args>\n    Poly(Args... args) : V<D>(args...) {}\n    Poly(initializer_list<D>\
    \ init) : V<D>(init.begin(), init.end()) {}\n\n    int size() const { return V<D>::size();\
    \ }\n    D at(int p) const { return (p < this->size() ? (*this)[p] : D(0)); }\n\
    \n    // first len terms\n    Poly pref(int len) const {\n        return Poly(this->begin(),\
    \ this->begin() + min(this->size(), len));\n    }\n\n    // for polynomial division\n\
    \    Poly rev() const {\n        Poly res = *this;\n        reverse(res.begin(),\
    \ res.end());\n        return res;\n    }\n\n    Poly shiftr(int d) const {\n\
    \        int n = max(size() + d, 0);\n        Poly res(n);\n        for (int i\
    \ = 0; i < size(); ++i) {\n            if (i + d >= 0) {\n                res[i\
    \ + d] = at(i);\n            }\n        }\n        return res;\n    }\n\n    Poly\
    \ operator+(const Poly& r) const {\n        auto n = max(size(), r.size());\n\
    \        V<D> tmp(n);\n        for (int i = 0; i < n; ++i) {\n            tmp[i]\
    \ = at(i) + r.at(i);\n        }\n        return tmp;\n    }\n    Poly operator-(const\
    \ Poly& r) const {\n        auto n = max(size(), r.size());\n        V<D> tmp(n);\n\
    \        for (int i = 0; i < n; ++i) {\n            tmp[i] = at(i) - r.at(i);\n\
    \        }\n        return tmp;\n    }\n\n    // scalar\n    Poly operator*(const\
    \ D& k) const {\n        int n = size();\n        V<D> tmp(n);\n        for (int\
    \ i = 0; i < n; ++i) {\n            tmp[i] = at(i) * k;\n        }\n        return\
    \ tmp;\n    }\n\n    Poly operator*(const Poly& r) const {\n        Poly a = *this;\n\
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
    \ }\n        return os;\n    }\n\n    explicit operator bool() const {\n     \
    \   bool f = false;\n        for (int i = 0; i < size(); ++i) {\n            if\
    \ (at(i)) {\n                f = true;\n            }\n        }\n        return\
    \ f;\n    }\n};\n\n// calculate characteristic polynomial\n// c_0 * s_i + c_1\
    \ * s_{i+1} + ... + c_k * s_{i+k} = 0\n// c_k = -1\n\ntemplate <class T>\nPoly<T>\
    \ berlekamp_massey(const V<T>& s) {\n    int n = int(s.size());\n    V<T> b =\
    \ {T(-1)}, c = {T(-1)};\n    T y = Mint(1);\n    for (int ed = 1; ed <= n; ed++)\
    \ {\n        int l = int(c.size()), m = int(b.size());\n        T x = 0;\n   \
    \     for (int i = 0; i < l; i++) {\n            x += c[i] * s[ed - l + i];\n\
    \        }\n        b.push_back(0);\n        m++;\n        if (!x) {\n       \
    \     continue;\n        }\n        T freq = x / y;\n        if (l < m) {\n  \
    \          auto tmp = c;\n            c.insert(begin(c), m - l, Mint(0));\n  \
    \          for (int i = 0; i < m; i++) {\n                c[m - 1 - i] -= freq\
    \ * b[m - 1 - i];\n            }\n            b = tmp;\n            y = x;\n \
    \       } else {\n            for (int i = 0; i < m; i++) {\n                c[l\
    \ - 1 - i] -= freq * b[m - 1 - i];\n            }\n        }\n    }\n    return\
    \ c;\n}\n\n// HUPC 2020 day3 K\n// calculate vec[0] * vec[1] * ...\n// deg(result)\
    \ must be bounded\n\ntemplate <class T>\nPoly<T> prod(const V<Poly<T>>& vec) {\n\
    \    auto comp = [](const auto& a, const auto& b) -> bool {\n        return a.size()\
    \ > b.size();\n    };\n    priority_queue<Poly<T>, V<Poly<T>>, decltype(comp)>\
    \ que(comp);\n    que.push(Poly<T>{1});\n\n    for (auto& pl : vec) que.push(pl);\n\
    \n    while (que.size() > 1) {\n        auto va = que.top();\n        que.pop();\n\
    \        auto vb = que.top();\n        que.pop();\n        que.push(va * vb);\n\
    \    }\n\n    return que.top();\n}\n\n#define call_from_test\n#line 1 \"cpp_src/math/BostanMori.hpp\"\
    \n// ref :\n// https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a#%E5%BD%A2%E5%BC%8F%E7%9A%84%E3%81%B9%E3%81%8D%E7%B4%9A%E6%95%B0\n\
    // a_i = \\sum_{j=1}^d c_j * a_{i-j}\n// input\n// a_0, a_1, a_2, ..., a_{d-1}\n\
    // c_1, c_2, c_3, ..., c_d\n// n\n// calculate a_n\n\ntemplate <class T>\nT bostan_mori(Poly<T>\
    \ a, Poly<T> c, ll n) {\n    if (n < a.size()) return a[n];\n    using P = Poly<T>;\n\
    \n    auto even = [&](const P& a) {\n        int sz = SZ(a);\n        P b((sz\
    \ + 1) / 2);\n        for (int i = 0; i < SZ(a); i += 2) {\n            b[i /\
    \ 2] = a[i];\n        }\n        return b;\n    };\n    auto odd = [&](const P&\
    \ a) {\n        int sz = SZ(a);\n        P b(sz / 2);\n        for (int i = 1;\
    \ i < SZ(a); i += 2) {\n            b[i / 2] = a[i];\n        }\n        return\
    \ b;\n    };\n    // a(x) -> a(-x)\n    auto neg = [&](const P& a) {\n       \
    \ auto b = a;\n        for (int i = 1; i < SZ(b); i += 2) {\n            b[i]\
    \ = -b[i];\n        }\n        return b;\n    };\n\n    int d = SZ(c);\n    P\
    \ q(d + 1);\n    q[0] = 1;\n    rep(i, SZ(c)) q[i + 1] = -c[i];\n    P p = a *\
    \ q;\n    p = p.pref(d);\n\n    while (n > 0) {\n        debug(p, q);\n      \
    \  auto u = p * neg(q);\n        if (n % 2 == 0) {\n            p = even(u);\n\
    \        } else {\n            p = odd(u);\n        }\n        q = even(q * neg(q));\n\
    \        n /= 2;\n    }\n    return p[0] / q[0];\n}\n#line 523 \"test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp\"\
    \n#undef call_from_test\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    ntt.init();\n\n    int d;\n    ll k;\n    cin >> d >> k;\n    Poly<Mint>\
    \ a(d);\n    rep(i, d) cin >> a[i];\n    Poly<Mint> c(d);\n    rep(i, d) cin >>\
    \ c[i];\n    auto v = bostan_mori(a, c, k);\n    cout << v << '\\n';\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
    \n//#pragma GCC optimize(\"Ofast\")\n//#pragma GCC optimize(\"unroll-loops\")\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = int64_t;\nusing ull\
    \ = uint64_t;\nusing pii = pair<int, int>;\ntemplate <class T>\nusing V = vector<T>;\n\
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
    \ (void(0))\n#endif\n\ntemplate <unsigned int MOD>\nstruct ModInt {\n    using\
    \ uint = unsigned int;\n    using ull = unsigned long long;\n    using M = ModInt;\n\
    \n    uint v;\n\n    ModInt(ll _v = 0) { set_norm(_v % MOD + MOD); }\n    M& set_norm(uint\
    \ _v) {  //[0, MOD * 2)->[0, MOD)\n        v = (_v < MOD) ? _v : _v - MOD;\n \
    \       return *this;\n    }\n\n    explicit operator bool() const { return v\
    \ != 0; }\n    explicit operator int() const { return v; }\n    M operator+(const\
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
    \     }\n        return M(p);\n    }\n\n    friend ostream& operator<<(ostream&\
    \ os, const M& a) { return os << a.v; }\n    friend istream& operator>>(istream&\
    \ in, M& x) {\n        ll v_;\n        in >> v_;\n        x = M(v_);\n       \
    \ return in;\n    }\n\n    bool operator<(const M& r) const { return v < r.v;\
    \ }\n    bool operator>(const M& r) const { return v < *this; }\n    bool operator<=(const\
    \ M& r) const { return !(r < *this); }\n    bool operator>=(const M& r) const\
    \ { return !(*this < r); }\n    bool operator==(const M& a) const { return v ==\
    \ a.v; }\n    bool operator!=(const M& a) const { return v != a.v; }\n\n    static\
    \ uint get_mod() { return MOD; }\n};\n\nusing Mint = ModInt<998244353>;\n\n/**\n\
    \ * @docs docs/ntt.md\n */\n\ntemplate <class D>\nstruct NumberTheoreticTransform\
    \ {\n    D root;\n    V<D> roots = {0, 1};\n    V<int> rev = {0, 1};\n    int\
    \ base = 1, max_base = -1;\n\n    void init() {\n        int mod = D::get_mod();\n\
    \        int tmp = mod - 1;\n        max_base = 0;\n        while (tmp % 2 ==\
    \ 0) {\n            tmp /= 2;\n            max_base++;\n        }\n\n        root\
    \ = 2;\n\n        while (true) {\n            if (root.pow(1 << max_base).v ==\
    \ 1) {\n                if (root.pow(1 << (max_base - 1)).v != 1) {\n        \
    \            break;\n                }\n            }\n            root++;\n \
    \       }\n    }\n\n    void ensure_base(int nbase) {\n        if (max_base ==\
    \ -1) init();\n        if (nbase <= base) return;\n        assert(nbase <= max_base);\n\
    \n        rev.resize(1 << nbase);\n        for (int i = 0; i < (1 << nbase); ++i)\
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
    \ ntt;\n\ntemplate <class D>\nstruct Poly : public V<D> {\n    template <class...\
    \ Args>\n    Poly(Args... args) : V<D>(args...) {}\n    Poly(initializer_list<D>\
    \ init) : V<D>(init.begin(), init.end()) {}\n\n    int size() const { return V<D>::size();\
    \ }\n    D at(int p) const { return (p < this->size() ? (*this)[p] : D(0)); }\n\
    \n    // first len terms\n    Poly pref(int len) const {\n        return Poly(this->begin(),\
    \ this->begin() + min(this->size(), len));\n    }\n\n    // for polynomial division\n\
    \    Poly rev() const {\n        Poly res = *this;\n        reverse(res.begin(),\
    \ res.end());\n        return res;\n    }\n\n    Poly shiftr(int d) const {\n\
    \        int n = max(size() + d, 0);\n        Poly res(n);\n        for (int i\
    \ = 0; i < size(); ++i) {\n            if (i + d >= 0) {\n                res[i\
    \ + d] = at(i);\n            }\n        }\n        return res;\n    }\n\n    Poly\
    \ operator+(const Poly& r) const {\n        auto n = max(size(), r.size());\n\
    \        V<D> tmp(n);\n        for (int i = 0; i < n; ++i) {\n            tmp[i]\
    \ = at(i) + r.at(i);\n        }\n        return tmp;\n    }\n    Poly operator-(const\
    \ Poly& r) const {\n        auto n = max(size(), r.size());\n        V<D> tmp(n);\n\
    \        for (int i = 0; i < n; ++i) {\n            tmp[i] = at(i) - r.at(i);\n\
    \        }\n        return tmp;\n    }\n\n    // scalar\n    Poly operator*(const\
    \ D& k) const {\n        int n = size();\n        V<D> tmp(n);\n        for (int\
    \ i = 0; i < n; ++i) {\n            tmp[i] = at(i) * k;\n        }\n        return\
    \ tmp;\n    }\n\n    Poly operator*(const Poly& r) const {\n        Poly a = *this;\n\
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
    \ }\n        return os;\n    }\n\n    explicit operator bool() const {\n     \
    \   bool f = false;\n        for (int i = 0; i < size(); ++i) {\n            if\
    \ (at(i)) {\n                f = true;\n            }\n        }\n        return\
    \ f;\n    }\n};\n\n// calculate characteristic polynomial\n// c_0 * s_i + c_1\
    \ * s_{i+1} + ... + c_k * s_{i+k} = 0\n// c_k = -1\n\ntemplate <class T>\nPoly<T>\
    \ berlekamp_massey(const V<T>& s) {\n    int n = int(s.size());\n    V<T> b =\
    \ {T(-1)}, c = {T(-1)};\n    T y = Mint(1);\n    for (int ed = 1; ed <= n; ed++)\
    \ {\n        int l = int(c.size()), m = int(b.size());\n        T x = 0;\n   \
    \     for (int i = 0; i < l; i++) {\n            x += c[i] * s[ed - l + i];\n\
    \        }\n        b.push_back(0);\n        m++;\n        if (!x) {\n       \
    \     continue;\n        }\n        T freq = x / y;\n        if (l < m) {\n  \
    \          auto tmp = c;\n            c.insert(begin(c), m - l, Mint(0));\n  \
    \          for (int i = 0; i < m; i++) {\n                c[m - 1 - i] -= freq\
    \ * b[m - 1 - i];\n            }\n            b = tmp;\n            y = x;\n \
    \       } else {\n            for (int i = 0; i < m; i++) {\n                c[l\
    \ - 1 - i] -= freq * b[m - 1 - i];\n            }\n        }\n    }\n    return\
    \ c;\n}\n\n// HUPC 2020 day3 K\n// calculate vec[0] * vec[1] * ...\n// deg(result)\
    \ must be bounded\n\ntemplate <class T>\nPoly<T> prod(const V<Poly<T>>& vec) {\n\
    \    auto comp = [](const auto& a, const auto& b) -> bool {\n        return a.size()\
    \ > b.size();\n    };\n    priority_queue<Poly<T>, V<Poly<T>>, decltype(comp)>\
    \ que(comp);\n    que.push(Poly<T>{1});\n\n    for (auto& pl : vec) que.push(pl);\n\
    \n    while (que.size() > 1) {\n        auto va = que.top();\n        que.pop();\n\
    \        auto vb = que.top();\n        que.pop();\n        que.push(va * vb);\n\
    \    }\n\n    return que.top();\n}\n\n#define call_from_test\n#include \"../../cpp_src/math/BostanMori.hpp\"\
    \n#undef call_from_test\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    ntt.init();\n\n    int d;\n    ll k;\n    cin >> d >> k;\n    Poly<Mint>\
    \ a(d);\n    rep(i, d) cin >> a[i];\n    Poly<Mint> c(d);\n    rep(i, d) cin >>\
    \ c[i];\n    auto v = bostan_mori(a, c, k);\n    cout << v << '\\n';\n    return\
    \ 0;\n}"
  dependsOn:
  - cpp_src/math/BostanMori.hpp
  isVerificationFile: true
  path: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
  requiredBy: []
  timestamp: '2022-03-17 11:21:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
- /verify/test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp.html
title: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
---
## 前提
- $p - 1$ が十分大きい $2$ べきで割り切れる場合に $\mod p$ で積を計算する
- modint ライブラリと併用する

## 例題

2D NTT

- https://yukicoder.me/problems/no/1241

- https://atcoder.jp/contests/jag2013spring/tasks/icpc2013spring_f (まだ)