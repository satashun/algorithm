---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: test/yosupo/det.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/det.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-17 17:36:15+09:00


* see: <a href="https:">https:</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM \
    https:  // judge.yosupo.jp/problem/matrix_det

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define ALL(c) (c).begin(), (c).end()
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

template <unsigned int MOD>
struct ModInt {
    using uint = unsigned int;
    using ull = unsigned long long;
    using M = ModInt;

    uint v;

    ModInt(ll _v = 0) { set_norm(_v % MOD + MOD); }
    M& set_norm(uint _v) {  //[0, MOD * 2)->[0, MOD)
        v = (_v < MOD) ? _v : _v - MOD;
        return *this;
    }

    explicit operator bool() const { return v != 0; }
    M operator+(const M& a) const { return M().set_norm(v + a.v); }
    M operator-(const M& a) const { return M().set_norm(v + MOD - a.v); }
    M operator*(const M& a) const { return M().set_norm(ull(v) * a.v % MOD); }
    M operator/(const M& a) const { return *this * a.inv(); }
    M& operator+=(const M& a) { return *this = *this + a; }
    M& operator-=(const M& a) { return *this = *this - a; }
    M& operator*=(const M& a) { return *this = *this * a; }
    M& operator/=(const M& a) { return *this = *this / a; }
    M operator-() const { return M() - *this; }
    M& operator++(int) { return *this = *this + 1; }
    M& operator--(int) { return *this = *this - 1; }

    M pow(ll n) const {
        if (n < 0) return inv().pow(-n);
        M x = *this, res = 1;
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    M inv() const {
        ll a = v, b = MOD, p = 1, q = 0, t;
        while (b != 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(p -= t * q, q);
        }
        return M(p);
    }

    bool operator==(const M& a) const { return v == a.v; }
    bool operator!=(const M& a) const { return v != a.v; }
    friend ostream& operator<<(ostream& os, const M& a) { return os << a.v; }
    static uint get_mod() { return MOD; }
};

using Mint = ModInt<998244353>;

const Mint zero(0);
const Mint one(1);

bool iszero(Mint x) { return x.v == 0; }
bool isone(Mint x) { return x.v == 1; }

// gifted

template <class T>
struct Matrix {
    int H, W;
    VV<T> a;
    Matrix() : H(0), W(0) {}
    Matrix(int H, int W) : H(H), W(W), a(VV<T>(H, V<T>(W))) {}
    Matrix(const VV<T>& v) : H(v.size()), W(v[0].size()), a(v) {}
    static Matrix E(int n) {
        Matrix a(n, n);
        rep(i, n) a.set(i, i, 1);
        return a;
    }
    T at(int i, int j) const { return a[i][j]; }
    void set(int i, int j, T v) { a[i][j] = v; }
    Matrix operator+(const Matrix& r) const {
        assert(H == r.H && W == r.W);
        VV<T> v(H, V<T>(W));
        rep(i, H) rep(j, W) v[i][j] = a[i][j] + r.a[i][j];
        return Matrix(v);
    }
    Matrix operator-(const Matrix& r) const {
        assert(H == r.H && W == r.W);
        VV<T> v(H, V<T>(W));
        rep(i, H) rep(j, W) v[i][j] = a[i][j] - r.a[i][j];
        return Matrix(v);
    }
    Matrix operator*(const Matrix& r) const {
        assert(W == r.H);
        VV<T> v(H, V<T>(r.W));
        rep(i, H) rep(k, W) rep(j, r.W) v[i][j] += a[i][k] * r.a[k][j];
        return Matrix(v);
    }
    Matrix& operator+=(const Matrix& r) { return (*this) = (*this) + r; }
    Matrix& operator-=(const Matrix& r) { return (*this) = (*this) - r; }
    Matrix& operator*=(const Matrix& r) { return (*this) = (*this) * r; }

    int sweep(int var) {
        int rank = 0;
        vector<bool> used(H);
        rep(j, var) {
            int i = 0;
            while (i < H && (used[i] || iszero(a[i][j]))) i++;
            if (i == H) continue;
            used[i] = true;
            rank++;
            T t = a[i][j];
            rep(k, W) a[i][k] = a[i][k] / t;
            rep(k, H) if (k != i) {
                T t = a[k][j];
                rep(l, W) a[k][l] = a[k][l] - a[i][l] * t;
            }
        }
        return rank;
    }

