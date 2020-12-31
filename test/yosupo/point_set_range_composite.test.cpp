#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

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
#define ALL(c) (c).begin(), (c).end()

#ifdef LOCAL
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define dump(x) true
#endif

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

#define call_from_test
#include "../../cpp_src/math/Modular.hpp"
#undef call_from_test

using Mint = ModInt<998244353>;

// index of root = 1

template <class U>
struct segtree {
    using T = typename U::T;
    int sz;
    V<T> dat;

    segtree(const V<T>& a) {
        int n = a.size();
        sz = 1;
        while (sz < n) sz <<= 1;
        dat.assign(sz * 2, U::id());
        for (int i = 0; i < n; ++i) {
            dat[sz + i] = a[i];
        }
        for (int i = sz - 1; i >= 1; --i) {
            upd(i);
        }
    }

    void upd(int p) { dat[p] = U::op(dat[p << 1], dat[p << 1 | 1]); }

    void build() {
        for (int i = sz - 1; i > 0; --i) {
            dat[i] = U::op(dat[i << 1], dat[i << 1 | 1]);
        }
    }

    void modify(int p, T v) {
        p += sz;
        dat[p] = v;
        while (p >>= 1) {
            dat[p] = U::op(dat[p << 1], dat[p << 1 | 1]);
        }
    }

    //[l, r)

    T query(int l, int r) {
        T lval = U::id(), rval = U::id();
        int res = 0;
        for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lval = U::op(lval, dat[l++]);
            if (r & 1) rval = U::op(dat[--r], rval);
        }
        return U::op(lval, rval);
    }
};

const int INF = TEN(9) + 10;

struct U {
    using T = pair<Mint, Mint>;
    static T id() { return mp(Mint(1), Mint(0)); }
    static T op(const T& a, const T& b) {
        return mp(a.first * b.first, a.second * b.first + b.second);
    }
};

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    V<pair<Mint, Mint>> vec(N);

    rep(i, N) {
        int a, b;
        scanf("%d %d", &a, &b);
        vec[i] = mp(Mint(a), Mint(b));
    }
    segtree<U> seg(vec);
    while (Q--) {
        int t;
        scanf("%d", &t);
        if (t == 0) {
            int p, c, d;
            scanf("%d %d %d", &p, &c, &d);
            seg.modify(p, mp(Mint(c), Mint(d)));
        } else {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            auto f = seg.query(l, r);
            printf("%d\n", (f.fi * Mint(x) + f.se).v);
        }
    }

    return 0;
}