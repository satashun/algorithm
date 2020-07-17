//O(NM)
struct bipartite_matching {
    int n;
    VV<int> g;
    V<int> match;
    V<bool> used;
    bipartite_matching() {}
    bipartite_matching(int n) : n(n), g(n), match(n), used(n) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool dfs(int v) {
        used[v] = true;

        for (int u : g[v]) {
            int w = match[u];
            if (w < 0 || (!used[w] && dfs(w))) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }

        return false;
    }

    int calc() {
        int res = 0;
        fill(match.begin(), match.end(), -1);

        for (int v = 0; v < n; ++v) {
            if (match[v] < 0) {
                fill(used.begin(), used.end(), false);
                res += dfs(v);
            }
        }
        return res;
    }
};