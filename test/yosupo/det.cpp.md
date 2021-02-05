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
  bundledCode: "#line 1 \"test/yosupo/det.cpp\"\n#define PROBLEM \\\n    https:  //\
    \ judge.yosupo.jp/problem/matrix_det\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntypedef pair<int, int> pii;\ntypedef long long ll;\ntemplate <class\
    \ T>\nusing V = vector<T>;\ntemplate <class T>\nusing VV = V<V<T>>;\n\n#define\
    \ pb push_back\n#define eb emplace_back\n#define mp make_pair\n#define fi first\n\
    #define se second\n#define rep(i, n) rep2(i, 0, n)\n#define rep2(i, m, n) for\
    \ (int i = m; i < (n); i++)\n#define ALL(c) (c).begin(), (c).end()\nconstexpr\
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
    \ ModInt<998244353>;\n\nconst Mint zero(0);\nconst Mint one(1);\n\nbool iszero(Mint\
    \ x) { return x.v == 0; }\nbool isone(Mint x) { return x.v == 1; }\n\n// gifted\n\
    \ntemplate <class T>\nstruct Matrix {\n    int H, W;\n    VV<T> a;\n    Matrix()\
    \ : H(0), W(0) {}\n    Matrix(int H, int W) : H(H), W(W), a(VV<T>(H, V<T>(W)))\
    \ {}\n    Matrix(const VV<T>& v) : H(v.size()), W(v[0].size()), a(v) {}\n    static\
    \ Matrix E(int n) {\n        Matrix a(n, n);\n        rep(i, n) a.set(i, i, 1);\n\
    \        return a;\n    }\n    T at(int i, int j) const { return a[i][j]; }\n\
    \    void set(int i, int j, T v) { a[i][j] = v; }\n    Matrix operator+(const\
    \ Matrix& r) const {\n        assert(H == r.H && W == r.W);\n        VV<T> v(H,\
    \ V<T>(W));\n        rep(i, H) rep(j, W) v[i][j] = a[i][j] + r.a[i][j];\n    \
    \    return Matrix(v);\n    }\n    Matrix operator-(const Matrix& r) const {\n\
    \        assert(H == r.H && W == r.W);\n        VV<T> v(H, V<T>(W));\n       \
    \ rep(i, H) rep(j, W) v[i][j] = a[i][j] - r.a[i][j];\n        return Matrix(v);\n\
    \    }\n    Matrix operator*(const Matrix& r) const {\n        assert(W == r.H);\n\
    \        VV<T> v(H, V<T>(r.W));\n        rep(i, H) rep(k, W) rep(j, r.W) v[i][j]\
    \ += a[i][k] * r.a[k][j];\n        return Matrix(v);\n    }\n    Matrix& operator+=(const\
    \ Matrix& r) { return (*this) = (*this) + r; }\n    Matrix& operator-=(const Matrix&\
    \ r) { return (*this) = (*this) - r; }\n    Matrix& operator*=(const Matrix& r)\
    \ { return (*this) = (*this) * r; }\n\n    int sweep(int var) {\n        int rank\
    \ = 0;\n        vector<bool> used(H);\n        rep(j, var) {\n            int\
    \ i = 0;\n            while (i < H && (used[i] || iszero(a[i][j]))) i++;\n   \
    \         if (i == H) continue;\n            used[i] = true;\n            rank++;\n\
    \            T t = a[i][j];\n            rep(k, W) a[i][k] = a[i][k] / t;\n  \
    \          rep(k, H) if (k != i) {\n                T t = a[k][j];\n         \
    \       rep(l, W) a[k][l] = a[k][l] - a[i][l] * t;\n            }\n        }\n\
    \        return rank;\n    }\n\n    Matrix pow(ll n) const {\n        assert(H\
    \ == W);\n        int h = H;\n        Matrix x = *this, res(h, h);\n        res\
    \ = E(h);\n        while (n > 0) {\n            if (n & 1) res *= x;\n       \
    \     x *= x;\n            n >>= 1;\n        }\n        return res;\n    }\n\n\
    \    friend ostream& operator<<(ostream& o, const Matrix& A) {\n        rep(i,\
    \ A.H) {\n            rep(j, A.W) o << A.a[i][j] << \" \";\n            o << endl;\n\
    \        }\n        return o;\n    }\n};\n\ntemplate <class T>\nT det(Matrix<T>\
    \ a) {\n    const int n = a.H;\n    Mint ans(1);\n\n    rep(i, n) {\n        for\
    \ (int j = i + 1; j < n; ++j)\n            if (a.a[j][i]) {\n                ans\
    \ = -ans;\n                swap(a.a[j], a.a[i]);\n                break;\n   \
    \         }\n        if (!a.a[i][i]) return 0;\n        ans *= a.a[i][i];\n  \
    \      for (int j = i + 1; j < n; ++j) {\n            auto w = -a.a[j][i] / a.a[i][i];\n\
    \            for (int k = i; k < n; ++k) a.a[j][k] += a.a[i][k] * w;\n       \
    \ }\n    }\n    return ans;\n}\n\nint main() {\n    int N;\n    cin >> N;\n  \
    \  Matrix<Mint> a(N, N);\n    rep(i, N) rep(j, N) cin >> a.a[i][j].v;\n    cout\
    \ << det(a) << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    https:  // judge.yosupo.jp/problem/matrix_det\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\ntypedef pair<int, int> pii;\n\
    typedef long long ll;\ntemplate <class T>\nusing V = vector<T>;\ntemplate <class\
    \ T>\nusing VV = V<V<T>>;\n\n#define pb push_back\n#define eb emplace_back\n#define\
    \ mp make_pair\n#define fi first\n#define se second\n#define rep(i, n) rep2(i,\
    \ 0, n)\n#define rep2(i, m, n) for (int i = m; i < (n); i++)\n#define ALL(c) (c).begin(),\
    \ (c).end()\nconstexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1);\
    \ }\n\ntemplate <class T, class U>\nvoid chmin(T& t, const U& u) {\n    if (t\
    \ > u) t = u;\n}\ntemplate <class T, class U>\nvoid chmax(T& t, const U& u) {\n\
    \    if (t < u) t = u;\n}\n\ntemplate <class T, class U>\nostream& operator<<(ostream&\
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
    \ operator bool() const { return v != 0; }\n    M operator+(const M& a) const\
    \ { return M().set_norm(v + a.v); }\n    M operator-(const M& a) const { return\
    \ M().set_norm(v + MOD - a.v); }\n    M operator*(const M& a) const { return M().set_norm(ull(v)\
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
    \ }\n};\n\nusing Mint = ModInt<998244353>;\n\nconst Mint zero(0);\nconst Mint\
    \ one(1);\n\nbool iszero(Mint x) { return x.v == 0; }\nbool isone(Mint x) { return\
    \ x.v == 1; }\n\n// gifted\n\ntemplate <class T>\nstruct Matrix {\n    int H,\
    \ W;\n    VV<T> a;\n    Matrix() : H(0), W(0) {}\n    Matrix(int H, int W) : H(H),\
    \ W(W), a(VV<T>(H, V<T>(W))) {}\n    Matrix(const VV<T>& v) : H(v.size()), W(v[0].size()),\
    \ a(v) {}\n    static Matrix E(int n) {\n        Matrix a(n, n);\n        rep(i,\
    \ n) a.set(i, i, 1);\n        return a;\n    }\n    T at(int i, int j) const {\
    \ return a[i][j]; }\n    void set(int i, int j, T v) { a[i][j] = v; }\n    Matrix\
    \ operator+(const Matrix& r) const {\n        assert(H == r.H && W == r.W);\n\
    \        VV<T> v(H, V<T>(W));\n        rep(i, H) rep(j, W) v[i][j] = a[i][j] +\
    \ r.a[i][j];\n        return Matrix(v);\n    }\n    Matrix operator-(const Matrix&\
    \ r) const {\n        assert(H == r.H && W == r.W);\n        VV<T> v(H, V<T>(W));\n\
    \        rep(i, H) rep(j, W) v[i][j] = a[i][j] - r.a[i][j];\n        return Matrix(v);\n\
    \    }\n    Matrix operator*(const Matrix& r) const {\n        assert(W == r.H);\n\
    \        VV<T> v(H, V<T>(r.W));\n        rep(i, H) rep(k, W) rep(j, r.W) v[i][j]\
    \ += a[i][k] * r.a[k][j];\n        return Matrix(v);\n    }\n    Matrix& operator+=(const\
    \ Matrix& r) { return (*this) = (*this) + r; }\n    Matrix& operator-=(const Matrix&\
    \ r) { return (*this) = (*this) - r; }\n    Matrix& operator*=(const Matrix& r)\
    \ { return (*this) = (*this) * r; }\n\n    int sweep(int var) {\n        int rank\
    \ = 0;\n        vector<bool> used(H);\n        rep(j, var) {\n            int\
    \ i = 0;\n            while (i < H && (used[i] || iszero(a[i][j]))) i++;\n   \
    \         if (i == H) continue;\n            used[i] = true;\n            rank++;\n\
    \            T t = a[i][j];\n            rep(k, W) a[i][k] = a[i][k] / t;\n  \
    \          rep(k, H) if (k != i) {\n                T t = a[k][j];\n         \
    \       rep(l, W) a[k][l] = a[k][l] - a[i][l] * t;\n            }\n        }\n\
    \        return rank;\n    }\n\n    Matrix pow(ll n) const {\n        assert(H\
    \ == W);\n        int h = H;\n        Matrix x = *this, res(h, h);\n        res\
    \ = E(h);\n        while (n > 0) {\n            if (n & 1) res *= x;\n       \
    \     x *= x;\n            n >>= 1;\n        }\n        return res;\n    }\n\n\
    \    friend ostream& operator<<(ostream& o, const Matrix& A) {\n        rep(i,\
    \ A.H) {\n            rep(j, A.W) o << A.a[i][j] << \" \";\n            o << endl;\n\
    \        }\n        return o;\n    }\n};\n\ntemplate <class T>\nT det(Matrix<T>\
    \ a) {\n    const int n = a.H;\n    Mint ans(1);\n\n    rep(i, n) {\n        for\
    \ (int j = i + 1; j < n; ++j)\n            if (a.a[j][i]) {\n                ans\
    \ = -ans;\n                swap(a.a[j], a.a[i]);\n                break;\n   \
    \         }\n        if (!a.a[i][i]) return 0;\n        ans *= a.a[i][i];\n  \
    \      for (int j = i + 1; j < n; ++j) {\n            auto w = -a.a[j][i] / a.a[i][i];\n\
    \            for (int k = i; k < n; ++k) a.a[j][k] += a.a[i][k] * w;\n       \
    \ }\n    }\n    return ans;\n}\n\nint main() {\n    int N;\n    cin >> N;\n  \
    \  Matrix<Mint> a(N, N);\n    rep(i, N) rep(j, N) cin >> a.a[i][j].v;\n    cout\
    \ << det(a) << endl;\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: test/yosupo/det.cpp
  requiredBy: []
  timestamp: '2020-07-17 17:36:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/yosupo/det.cpp
layout: document
redirect_from:
- /library/test/yosupo/det.cpp
- /library/test/yosupo/det.cpp.html
title: test/yosupo/det.cpp
---
