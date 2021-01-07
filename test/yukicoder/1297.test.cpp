#define PROBLEM "https://yukicoder.me/problems/no/1297"
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
#include "../../cpp_src/other/LineContainer.hpp"
#undef call_from_test

const ll INF = TEN(18);

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    ll C;
    cin >> N >> C;
    V<ll> a(N), b(N);
    rep(i, N) cin >> a[i] >> b[i];

    V<ll> dp(N + 1, INF), sub(N + 1, INF);
    dp[0] = 0;

    LineContainer<false> ls, ld;

    rep(i, N) {
        ls.add(-i, C * i * i + dp[i] * 2);
        sub[i + 1] = ls.query((2 * i + 1) * C + 2 * a[i]);

        if (i) {
            ld.add(-i * C + a[i - 1],
                   -(i - 1) * a[i - 1] + C * i * (i - 3) / 2 + sub[i]);
            dp[i + 1] = ld.query(i) + C * (i + 1) * (i + 2) / 2;
        }

        sub[i + 1] =
            sub[i + 1] / 2 + b[i] + a[i] * (i + 1) + C * i * (i + 1) / 2;
        chmin(dp[i + 1], sub[i + 1]);
    }

    cout << dp[N] << endl;

    return 0;
}