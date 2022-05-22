// old !!!!
// Hierholzer algorithm
// https://codeforces.com/contest/508/submission/92099335

// directed
// destruct graph
// todo : add BEST theorem

template <class E>
V<int> EulerianPath(const int s, VV<E>& g) {
    auto dfs = [&](auto&& self, int u, V<int>& path) -> void {
        while (!g[u].empty()) {
            int v = g[u].back();  // E : int
            g[u].pop_back();
            self(self, v, path);
        }
        path.push_back(u);
    };
    V<int> path;
    dfs(dfs, s, path);
    reverse(path.begin(), path.end());
    return path;
}