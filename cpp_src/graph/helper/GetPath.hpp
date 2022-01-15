// ABC233F
// pick a path from a to b : O(n)
template <class T>
V<pair<int, Edge<T>>> get_path(const Graph<T>& g, int a, int b) {
    using E = Edge<T>;

    int n = g.size();
    V<int> par(n, -1);
    V<E> par_edge(n);
    auto rec = [&](auto&& f, int v, int p, E pe) -> void {
        par[v] = p;
        par_edge[v] = pe;
        for (auto e : g[v]) {
            if (e.to == p) continue;
            f(f, e.to, v, e);
        }
    };
    rec(rec, a, -1, E());
    if (par[b] == -1) return {};
    V<pair<int, E>> vec;
    int cur = b;
    while (cur != a) {
        vec.emplace_back(par[cur], par_edge[cur]);
        cur = par[cur];
    }
    reverse(ALL(vec));
    return vec;
}