    Matrix pow(ll n) const {
        assert(H == W);
        int h = H;
        Matrix x = *this, res(h, h);
        res = E(h);
        while (n > 0) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    friend ostream& operator<<(ostream& o, const Matrix& A) {
        rep(i, A.H) {
            rep(j, A.W) o << A.a[i][j] << " ";
            o << endl;
        }
        return o;
    }
};

template <class T>
T det(Matrix<T> a) {
    const int n = a.H;
    Mint ans(1);

    rep(i, n) {
        for (int j = i + 1; j < n; ++j)
            if (a.a[j][i]) {
                ans = -ans;
                swap(a.a[j], a.a[i]);
                break;
            }
        if (!a.a[i][i]) return 0;
        ans *= a.a[i][i];
        for (int j = i + 1; j < n; ++j) {
            auto w = -a.a[j][i] / a.a[i][i];
            for (int k = i; k < n; ++k) a.a[j][k] += a.a[i][k] * w;
        }
    }
    return ans;
}

int main() {
    int N;
    cin >> N;
    Matrix<Mint> a(N, N);
    rep(i, N) rep(j, N) cin >> a.a[i][j].v;
    cout << det(a) << endl;
    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/det.cpp"
#define PROBLEM \
    https:  // judge.yosupo.jp/problem/matrix_det

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define ALL(c) (c).begin(), (c).end()
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

template <unsigned int MOD>
struct ModInt {
    using uint = unsigned int;
    using ull = unsigned long long;
    using M = ModInt;

    uint v;

    ModInt(ll _v = 0) { set_norm(_v % MOD + MOD); }
    M& set_norm(uint _v) {  //[0, MOD * 2)->[0, MOD)
        v = (_v < MOD) ? _v : _v - MOD;
        return *this;
    }

    explicit operator bool() const { return v != 0; }
    M operator+(const M& a) const { return M().set_norm(v + a.v); }
    M operator-(const M& a) const { return M().set_norm(v + MOD - a.v); }
    M operator*(const M& a) const { return M().set_norm(ull(v) * a.v % MOD); }
    M operator/(const M& a) const { return *this * a.inv(); }
    M& operator+=(const M& a) { return *this = *this + a; }
    M& operator-=(const M& a) { return *this = *this - a; }
    M& operator*=(const M& a) { return *this = *this * a; }
    M& operator/=(const M& a) { return *this = *this / a; }
    M operator-() const { return M() - *this; }
    M& operator++(int) { return *this = *this + 1; }
    M& operator--(int) { return *this = *this - 1; }

    M pow(ll n) const {
        if (n < 0) return inv().pow(-n);
        M x = *this, res = 1;
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    M inv() const {
        ll a = v, b = MOD, p = 1, q = 0, t;
        while (b != 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(p -= t * q, q);
        }
        return M(p);
    }

    bool operator==(const M& a) const { return v == a.v; }
    bool operator!=(const M& a) const { return v != a.v; }
    friend ostream& operator<<(ostream& os, const M& a) { return os << a.v; }
    static uint get_mod() { return MOD; }
};

using Mint = ModInt<998244353>;

const Mint zero(0);
const Mint one(1);

bool iszero(Mint x) { return x.v == 0; }
bool isone(Mint x) { return x.v == 1; }

// gifted

template <class T>
struct Matrix {
    int H, W;
    VV<T> a;
    Matrix() : H(0), W(0) {}
    Matrix(int H, int W) : H(H), W(W), a(VV<T>(H, V<T>(W))) {}
    Matrix(const VV<T>& v) : H(v.size()), W(v[0].size()), a(v) {}
    static Matrix E(int n) {
        Matrix a(n, n);
        rep(i, n) a.set(i, i, 1);
        return a;
    }
    T at(int i, int j) const { return a[i][j]; }
    void set(int i, int j, T v) { a[i][j] = v; }
    Matrix operator+(const Matrix& r) const {
        assert(H == r.H && W == r.W);
        VV<T> v(H, V<T>(W));
        rep(i, H) rep(j, W) v[i][j] = a[i][j] + r.a[i][j];
        return Matrix(v);
    }
    Matrix operator-(const Matrix& r) const {
        assert(H == r.H && W == r.W);
        VV<T> v(H, V<T>(W));
        rep(i, H) rep(j, W) v[i][j] = a[i][j] - r.a[i][j];
        return Matrix(v);
    }
    Matrix operator*(const Matrix& r) const {
        assert(W == r.H);
        VV<T> v(H, V<T>(r.W));
        rep(i, H) rep(k, W) rep(j, r.W) v[i][j] += a[i][k] * r.a[k][j];
        return Matrix(v);
    }
    Matrix& operator+=(const Matrix& r) { return (*this) = (*this) + r; }
    Matrix& operator-=(const Matrix& r) { return (*this) = (*this) - r; }
    Matrix& operator*=(const Matrix& r) { return (*this) = (*this) * r; }

    int sweep(int var) {
        int rank = 0;
        vector<bool> used(H);
        rep(j, var) {
            int i = 0;
            while (i < H && (used[i] || iszero(a[i][j]))) i++;
            if (i == H) continue;
            used[i] = true;
            rank++;
            T t = a[i][j];
            rep(k, W) a[i][k] = a[i][k] / t;
            rep(k, H) if (k != i) {
                T t = a[k][j];
                rep(l, W) a[k][l] = a[k][l] - a[i][l] * t;
            }
        }
        return rank;
    }

    Matrix pow(ll n) const {
        assert(H == W);
        int h = H;
        Matrix x = *this, res(h, h);
        res = E(h);
        while (n > 0) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    friend ostream& operator<<(ostream& o, const Matrix& A) {
        rep(i, A.H) {
            rep(j, A.W) o << A.a[i][j] << " ";
            o << endl;
        }
        return o;
    }
};

template <class T>
T det(Matrix<T> a) {
    const int n = a.H;
    Mint ans(1);

    rep(i, n) {
        for (int j = i + 1; j < n; ++j)
            if (a.a[j][i]) {
                ans = -ans;
                swap(a.a[j], a.a[i]);
                break;
            }
        if (!a.a[i][i]) return 0;
        ans *= a.a[i][i];
        for (int j = i + 1; j < n; ++j) {
            auto w = -a.a[j][i] / a.a[i][i];
            for (int k = i; k < n; ++k) a.a[j][k] += a.a[i][k] * w;
        }
    }
    return ans;
}

int main() {
    int N;
    cin >> N;
    Matrix<Mint> a(N, N);
    rep(i, N) rep(j, N) cin >> a.a[i][j].v;
    cout << det(a) << endl;
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

