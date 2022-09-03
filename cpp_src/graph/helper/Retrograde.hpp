// ABC209E
// cannot move -> lose
// 1:win, 0:lose, -1:draw
template <class T>
V<int> retrograde(const Graph<T>& g) {
    int n = g.size();
    auto rg = rev_graph(g);
    V<int> deg(n);
    rep(i, n) deg[i] = SZ(g[i]);
    queue<int> que;
    V<int> res(n, -1);

    rep(i, n) {
        if (deg[i] == 0) {
            res[i] = 0;
            que.push(i);
        }
    }

    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto e : rg[v]) {
            if (res[e.to] == -1) {
                deg[e.to]--;
                if (res[v] == 0) {
                    res[e.to] = 1;
                    que.push(e.to);
                } else if (deg[e.to] == 0) {
                    res[e.to] = 0;
                    que.push(e.to);
                }
            }
        }
    }
    return res;
}