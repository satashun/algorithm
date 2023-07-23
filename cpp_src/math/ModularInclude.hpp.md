---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/math/ModularInclude.hpp\"\n// modint + modular operations\
    \ + NTT\n\ntemplate <unsigned int MOD>\nstruct ModInt {\n    using uint = unsigned\
    \ int;\n    using ull = unsigned long long;\n    using M = ModInt;\n\n    uint\
    \ v;\n\n    ModInt(ll _v = 0) { set_norm(_v % MOD + MOD); }\n    M& set_norm(uint\
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
    \ uint get_mod() { return MOD; }\n};\n\n// using Mint = ModInt<1000000007>;\n\
    using Mint = ModInt<998244353>;\n\nV<Mint> fact, ifact, inv;\nVV<Mint> small_comb;\n\
    \nvoid mod_init() {\n    const int maxv = 1000010;\n    const int maxvv = 5000;\n\
    \n    fact.resize(maxv);\n    ifact.resize(maxv);\n    inv.resize(maxv);\n\n \
    \   small_comb = make_vec<Mint>(maxvv, maxvv);\n\n    fact[0] = 1;\n    for (int\
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
    \ {\n    ModPrepare() { mod_init(); }\n} prep_mod;\n\ntemplate <class D>\nstruct\
    \ NumberTheoreticTransform {\n    D root;\n    V<D> roots = {0, 1};\n    V<int>\
    \ rev = {0, 1};\n    int base = 1, max_base = -1;\n\n    void init() {\n     \
    \   int mod = D::get_mod();\n        int tmp = mod - 1;\n        max_base = 0;\n\
    \        while (tmp % 2 == 0) {\n            tmp /= 2;\n            max_base++;\n\
    \        }\n\n        root = 2;\n\n        while (true) {\n            if (root.pow(1\
    \ << max_base).v == 1) {\n                if (root.pow(1 << (max_base - 1)).v\
    \ != 1) {\n                    break;\n                }\n            }\n    \
    \        root++;\n        }\n    }\n\n    void ensure_base(int nbase) {\n    \
    \    if (max_base == -1) init();\n        if (nbase <= base) return;\n       \
    \ assert(nbase <= max_base);\n\n        rev.resize(1 << nbase);\n        for (int\
    \ i = 0; i < (1 << nbase); ++i) {\n            rev[i] = (rev[i >> 1] >> 1) + ((i\
    \ & 1) << (nbase - 1));\n        }\n        roots.resize(1 << nbase);\n\n    \
    \    while (base < nbase) {\n            D z = root.pow(1 << (max_base - 1 - base));\n\
    \            for (int i = 1 << (base - 1); i < (1 << base); ++i) {\n         \
    \       roots[i << 1] = roots[i];\n                roots[(i << 1) + 1] = roots[i]\
    \ * z;\n            }\n            ++base;\n        }\n    }\n\n    void ntt(V<D>&\
    \ a, bool inv = false) {\n        int n = a.size();\n        // assert((n & (n\
    \ - 1)) == 0);\n        int zeros = __builtin_ctz(n);\n        ensure_base(zeros);\n\
    \        int shift = base - zeros;\n\n        for (int i = 0; i < n; i++) {\n\
    \            if (i < (rev[i] >> shift)) {\n                swap(a[i], a[rev[i]\
    \ >> shift]);\n            }\n        }\n\n        for (int k = 1; k < n; k <<=\
    \ 1) {\n            for (int i = 0; i < n; i += 2 * k) {\n                for\
    \ (int j = 0; j < k; j++) {\n                    D x = a[i + j];\n           \
    \         D y = a[i + j + k] * roots[j + k];\n                    a[i + j] = x\
    \ + y;\n                    a[i + j + k] = x - y;\n                }\n       \
    \     }\n        }\n\n        int v = D(n).inv().v;\n        if (inv) {\n    \
    \        reverse(a.begin() + 1, a.end());\n            for (int i = 0; i < n;\
    \ i++) {\n                a[i] *= v;\n            }\n        }\n    }\n\n    V<D>\
    \ mul(V<D> a, V<D> b) {\n        if (a.size() == 0 && b.size() == 0) return {};\n\
    \        int s = a.size() + b.size() - 1;\n        int nbase = 1;\n        while\
    \ ((1 << nbase) < s) nbase++;\n        int sz = 1 << nbase;\n\n        if (sz\
    \ <= 16) {\n            V<D> ret(s);\n            for (int i = 0; i < a.size();\
    \ i++) {\n                for (int j = 0; j < b.size(); j++) ret[i + j] += a[i]\
    \ * b[j];\n            }\n            return ret;\n        }\n\n        a.resize(sz);\n\
    \        b.resize(sz);\n        ntt(a);\n        ntt(b);\n\n        for (int i\
    \ = 0; i < sz; i++) {\n            a[i] *= b[i];\n        }\n        ntt(a, true);\n\
    \n        a.resize(s);\n        return a;\n    }\n};\n\n// T : modint\ntemplate\
    \ <class T>\nvoid ntt_2d(VV<T>& a, bool rev) {\n    if (a.size() == 0 || a[0].size()\
    \ == 0) return;\n    int h = a.size(), w = a[0].size();\n\n    NumberTheoreticTransform<T>\
    \ fft;\n    fft.init();\n\n    for (auto& v : a) {\n        fft.ntt(v, rev);\n\
    \    }\n\n    rep(j, w) {\n        V<T> vh(h);\n        rep(i, h) { vh[i] = a[i][j];\
    \ }\n        fft.ntt(vh, rev);\n        rep(i, h) { a[i][j] = vh[i]; }\n    }\n\
    }\n"
  code: "// modint + modular operations + NTT\n\ntemplate <unsigned int MOD>\nstruct\
    \ ModInt {\n    using uint = unsigned int;\n    using ull = unsigned long long;\n\
    \    using M = ModInt;\n\n    uint v;\n\n    ModInt(ll _v = 0) { set_norm(_v %\
    \ MOD + MOD); }\n    M& set_norm(uint _v) {  //[0, MOD * 2)->[0, MOD)\n      \
    \  v = (_v < MOD) ? _v : _v - MOD;\n        return *this;\n    }\n\n    explicit\
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
    \ = ModInt<1000000007>;\nusing Mint = ModInt<998244353>;\n\nV<Mint> fact, ifact,\
    \ inv;\nVV<Mint> small_comb;\n\nvoid mod_init() {\n    const int maxv = 1000010;\n\
    \    const int maxvv = 5000;\n\n    fact.resize(maxv);\n    ifact.resize(maxv);\n\
    \    inv.resize(maxv);\n\n    small_comb = make_vec<Mint>(maxvv, maxvv);\n\n \
    \   fact[0] = 1;\n    for (int i = 1; i < maxv; ++i) {\n        fact[i] = fact[i\
    \ - 1] * i;\n    }\n\n    ifact[maxv - 1] = fact[maxv - 1].inv();\n\n    for (int\
    \ i = maxv - 2; i >= 0; --i) {\n        ifact[i] = ifact[i + 1] * (i + 1);\n \
    \   }\n\n    for (int i = 1; i < maxv; ++i) {\n        inv[i] = ifact[i] * fact[i\
    \ - 1];\n    }\n\n    for (int i = 0; i < maxvv; ++i) {\n        small_comb[i][0]\
    \ = small_comb[i][i] = 1;\n        for (int j = 1; j < i; ++j) {\n           \
    \ small_comb[i][j] = small_comb[i - 1][j] + small_comb[i - 1][j - 1];\n      \
    \  }\n    }\n}\n\nMint comb(int n, int r) {\n    if (n < 0 || r < 0 || r > n)\
    \ return Mint(0);\n    if (n < small_comb.size()) return small_comb[n][r];\n \
    \   return fact[n] * ifact[r] * ifact[n - r];\n}\n\nMint inv_comb(int n, int r)\
    \ {\n    if (n < 0 || r < 0 || r > n) return Mint(0);\n    return ifact[n] * fact[r]\
    \ * fact[n - r];\n}\n\n// O(k)\nMint comb_slow(ll n, ll k) {\n    if (n < 0 ||\
    \ k < 0 || k > n) return Mint(0);\n    Mint res = ifact[k];\n    for (int i =\
    \ 0; i < k; ++i) {\n        res = res * (n - i);\n    }\n    return res;\n}\n\n\
    // line up\n// a 'o' + b 'x'\nMint comb2(int a, int b) {\n    if (a < 0 || b <\
    \ 0) return 0;\n    return comb(a + b, a);\n}\n\n// divide a into b groups\nMint\
    \ nhr(int a, int b) {\n    if (b == 0) return Mint(a == 0);\n    return comb(a\
    \ + b - 1, a);\n}\n\n// O(p + log_p n)\n\nMint lucas(ll n, ll k, int p) {\n  \
    \  if (n < 0 || k < 0 || k > n) return Mint(0);\n    Mint res = 1;\n    while\
    \ (n > 0) {\n        res *= comb(n % p, k % p);\n        n /= p;\n        k /=\
    \ p;\n    }\n    return res;\n}\n\nstruct ModPrepare {\n    ModPrepare() { mod_init();\
    \ }\n} prep_mod;\n\ntemplate <class D>\nstruct NumberTheoreticTransform {\n  \
    \  D root;\n    V<D> roots = {0, 1};\n    V<int> rev = {0, 1};\n    int base =\
    \ 1, max_base = -1;\n\n    void init() {\n        int mod = D::get_mod();\n  \
    \      int tmp = mod - 1;\n        max_base = 0;\n        while (tmp % 2 == 0)\
    \ {\n            tmp /= 2;\n            max_base++;\n        }\n\n        root\
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
    \        int sz = 1 << nbase;\n\n        if (sz <= 16) {\n            V<D> ret(s);\n\
    \            for (int i = 0; i < a.size(); i++) {\n                for (int j\
    \ = 0; j < b.size(); j++) ret[i + j] += a[i] * b[j];\n            }\n        \
    \    return ret;\n        }\n\n        a.resize(sz);\n        b.resize(sz);\n\
    \        ntt(a);\n        ntt(b);\n\n        for (int i = 0; i < sz; i++) {\n\
    \            a[i] *= b[i];\n        }\n        ntt(a, true);\n\n        a.resize(s);\n\
    \        return a;\n    }\n};\n\n// T : modint\ntemplate <class T>\nvoid ntt_2d(VV<T>&\
    \ a, bool rev) {\n    if (a.size() == 0 || a[0].size() == 0) return;\n    int\
    \ h = a.size(), w = a[0].size();\n\n    NumberTheoreticTransform<T> fft;\n   \
    \ fft.init();\n\n    for (auto& v : a) {\n        fft.ntt(v, rev);\n    }\n\n\
    \    rep(j, w) {\n        V<T> vh(h);\n        rep(i, h) { vh[i] = a[i][j]; }\n\
    \        fft.ntt(vh, rev);\n        rep(i, h) { a[i][j] = vh[i]; }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/math/ModularInclude.hpp
  requiredBy: []
  timestamp: '2023-07-23 15:21:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/math/ModularInclude.hpp
layout: document
redirect_from:
- /library/cpp_src/math/ModularInclude.hpp
- /library/cpp_src/math/ModularInclude.hpp.html
title: cpp_src/math/ModularInclude.hpp
---
