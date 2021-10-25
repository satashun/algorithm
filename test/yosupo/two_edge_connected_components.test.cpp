#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

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

/*
#define call_from_test
#include "../../cpp_src/graph/GraphBase.hpp"
#include "../../cpp_src/graph/LCA.hpp"
#undef call_from_test
*/

#pragma once

template <class T>
class Edge {
   public:
    int from, to, idx;
    T cost;

    Edge() = default;
    Edge(int from, int to, T cost = T(1), int idx = -1)
        : from(from), to(to), cost(cost), idx(idx) {}
    operator int() const { return to; }
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

template <class T>
V<T> bfs(const Graph<T>& g, int s = 0) {
    int n = g.size();
    V<T> ds(n, numeric_limits<T>::max() / 2);
    using P = pair<T, int>;
    queue<int> que;
    que.push(s);
    ds[s] = 0;

    while (!que.empty()) {
        auto v = que.front();
        que.pop();
        for (auto e : g[v]) {
            T nx = ds[v] + 1;
            if (ds[e.to] > nx) {
                ds[e.to] = nx;
                que.push(e.to);
            }
        }
    }
    return ds;
}

template <class T>
V<T> dijkstra(const Graph<T>& g, int s = 0) {
    int n = g.size();
    V<T> ds(n, numeric_limits<T>::max() / 2);
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
    return ds;
}

// allow self loops, multiple edges
template <class T>
struct LowLink : Graph<T> {
   public:
    using Graph<T>::Graph;
    using Graph<T>::g;
    vector<int> ord, low, articulation;
    vector<Edge<T>> bridge;

    virtual void build() {
        used.assign(g.size(), 0);
        ord.assign(g.size(), 0);
        low.assign(g.size(), 0);
        int k = 0;
        for (int i = 0; i < g.size(); i++) {
            if (!used[i]) dfs(i, -1, k);
        }
    }

   private:
    vector<int> used;

    void dfs(int v, int par, int& k) {
        used[v] = true;
        low[v] = ord[v] = k++;
        bool is_articulation = false, seen = false;
        int cnt = 0;
        for (auto& e : g[v]) {
            if (e.to == par && !exchange(seen, true)) {
                continue;
            }
            if (!used[e.to]) {
                ++cnt;
                dfs(e.to, v, k);
                low[v] = min(low[v], low[e.to]);
                is_articulation |= (par >= 0 && low[e.to] >= ord[v]);
                if (ord[v] < low[e.to]) bridge.emplace_back(e);
            } else {
                low[v] = min(low[v], ord[e.to]);
            }
        }
        is_articulation |= (par == -1 && cnt > 1);
        if (is_articulation) articulation.push_back(v);
    }
};

// tree : u-v -> comp[u]-comp[v]
template <class T>
struct TwoEdgeConnectedComponents : LowLink<T> {
   public:
    using LowLink<T>::LowLink;
    using LowLink<T>::g;
    using LowLink<T>::ord;
    using LowLink<T>::low;
    using LowLink<T>::bridge;

    vector<int> comp;
    Graph<T> tree;
    vector<vector<int>> group;

    void build() {
        LowLink<T>::build();
        comp.assign(g.size(), -1);
        int k = 0;
        for (int i = 0; i < g.size(); i++) {
            if (comp[i] == -1) dfs(i, -1, k);
        }
        group.resize(k);
        for (int i = 0; i < g.size(); i++) {
            group[comp[i]].emplace_back(i);
        }
        tree = Graph<T>(k);
        for (auto& e : bridge) {
            tree.add_edge(comp[e.from], comp[e.to], e.cost);
        }
    }

    void show() {
        print(group.size());
        for (auto& v : group) {
            cout << SZ(v) << ' ';
            print(v);
        }
    }

   private:
    void dfs(int idx, int par, int& k) {
        if (par >= 0 && ord[par] >= low[idx])
            comp[idx] = comp[par];
        else
            comp[idx] = k++;
        for (auto& e : g[idx]) {
            if (comp[e.to] == -1) dfs(e.to, idx, k);
        }
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    TwoEdgeConnectedComponents<int> g(N);
    g.read(M, 0);
    g.build();
    g.show();

    return 0;
}