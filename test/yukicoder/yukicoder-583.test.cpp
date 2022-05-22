#pragma region satashun
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
    stable_sort(res.begin(), res.end(),
                [&](int i, int j) { return v[i] < v[j]; });
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

template <class T>
void show(T x) {
    print(x, 1);
}

template <typename Head, typename... Tail>
void show(Head H, Tail... T) {
    print(H, 2);
    show(T...);
}

struct prepare_io {
    prepare_io() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
    }
} prep_io;
#pragma endregion satashun

class unionfind {
    vector<int> par, rank;

   public:
    void init(int n) {
        par.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    unionfind() {}
    unionfind(int n) { init(n); }

    int find(int x) {
        if (par[x] == x)
            return x;
        else
            return par[x] = find(par[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;

        if (rank[x] < rank[y])
            par[x] = y;
        else {
            par[y] = x;
            if (rank[x] == rank[y]) ++rank[x];
        }
        return true;
    }

    bool same(int x, int y) { return (find(x) == find(y)); }
};

template <class T>
class Edge {
   public:
    int from, to, idx;
    T cost;

    Edge() = default;
    Edge(int from, int to, T cost = T(1), int idx = -1)
        : from(from), to(to), cost(cost), idx(idx) {}
    operator int() const { return to; }

    bool operator<(const Edge& e) const { return cost < e.cost; }
};

template <class T>
class Graph {
   public:
    using E = Edge<T>;
    vector<vector<E>> g;
    vector<E> edges;
    int es;

    Graph() {}
    Graph(int n) : g(n), edges(0), es(0){};

    int size() const { return g.size(); }

    virtual void add_directed_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es++);
    }

    virtual void add_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es);
        g[to].emplace_back(to, from, cost, es++);
    }

    inline vector<E>& operator[](const int& k) { return g[k]; }

    inline const vector<E>& operator[](const int& k) const { return g[k]; }

    void read(int M, int offset = -1, bool directed = false,
              bool weighted = false) {
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            a += offset;
            b += offset;
            T c = T(1);
            if (weighted) cin >> c;
            edges.emplace_back(a, b, c);
            if (directed)
                add_directed_edge(a, b, c);
            else
                add_edge(a, b, c);
        }
    }
};

// cost = 1 or tree
template <class T>
V<T> bfs(const Graph<T>& g, int s = 0) {
    const T inf = numeric_limits<T>::max() / 2;
    int n = g.size();

    V<T> ds(n, inf);
    queue<int> que;
    que.push(s);
    ds[s] = 0;

    while (!que.empty()) {
        auto v = que.front();
        que.pop();
        for (auto e : g[v]) {
            T nx = ds[v] + e.cost;
            if (ds[e.to] > nx) {
                ds[e.to] = nx;
                que.push(e.to);
            }
        }
    }
    for (auto& x : ds)
        if (x == inf) x = -1;
    return ds;
}

// must be optimized
template <class T>
V<T> bfs01(const Graph<T>& g, int s = 0) {
    const T inf = numeric_limits<T>::max() / 2;
    int n = g.size();

    V<T> ds(n, inf);
    using P = pair<T, int>;
    deque<int> que;
    que.push_back(s);
    ds[s] = 0;

    while (!que.empty()) {
        auto v = que.front();
        que.pop_front();
        for (auto e : g[v]) {
            T nx = ds[v] + e.cost;
            if (ds[e.to] > nx) {
                ds[e.to] = nx;
                if (e.cost == 0) {
                    que.push_front(e.to);
                } else {
                    que.push_back(e.to);
                }
            }
        }
    }
    for (auto& x : ds)
        if (x == inf) x = -1;
    return ds;
}

template <class T>
V<T> dijkstra(const Graph<T>& g, int s = 0) {
    const T inf = numeric_limits<T>::max() / 2;
    int n = g.size();

    V<T> ds(n, inf);
    using P = pair<T, int>;
    priority_queue<P, V<P>, greater<P>> que;
    que.emplace(0, s);
    ds[s] = 0;
    while (!que.empty()) {
        auto p = que.top();
        que.pop();
        int v = p.se;
        if (ds[v] < p.fi) continue;
        for (auto e : g[v]) {
            T nx = ds[v] + e.cost;
            if (ds[e.to] > nx) {
                ds[e.to] = nx;
                que.emplace(nx, e.to);
            }
        }
    }
    for (auto& x : ds)
        if (x == inf) x = -1;
    return ds;
}

// allow multiple edges and self loops, multiple components
template <class T, bool directed>
struct EulerianTrail : Graph<T> {
   public:
    using Graph<T>::g;
    using Graph<T>::Graph;
    using Graph<T>::edges;
    using Graph<T>::es;
    using E = Edge<T>;

    V<int> used_vertex, used_edge, deg;

    void init(int n) {
        deg.assign(n, 0);
        used_vertex.assign(n, 0);
    }

    void add_directed_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es++);
        deg[from]++;
        deg[to]--;
    }

    void add_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es);
        g[to].emplace_back(to, from, cost, es++);
        deg[from]++;
        deg[to]++;
    }

    EulerianTrail(int n) : Graph<T>(n), used_vertex(n), deg(n) {}

    E get_edge(int idx) const { return edges[idx]; }

    VV<int> enumerate_eulerian_trail() {
        if (directed) {
            for (auto& v : deg)
                if (v != 0) return {};
        } else {
            for (auto& v : deg)
                if (v & 1) return {};
        }
        used_edge.assign(es, 0);
        VV<int> res;
        rep(i, g.size()) {
            if (!SZ(g[i]) || used_vertex[i]) continue;
            res.push_back(go(i));
        }
        return res;
    }

    // yukicoder 583
    VV<int> enumerate_semi_eulerian_trail() {
        unionfind uf(g.size());
        for (auto& e : edges) {
            uf.unite(e.from, e.to);
        }
        VV<int> group(g.size());
        rep(i, g.size()) group[uf.find(i)].push_back(i);

        VV<int> res;
        used_edge.assign(es, 0);

        for (auto& vs : group) {
            if (!SZ(vs)) continue;
            int s = -1, t = -1;
            if (directed) {
                for (auto& v : vs) {
                    if (abs(deg[v]) > 1) {
                        return {};
                    } else if (deg[v] == 1) {
                        if (s != -1) return {};
                        s = v;
                    }
                }
            } else {
                for (auto& v : vs) {
                    if (deg[v] & 1) {
                        if (s == -1)
                            s = v;
                        else if (t == -1)
                            t = v;
                        else
                            return {};
                    }
                }
            }
            debug(s, t);
            if (s == -1) s = vs[0];
            res.emplace_back(go(s));
            if (!SZ(res.back())) res.pop_back();
        }
        return res;
    }

    // return {id of edges}
    V<int> go(int s) {
        stack<pair<int, int>> st;
        V<int> ord;
        st.emplace(s, -1);
        while (!st.empty()) {
            int idx = st.top().first;
            used_vertex[idx] = true;
            if (g[idx].empty()) {
                ord.emplace_back(st.top().second);
                st.pop();
            } else {
                auto e = g[idx].back();
                g[idx].pop_back();
                if (used_edge[e.idx]) continue;
                used_edge[e.idx] = true;
                st.emplace(e.to, e.idx);
            }
        }
        ord.pop_back();
        reverse(ord.begin(), ord.end());
        return ord;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    V<int> A(M), B(M);
    EulerianTrail<int, false> g(N);
    g.read(M, 0);

    auto res = g.enumerate_semi_eulerian_trail();
    show(SZ(res) == 1 ? "YES" : "NO");
    return 0;
}