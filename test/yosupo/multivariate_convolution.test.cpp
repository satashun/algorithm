#define PROBLEM \
    https:  // judge.yosupo.jp/problem/multivariate_convolution
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

template <class T>
V<T> make_vec(size_t a) {
    return V<T>(a);
}

template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return V<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define ALL(c) (c).begin(), (c).end()
#define SZ(x) ((int)(x).size())

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

template <class T>
void print(T x, int suc = 1) {
    cout << x;
    if (suc == 1)
        cout << "\n";
    else if (suc == 2)
        cout << " ";
}

template <class T>
void print(const vector<T>& v, int suc = 1) {
    for (int i = 0; i < v.size(); ++i)
        print(v[i], i == int(v.size()) - 1 ? suc : 2);
}

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
    explicit operator int() const { return v; }
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

    friend ostream& operator<<(ostream& os, const M& a) { return os << a.v; }
    friend istream& operator>>(istream& in, M& x) {
        ll v_;
        in >> v_;
        x = M(v_);
        return in;
    }

    bool operator<(const M& r) const { return v < r.v; }
    bool operator>(const M& r) const { return v < *this; }
    bool operator<=(const M& r) const { return !(r < *this); }
    bool operator>=(const M& r) const { return !(*this < r); }
    bool operator==(const M& a) const { return v == a.v; }
    bool operator!=(const M& a) const { return v != a.v; }

    static uint get_mod() { return MOD; }
};

// using Mint = ModInt<1000000007>;
using Mint = ModInt<998244353>;

template <class D>
struct NumberTheoreticTransform {
    D root;
    V<D> roots = {0, 1};
    V<int> rev = {0, 1};
    int base = 1, max_base = -1;

    void init() {
        int mod = D::get_mod();
        int tmp = mod - 1;
        max_base = 0;
        while (tmp % 2 == 0) {
            tmp /= 2;
            max_base++;
        }

        root = 2;

        while (true) {
            if (root.pow(1 << max_base).v == 1) {
                if (root.pow(1 << (max_base - 1)).v != 1) {
                    break;
                }
            }
            root++;
        }
    }

    void ensure_base(int nbase) {
        if (max_base == -1) init();
        if (nbase <= base) return;
        assert(nbase <= max_base);

        rev.resize(1 << nbase);
        for (int i = 0; i < (1 << nbase); ++i) {
            rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
        }
        roots.resize(1 << nbase);

        while (base < nbase) {
            D z = root.pow(1 << (max_base - 1 - base));
            for (int i = 1 << (base - 1); i < (1 << base); ++i) {
                roots[i << 1] = roots[i];
                roots[(i << 1) + 1] = roots[i] * z;
            }
            ++base;
        }
    }

    void ntt(V<D>& a, bool inv = false) {
        int n = a.size();
        // assert((n & (n - 1)) == 0);
        int zeros = __builtin_ctz(n);
        ensure_base(zeros);
        int shift = base - zeros;

        for (int i = 0; i < n; i++) {
            if (i < (rev[i] >> shift)) {
                swap(a[i], a[rev[i] >> shift]);
            }
        }

        for (int k = 1; k < n; k <<= 1) {
            for (int i = 0; i < n; i += 2 * k) {
                for (int j = 0; j < k; j++) {
                    D x = a[i + j];
                    D y = a[i + j + k] * roots[j + k];
                    a[i + j] = x + y;
                    a[i + j + k] = x - y;
                }
            }
        }

        int v = D(n).inv().v;
        if (inv) {
            reverse(a.begin() + 1, a.end());
            for (int i = 0; i < n; i++) {
                a[i] *= v;
            }
        }
    }

    V<D> mul(V<D> a, V<D> b) {
        if (a.size() == 0 && b.size() == 0) return {};
        int s = a.size() + b.size() - 1;
        int nbase = 1;
        while ((1 << nbase) < s) nbase++;
        int sz = 1 << nbase;
        a.resize(sz);
        b.resize(sz);
        ntt(a);
        ntt(b);

        for (int i = 0; i < sz; i++) {
            a[i] *= b[i];
        }
        ntt(a, true);

        a.resize(s);
        return a;
    }
};

// f(x_1, x_2, ..., x_k) * g(x_1, x_2, ..., x_k) mod (x_1^n_1, \cdots, x_k^n_k)
// base : {n_1, n_2, \cdots, n_k}
// i = i_1 + i_2 * n_1 + \cdots + i_k * (n_1 * n_2 \cdots * n_{k-1})

template <class T>
V<T> multivariate_convolution(V<T> a, V<T> b, V<int> base) {
    NumberTheoreticTransform<T> ntt;
    ntt.init();

    int K = base.size();

    if (K == 0) {
        return V<T>{a[0] * b[0]};
    }

    int n = a.size();
    int w = 1;
    while (w < n * 2) w *= 2;

    V<int> chi(n);
    for (int i = 0; i < n; ++i) {
        int t = i;
        int res = 0;
        for (int j = 0; j < K - 1; ++j) {
            t /= base[j];
            res = (res + t) % K;
        }
        chi[i] = res;
    }

    VV<T> F(K, V<T>(w)), G(K, V<T>(w));

    for (int i = 0; i < n; ++i) {
        F[chi[i]][i] += a[i];
        G[chi[i]][i] += b[i];
    }

    for (int i = 0; i < K; ++i) {
        ntt.ntt(F[i]);
        ntt.ntt(G[i]);
    }

    VV<T> A(K, V<T>(w));
    rep(p, w) {
        V<Mint> res(K);
        rep(i, K) {
            rep(j, K) { res[(i + j) % K] += F[i][p] * G[j][p]; }
        }
        rep(i, K) A[i][p] += res[i];
    }
    rep(i, K) ntt.ntt(A[i], true);
    V<T> res(n);
    rep(i, n) res[i] = A[chi[i]][i];
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int K;
    cin >> K;
    V<int> N(K);
    rep(i, K) cin >> N[i];
    int n = 1;
    rep(i, K) n *= N[i];
    V<int> base;
    V<Mint> f(n), g(n);
    rep(i, n) cin >> f[i];
    rep(i, n) cin >> g[i];

    auto ans = multivariate_convolution(f, g, N);
    print(ans);

    return 0;
}