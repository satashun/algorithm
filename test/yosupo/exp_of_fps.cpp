#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
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

// depend on ModInt, must use NTT friendly mod

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

// depends on FFT libs
// basically use with ModInt

NumberTheoreticTransform<Mint> ntt;

template <class D>
struct Poly : public V<D> {
    template <class... Args>
    Poly(Args... args) : V<D>(args...) {}
    Poly(initializer_list<D> init) : V<D>(init.begin(), init.end()) {}

    int size() const { return V<D>::size(); }
    D at(int p) const { return (p < this->size() ? (*this)[p] : D(0)); }

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
        while (res.size() && !res.back()) {
            res.pop_back();
        }
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

    // be careful when k = 0
    Poly pow(int n, ll k) const { return (log(n) * (D)k).exp(n); }

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
};

int main() {
    ntt.init();
    int N, M;
    scanf("%d %d", &N, &M);
    Poly<Mint> pl(N);
    rep(i, N) scanf("%d", &pl[i].v);
    cout << pl << endl;
    pl = pl.pow(N, M);
    rep(i, N) printf("%d%c", pl[i].v, i == N - 1 ? '\n' : ' ');
    return 0;
}