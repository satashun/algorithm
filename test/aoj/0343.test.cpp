#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0343"
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

#define call_from_test
#include "../../cpp_src/data_structure/FenwickTree.hpp"
#undef call_from_test

int main() {
    int N, C;
    cin >> N >> C;
    V<ll> tp(C), t(C), p(C);

    V<pair<ll, ll>> pt;
    rep(i, N) pt.eb(0, -i);
    V<ll> sc(N);

    rep(i, C) {
        cin >> tp[i];
        if (tp[i] == 0) {
            cin >> t[i] >> p[i];
            --t[i];
            sc[t[i]] += p[i];
            pt.eb(sc[t[i]], -t[i]);
        } else {
            cin >> t[i];
        }
    }
    sort(ALL(pt));
    int sz = SZ(pt);
    BIT<ll> T(sz);

    fill(ALL(sc), 0);
    rep(i, N) {
        int pos = lower_bound(ALL(pt), mp(0ll, ll(-i))) - pt.begin();
        T.add(pos, 1);
    }

    rep(i, C) {
        if (tp[i] == 0) {
            int pos = lower_bound(ALL(pt), mp(sc[t[i]], -t[i])) - pt.begin();
            T.add(pos, -1);
            sc[t[i]] += p[i];
            pos = lower_bound(ALL(pt), mp(sc[t[i]], -t[i])) - pt.begin();
            T.add(pos, 1);
        } else {
            int pos = T.lower_bound(N + 1 - t[i]);
            cout << -pt[pos - 1].se + 1 << ' ' << pt[pos - 1].fi << '\n';
        }
    }

    return 0;
}