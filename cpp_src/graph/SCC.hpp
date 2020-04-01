struct SCC {
    int n;
    VV<int> g, rg;
    V<int> vs, cmp;
    V<bool> vis;

    SCC(){}
    SCC(int n) : n(n) {
        g = rg = VV<int>(n);
        vs = cmp = V<int>(n);
        vis = V<bool>(n);
    }

    void add_edge(int from, int to) {
        g[from].push_back(to);
        rg[to].push_back(from);
    }

    void dfs(int v) {
        vis[v] = true;

        for (int to : g[v]) {
            if (!vis[to]) {
                dfs(to);
            }
        }

        vs.push_back(v);
    }

    void rdfs(int v, int k, V<int>& vec) {
        vis[v] = true;
        cmp[v] = k;
        vec.push_back(v);

        for (int to : rg[v]) {
            if (!vis[to]) {
                rdfs(to, k, vec);
            }
        }
    }

    VV<int> calc() {
        rep(v, n) if (!vis[v]) dfs(v);

        fill(vis.begin(), vis.end(), false);

        int k = 0;
        reverse(vs.begin(), vs.end());

        VV<int> vcomp;

        for (int v : vs) {
            if (!vis[v]) {
                V<int> vec;
                rdfs(v, k++, vec);
                vcomp.push_back(vec);
            }
        }

        return vcomp;
    }
};