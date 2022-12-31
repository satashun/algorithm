// ABC209E, ABC261H
template <class T>
Graph<T> rev_graph(const Graph<T>& g) {
    int n = g.size();
    Graph<T> rg(n);
    rep(i, n) {
        for (auto e : g[i]) {
            swap(e.from, e.to);
            rg[e.from].pb(e);
        }
    }
    return rg;
}