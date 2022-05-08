struct FordFulkerson {
    static constexpr int INF = TEN(9);

    struct edge {
        int to, cap, rev;
    };

    int n;
    VV<edge> g;
    V<bool> used;

    FordFulkerson(int n) : n(n), g(n), used(n) {}

    void add_edge(int from, int to, int cap, int rcap) {
        g[from].push_back((edge){to, cap, (int)g[to].size()});
        g[to].push_back((edge){from, rcap, (int)g[from].size() - 1});
    }

    int dfs(int v, int t, int f) {
        if (v == t) return f;
        used[v] = true;
        for (auto& e : g[v]) {
            if (!used[e.to] && e.cap > 0) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int flow = 0;
        while (1) {
            fill(used.begin(), used.end(), false);
            int f = dfs(s, t, INF);
            if (f == 0) return flow;
            flow += f;
        }
    }
};