#pragma region satashun
#include <algorithm>
#include <array>
#include <atomic>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
#include <condition_variable>
#include <deque>
#include <exception>
#include <forward_list>
#include <fstream>
#include <functional>
#include <future>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
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

template <typename T, typename V>
void fill_vec(T& v, const V& val) {
    v = val;
}

template <typename T, typename V>
void fill_vec(vector<T>& vec, const V& val) {
    for (auto& v : vec) fill_vec(v, val);
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

template <typename T>
int arglb(const V<T>& v, const T& x) {
    return distance(v.begin(), lower_bound(ALL(v), x));
}

template <typename T>
int argub(const V<T>& v, const T& x) {
    return distance(v.begin(), upper_bound(ALL(v), x));
}

template <class T>
void mkuni(vector<T>& v) {
    sort(ALL(v));
    v.erase(unique(ALL(v)), end(v));
}

template <class T>
vector<int> sort_by(const vector<T>& v, bool increasing = true) {
    vector<int> res(v.size());
    iota(res.begin(), res.end(), 0);

    if (increasing) {
        stable_sort(res.begin(), res.end(),
                    [&](int i, int j) { return v[i] < v[j]; });
    } else {
        stable_sort(res.begin(), res.end(),
                    [&](int i, int j) { return v[i] > v[j]; });
    }
    return res;
}

// prototype
template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p);

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v);

template <class T>
istream& operator>>(istream& is, vector<T>& v);

template <class T, size_t sz>
ostream& operator<<(ostream& os, const array<T, sz>& arr);

template <class T>
ostream& operator<<(ostream& os, const set<T>& ST);

template <class T>
ostream& operator<<(ostream& os, const unordered_set<T>& ST);

template <class T>
ostream& operator<<(ostream& os, const multiset<T>& ST);

template <class T, class U>
ostream& operator<<(ostream& os, const map<T, U>& MP);

template <class T, class U>
ostream& operator<<(ostream& os, const unordered_map<T, U>& MP);

ostream& operator<<(ostream& o, __int128_t x);

// io functions
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

template <class T, size_t sz>
ostream& operator<<(ostream& os, const array<T, sz>& arr) {
    os << '[';
    for (auto v : arr) os << v << ',';
    os << ']';
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const set<T>& ST) {
    os << "{";
    for (auto it = ST.begin(); it != ST.end(); ++it) {
        if (it != ST.begin()) os << ",";
        os << *it;
    }
    os << "}";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const unordered_set<T>& ST) {
    os << "{";
    for (auto it = ST.begin(); it != ST.end(); ++it) {
        if (it != ST.begin()) os << ",";
        os << *it;
    }
    os << "}";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const multiset<T>& ST) {
    os << "{";
    for (auto it = ST.begin(); it != ST.end(); ++it) {
        if (it != ST.begin()) os << ",";
        os << *it;
    }
    os << "}";
    return os;
}

template <class T, class U>
ostream& operator<<(ostream& os, const map<T, U>& MP) {
    for (auto it = MP.begin(); it != MP.end(); ++it) {
        os << "(" << it->first << ": " << it->second << ")";
    }
    return os;
}

template <class T, class U>
ostream& operator<<(ostream& os, const unordered_map<T, U>& MP) {
    for (auto it = MP.begin(); it != MP.end(); ++it) {
        os << "(" << it->first << ": " << it->second << ")";
    }
    return os;
}

string to_string(__int128_t x) {
    if (x == 0) return "0";
    string result;
    if (x < 0) {
        result += "-";
        x *= -1;
    }
    string t;
    while (x) {
        t.push_back('0' + x % 10);
        x /= 10;
    }
    reverse(t.begin(), t.end());
    return result + t;
}

ostream& operator<<(ostream& o, __int128_t x) { return o << to_string(x); }

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
V<T>& operator+=(V<T>& vec, const T& v) {
    for (auto& x : vec) x += v;
    return vec;
}

template <class T>
V<T>& operator-=(V<T>& vec, const T& v) {
    for (auto& x : vec) x -= v;
    return vec;
}

// suc : 1 = newline, 2 = space
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

int topbit(int t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int botbit(int a) { return a == 0 ? 32 : __builtin_ctz(a); }
int botbit(ll a) { return a == 0 ? 64 : __builtin_ctzll(a); }
int popcount(int t) { return __builtin_popcount(t); }
int popcount(ll t) { return __builtin_popcountll(t); }
int bit_parity(int t) { return __builtin_parity(t); }
int bit_parity(ll t) { return __builtin_parityll(t); }

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

// 解説: https://atcoder.jp/contests/ABC265/editorial/4577

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

    // FPS24 - R
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

        if (inv) {
            int v = D(n).inv().v;
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

NumberTheoreticTransform<Mint> ntt;

struct prepare_NTT {
    prepare_NTT() { ntt.init(); }
} prep_NTT;

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

// first d terms of f^k, where f is sparse.
// O(d * |i | f_i != 0|)
// FPS24 - A
template <class T>
V<T> pow_sparse(const Poly<T>& f, ll k, int d) {
    Poly<T> g(d);

    if (k == 0) {
        if (d > 0) g[0] = 1;
        return g;
    }

    V<pair<int, T>> fv;
    rep(i, f.size()) {
        if (f[i] != 0) fv.emplace_back(i, f[i]);
    }

    if (SZ(fv) == 0) {
        return g;
    }

    auto [head_pos, head_val] = fv[0];
    fv.erase(fv.begin());

    for (auto& [j, val] : fv) {
        j -= head_pos;
    }

    Poly<T> gg(d);

    gg[0] = head_val.pow(k);
    Mint rev = head_val.inv();

    for (int i = 0; i < d - 1; i++) {
        for (auto [j, val] : fv) {
            if (i + 1 - j < 0) break;
            gg[i + 1] += gg[i + 1 - j] * val * (T(k) * j - (i - j + 1));
        }
        gg[i + 1] *= inv[i + 1] * rev;
    }

    rep(i, d) {
        // k * head_pos < d-i
        if (head_pos > 0 && k >= (d - i + head_pos - 1) / head_pos) break;
        ll p = k * head_pos + i;
        g[p] = gg[i];
    }
    return g;
}

int main() {
    int N, K;
    ll M;
    cin >> N >> K >> M;
    Poly<Mint> pl(N);
    rep(i, K) {
        int j, a;
        cin >> j >> a;
        pl[j] = a;
    }
    pl = pow_sparse(pl, M, N);
    rep(i, N) { cout << pl[i] << (i != N - 1 ? ' ' : '\n'); }
    return 0;
}