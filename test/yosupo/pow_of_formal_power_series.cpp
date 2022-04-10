#pragma region satashun
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using uint = unsigned int;
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

template <class T>
void mkuni(vector<T>& v) {
    sort(ALL(v));
    v.erase(unique(ALL(v)), end(v));
}

template <class T>
vector<int> sort_by(const vector<T>& v) {
    vector<int> res(v.size());
    iota(res.begin(), res.end(), 0);
    stable_sort(res.begin(), res.end(),
                [&](int i, int j) { return v[i] < v[j]; });
    return res;
}

template <class T, class U>
istream& operator>>(istream& is, pair<T, U>& p) {
    is >> p.first >> p.second;
    return is;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) {
        is >> x;
    }
    return is;
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
void scan(vector<T>& v, T offset = T(0)) {
    for (auto& x : v) {
        cin >> x;
        x += offset;
    }
}

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

template <class T>
void show(T x) {
    print(x, 1);
}

template <typename Head, typename... Tail>
void show(Head H, Tail... T) {
    print(H, 2);
    show(T...);
}

struct prepare_io {
    prepare_io() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
    }
} prep_io;
#pragma endregion satashun

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

V<Mint> fact, ifact, inv;
VV<Mint> small_comb;

void mod_init() {
    const int maxv = 1000010;
    const int maxvv = 5000;

    fact.resize(maxv);
    ifact.resize(maxv);
    inv.resize(maxv);

    small_comb = make_vec<Mint>(maxvv, maxvv);

    fact[0] = 1;
    for (int i = 1; i < maxv; ++i) {
        fact[i] = fact[i - 1] * i;
    }

    ifact[maxv - 1] = fact[maxv - 1].inv();

    for (int i = maxv - 2; i >= 0; --i) {
        ifact[i] = ifact[i + 1] * (i + 1);
    }

    for (int i = 1; i < maxv; ++i) {
        inv[i] = ifact[i] * fact[i - 1];
    }

    for (int i = 0; i < maxvv; ++i) {
        small_comb[i][0] = small_comb[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            small_comb[i][j] = small_comb[i - 1][j] + small_comb[i - 1][j - 1];
        }
    }
}

Mint comb(int n, int r) {
    if (n < 0 || r < 0 || r > n) return Mint(0);
    if (n < small_comb.size()) return small_comb[n][r];
    return fact[n] * ifact[r] * ifact[n - r];
}

Mint inv_comb(int n, int r) {
    if (n < 0 || r < 0 || r > n) return Mint(0);
    return ifact[n] * fact[r] * fact[n - r];
}

// O(k)
Mint comb_slow(ll n, ll k) {
    if (n < 0 || k < 0 || k > n) return Mint(0);
    Mint res = ifact[k];
    for (int i = 0; i < k; ++i) {
        res = res * (n - i);
    }
    return res;
}

// line up
// a 'o' + b 'x'
Mint comb2(int a, int b) {
    if (a < 0 || b < 0) return 0;
    return comb(a + b, a);
}

// divide a into b groups
Mint nhr(int a, int b) {
    if (b == 0) return Mint(a == 0);
    return comb(a + b - 1, a);
}

// O(p + log_p n)

Mint lucas(ll n, ll k, int p) {
    if (n < 0 || k < 0 || k > n) return Mint(0);
    Mint res = 1;
    while (n > 0) {
        res *= comb(n % p, k % p);
        n /= p;
        k /= p;
    }
    return res;
}

struct ModPrepare {
    ModPrepare() { mod_init(); }
} prep_mod;

/**
 * @docs docs/ntt.md
 */

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

        if (sz <= 16) {
            V<D> ret(s);
            for (int i = 0; i < a.size(); i++) {
                for (int j = 0; j < b.size(); j++) ret[i + j] += a[i] * b[j];
            }
            return ret;
        }

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

// T : modint
template <class T>
void ntt_2d(VV<T>& a, bool rev) {
    if (a.size() == 0 || a[0].size() == 0) return;
    int h = a.size(), w = a[0].size();

    NumberTheoreticTransform<T> fft;
    fft.init();

    for (auto& v : a) {
        fft.ntt(v, rev);
    }

    rep(j, w) {
        V<T> vh(h);
        rep(i, h) { vh[i] = a[i][j]; }
        fft.ntt(vh, rev);
        rep(i, h) { a[i][j] = vh[i]; }
    }
}

// depends on FFT libs
// work only with NTT-friendly mod

NumberTheoreticTransform<Mint> ntt;

