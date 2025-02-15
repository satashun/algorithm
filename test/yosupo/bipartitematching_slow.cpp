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

/*
#define call_from_test
#undef call_from_test
*/

struct bipartite_matching {
    int n;
    VV<int> g;
    V<int> match;
    V<bool> used;
    bipartite_matching() {}
    bipartite_matching(int n) : n(n), g(n), match(n), used(n) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool dfs(int v) {
        used[v] = true;

        for (int u : g[v]) {
            int w = match[u];
            if (w < 0 || (!used[w] && dfs(w))) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }

        return false;
    }

    int calc() {
        int res = 0;
        fill(match.begin(), match.end(), -1);

        for (int v = 0; v < n; ++v) {
            if (match[v] < 0) {
                fill(used.begin(), used.end(), false);
                res += dfs(v);
            }
        }
        return res;
    }
};

int main() {
    int L, R, M;
    scanf("%d %d %d", &L, &R, &M);
    int n = L + R;
    bipartite_matching g(n);
    rep(i, M) {
        int a, b;
        scanf("%d%d", &a, &b);
        g.add_edge(a, b + L);
    }

    int K = g.calc();
    printf("%d\n", K);
    rep(i, L) {
        if (g.match[i] != -1) {
            printf("%d %d\n", i, g.match[i] - L);
        }
    }

    return 0;
}