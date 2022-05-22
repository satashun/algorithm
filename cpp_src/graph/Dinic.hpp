// O(V^2 E)
template <class F>
struct Dinic {
    static constexpr F INF = numeric_limits<F>::max();

    struct Edge {
        int to, rev;
        F cap;
        Edge(int to, F cap, int rev) : to(to), cap(cap), rev(rev){};
    };

    using E = Edge;

    VV<E> g;
    V<int> level, iter;

    Dinic() {}
    Dinic(int n) : g(n), level(n), iter(n) {}

    void add_edge(int from, int to, F cap) {
        g[from].emplace_back(to, cap, (int)g[to].size());
        g[to].emplace_back(from, 0, (int)g[from].size() - 1);
    }

    void bfs(int s) {
        fill(ALL(level), -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);

        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (auto& e : g[v]) {
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    F dfs(int v, int t, F f) {
        if (v == t) return f;
        for (int& i = iter[v]; i < g[v].size(); i++) {
            auto& e = g[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                F d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    F max_flow(int s, int t) {
        F flow = 0;
        while (true) {
            bfs(s);
            if (level[t] < 0) return flow;
            fill(ALL(iter), 0);
            F f;
            while ((f = dfs(s, t, INF)) > 0) flow += f;
        }
    }

    // after calling max_flow
    // vector of {0, 1} (S side : 0)
    V<int> mincut(int S = 0) {
        V<int> vis(g.size());
        V<int> res(g.size(), 1);
        min_dfs(S, res, vis);
        return res;
    }

    void min_dfs(int v, V<int>& col, V<int>& vis) {
        col[v] = 0;
        vis[v] = 1;
        for (auto e : g[v]) {
            if (!vis[e.to] && e.cap > 0) {
                min_dfs(e.to, col, vis);
            }
        }
    }
};

// GCJ 2022 Round 2C
// mat[i][j] := 0,1 (whether i-j exists)
// (size of max_matching, assignment)
pair<int, V<int>> max_matching(const VV<int>& mat) {
    int L = SZ(mat);
    if (L == 0) {
        return mp(0, V<int>{});
    }

    int R = SZ(mat[0]);
    int cnt_node = L + R + 2;
    int S = cnt_node - 2, T = cnt_node - 1;
    Dinic<int> g(cnt_node);
    V<int> to(L, -1);

    rep(i, L) {
        g.add_edge(S, i, 1);
        rep(j, R) {
            if (mat[i][j]) {
                g.add_edge(i, j + L, 1);
            }
        }
    }
    rep(j, R) g.add_edge(j + L, T, 1);

    int mf = g.max_flow(S, T);
    rep(i, L) {
        for (auto e : g.g[i]) {
            if (e.to >= L && e.to < L + R && e.cap == 0) {
                to[i] = e.to - L;
            }
        }
    }
    return make_pair(mf, to);
}