struct prepare_FPS {
    prepare_FPS() { ntt.init(); }
} prep_FPS;

template <class D>
struct Poly : public V<D> {
    template <class... Args>
    Poly(Args... args) : V<D>(args...) {}
    Poly(initializer_list<D> init) : V<D>(init.begin(), init.end()) {}

    int size() const { return V<D>::size(); }
    D at(int p) const { return (p < this->size() ? (*this)[p] : D(0)); }

    void shrink() {
        while (this->size() > 0 && this->back() == D(0)) this->pop_back();
    }

    // first len terms
    Poly pref(int len) const {
        return Poly(this->begin(), this->begin() + min(this->size(), len));
    }

    // for polynomial division
    Poly rev() const {
        Poly res = *this;
        reverse(res.begin(), res.end());
        return res;
    }

    Poly shiftr(int d) const {
        int n = max(size() + d, 0);
        Poly res(n);
        for (int i = 0; i < size(); ++i) {
            if (i + d >= 0) {
                res[i + d] = at(i);
            }
        }
        return res;
    }

    Poly operator+(const Poly& r) const {
        auto n = max(size(), r.size());
        V<D> tmp(n);
        for (int i = 0; i < n; ++i) {
            tmp[i] = at(i) + r.at(i);
        }
        return tmp;
    }
    Poly operator-(const Poly& r) const {
        auto n = max(size(), r.size());
        V<D> tmp(n);
        for (int i = 0; i < n; ++i) {
            tmp[i] = at(i) - r.at(i);
        }
        return tmp;
    }

    // scalar
    Poly operator*(const D& k) const {
        int n = size();
        V<D> tmp(n);
        for (int i = 0; i < n; ++i) {
            tmp[i] = at(i) * k;
        }
        return tmp;
    }

    Poly operator*(const Poly& r) const {
        Poly a = *this;
        Poly b = r;
        auto v = ntt.mul(a, b);
        return v;
    }

    // scalar
    Poly operator/(const D& k) const { return *this * k.inv(); }

    Poly operator/(const Poly& r) const {
        if (size() < r.size()) {
            return {{}};
        }
        int d = size() - r.size() + 1;
        return (rev().pref(d) * r.rev().inv(d)).pref(d).rev();
    }

    Poly operator%(const Poly& r) const {
        auto res = *this - *this / r * r;
        res.shrink();
        return res;
    }

    Poly diff() const {
        V<D> res(max(0, size() - 1));
        for (int i = 1; i < size(); ++i) {
            res[i - 1] = at(i) * i;
        }
        return res;
    }

    Poly inte() const {
        V<D> res(size() + 1);
        for (int i = 0; i < size(); ++i) {
            res[i + 1] = at(i) / (D)(i + 1);
        }
        return res;
    }

    // f * f.inv(m) === 1 mod (x^m)
    // f_0 ^ -1 must exist
    Poly inv(int m) const {
        Poly res = Poly({D(1) / at(0)});
        for (int i = 1; i < m; i *= 2) {
            res = (res * D(2) - res * res * pref(i * 2)).pref(i * 2);
        }
        return res.pref(m);
    }

    // f_0 = 1 must hold
    Poly log(int n) const {
        auto f = pref(n);
        return (f.diff() * f.inv(n - 1)).pref(n - 1).inte();
    }

    // f_0 = 0 must hold
    Poly exp(int n) const {
        auto h = diff();
        Poly f({1}), g({1});

        for (int m = 1; m < n; m *= 2) {
            g = (g * D(2) - f * g * g).pref(m);
            auto q = h.pref(m - 1);
            auto w = (q + g * (f.diff() - f * q)).pref(m * 2 - 1);
            f = (f + f * (*this - w.inte()).pref(m * 2)).pref(m * 2);
        }

        return f.pref(n);
    }

    // front n elements of f(x)^k
    // be careful when k = 0
    Poly pow(ll k, int n) const {
        int zero = 0;
        while (zero < size() && at(zero) == 0) {
            zero++;
        }

        if (zero == size() || zero * k >= n) {
            Poly res(n);
            if (n > 0 && k == 0) res[0] = 1;
            return res;
        }

        Poly h(this->begin() + zero, this->end());
        D a = h[0], ra = D(1) / a;
        h *= ra;
        h = h.log(n - zero * k) * D(k);
        h = h.exp(n - zero * k);
        h = h.shiftr(zero * k) * a.pow(k);
        return h;
    }

