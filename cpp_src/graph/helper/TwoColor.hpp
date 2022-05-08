template <class T>
pair<bool, V<int>> two_color(const Graph<T>& g) {
    int n = g.size();
    V<int> col(n, -1);

    auto rec = [&](auto&& f, int v, int c) -> bool {
        for (auto e : g[v]) {
            if (col[e.to] == -1) {
                col[e.to] = c ^ 1;
                if (!f(f, e.to, c ^ 1)) {
                    return false;
                }
            } else if (col[e.to] == c) {
                return false;
            }
        }
        return true;
    };

    rep(i, n) {
        if (col[i] == -1) {
            if (!rec(rec, i, 0)) {
                return mp(false, col);
            }
        }
    }
    return mp(true, col);
}