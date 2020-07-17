#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
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
#include "../../cpp_src/graph/Dinic.hpp"
#undef call_from_test

int main() {
    int L, R, M;
    scanf("%d %d %d", &L, &R, &M);
    int n = L + R + 2;
    int s = n - 2, t = n - 1;
    Dinic g(n);
    rep(i, M) {
        int a, b;
        scanf("%d%d", &a, &b);
        g.add_edge(a, b + L, 1);
    }
    rep(i, L) g.add_edge(s, i, 1);
    rep(i, R) g.add_edge(i + L, t, 1);

    int K = g.max_flow(s, t);

    printf("%d\n", K);
    rep(i, L) {
        int mt = -1;
        for (auto e : g.g[i])
            if (e.to >= L && e.to < L + R && e.cap == 0) {
                mt = e.to;
            }
        if (mt != -1) {
            printf("%d %d\n", i, mt - L);
        }
    }

    return 0;
}