    // f_0 = 1 must hold (use it with modular sqrt)
    // CF250E
    Poly sqrt(int n) const {
        Poly f = pref(n);
        Poly g({1});
        for (int i = 1; i < n; i *= 2) {
            g = (g + f.pref(i * 2) * g.inv(i * 2)) * D(2).inv();
        }
        return g.pref(n);
    }

    D eval(D x) const {
        D res = 0, c = 1;
        for (auto a : *this) {
            res += a * c;
            c *= x;
        }
        return res;
    }

    Poly powmod(ll k, const Poly& md) {
        auto v = *this % md;
        Poly res{1};
        while (k) {
            if (k & 1) {
                res = res * v % md;
            }
            v = v * v % md;
            k /= 2;
        }
        return res;
    }

    Poly& operator+=(const Poly& r) { return *this = *this + r; }
    Poly& operator-=(const Poly& r) { return *this = *this - r; }
    Poly& operator*=(const D& r) { return *this = *this * r; }
    Poly& operator*=(const Poly& r) { return *this = *this * r; }
    Poly& operator/=(const Poly& r) { return *this = *this / r; }
    Poly& operator/=(const D& r) { return *this = *this / r; }
    Poly& operator%=(const Poly& r) { return *this = *this % r; }

    friend ostream& operator<<(ostream& os, const Poly& pl) {
        if (pl.size() == 0) return os << "0";
        for (int i = 0; i < pl.size(); ++i) {
            if (pl[i]) {
                os << pl[i] << "x^" << i;
                if (i + 1 != pl.size()) os << ",";
            }
        }
        return os;
    }

    explicit operator bool() const {
        bool f = false;
        for (int i = 0; i < size(); ++i) {
            if (at(i)) {
                f = true;
            }
        }
        return f;
    }
};

// calculate characteristic polynomial
// c_0 * s_i + c_1 * s_{i+1} + ... + c_k * s_{i+k} = 0
// c_k = -1

template <class T>
Poly<T> berlekamp_massey(const V<T>& s) {
    int n = int(s.size());
    V<T> b = {T(-1)}, c = {T(-1)};
    T y = Mint(1);
    for (int ed = 1; ed <= n; ed++) {
        int l = int(c.size()), m = int(b.size());
        T x = 0;
        for (int i = 0; i < l; i++) {
            x += c[i] * s[ed - l + i];
        }
        b.push_back(0);
        m++;
        if (!x) {
            continue;
        }
        T freq = x / y;
        if (l < m) {
            auto tmp = c;
            c.insert(begin(c), m - l, Mint(0));
            for (int i = 0; i < m; i++) {
                c[m - 1 - i] -= freq * b[m - 1 - i];
            }
            b = tmp;
            y = x;
        } else {
            for (int i = 0; i < m; i++) {
                c[l - 1 - i] -= freq * b[m - 1 - i];
            }
        }
    }
    return c;
}

// HUPC 2020 day3 K, ABC225H
// calculate vec[0] * vec[1] * ...
// deg(result) must be bounded

template <class T>
Poly<T> prod(const V<Poly<T>>& vec) {
    auto comp = [](const auto& a, const auto& b) -> bool {
        return a.size() > b.size();
    };
    priority_queue<Poly<T>, V<Poly<T>>, decltype(comp)> que(comp);
    que.push(Poly<T>{1});

    for (auto& pl : vec) que.push(pl);

    while (que.size() > 1) {
        auto va = que.top();
        que.pop();
        auto vb = que.top();
        que.pop();
        que.push(va * vb);
    }

    return que.top();
}

// ABC215 G
// expand f(x + c)
// require factorial
template <class T>
Poly<T> taylor_shift(const Poly<T>& f, ll c) {
    using P = Poly<T>;
    int n = f.size();
    T powc = 1;
    P p(n), q(n);

    rep(i, n) {
        p[i] = f[i] * fact[i];
        q[n - 1 - i] = powc * ifact[i];
        powc *= c;
    }
    p = p * q;
    rep(i, n) q[i] = p[n - 1 + i] * ifact[i];
    return q;
}

using P = Poly<Mint>;

void slv() {
    int N, M;
    cin >> N >> M;
    V<int> a(N);
    cin >> a;
    P pl(N);
    rep(i, N) pl[i] = a[i];
    pl = pl.pow(M, N);
    rep(i, N) a[i] = pl[i].v;
    print(a);
}

int main() {
    int cases = 1;
    // cin >> cases;
    rep(i, cases) slv();

    return 0;
}