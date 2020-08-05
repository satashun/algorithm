// SSP, TLE

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

using R = __int128;

string to_string(R x) {
    if (x == 0) return "0";
    string s;
    bool r = 0;
    if (x < 0) {
        r = 1;
        x = -x;
    }
    while (x > 0) {
        s.pb('0' + x % 10);
        x /= 10;
    }
    if (r) s.pb('-');
    reverse(ALL(s));
    return s;
}

template <class C, class D>  // capacity, distance
struct MinCostFlow {
    struct edge {
        int to, rev, id;
        C cap;
        D cost;
        edge(int to, C cap, D cost, int rev, int id)
            : to(to), cap(cap), cost(cost), rev(rev), id(id){};
    };

    using E = edge;

    const D INF = D(1) << 120;

    int n;
    VV<E> g;
    V<D> h, dst;
    V<int> prevv, preve;
    V<C> b;
    D val;

    MinCostFlow(int n)
        : n(n), g(n), h(n), dst(n), prevv(n), preve(n), b(n), val(0) {}

    // watch out for self loops!
    void add_edge(int f, int t, C cap, D cost, int id, bool need = false) {
        if (!need && cost >= 0) {
            int szt = (int)g[t].size() + (f == t);
            g[f].emplace_back(t, cap, cost, szt, id);
            int szf = (int)g[f].size() - 1;
            g[t].emplace_back(f, 0, -cost, szf, -1);
        } else {
            b[f] -= cap;
            b[t] += cap;
            val += cost * cap;
            if (!need) {
                int szt = (int)g[t].size() + (f == t);
                g[f].emplace_back(t, 0, cost, szt, id);
                int szf = (int)g[f].size() - 1;
                g[t].emplace_back(f, cap, -cost, szf, -1);
            }
        }
    }

    void init_negative(int s) {
        fill(h.begin(), h.end(), INF);
        h[s] = 0;
        for (int t = 0; t < n; ++t) {
            for (int i = 0; i < n; ++i) {
                for (auto e : g[i]) {
                    if (!e.cap || h[i] == INF) continue;
                    h[e.to] = min(h[e.to], h[i] + e.cost);
                }
            }
        }
    }

    D exec(int s, int t, C f) {
        D res = 0;
        using Data = pair<D, int>;

        while (f > 0) {
            priority_queue<Data, vector<Data>, greater<Data>> que;
            fill(dst.begin(), dst.end(), INF);
            dst[s] = 0;
            que.push(Data(0, s));

            while (!que.empty()) {
                auto p = que.top();
                que.pop();
                int v = p.se;
                if (dst[v] < p.fi) continue;
                rep(i, g[v].size()) {
                    auto e = g[v][i];
                    D nd = dst[v] + e.cost + h[v] - h[e.to];
                    if (e.cap > 0 && dst[e.to] > nd) {
                        dst[e.to] = nd;
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        que.push(Data(dst[e.to], e.to));
                    }
                }
            }

            if (dst[t] == INF) return D(-INF);
            rep(i, n) h[i] += dst[i];

            C d = f;
            for (int v = t; v != s; v = prevv[v]) {
                d = min(d, g[prevv[v]][preve[v]].cap);
            }
            f -= d;
            res += d * h[t];
            for (int v = t; v != s; v = prevv[v]) {
                edge& e = g[prevv[v]][preve[v]];
                e.cap -= d;
                g[v][e.rev].cap += d;
            }
        }

        return res;
    }
};

void ng() {
    cout << "infeasible" << endl;
    exit(0);
}

int main() {
    int n, m;
    cin >> n >> m;
    MinCostFlow<R, R> flow(n + 2);
    rep(i, n) {
        ll x;
        cin >> x;
        flow.b[i] = x;
    }
    V<R> fl(m);

    rep(i, m) {
        int s, t, l, u, c;
        cin >> s >> t >> l >> u >> c;
        if (l > 0) {
            flow.add_edge(s, t, l, c, -1, true);
        } else {
            flow.add_edge(t, s, -l, -c, -1, true);
        }

        flow.add_edge(s, t, u - l, c, i);
        fl[i] = l;
    }

    int s = n, t = n + 1;
    R bs = 0, ps = 0;
    {
        rep(i, n) {
            bs += flow.b[i];
            if (flow.b[i] > 0) {
                ps += flow.b[i];
                flow.add_edge(s, i, flow.b[i], 0, -1);
            } else {
                flow.add_edge(i, t, -flow.b[i], 0, -1);
            }
        }
        if (bs != 0) {
            ng();
        }
    }

    flow.init_negative(s);

    auto ct = flow.exec(s, t, ps);
    if (ct == -flow.INF) ng();
    R ans = ct + flow.val;

    rep(i, n) {
        for (auto e : flow.g[i]) {
            if (e.id >= 0) {
                fl[e.id] += flow.g[e.to][e.rev].cap;
            }
        }
    }

    cout << to_string(ans) << endl;
    const R inf = TEN(15);
    rep(i, n) cout << to_string(max(min(flow.h[i], inf), -inf)) << endl;
    rep(i, m) cout << to_string(fl[i]) << endl;
    return 0;
}