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
    sort(res.begin(), res.end(), [&](int i, int j) { return v[i] < v[j]; });
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

struct prepare_io {
    prepare_io() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
    }
} prep_io;

template <class T, class U>
T powmod(T x, U k, T m) {
    x %= m;
    T res = 1 % m;
    while (k) {
        if (k & 1) {
            res = res * x % m;
        }
        k >>= 1;
        x = x * x % m;
    }
    return res;
}

// see : https://joisino.hatenablog.com/entry/2017/08/03/210000
// see : https://misteer.hatenablog.com/entry/miller-rabin
// test : https://yukicoder.me/problems/no/3030
// ref : http://miller-rabin.appspot.com/
// check if n is prime
// n < 4,759,123,141 -> call miller_rabin
// 2^64 > n >= 4,759,123,141 -> call miller_rabin_big
// O(k log^3 n)

bool miller_rabin(ll n) {
    static const vector<ll> v = {2, 7, 61};
    if (n < 2) {
        return false;
    } else if (n == 2) {
        return true;
    } else if (n % 2 == 0) {
        return false;
    }

    ull d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }
    for (auto a : v) {
        if (a % n == 0) continue;
        auto x = powmod(a, d, n);
        if (x == 1 || x == n - 1) continue;

        rep(r, s) {
            auto y = x * x % n;
            if (y == 1) {
                if (x != 1 && x != n - 1) {
                    return false;
                } else {
                    x = 1;
                    break;
                }
            }
            x = y;
        }
        if (x != 1) return false;
    }
    return true;
}

using R = __int128_t;
using ull = unsigned long long;
bool miller_rabin_big(ull n) {
    static const vector<R> v = {2,      325,     9375,      28178,
                                450775, 9780504, 1795265022};

    if (n < 2) {
        return false;
    } else if (n == 2) {
        return true;
    } else if (n % 2 == 0) {
        return false;
    }

    ull d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }
    for (auto a : v) {
        if (a % n == 0) continue;
        auto x = powmod(a, d, R(n));
        if (x == 1 || x == n - 1) continue;

        rep(r, s) {
            auto y = x * x % n;
            if (y == 1) {
                if (x != 1 && x != n - 1) {
                    return false;
                } else {
                    x = 1;
                    break;
                }
            }
            x = y;
        }
        if (x != 1) return false;
    }
    return true;
}

// bit op
int popcnt(uint x) { return __builtin_popcount(x); }
int popcnt(ull x) { return __builtin_popcountll(x); }
int bsr(uint x) { return 31 - __builtin_clz(x); }
int bsr(ull x) { return 63 - __builtin_clzll(x); }
int bsf(uint x) { return __builtin_ctz(x); }
int bsf(ull x) { return __builtin_ctzll(x); }

// binary gcd
ll binary_gcd(ll _a, ll _b) {
    ull a = abs(_a), b = abs(_b);
    if (a == 0) return b;
    if (b == 0) return a;
    int shift = bsf(a | b);
    a >>= bsf(a);
    do {
        b >>= bsf(b);
        if (a > b) swap(a, b);
        b -= a;
    } while (b);
    return (a << shift);
}

using R = __int128;

ll pollrard_single(ll n) {
    auto f = [&](ll x) { return ((R)x * x + 1) % n; };
    if (miller_rabin_big(n)) return n;
    if (n % 2 == 0) return 2;
    ll st = 0;
    while (true) {
        st++;

        ll x = st, y = f(x);
        while (true) {
            ll p = gcd((y - x + n), n);
            if (p == 0 || p == n) break;
            if (p != 1) return p;
            x = f(x);
            y = f(f(y));
        }
    }
}

V<ll> pollrard(ll n) {
    if (n == 1) return {};
    ll x = pollrard_single(n);
    if (x == n) return {x};
    V<ll> v1 = pollrard(x), v2 = pollrard(n / x);
    v1.insert(v1.end(), ALL(v2));
    return v1;
}

void slv() {
    ll x;
    cin >> x;
    auto ans = pollrard(x);
    sort(ALL(ans));
    debug(x, ans);
    print(SZ(ans), 2);
    print(ans);
}

int main() {
    int cases = 1;
    cin >> cases;
    rep(i, cases) slv();

    return 0;
}