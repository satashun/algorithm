---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: 'https:'
    links: []
  bundledCode: "#line 1 \"test/yosupo/multivariate_convolution.test.cpp\"\n#define\
    \ PROBLEM \\\n    https:  // judge.yosupo.jp/problem/multivariate_convolution\n\
    //#pragma GCC optimize(\"Ofast\")\n//#pragma GCC optimize(\"unroll-loops\")\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing pii = pair<int, int>;\ntemplate <class T>\n\
    using V = vector<T>;\ntemplate <class T>\nusing VV = V<V<T>>;\n\ntemplate <class\
    \ T>\nV<T> make_vec(size_t a) {\n    return V<T>(a);\n}\n\ntemplate <class T,\
    \ class... Ts>\nauto make_vec(size_t a, Ts... ts) {\n    return V<decltype(make_vec<T>(ts...))>(a,\
    \ make_vec<T>(ts...));\n}\n\n#define pb push_back\n#define eb emplace_back\n#define\
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
    \ (void(0))\n#endif\n\ntemplate <class T>\nvoid print(T x, int suc = 1) {\n  \
    \  cout << x;\n    if (suc == 1)\n        cout << \"\\n\";\n    else if (suc ==\
    \ 2)\n        cout << \" \";\n}\n\ntemplate <class T>\nvoid print(const vector<T>&\
    \ v, int suc = 1) {\n    for (int i = 0; i < v.size(); ++i)\n        print(v[i],\
    \ i == int(v.size()) - 1 ? suc : 2);\n}\n\ntemplate <unsigned int MOD>\nstruct\
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
    \ = ModInt<1000000007>;\nusing Mint = ModInt<998244353>;\n\ntemplate <class D>\n\
    struct NumberTheoreticTransform {\n    D root;\n    V<D> roots = {0, 1};\n   \
    \ V<int> rev = {0, 1};\n    int base = 1, max_base = -1;\n\n    void init() {\n\
    \        int mod = D::get_mod();\n        int tmp = mod - 1;\n        max_base\
    \ = 0;\n        while (tmp % 2 == 0) {\n            tmp /= 2;\n            max_base++;\n\
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
    \ ((1 << nbase) < s) nbase++;\n        int sz = 1 << nbase;\n        a.resize(sz);\n\
    \        b.resize(sz);\n        ntt(a);\n        ntt(b);\n\n        for (int i\
    \ = 0; i < sz; i++) {\n            a[i] *= b[i];\n        }\n        ntt(a, true);\n\
    \n        a.resize(s);\n        return a;\n    }\n};\n\n// f(x_1, x_2, ..., x_k)\
    \ * g(x_1, x_2, ..., x_k) mod (x_1^n_1, \\cdots, x_k^n_k)\n// base : {n_1, n_2,\
    \ \\cdots, n_k}\n// i = i_1 + i_2 * n_1 + \\cdots + i_k * (n_1 * n_2 \\cdots *\
    \ n_{k-1})\n\ntemplate <class T>\nV<T> multivariate_convolution(V<T> a, V<T> b,\
    \ V<int> base) {\n    NumberTheoreticTransform<T> ntt;\n    ntt.init();\n\n  \
    \  int K = base.size();\n\n    if (K == 0) {\n        return V<T>{a[0] * b[0]};\n\
    \    }\n\n    int n = a.size();\n    int w = 1;\n    while (w < n * 2) w *= 2;\n\
    \n    V<int> chi(n);\n    for (int i = 0; i < n; ++i) {\n        int t = i;\n\
    \        int res = 0;\n        for (int j = 0; j < K - 1; ++j) {\n           \
    \ t /= base[j];\n            res = (res + t) % K;\n        }\n        chi[i] =\
    \ res;\n    }\n\n    VV<T> F(K, V<T>(w)), G(K, V<T>(w));\n\n    for (int i = 0;\
    \ i < n; ++i) {\n        F[chi[i]][i] += a[i];\n        G[chi[i]][i] += b[i];\n\
    \    }\n\n    for (int i = 0; i < K; ++i) {\n        ntt.ntt(F[i]);\n        ntt.ntt(G[i]);\n\
    \    }\n\n    VV<T> A(K, V<T>(w));\n    rep(p, w) {\n        V<Mint> res(K);\n\
    \        rep(i, K) {\n            rep(j, K) { res[(i + j) % K] += F[i][p] * G[j][p];\
    \ }\n        }\n        rep(i, K) A[i][p] += res[i];\n    }\n    rep(i, K) ntt.ntt(A[i],\
    \ true);\n    V<T> res(n);\n    rep(i, n) res[i] = A[chi[i]][i];\n    return res;\n\
    }\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n \
    \   int K;\n    cin >> K;\n    V<int> N(K);\n    rep(i, K) cin >> N[i];\n    int\
    \ n = 1;\n    rep(i, K) n *= N[i];\n    V<int> base;\n    V<Mint> f(n), g(n);\n\
    \    rep(i, n) cin >> f[i];\n    rep(i, n) cin >> g[i];\n\n    auto ans = multivariate_convolution(f,\
    \ g, N);\n    print(ans);\n\n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    https:  // judge.yosupo.jp/problem/multivariate_convolution\n\
    //#pragma GCC optimize(\"Ofast\")\n//#pragma GCC optimize(\"unroll-loops\")\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing pii = pair<int, int>;\ntemplate <class T>\n\
    using V = vector<T>;\ntemplate <class T>\nusing VV = V<V<T>>;\n\ntemplate <class\
    \ T>\nV<T> make_vec(size_t a) {\n    return V<T>(a);\n}\n\ntemplate <class T,\
    \ class... Ts>\nauto make_vec(size_t a, Ts... ts) {\n    return V<decltype(make_vec<T>(ts...))>(a,\
    \ make_vec<T>(ts...));\n}\n\n#define pb push_back\n#define eb emplace_back\n#define\
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
    \ (void(0))\n#endif\n\ntemplate <class T>\nvoid print(T x, int suc = 1) {\n  \
    \  cout << x;\n    if (suc == 1)\n        cout << \"\\n\";\n    else if (suc ==\
    \ 2)\n        cout << \" \";\n}\n\ntemplate <class T>\nvoid print(const vector<T>&\
    \ v, int suc = 1) {\n    for (int i = 0; i < v.size(); ++i)\n        print(v[i],\
    \ i == int(v.size()) - 1 ? suc : 2);\n}\n\ntemplate <unsigned int MOD>\nstruct\
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
    \ = ModInt<1000000007>;\nusing Mint = ModInt<998244353>;\n\ntemplate <class D>\n\
    struct NumberTheoreticTransform {\n    D root;\n    V<D> roots = {0, 1};\n   \
    \ V<int> rev = {0, 1};\n    int base = 1, max_base = -1;\n\n    void init() {\n\
    \        int mod = D::get_mod();\n        int tmp = mod - 1;\n        max_base\
    \ = 0;\n        while (tmp % 2 == 0) {\n            tmp /= 2;\n            max_base++;\n\
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
    \ ((1 << nbase) < s) nbase++;\n        int sz = 1 << nbase;\n        a.resize(sz);\n\
    \        b.resize(sz);\n        ntt(a);\n        ntt(b);\n\n        for (int i\
    \ = 0; i < sz; i++) {\n            a[i] *= b[i];\n        }\n        ntt(a, true);\n\
    \n        a.resize(s);\n        return a;\n    }\n};\n\n// f(x_1, x_2, ..., x_k)\
    \ * g(x_1, x_2, ..., x_k) mod (x_1^n_1, \\cdots, x_k^n_k)\n// base : {n_1, n_2,\
    \ \\cdots, n_k}\n// i = i_1 + i_2 * n_1 + \\cdots + i_k * (n_1 * n_2 \\cdots *\
    \ n_{k-1})\n\ntemplate <class T>\nV<T> multivariate_convolution(V<T> a, V<T> b,\
    \ V<int> base) {\n    NumberTheoreticTransform<T> ntt;\n    ntt.init();\n\n  \
    \  int K = base.size();\n\n    if (K == 0) {\n        return V<T>{a[0] * b[0]};\n\
    \    }\n\n    int n = a.size();\n    int w = 1;\n    while (w < n * 2) w *= 2;\n\
    \n    V<int> chi(n);\n    for (int i = 0; i < n; ++i) {\n        int t = i;\n\
    \        int res = 0;\n        for (int j = 0; j < K - 1; ++j) {\n           \
    \ t /= base[j];\n            res = (res + t) % K;\n        }\n        chi[i] =\
    \ res;\n    }\n\n    VV<T> F(K, V<T>(w)), G(K, V<T>(w));\n\n    for (int i = 0;\
    \ i < n; ++i) {\n        F[chi[i]][i] += a[i];\n        G[chi[i]][i] += b[i];\n\
    \    }\n\n    for (int i = 0; i < K; ++i) {\n        ntt.ntt(F[i]);\n        ntt.ntt(G[i]);\n\
    \    }\n\n    VV<T> A(K, V<T>(w));\n    rep(p, w) {\n        V<Mint> res(K);\n\
    \        rep(i, K) {\n            rep(j, K) { res[(i + j) % K] += F[i][p] * G[j][p];\
    \ }\n        }\n        rep(i, K) A[i][p] += res[i];\n    }\n    rep(i, K) ntt.ntt(A[i],\
    \ true);\n    V<T> res(n);\n    rep(i, n) res[i] = A[chi[i]][i];\n    return res;\n\
    }\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n \
    \   int K;\n    cin >> K;\n    V<int> N(K);\n    rep(i, K) cin >> N[i];\n    int\
    \ n = 1;\n    rep(i, K) n *= N[i];\n    V<int> base;\n    V<Mint> f(n), g(n);\n\
    \    rep(i, n) cin >> f[i];\n    rep(i, n) cin >> g[i];\n\n    auto ans = multivariate_convolution(f,\
    \ g, N);\n    print(ans);\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/multivariate_convolution.test.cpp
  requiredBy: []
  timestamp: '2021-10-02 23:37:41+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/multivariate_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/multivariate_convolution.test.cpp
- /verify/test/yosupo/multivariate_convolution.test.cpp.html
title: test/yosupo/multivariate_convolution.test.cpp
---
