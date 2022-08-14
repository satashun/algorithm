// ABC211D, ABC222E, ABC218F
// dfs tree only with shortest paths
template <class T>
tuple<V<T>, V<int>, V<Edge<T>>> bfs_with_path(const Graph<T>& g, int s = 0,
                                              int ban = -1) {
    using E = Edge<T>;
    const T inf = numeric_limits<T>::max() / 2;
    int n = g.size();

    V<T> ds(n, inf);
    using P = pair<T, int>;
    queue<int> que;
    que.push(s);
    ds[s] = 0;
    V<int> par(n, -1);
    V<E> par_edge(n);

    while (!que.empty()) {
        auto v = que.front();
        que.pop();
        for (auto e : g[v]) {
            if (e.idx == ban) continue;
            T nx = ds[v] + e.cost;
            if (ds[e.to] > nx) {
                par[e.to] = v;
                par_edge[e.to] = e;
                ds[e.to] = nx;
                que.push(e.to);
            }
        }
    }

    for (auto& x : ds)
        if (x == inf) x = -1;
    return make_tuple(ds, par, par_edge);
}

// https://judge.yosupo.jp/problem/shortest_path
template <class T>
tuple<V<T>, V<int>, V<Edge<T>>> dijkstra_with_path(const Graph<T>& g, int s = 0,
                                                   int ban = -1) {
    using E = Edge<T>;
    const T inf = numeric_limits<T>::max() / 2;
    int n = g.size();

    V<T> ds(n, inf);
    using P = pair<T, int>;
    priority_queue<P, V<P>, greater<P>> que;
    que.emplace(0, s);
    ds[s] = 0;

    V<int> par(n, -1);
    V<E> par_edge(n);

    while (!que.empty()) {
        auto p = que.top();
        que.pop();
        int v = p.se;
        if (ds[v] < p.fi) continue;
        for (auto e : g[v]) {
            T nx = ds[v] + e.cost;
            if (ds[e.to] > nx) {
                ds[e.to] = nx;
                par[e.to] = v;
                par_edge[e.to] = e;
                que.emplace(nx, e.to);
            }
        }
    }

    for (auto& x : ds)
        if (x == inf) x = -1;
    return make_tuple(ds, par, par_edge);
}