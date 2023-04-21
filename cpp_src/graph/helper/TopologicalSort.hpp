// lexicographically smallest
template <class T>
V<int> topological_sort(const Graph<T>& g) {
    int n = g.size();

    priority_queue<int, V<int>, greater<int>> que;

    V<int> indeg(n);
    rep(i, n) {
        for (auto e : g[i]) {
            indeg[e.to]++;
        }
    }

    rep(i, n) if (indeg[i] == 0) que.push(i);

    V<int> res;
    while (!que.empty()) {
        int v = que.top();
        que.pop();
        res.pb(v);

        for (auto e : g[v]) {
            if (--indeg[e.to] == 0) {
                que.emplace(e.to);
            }
        }
    }

    if (SZ(res) < n) return V<int>{};
    return res;
}