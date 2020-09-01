#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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

const int maxv = 1000010;

V<Mint> fact(maxv), ifact(maxv), inv(maxv);

void init() {
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
}

inline Mint comb(int n, int k) {
    if (k < 0) return 0;
    Mint res = ifact[k];
    rep(i, k) res = res * (n - i);
    return res;
}

const Mint i2 = (Mint::get_mod() + 1) / 2;

using R = __int128;

int main() {
    init();

    int n, s;
    cin >> n >> s;
    V<pii> vec;
    rep(i, n) {
        int l, r;
        cin >> l >> r;
        vec.eb(1, l);
        vec.eb(-1, r + 1);
    }

    Mint x, y, z, u, v;

    {
        V<pair<int, Mint>> a[4], b[4];
        for (auto& p : vec) {
            for (auto& q : vec) {
                int k = p.se + q.se;
                Mint c = Mint(p.fi) * q.fi;
                rep(t, 4) {
                    a[t].eb(k, c * comb(s - k + 3, t));
                    b[t].eb(k, c * comb(-k, t));
                }
            }
        }
        rep(t, 4) {
            sort(ALL(a[t]), [&](pair<int, Mint> p, pair<int, Mint> q) {
                return p.fi < q.fi;
            });
            sort(ALL(b[t]), [&](pair<int, Mint> p, pair<int, Mint> q) {
                return p.fi < q.fi;
            });
        }
        rep(t, 4) {
            Mint cur;
            for (auto& p : a[t]) cur += p.se;
            int now = (int)a[t].size() - 1;
            for (auto& q : b[3 - t]) {
                while (now >= 0 && a[t][now].fi + q.fi > s) {
                    cur -= a[t][now--].se;
                }
                x += q.se * cur;
            }
        }
    }

    R sum = 0;

    for (auto& p : vec) {
        rep(i, vec.size()) {
            rep(j, i + 1) {
                auto &q = vec[i], &r = vec[j];
                ll k = s - (p.se * 2 + q.se + r.se);
                int c = p.fi * q.fi * r.fi * (j != i ? 2 : 1);
                if (k >= 0) {
                    if (k & 1) {
                        ll r = (k - 1) / 2;
                        sum += (r + 2) * (r + 1) * c * 2;
                    } else {
                        ll r = k / 2;
                        sum += (r * 2 + 2) * (r + 1) * c;
                    }
                }
            }
        }
    }
    y = sum % Mint::get_mod();
    y *= i2;

    for (auto& p : vec) {
        for (auto& q : vec) {
            int k = (p.se + q.se) * 2;
            Mint c = Mint(p.fi) * q.fi;
            if (k <= s) {
                int r = s - k;
                if (r % 2 == 0) {
                    z += c * (r / 2 + 1);
                }
            }
        }
    }

    for (auto& p : vec) {
        for (auto& q : vec) {
            Mint c = Mint(p.fi) * q.fi;
            int k = p.se * 3 + q.se;
            if (k <= s) {
                int r = s - k;
                u += c * (r / 3 + 1);
            }
        }
    }

    for (auto& p : vec) {
        Mint c = Mint(p.fi);
        int k = p.se * 4;
        if (k <= s) {
            int r = s - k;
            if (r % 4 == 0) v += c;
        }
    }

    debug(x.v, y.v, z.v, u.v, v.v);
    cout << ((x - y * 6 + z * 3 + u * 8 - v * 6) / 24).v << endl;

    return 0;
}